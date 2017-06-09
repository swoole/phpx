/*
  +----------------------------------------------------------------------+
  | PHP-X                                                               |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <mikan.tenny@gmail.com>                        |
  +----------------------------------------------------------------------+
*/

#include "phpx.h"

using namespace std;

namespace php
{

unordered_map<string, Resource *> resource_map;
unordered_map<string, Class*> class_map;
unordered_map<string, Interface*> interface_map;
map<const char *, map<const char *, method_t, strCmp>, strCmp> method_map;
map<const char *, function_t, strCmp> function_map;
unordered_map<string, Extension*> _name_to_extension;
unordered_map<int, Extension*> _module_number_to_extension;

int arg_list_size = 0;
zval **arg_list = nullptr;

Variant ini_get(string varname)
{
    char* str = zend_ini_string((char *) varname.c_str(), (uint) varname.length(), 0);
    return Variant(str);
}
void error(int level, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    php_verror(NULL, "", level, format, args);
    va_end(args);
}

void echo(const char *format, ...)
{
    va_list args;
    char *buffer;
    size_t size;

    va_start(args, format);
    size = vspprintf(&buffer, 0, format, args);
    PHPWRITE(buffer, size);
    efree(buffer);
    va_end(args);
}

int extension_startup(int type, int module_number)
{
    zend_module_entry *module;
    void *ptr;
    ZEND_HASH_FOREACH_PTR(&module_registry, ptr)
    {
        module = (zend_module_entry *) ptr;
        if (module_number == module->module_number)
        {
            Extension *extension = _name_to_extension[module->name];
            extension->started = true;
            if (extension->onStart)
            {
                extension->onStart();
            }
            _module_number_to_extension[module_number] = extension;
            break;
        }
    }
    ZEND_HASH_FOREACH_END();
    return SUCCESS;
}

void extension_info(zend_module_entry *module)
{
    Extension *extension = _module_number_to_extension[module->module_number];
    if (extension->header.size() > 0 && extension->body.size() > 0)
    {
        php_info_print_table_start();
        auto header = extension->header;
        size_t size = header.size();
        switch (size)
        {
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
        for (auto row : extension->body)
        {
            size = row.size();
            switch (size)
            {
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

int extension_shutdown(int type, int module_number)
{
    Extension *extension = _module_number_to_extension[module_number];
    if (extension->onShutdown)
    {
        extension->onShutdown();
    }
    _name_to_extension.erase(extension->name);
    _module_number_to_extension.erase(module_number);
    delete extension;

    return SUCCESS;
}

int extension_before_request(int type, int module_number)
{
    Extension *extension = _module_number_to_extension[module_number];
    if (extension->onBeforeRequest)
    {
        extension->onBeforeRequest();
    }

    return SUCCESS;
}

int extension_after_request(int type, int module_number)
{
    Extension *extension = _module_number_to_extension[module_number];
    if (extension->onAfterRequest)
    {
        extension->onAfterRequest();
    }

    return SUCCESS;
}

void _exec_function(zend_execute_data *data, zval *return_value)
{
    function_t func = function_map[(const char *) data->func->common.function_name->val];
    Args args;

    zval *param_ptr = ZEND_CALL_ARG(EG(current_execute_data), 1);
    int arg_count = ZEND_CALL_NUM_ARGS(EG(current_execute_data));

    while (arg_count-- > 0)
    {
        args.append(param_ptr);
        param_ptr++;
    }
    Variant _retval(return_value, true);
    func(args, _retval);
}

void _exec_method(zend_execute_data *data, zval *return_value)
{
    method_t func = method_map[(const char *) data->func->common.scope->name->val][(const char *) data->func->common.function_name->val];
    Args args;

    Object _this(&data->This, true);

    zval *param_ptr = ZEND_CALL_ARG(EG(current_execute_data), 1);
    int arg_count = ZEND_CALL_NUM_ARGS(EG(current_execute_data));

    while (arg_count-- > 0)
    {
        args.append(param_ptr);
        param_ptr++;
    }
    Variant _retval(return_value, true);
    func(_this, args, _retval);
}

}
