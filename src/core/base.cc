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
const char *box_res_name = "php::box";
int box_res_id;

static zend_array *func_cache_map = nullptr;
std::function<void(zend_object *)> throw_impl;

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

Variant concat(const ArgList &args) {
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
        return {};
    }
    return {var, Ctor::Indirect};
}

void initGlobal(const String &name, Variant &var) {
    auto gvar = global(name);
    var.unset();
    if (gvar.isIndirect()) {
        *var.ptr() = *gvar.ptr();
    } else {
        auto addr = zend_hash_add_new(&EG(symbol_table), name.str(), undef());
        ZVAL_INDIRECT(var.ptr(), addr);
    }
}

void unsetGlobal(const String &name) {
    zend_hash_del(&EG(symbol_table), name.str());
}

Variant constant(const String &name) {
    auto c = zend_get_constant_ex(name.str(), zend_get_executed_scope(), ZEND_FETCH_CLASS_EXCEPTION);
    throwErrorIfOccurred();
    return Variant{c};
}

Variant constant(zend_class_entry *ce, const String &name) {
    if (ce == nullptr) {
        return {zend_get_constant(name.str())};
    } else {
        return zend_hash_find(CE_CONSTANTS_TABLE(ce), name.str());
    }
}

void exit(const Variant &status) {
    if (status.isInt()) {
        EG(exit_status) = status.toInt();
    } else {
        auto zv = NO_CONST_V(status);
        zend_print_zval(zv, 0);
        EG(exit_status) = 0;
    }
    zend_throw_graceful_exit();
    if (throw_impl) {
        throw_impl(EG(exception));
    }
}

static void box_dtor(zend_resource *res) {
    auto box = static_cast<Box *>(res->ptr);
    box->destroy();
}

#ifdef ZTS
#define THREAD_LOCAL thread_local
#else
#define THREAD_LOCAL
#endif

THREAD_LOCAL bool request_init_called = false;
THREAD_LOCAL bool request_shutdown_called = false;

void request_init() {
    if (request_init_called) {
        return;
    }
    request_init_called = true;
    box_res_id = zend_register_list_destructors_ex(box_dtor, nullptr, box_res_name, 0);
    if (box_res_id < 0) {
        throwError("failed to register box resource");
    }
}

void request_shutdown() {
    if (request_shutdown_called) {
        return;
    }
    request_shutdown_called = true;
    if (func_cache_map) {
        zend_hash_destroy(func_cache_map);
        pefree(func_cache_map, 1);
    }
}

void throwException(const String &class_name, const char *message, int code) {
    zend_class_entry *ce = getClassEntry(class_name);
    if (ce == nullptr) {
        throwError("class '%s' undefined.", class_name.toCString());
        return;
    }
    zend_throw_exception(ce, message, code);
    if (throw_impl) {
        throw_impl(EG(exception));
    }
}

void throwException(const Object &e) {
    auto zv = NO_CONST_V(e);
    zval_add_ref(zv);
    EG(exception) = Z_OBJ_P(zv);
    if (throw_impl) {
        throw_impl(EG(exception));
    }
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

zend_function *getFunction(const String &name) {
    zend_fcall_info_cache fcc;
    zval *fn = NO_CONST_V(name);

    if (!is_callable_ex(fn, nullptr, 0, nullptr, &fcc, nullptr)) {
        ZEND_ASSERT(error && "Should have error if not callable");
        auto callable_name = zend_get_callable_name_ex(fn, nullptr);
        zend_throw_error(NULL, "function '%s' is undefined.", ZSTR_VAL(callable_name));
        zend_string_release_ex(callable_name, 0);
    }
    throwErrorIfOccurred();

    return fcc.function_handler;
}

zend_function *getMethod(zend_class_entry *ce, const String &name) {
    auto lmname = zend_string_tolower(name.str());
    auto zv = zend_hash_find(&ce->function_table, lmname);
    zend_string_release(lmname);
    if (UNEXPECTED(zv == nullptr)) {
        throwError("method '%s::%s' is undefined.", ZSTR_VAL(ce->name), name.data());
        return nullptr;
    }
    return (zend_function *) Z_PTR_P(zv);
}

static void call_function_impl(
    const zval *zobject, const zval *function_name, zval *retval_ptr, uint32_t param_count, zval params[]) {
    zend_fcall_info fci;

    fci.size = sizeof(fci);
    if (zobject) {
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

    throwErrorIfOccurred();
}

Variant call_impl(const zval *object, const zval *func, Args &args) {
    Variant retval{};
    call_function_impl(object, func, retval.ptr(), args.count(), args.ptr());
    return retval;
}

Variant call_impl(const zval *object, const zval *func) {
    Variant retval{};
    call_function_impl(object, func, retval.ptr(), 0, nullptr);
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

Variant call(const Variant &func, const ArgList &args) {
    Args _args(args);
    return call_impl(nullptr, func.const_ptr(), _args);
}

Variant call(zend_function *func) {
    Variant retval{};
    zend_call_known_function(func, nullptr, nullptr, retval.ptr(), 0, nullptr, nullptr);
    throwErrorIfOccurred();
    return retval;
}

Variant call(zend_function *func, const ArgList &args) {
    Variant retval{};
    Args _args(args);
    zend_call_known_function(func, nullptr, nullptr, retval.ptr(), _args.count(), _args.ptr(), nullptr);
    throwErrorIfOccurred();
    return retval;
}

Variant call(zend_class_entry *ce, zend_function *func) {
    Variant retval{};
    zend_call_known_function(func, nullptr, ce, retval.ptr(), 0, nullptr, nullptr);
    throwErrorIfOccurred();
    return retval;
}

Variant call(zend_class_entry *ce, zend_function *func, const ArgList &args) {
    Variant retval{};
    Args _args(args);
    zend_call_known_function(func, nullptr, ce, retval.ptr(), _args.count(), _args.ptr(), nullptr);
    throwErrorIfOccurred();
    return retval;
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
    Variant result;
    zend_op_array *new_op_array = zend_include_or_eval(filename, type);

    if (UNEXPECTED(new_op_array == ZEND_FAKE_OP_ARRAY)) {
        return true;
    } else if (EXPECTED(new_op_array != nullptr && EG(exception) == nullptr)) {
        zend_execute(new_op_array, result.ptr());
    }

    if (EXPECTED(new_op_array != nullptr)) {
        destroy_op_array(new_op_array);
        efree_size(new_op_array, sizeof(zend_op_array));
    } else {
        result = false;
    }
    throwErrorIfOccurred();

    return result;
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

bool empty(const Variant &v, const std::initializer_list<std::pair<Operation, const Variant>> &list) {
    Variant tmp(v.const_ptr(), Ctor::Indirect);
    for (const auto &expr : list) {
        if (expr.first == ArrayDimFetch) {
            if (!tmp.isArray()) {
                return true;
            } else {
                tmp = tmp.item(expr.second);
            }
        } else if (expr.first == PropertyFetch) {
            if (!tmp.isObject()) {
                return true;
            } else {
                Object o(tmp);
                tmp = o.attr(expr.second);
            }
        } else {
            abort();
        }
        if (!tmp) {
            return true;
        }
    }
    return !tmp;
}

Variant getStaticProperty(const String &class_name, const String &prop) {
    const auto ce = getClassEntry(class_name);
    if (UNEXPECTED(!ce)) {
        throwError("class '%s' is undefined.", class_name.toCString());
        return {};
    }
    return {zend_read_static_property_ex(ce, prop.str(), true), Ctor::Move};
}

Variant getStaticProperty(zend_class_entry *ce, uint32_t offset) {
    if (UNEXPECTED(CE_STATIC_MEMBERS(ce) == NULL)) {
        zend_class_init_statics(ce);
    }
    return Variant{CE_STATIC_MEMBERS(ce) + offset, Ctor::Indirect};
}

bool hasStaticProperty(const String &class_name, const String &prop) {
    const auto ce = getClassEntry(class_name);
    if (UNEXPECTED(!ce)) {
        throwError("class '%s' is undefined.", class_name.toCString());
        return {};
    }
    return zend_hash_exists(&ce->properties_info, prop.str());
}

bool setStaticProperty(const String &class_name, const String &prop, const Variant &v) {
    const auto ce = getClassEntry(class_name);
    if (UNEXPECTED(!ce)) {
        throwError("class '%s' is undefined.", class_name.toCString());
        return {};
    }
    const auto zv = NO_CONST_V(v);
    Z_TRY_ADDREF_P(zv);
    return zend_update_static_property_ex(ce, prop.str(), zv) == SUCCESS;
}

uint32_t getPropertyOffset(const String &class_name, const String &prop) {
    const auto ce = getClassEntry(class_name);
    if (UNEXPECTED(!ce)) {
        throwError("class '%s' is undefined.", class_name.toCString());
        return 0;
    }
    return getPropertyOffset(ce, prop);
}

uint32_t getPropertyOffset(zend_class_entry *ce, const String &prop) {
    auto prev_scope = EG(fake_scope);
    EG(fake_scope) = ce;
    auto prop_info = zend_get_property_info(ce, prop.str(), 0);
    if (UNEXPECTED(!prop_info)) {
        throwError("property '%s::%s' is undefined.", ce->name->val, prop.toCString());
        return 0;
    }
    EG(fake_scope) = prev_scope;
    return prop_info->offset;
}
}  // namespace php
