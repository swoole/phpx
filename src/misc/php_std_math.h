/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP math functions               |
  +----------------------------------------------------------------------+
  | round via PHPAPI _php_math_round()                                    |
  +----------------------------------------------------------------------+
*/

#pragma once

#include "phpx.h"

extern "C" {
#include "ext/standard/php_math.h"
}

namespace php::std {

// round(mixed $num, int $precision = 0, int $mode = PHP_ROUND_HALF_UP): float
Float round(const Variant &value, Int precision = 0, Int mode = PHP_ROUND_HALF_UP);

// abs(mixed $value): int|float
inline Variant abs(const Variant &value) {
    if (value.isInt()) {
        Int v = value.toInt();
        return Variant(v >= 0 ? v : -v);
    }
    double v = value.toFloat();
    return Variant(v >= 0 ? v : -v);
}

// floor(float $num): float
inline Float floor(const Variant &value) {
    return static_cast<Float>(::floor(value.toFloat()));
}

// ceil(float $num): float
inline Float ceil(const Variant &value) {
    return static_cast<Float>(::ceil(value.toFloat()));
}

// number_format(float $num, int $decimals = 0, ?string $decimal_separator = '.', ?string $thousands_separator = ','): string
inline String number_format(const Variant &num, Int decimals = 0,
                             const String &dec_point = String(".", 1),
                             const String &thousand_sep = String(",", 1)) {
    zend_string *result = _php_math_number_format_ex(num.toFloat(), (int) decimals,
                                                      dec_point.data(), dec_point.length(),
                                                      thousand_sep.data(), thousand_sep.length());
    return String(result, Ctor::Move);
}

}  // namespace php::std
