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

namespace php::std {

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

Array array_merge(const Array &array);
Array array_merge(const Array &array, const Array &other);

template <typename... Rest>
inline Array array_merge(const Array &array, const Array &other, const Rest &...arrays) {
    static_assert((::std::is_same_v<Array, ::std::decay_t<Rest>> && ...),
                  "array_merge only accepts Array arguments");
    Array result = array_merge(array, other);
    ((result = array_merge(result, arrays)), ...);
    return result;
}

Array array_merge_recursive(const Array &array);
Array array_merge_recursive(const Array &array, const Array &other);

template <typename... Rest>
inline Array array_merge_recursive(const Array &array, const Array &other, const Rest &...arrays) {
    static_assert((::std::is_same_v<Array, ::std::decay_t<Rest>> && ...),
                  "array_merge_recursive only accepts Array arguments");
    Array result = array_merge_recursive(array, other);
    ((result = array_merge_recursive(result, arrays)), ...);
    return result;
}

// ========================
// Array transformation
// ========================

Array array_map(const Variant &callback, const Array &array);
Array array_filter(const Array &array, const Variant &callback = Variant(), Int mode = 0);
Variant array_reduce(const Array &array, const Variant &callback, const Variant &initial = Variant());

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
    if (value.isNull()) {
        return 0;
    }
    return 1;
}

// ========================
// Array slicing / chunking
// ========================

Array array_slice(const Array &array, Int offset, const Variant &length = Variant(), bool preserve_keys = false);
Array array_chunk(const Array &array, Int length, bool preserve_keys = false);

// ========================
// Array dedup / column
// ========================

Array array_unique(const Array &array, Int sort_flags = 2);
Array array_column(const Array &array, const Variant &column_key, const Variant &index_key = Variant());

// ========================
// Array type checks
// ========================

inline Bool array_is_list(const Array &array) {
    return zend_array_is_list(Z_ARRVAL_P(array.unwrap_ptr()));
}

// ========================
// Array in-place mutation
// ========================

Bool sort(Variant &arg, Int flags = 0);
Bool asort(Variant &arg, Int flags = 0);

// Internal flag bit used by rsort/arsort to signal descending order.
// PHP_SORT values 0-4 are exclusive (not bit flags), so we use bit 5 (16)
// to encode direction, avoiding collisions with SORT_NUMERIC=1, SORT_STRING=2,
// SORT_DESC=3, SORT_ASC=4, and SORT_FLAG_CASE=8.
constexpr int AOT_SORT_REVERSE = 16;

inline Bool rsort(Variant &arg, Int flags = 0) {
    return sort(arg, static_cast<Int>(static_cast<int>(flags) | AOT_SORT_REVERSE));
}
inline Bool arsort(Variant &arg, Int flags = 0) {
    return asort(arg, static_cast<Int>(static_cast<int>(flags) | AOT_SORT_REVERSE));
}
namespace detail {
Int array_push_impl(Variant &arg, const Variant *values, ::std::size_t value_count);
Int array_unshift_impl(Variant &arg, const Variant *values, ::std::size_t value_count);
}

inline Int array_push(Variant &arg) {
    return detail::array_push_impl(arg, nullptr, 0);
}

template <typename First, typename... Rest>
inline Int array_push(Variant &arg, const First &first, const Rest &...rest) {
    Variant values[] = {Variant(first), Variant(rest)...};
    return detail::array_push_impl(arg, values, sizeof...(Rest) + 1);
}

Variant array_pop(Variant &arg);
Variant array_shift(Variant &arg);

inline Int array_unshift(Variant &arg) {
    return detail::array_unshift_impl(arg, nullptr, 0);
}

template <typename First, typename... Rest>
inline Int array_unshift(Variant &arg, const First &first, const Rest &...rest) {
    Variant values[] = {Variant(first), Variant(rest)...};
    return detail::array_unshift_impl(arg, values, sizeof...(Rest) + 1);
}

// reset(array &$array): mixed
Variant reset(Variant &arg);

// end(array &$array): mixed
Variant end(Variant &arg);

// ksort(array &$array, int $flags = 0): true
Bool ksort(Variant &arg, Int flags = 0);

// array_reverse(array $array, bool $preserve_keys = false): array
Array array_reverse(const Array &array, bool preserve_keys = false);

// array_diff(array $array, array ...$arrays): array
Array array_diff(const Array &array, const Array &others);

template <typename... Rest>
inline Array array_diff(const Array &array, const Array &other, const Rest &...arrays) {
    static_assert((::std::is_same_v<Array, ::std::decay_t<Rest>> && ...),
                  "array_diff only accepts Array arguments");
    Array result = array_diff(array, other);
    ((result = array_diff(result, arrays)), ...);
    return result;
}

// ========================
// Array math operations
// ========================

Variant array_sum(const Array &array);
Variant array_product(const Array &array);

// ========================
// Array construction
// ========================

Array array_combine(const Array &keys, const Array &values);
Array array_fill(Int start_index, Int count, const Variant &value);
Array array_flip(const Array &array);

// ========================
// Array intersection
// ========================

Array array_intersect(const Array &array, const Array &others);

template <typename... Rest>
inline Array array_intersect(const Array &array, const Array &other, const Rest &...arrays) {
    static_assert((::std::is_same_v<Array, ::std::decay_t<Rest>> && ...),
                  "array_intersect only accepts Array arguments");
    Array result = array_intersect(array, other);
    ((result = array_intersect(result, arrays)), ...);
    return result;
}

}  // namespace php::std
