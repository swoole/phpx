/*
  +----------------------------------------------------------------------+
  | PHP-X                                                               |
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

#include "zend_smart_str.h"

using namespace std;

namespace php
{

Variant Variant::serialize()
{
    smart_str serialized_data = { 0 };
	php_serialize_data_t var_hash;
	PHP_VAR_SERIALIZE_INIT(var_hash);
	php_var_serialize(&serialized_data, ptr(), &var_hash TSRMLS_CC);
	PHP_VAR_SERIALIZE_DESTROY(var_hash);
	Variant retval(serialized_data.s->val, serialized_data.s->len);
	smart_str_free(&serialized_data);
	retval.addRef();
	return retval;
}

Variant Variant::unserialize()
{
    php_unserialize_data_t var_hash;
    Variant retval;
	PHP_VAR_UNSERIALIZE_INIT(var_hash);

	char *data = Z_STRVAL_P(ptr());
	size_t length = Z_STRLEN_P(ptr());
	if (php_var_unserialize(retval.ptr(), (const unsigned char **) &data,
			(const unsigned char *) data + length, &var_hash))
	{
		retval.addRef();
		return retval;
	}
	else
	{
		return nullptr;
	}
}

}
