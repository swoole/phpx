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
#include "ext/standard/crc32.h"
#include "ext/standard/url.h"
#include "ext/standard/md5.h"
#include "ext/standard/sha1.h"
#include "ext/hash/php_hash.h"
#include "ext/json/php_json.h"
#include "ext/standard/php_var.h"
#include "ext/standard/php_versioning.h"
#include "ext/standard/php_standard.h"
#include "ext/random/php_random.h"
#include "php_variables.h"
}

#include "phpx.h"

namespace php::std {

// ========================
// crc32 (inline, simple call to php_crc32_bulk_update)
// ========================

inline Int crc32(const String &s) {
    uint32_t crc = php_crc32_bulk_init();
    crc = php_crc32_bulk_update(crc, s.data(), s.length());
    return php_crc32_bulk_end(crc);
}

// ========================
// md5(string $string, bool $binary = false): string
// ========================
Variant md5(const String &s, bool raw_output = false);

// ========================
// sha1(string $string, bool $binary = false): string
// ========================
Variant sha1(const String &s, bool raw_output = false);

// ========================
// hash(string $algo, string $data, bool $binary = false): string
// ========================
Variant hash(const String &algo, const String &data, bool raw_output = false);

// ========================
// random_int(int $min, int $max): int
// ========================

inline Int random_int(Int min, Int max) {
    zend_long result;
    if (php_random_int(min, max, &result, true) == FAILURE) {
        throwErrorIfOccurred();
        return 0;
    }
    return static_cast<Int>(result);
}

// ========================
// random_bytes(int $length): string
// ========================

inline String random_bytes(Int length) {
    if (UNEXPECTED(length < 1)) {
        php::throwException(zend_ce_value_error, "random_bytes(): Argument #1 ($length) must be greater than 0");
        return String();
    }
    zend_string *bytes = zend_string_alloc(length, 0);
    if (php_random_bytes(ZSTR_VAL(bytes), length, true) == FAILURE) {
        zend_string_release(bytes);
        throwErrorIfOccurred();
        return String();
    }
    ZSTR_VAL(bytes)[length] = 0;
    return String(bytes, Ctor::Move);
}

// ========================
// mt_rand() : int
// mt_rand(int $min, int $max): int
// ========================

inline Int mt_rand() {
    return static_cast<Int>(php_mt_rand());
}

inline Int mt_rand(Int min, Int max) {
    return static_cast<Int>(php_mt_rand_range(min, max));
}

// ========================
// rand() : int
// rand(int $min, int $max): int
// ========================

inline Int rand() {
    return static_cast<Int>(php_mt_rand());
}

inline Int rand(Int min, Int max) {
    return static_cast<Int>(php_mt_rand_range(min, max));
}

// ========================
// json_encode(mixed $value, int $flags = 0, int $depth = 512): string|false
// ========================

inline Variant json_encode(const Variant &value, int options = 0, int depth = 512) {
    smart_str buf = {0};
    if (php_json_encode_ex(&buf, const_cast<zval *>(value.unwrap_ptr()), options, depth) != SUCCESS) {
        smart_str_free(&buf);
        return Variant(false);
    }
    smart_str_0(&buf);
    if (!buf.s) {
        return Variant(String());
    }
    Variant result(String(ZSTR_VAL(buf.s), ZSTR_LEN(buf.s)));
    smart_str_free(&buf);
    return result;
}

// ========================
// json_decode(string $json, ?bool $assoc = null, int $depth = 512, int $flags = 0): mixed
// ========================

inline Variant json_decode(const String &json, bool assoc = false, int depth = 512, int options = 0) {
    zval retval;
    ZVAL_NULL(&retval);
    if (php_json_decode_ex(
            &retval, json.data(), json.length(), options | (assoc ? PHP_JSON_OBJECT_AS_ARRAY : 0), depth) != SUCCESS) {
        return Variant(nullptr);
    }
    return Variant(&retval, Ctor::Move);
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
Variant version_compare(const String &v1, const String &v2, const String &op = String());

// ========================
// print_r(mixed $value, bool $return = false): string|bool
// ========================
Variant print_r(const Variant &value, bool do_return = false);

// uniqid(string $prefix = "", bool $more_entropy = false): string
String uniqid(const String &prefix = String(), bool more_entropy = false);

// parse_str(string $string, &$array = null): void
Array parse_str(const String &str);
void parse_str(const String &str, Array &result);

// shell_exec(string $command): string|false|null
Variant shell_exec(const String &command);

}  // namespace php::std
