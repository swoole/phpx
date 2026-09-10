/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - PHP hash wrappers                                       |
  +----------------------------------------------------------------------+
*/

#pragma once

extern "C" {
#include "php.h"
#include "ext/standard/md5.h"
#include "ext/standard/sha1.h"
#include "ext/hash/php_hash.h"
}

#include "phpx.h"

namespace php::fn {

Variant md5(const String &value, bool raw_output = false);
Variant sha1(const String &value, bool raw_output = false);
Variant hash(const String &algo, const String &data, bool raw_output = false);

}  // namespace php::fn
