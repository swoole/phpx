/*
  +----------------------------------------------------------------------+
  | Swoole                                                               |
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

namespace php
{

int array_data_compare(const void *a, const void *b)
{
    Bucket *f;
    Bucket *s;
    zval result;
    zval *first;
    zval *second;

    f = (Bucket *) a;
    s = (Bucket *) b;

    first = &f->val;
    second = &s->val;

    if (UNEXPECTED(Z_TYPE_P(first) == IS_INDIRECT))
    {
        first = Z_INDIRECT_P(first);
    }
    if (UNEXPECTED(Z_TYPE_P(second) == IS_INDIRECT))
    {
        second = Z_INDIRECT_P(second);
    }
    if (compare_function(&result, first, second) == FAILURE)
    {
        return 0;
    }

    ZEND_ASSERT(Z_TYPE(result) == IS_LONG);
    return Z_LVAL(result);
}

}
