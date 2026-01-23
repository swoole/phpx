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

#pragma once

#include "zend_types.h"

namespace php {
typedef unsigned char uchar;
typedef zend_long Int;
typedef double Float;
typedef bool Bool;

struct Resource {
    const char *name;
    int type;
};

class Variant;
class Array;
class Object;
class String;
class Args;
class Reference;

using var = Variant;
using array = Array;
using object = Object;
using string = String;

using Var = Variant;
using Str = String;
using Ref = Reference;

typedef void (*resource_dtor)(zend_resource *);

enum ZvalType {
    TYPE_UNDEF = IS_UNDEF,
    TYPE_NULL = IS_NULL,
    TYPE_FALSE = IS_FALSE,
    TYPE_TRUE = IS_TRUE,
    TYPE_LONG = IS_LONG,
    TYPE_DOUBLE = IS_DOUBLE,
    TYPE_STRING = IS_STRING,
    TYPE_ARRAY = IS_ARRAY,
    TYPE_OBJECT = IS_OBJECT,
    TYPE_RESOURCE = IS_RESOURCE,
    TYPE_REFERENCE = IS_REFERENCE,
};
}  // namespace php
