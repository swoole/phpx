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
std::map<const char *, std::map<const char *, Method *, StrCmp>, StrCmp> method_map;
std::map<const char *, Function *, StrCmp> function_map;

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

Variant global(const String &name) {
    zend_is_auto_global(name.ptr());
    zval *var = zend_hash_find_ind(&EG(symbol_table), name.ptr());
    if (!var) {
        return false;
    }
    return {var};
}

void throwException(const char *name, const char *message, int code) {
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        php_error_docref(nullptr, E_WARNING, "class '%s' undefined.", name);
        return;
    }
    zend_throw_exception(ce, message, code);
}

static inline ZEND_RESULT_CODE _check_args_num(const zend_execute_data *data, const int num_args) {
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

zend_result _call_user_function_impl(const zval *object,
                                     const zval *function_name,
                                     zval *retval_ptr,
                                     uint32_t param_count,
                                     zval params[],
                                     HashTable *named_params) /* {{{ */
{
    zend_fcall_info fci;

    fci.size = sizeof(fci);
    if (object) {
        ZEND_ASSERT(Z_TYPE_P(object) == IS_OBJECT);
        fci.object = Z_OBJ_P(object);
    } else {
        fci.object = nullptr;
    }
    ZVAL_COPY_VALUE(&fci.function_name, function_name);
    fci.retval = retval_ptr;
    fci.param_count = param_count;
    fci.params = params;
    fci.named_params = named_params;

    return zend_call_function(&fci, nullptr);
}

Variant _call(const zval *object, const zval *func, Args &args) {
    Variant retval{};
    _call_user_function_impl(object, func, retval.ptr(), args.count(), args.ptr(), nullptr);
    return retval;
}

Variant _call(const zval *object, const zval *func) {
    Variant retval{};
    _call_user_function_impl(object, func, retval.ptr(), 0, nullptr, nullptr);
    return retval;
}

Variant call(const Variant &func, Array &args) {
    Args _args;
    for (size_t i = 0; i < args.count(); i++) {
        _args.append(args[i]);
    }
    return _call(nullptr, func.const_ptr(), _args);
}

Variant call(const Variant &func, const std::initializer_list<Variant> &args) {
    Args _args;
    for (const auto &arg : args) {
        _args.append(const_cast<Variant &>(arg).ptr());
    }
    return _call(nullptr, func.const_ptr(), _args);
}

Variant include(const String &file) {
    zend_file_handle file_handle;
    zend_stream_init_filename(&file_handle, file.data());
    int ret = php_stream_open_for_zend_ex(&file_handle, USE_PATH | STREAM_OPEN_FOR_INCLUDE);
    if (ret != SUCCESS) {
        return false;
    }

    if (!file_handle.opened_path) {
        file_handle.opened_path = zend_string_copy(file.ptr());
    }
    zend_string *opened_path = zend_string_copy(file_handle.opened_path);
    zval dummy;
    Variant retval = false;
    zend_op_array *new_op_array;
    ZVAL_NULL(&dummy);
    if (zend_hash_add(&EG(included_files), opened_path, &dummy)) {
        new_op_array = zend_compile_file(&file_handle, ZEND_REQUIRE);
    } else {
        new_op_array = nullptr;
    }
    zend_destroy_file_handle(&file_handle);
    zend_string_release(opened_path);
    if (!new_op_array) {
        return false;
    }

    ZVAL_UNDEF(retval.ptr());
    zend_execute(new_op_array, retval.ptr());

    destroy_op_array(new_op_array);
    efree(new_op_array);
    return retval;
}

PHPX_API void eval(const String &script) {
    zend_eval_stringl((char *) script.data(), script.length(), nullptr, "eval()'d code");
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
