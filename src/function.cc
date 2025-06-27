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

using namespace std;

namespace php {

Variant http_build_query(const Variant &data, const char *prefix, const char *arg_sep, int enc_type) {
    smart_str formstr = {0};

    Variant &_data = const_cast<Variant &>(data);
    if (!_data.isArray() && !_data.isObject()) {
        error(E_WARNING, "Parameter 1 expected to be Array or Object.  Incorrect value given");
        return false;
    }

    size_t prefix_len = prefix != nullptr ? strlen(prefix) : 0;

#if PHP_VERSION_ID >= 80300
    auto _arg_sep = zend_string_init(arg_sep, strlen(arg_sep), 0);
    php_url_encode_hash_ex(HASH_OF(_data.ptr()), &formstr, prefix, prefix_len, NULL, NULL, _arg_sep, enc_type);
    zend_string_release(_arg_sep);
#else
    php_url_encode_hash_ex(HASH_OF(_data.ptr()),
                           &formstr,
                           prefix,
                           prefix_len,
                           NULL,
                           0,
                           NULL,
                           0,
                           (_data.isObject() ? _data.ptr() : NULL),
                           (char *) arg_sep,
                           enc_type);
#endif

    if (!formstr.s) {
        return "";
    }

    smart_str_0(&formstr);
    return formstr.s;
}

}  // namespace php
