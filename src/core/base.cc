/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <rango@swoole.com>                             |
  +----------------------------------------------------------------------+
*/

#include "phpx.h"

namespace php {
std::unordered_map<std::string, zval> global_vars;
const char *box_res_name = "php::box";
int box_res_id;

static zend_array *func_cache_map = nullptr;

void error(int level, const char *format, ...) {
    va_list args;
    va_start(args, format);
    php_verror(nullptr, "", level, format, args);
    va_end(args);
}

void echo(const char *format, ...) {
    va_list args;
    char *buffer;

    va_start(args, format);
    const size_t size = vspprintf(&buffer, 0, format, args);
    PHPWRITE(buffer, size);
    efree(buffer);
    va_end(args);
}

void echo(const String &str) {
    PHPWRITE(str.data(), str.length());
}

void echo(const Variant &val) {
    echo(val.toString());
}

void echo(Int val) {
    echo("%ld", val);
}

void echo(Float val) {
    echo("%f", val);
}

Variant concat(const Variant &a, const Variant &b) {
    return a.concat(b);
}

Variant concat(const std::initializer_list<Variant> &args) {
    if (args.size() == 0) {
        return Variant();
    }

    auto it = args.begin();
    Variant result = *it;
    ++it;

    for (; it != args.end(); ++it) {
        result = result.concat(*it);
    }

    return result;
}

Variant global(const String &name) {
    zend_is_auto_global(name.str());
    zval *var = zend_hash_find_ind(&EG(symbol_table), name.str());
    if (!var) {
        return false;
    }
    return {var};
}

void exit(const Variant &status) {
    if (status.isInt()) {
        EG(exit_status) = status.toInt();
    } else {
        auto zv = NO_CONST_V(status);
        zend_print_zval(zv, 0);
        EG(exit_status) = 0;
    }
    EG(exception) = zend_create_graceful_exit();
    if (EG(current_execute_data)) {
        EG(opline_before_exception) = EG(current_execute_data)->opline;
        EG(current_execute_data)->opline = EG(exception_op);
    }
    zend_bailout();
}

static void box_dtor(zend_resource *res) {
    Box *box = (Box *) res->ptr;
    box->destroy();
}

void request_init() {
    box_res_id = zend_register_list_destructors_ex(box_dtor, nullptr, box_res_name, 0);
    if (box_res_id < 0) {
        zend_throw_error(NULL, "error");
        return;
    }
}

void request_shutdown() {
    if (func_cache_map) {
        zend_hash_destroy(func_cache_map);
        pefree(func_cache_map, 1);
    }
    for (auto kv : global_vars) {
        zval_ptr_dtor(&kv.second);
    }
}

void throwException(const String &class_name, const char *message, int code) {
    zend_class_entry *ce = getClassEntry(class_name);
    if (ce == nullptr) {
        php_error_docref(nullptr, E_WARNING, "class '%s' undefined.", class_name.toCString());
        return;
    }
    zend_throw_exception(ce, message, code);
}

void throwException(const Object &e) {
    auto zv = NO_CONST_V(e);
    zval_add_ref(zv);
    EG(exception) = Z_OBJ_P(zv);
    zend_bailout();
}

Object catchException() {
    if (!EG(exception)) {
        return Object{};
    }
    zval zv;
    ZVAL_OBJ(&zv, EG(exception));
    Variant result{&zv};
    zend_clear_exception();
    return result;
}

Int atoi(const String &str) {
#if PHP_VERSION_ID >= 80200
    zend_string *errstr;
    Int size = zend_ini_parse_quantity(str.str(), &errstr);
    if (errstr) {
        error(E_WARNING, "failed to parse '%s' to size, Error: %s", str.data(), ZSTR_VAL(errstr));
        zend_string_release(errstr);
    }
    return size;
#else
    return zend_atol(str.data(), str.length());
#endif
}

static void free_fci_cache(zval *el) {
    pefree((zend_fcall_info_cache *) Z_PTR_P(el), 1);
}

static bool is_callable_ex(zval *callable,
                           zend_object *object,
                           uint32_t check_flags,
                           zend_string **callable_name,
                           zend_fcall_info_cache *fcc,
                           char **error) /* {{{ */
{
    zend_execute_data *frame = EG(current_execute_data);
    while (frame && !frame->func) {
        frame = frame->prev_execute_data;
    }

    bool ret = zend_is_callable_at_frame(callable, object, frame, check_flags, fcc, error);
    if (callable_name) {
        *callable_name = zend_get_callable_name_ex(callable, object);
    }
    return ret;
}

static void _call_user_function_impl(
    const zval *zobject, const zval *function_name, zval *retval_ptr, uint32_t param_count, zval params[]) {
    zend_fcall_info fci;

    fci.size = sizeof(fci);
    if (zobject) {
        ZEND_ASSERT(Z_TYPE_P(zobject) == IS_OBJECT);
        fci.object = Z_OBJ_P(zobject);
    } else {
        fci.object = nullptr;
    }
    ZVAL_COPY_VALUE(&fci.function_name, function_name);
    fci.retval = retval_ptr;
    fci.param_count = param_count;
    fci.params = params;
    fci.named_params = nullptr;

    zend_fcall_info_cache fcc;
    zend_fcall_info_cache *fci_cache;
    bool with_cache = Z_TYPE_P(function_name) == IS_STRING && !zobject;
    char *error = NULL;

    if (with_cache) {
        if (UNEXPECTED(func_cache_map == nullptr)) {
            func_cache_map = (zend_array *) pemalloc(sizeof(zend_array), 1);
            zend_hash_init(func_cache_map, 0, NULL, free_fci_cache, 0);
        } else {
            fci_cache = (zend_fcall_info_cache *) zend_hash_find_ptr(func_cache_map, Z_STR_P(function_name));
            if (fci_cache) {
                goto _do_call;
            }
        }
    }

    if (!is_callable_ex(&fci.function_name, fci.object, 0, NULL, &fcc, &error)) {
        ZEND_ASSERT(error && "Should have error if not callable");
        auto callable_name = zend_get_callable_name_ex(&fci.function_name, fci.object);
        zend_throw_error(NULL, "Invalid callback %s, %s", ZSTR_VAL(callable_name), error);
        efree(error);
        zend_string_release_ex(callable_name, 0);
    } else {
        fci_cache = &fcc;
        if (with_cache) {
            auto _cache = (zend_fcall_info_cache *) pemalloc(sizeof(fcc), 1);
            *_cache = fcc;
            zend_hash_update_ptr(func_cache_map, Z_STR_P(function_name), _cache);
        }
    _do_call:
        zend_call_function(&fci, fci_cache);
    }
}

Variant call_impl(const zval *object, const zval *func, Args &args) {
    Variant retval{};
    _call_user_function_impl(object, func, retval.ptr(), args.count(), args.ptr());
    return retval;
}

Variant call_impl(const zval *object, const zval *func) {
    Variant retval{};
    _call_user_function_impl(object, func, retval.ptr(), 0, nullptr);
    return retval;
}

Variant call(const Variant &func, Array &args) {
    Args _args(args.count());
    for (size_t i = 0; i < args.count(); i++) {
        _args.append(args[i]);
    }
    return call_impl(nullptr, func.const_ptr(), _args);
}

Variant call(const Variant &func, Args &args) {
    return call_impl(nullptr, func.const_ptr(), args);
}

Variant call(const Variant &func, const std::initializer_list<Variant> &args) {
    Args _args(args.size());
    for (const auto &arg : args) {
        _args.append(arg.const_ptr());
    }
    return call_impl(nullptr, func.const_ptr(), _args);
}

#define ZEND_FAKE_OP_ARRAY ((zend_op_array *) (intptr_t) -1)

static zend_never_inline zend_op_array *ZEND_FASTCALL zend_include_or_eval(zend_string *inc_filename, const int type) {
    zend_op_array *new_op_array = nullptr;
    switch (type) {
    case ZEND_INCLUDE_ONCE:
    case ZEND_REQUIRE_ONCE: {
        zend_file_handle file_handle;
        zend_string *resolved_path = zend_resolve_path(inc_filename);
        if (EXPECTED(resolved_path)) {
            if (zend_hash_exists(&EG(included_files), resolved_path)) {
                new_op_array = ZEND_FAKE_OP_ARRAY;
                zend_string_release_ex(resolved_path, false);
                break;
            }
        } else if (UNEXPECTED(EG(exception))) {
            break;
        } else {
            resolved_path = zend_string_copy(inc_filename);
        }

        zend_stream_init_filename_ex(&file_handle, resolved_path);
        if (SUCCESS == zend_stream_open(&file_handle)) {
            if (!file_handle.opened_path) {
                file_handle.opened_path = zend_string_copy(resolved_path);
            }

            if (zend_hash_add_empty_element(&EG(included_files), file_handle.opened_path)) {
                new_op_array =
                    zend_compile_file(&file_handle, (type == ZEND_INCLUDE_ONCE ? ZEND_INCLUDE : ZEND_REQUIRE));
            } else {
                new_op_array = ZEND_FAKE_OP_ARRAY;
            }
        } else if (!EG(exception)) {
            zend_message_dispatcher((type == ZEND_INCLUDE_ONCE) ? ZMSG_FAILED_INCLUDE_FOPEN : ZMSG_FAILED_REQUIRE_FOPEN,
                                    ZSTR_VAL(inc_filename));
        }
        zend_destroy_file_handle(&file_handle);
        zend_string_release_ex(resolved_path, false);
    } break;
    case ZEND_EVAL: {
        char *eval_desc = zend_make_compiled_string_description("eval()");
#if PHP_VERSION_ID < 80200
        new_op_array = zend_compile_string(inc_filename, eval_desc);
#else
        new_op_array = zend_compile_string(inc_filename, eval_desc, ZEND_COMPILE_POSITION_AFTER_OPEN_TAG);
#endif
        efree(eval_desc);
    } break;
    case ZEND_INCLUDE:
    case ZEND_REQUIRE:
    default:
        new_op_array = compile_filename(type, inc_filename);
        break;
    }

    return new_op_array;
}

static Variant include_impl(zend_string *filename, const int type) {
    zend_op_array *new_op_array = zend_include_or_eval(filename, type);
    if (UNEXPECTED(EG(exception) != nullptr)) {
        if (new_op_array != ZEND_FAKE_OP_ARRAY && new_op_array != nullptr) {
            destroy_op_array(new_op_array);
            efree_size(new_op_array, sizeof(zend_op_array));
        }
        return {};
    } else if (new_op_array == ZEND_FAKE_OP_ARRAY) {
        return true;
    } else if (UNEXPECTED(new_op_array == nullptr)) {
        return false;
    } else {
        Variant result;
        zend_execute(new_op_array, result.ptr());
        if (new_op_array != ZEND_FAKE_OP_ARRAY && new_op_array != nullptr) {
            destroy_op_array(new_op_array);
            efree_size(new_op_array, sizeof(zend_op_array));
        }
        return result;
    }
}

Variant include(const String &file, IncludeType type) {
    return include_impl(file.str(), type);
}

Variant eval(const String &script) {
    return include_impl(script.str(), ZEND_EVAL);
}

bool equals(const Variant &a, const Variant &b) {
    return compare(a, b) == 0;
}

bool same(const Variant &a, const Variant &b) {
    return zend_is_identical(NO_CONST_V(a), NO_CONST_V(b));
}

int compare(const Variant &a, const Variant &b) {
    return zend_compare(NO_CONST_V(a), NO_CONST_V(b));
}

zend_function_entry *copy_function_entries(const zend_function_entry *_functions) {
    const zend_function_entry *ptr = _functions;
    size_t count = 0;
    while (ptr->fname) {
        count++;
        ptr++;
    }

    auto *functions = new zend_function_entry[count + 1]();
    int i = 0;
    ptr = _functions;
    while (ptr->fname) {
        functions[i] = *ptr;
        i++;
        ptr++;
    }
    return functions;
}

Variant getStaticProperty(const String &class_name, const String &prop) {
    const auto ce = getClassEntry(class_name);
    if (UNEXPECTED(!ce)) {
        zend_throw_exception_ex(nullptr, -1, "class '%s' is undefined.", class_name.toCString());
    }
    return Variant(zend_read_static_property_ex(ce, prop.str(), true), Ctor::Move);
}

bool hasStaticProperty(const String &class_name, const String &prop) {
    const auto ce = getClassEntry(class_name);
    if (UNEXPECTED(!ce)) {
        zend_throw_exception_ex(nullptr, -1, "class '%s' is undefined.", class_name.toCString());
    }
    return zend_hash_exists(&ce->properties_info, prop.str());
}

bool setStaticProperty(const String &class_name, const String &prop, const Variant &v) {
    const auto ce = getClassEntry(class_name);
    if (UNEXPECTED(!ce)) {
        zend_throw_exception_ex(nullptr, -1, "class '%s' is undefined.", class_name.toCString());
    }
    const auto zv = NO_CONST_V(v);
    Z_TRY_ADDREF_P(zv);
    return zend_update_static_property_ex(ce, prop.str(), zv) == SUCCESS;
}

uint32_t getPropertyOffset(const String &class_name, const String &prop) {
    const auto ce = getClassEntry(class_name);
    if (UNEXPECTED(!ce)) {
        zend_throw_exception_ex(nullptr, -1, "class '%s' is undefined.", class_name.toCString());
    }
    auto prev_scope = EG(fake_scope);
    EG(fake_scope) = ce;
    auto prop_info = zend_get_property_info(ce, prop.str(), 0);
    EG(fake_scope) = prev_scope;
    return prop_info->offset;
}
}  // namespace php
