/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for Zend built-in functions          |
  +----------------------------------------------------------------------+
  | Eliminates zend_call_function overhead by directly calling Zend APIs  |
  +----------------------------------------------------------------------+
*/

#pragma once

extern "C" {
#include "php.h"
#include "zend_API.h"
#include "zend_interfaces.h"
#include "zend_exceptions.h"
#include "zend_closures.h"
}

#include "phpx.h"

namespace php::fn {

// ========================
// P0: Pure string operations (inline)
// ========================

inline Int strlen(const String &s) {
    return static_cast<Int>(s.length());
}

inline Int strcmp(const String &s1, const String &s2) {
    return zend_binary_strcmp(s1.data(), s1.length(), s2.data(), s2.length());
}

inline Int strncmp(const String &s1, const String &s2, Int len) {
    if (UNEXPECTED(len < 0)) {
        php::throwException(zend_ce_value_error, "strncmp(): Argument #3 ($length) must be greater than or equal to 0");
    }
    return zend_binary_strncmp(s1.data(), s1.length(), s2.data(), s2.length(), len);
}

inline Int strcasecmp(const String &s1, const String &s2) {
    return zend_binary_strcasecmp(s1.data(), s1.length(), s2.data(), s2.length());
}

inline Int strncasecmp(const String &s1, const String &s2, Int len) {
    if (UNEXPECTED(len < 0)) {
        php::throwException(zend_ce_value_error,
                            "strncasecmp(): Argument #3 ($length) must be greater than or equal to 0");
    }
    return zend_binary_strncasecmp(s1.data(), s1.length(), s2.data(), s2.length(), len);
}

// ========================
// P0: Class/function existence checks
// ========================

Bool class_exists(const String &name, bool autoload = true);
Bool interface_exists(const String &name, bool autoload = true);
Bool trait_exists(const String &name, bool autoload = true);
Bool enum_exists(const String &name, bool autoload = true);
Bool function_exists(const String &name);

// formatted=true skips leading-backslash removal and case-folding
inline Bool function_exists(const String &name, bool formatted) {
    if (formatted) {
        return zend_hash_exists(EG(function_table), name.str());
    }
    return function_exists(name);
}

// ========================
// P0: Method/property/constant instance checks
// ========================

Bool method_exists(const Variant &obj_or_class, const String &method);
Bool property_exists(const Variant &obj_or_class, const String &property);
Bool is_a(const Variant &obj, const String &class_name, bool allow_string = false);
Bool is_subclass_of(const Variant &obj, const String &class_name, bool allow_string = true);
Bool defined(const String &name);
Bool define(const String &name, const Variant &value, bool case_insensitive = false);

// ========================
// Type checking functions (inline, direct Z_TYPE_P checks)
// ========================

inline Bool is_array(const Variant &value) {
    return value.isArray();
}

inline Bool is_string(const Variant &value) {
    return value.isString();
}

inline Bool is_object(const Variant &value) {
    return value.isObject();
}

inline Bool is_int(const Variant &value) {
    return Z_TYPE_P(value.unwrap_ptr()) == IS_LONG;
}

inline Bool is_bool(const Variant &value) {
    auto t = Z_TYPE_P(value.unwrap_ptr());
    return t == IS_TRUE || t == IS_FALSE;
}

inline Bool is_float(const Variant &value) {
    return Z_TYPE_P(value.unwrap_ptr()) == IS_DOUBLE;
}

inline Bool is_resource(const Variant &value) {
    return Z_TYPE_P(value.unwrap_ptr()) == IS_RESOURCE;
}

inline Bool is_scalar(const Variant &value) {
    switch (Z_TYPE_P(value.unwrap_ptr())) {
    case IS_FALSE:
    case IS_TRUE:
    case IS_DOUBLE:
    case IS_LONG:
    case IS_STRING:
        return true;
    default:
        return false;
    }
}

inline Bool is_countable(const Variant &value) {
    return zend_is_countable(NO_CONST_V(value));
}

inline Bool is_null(const Variant &value) {
    return value.isNull();
}

inline Bool is_iterable(const Variant &value) {
    return zend_is_iterable(NO_CONST_V(value));
}

inline Bool is_numeric(const Variant &value) {
    int type = Z_TYPE_P(value.unwrap_ptr());
    switch (type) {
    case IS_LONG:
    case IS_DOUBLE:
        return true;
    case IS_STRING: {
        const zval *zv = value.unwrap_ptr();
        return is_numeric_string(Z_STRVAL_P(zv), Z_STRLEN_P(zv), nullptr, nullptr, 0) != 0;
    }
    default:
        return false;
    }
}

// ========================
// is_callable (needs zend_is_callable_ex)
// ========================

inline Bool is_callable(const Variant &value, bool syntax_only = false) {
    int check_flags = syntax_only ? IS_CALLABLE_CHECK_SYNTAX_ONLY : 0;
    return zend_is_callable_ex(NO_CONST_V(value), nullptr, check_flags, nullptr, nullptr, nullptr) != 0;
}

// ========================
// P1: Class identity queries
// ========================

inline String get_class(const Object &obj) {
    return String(obj.ce()->name, php::Ctor::Copy);
}

Variant get_parent_class(const Variant &obj_or_class);

// gettype(mixed $value): string
inline String gettype(const Variant &value) {
    zend_string *s = zend_zval_get_legacy_type(value.unwrap_ptr());
    return String(s, php::Ctor::Move);
}

}  // namespace php::fn
