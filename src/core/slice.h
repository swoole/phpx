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

#include "phpx_types.h"

#include <cstddef>

namespace php::detail {

static inline bool prepareSlice(Int &offset, Int &length, size_t total) {
    if (offset < 0) {
        if (-static_cast<size_t>(offset) > total) {
            offset = 0;
        } else {
            offset = static_cast<Int>(total) + offset;
        }
    } else if (static_cast<size_t>(offset) > total) {
        return false;
    }

    if (length < 0) {
        if (-static_cast<size_t>(length) > total - static_cast<size_t>(offset)) {
            length = 0;
        } else {
            length = static_cast<Int>(total) - offset + length;
        }
    } else if (static_cast<size_t>(length) > total - static_cast<size_t>(offset)) {
        length = static_cast<Int>(total) - offset;
    }

    return true;
}

}  // namespace php::detail
