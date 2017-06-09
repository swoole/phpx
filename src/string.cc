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

}
