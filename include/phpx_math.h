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
namespace math {
static inline Int abs(Int v) {
    return std::abs(v);
}

static inline Float abs(Float v) {
    return std::fabs(v);
}

Variant abs(const Variant &v);

static inline Variant mod(const Variant &a, const Variant &b) {
    return a % b;
}
}  // namespace math
}  // namespace php
