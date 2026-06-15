/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP array functions              |
  +----------------------------------------------------------------------+
  | Eliminates zend_call_function overhead by directly calling Zend APIs  |
  +----------------------------------------------------------------------+
*/

#pragma once

#include "phpx.h"

extern "C" {
#include "ext/standard/php_array.h"
}

#include <cstddef>
#include <type_traits>

namespace php::fn {

// ========================
// Array existence / search
// ========================

Bool in_array(const Variant &needle, const Array &haystack, bool strict = false);

inline Bool array_key_exists(const Variant &key, const Array &array) {
    if (key.isInt()) {
        return zend_hash_index_exists(array.array(), key.toInt());
    }
    if (key.isString()) {
        return zend_symtable_exists(array.array(), Z_STR_P(key.unwrap_ptr()));
    }
    return false;
}

Variant array_search(const Variant &needle, const Array &haystack, bool strict = false);

// ========================
// Array key/value extraction
// ========================

Array array_keys(const Array &array);
Array array_keys_filter(const Array &array, const Variant &filter_value, bool strict = false);
Array array_values(const Array &array);

// ========================
// Array first/last key
// ========================

Variant array_key_first(const Array &array);
Variant array_key_last(const Array &array);

// ========================
// Array merge operations
// ========================

Array array_merge();
Array array_merge(const Array &array);
Array array_merge(const Array &array, const Array &other);

template <typename... Rest>
inline Array array_merge(const Array &array, const Array &other, const Rest &...arrays) {
    static_assert((std::is_same_v<Array, std::decay_t<Rest>> && ...), "array_merge only accepts Array arguments");
    Array result = array_merge(array, other);
    ((result = array_merge(result, arrays)), ...);
    return result;
}

// ========================
// Array counting
// ========================

inline Int count(const Variant &value, Int mode = 0) {
    if (value.isArray()) {
        if (mode == 1) {
            return php_count_recursive(value.array());
        }
        return static_cast<Int>(zend_hash_num_elements(value.array()));
    }
    if (value.isObject()) {
        zend_object *zobj = Z_OBJ_P(value.unwrap_ptr());
        if (zobj->handlers->count_elements) {
            zend_long cnt = 1;
            if (SUCCESS == zobj->handlers->count_elements(zobj, &cnt)) {
                return static_cast<Int>(cnt);
            }
        }
        if (instanceof_function(zobj->ce, zend_ce_countable)) {
            return 1;
        }
        return 1;
    }
    php::throwException(zend_ce_type_error, "count(): Argument #1 ($value) must be of type Countable|array");
    return 0;
}

// ========================
// Array type checks
// ========================

inline Bool array_is_list(const Array &array) {
    return zend_array_is_list(Z_ARRVAL_P(array.unwrap_ptr()));
}

// ========================
// Array in-place mutation
// ========================

namespace detail {
Int array_push_impl(Variant &arg, const Variant *values, std::size_t value_count);
}  // namespace detail

inline Int array_push(Variant &arg) {
    return detail::array_push_impl(arg, nullptr, 0);
}

template <typename First, typename... Rest>
inline Int array_push(Variant &arg, const First &first, const Rest &...rest) {
    Variant values[] = {Variant(first), Variant(rest)...};
    return detail::array_push_impl(arg, values, sizeof...(Rest) + 1);
}

// ========================
// Array construction
// ========================

Array array_fill(Int start_index, Int count, const Variant &value);

}  // namespace php::fn
