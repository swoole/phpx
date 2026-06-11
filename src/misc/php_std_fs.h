/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP filesystem functions         |
  +----------------------------------------------------------------------+
  | is_dir, is_file via PHPAPI php_stat()                                 |
  +----------------------------------------------------------------------+
*/

#pragma once

#include "phpx.h"

extern "C" {
#include "ext/standard/php_filestat.h"
}

namespace php::std {

Bool is_dir(const String &filename);
Bool is_file(const String &filename);
Variant realpath(const String &path);

}  // namespace php::std
