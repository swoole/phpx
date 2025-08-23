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
#include "zend_inheritance.h"
END_EXTERN_C()

namespace php {
Class::Class(const char *name) {
    class_name = name;
    INIT_CLASS_ENTRY_EX(_ce, name, strlen(name), nullptr);
    parent_ce = nullptr;
    ce = nullptr;
    activated = false;
    functions = nullptr;
}

bool Class::extends(zend_class_entry *_parent_class) {
    if (activated) {
        return false;
    }
    parent_class_name = std::string(_parent_class->name->val, _parent_class->name->len);
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

bool Class::implements(zend_class_entry *if_ce) {
    if (activated) {
        return false;
    }
    interfaces.push_back(if_ce);
    return true;
}

bool Class::implements(const Interface *_if) {
    return implements(_if->ptr());
}

bool Class::addConstant(const char *name, const Variant &v) {
    if (activated) {
        return false;
    }
    Constant c;
    c.name = name;
    ZVAL_COPY(&c.value, v.const_ptr());
    constants.push_back(c);
    return true;
}

bool Class::addProperty(const char *name, const Variant &v, int flags) {
    if (activated) {
        return false;
    }
    Property p;
    p.name = name;
    ZVAL_COPY(&p.value, v.const_ptr());
    p.flags = flags;
    properties.push_back(p);
    return true;
}

bool Class::addStaticProperty(const char *name, const Variant &v, int flags) {
    return addProperty(name, v, flags | ZEND_ACC_STATIC);
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
        return false;
    }
    aliases.emplace_back(alias_name);
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
        ce = zend_register_internal_class(&_ce);
    }
    if (ce == nullptr) {
        return false;
    }
    /**
     * implements interface
     */
    for (auto const if_ce : interfaces) {
        zend_do_implement_interface(ce, if_ce);
    }
    /**
     * register property
     */
    for (auto p : properties) {
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
    for (auto &constant : constants) {
        if (Z_TYPE(constant.value) == IS_STRING) {
            zend_declare_class_constant_stringl(
                ce, constant.name.c_str(), constant.name.length(), Z_STRVAL(constant.value), Z_STRLEN(constant.value));
        } else {
            zend_declare_class_constant(ce, constant.name.c_str(), constant.name.length(), &constant.value);
        }
    }
    for (const auto &alias : aliases) {
        if (zend_register_class_alias_ex(alias.c_str(), alias.length(), ce, true) < 0) {
            return false;
        }
    }
    activated = true;
    return true;
}

Variant Class::getStaticProperty(const char *name, const std::string &prop) {
    const auto ce = getClassEntry(name);
    if (!ce) {
        zend_throw_exception_ex(nullptr, -1, "class '%s' is undefined.", name);
    }
    const auto retval = zend_read_static_property(ce, prop.c_str(), prop.length(), true);
    Variant rv{retval};
    zval_ptr_dtor(retval);
    return rv;
}

bool Class::setStaticProperty(const char *name, const std::string &prop, const Variant &v) {
    const auto ce = getClassEntry(name);
    if (!ce) {
        zend_throw_exception_ex(nullptr, -1, "class '%s' is undefined.", name);
    }
    const auto zv = NO_CONST_V(v);
    Z_TRY_ADDREF_P(zv);
    return zend_update_static_property(ce, prop.c_str(), prop.length(), zv) == SUCCESS;
}
}  // namespace php
