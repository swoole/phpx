/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Type checking, misc, and variable function wrappers      |
  +----------------------------------------------------------------------+
  | Implementations for microtime, hrtime, crc32, pack/unpack,            |
  | and HTML entity functions.                                            |
  +----------------------------------------------------------------------+
*/

#include "php_std_misc.h"

#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <cerrno>
#include <sys/time.h>

namespace php::std {

// ========================
// md5
// ========================

Variant md5(const String &s, bool raw_output) {
    PHP_MD5_CTX context;
    unsigned char digest[16];

    PHP_MD5Init(&context);
    PHP_MD5Update(&context, (const unsigned char *) s.data(), s.length());
    PHP_MD5Final(digest, &context);

    if (raw_output) {
        return Variant(String((char *) digest, 16));
    }

    char hex[33];
    make_digest_ex(hex, digest, 16);
    return Variant(String(hex, 32));
}

// ========================
// version_compare
// ========================

Int version_compare(const String &v1, const String &v2) {
    return static_cast<Int>(php_version_compare(v1.data(), v2.data()));
}

// ========================
// print_r
// ========================

Variant print_r(const Variant &value, bool do_return) {
    if (do_return) {
        zend_string *s = zend_print_zval_r_to_str(NO_CONST_V(value), 0);
        if (!s) {
            return Variant(String());
        }
        return Variant(String(s, Ctor::Move));
    }
    zend_print_zval_r(NO_CONST_V(value), 0);
    return Variant(true);
}

// ========================
// uniqid
// ========================

static zend_string *_uniqid_hash(const String &prefix, bool more_entropy) {
    char uniqid_buf[128];
    struct timeval tv;
    gettimeofday(&tv, NULL);
    zend_ulong sec = static_cast<zend_ulong>(tv.tv_sec);
    int usec = static_cast<int>(tv.tv_usec % 0x100000);

    if (more_entropy) {
        int len = snprintf(uniqid_buf,
                           sizeof(uniqid_buf),
                           "%s%08lx%05x%.8F",
                           prefix.length() > 0 ? prefix.data() : "",
                           sec,
                           usec,
                           php_combined_lcg() * 10);
        return zend_string_init(uniqid_buf, len, 0);
    }

    int len =
        snprintf(uniqid_buf, sizeof(uniqid_buf), "%s%08lx%05x", prefix.length() > 0 ? prefix.data() : "", sec, usec);
    return zend_string_init(uniqid_buf, len, 0);
}

String uniqid(const String &prefix, bool more_entropy) {
    zend_string *s = _uniqid_hash(prefix, more_entropy);
    return String(s, Ctor::Move);
}

// ========================
// parse_str
// ========================

Array parse_str(const String &str) {
    Array retval;
    auto res = estrndup(str.data(), str.length());
    sapi_module.treat_data(PARSE_STRING, res, retval.ptr());
    return retval;
}

// ========================
// shell_exec
// ========================

Variant shell_exec(const String &command) {
    if (command.length() == 0) {
        zend_argument_value_error(1, "cannot be empty");
        return Variant(nullptr);
    }

#ifdef PHP_WIN32
    FILE *in = VCWD_POPEN(command.data(), "rt");
#else
    FILE *in = VCWD_POPEN(command.data(), "r");
#endif
    if (!in) {
        php_error_docref(nullptr, E_WARNING, "Unable to execute '%s'", command.data());
        return Variant(false);
    }

    php_stream *stream = php_stream_fopen_from_pipe(in, "rb");
    zend_string *ret = php_stream_copy_to_mem(stream, PHP_STREAM_COPY_ALL, 0);
    php_stream_close(stream);

    if (ret && ZSTR_LEN(ret) > 0) {
        return Variant(String(ret, php::Ctor::Move));
    }
    if (ret) {
        zend_string_release(ret);
    }
    return Variant(nullptr);
}

}  // namespace php::std
