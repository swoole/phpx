/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP date/time functions          |
  +----------------------------------------------------------------------+
  | time, date and gmdate via PHPAPI exports                              |
  +----------------------------------------------------------------------+
*/

#pragma once

#include "phpx.h"

extern "C" {
#include "ext/date/php_date.h"
}

namespace php::fn {

// time(): int — current Unix timestamp
inline Int time() {
    return static_cast<Int>(php_time());
}

// date(string $format, ?int $timestamp = null): string
String date(const String &format, const Variant &timestamp = Variant());

// gmdate(string $format, ?int $timestamp = null): string
String gmdate(const String &format, const Variant &timestamp = Variant());

}  // namespace php::fn
