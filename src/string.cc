/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | Copyright (c) 2016-2017 The Swoole Group                             |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the GPL license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.gnu.org/licenses/                                         |
  | If you did not receive a copy of the GPL3.0 license and are unable   |
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <mikan.tenny@gmail.com>                        |
  +----------------------------------------------------------------------+
*/

#include "phpx.h"

using namespace std;

namespace php
{

String String::substr(long _offset, long _length)
{

    if ((_length < 0 && (size_t) (-_length) > this->length()))
    {
        return "";
    }
    else if (_length > (zend_long) this->length())
    {
        _length = this->length();
    }

    if (_offset > (zend_long) this->length())
    {
        return "";
    }
    else if (_offset < 0 && -_offset > this->length())
    {
        _offset = 0;
    }

    if (_length < 0 && (_length + (zend_long) this->length() - _offset) < 0)
    {
        return "";
    }

    /* if "from" position is negative, count start position from the end
     * of the string
     */
    if (_offset < 0)
    {
        _offset = (zend_long) this->length() + _offset;
        if (_offset < 0)
        {
            _offset = 0;
        }
    }

    /* if "length" position is negative, set it to the length
     * needed to stop that many chars from the end of the string
     */
    if (_length < 0)
    {
        _length = ((zend_long) this->length() - _offset) + _length;
        if (_length < 0)
        {
            _length = 0;
        }
    }

    if (_offset > (zend_long) this->length())
    {
        return "";
    }

    if ((_offset + _length) > (zend_long) this->length())
    {
        _length = this->length() - _offset;
    }

    return String(value->val + _offset, _length);
}

Variant String::split(String &delim, long limit)
{
    Variant param_delim(delim.c_str(), delim.length());
    zend_string_addref(value);
    Variant param_str(value);
    Variant param_limit(limit);
    return exec("explode", param_delim, param_str, param_limit);
}

void String::stripTags(String &allow)
{
    zend_string_addref(value);
    Variant param_str(value);
    Variant param_allow(allow.c_str(), allow.length());

    Variant ret = exec("strip_tags", param_str, param_allow);
    if (ret.isString()) {
        zend_string_release(value);
        ret.addRef();
        value = Z_STR_P(ret.ptr());
    }
}

String String::addSlashes()
{
    zend_string_addref(value);
    Variant param_str(value);

    Variant ret = exec("addslashes", param_str);
    if (ret.isString()) {
        return String(ret.toCString(), ret.length());
    }
    return String("");
}

String String::basename(String &suffix)
{
    zend_string_addref(value);
    Variant param_path(value);
    Variant param_suffix(suffix.c_str(), suffix.length());

    Variant ret = exec("basename", param_path, param_suffix);
    if (ret.isString()) {
        return String(ret.toCString(), ret.length());
    }
    return String("");
}

String String::dirname()
{
    zend_string_addref(value);
    Variant param_path(value);

    Variant ret = exec("dirname", param_path);
    if (ret.isString()) {
        return String(ret.toCString(), ret.length());
    }
    return String("");
}

void String::stripSlashes()
{
    zend_string_addref(value);
    Variant param_str(value);

    Variant ret = exec("stripcslashes", param_str);
    if (ret.isString()) {
        zend_string_release(value);
        ret.addRef();
        value = Z_STR_P(ret.ptr());
    }
}

}
