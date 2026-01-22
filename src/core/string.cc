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
String String::format(const char *format, ...) {
    va_list args;
    va_start(args, format);
    zend_string *s = vstrpprintf(0, format, args);
    va_end(args);
    return String(s, Ctor::Move);
}

String String::trim(const char *what, TrimMode mode) const {
    return String(php_trim(str(), what, strlen(what), mode), Ctor::Move);
}

void String::print() const {
    if (str()) {
        php_printf("(string[%zu]) \"%.*s\"\n", length(), (int) length(), data());
    } else {
        php_printf("(null)\n");
    }
}

bool String::equals(const String &s, const bool ci) const {
    if (s.length() != length()) {
        return false;
    }
    if (ci) {
        return s.length() == length() && zend_binary_strcasecmp(data(), length(), s.data(), s.length()) == 0;
    }
    return zend_string_equals(s.str(), str());
}

String String::offsetGet(zend_long _offset) const {
    _offset = offset(_offset);
    if (UNEXPECTED(_offset == -1)) {
        return String{"", 0};
    } else {
        return String{data() + _offset, 1};
    }
}

void String::offsetSet(zend_long _offset, const Variant &value) {
    _offset = offset(_offset);
    if (_offset != -1) {
        auto wr_str = value.toString();
        if (wr_str.length() > 0) {
            str()->val[_offset] = wr_str.str()->val[0];
        }
    }
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

    return {data() + f, (size_t) l};
}

Array String::split(const String &delim, const long limit) const {
    Array retval;
    php_explode(delim.str(), str(), retval.ptr(), limit);
    return retval;
}

String String::stripTags(const String &allow, bool allow_tag_spaces) const {
    auto new_str = zend_string_copy(str());
    new_str->len = php_strip_tags_ex(new_str->val, new_str->len, allow.data(), allow.length(), allow_tag_spaces);
    new_str->val[new_str->len] = '\0';
    return String(new_str, Ctor::Move);
}

String String::addSlashes() const {
    return String(php_addslashes(str()), Ctor::Move);
}

String String::basename(const String &suffix) const {
    return String(php_basename(data(), length(), suffix.data(), suffix.length()), Ctor::Move);
}

String String::dirname() const {
    auto new_str = zend_string_copy(str());
    new_str->len = php_dirname(new_str->val, new_str->len);
    new_str->val[new_str->len] = '\0';
    return String(new_str, Ctor::Move);
}

String String::stripSlashes() const {
    auto new_str = zend_string_copy(str());
    php_stripslashes(new_str);
    return String(new_str, Ctor::Move);
}

}  // namespace php
