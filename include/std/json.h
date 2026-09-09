/*
  +----------------------------------------------------------------------+
  | PHP-X — direct JSON wrappers                                         |
  +----------------------------------------------------------------------+
*/

#pragma once

extern "C" {
#include "Zend/zend_smart_str.h"
#include "ext/json/php_json.h"
}

#include "phpx.h"

namespace php::fn {

namespace detail {
inline php_json_error_code jsonLastErrorCode() {
#if PHP_VERSION_ID >= 80600
    return JSON_G(error_details).code;
#else
    return static_cast<php_json_error_code>(JSON_G(error_code));
#endif
}

inline void clearJsonLastError() {
#if PHP_VERSION_ID >= 80600
    php_json_error_details_clear(&JSON_G(error_details));
#else
    JSON_G(error_code) = PHP_JSON_ERROR_NONE;
#endif
}

inline void throwJsonException(php_json_error_code code) {
    Variant message = php::call(php::getFunction(String("json_last_error_msg")), {});
    php::throwException(php::getClassEntrySafe(String("JsonException")), message.toCString(), code);
}
}  // namespace detail

inline Variant json_encode(const Variant &value, int options = 0, zend_long depth = 512) {
    smart_str buf = {0};
    php_json_encode_ex(&buf, const_cast<zval *>(value.unwrap_ptr()), options, depth);

    const php_json_error_code error = detail::jsonLastErrorCode();
    if (error != PHP_JSON_ERROR_NONE) {
        if ((options & PHP_JSON_THROW_ON_ERROR) && !(options & PHP_JSON_PARTIAL_OUTPUT_ON_ERROR)) {
            smart_str_free(&buf);
            detail::throwJsonException(error);
            return Variant(false);
        }
        if (!(options & PHP_JSON_PARTIAL_OUTPUT_ON_ERROR)) {
            smart_str_free(&buf);
            return Variant(false);
        }
    }

    smart_str_0(&buf);
    if (!buf.s) {
        return Variant(String());
    }
    Variant result(String(ZSTR_VAL(buf.s), ZSTR_LEN(buf.s)));
    smart_str_free(&buf);
    return result;
}

inline Variant json_decode(
    const String &json, const Variant &assoc = Variant(), zend_long depth = 512, int options = 0) {
    if (UNEXPECTED(depth <= 0)) {
        php::throwExceptionEx(
            zend_ce_value_error, 0, "json_decode(): Argument #3 ($depth) must be greater than 0");
        return Variant(nullptr);
    }
    if (UNEXPECTED(depth > INT_MAX)) {
        php::throwExceptionEx(
            zend_ce_value_error, 0, "json_decode(): Argument #3 ($depth) must be less than %d", INT_MAX);
        return Variant(nullptr);
    }

    if (!(options & PHP_JSON_THROW_ON_ERROR)) {
        detail::clearJsonLastError();
    }
    if (!assoc.isNull()) {
        if (assoc.toBool()) {
            options |= PHP_JSON_OBJECT_AS_ARRAY;
        } else {
            options &= ~PHP_JSON_OBJECT_AS_ARRAY;
        }
    }

    zval retval;
    ZVAL_NULL(&retval);
    if (php_json_decode_ex(&retval, json.data(), json.length(), options, depth) != SUCCESS) {
        php::throwErrorIfOccurred();
        return Variant(nullptr);
    }
    return Variant(&retval, Ctor::Move);
}

}  // namespace php::fn
