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
    auto *value = key.unwrap_ptr();
    switch (Z_TYPE_P(value)) {
    case IS_LONG:
        return zend_hash_index_exists(array.array(), Z_LVAL_P(value));
    case IS_STRING:
        return zend_symtable_exists(array.array(), Z_STR_P(value));
    case IS_FALSE:
        return zend_hash_index_exists(array.array(), 0);
    case IS_TRUE:
        return zend_hash_index_exists(array.array(), 1);
    default:
        break;
    }

    // Diagnostics may invoke user handlers that replace either caller argument.
    // Retain value snapshots just as PHP's by-value function call does.
    Variant stable_key(key);
    Array stable_array(array.unwrap_ptr());
    value = stable_key.unwrap_ptr();
    switch (Z_TYPE_P(value)) {
    case IS_NULL:
#if PHP_VERSION_ID >= 80500
        zend_error(E_DEPRECATED,
                   "Using null as the key parameter for array_key_exists() is deprecated, use an empty string instead");
        throwErrorIfOccurred();
#endif
        return zend_hash_exists(stable_array.array(), ZSTR_EMPTY_ALLOC());
    case IS_DOUBLE: {
        zend_long index = zend_dval_to_lval_safe(Z_DVAL_P(value));
        throwErrorIfOccurred();
        return zend_hash_index_exists(stable_array.array(), index);
    }
    case IS_RESOURCE:
        zend_use_resource_as_offset(value);
        throwErrorIfOccurred();
        return zend_hash_index_exists(stable_array.array(), Z_RES_HANDLE_P(value));
    default:
        throwExceptionEx(zend_ce_type_error, 0, "array_key_exists(): Argument #1 ($key) must be a valid array offset type");
        return false;
    }
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
    // The two-array overload's empty-input shortcut must not apply to a larger call.
    Array result = array_merge(array);
    SEPARATE_ARRAY(result.ptr());
    php_array_merge(result.array(), other.array());
    (php_array_merge(result.array(), arrays.array()), ...);
    return result;
}

// ========================
// Array counting
// ========================

Int count(const Variant &value, Int mode = 0);

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
