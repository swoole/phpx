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
std::unordered_map<std::string, Resource *> resource_map;
std::unordered_map<std::string, Class *> class_map;
std::unordered_map<std::string, Interface *> interface_map;
std::map<const char *, std::map<const char *, Method *, StrCmp>, StrCmp> method_map;
std::map<const char *, Function *, StrCmp> function_map;
std::map<int, void *> object_array;
std::unordered_map<std::string, std::shared_ptr<Extension>> _name_to_extension;
std::unordered_map<int, std::shared_ptr<Extension>> _module_number_to_extension;

void error(int level, const char *format, ...) {
    va_list args;
    va_start(args, format);
    php_verror(nullptr, "", level, format, args);
    va_end(args);
}

Variant constant(const char *name) {
    zend_string *_name = zend_string_init(name, strlen(name), false);
    zval *val = zend_get_constant_ex(_name, nullptr, ZEND_FETCH_CLASS_SILENT);
    zend_string_free(_name);
    if (val == nullptr) {
        return {};
    }
    Variant retval(val);
    return retval;
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

zend_result extension_startup(int type, int module_number) {
    void *ptr;
    ZEND_HASH_FOREACH_PTR(&module_registry, ptr) {
        auto *module = static_cast<zend_module_entry *>(ptr);
        if (module_number == module->module_number) {
            auto extension = _name_to_extension[module->name];
            extension->started = true;
            extension->registerIniEntries(module_number);
            if (extension->onStart) {
                extension->onStart();
            }
            _module_number_to_extension[module_number] = extension;
            break;
        }
    }
    ZEND_HASH_FOREACH_END();
    return SUCCESS;
}

void extension_info(zend_module_entry *module) {
    auto extension = _module_number_to_extension[module->module_number];
    if (!extension->header.empty() && !extension->body.empty()) {
        php_info_print_table_start();
        auto header = extension->header;
        size_t size = header.size();
        switch (size) {
        case 2:
            php_info_print_table_header(size, header[0].c_str(), header[1].c_str());
            break;
        case 3:
            php_info_print_table_header(size, header[0].c_str(), header[1].c_str(), header[2].c_str());
            break;
        default:
            error(E_WARNING, "invalid info header size.");
            return;
        }
        for (auto row : extension->body) {
            size = row.size();
            switch (size) {
            case 2:
                php_info_print_table_row(size, row[0].c_str(), row[1].c_str());
                break;
            case 3:
                php_info_print_table_row(size, row[0].c_str(), row[1].c_str(), row[2].c_str());
                break;
            default:
                error(E_WARNING, "invalid info row size.");
                return;
            }
        }
        php_info_print_table_end();
    }
}

zend_result extension_shutdown(int type, int module_number) {
    auto extension = _module_number_to_extension[module_number];
    if (extension->onShutdown) {
        extension->onShutdown();
    }
    extension->unregisterIniEntries(module_number);
    return SUCCESS;
}

zend_result extension_before_request(int type, int module_number) {
    auto extension = _module_number_to_extension[module_number];
    if (extension->onBeforeRequest) {
        extension->onBeforeRequest();
    }
    return SUCCESS;
}

zend_result extension_after_request(int type, int module_number) {
    auto extension = _module_number_to_extension[module_number];
    if (extension->onAfterRequest) {
        extension->onAfterRequest();
    }
    return SUCCESS;
}

static inline ZEND_RESULT_CODE _check_args_num(zend_execute_data *data, int num_args) {
    uint32_t min_num_args = data->func->common.required_num_args;
    uint32_t max_num_args = data->func->common.num_args;

    if (num_args < min_num_args || (num_args > max_num_args && max_num_args > 0)) {
        zend_wrong_parameters_count_error(min_num_args, max_num_args);
        return FAILURE;
    }

    return SUCCESS;
}

void _exec_function(zend_execute_data *data, zval *return_value) {
    auto iter_func = function_map.find(data->func->common.function_name->val);
    if (iter_func == function_map.end()) {
        error(E_WARNING, "[phpx::_exec_function] function '%s' not found", data->func->common.function_name->val);
        return;
    }

    Function *func = iter_func->second;
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
    auto iter_class = method_map.find(data->func->common.scope->name->val);
    if (iter_class == method_map.end()) {
        error(E_WARNING, "[phpx::_exec_method] class '%s' not found", data->func->common.scope->name->val);
        return;
    }
    auto iter_method = iter_class->second.find((const char *) data->func->common.function_name->val);
    if (iter_method == iter_class->second.end()) {
        error(E_WARNING, "[phpx::_exec_method] method '%s' not found", data->func->common.function_name->val);
        return;
    }

    auto me = iter_method->second;
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
    auto retval = me->impl(_this, args);
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
    Variant retval;
    if (_call_user_function_impl(object, func, retval.ptr(), args.count(), args.ptr(), nullptr) == SUCCESS) {
        return retval;
    } else {
        return {};
    }
}

Variant _call(const zval *object, const zval *func) {
    Variant retval = false;
    if (_call_user_function_impl(object, func, retval.ptr(), 0, nullptr, nullptr) == 0) {
        return retval;
    } else {
        return {};
    }
}

Variant call(const Variant &func, const Array &args) {
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

Variant include(const std::string &file) {
    zend_file_handle file_handle;
    zend_stream_init_filename(&file_handle, file.c_str());
    int ret = php_stream_open_for_zend_ex(&file_handle, USE_PATH | STREAM_OPEN_FOR_INCLUDE);
    if (ret != SUCCESS) {
        return false;
    }

    if (!file_handle.opened_path) {
        file_handle.opened_path = zend_string_init(file.c_str(), file.length(), false);
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
