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

BEGIN_EXTERN_C()
#include "zend_ini.h"
END_EXTERN_C()

namespace php {
std::map<const char *, std::map<const char *, Method *, StrCmp>, StrCmp> method_map;
std::map<const char *, Function *, StrCmp> function_map;
std::map<const char *, zend_fcall_info_cache *, StrCmp> func_cache_map;

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
    zend_bailout();
}

void request_shutdown() {
    for (auto kv : func_cache_map) {
        efree(kv.second);
    }
    func_cache_map.clear();
}

void throwException(const char *name, const char *message, int code) {
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        php_error_docref(nullptr, E_WARNING, "class '%s' undefined.", name);
        return;
    }
    zend_throw_exception(ce, message, code);
}

Object catchException() {
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

static ZEND_RESULT_CODE _check_args_num(const zend_execute_data *data, const int num_args) {
    const uint32_t min_num_args = data->func->common.required_num_args;
    const uint32_t max_num_args = data->func->common.num_args;

    if (num_args < min_num_args || (num_args > max_num_args && max_num_args > 0)) {
        zend_wrong_parameters_count_error(min_num_args, max_num_args);
        return FAILURE;
    }

    return SUCCESS;
}

#define FUNC_RESERVE_INDEX 3

void _exec_function(zend_execute_data *data, zval *return_value) {
    Function *func = nullptr;
    const auto fn_reserved = data->func->internal_function.reserved;
    const auto fn_name = data->func->common.function_name->val;
    if (EXPECTED(fn_reserved[FUNC_RESERVE_INDEX])) {
        func = static_cast<Function *>(fn_reserved[FUNC_RESERVE_INDEX]);
    } else {
        auto iter_func = function_map.find(fn_name);
        if (iter_func == function_map.end()) {
            error(E_WARNING, "[phpx::_exec_function] function '%s' not found", fn_name);
            return;
        }
        func = iter_func->second;
        fn_reserved[FUNC_RESERVE_INDEX] = func;
    }

    Args args;
    zval *param_ptr = ZEND_CALL_ARG(EG(current_execute_data), 1);
    int arg_count = ZEND_CALL_NUM_ARGS(EG(current_execute_data));

    if (_check_args_num(data, arg_count) == FAILURE) {
        return;
    }

    while (arg_count-- > 0) {
        args.append(param_ptr);
        param_ptr++;
    }
    auto retval = func->impl(args);
    retval.moveTo(return_value);
}

void _exec_method(zend_execute_data *data, zval *return_value) {
    Method *method = nullptr;
    const auto fn_reserved = data->func->internal_function.reserved;
    const auto class_name = data->func->common.scope->name->val;
    const auto method_name = data->func->common.function_name->val;
    if (EXPECTED(fn_reserved[FUNC_RESERVE_INDEX])) {
        method = static_cast<Method *>(fn_reserved[FUNC_RESERVE_INDEX]);
    } else {
        const auto iter_class = method_map.find(class_name);
        if (iter_class == method_map.end()) {
            error(E_WARNING, "[phpx::_exec_method] class '%s' not found", class_name);
            return;
        }
        auto iter_method = iter_class->second.find(method_name);
        if (iter_method == iter_class->second.end()) {
            error(E_WARNING, "[phpx::_exec_method] method '%s' not found", method_name);
            return;
        }

        method = iter_method->second;
        fn_reserved[FUNC_RESERVE_INDEX] = method;
    }

    Args args;
    Object _this(&data->This);

    zval *param_ptr = ZEND_CALL_ARG(EG(current_execute_data), 1);
    int arg_count = ZEND_CALL_NUM_ARGS(EG(current_execute_data));

    if (_check_args_num(data, arg_count) == FAILURE) {
        return;
    }

    while (arg_count-- > 0) {
        args.append(param_ptr);
        param_ptr++;
    }
    auto retval = method->impl(_this, args);
    retval.moveTo(return_value);
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

    zend_fcall_info_cache *fci_cache = nullptr;

    if (Z_TYPE_P(function_name) == IS_STRING && !zobject) {
        auto iter = func_cache_map.find(Z_STRVAL_P(function_name));
        if (iter == func_cache_map.end()) {
            fci_cache = (zend_fcall_info_cache *) emalloc(sizeof(*fci_cache));
            if (zend_is_callable_ex(&fci.function_name, fci.object, 0, NULL, fci_cache, nullptr)) {
                func_cache_map[Z_STRVAL_P(function_name)] = fci_cache;
            } else {
                efree(fci_cache);
                fci_cache = nullptr;
            }
        } else {
            fci_cache = iter->second;
        }
    }

    zend_call_function(&fci, fci_cache);
}

Variant _call(const zval *object, const zval *func, Args &args) {
    Variant retval{};
    _call_user_function_impl(object, func, retval.ptr(), args.count(), args.ptr());
    return retval;
}

Variant _call(const zval *object, const zval *func) {
    Variant retval{};
    _call_user_function_impl(object, func, retval.ptr(), 0, nullptr);
    return retval;
}

Variant call(const Variant &func, Array &args) {
    Args _args(args.count());
    for (size_t i = 0; i < args.count(); i++) {
        _args.append(args[i]);
    }
    return _call(nullptr, func.const_ptr(), _args);
}

Variant call(const Variant &func, Args &args) {
    return _call(nullptr, func.const_ptr(), args);
}

Variant call(const Variant &func, const std::initializer_list<Variant> &args) {
    Args _args(args.size());
    for (const auto &arg : args) {
        _args.append(const_cast<Variant &>(arg).ptr());
    }
    return _call(nullptr, func.const_ptr(), _args);
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
        char *eval_desc = zend_make_compiled_string_description("eval()'d code");
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

static Variant _include(zend_string *filename, const int type) {
    zend_op_array *new_op_array = zend_include_or_eval(filename, type);
    if (UNEXPECTED(EG(exception) != nullptr)) {
        if (new_op_array != ZEND_FAKE_OP_ARRAY && new_op_array != nullptr) {
            destroy_op_array(new_op_array);
            efree_size(new_op_array, sizeof(zend_op_array));
        }
        return nullptr;
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

Variant include(const String &file) {
    return _include(file.str(), ZEND_INCLUDE);
}

Variant include_once(const String &file) {
    return _include(file.str(), ZEND_INCLUDE_ONCE);
}

Variant require(const String &file) {
    return _include(file.str(), ZEND_REQUIRE);
}

Variant require_once(const String &file) {
    return _include(file.str(), ZEND_REQUIRE_ONCE);
}

Variant eval(const String &script) {
    return _include(script.str(), ZEND_EVAL);
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
}  // namespace php
