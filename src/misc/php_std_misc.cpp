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
// sha1
// ========================

Variant sha1(const String &s, bool raw_output) {
    PHP_SHA1_CTX context;
    unsigned char digest[20];

    PHP_SHA1Init(&context);
    PHP_SHA1Update(&context, (const unsigned char *) s.data(), s.length());
    PHP_SHA1Final(digest, &context);

    if (raw_output) {
        return Variant(String((char *) digest, 20));
    }

    char hex[41];
    make_sha1_digest(hex, digest);
    return Variant(String(hex, 40));
}

// ========================
// hash
// ========================

Variant hash(const String &algo, const String &data, bool raw_output) {
    const php_hash_ops *ops = php_hash_fetch_ops(algo.str());
    if (!ops) {
        php_error_docref(nullptr, E_WARNING, "Unknown hashing algorithm: %s", algo.data());
        return Variant(false);
    }

    void *context = php_hash_alloc_context(ops);
    ops->hash_init(context, nullptr);
    ops->hash_update(context, (const unsigned char *) data.data(), data.length());

    auto *digest = (unsigned char *) emalloc(ops->digest_size);
    ops->hash_final(digest, context);
    efree(context);

    if (raw_output) {
        String result((char *) digest, ops->digest_size);
        efree(digest);
        return Variant(result);
    }

    size_t hex_len = ops->digest_size * 2;
    auto *hex = (char *) emalloc(hex_len + 1);
    php_hash_bin2hex(hex, digest, ops->digest_size);
    hex[hex_len] = '\0';
    efree(digest);

    String result(hex, hex_len);
    efree(hex);
    return Variant(result);
}

// ========================
// version_compare
// ========================

Variant version_compare(const String &v1, const String &v2, const String &op) {
    int result = php_version_compare(v1.data(), v2.data());
    if (op.length() == 0) {
        return Variant(static_cast<Int>(result));
    }

    if (zend_string_equals_literal(op.str(), "<") || zend_string_equals_literal(op.str(), "lt")) {
        return Variant(result == -1);
    }
    if (zend_string_equals_literal(op.str(), "<=") || zend_string_equals_literal(op.str(), "le")) {
        return Variant(result != 1);
    }
    if (zend_string_equals_literal(op.str(), ">") || zend_string_equals_literal(op.str(), "gt")) {
        return Variant(result == 1);
    }
    if (zend_string_equals_literal(op.str(), ">=") || zend_string_equals_literal(op.str(), "ge")) {
        return Variant(result != -1);
    }
    if (zend_string_equals_literal(op.str(), "==") || zend_string_equals_literal(op.str(), "=") ||
        zend_string_equals_literal(op.str(), "eq")) {
        return Variant(result == 0);
    }
    if (zend_string_equals_literal(op.str(), "!=") || zend_string_equals_literal(op.str(), "<>") ||
        zend_string_equals_literal(op.str(), "ne")) {
        return Variant(result != 0);
    }

    php::throwException(zend_ce_value_error,
                        "version_compare(): Argument #3 ($operator) must be a valid comparison operator");
    return Variant(false);
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
    Array result;
    auto res = estrndup(str.data(), str.length());
    sapi_module.treat_data(PARSE_STRING, res, result.ptr());
    return result;
}

void parse_str(const String &str, Array &result) {
    auto res = estrndup(str.data(), str.length());
    sapi_module.treat_data(PARSE_STRING, res, result.ptr());
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
