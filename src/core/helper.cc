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
#include "zend_operators.h"

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
namespace fn {
bool function_exists(const String &fname, bool formatted) {
    if (formatted) {
        return zend_hash_exists(EG(function_table), fname.str());
    }

    zend_string *name = fname.str();
    bool exists;
    zend_string *lcname;

    if (ZSTR_VAL(name)[0] == '\\') {
        /* Ignore leading "\" */
        lcname = zend_string_alloc(ZSTR_LEN(name) - 1, 0);
        zend_str_tolower_copy(ZSTR_VAL(lcname), ZSTR_VAL(name) + 1, ZSTR_LEN(name) - 1);
    } else {
        lcname = zend_string_tolower(name);
    }

    exists = zend_hash_exists(EG(function_table), lcname);
    zend_string_release_ex(lcname, 0);
    return exists;
}

Int ord(const Variant &v) {
    auto sv = v.toString();
    return sv.data()[0];
}

String chr(Int c) {
    return {zend_one_char_string[c]};
}
}  // namespace fn
}  // namespace php
