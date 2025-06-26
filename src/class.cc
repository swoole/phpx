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

Class::Class(const char *name) {
    class_name = name;
    INIT_CLASS_ENTRY_EX(_ce, name, strlen(name), NULL);
    parent_ce = NULL;
    ce = NULL;
    activated = false;
    functions = nullptr;
}

bool Class::extends(zend_class_entry *_parent_class) {
    if (activated) {
        return false;
    }
    parent_class_name = string(_parent_class->name->val, _parent_class->name->len);
    parent_ce = _parent_class;
    return parent_ce != nullptr;
}

bool Class::extends(Class *parent) {
    if (activated) {
        return false;
    }
    parent_class_name = parent->getName();
    parent_ce = parent->ptr();
    return parent_ce != nullptr;
}

bool Class::implements(const char *name) {
    if (activated) {
        return false;
    }
    if (interfaces.find(name) != interfaces.end()) {
        return false;
    }
    zend_class_entry *interface_ce = getClassEntry(name);
    if (interface_ce == NULL) {
        return false;
    }
    interfaces[name] = interface_ce;
    return true;
}

bool Class::implements(zend_class_entry *interface_ce) {
    if (activated) {
        return false;
    }
    interfaces[interface_ce->name->val] = interface_ce;
    return true;
}

bool Class::addConstant(const char *name, Variant v) {
    if (activated) {
        return false;
    }
    Constant c;
    c.name = name;
    ZVAL_COPY(&c.value, v.ptr());
    constants.push_back(c);
    return true;
}

bool Class::addProperty(const char *name, Variant v, int flags) {
    if (activated) {
        return false;
    }
    Property p;
    p.name = name;
    ZVAL_COPY(&p.value, v.ptr());
    p.flags = flags;
    propertys.push_back(p);
    return true;
}

bool Class::registerFunctions(const zend_function_entry *_functions) {
    functions = copy_function_entries(_functions);
    zend_function_entry *ptr = functions;
    while (ptr->fname) {
        ptr->handler = _exec_method;
        auto iter1 = method_map.find(class_name.c_str());
        if (iter1 == method_map.end()) {
            return false;
        }
        auto iter2 = iter1->second.find(ptr->fname);
        if (iter2 == iter1->second.end()) {
            error(E_ERROR, "No function named %s", ptr->fname);
            return false;
        }
        ptr++;
    }
    return true;
}

bool Class::alias(const char *alias_name) {
    if (activated) {
        error(E_WARNING, "Please execute alias method before activate.");
        return false;
    }
    aliases.push_back(alias_name);
    return true;
}

bool Class::activate() {
    if (activated) {
        return false;
    }
    /**
     * register methods
     */
    _ce.info.internal.builtin_functions = functions;
    if (parent_ce) {
        ce = zend_register_internal_class_ex(&_ce, parent_ce);
    } else {
        ce = zend_register_internal_class(&_ce TSRMLS_CC);
    }
    if (ce == NULL) {
        return false;
    }
    /**
     * implements interface
     */
    for (auto i = interfaces.begin(); i != interfaces.end(); i++) {
        zend_do_implement_interface(ce, interfaces[i->first]);
    }
    /**
     * register property
     */
    for (int i = 0; i != propertys.size(); i++) {
        Property p = propertys[i];
        if (Z_TYPE(p.value) == IS_STRING) {
            zend_declare_property_stringl(
                ce, p.name.c_str(), p.name.length(), Z_STRVAL(p.value), Z_STRLEN(p.value), p.flags);
        } else {
            zend_declare_property(ce, p.name.c_str(), p.name.length(), &p.value, p.flags);
        }
    }
    /**
     * register constant
     */
    for (int i = 0; i != constants.size(); i++) {
        if (Z_TYPE(constants[i].value) == IS_STRING) {
            zend_declare_class_constant_stringl(ce,
                                                constants[i].name.c_str(),
                                                constants[i].name.length(),
                                                Z_STRVAL(constants[i].value),
                                                Z_STRLEN(constants[i].value));
        } else {
            zend_declare_class_constant(ce, constants[i].name.c_str(), constants[i].name.length(), &constants[i].value);
        }
    }
    for (int i = 0; i < aliases.size(); i++) {
        string alias = aliases[i];
#if PHP_VERSION_ID > 70300
        if (zend_register_class_alias_ex(alias.c_str(), alias.length(), ce, 1) < 0)
#else
        if (zend_register_class_alias_ex(alias.c_str(), alias.length(), ce) < 0)
#endif
        {
            return false;
        }
    }
    activated = true;
    return true;
}

}  // namespace php
