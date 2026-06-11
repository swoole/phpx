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
#include "zend_hrtime.h"
#include "ext/standard/crc32.h"
#include "ext/standard/url.h"
#include "ext/standard/html.h"
#include "ext/standard/md5.h"
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
    uint32_t init = 0;
    uint32_t crc = php_crc32_bulk_update(init, s.data(), s.length());
    return static_cast<Int>(crc ^ 0xFFFFFFFF);
}

// ========================
// microtime (needs gettimeofday, implemented in .cpp)
// ========================

Variant microtime(bool as_float = false);

// ========================
// hrtime (needs clock_gettime via zend_hrtime, implemented in .cpp)
// ========================

Variant hrtime(bool as_number = false);

// ========================
// pack / unpack (complex, implemented in .cpp)
// ========================

Variant pack(const String &format, const Variant &values);
Variant unpack(const String &format, const String &data, Int offset = 0);

// ========================
// HTML entity functions (implemented in .cpp)
// ========================

String htmlspecialchars(const String &s, Int flags = ENT_QUOTES | ENT_SUBSTITUTE,
                        const Variant &encoding = Variant(nullptr),
                        bool double_encode = true);

String htmlentities(const String &s, Int flags = ENT_QUOTES | ENT_SUBSTITUTE,
                    const Variant &encoding = Variant(nullptr),
                    bool double_encode = true);

String htmlspecialchars_decode(const String &s, Int flags = ENT_QUOTES | ENT_SUBSTITUTE);

String html_entity_decode(const String &s, Int flags = ENT_QUOTES | ENT_SUBSTITUTE,
                          const Variant &encoding = Variant(nullptr));

String strip_tags(const String &s, const Variant &allowed_tags = Variant(nullptr));

// ========================
// md5(string $string, bool $binary = false): string
// ========================
Variant md5(const String &s, bool raw_output = false);

// ========================
// version_compare(string $v1, string $v2): int
// ========================
Int version_compare(const String &v1, const String &v2);

// ========================
// print_r(mixed $value, bool $return = false): string|bool
// ========================
Variant print_r(const Variant &value, bool do_return = false);

// uniqid(string $prefix = "", bool $more_entropy = false): string
String uniqid(const String &prefix = String(), bool more_entropy = false);

// parse_str(string $string): array
Array parse_str(const String &str);

}  // namespace php::std
