/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP string functions             |
  +----------------------------------------------------------------------+
  | Eliminates zend_call_function overhead by directly calling Zend APIs  |
  +----------------------------------------------------------------------+
*/

#pragma once

#include "phpx.h"

namespace php::fn {

// ========================
// str_starts_with(string $haystack, string $needle): bool
// ========================
inline Bool str_starts_with(const String &haystack, const String &needle) {
    return zend_string_starts_with(haystack.str(), needle.str());
}

// ========================
// str_ends_with(string $haystack, string $needle): bool
// ========================
inline Bool str_ends_with(const String &haystack, const String &needle) {
    size_t hlen = ZSTR_LEN(haystack.str());
    size_t nlen = ZSTR_LEN(needle.str());
    return hlen >= nlen && memcmp(ZSTR_VAL(haystack.str()) + hlen - nlen, ZSTR_VAL(needle.str()), nlen) == 0;
}

// ========================
// str_contains(string $haystack, string $needle): bool
// ========================
inline Bool str_contains(const String &haystack, const String &needle) {
    const char *found = (const char *) php_memnstr(ZSTR_VAL(haystack.str()),
                                                   ZSTR_VAL(needle.str()),
                                                   ZSTR_LEN(needle.str()),
                                                   ZSTR_VAL(haystack.str()) + ZSTR_LEN(haystack.str()));
    return found != nullptr;
}

// ========================
// lcfirst(string $s): string
// ========================
inline String lcfirst(const String &s) {
    if (s.length() == 0) {
        return String();
    }
    zend_string *result = zend_string_alloc(s.length(), 0);
    ZSTR_VAL(result)[s.length()] = '\0';
    memcpy(ZSTR_VAL(result), s.data(), s.length());
    if (ZSTR_VAL(result)[0] >= 'A' && ZSTR_VAL(result)[0] <= 'Z') {
        ZSTR_VAL(result)[0] = (char) (ZSTR_VAL(result)[0] + 32);
    }
    return String(result, Ctor::Move);
}

// ========================
// explode(string $delimiter, string $string, int $limit = PHP_INT_MAX): array
// ========================
Array explode(const String &delimiter, const String &string, Int limit = ZEND_LONG_MAX);

// ========================
// implode(string $glue, array $pieces): string
// join(...) — alias
// ========================
String implode(const String &glue, const Array &pieces);
inline String join(const String &glue, const Array &pieces) {
    return implode(glue, pieces);
}

// ========================
// strpos / stripos / strrpos / strripos
// ========================
Variant strpos(const String &haystack, const String &needle, Int offset = 0);
Variant stripos(const String &haystack, const String &needle, Int offset = 0);
Variant strrpos(const String &haystack, const String &needle, Int offset = 0);

// ========================
// strstr / stristr
// ========================
Variant strstr(const String &haystack, const String &needle, bool before_needle = false);
Variant stristr(const String &haystack, const String &needle, bool before_needle = false);

// ========================
// substr(string $s, int $offset, ?int $length = null): string
// ========================
String substr(const String &s, Int offset, const Variant &length = Variant());

// ========================
// trim / ltrim / rtrim
// Pass nullptr/0 for what/what_len to use default whitespace chars.
// Mode: 1=left, 2=right, 3=both.
// ========================
inline String trim(const String &s, const char *what = nullptr, size_t what_len = 0) {
    return String(php_trim(s.str(), what, what_len, 3), Ctor::Move);
}
inline String ltrim(const String &s, const char *what = nullptr, size_t what_len = 0) {
    return String(php_trim(s.str(), what, what_len, 1), Ctor::Move);
}
inline String rtrim(const String &s, const char *what = nullptr, size_t what_len = 0) {
    return String(php_trim(s.str(), what, what_len, 2), Ctor::Move);
}

// ========================
// strtolower / strtoupper
// ========================
inline String strtolower(const String &s) {
    size_t slen = s.length();
    if (slen == 0) {
        return String();
    }
    auto result = zend_string_tolower(s.str());
    return String(result, Ctor::Move);
}

inline String strtoupper(const String &s) {
    size_t slen = s.length();
    if (slen == 0) {
        return String();
    }
    auto result = zend_string_toupper(s.str());
    return String(result, Ctor::Move);
}

// ========================
// str_repeat(string $s, int $times): string
// ========================
inline String str_repeat(const String &s, Int times) {
    if (times < 0) {
        php::throwException(zend_ce_value_error,
                            "str_repeat(): Argument #2 ($times) must be greater than or equal to 0");
        return String();
    }
    if (times == 0) {
        return String();
    }
    size_t slen = s.length();
    zend_string *result = zend_string_safe_alloc((size_t) times, slen, 0, 0);
    char *p = ZSTR_VAL(result);
    for (Int i = 0; i < times; i++) {
        memcpy(p + (size_t) i * slen, s.data(), slen);
    }
    ZSTR_VAL(result)[(size_t) times * slen] = '\0';
    return String(result, Ctor::Move);
}

// ========================
// dirname / basename
// ========================
String dirname(const String &path, int levels = 1);
String basename(const String &path, const String &suffix = String());

// ucfirst(string $s): string
inline String ucfirst(const String &s) {
    if (s.length() == 0) {
        return String();
    }
    zend_string *result = zend_string_alloc(s.length(), 0);
    ZSTR_VAL(result)[s.length()] = '\0';
    memcpy(ZSTR_VAL(result), s.data(), s.length());
    if (ZSTR_VAL(result)[0] >= 'a' && ZSTR_VAL(result)[0] <= 'z') {
        ZSTR_VAL(result)[0] = (char) (ZSTR_VAL(result)[0] - 32);
    }
    return String(result, Ctor::Move);
}

// ========================
// ord(string $s): int
// ========================
inline Int ord(const String &s) {
    if (s.length() == 0) {
        return 0;
    }
    return static_cast<Int>(static_cast<unsigned char>(s.data()[0]));
}

// ========================
// chr(int $codepoint): string
// ========================
inline String chr(Int c) {
    return String(zend_one_char_string[static_cast<unsigned char>(c)], Ctor::Copy);
}

}  // namespace php::fn
