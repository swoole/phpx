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

#include <string>
#include <initializer_list>
#include <functional>
#include <vector>

namespace php {
typedef unsigned char uchar;
typedef zend_long Int;
typedef double Float;
typedef bool Bool;

enum Operation {
    ArrayDimFetch,
    PropertyFetch,
};

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
class Box;

using var = Variant;
using array = Array;
using object = Object;
using string = String;

using Var = Variant;
using Str = String;
using Ref = Reference;
using ArgList = std::initializer_list<const Variant>;
using OperationChain = std::initializer_list<std::pair<Operation, const Variant>>;

using StrKeyMap = std::initializer_list<std::pair<zend_string *, const Variant>>;
/**
 * A `String` object cannot be used as an array key, as this may create ambiguity with the definition of `ArrayList`.
 * Since `String` is a subclass of `Variant`, `{String, Variant}` could be interpreted as an `ArrayList` type. When
 * using strings as keys in a map, the key may only be `std::string` or `zend_string*`.
 */
using StdStrKeyMap = std::initializer_list<std::pair<const std::string, const Variant>>;
using IntKeyMap = std::initializer_list<std::pair<Int, const Variant>>;
using ArrayList = std::initializer_list<const Variant>;

using ClosureFn = std::function<Variant(INTERNAL_FUNCTION_PARAMETERS, Object &, Args &)>;

typedef void (*resource_dtor)(zend_resource *);
}  // namespace php
