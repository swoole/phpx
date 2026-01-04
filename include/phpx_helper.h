/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <rango@swoole.com>                             |
  +----------------------------------------------------------------------+
*/

#pragma once

#include "phpx.h"

namespace php {
static inline bool equals(Int a, Int b) {
    return a == b;
}

static inline bool equals(Float a, Float b) {
    return a == b;
}

static inline Int to_int(Int v) {
    return v;
}

static inline Int to_int(const Variant &v) {
    return v.toInt();
}

static inline Float to_float(Float v) {
    return v;
}

static inline Float to_float(const Variant &v) {
    return v.toFloat();
}

static inline bool to_bool(bool v) {
    return v;
}

static inline bool to_bool(const Variant &v) {
    return v.toBool();
}

static inline void echo(int val) {
    echo((Int) val);
}

static inline Int len(const Variant &v) {
    return v.length();
}
}  // namespace php
