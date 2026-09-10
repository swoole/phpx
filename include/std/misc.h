/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Type checking, misc, and variable function wrappers      |
  +----------------------------------------------------------------------+
  | Direct C++ wrappers for PHP standard type-checking, microtime,        |
  | hrtime, crc32, pack/unpack, and HTML entity functions.                |
  +----------------------------------------------------------------------+
*/

#pragma once

extern "C" {
#include "php.h"
#include "zend_API.h"
#include "zend_interfaces.h"
#include "zend_exceptions.h"
#include "Zend/zend_smart_str.h"
#include "ext/standard/base64.h"
#include "ext/standard/crc32.h"
#include "ext/standard/url.h"
#include "ext/standard/php_var.h"
#include "ext/standard/php_versioning.h"
#include "ext/standard/php_standard.h"
#include "php_variables.h"
}

#include "phpx.h"
#include "std/hash.h"
#include "std/json.h"
#include "std/random.h"

namespace php::fn {

// ========================
// crc32 (inline, simple call to php_crc32_bulk_update)
// ========================

inline Int crc32(const String &s) {
    uint32_t crc = php_crc32_bulk_init();
    crc = php_crc32_bulk_update(crc, s.data(), s.length());
    return php_crc32_bulk_end(crc);
}

// ========================
// base64_encode(string $string): string
// ========================

inline String base64_encode(const String &data) {
    zend_string *result = php_base64_encode((const unsigned char *) data.data(), data.length());
    if (!result) {
        return String();
    }
    return String(result, Ctor::Move);
}

// ========================
// base64_decode(string $string, bool $strict = false): string|false
// ========================

inline Variant base64_decode(const String &data, bool strict = false) {
    zend_string *result = php_base64_decode_ex((const unsigned char *) data.data(), data.length(), strict);
    if (!result) {
        return Variant(false);
    }
    return Variant(String(result, Ctor::Move));
}

// ========================
// urlencode(string $string): string
// ========================

inline String urlencode(const String &data) {
    zend_string *result = php_url_encode(data.data(), data.length());
    if (!result) {
        return String();
    }
    return String(result, Ctor::Move);
}

// ========================
// urldecode(string $string): string
// ========================

inline String urldecode(const String &data) {
    if (data.empty()) {
        return String();
    }
    size_t len = data.length();
    zend_string *buf = zend_string_init(data.data(), len, 0);
    size_t new_len = php_url_decode(ZSTR_VAL(buf), len);
    ZSTR_VAL(buf)[new_len] = '\0';
    ZSTR_LEN(buf) = new_len;
    return String(buf, Ctor::Move);
}

// ========================
// rawurlencode(string $string): string
// ========================

inline String rawurlencode(const String &data) {
    zend_string *result = php_raw_url_encode(data.data(), data.length());
    if (!result) {
        return String();
    }
    return String(result, Ctor::Move);
}

// ========================
// rawurldecode(string $string): string
// ========================

inline String rawurldecode(const String &data) {
    if (data.empty()) {
        return String();
    }
    size_t len = data.length();
    zend_string *buf = zend_string_init(data.data(), len, 0);
    size_t new_len = php_raw_url_decode(ZSTR_VAL(buf), len);
    ZSTR_VAL(buf)[new_len] = '\0';
    ZSTR_LEN(buf) = new_len;
    return String(buf, Ctor::Move);
}

// ========================
// serialize(mixed $value): string
// ========================

inline String serialize(const Variant &value) {
    smart_str buf = {0};
    php_serialize_data_t data = php_var_serialize_init();
    php_var_serialize(&buf, const_cast<zval *>(value.unwrap_ptr()), &data);
    php_var_serialize_destroy(data);
    smart_str_0(&buf);
    if (!buf.s) {
        return String();
    }
    String result(ZSTR_VAL(buf.s), ZSTR_LEN(buf.s));
    smart_str_free(&buf);
    return result;
}

// ========================
// unserialize(string $data, array $options = []): mixed
// ========================

inline Variant unserialize(const String &data, const Array &options = Array()) {
    zval retval;
    ZVAL_NULL(&retval);
    php_unserialize_with_options(&retval,
                                 data.data(),
                                 data.length(),
                                 options.count() > 0 ? const_cast<zend_array *>(options.array()) : nullptr,
                                 "unserialize");
    return Variant(&retval, Ctor::Move);
}

// ========================
// version_compare(string $v1, string $v2, ?string $operator = null): int|bool
// ========================
Variant version_compare(const String &v1, const String &v2, const Variant &op = Variant());

// ========================
// print_r(mixed $value, bool $return = false): string|bool
// ========================
Variant print_r(const Variant &value, bool do_return = false);

// uniqid(string $prefix = "", bool $more_entropy = false): string
String uniqid(const String &prefix = String(), bool more_entropy = false);

// parse_str(string $string, &$array = null): void
#ifndef PHPX_NANO
Array parse_str(const String &str);
void parse_str(const String &str, Array &result);
#endif

// shell_exec(string $command): string|false|null
#ifndef PHPX_NANO
Variant shell_exec(const String &command);
#endif

}  // namespace php::fn
