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
static Variant __construct{ZEND_STRL("__construct"), true};

String Object::hash() const {
    return String::from(php_spl_object_hash(object()));
}

Variant Object::exec(const Variant &fn, const std::initializer_list<Variant> &args) {
    Args _args;
    for (const auto &arg : args) {
        _args.append(const_cast<Variant &>(arg).ptr());
    }
    return _call(ptr(), fn.const_ptr(), _args);
}

bool Object::instanceOf(const String &name) const {
    auto cls_ce = getClassEntry(name);
    if (!cls_ce) {
        return false;
    }
    return instanceof_function(ce(), cls_ce);
}

Variant Object::callParentMethod(const String &func, const std::initializer_list<Variant> &args) {
    Args _args;
    for (const auto &arg : args) {
        _args.append(const_cast<Variant &>(arg).ptr());
    }

    Variant retval;
    auto fn = (zend_function *) zend_hash_find_ptr_lc(&parent_ce()->function_table, func.str());
    if (UNEXPECTED(fn == nullptr)) {
        /* error at c-level */
        zend_error_noreturn(
            E_CORE_ERROR, "Couldn't find implementation for method %s::%s", ZSTR_VAL(parent_ce()->name), func.data());
    } else if (UNEXPECTED(fn->common.fn_flags & ZEND_ACC_ABSTRACT)) {
        zend_throw_error(NULL,
                         "Cannot call abstract method %s::%s()",
                         ZSTR_VAL(fn->common.scope->name),
                         ZSTR_VAL(fn->common.function_name));
    } else {
        zend_call_known_function(fn, object(), ce(), retval.ptr(), _args.count(), _args.ptr(), nullptr);
    }

    return retval;
}

Variant Object::getPropertyReference(const String &prop_name) {
    auto zobj = object();
    zval rv;
    zval *member_p = zobj->handlers->get_property_ptr_ptr(zobj, prop_name.str(), BP_VAR_RW, NULL);

    if (!member_p) {
        member_p = zobj->handlers->read_property(zobj, prop_name.str(), BP_VAR_RW, NULL, &rv);
        if (!member_p) {
            return {};
        }
    }

    if (Z_TYPE_P(member_p) == IS_REFERENCE) {
        return Variant(member_p, false, true);
    }

    auto ref = newReference();
    auto prop_info = zend_get_property_info(ce(), prop_name.str(), 1);
    if (prop_info) {
        ZEND_REF_ADD_TYPE_SOURCE(ref.reference(), prop_info);
    }

    if (member_p != &rv) {
        ZVAL_COPY(Z_REFVAL_P(ref.ptr()), member_p);
    } else {
        ZVAL_COPY_VALUE(Z_REFVAL_P(ref.ptr()), member_p);
    }

    ZVAL_REF(member_p, ref.reference());
    Z_TRY_ADDREF_P(ref.ptr());

    return ref;
}

void Object::appendArrayProperty(const String &name, const Variant &value) {
    zval rv;
    Variant retval;
    zval *member_p = zend_read_property_ex(ce(), object(), name.str(), false, &rv);

    if (UNEXPECTED(!member_p)) {
        return;
    }

    ZVAL_DEREF(member_p);
    auto zv = NO_CONST_V(value);
    Z_TRY_ADDREF_P(zv);
    zend_hash_next_index_insert(Z_ARRVAL_P(member_p), zv);
}

void Object::updateArrayProperty(const String &name, zend_long offset, const Variant &value) {
    zval rv;
    Variant retval;
    zval *member_p = zend_read_property_ex(ce(), object(), name.str(), false, &rv);

    if (UNEXPECTED(!member_p)) {
        return;
    }

    ZVAL_DEREF(member_p);
    auto zv = NO_CONST_V(value);
    Z_TRY_ADDREF_P(zv);
    zend_hash_index_update(Z_ARRVAL_P(member_p), offset, zv);
}

void Object::updateArrayProperty(const String &name, const Variant &key, const Variant &value) {
    zval rv;
    Variant retval;
    zval *member_p = zend_read_property_ex(ce(), object(), name.str(), false, &rv);

    if (UNEXPECTED(!member_p)) {
        return;
    }

    ZVAL_DEREF(member_p);
    auto zv = NO_CONST_V(value);
    Z_TRY_ADDREF_P(zv);

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

Object newObject(const char *name) {
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    if (ce->constructor) {
        _call(object.ptr(), __construct.ptr());
    }
    return object;
}

Object newObject(const char *name, const std::initializer_list<Variant> &args) {
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    Args _args;
    for (const auto &arg : args) {
        _args.append(const_cast<Variant &>(arg).ptr());
    }
    if (ce->constructor) {
        object.call(__construct, _args);
    }
    return object;
}

Object to_object(const Variant &v) {
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
    return Object(&result, false, false);
}
}  // namespace php
