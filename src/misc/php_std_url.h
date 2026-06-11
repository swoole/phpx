/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP URL and base64 functions     |
  +----------------------------------------------------------------------+
  | Eliminates zend_call_function overhead by directly calling PHP APIs   |
  +----------------------------------------------------------------------+
*/

#pragma once

#include "phpx.h"

extern "C" {
#include "ext/standard/url.h"
#include "ext/standard/base64.h"
}

namespace php::std {

// ========================
// URL encode/decode
// ========================

inline String urlencode(const String &s) {
    zend_string *encoded = php_url_encode(s.data(), s.length());
    return String(encoded, php::Ctor::Copy);
}

inline String urldecode(const String &s) {
    size_t len = s.length();
    zend_string *buf = zend_string_init(s.data(), len, false);
    ZSTR_LEN(buf) = php_url_decode(ZSTR_VAL(buf), len);
    return String(buf, php::Ctor::Move);
}

inline String rawurlencode(const String &s) {
    zend_string *encoded = php_raw_url_encode(s.data(), s.length());
    return String(encoded, php::Ctor::Copy);
}

inline String rawurldecode(const String &s) {
    size_t len = s.length();
    zend_string *buf = zend_string_init(s.data(), len, false);
    ZSTR_LEN(buf) = php_raw_url_decode(ZSTR_VAL(buf), len);
    return String(buf, php::Ctor::Move);
}

// ========================
// get_headers (stub)
// ========================

inline Variant get_headers(const String &url, bool associative = false) {
    // TODO: implement HTTP header fetching via php_stream_open_wrapper_ex
    return Variant(false);
}

// ========================
// base64 encode/decode
// ========================

inline String base64_encode(const String &s) {
    zend_string *encoded = php_base64_encode(
        reinterpret_cast<const unsigned char *>(s.data()), s.length());
    return String(encoded, php::Ctor::Copy);
}

inline Variant base64_decode(const String &s, bool strict = false) {
    zend_string *decoded = php_base64_decode_ex(
        reinterpret_cast<const unsigned char *>(s.data()), s.length(), strict);
    if (decoded == nullptr) {
        return Variant(false);
    }
    return Variant(String(decoded, php::Ctor::Copy));
}

// ========================
// parse_url (implemented in .cpp)
// ========================

Variant parse_url(const String &url, Int component = -1);

}  // namespace php::std
