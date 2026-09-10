/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | Direct C++ wrappers for PHP's random extension.                      |
  | SPDX-License-Identifier: Apache-2.0                                  |
  +----------------------------------------------------------------------+
*/

#pragma once

extern "C" {
#include "php.h"
#include "Zend/zend_exceptions.h"
#include "ext/random/php_random.h"
}

#include "phpx.h"

namespace php::fn {

inline Int random_int(Int min, Int max) {
    if (UNEXPECTED(min > max)) {
        php::throwException(zend_ce_value_error,
                            "random_int(): Argument #1 ($min) must be less than or equal to argument #2 ($max)");
        return 0;
    }
    zend_long result;
    if (php_random_int(min, max, &result, true) == FAILURE) {
        throwErrorIfOccurred();
        return 0;
    }
    return static_cast<Int>(result);
}

inline String random_bytes(Int length) {
    if (UNEXPECTED(length < 1)) {
        php::throwException(zend_ce_value_error, "random_bytes(): Argument #1 ($length) must be greater than 0");
        return String();
    }
    zend_string *bytes = zend_string_alloc(length, 0);
    if (php_random_bytes(ZSTR_VAL(bytes), length, true) == FAILURE) {
        zend_string_release(bytes);
        throwErrorIfOccurred();
        return String();
    }
    ZSTR_VAL(bytes)[length] = 0;
    return String(bytes, Ctor::Move);
}

inline Int mt_rand() {
    return static_cast<Int>(php_mt_rand() >> 1);
}

inline Int mt_rand(Int min, Int max) {
    if (UNEXPECTED(max < min)) {
        php::throwException(zend_ce_value_error,
                            "mt_rand(): Argument #2 ($max) must be greater than or equal to argument #1 ($min)");
        return 0;
    }
    return static_cast<Int>(php_mt_rand_common(min, max));
}

inline Int rand() {
    return static_cast<Int>(php_mt_rand() >> 1);
}

inline Int rand(Int min, Int max) {
    if (max < min) {
        return static_cast<Int>(php_mt_rand_common(max, min));
    }
    return static_cast<Int>(php_mt_rand_common(min, max));
}

}  // namespace php::fn
