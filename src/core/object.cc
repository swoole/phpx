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
#include "phpx_fake_scope_guard.h"

BEGIN_EXTERN_C()
#include "zend_smart_str.h"
#include <ext/spl/php_spl.h>
END_EXTERN_C()

namespace php {
bool Object::offsetExists(const Variant &offset, int check_empty) const {
    auto obj = checkedObject("Cannot check offset");
    auto result = obj->handlers->has_dimension(obj, NO_CONST_V(offset), check_empty) != 0;
    throwErrorIfOccurred();
    return result;
}

bool Object::offsetExists(zend_long offset, int check_empty) {
    auto obj = checkedObject("Cannot check offset");
    zval tmp;
    ZVAL_LONG(&tmp, offset);
    auto result = obj->handlers->has_dimension(obj, &tmp, check_empty) != 0;
    throwErrorIfOccurred();
    return result;
}

static Variant wrap_dimension_result(zval *result, zval *rv) {
    if (UNEXPECTED(EG(exception) != nullptr)) {
        if (!Z_ISUNDEF_P(rv)) {
            zval_ptr_dtor(rv);
        }
        throwErrorIfOccurred();
        return {};
    }
    return result == rv ? Variant{result, Ctor::Move} : Variant{result};
}

Variant Object::offsetGet(const Variant &offset, int type) {
    auto obj = checkedObject("Cannot read offset");
    zval rv;
    ZVAL_UNDEF(&rv);
    auto result = obj->handlers->read_dimension(obj, NO_CONST_V(offset), type, &rv);
    return wrap_dimension_result(result, &rv);
}

Variant Object::offsetGet(zend_long offset, int type) {
    auto obj = checkedObject("Cannot read offset");
    zval tmp;
    ZVAL_LONG(&tmp, offset);
    zval rv;
    ZVAL_UNDEF(&rv);
    auto result = obj->handlers->read_dimension(obj, &tmp, type, &rv);
    return wrap_dimension_result(result, &rv);
}

void Object::offsetSet(const Variant &offset, const Variant &value) {
    auto obj = checkedObject("Cannot write offset");
    obj->handlers->write_dimension(obj, NO_CONST_V(offset), NO_CONST_V(value));
    throwErrorIfOccurred();
}

void Object::offsetSet(zend_long offset, const Variant &value) {
    auto obj = checkedObject("Cannot write offset");
    zval tmp;
    ZVAL_LONG(&tmp, offset);
    obj->handlers->write_dimension(obj, &tmp, NO_CONST_V(value));
    throwErrorIfOccurred();
}

void Object::offsetUnset(const Variant &offset) {
    auto obj = checkedObject("Cannot unset offset");
    obj->handlers->unset_dimension(obj, NO_CONST_V(offset));
    throwErrorIfOccurred();
}

void Object::offsetUnset(zend_long offset) {
    auto obj = checkedObject("Cannot unset offset");
    zval tmp;
    ZVAL_LONG(&tmp, offset);
    obj->handlers->unset_dimension(obj, &tmp);
    throwErrorIfOccurred();
}

String Object::hash() const {
    return String(php_spl_object_hash(checkedObject("Cannot hash object")), Ctor::Move);
}

zend_long Object::count() {
    auto obj = checkedObject("Cannot count object");
    if (obj->handlers->count_elements) {
        zend_long rv;
        auto rc = obj->handlers->count_elements(obj, &rv);
        throwErrorIfOccurred();
        return rc == SUCCESS ? rv : 0;
    } else {
        return 0;
    }
}

bool Object::propertyExists(const String &name, PropertyOperation op) const {
    auto obj = checkedObject("Cannot inspect object properties");
    bool rs;
    do {
        FakeScopeGuard fake_scope_guard{obj->ce};
        rs = obj->handlers->has_property(obj, name.str(), op, NULL);
    } while (0);

    throwErrorIfOccurred();
    return rs;
}

bool Object::instanceOf(const String &name) const {
    auto obj = checkedObject("Cannot inspect object class");
    auto cls_ce = getClassEntry(name);
    if (!cls_ce) {
        return false;
    }
    return instanceof_function(obj->ce, cls_ce);
}

Variant Object::callParentMethod(const String &func, const ArgList &args) {
    Args _args(args);
    Variant retval;

    if (UNEXPECTED(!isObject())) {
        throwError("call method `%s` on %s", func.data(), typeStr());
        return retval;
    }

    auto obj = object();

    if (UNEXPECTED(obj->ce->parent == nullptr)) {
        throwError("class does not inherit the parent class");
        return retval;
    }

    auto fn = (zend_function *) zend_hash_find_ptr_lc(&obj->ce->parent->function_table, func.str());
    if (UNEXPECTED(fn == nullptr)) {
        throwError("Couldn't find implementation for method %s::%s", ZSTR_VAL(parent_ce()->name), func.data());
    } else if (UNEXPECTED(fn->common.fn_flags & ZEND_ACC_ABSTRACT)) {
        throwError("Cannot call abstract method %s::%s()",
                   ZSTR_VAL(fn->common.scope->name),
                   ZSTR_VAL(fn->common.function_name));
    } else {
        zend_call_known_function(fn, obj, obj->ce, retval.ptr(), _args.count(), _args.ptr(), nullptr);
        throwErrorIfOccurred();
    }

    return retval;
}

Variant Object::get(const String &name) const {
    return getProperty(name.str());
}

Object Object::clone() const {
    if (UNEXPECTED(!isObject())) {
        throwError("Attempt to clone on %s", typeStr());
        return {};
    }

    auto obj = object();
    auto clone_obj = obj->handlers->clone_obj;
    if (clone_obj == nullptr) {
        throwError("Trying to clone an uncloneable object of class %s", ZSTR_VAL(obj->ce->name));
        return {};
    }
    Object retval;
    const auto new_object = clone_obj(obj);
    if (new_object != nullptr) {
        // Take ownership before propagating a possible __clone() exception.
        // Zend may return the allocated clone with EG(exception) set; keeping
        // it in an RAII wrapper ensures that exceptional callbacks do not leak
        // the partially initialized object.
        ZVAL_OBJ(retval.ptr(), new_object);
    }
    throwErrorIfOccurred();
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
