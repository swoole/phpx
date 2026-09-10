/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Type checking, misc, and variable function wrappers      |
  +----------------------------------------------------------------------+
  | Implementations for microtime, hrtime, crc32, pack/unpack,            |
  | and HTML entity functions.                                            |
  +----------------------------------------------------------------------+
*/

#include "std/misc.h"

#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <cerrno>
#include <chrono>
#include <cinttypes>

#ifdef PHPX_NANO
#include "php_nano_extension.h"
#endif

namespace php::fn {

// ========================
// version_compare
// ========================

Variant version_compare(const String &v1, const String &v2, const Variant &op) {
    int result = php_version_compare(v1.data(), v2.data());
    if (op.isNull() || op.toString().empty()) {
        return Variant(static_cast<Int>(result));
    }

    String op_str = op.toString();
    if (zend_string_equals_literal(op_str.str(), "<") || zend_string_equals_literal(op_str.str(), "lt")) {
        return Variant(result == -1);
    }
    if (zend_string_equals_literal(op_str.str(), "<=") || zend_string_equals_literal(op_str.str(), "le")) {
        return Variant(result != 1);
    }
    if (zend_string_equals_literal(op_str.str(), ">") || zend_string_equals_literal(op_str.str(), "gt")) {
        return Variant(result == 1);
    }
    if (zend_string_equals_literal(op_str.str(), ">=") || zend_string_equals_literal(op_str.str(), "ge")) {
        return Variant(result != -1);
    }
    if (zend_string_equals_literal(op_str.str(), "==") || zend_string_equals_literal(op_str.str(), "=") ||
        zend_string_equals_literal(op_str.str(), "eq")) {
        return Variant(result == 0);
    }
    if (zend_string_equals_literal(op_str.str(), "!=") || zend_string_equals_literal(op_str.str(), "<>") ||
        zend_string_equals_literal(op_str.str(), "ne")) {
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
#ifdef PHPX_NANO
    return php_nano_unique_id(prefix.str(), more_entropy);
#else
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto sec_dur = std::chrono::duration_cast<std::chrono::seconds>(duration);
    auto usec_dur = std::chrono::duration_cast<std::chrono::microseconds>(duration - sec_dur);
    zend_ulong sec = static_cast<zend_ulong>(sec_dur.count());
    int usec = static_cast<int>(usec_dur.count() % 0x100000);

    if (more_entropy) {
        return zend_strpprintf(0,
                               "%s%08" PRIx64 "%05x%.8F",
                               prefix.length() > 0 ? prefix.data() : "",
                               static_cast<std::uint64_t>(sec),
                               usec,
                               php_combined_lcg() * 10);
    }

    return zend_strpprintf(
        0, "%s%08" PRIx64 "%05x", prefix.length() > 0 ? prefix.data() : "", static_cast<std::uint64_t>(sec), usec);
#endif
}

String uniqid(const String &prefix, bool more_entropy) {
    zend_string *s = _uniqid_hash(prefix, more_entropy);
    return String(s, Ctor::Move);
}

// ========================
// parse_str
// ========================

#ifndef PHPX_NANO
Array parse_str(const String &str) {
    Array result;
    auto res = estrndup(str.data(), str.length());
    sapi_module.treat_data(PARSE_STRING, res, result.ptr());
    return result;
}

void parse_str(const String &str, Array &result) {
    result = Array();
    auto res = estrndup(str.data(), str.length());
    sapi_module.treat_data(PARSE_STRING, res, result.ptr());
}
#endif

// ========================
// shell_exec
// ========================

#ifndef PHPX_NANO
Variant shell_exec(const String &command) {
    if (command.length() == 0) {
        zend_argument_value_error(1, "cannot be empty");
        return Variant(nullptr);
    }

#if defined(__wasi__) || defined(PHPX_IOS) || defined(PHPX_ANDROID)
    php::throwException(zend_ce_error, "shell_exec() is not supported on this platform");
    return Variant(nullptr);
#else
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
#endif
}
#endif

}  // namespace php::fn
