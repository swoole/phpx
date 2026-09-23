#include <typephp_opcode_table.h>
#include "../../thirdparty/opcache/opcode_unserialize.h"

extern "C" {
#include "php.h"
#include "zend_compile.h"
#include "zend_stream.h"
#include "zend_virtual_cwd.h"
#include "main/php_memory_streams.h"
#include "main/streams/php_stream_plain_wrapper.h"
}

#include <filesystem>
#include <string>
#include <unordered_map>
#include <sys/stat.h>
#ifdef _WIN32
#include <windows.h>
#include <cstdlib>
#endif

#ifdef _WIN32
extern "C" const uint8_t *typephp_embedded_archive_data(void) {
    HMODULE module = nullptr;
    if (!GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                            reinterpret_cast<LPCWSTR>(&typephp_embedded_archive_data), &module)) {
        std::abort();
    }
    HRSRC resource = FindResourceW(module, MAKEINTRESOURCEW(24103), MAKEINTRESOURCEW(10));
    if (!resource) std::abort();
    HGLOBAL loaded = LoadResource(module, resource);
    if (!loaded) std::abort();
    const void *data = LockResource(loaded);
    if (!data) std::abort();
    return static_cast<const uint8_t *>(data);
}
#endif

namespace {
template<class T> using EntryMap = std::unordered_map<std::string, const T *>;
EntryMap<typephp_opcode_entry> entries;
EntryMap<typephp_embedded_file_entry> raw_entries;
zend_op_array *(*old_compile_file)(zend_file_handle *, int) = nullptr;
zend_string *(*old_resolve_path)(zend_string *) = nullptr;
zend_result (*old_stream_open)(zend_file_handle *) = nullptr;
php_stream_wrapper_ops wrapped_file_ops;
php_stream_wrapper wrapped_file_wrapper;
bool file_wrapper_installed = false;
bool runtime_hooks_installed = false;
bool opcode_table_started = false;

std::string lexical_path(const std::string &path) {
    return std::filesystem::path(path).lexically_normal().string();
}

template<class T> const T *lookup(const EntryMap<T> &table, const std::string &original_name) {
    std::string name = original_name;
    if (name.rfind("file://", 0) == 0) name.erase(0, 7);
    auto found = table.find(name);
    if (found != table.end()) return found->second;

    std::filesystem::path path(name);
    if (path.is_absolute()) {
        found = table.find(lexical_path(name));
        return found == table.end() ? nullptr : found->second;
    }

    const zend_string *executed = zend_get_executed_filename_ex();
    if (executed && ZSTR_LEN(executed)) {
        std::filesystem::path base(ZSTR_VAL(executed));
        found = table.find(lexical_path((base.parent_path() / path).string()));
        if (found != table.end()) return found->second;
    }

    char cwd[MAXPATHLEN];
    if (VCWD_GETCWD(cwd, sizeof(cwd))) {
        found = table.find(lexical_path((std::filesystem::path(cwd) / path).string()));
        if (found != table.end()) return found->second;
    }
    return nullptr;
}

template<class T> const T *lookup(const EntryMap<T> &table, zend_string *filename) {
    if (!filename || memchr(ZSTR_VAL(filename), '\0', ZSTR_LEN(filename))) return nullptr;
    return lookup(table, std::string(ZSTR_VAL(filename), ZSTR_LEN(filename)));
}

ssize_t empty_reader(void *, char *, size_t) { return 0; }
size_t empty_size(void *) { return 0; }
void empty_close(void *) {}

void mark_embedded_handle(zend_file_handle *handle, const char *path, const void *entry) {
    handle->type = ZEND_HANDLE_STREAM;
    handle->handle.stream.handle = const_cast<void *>(entry);
    handle->handle.stream.isatty = 0;
    handle->handle.stream.reader = empty_reader;
    handle->handle.stream.fsizer = empty_size;
    handle->handle.stream.closer = empty_close;
    if (!handle->opened_path) {
        handle->opened_path = zend_string_init(path, strlen(path), 0);
    }
}

zend_op_array *embedded_compile_file(zend_file_handle *handle, int type) {
    zend_string *filename = handle->opened_path ? handle->opened_path : handle->filename;
    const typephp_opcode_entry *entry = lookup(entries, filename);
    if (entry) {
        if (handle->type == ZEND_HANDLE_FILENAME) mark_embedded_handle(handle, entry->path, entry);
        typephp_opcode_blob blob{entry->bytes, entry->length};
        return typephp_opcache_load(&blob);
    }
    const typephp_embedded_file_entry *raw = lookup(raw_entries, filename);
    if (raw && std::filesystem::path(raw->path).extension() == ".php") {
        if (handle->type == ZEND_HANDLE_FILENAME) mark_embedded_handle(handle, raw->path, raw);
        zend_string *empty = zend_string_init("", 0, 0);
        zend_op_array *result = zend_compile_string(empty, raw->path, ZEND_COMPILE_POSITION_AFTER_OPEN_TAG);
        zend_string_release(empty);
        return result;
    }
    return old_compile_file(handle, type);
}

zend_string *resolve_path(zend_string *filename) {
    const typephp_embedded_file_entry *raw = lookup(raw_entries, filename);
    if (raw) return zend_string_init(raw->path, strlen(raw->path), 0);
    const typephp_opcode_entry *opcode = lookup(entries, filename);
    if (opcode) return zend_string_init(opcode->path, strlen(opcode->path), 0);
    return old_resolve_path(filename);
}

zend_result stream_open(zend_file_handle *handle) {
    const typephp_embedded_file_entry *raw = lookup(raw_entries, handle->filename);
    if (raw && std::filesystem::path(raw->path).extension() == ".php") {
        mark_embedded_handle(handle, raw->path, raw);
        return SUCCESS;
    }
    const typephp_opcode_entry *opcode = lookup(entries, handle->filename);
    if (opcode) {
        mark_embedded_handle(handle, opcode->path, opcode);
        return SUCCESS;
    }
    return old_stream_open(handle);
}

php_stream *open_embedded_file(php_stream_wrapper *, const char *filename, const char *mode,
                               int options, zend_string **opened_path, php_stream_context *context STREAMS_DC) {
    const typephp_embedded_file_entry *raw = lookup(raw_entries, std::string(filename));
    if (raw && mode[0] == 'r') {
        zend_string *bytes = zend_string_init(reinterpret_cast<const char *>(raw->bytes), raw->length, 0);
        php_stream *stream = php_stream_memory_open(TEMP_STREAM_READONLY, bytes);
        zend_string_release(bytes);
        if (stream && opened_path) {
            *opened_path = zend_string_init(raw->path, strlen(raw->path), 0);
        }
        return stream;
    }
    return php_plain_files_wrapper.wops->stream_opener(
        &php_plain_files_wrapper, filename, mode, options, opened_path, context STREAMS_CC);
}

int stat_embedded_file(php_stream_wrapper *, const char *filename, int flags,
                       php_stream_statbuf *statbuf, php_stream_context *context) {
    const typephp_embedded_file_entry *raw = lookup(raw_entries, std::string(filename));
    if (raw) {
        memset(statbuf, 0, sizeof(*statbuf));
        statbuf->sb.st_mode = S_IFREG | 0444;
        statbuf->sb.st_size = static_cast<decltype(statbuf->sb.st_size)>(raw->length);
        statbuf->sb.st_nlink = 1;
        return 0;
    }
    std::string directory(filename);
    if (directory.rfind("file://", 0) == 0) directory.erase(0, 7);
    directory = lexical_path(directory);
    if (!directory.empty() && directory.back() != '/') directory.push_back('/');
    for (const auto &item : raw_entries) {
        if (item.first.rfind(directory, 0) == 0) {
            memset(statbuf, 0, sizeof(*statbuf));
            statbuf->sb.st_mode = S_IFDIR | 0555;
            statbuf->sb.st_nlink = 1;
            return 0;
        }
    }
    return php_plain_files_wrapper.wops->url_stat(
        &php_plain_files_wrapper, filename, flags, statbuf, context);
}

}

extern "C" void typephp_opcode_table_startup(void) {
    if (opcode_table_started) return;
    size_t count = 0;
    const typephp_opcode_entry *table = typephp_project_opcode_table(&count);
    size_t raw_count = 0;
    const typephp_embedded_file_entry *raw_table = typephp_project_embedded_file_table(&raw_count);
    if (!raw_count && !count) return;
    if (count != 0 && strcmp(typephp_project_php_version(), PHP_VERSION) != 0) {
        zend_error_noreturn(E_ERROR, "Embedded opcodes were built for PHP %s, runtime is PHP %s",
                            typephp_project_php_version(), PHP_VERSION);
    }
    for (size_t i = 0; i < count; ++i) {
        entries.emplace(table[i].path, &table[i]);
    }
    for (size_t i = 0; i < raw_count; ++i) {
        raw_entries.emplace(raw_table[i].path, &raw_table[i]);
    }
    opcode_table_started = true;
}

extern "C" void typephp_opcode_table_request_startup(void) {
    if (!opcode_table_started) return;

    // Zend extensions such as OPcache install their compiler hooks after
    // module MINIT. Chain TypePHP outside those hooks at the first request so
    // embedded opcodes are resolved before OPcache tries to stat the synthetic
    // zend_file_handle. Keep the process-wide chain for subsequent requests.
    if (!runtime_hooks_installed) {
        old_compile_file = zend_compile_file;
        old_resolve_path = zend_resolve_path;
        old_stream_open = zend_stream_open_function;
        zend_compile_file = embedded_compile_file;
        zend_resolve_path = resolve_path;
        zend_stream_open_function = stream_open;
        runtime_hooks_installed = true;
    }

    if (file_wrapper_installed) return;

    wrapped_file_ops = *php_plain_files_wrapper.wops;
    wrapped_file_ops.stream_opener = open_embedded_file;
    wrapped_file_ops.url_stat = stat_embedded_file;
    wrapped_file_wrapper = php_plain_files_wrapper;
    wrapped_file_wrapper.wops = &wrapped_file_ops;
    zend_string *protocol = zend_string_init("file", sizeof("file") - 1, 0);
    if (php_unregister_url_stream_wrapper_volatile(protocol) == SUCCESS &&
        php_register_url_stream_wrapper_volatile(protocol, &wrapped_file_wrapper) == SUCCESS) {
        file_wrapper_installed = true;
    } else {
        zend_error_noreturn(E_ERROR, "Cannot install embedded file stream wrapper");
    }
    zend_string_release(protocol);
}

extern "C" void typephp_opcode_table_install(void) {
    typephp_opcode_table_startup();
    typephp_opcode_table_request_startup();
}

extern "C" int typephp_embedded_file_exists(const char *path) {
    if (!path) return 0;
    const std::string name(path);
    return lookup(entries, name) != nullptr || lookup(raw_entries, name) != nullptr;
}

extern "C" int typephp_embedded_path_kind(const char *path) {
    if (!path) return 0;
    std::string name(path);
    if (lookup(entries, name) || lookup(raw_entries, name)) return 1;
    if (name.rfind("file://", 0) == 0) name.erase(0, 7);
    name = lexical_path(name);
    if (!name.empty() && name.back() != std::filesystem::path::preferred_separator) {
        name.push_back(std::filesystem::path::preferred_separator);
    }
    const auto contains_child = [&name](const auto &table) {
        for (const auto &item : table) {
            if (item.first.rfind(name, 0) == 0) return true;
        }
        return false;
    };
    return contains_child(entries) || contains_child(raw_entries) ? 2 : 0;
}

extern "C" void typephp_opcode_table_require(const char *path) {
    const typephp_opcode_entry *entry = lookup(entries, std::string(path));
    if (!entry) {
        zend_error_noreturn(E_ERROR, "Missing embedded opcode: %s", path);
    }
    if (zend_hash_str_exists(&EG(included_files), entry->path, strlen(entry->path))) {
        return;
    }
    zend_file_handle handle;
    zend_stream_init_filename(&handle, entry->path);
    zend_execute_scripts(ZEND_REQUIRE, nullptr, 1, &handle);
    zend_destroy_file_handle(&handle);
}

extern "C" void typephp_opcode_table_request_shutdown(void) {
    if (file_wrapper_installed) {
        zend_string *protocol = zend_string_init("file", sizeof("file") - 1, 0);
        php_unregister_url_stream_wrapper_volatile(protocol);
        php_register_url_stream_wrapper_volatile(protocol, &php_plain_files_wrapper);
        zend_string_release(protocol);
        file_wrapper_installed = false;
    }
}

extern "C" void typephp_opcode_table_shutdown(void) {
    if (!opcode_table_started) return;
    typephp_opcode_table_request_shutdown();
    if (runtime_hooks_installed) {
        if (zend_compile_file == embedded_compile_file) zend_compile_file = old_compile_file;
        if (zend_resolve_path == resolve_path) zend_resolve_path = old_resolve_path;
        if (zend_stream_open_function == stream_open) zend_stream_open_function = old_stream_open;
        runtime_hooks_installed = false;
    }
    old_compile_file = nullptr;
    old_resolve_path = nullptr;
    old_stream_open = nullptr;
    entries.clear();
    raw_entries.clear();
    opcode_table_started = false;
}

extern "C" void typephp_opcode_table_uninstall(void) {
    typephp_opcode_table_shutdown();
}
