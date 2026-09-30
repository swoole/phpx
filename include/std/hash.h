/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - PHP hash wrappers                                       |
  +----------------------------------------------------------------------+
*/

#pragma once

#include "phpx.h"

extern "C" {
#include "ext/standard/md5.h"
#include "ext/standard/sha1.h"
#include "ext/hash/php_hash.h"
}


namespace php::fn {

Variant md5(const String &value, bool raw_output = false);
Variant sha1(const String &value, bool raw_output = false);
Variant hash(const String &algo, const String &data, bool raw_output = false);

}  // namespace php::fn
