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

Variant http_build_query(const Variant &data, const char* prefix, const char* arg_sep, int enc_type)
{
    Variant &_data = const_cast<Variant &>(data);
    if (!_data.isArray() && !_data.isObject())
    {
        error(E_WARNING, "Parameter 1 expected to be Array or Object.  Incorrect value given");
        return false;
    }

    Variant param_prefix(prefix);
    Variant param_arg_sep(arg_sep);
    Variant param_enc_type(enc_type);

    Variant retval = exec("http_build_query", _data, param_prefix, param_arg_sep, param_enc_type);
    return retval;
}

}


