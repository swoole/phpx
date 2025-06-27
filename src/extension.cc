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
  | Author: Tianfeng Han  <mikan.tenny@gmail.com>                        |
  +----------------------------------------------------------------------+
*/

#include "phpx.h"

using namespace std;

namespace php {

Extension::Extension(const char *_name, const char *_version) {
    module.name = _name;
    module.version = _version;
    name = _name;
    version = _version;
    _name_to_extension[_name] = std::shared_ptr<Extension>(this);
    functions = nullptr;
}

bool Extension::require(const char *name, const char *version) {
    this->checkStartupStatus(BEFORE_START, __func__);
    if (module.deps == nullptr) {
        module.deps = static_cast<const zend_module_dep *>(calloc(16, sizeof(zend_module_dep)));
        if (module.deps == nullptr) {
            return false;
        }
        deps_array_size = 16;
    } else if (deps_count + 1 == deps_array_size) {
        deps_array_size *= 2;
        void *new_array = realloc((void *) module.deps, deps_array_size * sizeof(zend_module_dep));
        if (new_array == nullptr) {
            return false;
        }
        module.deps = static_cast<const zend_module_dep *>(new_array);
    }

    auto *deps_array = const_cast<zend_module_dep *>(module.deps);
    deps_array[deps_count].name = name;
    deps_array[deps_count].rel = nullptr;
    deps_array[deps_count].version = version;
    deps_array[deps_count].type = MODULE_DEP_REQUIRED;

    deps_array[deps_count + 1].name = nullptr;
    deps_array[deps_count + 1].rel = nullptr;
    deps_array[deps_count + 1].version = nullptr;
    deps_array[deps_count + 1].type = 0;

    deps_count++;
    return true;
}

bool Extension::registerClass(Class *c) {
    this->checkStartupStatus(AFTER_START, __func__);
    c->activate();
    class_map[c->getName()] = c;
    return true;
}

bool Extension::registerInterface(Interface *i) {
    this->checkStartupStatus(AFTER_START, __func__);
    i->activate();
    interface_map[i->getName()] = i;
    return true;
}

bool Extension::registerResource(const char *name, resource_dtor dtor) {
    this->checkStartupStatus(AFTER_START, __func__);
    Resource *res = new Resource;
    int type = zend_register_list_destructors_ex(dtor, NULL, name, 0);
    if (type < 0) {
        return false;
    }
    res->type = type;
    res->name = name;
    resource_map[name] = res;
    return true;
}

void Extension::registerConstant(const char *name, long v) {
    zend_register_long_constant(name, strlen(name), v, CONST_CS | CONST_PERSISTENT, module.module_number);
}

void Extension::registerConstant(const char *name, int v) {
    zend_register_long_constant(name, strlen(name), v, CONST_CS | CONST_PERSISTENT, module.module_number);
}

void Extension::registerConstant(const char *name, bool v) {
    zend_register_bool_constant(name, strlen(name), v, CONST_CS | CONST_PERSISTENT, module.module_number);
}

void Extension::registerConstant(const char *name, const char *v) {
    zend_register_string_constant(name, strlen(name), (char *) v, CONST_CS | CONST_PERSISTENT, module.module_number);
}

void Extension::registerConstant(const char *name, const char *v, size_t len) {
    zend_register_stringl_constant(
        name, strlen(name), (char *) v, len, CONST_CS | CONST_PERSISTENT, module.module_number);
}

void Extension::registerConstant(const char *name, double v) {
    zend_register_double_constant(name, strlen(name), v, CONST_CS | CONST_PERSISTENT, module.module_number);
}

void Extension::registerConstant(const char *name, float v) {
    zend_register_double_constant(name, strlen(name), v, CONST_CS | CONST_PERSISTENT, module.module_number);
}

void Extension::registerConstant(const char *name, string &v) {
    zend_register_stringl_constant(
        name, strlen(name), (char *) v.c_str(), v.length(), CONST_CS | CONST_PERSISTENT, module.module_number);
}

bool Extension::registerFunctions(const zend_function_entry *_functions) {
    checkStartupStatus(BEFORE_START, __func__);
    functions = copy_function_entries(_functions);
    zend_function_entry *ptr = functions;

    while (ptr->fname) {
        ptr->handler = _exec_function;
        if (function_map.find(ptr->fname) == function_map.end()) {
            error(E_ERROR, "No function named %s", ptr->fname);
            return false;
        }
        ptr++;
    }
    module.functions = functions;
    return true;
}

void Extension::registerIniEntries(int module_number) {
    if (!ini_entries.size()) {
        return;
    }

    zend_ini_entry_def *entry_defs = new zend_ini_entry_def[ini_entries.size() + 1];

    for (auto i = 0; i < ini_entries.size(); ++i) {
        IniEntry &entry = ini_entries[i];
        zend_ini_entry_def def = {
            entry.name.c_str(),                    // name
            NULL,                                  // on_modify
            NULL,                                  // mh_arg1
            NULL,                                  // mh_arg2
            NULL,                                  // mh_arg3
            entry.default_value.c_str(),           // value
            NULL,                                  // displayer
            (uint32_t) entry.modifiable,           // modifiable
            (uint16_t) entry.name.size(),          // name_length
            (uint8_t) entry.default_value.size(),  // value_length
        };
        entry_defs[i] = def;
    }
    memset(entry_defs + ini_entries.size(), 0, sizeof(*entry_defs));

    zend_register_ini_entries(entry_defs, module_number);
    delete[] entry_defs;
}

void Extension::unregisterIniEntries(int module_number) {
    if (ini_entries.size()) {
        zend_unregister_ini_entries(module_number);
    }
}

}  // namespace php
