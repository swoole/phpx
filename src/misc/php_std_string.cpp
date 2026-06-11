/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP string functions             |
  +----------------------------------------------------------------------+
  | Implementation of complex string functions                            |
  +----------------------------------------------------------------------+
*/

#include "php_std_string.h"
#include <vector>

extern "C" {
// php_explode_negative_limit is PHPAPI in string.c but not declared in php_string.h
PHPAPI void php_explode_negative_limit(const zend_string *delim, zend_string *str, zval *return_value, zend_long limit);
}

namespace php::std {

// ========================
// explode
// ========================

Array explode(const String &delimiter, const String &string, Int limit) {
    if (UNEXPECTED(delimiter.empty())) {
        php::throwException(zend_ce_value_error,
            "explode(): Argument #1 ($separator) cannot be empty");
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
// str_replace (string-only fast path plus array support)
// ========================

static String _str_replace_string(const String &search, const String &replace, const String &subject) {
    if (search.empty()) {
        return subject;
    }
    zend_string *result = php_str_to_str(
        subject.data(), subject.length(),
        search.data(), search.length(),
        replace.data(), replace.length());
    return String(result, Ctor::Move);
}

Variant str_replace(const Variant &search, const Variant &replace, const Variant &subject) {
    // Fast path: all three are strings
    if (search.isString() && replace.isString() && subject.isString()) {
        return Variant(_str_replace_string(search.toString(), replace.toString(), subject.toString()));
    }

    // Mixed types — handle with array iteration
    bool search_is_array = search.isArray();
    bool replace_is_array = replace.isArray();
    bool subject_is_array = subject.isArray();

    if (subject_is_array) {
        Array subject_arr = php::toArray(subject);
        Array result(subject_arr.count());

        if (search_is_array) {
            Array search_arr = php::toArray(search);
            Array replace_arr;
            if (replace_is_array) {
                replace_arr = php::toArray(replace);
            }

            // Build search/replace arrays
            ::std::vector<String> search_vec;
            ::std::vector<String> replace_vec;
            size_t replace_count = replace_is_array ? replace_arr.count() : 0;
            size_t idx = 0;
            for (const auto &skv : search_arr) {
                if (skv.value.isString()) {
                    search_vec.push_back(skv.value.toString());
                } else {
                    search_vec.push_back(String(skv.value));
                }
                if (replace_is_array && idx < replace_count) {
                    Variant rv = replace_arr.get((zend_ulong)idx);
                    if (rv.isString()) {
                        replace_vec.push_back(rv.toString());
                    } else {
                        replace_vec.push_back(String(rv));
                    }
                } else {
                    replace_vec.push_back(String());
                }
                idx++;
            }

            for (const auto &kv : subject_arr) {
                if (kv.value.isString()) {
                    String val = kv.value.toString();
                    for (size_t i = 0; i < search_vec.size(); i++) {
                        val = _str_replace_string(search_vec[i], replace_vec[i], val);
                    }
                    result.set(kv.key, val);
                } else {
                    result.set(kv.key, kv.value);
                }
            }
        } else {
            // Single search string, array subject
            String search_str = search.isString() ? search.toString() : String(search);
            String replace_str = replace.isString() ? replace.toString() : String(replace);

            for (const auto &kv : subject_arr) {
                if (kv.value.isString()) {
                    result.set(kv.key, _str_replace_string(search_str, replace_str, kv.value.toString()));
                } else {
                    result.set(kv.key, kv.value);
                }
            }
        }

        return Variant(result);
    }

    // subject is string
    String subject_str = subject.isString() ? subject.toString() : String(subject);
    String replace_str = replace.isString() ? replace.toString() : String(replace);

    if (search_is_array) {
        Array search_arr = php::toArray(search);
        for (const auto &skv : search_arr) {
            String search_str = skv.value.isString() ? skv.value.toString() : String(skv.value);
            subject_str = _str_replace_string(search_str, replace_str, subject_str);
        }
        return Variant(subject_str);
    }

    // Fallback: convert search to string
    String search_str = search.isString() ? search.toString() : String(search);
    return Variant(_str_replace_string(search_str, replace_str, subject_str));
}

// ========================
// strpos
// ========================

Variant strpos(const String &haystack, const String &needle, Int offset) {
    const char *found = nullptr;
    size_t haystack_len = haystack.length();
    size_t needle_len = needle.length();

    if (needle_len == 0) {
        php::throwException(zend_ce_value_error,
            "strpos(): Argument #2 ($needle) must not be empty");
        return Variant();
    }

    if (offset < 0) {
        offset += (Int)haystack_len;
    }
    if (offset < 0 || (size_t)offset > haystack_len) {
        php::throwException(zend_ce_value_error,
            "strpos(): Argument #3 ($offset) must be contained in argument #1 ($haystack)");
        return Variant();
    }

    found = (const char *)php_memnstr(
        haystack.data() + offset,
        needle.data(), needle_len,
        haystack.data() + haystack_len);

    if (!found) {
        return Variant(false);
    }
    return Variant((Int)(found - haystack.data()));
}

// ========================
// stripos
// ========================

Variant stripos(const String &haystack, const String &needle, Int offset) {
    size_t haystack_len = haystack.length();
    size_t needle_len = needle.length();

    if (needle_len == 0) {
        php::throwException(zend_ce_value_error,
            "stripos(): Argument #2 ($needle) must not be empty");
        return Variant();
    }

    if (offset < 0) {
        offset += (Int)haystack_len;
    }
    if (offset < 0 || (size_t)offset > haystack_len) {
        php::throwException(zend_ce_value_error,
            "stripos(): Argument #3 ($offset) must be contained in argument #1 ($haystack)");
        return Variant();
    }

    const char *found = (const char *)php_memnistr(
        haystack.data() + offset,
        needle.data(), needle_len,
        haystack.data() + haystack_len);

    if (!found) {
        return Variant(false);
    }
    return Variant((Int)(found - haystack.data()));
}

// ========================
// strrpos
// ========================

Variant strrpos(const String &haystack, const String &needle, Int offset) {
    size_t haystack_len = haystack.length();
    size_t needle_len = needle.length();

    if (needle_len == 0) {
        php::throwException(zend_ce_value_error,
            "strrpos(): Argument #2 ($needle) must not be empty");
        return Variant();
    }

    const char *p, *e;

    if (offset >= 0) {
        if ((size_t)offset > haystack_len) {
            php::throwException(zend_ce_value_error,
                "strrpos(): Argument #3 ($offset) must be contained in argument #1 ($haystack)");
            return Variant();
        }
        p = haystack.data() + (size_t)offset;
        e = haystack.data() + haystack_len;
    } else {
        if (offset < -ZEND_LONG_MAX || (size_t)(-offset) > haystack_len) {
            php::throwException(zend_ce_value_error,
                "strrpos(): Argument #3 ($offset) must be contained in argument #1 ($haystack)");
            return Variant();
        }
        p = haystack.data();
        if ((size_t)(-offset) < needle_len) {
            e = haystack.data() + haystack_len;
        } else {
            e = haystack.data() + haystack_len + offset + needle_len;
        }
    }

    const char *found = (const char *)zend_memnrstr(p, needle.data(), needle_len, e);

    if (!found) {
        return Variant(false);
    }
    return Variant((Int)(found - haystack.data()));
}

// ========================
// strripos
// ========================

Variant strripos(const String &haystack, const String &needle, Int offset) {
    size_t haystack_len = haystack.length();
    size_t needle_len = needle.length();

    if (needle_len == 0) {
        php::throwException(zend_ce_value_error,
            "strripos(): Argument #2 ($needle) must not be empty");
        return Variant();
    }

    // Single character optimization (avoids tolower alloc)
    if (needle_len == 1) {
        char needle_lowered = (char)zend_tolower_ascii((unsigned char)*needle.data());
        const char *p, *e;

        if (offset >= 0) {
            if ((size_t)offset > haystack_len) {
                php::throwException(zend_ce_value_error,
                    "strripos(): Argument #3 ($offset) must be contained in argument #1 ($haystack)");
                return Variant();
            }
            p = haystack.data() + (size_t)offset;
            e = haystack.data() + haystack_len - 1;
        } else {
            if (offset < -ZEND_LONG_MAX || (size_t)(-offset) > haystack_len) {
                php::throwException(zend_ce_value_error,
                    "strripos(): Argument #3 ($offset) must be contained in argument #1 ($haystack)");
                return Variant();
            }
            p = haystack.data();
            e = haystack.data() + haystack_len + (size_t)offset;
        }

        while (e >= p) {
            if (zend_tolower_ascii((unsigned char)*e) == (unsigned char)needle_lowered) {
                return Variant((Int)(e - haystack.data()));
            }
            e--;
        }
        return Variant(false);
    }

    // Multi-character: lowercase copies, then reverse search
    zend_string *haystack_lc = zend_string_tolower(haystack.str());
    zend_string *needle_lc = zend_string_tolower(needle.str());

    const char *p, *e;

    if (offset >= 0) {
        if ((size_t)offset > haystack_len) {
            zend_string_release_ex(haystack_lc, 0);
            zend_string_release_ex(needle_lc, 0);
            php::throwException(zend_ce_value_error,
                "strripos(): Argument #3 ($offset) must be contained in argument #1 ($haystack)");
            return Variant();
        }
        p = ZSTR_VAL(haystack_lc) + offset;
        e = ZSTR_VAL(haystack_lc) + haystack_len;
    } else {
        if (offset < -ZEND_LONG_MAX || (size_t)(-offset) > haystack_len) {
            zend_string_release_ex(haystack_lc, 0);
            zend_string_release_ex(needle_lc, 0);
            php::throwException(zend_ce_value_error,
                "strripos(): Argument #3 ($offset) must be contained in argument #1 ($haystack)");
            return Variant();
        }
        p = ZSTR_VAL(haystack_lc);
        if ((size_t)(-offset) < needle_len) {
            e = ZSTR_VAL(haystack_lc) + haystack_len;
        } else {
            e = ZSTR_VAL(haystack_lc) + haystack_len + offset + needle_len;
        }
    }

    const char *found = (const char *)zend_memnrstr(
        p, ZSTR_VAL(needle_lc), needle_len, e);

    Int pos = found ? (Int)(found - ZSTR_VAL(haystack_lc)) : -1;

    zend_string_release_ex(haystack_lc, 0);
    zend_string_release_ex(needle_lc, 0);

    if (pos < 0) {
        return Variant(false);
    }
    return Variant(pos);
}

// ========================
// strstr
// ========================

Variant strstr(const String &haystack, const String &needle, bool before_needle) {
    size_t haystack_len = haystack.length();
    size_t needle_len = needle.length();

    if (needle_len == 0) {
        php::throwException(zend_ce_value_error,
            "strstr(): Argument #2 ($needle) must not be empty");
        return Variant();
    }

    const char *found = (const char *)php_memnstr(
        haystack.data(), needle.data(), needle_len,
        haystack.data() + haystack_len);

    if (!found) {
        return Variant(false);
    }

    if (before_needle) {
        size_t result_len = (size_t)(found - haystack.data());
        return Variant(String(zend_string_init(haystack.data(), result_len, 0), Ctor::Move));
    }

    size_t result_len = haystack_len - (size_t)(found - haystack.data());
    return Variant(String(zend_string_init(found, result_len, 0), Ctor::Move));
}

// ========================
// stristr
// ========================

Variant stristr(const String &haystack, const String &needle, bool before_needle) {
    size_t haystack_len = haystack.length();
    size_t needle_len = needle.length();

    if (needle_len == 0) {
        php::throwException(zend_ce_value_error,
            "stristr(): Argument #2 ($needle) must not be empty");
        return Variant();
    }

    // php_stristr is PHPAPI — returns pointer to first occurrence
    const char *found = (const char *)php_stristr(
        haystack.data(), needle.data(), haystack_len, needle_len);

    if (!found) {
        return Variant(false);
    }

    if (before_needle) {
        size_t result_len = (size_t)(found - haystack.data());
        return Variant(String(zend_string_init(haystack.data(), result_len, 0), Ctor::Move));
    }

    size_t result_len = haystack_len - (size_t)(found - haystack.data());
    return Variant(String(zend_string_init(found, result_len, 0), Ctor::Move));
}

// ========================
// substr
// ========================

String substr(const String &s, Int offset, Int length) {
    size_t slen = s.length();

    // Handle negative offset
    if (offset < 0) {
        offset = (Int)slen + offset;
        if (offset < 0) {
            offset = 0;
        }
    }

    // If offset is beyond string length, return empty
    if ((size_t)offset >= slen) {
        return String();
    }

    size_t result_len;
    if (length == ZEND_LONG_MAX) {
        // No length specified — take rest of string
        result_len = slen - (size_t)offset;
    } else if (length < 0) {
        // Negative length means omit that many characters from the end
        Int end = (Int)slen + length;
        if (end <= offset) {
            return String();
        }
        result_len = (size_t)(end - offset);
    } else {
        result_len = (size_t)length;
        if ((size_t)(offset + (Int)result_len) > slen) {
            result_len = slen - (size_t)offset;
        }
    }

    return String(zend_string_init(s.data() + offset, result_len, 0), Ctor::Move);
}

// ========================
// str_pad
// ========================

String str_pad(const String &s, Int length, const String &pad, int pad_type) {
    size_t slen = s.length();

    if (length <= 0 || (size_t)length <= slen) {
        return s;
    }

    size_t pad_len = pad.length();
    if (pad_len == 0) {
        return s;
    }

    size_t result_len = (size_t)length;
    size_t pad_size = result_len - slen;

    zend_string *result = zend_string_alloc(result_len, 0);
    char *p = ZSTR_VAL(result);

    switch (pad_type) {
    case PHP_STR_PAD_LEFT:
        // Pad on the left
        for (size_t i = 0; i < pad_size; i++) {
            p[i] = pad.data()[i % pad_len];
        }
        memcpy(p + pad_size, s.data(), slen);
        break;

    case PHP_STR_PAD_BOTH:
        {
            size_t left = pad_size / 2;
            size_t right = pad_size - left;
            for (size_t i = 0; i < left; i++) {
                p[i] = pad.data()[i % pad_len];
            }
            memcpy(p + left, s.data(), slen);
            for (size_t i = 0; i < right; i++) {
                p[left + slen + i] = pad.data()[i % pad_len];
            }
        }
        break;

    case PHP_STR_PAD_RIGHT:
    default:
        memcpy(p, s.data(), slen);
        for (size_t i = 0; i < pad_size; i++) {
            p[slen + i] = pad.data()[i % pad_len];
        }
        break;
    }

    ZSTR_VAL(result)[result_len] = '\0';
    return String(result, Ctor::Move);
}

// ========================
// dirname / basename
// ========================

String dirname(const String &path, int levels) {
    size_t len = path.length();
    if (len == 0) {
        return String();
    }
    char *buf = (char *)emalloc(len + 1);
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

// ========================
// strtr
// ========================

String strtr(const String &str, const String &from, const String &to) {
    size_t len = str.length();
    if (len == 0) {
        return String();
    }
    char *buf = (char *)emalloc(len + 1);
    memcpy(buf, str.data(), len);
    buf[len] = '\0';
    size_t trlen = from.length() < to.length() ? from.length() : to.length();
    php_strtr(buf, len, from.data(), to.data(), trlen);
    String result(buf, len);
    efree(buf);
    return result;
}

}  // namespace php::std
