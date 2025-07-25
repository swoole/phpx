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
Extension::Extension(const char *_name, const char *_version) {
    module.name = _name;
    module.version = _version;
    name = _name;
    version = _version;
    _name_to_extension[_name] = std::shared_ptr<Extension>(this);
    functions = nullptr;
}

void Extension::require(const char *name, const char *version) {
    checkStartupStatus(BEFORE_START, __func__);
    if (deps_.size() < deps_count + 2) {
        deps_.resize(deps_.size() + 8);
    }

    module.deps = deps_.data();
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
}

bool Extension::registerClass(Class *c) const {
    checkStartupStatus(AFTER_START, __func__);
    c->activate();
    class_map[c->getName()] = c;
    return true;
}

bool Extension::registerInterface(Interface *i) const {
    checkStartupStatus(AFTER_START, __func__);
    i->activate();
    interface_map[i->getName()] = i;
    return true;
}

bool Extension::registerResource(const char *name, resource_dtor dtor) const {
    checkStartupStatus(AFTER_START, __func__);
    auto *res = new Resource;
    int type = zend_register_list_destructors_ex(dtor, nullptr, name, 0);
    if (type < 0) {
        return false;
    }
    res->type = type;
    res->name = name;
    resource_map[name] = res;
    return true;
}

void Extension::registerConstant(const char *name, long v) const {
    zend_register_long_constant(name, strlen(name), v, CONST_CS | CONST_PERSISTENT, module.module_number);
}

void Extension::registerConstant(const char *name, int v) const {
    zend_register_long_constant(name, strlen(name), v, CONST_CS | CONST_PERSISTENT, module.module_number);
}

void Extension::registerConstant(const char *name, bool v) const {
    zend_register_bool_constant(name, strlen(name), v, CONST_CS | CONST_PERSISTENT, module.module_number);
}

void Extension::registerConstant(const char *name, const char *v) const {
    zend_register_string_constant(name, strlen(name), v, CONST_CS | CONST_PERSISTENT, module.module_number);
}

void Extension::registerConstant(const char *name, const char *v, size_t len) const {
    zend_register_stringl_constant(name, strlen(name), v, len, CONST_CS | CONST_PERSISTENT, module.module_number);
}

void Extension::registerConstant(const char *name, double v) const {
    zend_register_double_constant(name, strlen(name), v, CONST_CS | CONST_PERSISTENT, module.module_number);
}

void Extension::registerConstant(const char *name, const std::string &v) const {
    zend_register_stringl_constant(
        name, strlen(name), v.c_str(), v.length(), CONST_CS | CONST_PERSISTENT, module.module_number);
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
    if (ini_entries.empty()) {
        return;
    }

    auto *entry_defs = new zend_ini_entry_def[ini_entries.size() + 1];

    for (auto i = 0; i < ini_entries.size(); ++i) {
        IniEntry &entry = ini_entries[i];
        zend_ini_entry_def def = {
            entry.name.c_str(),
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            entry.default_value.c_str(),
            nullptr,
            (uint32_t) entry.default_value.size(),
            (uint16_t) entry.name.size(),
            (uint8_t) entry.modifiable,
        };
        entry_defs[i] = def;
    }
    memset(entry_defs + ini_entries.size(), 0, sizeof(*entry_defs));

    zend_register_ini_entries(entry_defs, module_number);
    delete[] entry_defs;
}

void Extension::unregisterIniEntries(int module_number) const {
    if (!ini_entries.empty()) {
        zend_unregister_ini_entries(module_number);
    }
}

void Extension::checkStartupStatus(const StartupStatus status, const char *func) const {
    if (status == AFTER_START && !this->started) {
        zend_error(E_CORE_ERROR, "php::%s must be called after startup.", func);
    } else if (status == BEFORE_START && this->started) {
        zend_error(E_CORE_ERROR, "php::%s must be called before startup.", func);
    }
}

void Extension::addIniEntry(const char *name, const char *default_value, int modifiable) {
    IniEntry entry;
    entry.name = name;
    entry.default_value = default_value;
    entry.modifiable = modifiable;
    ini_entries.push_back(entry);
}

Interface::Interface(const char *name) {
    this->name = name;
    INIT_CLASS_ENTRY_EX(_ce, name, strlen(name), nullptr);
    ce = nullptr;
    functions = nullptr;
}

bool Interface::activate() {
    if (activated) {
        return false;
    }
    _ce.info.internal.builtin_functions = functions;
    ce = zend_register_internal_interface(&_ce TSRMLS_CC);
    if (ce == nullptr) {
        return false;
    }
    activated = true;
    return true;
}
}  // namespace php
