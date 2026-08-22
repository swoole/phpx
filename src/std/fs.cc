/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP filesystem functions         |
  +----------------------------------------------------------------------+
*/

#include "std/fs.h"

namespace php::fn {

static Bool _fs_stat(const String &filename, int type) {
    zval retval;
    ZVAL_UNDEF(&retval);
    php_stat(filename.str(), type, &retval);
    Bool result = Z_TYPE(retval) != IS_UNDEF && zend_is_true(&retval);
    zval_ptr_dtor(&retval);
    return result;
}

Bool is_dir(const String &filename) {
    return _fs_stat(filename, FS_IS_DIR);
}

Bool is_file(const String &filename) {
    return _fs_stat(filename, FS_IS_FILE);
}

Bool file_exists(const String &filename) {
    return _fs_stat(filename, FS_EXISTS);
}

Variant realpath(const String &path) {
    // expand_filepath() follows Zend's MAXPATHLEN contract. PATH_MAX is not
    // guaranteed to describe the same buffer size, notably on Windows.
    char resolved[MAXPATHLEN];
    if (!expand_filepath(path.data(), resolved)) {
        return Variant(false);
    }
    return Variant(String(resolved));
}

}  // namespace php::fn
