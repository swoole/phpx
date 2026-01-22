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
Variant Variant::getPropertyIndirect(const Variant &name) const {
    if (UNEXPECTED(!isObject())) {
        zend_throw_error(NULL, "Only objects support the getPropertyIndirect() method");
        return Variant{};
    }
    auto zk = NO_CONST_V(name);
    auto prop_name = zval_get_string(zk);
    zval rv;
    zval *member_p = zend_read_property_ex(ce(), object(), prop_name, false, &rv);
    member_p = unwrap_zval(member_p);
    zend_string_release(prop_name);
    return Variant{member_p, Ctor::Indirect};
}

Variant Variant::getPropertyIndirect(uintptr_t offset) const {
    if (UNEXPECTED(!isObject())) {
        zend_throw_error(NULL, "Only objects support the getPropertyIndirect() method");
        return Variant{};
    }
    return Variant{OBJ_PROP(object(), offset), Ctor::Indirect};
}

Variant Variant::offsetGetIndirect(zend_long offset) const {
    auto zvar = unwrap_zval(const_ptr());
    zval *retval;
    zval rv;

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        retval = zend_hash_index_find(Z_ARRVAL_P(zvar), offset);
        if (retval == nullptr) {
            return Variant{};
        }
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        auto obj = object();
        zval dim;
        ZVAL_LONG(&dim, offset);
        retval = obj->handlers->read_dimension(obj, &dim, BP_VAR_RW, &rv);
        if (UNEXPECTED(retval == NULL || retval == &EG(uninitialized_zval) || retval == &rv)) {
            zend_throw_error(
                NULL, "Indirect modification of overloaded element of %s has no effect", ZSTR_VAL(ce()->name));
            return Variant{};
        }
    } else {
        zend_throw_error(
            NULL, "Only arrays or objects support the offsetGetIndirect(%ld) method, got `%s`", offset, typeStr());
        return Variant{};
    }

    return Variant{retval, Ctor::Indirect};
}

Variant Variant::offsetGetIndirect(const Variant &key) const {
    auto zvar = unwrap_zval(const_ptr());
    zval *retval;
    zval rv;

    if (key.isInt() || key.isFloat() || key.isNumeric() || Z_TYPE_P(zvar) == IS_STRING) {
        return offsetGetIndirect(key.toInt());
    }

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        auto skey = key.toString();
        retval = zend_hash_find(Z_ARRVAL_P(zvar), skey.str());
        if (retval == nullptr) {
            return Variant{};
        }
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        auto obj = object();
        auto dim = NO_CONST_V(key);
        retval = obj->handlers->read_dimension(obj, dim, BP_VAR_RW, &rv);
        if (UNEXPECTED(retval == NULL || retval == &EG(uninitialized_zval) || retval == &rv)) {
            zend_throw_error(NULL, "Indirect modification of overloaded element of %s has no effect", ZSTR_VAL(ce()->name));
            return Variant{};
        }
    } else {
        zend_throw_error(NULL, "Only arrays or objects support the offsetGetIndirect() method");
        return Variant{};
    }

    return Variant{retval, Ctor::Indirect};
}
}  // namespace php
