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

namespace php
{

String md5(String data, bool raw_output)
{
    Variant param_str(data.c_str(), data.length());
    Variant param_raw_output(raw_output);

    Variant retval = exec("md5", param_str, param_raw_output);
    if (retval.isString())
    {
        return String(retval.toCString(), retval.length());
    }
    return String("");
}

String sha1(String data, bool raw_output)
{
    Variant param_str(data.c_str(), data.length());
    Variant param_raw_output(raw_output);

    Variant retval = exec("sha1", param_str, param_raw_output);
    if (retval.isString())
    {
        return String(retval.toCString(), retval.length());
    }
    return String("");
}

int crc32(String data)
{
    Variant param_str(data.c_str(), data.length());

    Variant retval = exec("crc32", param_str);
    return retval.toInt();
}

String hash(String algo, String data, bool raw_output)
{
    Variant param_algo(algo.c_str(), algo.length());
    Variant param_str(data.c_str(), data.length());
    Variant param_raw_output(raw_output);

    Variant retval = exec("hash", param_algo, param_str, param_raw_output);
    if (retval.isString())
    {
        return String(retval.toCString(), retval.length());
    }
    return String("");
}

String hash_hmac(String algo, String data, String key, bool raw_output)
{
    Variant param_algo(algo.c_str(), algo.length());
    Variant param_str(data.c_str(), data.length());
    Variant param_key(key.c_str(), key.length());
    Variant param_raw_output(raw_output);

    Variant retval = exec("hash_hmac", param_algo, param_str, param_key, param_raw_output);
    if (retval.isString())
    {
        return String(retval.toCString(), retval.length());
    }
    return String("");
}

}
