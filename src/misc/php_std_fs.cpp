/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP filesystem functions         |
  +----------------------------------------------------------------------+
*/

#include "php_std_fs.h"

#include <climits>

namespace php::std {

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

Variant realpath(const String &path) {
    char resolved[PATH_MAX];
    if (!expand_filepath(path.data(), resolved)) {
        return Variant(false);
    }
    return Variant(String(resolved));
}

}  // namespace php::std
