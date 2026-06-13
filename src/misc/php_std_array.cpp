/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP array functions              |
  +----------------------------------------------------------------------+
  | Implementation of complex array functions                             |
  +----------------------------------------------------------------------+
*/

#include "php_std_array.h"

namespace php::std {

// ========================
// Internal comparison helpers
// ========================

/**
 * Search array for a value. Returns true/false or the key depending on behavior.
 * behavior: 0 = return bool (in_array), 1 = return key (array_search)
 */
static Variant _search_array(const Variant &needle, zend_array *ht, bool strict, int behavior) {
    zval *entry;
    zend_ulong num_idx;
    zend_string *str_idx;

    if (strict) {
        ZEND_HASH_FOREACH_KEY_VAL(ht, num_idx, str_idx, entry) {
            ZVAL_DEREF(entry);
            if (fast_is_identical_function(NO_CONST_V(needle), entry)) {
                if (behavior == 0) {
                    return Variant(true);
                } else {
                    if (str_idx) {
                        return Variant(str_idx);
                    } else {
                        return Variant(static_cast<zend_long>(num_idx));
                    }
                }
            }
        }
        ZEND_HASH_FOREACH_END();
    } else {
        ZEND_HASH_FOREACH_KEY_VAL(ht, num_idx, str_idx, entry) {
            ZVAL_DEREF(entry);
            if (fast_equal_check_function(NO_CONST_V(needle), entry)) {
                if (behavior == 0) {
                    return Variant(true);
                } else {
                    if (str_idx) {
                        return Variant(str_idx);
                    } else {
                        return Variant(static_cast<zend_long>(num_idx));
                    }
                }
            }
        }
        ZEND_HASH_FOREACH_END();
    }

    return Variant(false);
}

// ========================
// 1. in_array
// ========================

Bool in_array(const Variant &needle, const Array &haystack, bool strict) {
    Variant result = _search_array(needle, haystack.array(), strict, 0);
    return result.toBool();
}

// ========================
// 3. array_keys (without filter)
// ========================

Array array_keys(const Array &array) {
    zend_array *arrval = array.array();
    zend_ulong elem_count = zend_hash_num_elements(arrval);

    if (elem_count == 0) {
        return Array();
    }

    Array result(static_cast<size_t>(elem_count));

    if (HT_IS_PACKED(arrval) && HT_IS_WITHOUT_HOLES(arrval)) {
        zend_hash_real_init_packed(result.array());
        ZEND_HASH_FILL_PACKED(result.array()) {
            for (zend_ulong i = 0; i < elem_count; i++) {
                ZEND_HASH_FILL_SET_LONG(static_cast<zend_long>(i));
                ZEND_HASH_FILL_NEXT();
            }
        }
        ZEND_HASH_FILL_END();
    } else {
        zend_hash_real_init_mixed(result.array());
        zend_ulong num_idx;
        zend_string *str_idx;
        zval *entry;
        ZEND_HASH_FOREACH_KEY_VAL(arrval, num_idx, str_idx, entry) {
            if (str_idx) {
                zval zv;
                ZVAL_STR_COPY(&zv, str_idx);
                zend_hash_next_index_insert_new(result.array(), &zv);
            } else {
                zval zv;
                ZVAL_LONG(&zv, static_cast<zend_long>(num_idx));
                zend_hash_next_index_insert_new(result.array(), &zv);
            }
        }
        ZEND_HASH_FOREACH_END();
    }

    return result;
}

// ========================
// 3b. array_keys with filter_value
// ========================

Array array_keys_filter(const Array &array, const Variant &filter_value, bool strict) {
    zend_array *arrval = array.array();
    zend_ulong elem_count = zend_hash_num_elements(arrval);

    if (elem_count == 0) {
        return Array();
    }

    Array result;
    zval *entry;
    zend_ulong num_idx;
    zend_string *str_idx;

    if (strict) {
        ZEND_HASH_FOREACH_KEY_VAL(arrval, num_idx, str_idx, entry) {
            ZVAL_DEREF(entry);
            if (fast_is_identical_function(NO_CONST_V(filter_value), entry)) {
                if (str_idx) {
                    zval zv;
                    ZVAL_STR_COPY(&zv, str_idx);
                    zend_hash_next_index_insert_new(result.array(), &zv);
                } else {
                    zval zv;
                    ZVAL_LONG(&zv, static_cast<zend_long>(num_idx));
                    zend_hash_next_index_insert_new(result.array(), &zv);
                }
            }
        }
        ZEND_HASH_FOREACH_END();
    } else {
        ZEND_HASH_FOREACH_KEY_VAL(arrval, num_idx, str_idx, entry) {
            if (fast_equal_check_function(NO_CONST_V(filter_value), entry)) {
                if (str_idx) {
                    zval zv;
                    ZVAL_STR_COPY(&zv, str_idx);
                    zend_hash_next_index_insert_new(result.array(), &zv);
                } else {
                    zval zv;
                    ZVAL_LONG(&zv, static_cast<zend_long>(num_idx));
                    zend_hash_next_index_insert_new(result.array(), &zv);
                }
            }
        }
        ZEND_HASH_FOREACH_END();
    }

    return result;
}

// ========================
// 4. array_values
// ========================

Array array_values(const Array &array) {
    zend_array *arrval = array.array();
    zend_long arrlen = static_cast<zend_long>(zend_hash_num_elements(arrval));

    if (!arrlen) {
        return Array();
    }

    // Return vector-like packed arrays as-is (already indexed 0..n-1)
    if (HT_IS_PACKED(arrval) && HT_IS_WITHOUT_HOLES(arrval) &&
        arrval->nNextFreeElement == static_cast<uint32_t>(arrlen)) {
        return Array(array);
    }

    // Convert to list (re-indexed) via zend internal API
    zend_array *new_ht = zend_array_to_list(arrval);
    Array result;
    zend_array_destroy(result.array());  // free empty init array
    ZVAL_ARR(result.ptr(), new_ht);      // take ownership of new_ht
    return result;
}

// ========================
// 5. array_merge
// ========================

Array array_merge() {
    return Array();
}

Array array_merge(const Array &array) {
    return Array(array);
}

Array array_merge(const Array &array, const Array &other) {
    Array result(array);
    SEPARATE_ARRAY(result.ptr());
    php_array_merge(result.array(), other.array());
    return result;
}

// ========================
// 16. array_push (in-place)
// ========================

Int detail::array_push_impl(Variant &arg, const Variant *values, ::std::size_t value_count) {
    zval *zv = arg.unwrap_ptr();
    if (!zval_is_array(zv)) {
        php::throwException(zend_ce_type_error, "array_push(): Argument #1 ($array) must be of type array");
        return 0;
    }
    SEPARATE_ARRAY(zv);

    for (::std::size_t i = 0; i < value_count; i++) {
        const Variant &val = values[i];
        zval *v = NO_CONST_V(val);
        Z_TRY_ADDREF_P(v);
        if (zend_hash_next_index_insert(Z_ARRVAL_P(zv), v) == nullptr) {
            Z_TRY_DELREF_P(v);
            php::throwException(zend_ce_error,
                                "Cannot add element to the array as the next element is already occupied");
            return static_cast<Int>(zend_hash_num_elements(Z_ARRVAL_P(zv)));
        }
    }

    return static_cast<Int>(zend_hash_num_elements(Z_ARRVAL_P(zv)));
}

// ========================
// 20. array_search
// ========================

Variant array_search(const Variant &needle, const Array &haystack, bool strict) {
    return _search_array(needle, haystack.array(), strict, 1);
}

// ========================
// 21. reset
// ========================

Variant reset(const Variant &arg) {
    zval *zv = NO_CONST_V(arg);
    if (!zval_is_array(zv)) {
        php::throwException(zend_ce_type_error, "reset(): Argument #1 ($array) must be of type array");
        return Variant(false);
    }
    zend_array *ht = Z_ARRVAL_P(zv);
    zend_hash_internal_pointer_reset(ht);
    zval *entry = zend_hash_get_current_data(ht);
    if (entry) {
        ZVAL_DEREF(entry);
        Variant result;
        ZVAL_COPY(result.unwrap_ptr(), entry);
        return result;
    }
    return Variant(false);
}

// ========================
// 22. end
// ========================

Variant end(const Variant &arg) {
    zval *zv = NO_CONST_V(arg);
    if (!zval_is_array(zv)) {
        php::throwException(zend_ce_type_error, "end(): Argument #1 ($array) must be of type array");
        return Variant(false);
    }
    zend_array *ht = Z_ARRVAL_P(zv);
    zend_hash_internal_pointer_end(ht);
    zval *entry = zend_hash_get_current_data(ht);
    if (entry) {
        ZVAL_DEREF(entry);
        Variant result;
        ZVAL_COPY(result.unwrap_ptr(), entry);
        return result;
    }
    return Variant(false);
}

// ========================
// array_key_first
// ========================

Variant array_key_first(const Array &array) {
    HashTable *ht = array.array();
    zend_ulong num_idx;
    zend_string *str_idx;

    ZEND_HASH_FOREACH_KEY(ht, num_idx, str_idx) {
        if (str_idx) {
            return Variant(String(str_idx));
        }
        return Variant(static_cast<Int>(num_idx));
    }
    ZEND_HASH_FOREACH_END();

    return Variant(nullptr);
}

// ========================
// array_key_last
// ========================

Variant array_key_last(const Array &array) {
    HashTable *ht = array.array();
    if (zend_hash_num_elements(ht) == 0) {
        return Variant(nullptr);
    }

    zend_ulong last_num = 0;
    zend_string *last_str = nullptr;
    zend_ulong num_idx;
    zend_string *str_idx;

    ZEND_HASH_FOREACH_KEY(ht, num_idx, str_idx) {
        last_num = num_idx;
        last_str = str_idx;
    }
    ZEND_HASH_FOREACH_END();

    if (last_str) {
        return Variant(String(last_str));
    }
    return Variant(static_cast<Int>(last_num));
}

// ========================
// array_fill
// ========================

Array array_fill(Int start_index, Int count, const Variant &value) {
    if (count < 0) {
        php::throwException(zend_ce_value_error,
                            "array_fill(): Argument #2 ($count) must be greater than or equal to 0");
        return Array();
    }

    if (count == 0) {
        return Array();
    }

    zend_array *dest = zend_new_array(static_cast<uint32_t>(count));
    zval val_copy;

    for (Int i = 0; i < count; i++) {
        ZVAL_COPY(&val_copy, value.unwrap_ptr());
        zend_hash_index_update(dest, start_index + i, &val_copy);
    }

    Array result;
    zend_array_destroy(result.array());
    ZVAL_ARR(result.ptr(), dest);
    return result;
}

}  // namespace php::std
