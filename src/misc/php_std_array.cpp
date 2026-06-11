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
        } ZEND_HASH_FOREACH_END();
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
        } ZEND_HASH_FOREACH_END();
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
        } ZEND_HASH_FILL_END();
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
        } ZEND_HASH_FOREACH_END();
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
        } ZEND_HASH_FOREACH_END();
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
        } ZEND_HASH_FOREACH_END();
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
    ZVAL_ARR(result.ptr(), new_ht);       // take ownership of new_ht
    return result;
}

// ========================
// 5. array_merge
// ========================

Array array_merge(::std::initializer_list<Array> arrays) {
    if (arrays.size() == 0) {
        return Array();
    }

    Array result;
    bool first = true;

    for (const auto &arr : arrays) {
        if (first) {
            result = arr;
            first = false;
        } else {
            SEPARATE_ARRAY(result.ptr());
            php_array_merge(result.array(), arr.array());
        }
    }

    return result;
}

// ========================
// 6. array_merge_recursive
// ========================

Array array_merge_recursive(::std::initializer_list<Array> arrays) {
    if (arrays.size() == 0) {
        return Array();
    }

    Array result;
    bool first = true;

    for (const auto &arr : arrays) {
        if (first) {
            result = arr;
            first = false;
        } else {
            SEPARATE_ARRAY(result.ptr());
            php_array_merge_recursive(result.array(), arr.array());
        }
    }

    return result;
}

// ========================
// 7. array_map
// ========================

Array array_map(const Variant &callback, const Array &array) {
    zend_array *input = array.array();
    zend_ulong maxlen = zend_hash_num_elements(input);

    // Null callback: return array as-is
    if (callback.isNull() || (callback.isString() && callback.toString().length() == 0)) {
        return Array(array);
    }

    if (maxlen == 0) {
        return Array();
    }

    if (HT_IS_PACKED(input)) {
        Array result(static_cast<size_t>(input->nNumUsed));
        zend_hash_real_init_packed(result.array());

        zval cb_result;
        ZEND_HASH_FILL_PACKED(result.array()) {
            for (zval *cur = input->arPacked,
                      *end = input->arPacked + input->nNumUsed;
                 cur != end; cur++) {
                if (Z_ISUNDEF_P(cur)) {
                    ZVAL_UNDEF(&cb_result);
                    ZEND_HASH_FILL_ADD(&cb_result);
                    continue;
                }
                // Invoke callback
                Variant ret = const_cast<Variant &>(callback)({Variant(cur, Ctor::CopyRef)});
                ZVAL_COPY_VALUE(&cb_result, NO_CONST_V(ret));
                ZEND_HASH_FILL_ADD(&cb_result);
            }
        } ZEND_HASH_FILL_END();
        return result;
    } else {
        Array result(static_cast<size_t>(maxlen));
        zend_hash_real_init_mixed(result.array());

        zend_ulong num_key;
        zend_string *str_key;
        zval *val;

        ZEND_HASH_MAP_FOREACH_KEY_VAL(input, num_key, str_key, val) {
            Variant ret = const_cast<Variant &>(callback)({Variant(val, Ctor::CopyRef)});
            zval *cb_result = NO_CONST_V(ret);
            if (str_key) {
                _zend_hash_append(result.array(), str_key, cb_result);
            } else {
                zend_hash_index_add_new(result.array(), num_key, cb_result);
            }
        } ZEND_HASH_FOREACH_END();
        return result;
    }
}

// ========================
// 8. array_filter
// ========================

Array array_filter(const Array &array, const Variant &callback, Int mode) {
    zend_array *input = array.array();
    zend_ulong count = zend_hash_num_elements(input);

    if (count == 0) {
        return Array();
    }

    Array result;
    bool have_callback = !(callback.isNull() || (callback.isString() && callback.toString().length() == 0));

    zend_ulong num_key;
    zend_string *str_key;
    zval *operand;

    ZEND_HASH_FOREACH_KEY_VAL(input, num_key, str_key, operand) {
        if (have_callback) {
            Variant ret;
            if (mode == 2 /* ARRAY_FILTER_USE_KEY */) {
                Variant key_arg;
                if (str_key) {
                    key_arg = Variant(str_key);
                } else {
                    key_arg = Variant(static_cast<zend_long>(num_key));
                }
                ret = const_cast<Variant &>(callback)({key_arg});
            } else if (mode == 1 /* ARRAY_FILTER_USE_BOTH */) {
                Variant key_arg;
                if (str_key) {
                    key_arg = Variant(str_key);
                } else {
                    key_arg = Variant(static_cast<zend_long>(num_key));
                }
                ret = const_cast<Variant &>(callback)({Variant(operand, Ctor::CopyRef), key_arg});
            } else {
                ret = const_cast<Variant &>(callback)({Variant(operand, Ctor::CopyRef)});
            }

            if (!ret.toBool()) {
                continue;
            }
        } else if (!zend_is_true(operand)) {
            continue;
        }

        zval *new_entry;
        if (str_key) {
            new_entry = zend_hash_add_new(result.array(), str_key, operand);
        } else {
            new_entry = zend_hash_index_add_new(result.array(), num_key, operand);
        }
        zval_add_ref(new_entry);
    } ZEND_HASH_FOREACH_END();

    return result;
}

// ========================
// 9. array_reduce
// ========================

Variant array_reduce(const Array &array, const Variant &callback, const Variant &initial) {
    zend_array *htbl = array.array();

    // Set the initial value as the result
    Variant result;
    if (!initial.isNull() || !initial.isUndef()) {
        result = initial;
    } else {
        result = Variant();  // null
    }

    if (zend_hash_num_elements(htbl) == 0) {
        return result;
    }

    zval *operand;
    ZEND_HASH_FOREACH_VAL(htbl, operand) {
        result = const_cast<Variant &>(callback)({result, Variant(operand, Ctor::CopyRef)});
    } ZEND_HASH_FOREACH_END();

    return result;
}

// ========================
// 11. array_slice
// ========================

Array array_slice(const Array &array, Int offset, const Variant &length, bool preserve_keys) {
    zend_array *input_ht = array.array();
    zend_ulong num_in = zend_hash_num_elements(input_ht);

    // Determine length
    zend_long len;
    bool length_is_null = length.isNull();
    if (length_is_null) {
        len = static_cast<zend_long>(num_in);
    } else {
        len = length.toInt();
    }

    // Clamp offset
    zend_long off = offset;
    if (off > static_cast<zend_long>(num_in)) {
        return Array();
    } else if (off < 0 && (off = static_cast<zend_long>(num_in) + off) < 0) {
        off = 0;
    }

    // Clamp length
    if (len < 0) {
        len = static_cast<zend_long>(num_in) - off + len;
    } else if (static_cast<zend_ulong>(off + len) > num_in) {
        len = static_cast<zend_long>(num_in) - off;
    }

    if (len <= 0) {
        return Array();
    }

    Array result(static_cast<size_t>(len));

    if (HT_IS_PACKED(input_ht)) {
        // Find element at offset
        uint32_t pos = 0;
        zend_long remaining = off;
        for (pos = 0; pos < input_ht->nNumUsed; pos++) {
            zval *zv = input_ht->arPacked + pos;
            if (Z_TYPE_P(zv) != IS_UNDEF) {
                if (remaining == 0) break;
                remaining--;
            }
        }

        if (!preserve_keys || (off == 0 && HT_IS_WITHOUT_HOLES(input_ht))) {
            zend_hash_real_init_packed(result.array());
            ZEND_HASH_FILL_PACKED(result.array()) {
                for (zend_ulong added = 0;
                     added < static_cast<zend_ulong>(len) && pos < input_ht->nNumUsed;
                     pos++) {
                    zval *zv = input_ht->arPacked + pos;
                    if (Z_TYPE_P(zv) == IS_UNDEF) continue;
                    zval *entry = zv;
                    if (Z_ISREF_P(entry) && Z_REFCOUNT_P(entry) == 1) {
                        entry = Z_REFVAL_P(entry);
                    }
                    Z_TRY_ADDREF_P(entry);
                    ZEND_HASH_FILL_ADD(entry);
                    added++;
                }
            } ZEND_HASH_FILL_END();
        } else {
            zend_ulong added = 0;
            for (; added < static_cast<zend_ulong>(len) && pos < input_ht->nNumUsed; pos++) {
                zval *zv = input_ht->arPacked + pos;
                if (Z_TYPE_P(zv) == IS_UNDEF) continue;
                zval *entry = zv;
                if (Z_ISREF_P(entry) && Z_REFCOUNT_P(entry) == 1) {
                    entry = Z_REFVAL_P(entry);
                }
                Z_TRY_ADDREF_P(entry);
                zend_hash_index_add_new(result.array(), pos, entry);
                added++;
            }
        }
    } else {
        // Non-packed array
        zend_ulong num_key;
        zend_string *str_key;
        zval *entry;
        zend_ulong pos = 0;
        zend_ulong added = 0;

        ZEND_HASH_FOREACH_KEY_VAL(input_ht, num_key, str_key, entry) {
            if (pos < static_cast<zend_ulong>(off)) {
                pos++;
                continue;
            }
            if (added >= static_cast<zend_ulong>(len)) {
                break;
            }

            ZVAL_DEREF(entry);
            if (!preserve_keys) {
                zval *new_entry = zend_hash_next_index_insert(result.array(), entry);
                zval_add_ref(new_entry);
            } else {
                if (str_key) {
                    zval *new_entry = zend_hash_add_new(result.array(), str_key, entry);
                    zval_add_ref(new_entry);
                } else {
                    zval *new_entry = zend_hash_index_add_new(result.array(), num_key, entry);
                    zval_add_ref(new_entry);
                }
            }
            pos++;
            added++;
        } ZEND_HASH_FOREACH_END();
    }

    return result;
}

// ========================
// 12. array_chunk
// ========================

Array array_chunk(const Array &array, Int length, bool preserve_keys) {
    zend_array *input = array.array();
    zend_ulong num_in = zend_hash_num_elements(input);

    if (length < 1) {
        php::throwException(zend_ce_value_error,
            "array_chunk(): Argument #2 ($length) must be greater than 0");
        return Array();
    }

    if (static_cast<zend_ulong>(length) > num_in) {
        if (num_in == 0) return Array();
        length = static_cast<Int>(num_in);
    }

    zend_ulong num_chunks = ((num_in - 1) / static_cast<zend_ulong>(length)) + 1;
    Array result(static_cast<size_t>(num_chunks));
    zend_hash_real_init_packed(result.array());

    zval chunk;
    ZVAL_UNDEF(&chunk);
    zend_ulong current = 0;

    zend_ulong num_key;
    zend_string *str_key;
    zval *entry;

    ZEND_HASH_FOREACH_KEY_VAL(input, num_key, str_key, entry) {
        if (Z_TYPE(chunk) == IS_UNDEF) {
            array_init_size(&chunk, static_cast<uint32_t>(length));
        }

        if (preserve_keys) {
            zval *dst;
            if (str_key) {
                dst = zend_hash_add_new(Z_ARRVAL(chunk), str_key, entry);
            } else {
                dst = zend_hash_index_add_new(Z_ARRVAL(chunk), num_key, entry);
            }
            zval_add_ref(dst);
        } else {
            zval *dst = zend_hash_next_index_insert(Z_ARRVAL(chunk), entry);
            zval_add_ref(dst);
        }

        current++;
        if (current == static_cast<zend_ulong>(length)) {
            add_next_index_zval(result.ptr(), &chunk);
            ZVAL_UNDEF(&chunk);
            current = 0;
        }
    } ZEND_HASH_FOREACH_END();

    if (Z_TYPE(chunk) != IS_UNDEF) {
        add_next_index_zval(result.ptr(), &chunk);
    }

    return result;
}

// ========================
// 13. array_unique
// ========================

Array array_unique(const Array &array, Int sort_flags) {
    zend_array *input = array.array();

    if (zend_hash_num_elements(input) <= 1) {
        return Array(array);
    }

    if (sort_flags == 2 /* SORT_STRING */) {
        // Use a HashTable to track seen values
        HashTable seen;
        zend_hash_init(&seen, zend_hash_num_elements(input), NULL, NULL, 0);

        Array result;

        zend_ulong num_key;
        zend_string *str_key;
        zval *val;

        ZEND_HASH_FOREACH_KEY_VAL(input, num_key, str_key, val) {
            zval *retval;
            if (Z_TYPE_P(val) == IS_STRING) {
                retval = zend_hash_add_empty_element(&seen, Z_STR_P(val));
            } else {
                zend_string *tmp_str_val;
                zend_string *str_val = zval_get_tmp_string(val, &tmp_str_val);
                retval = zend_hash_add_empty_element(&seen, str_val);
                zend_tmp_string_release(tmp_str_val);
            }

            if (retval) {
                // First occurrence
                if (Z_ISREF_P(val) && Z_REFCOUNT_P(val) == 1) {
                    ZVAL_DEREF(val);
                }
                Z_TRY_ADDREF_P(val);

                if (str_key) {
                    zend_hash_add_new(result.array(), str_key, val);
                } else {
                    zend_hash_index_add_new(result.array(), num_key, val);
                }
            }
        } ZEND_HASH_FOREACH_END();

        zend_hash_destroy(&seen);
        return result;
    }

    // For other sort flags (SORT_REGULAR, SORT_NUMERIC), use sort-based dedup
    // matching PHP's behavior: copy the array, sort pointers, delete duplicates from copy.

    // Use PHP's unstable comparators for dedup (same as php_get_data_compare_func_unstable)
    using cmp_func_t = int (*)(const void *, const void *);

    struct BucketIndex {
        Bucket b;
        uint32_t i;  // original index for stable ordering
    };

    uint32_t num_elements = zend_hash_num_elements(input);
    BucketIndex *arTmp = (BucketIndex *)emalloc((num_elements + 1) * sizeof(BucketIndex));
    uint32_t count = 0;

    if (HT_IS_PACKED(input)) {
        zval *zv = input->arPacked;
        for (uint32_t idx = 0; idx < input->nNumUsed; idx++, zv++) {
            if (Z_TYPE_P(zv) == IS_UNDEF) continue;
            ZVAL_COPY_VALUE(&arTmp[count].b.val, zv);
            arTmp[count].b.h = idx;
            arTmp[count].b.key = NULL;
            arTmp[count].i = count;
            count++;
        }
    } else {
        Bucket *p = input->arData;
        for (uint32_t idx = 0; idx < input->nNumUsed; idx++, p++) {
            if (Z_TYPE(p->val) == IS_UNDEF) continue;
            arTmp[count].b = *p;
            arTmp[count].i = count;
            count++;
        }
    }
    ZVAL_UNDEF(&arTmp[count].b.val);

    if (count <= 1) {
        efree(arTmp);
        return Array(array);
    }

    // Choose comparator
    cmp_func_t cmp;
    if (sort_flags == 1 /* SORT_NUMERIC */) {
        cmp = [](const void *a, const void *b) -> int {
            const auto *ba = (const BucketIndex *)a;
            const auto *bb = (const BucketIndex *)b;
            return numeric_compare_function(
                const_cast<zval *>(&ba->b.val),
                const_cast<zval *>(&bb->b.val));
        };
    } else {
        cmp = [](const void *a, const void *b) -> int {
            const auto *ba = (const BucketIndex *)a;
            const auto *bb = (const BucketIndex *)b;
            return zend_compare(
                const_cast<zval *>(&ba->b.val),
                const_cast<zval *>(&bb->b.val));
        };
    }

    zend_sort((void *)arTmp, count, sizeof(BucketIndex), cmp,
              [](void *a, void *b) {
                  auto tmp = *(BucketIndex *)a;
                  *(BucketIndex *)a = *(BucketIndex *)b;
                  *(BucketIndex *)b = tmp;
              });

    // Copy the original array (we'll delete duplicates from it)
    Array result;
    zend_array_destroy(result.array());
    ZVAL_ARR(result.ptr(), zend_array_dup(input));

    // Go through sorted array, delete duplicates (keep first occurrence = lowest original index)
    BucketIndex *lastkept = arTmp;
    for (BucketIndex *cmpdata = arTmp + 1; Z_TYPE(cmpdata->b.val) != IS_UNDEF; cmpdata++) {
        if (cmp(&lastkept->b, &cmpdata->b) != 0) {
            lastkept = cmpdata;
        } else {
            // Duplicate: delete the one with higher original index
            Bucket *p;
            if (lastkept->i > cmpdata->i) {
                p = &lastkept->b;
                lastkept = cmpdata;
            } else {
                p = &cmpdata->b;
            }
            if (p->key == NULL) {
                zend_hash_index_del(result.array(), p->h);
            } else {
                zend_hash_del(result.array(), p->key);
            }
        }
    }

    efree(arTmp);
    return result;
}

// ========================
// 14. array_column
// ========================

Array array_column(const Array &array, const Variant &column_key, const Variant &index_key) {
    zend_array *input = array.array();
    bool column_is_null = column_key.isNull();
    bool index_is_null = index_key.isNull();

    Array result(static_cast<size_t>(zend_hash_num_elements(input)));

    if (column_is_null && index_is_null) {
        // No column, no index: return values as-is
        zend_hash_real_init_packed(result.array());
        zval *data;
        ZEND_HASH_FILL_PACKED(result.array()) {
            ZEND_HASH_FOREACH_VAL(input, data) {
                ZVAL_DEREF(data);
                Z_TRY_ADDREF_P(data);
                ZEND_HASH_FILL_ADD(data);
            } ZEND_HASH_FOREACH_END();
        } ZEND_HASH_FILL_END();
        return result;
    }

    zend_string *column_str = nullptr;
    zend_long column_long = 0;
    zend_string *index_str = nullptr;
    zend_long index_long = 0;

    if (!column_is_null) {
        if (column_key.isString()) {
            column_str = Z_STR_P(column_key.unwrap_ptr());
        } else if (column_key.isInt()) {
            column_long = column_key.toInt();
        }
    }
    if (!index_is_null) {
        if (index_key.isString()) {
            index_str = Z_STR_P(index_key.unwrap_ptr());
        } else if (index_key.isInt()) {
            index_long = index_key.toInt();
        }
    }

    zval *data;
    void *cache_slot_col[3] = {nullptr, nullptr, nullptr};
    void *cache_slot_idx[3] = {nullptr, nullptr, nullptr};

    ZEND_HASH_FOREACH_VAL(input, data) {
        ZVAL_DEREF(data);

        // Extract column value
        zval *colval = nullptr;
        zval rv;

        if (column_is_null) {
            Z_TRY_ADDREF_P(data);
            colval = data;
        } else if (Z_TYPE_P(data) == IS_OBJECT) {
            // Get object property
            zend_object *zobj = Z_OBJ_P(data);
            if (column_str) {
                colval = zobj->handlers->read_property(zobj, column_str, BP_VAR_R, cache_slot_col, &rv);
            } else {
                // numeric key on object - try offsetGet
                zval tmp;
                ZVAL_LONG(&tmp, column_long);
                colval = zobj->handlers->read_dimension(zobj, &tmp, BP_VAR_R, &rv);
            }
            if (colval == nullptr || Z_ISUNDEF_P(colval)) {
                continue;
            }
        } else if (Z_TYPE_P(data) == IS_ARRAY) {
            // Array access
            zend_array *data_arr = Z_ARRVAL_P(data);
            if (column_str) {
                colval = zend_hash_find(data_arr, column_str);
            } else {
                colval = zend_hash_index_find(data_arr, static_cast<zend_ulong>(column_long));
            }
            if (colval == nullptr || Z_ISUNDEF_P(colval)) {
                continue;
            }
        } else {
            // Non-array, non-object: skip
            continue;
        }

        Z_TRY_ADDREF_P(colval);

        if (index_is_null) {
            // No index key, just append
            zend_hash_next_index_insert(result.array(), colval);
            zval_ptr_dtor(colval);
        } else {
            // Extract index key value
            zval *keyval = nullptr;
            zval idx_rv;

            if (Z_TYPE_P(data) == IS_OBJECT) {
                zend_object *zobj = Z_OBJ_P(data);
                if (index_str) {
                    keyval = zobj->handlers->read_property(zobj, index_str, BP_VAR_R, cache_slot_idx, &idx_rv);
                } else {
                    zval tmp;
                    ZVAL_LONG(&tmp, index_long);
                    keyval = zobj->handlers->read_dimension(zobj, &tmp, BP_VAR_R, &idx_rv);
                }
            } else if (Z_TYPE_P(data) == IS_ARRAY) {
                zend_array *data_arr = Z_ARRVAL_P(data);
                if (index_str) {
                    keyval = zend_hash_find(data_arr, index_str);
                } else {
                    keyval = zend_hash_index_find(data_arr, static_cast<zend_ulong>(index_long));
                }
            }

            if (keyval && !Z_ISUNDEF_P(keyval)) {
                array_set_zval_key(result.array(), keyval, colval);
                zval_ptr_dtor(colval);
                zval_ptr_dtor(keyval);
            } else {
                zend_hash_next_index_insert(result.array(), colval);
                zval_ptr_dtor(colval);
            }
        }
    } ZEND_HASH_FOREACH_END();

    return result;
}

// ========================
// 15. sort (in-place)
// ========================

// Internal sort comparators
static int _sort_regular(Bucket *a, Bucket *b) {
    return array_data_compare(a, b);
}

static int _sort_numeric(Bucket *a, Bucket *b) {
    double d1 = zval_get_double(&a->val);
    double d2 = zval_get_double(&b->val);
    if (d1 < d2) return -1;
    if (d1 > d2) return 1;
    return 0;
}

static int _sort_string(Bucket *a, Bucket *b) {
    zend_string *s1 = zval_get_string(&a->val);
    zend_string *s2 = zval_get_string(&b->val);
    int ret = zend_binary_strcmp(ZSTR_VAL(s1), ZSTR_LEN(s1), ZSTR_VAL(s2), ZSTR_LEN(s2));
    zend_string_release(s1);
    zend_string_release(s2);
    return ret;
}

static int _sort_string_case(Bucket *a, Bucket *b) {
    zend_string *s1 = zval_get_string(&a->val);
    zend_string *s2 = zval_get_string(&b->val);
    int ret = zend_binary_strcasecmp(ZSTR_VAL(s1), ZSTR_LEN(s1), ZSTR_VAL(s2), ZSTR_LEN(s2));
    zend_string_release(s1);
    zend_string_release(s2);
    return ret;
}

static int _sort_numeric_desc(Bucket *a, Bucket *b) {
    return _sort_numeric(b, a);
}

static int _sort_string_desc(Bucket *a, Bucket *b) {
    return _sort_string(b, a);
}

static int _sort_string_case_desc(Bucket *a, Bucket *b) {
    return _sort_string_case(b, a);
}

Bool sort(Variant &arg, Int flags) {
    zval *zv = arg.unwrap_ptr();
    if (!zval_is_array(zv) || zend_hash_num_elements(Z_ARRVAL_P(zv)) <= 1) {
        return true;
    }

    SEPARATE_ARRAY(zv);

    bucket_compare_func_t cmp;
    bool renumber = true;
    int sort_type = static_cast<int>(flags);
    int case_flag = sort_type & PHP_SORT_FLAG_CASE;
    bool descending = (sort_type & AOT_SORT_REVERSE) != 0;
    int base_type = sort_type & ~AOT_SORT_REVERSE & ~PHP_SORT_FLAG_CASE;

    // Map SORT_DESC(3)/SORT_ASC(4) back to REGULAR — they encode direction in the type slot
    if (base_type == PHP_SORT_DESC) {
        descending = true;
        base_type = PHP_SORT_REGULAR;
    } else if (base_type == PHP_SORT_ASC) {
        base_type = PHP_SORT_REGULAR;
    }

    switch (base_type | case_flag) {
    case PHP_SORT_NUMERIC:
        cmp = descending ? _sort_numeric_desc : _sort_numeric;
        break;
    case PHP_SORT_STRING:
        cmp = descending ? _sort_string_desc : _sort_string;
        break;
    case PHP_SORT_STRING | PHP_SORT_FLAG_CASE:
        cmp = descending ? _sort_string_case_desc : _sort_string_case;
        break;
    case PHP_SORT_REGULAR:
    default:
        cmp = _sort_regular;
        break;
    }

    zend_hash_sort(Z_ARRVAL_P(zv), cmp, renumber);
    return true;
}

// ========================
// asort (in-place, preserves keys)
// ========================

Bool asort(Variant &arg, Int flags) {
    zval *zv = arg.unwrap_ptr();
    if (!zval_is_array(zv) || zend_hash_num_elements(Z_ARRVAL_P(zv)) <= 1) {
        return true;
    }

    SEPARATE_ARRAY(zv);

    bucket_compare_func_t cmp;
    int sort_type = static_cast<int>(flags);
    int case_flag = sort_type & PHP_SORT_FLAG_CASE;
    bool descending = (sort_type & AOT_SORT_REVERSE) != 0;
    int base_type = sort_type & ~AOT_SORT_REVERSE & ~PHP_SORT_FLAG_CASE;

    if (base_type == PHP_SORT_DESC) {
        descending = true;
        base_type = PHP_SORT_REGULAR;
    } else if (base_type == PHP_SORT_ASC) {
        base_type = PHP_SORT_REGULAR;
    }

    switch (base_type | case_flag) {
    case PHP_SORT_NUMERIC:
        cmp = descending ? _sort_numeric_desc : _sort_numeric;
        break;
    case PHP_SORT_STRING:
        cmp = descending ? _sort_string_desc : _sort_string;
        break;
    case PHP_SORT_STRING | PHP_SORT_FLAG_CASE:
        cmp = descending ? _sort_string_case_desc : _sort_string_case;
        break;
    case PHP_SORT_REGULAR:
    default:
        cmp = _sort_regular;
        break;
    }

    zend_hash_sort(Z_ARRVAL_P(zv), cmp, false);
    return true;
}

// ========================
// 16. array_push (in-place)
// ========================

Int array_push(Variant &arg, ::std::initializer_list<Variant> values) {
    zval *zv = arg.unwrap_ptr();
    if (!zval_is_array(zv)) {
        php::throwException(zend_ce_type_error, "array_push(): Argument #1 ($array) must be of type array");
        return 0;
    }
    SEPARATE_ARRAY(zv);

    for (const auto &val : values) {
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
// 17. array_pop (in-place)
// ========================

Variant array_pop(Variant &arg) {
    zval *zv = arg.unwrap_ptr();
    if (!zval_is_array(zv)) {
        return Variant();  // null
    }
    zend_array *ht = Z_ARRVAL_P(zv);

    if (zend_hash_num_elements(ht) == 0) {
        return Variant();  // null
    }

    SEPARATE_ARRAY(zv);
    ht = Z_ARRVAL_P(zv);  // re-fetch after separation

    if (HT_IS_PACKED(ht)) {
        uint32_t idx = ht->nNumUsed;
        while (idx > 0) {
            idx--;
            zval *val = ht->arPacked + idx;
            if (Z_TYPE_P(val) != IS_UNDEF) {
                Variant result;
                ZVAL_COPY_VALUE(result.ptr(), val);
                ZVAL_UNDEF(val);

                if (idx == (ht->nNextFreeElement - 1)) {
                    uint32_t new_next = idx;
                    while (new_next > 0) {
                        new_next--;
                        if (Z_TYPE(ht->arPacked[new_next]) != IS_UNDEF) {
                            new_next++;
                            break;
                        }
                    }
                    ht->nNextFreeElement = new_next;
                }

                zend_hash_packed_del_val(ht, val);

                if (!HT_HAS_ITERATORS(ht)) {
                    uint32_t k = 0;
                    for (uint32_t i = 0; i < ht->nNumUsed; i++) {
                        zval *v = ht->arPacked + i;
                        if (Z_TYPE_P(v) == IS_UNDEF) continue;
                        if (i != k) {
                            zval *q = ht->arPacked + k;
                            ZVAL_COPY_VALUE(q, v);
                            ZVAL_UNDEF(v);
                        }
                        k++;
                    }
                    ht->nNumUsed = k;
                }

                return result;
            }
        }
        return Variant();  // null
    } else {
        zend_ulong last_num = 0;
        zend_string *last_str = nullptr;
        zval *last_val = nullptr;
        zend_ulong num_key;
        zend_string *str_key;
        zval *val;

        ZEND_HASH_FOREACH_KEY_VAL(ht, num_key, str_key, val) {
            last_num = num_key;
            last_str = str_key;
            last_val = val;
        } ZEND_HASH_FOREACH_END();

        if (last_val) {
            Variant result(last_val);
            if (last_str) {
                zend_hash_del(ht, last_str);
            } else {
                zend_hash_index_del(ht, last_num);
            }
            return result;
        }
        return Variant();  // null
    }
}

// ========================
// 18. array_shift (in-place)
// ========================

Variant array_shift(Variant &arg) {
    zval *zv = arg.unwrap_ptr();
    if (!zval_is_array(zv)) {
        return Variant();  // null
    }
    zend_array *ht = Z_ARRVAL_P(zv);

    if (zend_hash_num_elements(ht) == 0) {
        return Variant();  // null
    }

    SEPARATE_ARRAY(zv);
    ht = Z_ARRVAL_P(zv);

    if (HT_IS_PACKED(ht)) {
        uint32_t idx = 0;
        zval *val = nullptr;

        while (idx < ht->nNumUsed) {
            val = ht->arPacked + idx;
            if (Z_TYPE_P(val) != IS_UNDEF) {
                break;
            }
            idx++;
        }

        if (idx >= ht->nNumUsed) {
            return Variant();  // null
        }

        Variant result;
        ZVAL_COPY_VALUE(result.ptr(), val);
        ZVAL_UNDEF(val);

        zend_hash_packed_del_val(ht, val);

        if (!HT_HAS_ITERATORS(ht)) {
            uint32_t k = 0;
            for (uint32_t i = 0; i < ht->nNumUsed; i++) {
                val = ht->arPacked + i;
                if (Z_TYPE_P(val) == IS_UNDEF) continue;
                if (i != k) {
                    zval *q = ht->arPacked + k;
                    ZVAL_COPY_VALUE(q, val);
                    ZVAL_UNDEF(val);
                }
                k++;
            }
            ht->nNumUsed = k;
            ht->nNextFreeElement = k;
        } else {
            uint32_t iter_pos = zend_hash_iterators_lower_pos(ht, 0);
            uint32_t k = 0;
            for (uint32_t i = 0; i < ht->nNumUsed; i++) {
                val = ht->arPacked + i;
                if (Z_TYPE_P(val) == IS_UNDEF) continue;
                if (i != k) {
                    zval *q = ht->arPacked + k;
                    ZVAL_COPY_VALUE(q, val);
                    ZVAL_UNDEF(val);
                    if (i == iter_pos) {
                        zend_hash_iterators_update(ht, i, k);
                        iter_pos = zend_hash_iterators_lower_pos(ht, iter_pos + 1);
                    }
                }
                k++;
            }
            ht->nNumUsed = k;
            ht->nNextFreeElement = k;
        }

        return result;
    } else {
        // Non-packed: find the first element using arData iteration (matching PHP)
        uint32_t idx = 0;
        Bucket *p;
        zval *first_val = nullptr;

        while (idx < ht->nNumUsed) {
            p = ht->arData + idx;
            first_val = &p->val;
            if (Z_TYPE_P(first_val) != IS_UNDEF) {
                break;
            }
            idx++;
        }

        if (!first_val || Z_TYPE_P(first_val) == IS_UNDEF) {
            return Variant();
        }

        Variant result;
        ZVAL_COPY_VALUE(result.ptr(), first_val);
        ZVAL_UNDEF(first_val);

        // Delete the first bucket
        zend_hash_del_bucket(ht, p);

        // Re-index integer keys
        uint32_t k = 0;
        bool should_rehash = false;
        for (uint32_t i = 0; i < ht->nNumUsed; i++) {
            p = ht->arData + i;
            if (Z_TYPE(p->val) == IS_UNDEF) continue;
            if (p->key == NULL) {
                if (p->h != k) {
                    p->h = k++;
                    should_rehash = true;
                } else {
                    k++;
                }
            }
        }
        ht->nNextFreeElement = k;
        if (should_rehash) {
            zend_hash_rehash(ht);
        }

        zend_hash_internal_pointer_reset(ht);

        if (Z_ISREF_P(result.ptr())) {
            zend_unwrap_reference(result.ptr());
        }
        return result;
    }
}

// ========================
// 19. array_unshift (in-place)
// ========================

Int array_unshift(Variant &arg, ::std::initializer_list<Variant> values) {
    zval *zv = arg.unwrap_ptr();
    if (!zval_is_array(zv)) {
        php::throwException(zend_ce_type_error, "array_unshift(): Argument #1 ($array) must be of type array");
        return 0;
    }

    if (values.size() == 0) {
        return static_cast<Int>(zend_hash_num_elements(Z_ARRVAL_P(zv)));
    }

    SEPARATE_ARRAY(zv);
    zend_array *old_ht = Z_ARRVAL_P(zv);

    HashTable new_hash;
    zend_hash_init(&new_hash, zend_hash_num_elements(old_ht) + values.size(), NULL, ZVAL_PTR_DTOR, 0);

    // Add new elements at the beginning
    for (const auto &val : values) {
        zval *v = NO_CONST_V(val);
        Z_TRY_ADDREF_P(v);
        zend_hash_next_index_insert_new(&new_hash, v);
    }

    // Copy existing elements, preserving string keys
    {
        zend_string *key;
        zval *value;
        ZEND_HASH_FOREACH_STR_KEY_VAL(old_ht, key, value) {
            if (key) {
                zend_hash_add_new(&new_hash, key, value);
            } else {
                zend_hash_next_index_insert_new(&new_hash, value);
            }
        } ZEND_HASH_FOREACH_END();
    }

    // Handle iterators
    if (UNEXPECTED(HT_HAS_ITERATORS(old_ht))) {
        zend_hash_iterators_advance(old_ht, values.size());
        HT_SET_ITERATORS_COUNT(&new_hash, HT_ITERATORS_COUNT(old_ht));
        HT_SET_ITERATORS_COUNT(old_ht, 0);
    }

    // Replace old HashTable data
    old_ht->pDestructor = NULL;
    zend_hash_destroy(old_ht);

    HT_FLAGS(old_ht)          = HT_FLAGS(&new_hash);
    old_ht->nTableSize        = new_hash.nTableSize;
    old_ht->nTableMask        = new_hash.nTableMask;
    old_ht->nNumUsed          = new_hash.nNumUsed;
    old_ht->nNumOfElements    = new_hash.nNumOfElements;
    old_ht->nNextFreeElement  = new_hash.nNextFreeElement;
    old_ht->arData            = new_hash.arData;
    old_ht->pDestructor       = new_hash.pDestructor;

    zend_hash_internal_pointer_reset(old_ht);

    return static_cast<Int>(zend_hash_num_elements(old_ht));
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

Variant reset(Variant &arg) {
    zval *zv = arg.unwrap_ptr();
    if (!zval_is_array(zv)) {
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

Variant end(Variant &arg) {
    zval *zv = arg.unwrap_ptr();
    if (!zval_is_array(zv)) {
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
// 23. ksort
// ========================

// Key comparators (matching PHP's php_get_key_compare_func approach)

static int _ksort_key_compare_regular(Bucket *a, Bucket *b) {
    if (a->key == nullptr && b->key == nullptr) {
        return (a->h > b->h) ? 1 : ((a->h < b->h) ? -1 : 0);
    }
    if (a->key == nullptr) {
        // Integer key < string key in PHP
        return -1;
    }
    if (b->key == nullptr) {
        return 1;
    }
    return zend_binary_strcmp(ZSTR_VAL(a->key), ZSTR_LEN(a->key),
                              ZSTR_VAL(b->key), ZSTR_LEN(b->key));
}

static int _ksort_key_compare_numeric(Bucket *a, Bucket *b) {
    double d1, d2;
    if (a->key) {
        d1 = zend_strtod(ZSTR_VAL(a->key), nullptr);
    } else {
        d1 = (double)(zend_long)a->h;
    }
    if (b->key) {
        d2 = zend_strtod(ZSTR_VAL(b->key), nullptr);
    } else {
        d2 = (double)(zend_long)b->h;
    }
    return ZEND_THREEWAY_COMPARE(d1, d2);
}

static int _ksort_key_compare_string_case(Bucket *a, Bucket *b) {
    if (a->key == nullptr && b->key == nullptr) {
        return (a->h > b->h) ? 1 : ((a->h < b->h) ? -1 : 0);
    }
    if (a->key == nullptr) return -1;
    if (b->key == nullptr) return 1;
    return zend_binary_strcasecmp(ZSTR_VAL(a->key), ZSTR_LEN(a->key),
                                  ZSTR_VAL(b->key), ZSTR_LEN(b->key));
}

Bool ksort(Variant &arg, Int flags) {
    zval *zv = arg.unwrap_ptr();
    if (!zval_is_array(zv)) {
        return true;
    }

    SEPARATE_ARRAY(zv);

    int sort_type = static_cast<int>(flags);
    int case_flag = sort_type & PHP_SORT_FLAG_CASE;
    int base_type = sort_type & ~PHP_SORT_FLAG_CASE;
    bool descending = false;

    // Map PHP_SORT_DESC(3) / PHP_SORT_ASC(4) back to REGULAR
    if (base_type == PHP_SORT_DESC) {
        descending = true;
        base_type = PHP_SORT_REGULAR;
    } else if (base_type == PHP_SORT_ASC) {
        base_type = PHP_SORT_REGULAR;
    }

    bucket_compare_func_t cmp;
    switch (base_type | case_flag) {
    case PHP_SORT_NUMERIC:
        cmp = _ksort_key_compare_numeric;
        break;
    case PHP_SORT_STRING | PHP_SORT_FLAG_CASE:
        cmp = _ksort_key_compare_string_case;
        break;
    case PHP_SORT_STRING:
    case PHP_SORT_REGULAR:
    default:
        cmp = _ksort_key_compare_regular;
        break;
    }

    // Note: descending with sort by key is rare; we don't reverse for now.
    // ksort() always sorts ascending by key.
    zend_hash_sort(Z_ARRVAL_P(zv), cmp, false);
    return true;
}

// ========================
// 24. array_reverse
// ========================

Array array_reverse(const Array &array, bool preserve_keys) {
    zend_array *src = array.array();
    uint32_t num = zend_hash_num_elements(src);

    if (num == 0) {
        return Array();
    }

    zend_array *dest = zend_new_array(num);
    zval *entries = (zval *)emalloc(sizeof(zval) * num);
    zend_ulong *nums = (zend_ulong *)emalloc(sizeof(zend_ulong) * num);
    zend_string **strs = (zend_string **)emalloc(sizeof(zend_string *) * num);
    bool *has_str = (bool *)emalloc(sizeof(bool) * num);

    zval *entry_val;
    zend_ulong num_idx;
    zend_string *str_idx;
    uint32_t idx = 0;

    ZEND_HASH_FOREACH_KEY_VAL(src, num_idx, str_idx, entry_val) {
        ZVAL_DEREF(entry_val);
        ZVAL_COPY(&entries[idx], entry_val);
        if (str_idx) {
            strs[idx] = str_idx;
            has_str[idx] = true;
        } else {
            nums[idx] = num_idx;
            has_str[idx] = false;
        }
        idx++;
    } ZEND_HASH_FOREACH_END();

    for (int i = static_cast<int>(num) - 1; i >= 0; i--) {
        if (has_str[i]) {
            if (preserve_keys) {
                zend_hash_add(dest, strs[i], &entries[i]);
            } else {
                zend_hash_next_index_insert(dest, &entries[i]);
            }
        } else {
            if (preserve_keys) {
                zend_hash_index_add(dest, nums[i], &entries[i]);
            } else {
                zend_hash_next_index_insert(dest, &entries[i]);
            }
        }
    }

    for (uint32_t i = 0; i < num; i++) {
        zval_ptr_dtor(&entries[i]);
    }
    efree(entries);
    efree(nums);
    efree(strs);
    efree(has_str);

    // Take ownership of dest without bumping refcount
    Array result;
    zend_array_destroy(result.array());
    ZVAL_ARR(result.ptr(), dest);
    return result;
}

// ========================
// 25. array_diff
// ========================
// PHP compares values as strings (zval_get_tmp_string), not loose equality.

Array array_diff(const Array &array, const Array &others) {
    zend_array *src = array.array();
    zend_array *exclude = others.array();
    uint32_t num_exclude = zend_hash_num_elements(exclude);

    if (num_exclude == 0) {
        return Array(array);
    }

    if (zend_hash_num_elements(src) == 0) {
        return Array();
    }

    // Deep copy the source array
    zend_array *dest = zend_array_dup(src);
    uint32_t num_elements = zend_hash_num_elements(src);

    // Collect string keys to delete (can't delete during iteration)
    zend_string **del_keys = (zend_string **)emalloc(sizeof(zend_string *) * num_elements);
    zend_ulong *del_idx = (zend_ulong *)emalloc(sizeof(zend_ulong) * num_elements);
    uint32_t del_keys_count = 0;
    uint32_t del_idx_count = 0;

    zval *entry;
    zend_ulong num_idx;
    zend_string *str_idx;

    ZEND_HASH_FOREACH_KEY_VAL(dest, num_idx, str_idx, entry) {
        ZVAL_DEREF(entry);

        zend_string *tmp_str;
        zend_string *str = zval_get_tmp_string(entry, &tmp_str);

        bool found = false;
        {
            zval *ex_entry;
            ZEND_HASH_FOREACH_VAL(exclude, ex_entry) {
                zend_string *tmp_ex;
                zend_string *ex_str = zval_get_tmp_string(ex_entry, &tmp_ex);
                if (zend_string_equals(str, ex_str)) {
                    found = true;
                    zend_tmp_string_release(tmp_ex);
                    break;
                }
                zend_tmp_string_release(tmp_ex);
            } ZEND_HASH_FOREACH_END();
        }
        zend_tmp_string_release(tmp_str);

        if (found) {
            if (str_idx) {
                del_keys[del_keys_count++] = str_idx;
            } else {
                del_idx[del_idx_count++] = num_idx;
            }
        }
    } ZEND_HASH_FOREACH_END();

    // Delete marked entries
    for (uint32_t i = 0; i < del_keys_count; i++) {
        zend_hash_del(dest, del_keys[i]);
    }
    for (uint32_t i = 0; i < del_idx_count; i++) {
        zend_hash_index_del(dest, del_idx[i]);
    }
    efree(del_keys);
    efree(del_idx);

    Array result;
    zend_array_destroy(result.array());
    ZVAL_ARR(result.ptr(), dest);
    return result;
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
    } ZEND_HASH_FOREACH_END();

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
    } ZEND_HASH_FOREACH_END();

    if (last_str) {
        return Variant(String(last_str));
    }
    return Variant(static_cast<Int>(last_num));
}

// ========================
// array_sum
// ========================

Variant array_sum(const Array &array) {
    HashTable *ht = array.array();
    double sum = 0.0;
    bool has_float = false;
    zval *entry;

    ZEND_HASH_FOREACH_VAL(ht, entry) {
        ZVAL_DEREF(entry);
        if (Z_TYPE_P(entry) == IS_LONG) {
            sum += (double)Z_LVAL_P(entry);
        } else if (Z_TYPE_P(entry) == IS_DOUBLE) {
            sum += Z_DVAL_P(entry);
            has_float = true;
        } else if (Z_TYPE_P(entry) == IS_TRUE) {
            sum += 1.0;
        } else if (Z_TYPE_P(entry) == IS_ARRAY || Z_TYPE_P(entry) == IS_OBJECT) {
            // skip — PHP ignores non-numeric values
        } else if (Z_TYPE_P(entry) == IS_STRING) {
            // Only count as float if the string represents a float value
            zend_long lval;
            double dval;
            int ret = is_numeric_string(Z_STRVAL_P(entry), Z_STRLEN_P(entry), &lval, &dval, 0);
            if (ret == IS_LONG) {
                sum += (double)lval;
            } else if (ret == IS_DOUBLE) {
                sum += dval;
                has_float = true;
            }
            // ret == 0: non-numeric string, contributes 0 (no has_float)
        } else {
            // IS_FALSE, IS_NULL, IS_RESOURCE — all convert to 0, no float
            sum += zval_get_double(entry);
        }
    } ZEND_HASH_FOREACH_END();

    if (has_float) {
        return Variant(sum);
    }
    return Variant(static_cast<Int>(sum));
}

// ========================
// array_product
// ========================

Variant array_product(const Array &array) {
    HashTable *ht = array.array();
    double product = 1.0;
    bool has_float = false;
    zval *entry;

    ZEND_HASH_FOREACH_VAL(ht, entry) {
        ZVAL_DEREF(entry);
        if (Z_TYPE_P(entry) == IS_LONG) {
            product *= (double)Z_LVAL_P(entry);
        } else if (Z_TYPE_P(entry) == IS_DOUBLE) {
            product *= Z_DVAL_P(entry);
            has_float = true;
        } else if (Z_TYPE_P(entry) == IS_TRUE) {
            // Multiply by 1 — no change
        } else if (Z_TYPE_P(entry) == IS_ARRAY || Z_TYPE_P(entry) == IS_OBJECT) {
            // skip — PHP ignores non-numeric values
        } else if (Z_TYPE_P(entry) == IS_STRING) {
            zend_long lval;
            double dval;
            int ret = is_numeric_string(Z_STRVAL_P(entry), Z_STRLEN_P(entry), &lval, &dval, 0);
            if (ret == IS_LONG) {
                product *= (double)lval;
            } else if (ret == IS_DOUBLE) {
                product *= dval;
                has_float = true;
            } else {
                // ret == 0: non-numeric string, contributes 0 (product becomes 0)
                product = 0.0;
            }
        } else {
            // IS_FALSE, IS_NULL, IS_RESOURCE — all convert to 0
            product *= zval_get_double(entry);
        }
    } ZEND_HASH_FOREACH_END();

    if (has_float) {
        return Variant(product);
    }
    return Variant(static_cast<Int>(product));
}

// ========================
// array_combine
// ========================

Array array_combine(const Array &keys, const Array &values) {
    HashTable *keys_ht = keys.array();
    HashTable *values_ht = values.array();
    uint32_t num_keys = zend_hash_num_elements(keys_ht);

    if (num_keys != zend_hash_num_elements(values_ht)) {
        php::throwException(zend_ce_value_error,
            "array_combine(): Argument #1 ($keys) and argument #2 ($values) must have the same number of elements");
        return Array();
    }

    if (num_keys == 0) {
        return Array();
    }

    zend_array *dest = zend_new_array(num_keys);
    uint32_t pos_values = 0;
    zval *entry_keys;
    zval *entry_values;

    ZEND_HASH_FOREACH_VAL(keys_ht, entry_keys) {
        // Find next non-undef value from values array by position
        while (1) {
            if (pos_values >= values_ht->nNumUsed) {
                break;
            }
            entry_values = ZEND_HASH_ELEMENT(values_ht, pos_values);
            if (Z_TYPE_P(entry_values) != IS_UNDEF) {
                if (Z_TYPE_P(entry_keys) == IS_LONG) {
                    entry_values = zend_hash_index_update(dest, Z_LVAL_P(entry_keys), entry_values);
                } else if (Z_TYPE_P(entry_keys) == IS_STRING) {
                    entry_values = zend_symtable_update(dest, Z_STR_P(entry_keys), entry_values);
                } else {
                    // Non-int/non-string key: convert to string like PHP
                    zend_string *tmp_key;
                    zend_string *key = zval_get_tmp_string(entry_keys, &tmp_key);
                    entry_values = zend_symtable_update(dest, key, entry_values);
                    zend_tmp_string_release(tmp_key);
                }
                zval_add_ref(entry_values);
                pos_values++;
                break;
            }
            pos_values++;
        }
    } ZEND_HASH_FOREACH_END();

    Array result;
    zend_array_destroy(result.array());
    ZVAL_ARR(result.ptr(), dest);
    return result;
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

// ========================
// array_flip
// ========================

Array array_flip(const Array &array) {
    HashTable *src = array.array();
    zend_array *dest = zend_new_array(zend_hash_num_elements(src));
    zval *entry;
    zval key_copy;
    zval val_copy;
    zend_ulong num_idx;
    zend_string *str_idx;

    ZEND_HASH_FOREACH_KEY_VAL(src, num_idx, str_idx, entry) {
        ZVAL_DEREF(entry);

        // Only strings and integers can be used as keys
        if (Z_TYPE_P(entry) == IS_STRING) {
            // Original key becomes new value
            if (str_idx) {
                ZVAL_STR_COPY(&val_copy, str_idx);
            } else {
                ZVAL_LONG(&val_copy, static_cast<zend_long>(num_idx));
            }
            // Entry value becomes new key
            ZVAL_STR_COPY(&key_copy, Z_STR_P(entry));
        } else if (Z_TYPE_P(entry) == IS_LONG) {
            // Original key becomes new value
            if (str_idx) {
                ZVAL_STR_COPY(&val_copy, str_idx);
            } else {
                ZVAL_LONG(&val_copy, static_cast<zend_long>(num_idx));
            }
            // Entry value becomes new key
            ZVAL_LONG(&key_copy, Z_LVAL_P(entry));
        } else {
            php::throwException(zend_ce_value_error,
                "array_flip(): Can only flip string and integer values, entry skipped");
            continue;
        }

        if (Z_TYPE(key_copy) == IS_STRING) {
            zend_symtable_update(dest, Z_STR(key_copy), &val_copy);
            zval_ptr_dtor(&key_copy);
        } else {
            zend_hash_index_update(dest, Z_LVAL(key_copy), &val_copy);
        }
    } ZEND_HASH_FOREACH_END();

    Array result;
    zend_array_destroy(result.array());
    ZVAL_ARR(result.ptr(), dest);
    return result;
}

// ========================
// array_intersect
// ========================
// PHP compares values as strings (not loose equality).

Array array_intersect(const Array &array, const Array &others) {
    HashTable *src = array.array();
    HashTable *include = others.array();
    uint32_t num_include = zend_hash_num_elements(include);

    if (num_include == 0 || zend_hash_num_elements(src) == 0) {
        return Array();
    }

    // Deep copy the source array
    zend_array *dest = zend_array_dup(src);
    uint32_t num_elements = zend_hash_num_elements(src);

    // Collect keys to delete
    zend_string **del_keys = (zend_string **)emalloc(sizeof(zend_string *) * num_elements);
    zend_ulong *del_idx = (zend_ulong *)emalloc(sizeof(zend_ulong) * num_elements);
    uint32_t del_keys_count = 0;
    uint32_t del_idx_count = 0;

    zval *entry;
    zend_ulong num_idx;
    zend_string *str_idx;

    ZEND_HASH_FOREACH_KEY_VAL(dest, num_idx, str_idx, entry) {
        ZVAL_DEREF(entry);

        zend_string *tmp_str;
        zend_string *str = zval_get_tmp_string(entry, &tmp_str);

        bool found = false;
        {
            zval *inc_entry;
            ZEND_HASH_FOREACH_VAL(include, inc_entry) {
                zend_string *tmp_inc;
                zend_string *inc_str = zval_get_tmp_string(inc_entry, &tmp_inc);
                if (zend_string_equals(str, inc_str)) {
                    found = true;
                    zend_tmp_string_release(tmp_inc);
                    break;
                }
                zend_tmp_string_release(tmp_inc);
            } ZEND_HASH_FOREACH_END();
        }
        zend_tmp_string_release(tmp_str);

        if (!found) {
            if (str_idx) {
                del_keys[del_keys_count++] = str_idx;
            } else {
                del_idx[del_idx_count++] = num_idx;
            }
        }
    } ZEND_HASH_FOREACH_END();

    // Delete marked entries
    for (uint32_t i = 0; i < del_keys_count; i++) {
        zend_hash_del(dest, del_keys[i]);
    }
    for (uint32_t i = 0; i < del_idx_count; i++) {
        zend_hash_index_del(dest, del_idx[i]);
    }
    efree(del_keys);
    efree(del_idx);

    Array result;
    zend_array_destroy(result.array());
    ZVAL_ARR(result.ptr(), dest);
    return result;
}

}  // namespace php::std
