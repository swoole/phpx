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
    if (memchr(path.data(), '\0', path.length())) {
        php::throwException(zend_ce_value_error,
                            "realpath(): Argument #1 ($path) must not contain any null bytes");
        return Variant();
    }

    char resolved[MAXPATHLEN];
    if (!VCWD_REALPATH(path.data(), resolved)) {
        return Variant(false);
    }
    if (php_check_open_basedir(resolved)) {
        return Variant(false);
    }
#ifdef ZTS
    if (VCWD_ACCESS(resolved, F_OK)) {
        return Variant(false);
    }
#endif
    return Variant(String(resolved));
}

}  // namespace php::fn
