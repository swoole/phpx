/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP string functions             |
  +----------------------------------------------------------------------+
  | Implementation of complex string functions                            |
  +----------------------------------------------------------------------+
*/

#include "std/string.h"
#include <vector>

extern "C" {
// php_explode_negative_limit is PHPAPI in string.c but not declared in php_string.h
PHPAPI void php_explode_negative_limit(const zend_string *delim, zend_string *str, zval *return_value, zend_long limit);
}

namespace php::fn {

// ========================
// explode
// ========================

Array explode(const String &delimiter, const String &string, Int limit) {
    if (UNEXPECTED(delimiter.empty())) {
        php::throwException(zend_ce_value_error, "explode(): Argument #1 ($separator) must not be empty");
        return Array();
    }

    Array result;

    if (string.empty()) {
        if (limit >= 0) {
            result.append(String());
        }
        return result;
    }

    if (limit > 1) {
        php_explode(delimiter.str(), string.str(), result.ptr(), limit);
    } else if (limit < 0) {
        php_explode_negative_limit(delimiter.str(), string.str(), result.ptr(), limit);
    } else {
        // limit == 0 or 1: return the whole string as a single element
        result.append(string);
    }

    return result;
}

// ========================
// implode
// ========================

String implode(const String &glue, const Array &pieces) {
    zval rv;
    ZVAL_NULL(&rv);
    php_implode(glue.str(), pieces.array(), &rv);
    return String(&rv, Ctor::Move);
}

// ========================
// strpos
// ========================

Variant strpos(const String &haystack, const String &needle, Int offset) {
    const char *found = nullptr;
    size_t haystack_len = haystack.length();
    size_t needle_len = needle.length();

    if (needle_len == 0) {
        return Variant(Int(0));
    }

    if (offset < 0) {
        offset += (Int) haystack_len;
    }
    if (offset < 0 || (size_t) offset > haystack_len) {
        php::throwException(zend_ce_value_error,
                            "strpos(): Argument #3 ($offset) must be contained in argument #1 ($haystack)");
        return Variant();
    }

    found =
        (const char *) php_memnstr(haystack.data() + offset, needle.data(), needle_len, haystack.data() + haystack_len);

    if (!found) {
        return Variant(false);
    }
    return Variant((Int) (found - haystack.data()));
}

// ========================
// stripos
// ========================

Variant stripos(const String &haystack, const String &needle, Int offset) {
    size_t haystack_len = haystack.length();
    size_t needle_len = needle.length();

    if (needle_len == 0) {
        return Variant(Int(0));
    }

    if (offset < 0) {
        offset += (Int) haystack_len;
    }
    if (offset < 0 || (size_t) offset > haystack_len) {
        php::throwException(zend_ce_value_error,
                            "stripos(): Argument #3 ($offset) must be contained in argument #1 ($haystack)");
        return Variant();
    }

    const char *found = (const char *) php_memnistr(
        haystack.data() + offset, needle.data(), needle_len, haystack.data() + haystack_len);

    if (!found) {
        return Variant(false);
    }
    return Variant((Int) (found - haystack.data()));
}

// ========================
// strrpos
// ========================

Variant strrpos(const String &haystack, const String &needle, Int offset) {
    size_t haystack_len = haystack.length();
    size_t needle_len = needle.length();

    if (needle_len == 0) {
        // Empty needle matches at the end of the string (PHP 8.x behavior)
        return Variant((Int) haystack_len);
    }

    const char *p, *e;

    if (offset >= 0) {
        if ((size_t) offset > haystack_len) {
            php::throwException(zend_ce_value_error,
                                "strrpos(): Argument #3 ($offset) must be contained in argument #1 ($haystack)");
            return Variant();
        }
        p = haystack.data() + (size_t) offset;
        e = haystack.data() + haystack_len;
    } else {
        if (offset < -ZEND_LONG_MAX || (size_t) (-offset) > haystack_len) {
            php::throwException(zend_ce_value_error,
                                "strrpos(): Argument #3 ($offset) must be contained in argument #1 ($haystack)");
            return Variant();
        }
        p = haystack.data();
        if ((size_t) (-offset) < needle_len) {
            e = haystack.data() + haystack_len;
        } else {
            e = haystack.data() + haystack_len + offset + needle_len;
        }
    }

    const char *found = (const char *) zend_memnrstr(p, needle.data(), needle_len, e);

    if (!found) {
        return Variant(false);
    }
    return Variant((Int) (found - haystack.data()));
}

// ========================
// strstr

Variant strstr(const String &haystack, const String &needle, bool before_needle) {
    size_t haystack_len = haystack.length();
    size_t needle_len = needle.length();

    if (needle_len == 0) {
        // Empty needle matches from the start (PHP 8.x behavior)
        if (before_needle) {
            return Variant(String());
        }
        return Variant(haystack);
    }

    const char *found =
        (const char *) php_memnstr(haystack.data(), needle.data(), needle_len, haystack.data() + haystack_len);

    if (!found) {
        return Variant(false);
    }

    if (before_needle) {
        size_t result_len = (size_t) (found - haystack.data());
        return Variant(String(zend_string_init(haystack.data(), result_len, 0), Ctor::Move));
    }

    size_t result_len = haystack_len - (size_t) (found - haystack.data());
    return Variant(String(zend_string_init(found, result_len, 0), Ctor::Move));
}

// ========================
// stristr
// ========================

Variant stristr(const String &haystack, const String &needle, bool before_needle) {
    size_t haystack_len = haystack.length();
    size_t needle_len = needle.length();

    if (needle_len == 0) {
        if (before_needle) {
            return Variant(String());
        }
        return Variant(haystack);
    }

    // php_stristr is PHPAPI — returns pointer to first occurrence
    const char *found =
        (const char *) php_stristr((char *) haystack.data(), (char *) needle.data(), haystack_len, needle_len);

    if (!found) {
        return Variant(false);
    }

    if (before_needle) {
        size_t result_len = (size_t) (found - haystack.data());
        return Variant(String(zend_string_init(haystack.data(), result_len, 0), Ctor::Move));
    }

    size_t result_len = haystack_len - (size_t) (found - haystack.data());
    return Variant(String(zend_string_init(found, result_len, 0), Ctor::Move));
}

// ========================
// substr
// ========================

String substr(const String &s, Int offset, const Variant &length) {
    size_t slen = s.length();

    // Handle negative offset
    if (offset < 0) {
        offset = (Int) slen + offset;
        if (offset < 0) {
            offset = 0;
        }
    }

    // If offset is beyond string length, return empty
    if ((size_t) offset >= slen) {
        return String();
    }

    size_t result_len;
    if (length.isNull()) {
        // No length specified — take rest of string
        result_len = slen - (size_t) offset;
    } else {
        Int length_int = length.toInt();
        if (length_int < 0) {
            // Negative length means omit that many characters from the end
            Int end = (Int) slen + length_int;
            if (end <= offset) {
                return String();
            }
            result_len = (size_t) (end - offset);
        } else {
            result_len = (size_t) length_int;
            if ((size_t) (offset + (Int) result_len) > slen) {
                result_len = slen - (size_t) offset;
            }
        }
    }

    return String(zend_string_init(s.data() + offset, result_len, 0), Ctor::Move);
}

// ========================
// dirname / basename
// ========================

String dirname(const String &path, int levels) {
    size_t len = path.length();
    if (len == 0) {
        return String();
    }
    char *buf = (char *) emalloc(len + 1);
    memcpy(buf, path.data(), len);
    buf[len] = '\0';
    size_t new_len = len;
    for (int i = 0; i < levels; i++) {
        new_len = php_dirname(buf, new_len);
        if (new_len == 0) {
            efree(buf);
            return String(".", 1);
        }
    }
    String result(buf, new_len);
    efree(buf);
    return result;
}

String basename(const String &path, const String &suffix) {
    const char *suf_ptr = suffix.length() > 0 ? suffix.data() : nullptr;
    size_t suf_len = suffix.length();
    zend_string *result = php_basename(path.data(), path.length(), suf_ptr, suf_len);
    if (!result) {
        return String();
    }
    return String(result, Ctor::Move);
}

}  // namespace php::fn
