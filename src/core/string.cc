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

namespace php {
String::String(Variant &v) {
    str = zval_get_string(v.ptr());
}

String String::substr(long f, long l) const {
    if (f < 0) {
        /* if "from" position is negative, count start position from the end
         * of the string
         */
        if (-(size_t) f > length()) {
            f = 0;
        } else {
            f = (zend_long) length() + f;
        }
    } else if ((size_t) f > length()) {
        return "";
    }

    if (l < 0) {
        /* if "length" position is negative, set it to the length
         * needed to stop that many chars from the end of the string
         */
        if (-(size_t) l > length() - (size_t) f) {
            l = 0;
        } else {
            l = (zend_long) length() - f + l;
        }
    } else if ((size_t) l > length() - (size_t) f) {
        l = (zend_long) length() - f;
    }

    return {str->val + f, (size_t) l};
}

Variant String::split(const String &delim, const long limit) const {
    Array retval;
    php_explode(delim.ptr(), str, retval.ptr(), limit);
    return retval;
}

void String::stripTags(const String &allow, bool allow_tag_spaces) const {
    str->len = php_strip_tags_ex(c_str(), length(), allow.c_str(), allow.length(), allow_tag_spaces);
}

String String::addSlashes() const {
    return php_addslashes(str);
}

String String::basename(const String &suffix) const {
    return php_basename(c_str(), length(), suffix.c_str(), suffix.length());
}

String String::dirname() const {
    size_t n = php_dirname(c_str(), length());
    return {c_str(), n};
}

void String::stripSlashes() const {
    php_stripslashes(str);
}

}  // namespace php
