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

// floor(float $num): float
inline Float floor(const Variant &value) {
    return static_cast<Float>(::floor(value.toFloat()));
}

// ceil(float $num): float
inline Float ceil(const Variant &value) {
    return static_cast<Float>(::ceil(value.toFloat()));
}

// max(mixed $value, mixed ...$values): mixed
Variant max(const Variant &arg);

// min(mixed $value, mixed ...$values): mixed
Variant min(const Variant &arg);

}  // namespace php::std
