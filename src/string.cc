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
  | Author: Tianfeng Han  <mikan.tenny@gmail.com>                        |
  +----------------------------------------------------------------------+
*/

#include "phpx.h"

namespace php {
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

    return {value->val + f, (size_t) l};
}

Variant String::split(const String &delim, const long limit) const {
    Array retval;
    php_explode(delim.ptr(), value, retval.ptr(), limit);
    return retval;
}

void String::stripTags(const String &allow, bool allow_tag_spaces) const {
    value->len = php_strip_tags_ex(c_str(), length(), allow.c_str(), allow.length(), allow_tag_spaces);
}

String String::addSlashes() const {
    return php_addslashes(value);
}

String String::basename(const String &suffix) const {
    return php_basename(this->c_str(), this->length(), suffix.c_str(), suffix.length());
}

String String::dirname() const {
    size_t n = php_dirname(this->c_str(), this->length());
    return {this->c_str(), n};
}

void String::stripSlashes() const {
    php_stripslashes(value);
}

}  // namespace php
