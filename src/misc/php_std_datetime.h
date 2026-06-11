/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP date/time functions          |
  +----------------------------------------------------------------------+
  | time, date, strtotime via PHPAPI exports                              |
  +----------------------------------------------------------------------+
*/

#pragma once

#include "phpx.h"

extern "C" {
#include "ext/date/php_date.h"
}

namespace php::std {

// time(): int — current Unix timestamp
inline Int time() {
    return static_cast<Int>(php_time());
}

// date(string $format, ?int $timestamp = null): string
String date(const String &format, const Variant &timestamp = Variant());

// strtotime(string $datetime, ?int $baseTimestamp = null): int|false
Variant strtotime(const String &datetime, const Variant &baseTimestamp = Variant());

}  // namespace php::std
