/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP ctype functions              |
  +----------------------------------------------------------------------+
  | These wrappers deliberately do not depend on ext/ctype.               |
  +----------------------------------------------------------------------+
*/

#pragma once

#include <cctype>

#include "phpx.h"

namespace php::fn {

namespace detail {

using CtypePredicate = int (*)(int);

inline Bool ctype(const Variant &text, CtypePredicate predicate, bool allow_digits, bool allow_minus) {
    const zval *value = text.unwrap_ptr();
    if (Z_TYPE_P(value) == IS_STRING) {
        const auto *cursor = reinterpret_cast<const unsigned char *>(Z_STRVAL_P(value));
        const auto *end = cursor + Z_STRLEN_P(value);
        if (cursor == end) {
            return false;
        }
        while (cursor < end) {
            if (!predicate(*cursor++)) {
                return false;
            }
        }
        return true;
    }

    // Match ext/ctype's legacy integer interpretation. PHP emits an
    // E_DEPRECATED notice for non-string arguments; TypePHP keeps only the
    // classification result so the direct path remains independent of the
    // extension and its registered function handlers.
    if (Z_TYPE_P(value) != IS_LONG) {
        return false;
    }
    const Int number = Z_LVAL_P(value);
    if (number >= 0 && number <= 255) {
        return predicate(static_cast<int>(number)) != 0;
    }
    if (number >= -128 && number < 0) {
        return predicate(static_cast<int>(number + 256)) != 0;
    }
    return number >= 0 ? allow_digits : allow_minus;
}

}  // namespace detail

inline Bool ctype_alnum(const Variant &text) {
    return detail::ctype(text, std::isalnum, true, false);
}

inline Bool ctype_alpha(const Variant &text) {
    return detail::ctype(text, std::isalpha, false, false);
}

inline Bool ctype_cntrl(const Variant &text) {
    return detail::ctype(text, std::iscntrl, false, false);
}

inline Bool ctype_digit(const Variant &text) {
    return detail::ctype(text, std::isdigit, true, false);
}

inline Bool ctype_lower(const Variant &text) {
    return detail::ctype(text, std::islower, false, false);
}

inline Bool ctype_graph(const Variant &text) {
    return detail::ctype(text, std::isgraph, true, true);
}

inline Bool ctype_print(const Variant &text) {
    return detail::ctype(text, std::isprint, true, true);
}

inline Bool ctype_punct(const Variant &text) {
    return detail::ctype(text, std::ispunct, false, false);
}

inline Bool ctype_space(const Variant &text) {
    return detail::ctype(text, std::isspace, false, false);
}

inline Bool ctype_upper(const Variant &text) {
    return detail::ctype(text, std::isupper, false, false);
}

inline Bool ctype_xdigit(const Variant &text) {
    return detail::ctype(text, std::isxdigit, true, false);
}

}  // namespace php::fn
