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
        auto rc = object()->handlers->count_elements(object(), &rv);
        throwErrorIfOccurred();
        return rc == SUCCESS ? rv : 0;
    } else {
        return 0;
    }
}

bool Object::propertyExists(const String &name, PropertyOperation op) const {
    zend_string *property = name.str();

    auto property_info = (zend_property_info *) zend_hash_find_ptr(&ce()->properties_info, property);
    if (property_info != NULL && (!(property_info->flags & ZEND_ACC_PRIVATE) || property_info->ce == ce())) {
        return true;
    }

    auto ori_scope = EG(fake_scope);
    EG(fake_scope) = ce();
    bool rs = object()->handlers->has_property(object(), name.str(), op, NULL);

    EG(fake_scope) = ori_scope;
    throwErrorIfOccurred();
    return rs;
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

    if (UNEXPECTED(isNull())) {
        throwError("call method `%s` on null", func.data());
        return retval;
    }

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
        throwErrorIfOccurred();
    }

    return retval;
}

Variant Object::get(const String &name) const {
    return getProperty(name.str());
}

Object Object::clone() const {
    if (UNEXPECTED(isNull())) {
        throwError("Attempt to clone on null");
        return {};
    }

    auto clone_obj = object()->handlers->clone_obj;
    if (clone_obj == nullptr) {
        throwError("Trying to clone an uncloneable object of class %s", ZSTR_VAL(ce()->name));
        return {};
    }
    const auto new_object = clone_obj(object());
    throwErrorIfOccurred();

    Object retval;
    ZVAL_OBJ(retval.ptr(), new_object);
    return retval;
}

Object newObject(zend_class_entry *ce) {
    Object object;

    auto rc = object_init_ex(object.ptr(), ce);
    if (EXPECTED(rc == SUCCESS)) {
        auto this_ = object.object();
        auto ctor = ce->constructor;
        if (ctor) {
            try {
                zend_call_known_function(ctor, this_, ce, nullptr, 0, nullptr, nullptr);
                throwErrorIfOccurred();
            } catch (...) {
                zend_object_store_ctor_failed(this_);
                throw;
            }
        }
    }
    throwErrorIfOccurred();

    return object;
}

Object newObject(zend_class_entry *ce, Args &args, zend_array *named_args) {
    Object object;

    auto rc = object_init_ex(object.ptr(), ce);
    if (EXPECTED(rc == SUCCESS)) {
        auto this_ = object.object();
        auto ctor = ce->constructor;
        if (ctor) {
            try {
                zend_call_known_function(ctor, this_, ce, nullptr, args.count(), args.ptr(), named_args);
                throwErrorIfOccurred();
            } catch (...) {
                zend_object_store_ctor_failed(this_);
                throw;
            }
        }
    }
    throwErrorIfOccurred();

    return object;
}

Object newObject(zend_class_entry *ce, const ArgList &args, zend_array *named_args) {
    Args _args(args);
    return newObject(ce, _args, named_args);
}

Object newObject(zend_class_entry *ce, Array &args, zend_array *named_args) {
    Args _args(args);
    return newObject(ce, _args, named_args);
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
    auto ce = getClassEntrySafe(class_name);
    if (UNEXPECTED(ce == nullptr)) {
        return {};
    }
    return toObject(v, ce);
}
}  // namespace php
