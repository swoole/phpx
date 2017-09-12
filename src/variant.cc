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

#include "zend_smart_str.h"

using namespace std;

namespace php
{

bool Variant::equals(Variant &v, bool strict)
{
    if (strict)
    {
        if (fast_is_identical_function(v.ptr(), ptr()))
        {
            return true;
        }
    }
    else
    {
        if (v.isInt())
        {
            if (fast_equal_check_long(v.ptr(), ptr()))
            {
                return true;
            }
        }
        else if (v.isString())
        {
            if (fast_equal_check_string(v.ptr(), ptr()))
            {
                return true;
            }
        }
        else
        {
            if (fast_equal_check_function(v.ptr(), ptr()))
            {
                return true;

            }
        }
    }
    return false;
}

Variant Variant::serialize()
{
    return exec("serialize", *this);
}

Variant Variant::unserialize()
{
    return exec("unserialize", *this);
}

Variant Variant::jsonEncode(zend_long options, zend_long depth)
{
    Variant param_options(options);
    Variant param_depth(depth);

    return exec("json_encode", *this, param_options, param_depth);
}

Variant Variant::jsonDecode(zend_long options, zend_long depth)
{
    Variant param_assoc(true);
    Variant param_depth(depth);
    Variant param_options(options);

    return exec("json_decode", *this, param_assoc, param_depth, param_options);
}

bool Variant::isCallable()
{
    return zend_is_callable(ptr(), 0, nullptr);
}

}
