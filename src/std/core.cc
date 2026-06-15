/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for Zend built-in functions          |
  +----------------------------------------------------------------------+
  | Implementation of functions requiring access to EG() globals          |
  +----------------------------------------------------------------------+
*/

#include "std/core.h"

namespace php::fn {

// ========================
// _class_exists core
// ========================

static Bool _class_exists(const String &name, bool autoload, int match_flags, int skip_flags) {
    zend_string *lcname;
    zend_class_entry *ce;

    if (ZSTR_HAS_CE_CACHE(name.str())) {
        ce = ZSTR_GET_CE_CACHE(name.str());
        if (ce) {
            return (ce->ce_flags & match_flags) == match_flags && !(ce->ce_flags & skip_flags);
        }
    }

    if (!autoload) {
        if (name.data()[0] == '\\') {
            lcname = zend_string_alloc(name.length() - 1, 0);
            zend_str_tolower_copy(ZSTR_VAL(lcname), name.data() + 1, name.length() - 1);
        } else {
            lcname = zend_string_tolower(name.str());
        }
        ce = static_cast<zend_class_entry *>(zend_hash_find_ptr(EG(class_table), lcname));
        zend_string_release_ex(lcname, 0);
    } else {
        ce = zend_lookup_class(name.str());
    }

    if (ce) {
        return (ce->ce_flags & match_flags) == match_flags && !(ce->ce_flags & skip_flags);
    }
    return false;
}

Bool class_exists(const String &name, bool autoload) {
    return _class_exists(name, autoload, ZEND_ACC_LINKED, ZEND_ACC_INTERFACE | ZEND_ACC_TRAIT);
}

Bool interface_exists(const String &name, bool autoload) {
    return _class_exists(name, autoload, ZEND_ACC_LINKED | ZEND_ACC_INTERFACE, 0);
}

Bool trait_exists(const String &name, bool autoload) {
    return _class_exists(name, autoload, ZEND_ACC_TRAIT, 0);
}

Bool enum_exists(const String &name, bool autoload) {
    return _class_exists(name, autoload, ZEND_ACC_ENUM, 0);
}

// ========================
// function_exists
// ========================

Bool function_exists(const String &name) {
    zend_string *lcname;

    if (name.data()[0] == '\\') {
        lcname = zend_string_alloc(name.length() - 1, 0);
        zend_str_tolower_copy(ZSTR_VAL(lcname), name.data() + 1, name.length() - 1);
    } else {
        lcname = zend_string_tolower(name.str());
    }

    bool exists = zend_hash_exists(EG(function_table), lcname);
    zend_string_release_ex(lcname, 0);
    return exists;
}

// ========================
// method_exists
// ========================

Bool method_exists(const Variant &obj_or_class, const String &method) {
    zend_class_entry *ce;

    if (obj_or_class.isObject()) {
        ce = Z_OBJCE_P(NO_CONST_V(obj_or_class));
    } else if (obj_or_class.isString()) {
        ce = zend_lookup_class(Z_STR_P(NO_CONST_V(obj_or_class)));
        if (!ce) {
            return false;
        }
    } else {
        php::throwException(zend_ce_type_error,
                            "method_exists(): Argument #1 ($object_or_class) must be of type object|string");
        return false;
    }

    zend_string *lcname = zend_string_tolower(method.str());
    zend_function *func = static_cast<zend_function *>(zend_hash_find_ptr(&ce->function_table, lcname));
    zend_string_release_ex(lcname, 0);

    if (func) {
        if (obj_or_class.isObject()) {
            return true;
        }
        return !(func->common.fn_flags & ZEND_ACC_PRIVATE) || func->common.scope == ce;
    }

    if (obj_or_class.isObject()) {
        zend_object *obj = Z_OBJ_P(NO_CONST_V(obj_or_class));
        const zval *this_ = obj_or_class.unwrap_ptr();
        func = Z_OBJ_HT_P(this_)->get_method(&obj, method.str(), nullptr);
        if (func != nullptr) {
            if (func->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE) {
                bool result = (func->common.scope == zend_ce_closure &&
                               zend_string_equals_literal_ci(method.str(), ZEND_INVOKE_FUNC_NAME));
                zend_string_release_ex(func->common.function_name, 0);
                zend_free_trampoline(func);
                return result;
            }
            return true;
        }
    } else {
        if (ce == zend_ce_closure && zend_string_equals_literal_ci(method.str(), ZEND_INVOKE_FUNC_NAME)) {
            return true;
        }
    }
    return false;
}

// ========================
// property_exists
// ========================

Bool property_exists(const Variant &obj_or_class, const String &property) {
    zend_class_entry *ce;

    if (obj_or_class.isObject()) {
        ce = Z_OBJCE_P(NO_CONST_V(obj_or_class));
    } else if (obj_or_class.isString()) {
        ce = zend_lookup_class(Z_STR_P(NO_CONST_V(obj_or_class)));
        if (!ce) {
            return false;
        }
    } else {
        php::throwException(zend_ce_type_error,
                            "property_exists(): Argument #1 ($object_or_class) must be of type object|string");
        return false;
    }

    zend_property_info *prop_info =
        static_cast<zend_property_info *>(zend_hash_find_ptr(&ce->properties_info, property.str()));
    if (prop_info != nullptr && (!(prop_info->flags & ZEND_ACC_PRIVATE) || prop_info->ce == ce)) {
        return true;
    }

    if (obj_or_class.isObject()) {
        return Z_OBJ_HANDLER_P(NO_CONST_V(obj_or_class), has_property)(
                   Z_OBJ_P(NO_CONST_V(obj_or_class)), property.str(), ZEND_PROPERTY_EXISTS, nullptr) != 0;
    }
    return false;
}

// ========================
// is_a
// ========================

Bool is_a(const Variant &obj, const String &class_name, bool allow_string) {
    zend_class_entry *instance_ce;

    if (allow_string && obj.isString()) {
        instance_ce = zend_lookup_class(Z_STR_P(NO_CONST_V(obj)));
        if (!instance_ce) {
            return false;
        }
    } else if (obj.isObject()) {
        instance_ce = Z_OBJCE_P(NO_CONST_V(obj));
    } else {
        return false;
    }

    if (zend_string_equals(instance_ce->name, class_name.str())) {
        return true;
    }

    zend_class_entry *ce = zend_lookup_class_ex(class_name.str(), nullptr, ZEND_FETCH_CLASS_NO_AUTOLOAD);
    if (!ce) {
        return false;
    }

    return instanceof_function(instance_ce, ce);
}

// ========================
// is_subclass_of
// ========================

Bool is_subclass_of(const Variant &obj, const String &class_name, bool allow_string) {
    zend_class_entry *instance_ce;

    if (allow_string && obj.isString()) {
        instance_ce = zend_lookup_class(Z_STR_P(NO_CONST_V(obj)));
        if (!instance_ce) {
            return false;
        }
    } else if (obj.isObject()) {
        instance_ce = Z_OBJCE_P(NO_CONST_V(obj));
    } else {
        return false;
    }

    zend_class_entry *ce = zend_lookup_class_ex(class_name.str(), nullptr, ZEND_FETCH_CLASS_NO_AUTOLOAD);
    if (!ce) {
        return false;
    }

    if (instance_ce == ce) {
        return false;
    }

    return instanceof_function(instance_ce, ce);
}

// ========================
// defined
// ========================

Bool defined(const String &name) {
    return zend_get_constant_ex(name.str(), zend_get_executed_scope(), ZEND_FETCH_CLASS_SILENT) != nullptr;
}

// ========================
// define
// ========================

static bool _validate_constant_array(HashTable *ht, int arg_num) {
    bool ret = 1;
    zval *val;

    GC_PROTECT_RECURSION(ht);
    ZEND_HASH_FOREACH_VAL(ht, val) {
        ZVAL_DEREF(val);
        if (Z_TYPE_P(val) == IS_ARRAY && Z_REFCOUNTED_P(val)) {
            if (Z_IS_RECURSIVE_P(val)) {
                zend_argument_value_error(arg_num, "cannot be a recursive array");
                ret = 0;
                break;
            } else if (!_validate_constant_array(Z_ARRVAL_P(val), arg_num)) {
                ret = 0;
                break;
            }
        }
    }
    ZEND_HASH_FOREACH_END();
    GC_UNPROTECT_RECURSION(ht);
    return ret;
}

static void _copy_constant_array(zval *dst, zval *src) {
    zend_string *key;
    zend_ulong idx;
    zval *new_val, *val;

    array_init_size(dst, zend_hash_num_elements(Z_ARRVAL_P(src)));
    ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(src), idx, key, val) {
        ZVAL_DEREF(val);
        if (key) {
            new_val = zend_hash_add_new(Z_ARRVAL_P(dst), key, val);
        } else {
            new_val = zend_hash_index_add_new(Z_ARRVAL_P(dst), idx, val);
        }
        if (Z_TYPE_P(val) == IS_ARRAY) {
            if (Z_REFCOUNTED_P(val)) {
                _copy_constant_array(new_val, val);
            }
        } else {
            Z_TRY_ADDREF_P(val);
        }
    }
    ZEND_HASH_FOREACH_END();
}

Bool define(const String &name, const Variant &value, bool case_insensitive) {
    zend_string *zname = name.str();

    if (zend_memnstr(ZSTR_VAL(zname), "::", sizeof("::") - 1, ZSTR_VAL(zname) + ZSTR_LEN(zname))) {
        zend_argument_value_error(1, "cannot be a class constant");
        return false;
    }

    if (case_insensitive) {
        zend_error(E_WARNING,
                   "define(): Argument #3 ($case_insensitive) is ignored "
                   "since declaration of case-insensitive constants is no longer supported");
    }

    zend_constant c;
    zval val_free;
    ZVAL_UNDEF(&val_free);

    zval *val = NO_CONST_V(value);
    if (Z_TYPE_P(val) == IS_ARRAY) {
        if (Z_REFCOUNTED_P(val)) {
            if (!_validate_constant_array(Z_ARRVAL_P(val), 2)) {
                return false;
            }
            _copy_constant_array(&c.value, val);
            goto register_constant;
        }
    }

    ZVAL_COPY(&c.value, val);
    zval_ptr_dtor_safe(&val_free);

register_constant:
    ZEND_CONSTANT_SET_FLAGS(&c, 0, PHP_USER_CONSTANT);
    c.name = zend_string_copy(zname);
#if PHP_VERSION_ID >= 80500
    if (zend_register_constant(&c) != nullptr) {
#else
    if (zend_register_constant(&c) == SUCCESS) {
#endif
        return true;
    }
    return false;
}

// ========================
// get_parent_class
// ========================

Variant get_parent_class(const Variant &obj_or_class) {
    zend_class_entry *ce = nullptr;

    if (obj_or_class.isObject()) {
        ce = Z_OBJCE_P(NO_CONST_V(obj_or_class));
    } else if (obj_or_class.isString()) {
        ce = zend_lookup_class(Z_STR_P(NO_CONST_V(obj_or_class)));
        if (!ce) {
            return Variant(false);
        }
    } else {
        php::throwException(zend_ce_type_error,
                            "get_parent_class(): Argument #1 ($object_or_class) must be of type object|string");
        return Variant(false);
    }

    if (ce && ce->parent) {
        return Variant(String(ce->parent->name, php::Ctor::Copy));
    }
    return Variant(false);
}

}  // namespace php::fn
