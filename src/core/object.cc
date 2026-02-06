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
#include "zend_smart_str.h"
#include <ext/spl/php_spl.h>
END_EXTERN_C()

namespace php {
String Object::hash() const {
    return String(php_spl_object_hash(object()), Ctor::Move);
}

zend_long Object::count() {
    if (object()->handlers->count_elements) {
        zend_long rv;
        return object()->handlers->count_elements(object(), &rv) == SUCCESS ? rv : 0;
    } else {
        return 0;
    }
}

Variant Object::exec(const Variant &fn, const ArgList &args) {
    if (UNEXPECTED(isNull())) {
        throwError("read property `%s` on null", fn.toCString());
        return {};
    }
    Args _args(args);
    return call_impl(unwrap_ptr(), fn.const_ptr(), _args);
}

bool Object::instanceOf(const String &name) const {
    auto cls_ce = getClassEntry(name);
    if (!cls_ce) {
        return false;
    }
    return instanceof_function(ce(), cls_ce);
}

Variant Object::callParentMethod(const String &func, const ArgList &args) {
    Args _args(args);
    Variant retval;

    if (UNEXPECTED(parent_ce() == nullptr)) {
        throwError("class does not inherit the parent class");
        return retval;
    }

    auto fn = (zend_function *) zend_hash_find_ptr_lc(&parent_ce()->function_table, func.str());
    if (UNEXPECTED(fn == nullptr)) {
        throwError("Couldn't find implementation for method %s::%s", ZSTR_VAL(parent_ce()->name), func.data());
    } else if (UNEXPECTED(fn->common.fn_flags & ZEND_ACC_ABSTRACT)) {
        throwError("Cannot call abstract method %s::%s()",
                   ZSTR_VAL(fn->common.scope->name),
                   ZSTR_VAL(fn->common.function_name));
    } else {
        zend_call_known_function(fn, object(), ce(), retval.ptr(), _args.count(), _args.ptr(), nullptr);
    }

    return retval;
}

Reference Object::attrRef(const String &prop_name) {
    if (UNEXPECTED(isNull())) {
        throwError("read property `%s` on null", prop_name.toCString());
        return {};
    }

    auto member = attr(prop_name);
    if (zval_is_ref(member.const_ptr())) {
        return Reference(member.const_ptr());
    } else if (!member.isIndirect()) {
        return {};
    }

    auto ref = member.toReference();
    auto prop_info = zend_get_property_info(ce(), prop_name.str(), 1);
    if (prop_info) {
        ZEND_REF_ADD_TYPE_SOURCE(ref.reference(), prop_info);
    }
    return ref;
}

Variant Object::attr(const Variant &name, bool update) const {
    if (UNEXPECTED(isNull())) {
        throwError("read property `%s` on null", name.toCString());
        return {};
    }

    auto prop_name = name.toString();
    zval rv;
    auto member_p = zend_read_property_ex(ce(), object(), prop_name.str(), true, &rv);

    if (zval_is_null(member_p) && update) {
        zval tmp;
        ZVAL_NULL(&tmp);
        auto old_scope = EG(fake_scope);
        EG(fake_scope) = ce();
        member_p = object()->handlers->write_property(object(), prop_name.str(), &tmp, NULL);
        EG(fake_scope) = old_scope;
    }

    if (member_p == &rv) {
        return Variant{member_p};
    } else if (zval_is_ref(member_p)) {
        return Variant{member_p, Ctor::CopyRef};
    } else {
        return Variant{member_p, Ctor::Indirect};
    }
}

void Object::appendArrayProperty(const String &name, const Variant &value) {
    zval rv;
    Variant retval;
    zval *member_p = zend_read_property_ex(ce(), object(), name.str(), true, &rv);

    if (UNEXPECTED(ZVAL_IS_NULL(member_p))) {
        throwError("property `%s` is undefined", name.data());
        return;
    }

    if (Z_TYPE_P(member_p) != IS_ARRAY) {
        throwError("property `%s` must be `array`", name.data());
        return;
    }

    ZVAL_DEREF(member_p);
    auto zv = NO_CONST_V(value);
    Z_TRY_ADDREF_P(zv);
    SEPARATE_ARRAY(member_p);
    zend_hash_next_index_insert(Z_ARRVAL_P(member_p), zv);
}

void Object::updateArrayProperty(const String &name, zend_long offset, const Variant &value) {
    zval rv;
    Variant retval;
    zval *member_p = zend_read_property_ex(ce(), object(), name.str(), true, &rv);

    if (UNEXPECTED(ZVAL_IS_NULL(member_p))) {
        throwError("property `%s` is undefined", name.data());
        return;
    }

    if (Z_TYPE_P(member_p) != IS_ARRAY) {
        throwError("property `%s` must be `array`", name.data());
        return;
    }

    ZVAL_DEREF(member_p);
    auto zv = NO_CONST_V(value);
    Z_TRY_ADDREF_P(zv);
    SEPARATE_ARRAY(member_p);
    zend_hash_index_update(Z_ARRVAL_P(member_p), offset, zv);
}

void Object::updateArrayProperty(const String &name, const Variant &key, const Variant &value) {
    zval rv;
    Variant retval;
    zval *member_p = zend_read_property_ex(ce(), object(), name.str(), true, &rv);

    if (UNEXPECTED(ZVAL_IS_NULL(member_p))) {
        throwError("property `%s` is undefined", name.data());
        return;
    }

    if (Z_TYPE_P(member_p) != IS_ARRAY) {
        throwError("property `%s` must be `array`", name.data());
        return;
    }

    ZVAL_DEREF(member_p);
    auto zv = NO_CONST_V(value);
    Z_TRY_ADDREF_P(zv);
    SEPARATE_ARRAY(member_p);

    if (key.isInt() || key.isFloat() || key.isNumeric()) {
        zend_hash_index_update(Z_ARRVAL_P(member_p), key.toInt(), zv);
    } else if (key.isNull()) {
        zend_hash_next_index_insert(Z_ARRVAL_P(member_p), zv);
    } else {
        auto skey = key.toString();
        zend_hash_update(Z_ARRVAL_P(member_p), skey.str(), zv);
    }
}

Variant Object::get(const String &name) const {
    return getProperty(name.str());
}

Object Object::clone() const {
    const auto new_object = zend_objects_clone_obj(object());
    Object retval;
    ZVAL_OBJ(retval.ptr(), new_object);
    return retval;
}

Object newObject(zend_class_entry *ce) {
    Object object;
    auto rc = object_init_ex(object.ptr(), ce);
    if (EXPECTED(rc == SUCCESS)) {
        if (ce->constructor) {
            zend_call_known_function(ce->constructor, object.object(), object.ce(), nullptr, 0, nullptr, nullptr);
        }
    }
    throwErrorIfOccurred();
    return object;
}

Object newObject(zend_class_entry *ce, const ArgList &args) {
    Object object;

    auto rc = object_init_ex(object.ptr(), ce);
    if (EXPECTED(rc == SUCCESS)) {
        if (ce->constructor) {
            Args _args(args);
            zend_call_known_function(
                ce->constructor, object.object(), object.ce(), nullptr, _args.count(), _args.ptr(), nullptr);
        }
    }
    throwErrorIfOccurred();

    return object;
}

Object toObject(const Variant &v) {
    if (v.isObject()) {
        return v;
    }
    zval result;
    zval *expr = NO_CONST_V(v);
    zend_array *ht;
    ZVAL_OBJ(&result, zend_objects_new(zend_standard_class_def));
    if (Z_TYPE_P(expr) == IS_ARRAY) {
        ht = zend_symtable_to_proptable(Z_ARR_P(expr));
        if (GC_FLAGS(ht) & IS_ARRAY_IMMUTABLE) {
            /* TODO: try not to duplicate immutable arrays as well ??? */
            ht = zend_array_dup(ht);
        }
        Z_OBJ(result)->properties = ht;
    } else if (Z_TYPE_P(expr) != IS_NULL) {
        Z_OBJ(result)->properties = ht = zend_new_array(1);
        expr = zend_hash_add_new(ht, ZSTR_KNOWN(ZEND_STR_SCALAR), expr);
        if (IS_CONST == IS_CONST) {
            if (UNEXPECTED(Z_OPT_REFCOUNTED_P(expr))) Z_ADDREF_P(expr);
        } else {
            if (Z_OPT_REFCOUNTED_P(expr)) Z_ADDREF_P(expr);
        }
    }
    return Object(&result, Ctor::Move);
}

Object toObject(const Variant &v, const String &class_name) {
    if (UNEXPECTED(!v.isObject())) {
        throwError("parameter 1 must be `object`, got `%s`", v.typeStr());
        return {};
    }
    auto ce = getClassEntry(class_name);
    if (UNEXPECTED(ce == nullptr)) {
        throwError("class '%s' is undefined.", class_name.toCString());
        return {};
    }
    if (UNEXPECTED(!instanceof_function(v.ce(), ce))) {
        throwError(
            "must be instance of class `%s`, object of `%s` given", class_name.toCString(), ZSTR_VAL(v.ce()->name));
        return {};
    }
    return Object{v.unwrap_ptr()};
}
}  // namespace php
