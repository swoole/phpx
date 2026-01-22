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

#include "phpx.h"
#include "phpx_helper.h"
#include "phpx_func.h"

namespace php {
namespace math {
Variant abs(const Variant &v) {
    switch (v.type()) {
    case IS_LONG:
        return std::abs(v.toInt());
    case IS_DOUBLE:
        return std::fabs(v.toFloat());
    default:
        return php::abs(v);
    }
}
}  // namespace math
}  // namespace php
