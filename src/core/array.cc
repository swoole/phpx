/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <rango@swoole.com>                             |
  +----------------------------------------------------------------------+
*/

#include "phpx.h"

#include "phpx_func.h"
#include "zend_closures.h"

namespace php {
int array_data_compare(Bucket *f, Bucket *s) {
    zval result;
    zval *first = &f->val;
    zval *second = &s->val;

    if (UNEXPECTED(Z_TYPE_P(first) == IS_INDIRECT)) {
        first = Z_INDIRECT_P(first);
    }
    if (UNEXPECTED(Z_TYPE_P(second) == IS_INDIRECT)) {
        second = Z_INDIRECT_P(second);
    }
    if (compare_function(&result, first, second) == FAILURE) {
        return 0;
    }

    ZEND_ASSERT(Z_TYPE(result) == IS_LONG);
    return Z_LVAL(result);
}

Array Array::slice(long offset, long length, bool preserve_keys) {
    auto zarr = unwrap_ptr();
    size_t num_in = count();

    if (offset > num_in) {
        return Array{};
    } else if (offset < 0 && (offset = (num_in + offset)) < 0) {
        offset = 0;
    }

    if (length < 0) {
        length = num_in - offset + length;
    } else if (((zend_ulong) offset + (zend_ulong) length) > (unsigned) num_in) {
        length = num_in - offset;
    }

    if (length <= 0) {
        return {};
    }

    zend_string *string_key;
    zend_ulong num_key;
    zval *entry;

    zval return_value;
    array_init_size(&return_value, (uint32_t) length);

    /* Start at the beginning and go until we hit offset */
    int pos = 0;
    if (!preserve_keys && (Z_ARRVAL_P(zarr)->u.flags & HASH_FLAG_PACKED)) {
        zend_hash_real_init(Z_ARRVAL_P(&return_value), true);
        ZEND_HASH_FILL_PACKED(Z_ARRVAL_P(&return_value)) {
            ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(zarr), entry) {
                pos++;
                if (pos <= offset) {
                    continue;
                }
                if (pos > offset + length) {
                    break;
                }
                ZEND_HASH_FILL_ADD(entry);
                zval_add_ref(entry);
            }
            ZEND_HASH_FOREACH_END();
        }
        ZEND_HASH_FILL_END();
    } else {
        ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(zarr), num_key, string_key, entry) {
            pos++;
            if (pos <= offset) {
                continue;
            }
            if (pos > offset + length) {
                break;
            }

            if (string_key) {
                entry = zend_hash_add_new(Z_ARRVAL_P(&return_value), string_key, entry);
            } else {
                if (preserve_keys) {
                    entry = zend_hash_index_add_new(Z_ARRVAL_P(&return_value), num_key, entry);
                } else {
                    entry = zend_hash_next_index_insert_new(Z_ARRVAL_P(&return_value), entry);
                }
            }
            zval_add_ref(entry);
        }
        ZEND_HASH_FOREACH_END();
    }
    return Array(&return_value, false, false);
}

Array::Array(const zval *v, bool indirect, bool copy) : Variant(v, indirect, copy) {
    if (isNull()) {
        array_init(ptr());
    } else {
        zval *zarray = unwrap_ptr();
        if (Z_TYPE_P(zarray) != IS_ARRAY) {
            error(E_ERROR, "parameter 1 must be `array`, got `%s`", typeStr());
        }
    }
}

Array::Array(const Variant &v) : Array(v.const_ptr()) {}

void Array::copyFrom(const std::initializer_list<const Variant> &list) {
    for (const auto &val : list) {
        append(val);
    }
}

void Array::copyFrom(const std::initializer_list<std::pair<const std::string, const Variant>> &list) {
    for (const auto &kv : list) {
        set(String(kv.first), kv.second);
    }
}

void Array::copyFrom(const std::initializer_list<std::pair<Int, const Variant>> &list) {
    for (const auto &kv : list) {
        set(kv.first, kv.second);
    }
}

Array::Array(const std::initializer_list<const Variant> &list) {
    array_init(&val);
    copyFrom(list);
}

Array::Array(const std::initializer_list<std::pair<const std::string, const Variant>> &list) {
    array_init(&val);
    copyFrom(list);
}

Array::Array(const std::initializer_list<std::pair<Int, const Variant>> &list) {
    array_init(&val);
    copyFrom(list);
}

Array &Array::operator=(const std::initializer_list<const Variant> &list) {
    destroy();
    auto zarr = unwrap_ptr();
    array_init(zarr);
    copyFrom(list);
    return *this;
}

Array &Array::operator=(const std::initializer_list<std::pair<const std::string, const Variant>> &list) {
    destroy();
    auto zarr = unwrap_ptr();
    array_init(zarr);
    copyFrom(list);
    return *this;
}

Array &Array::operator=(const std::initializer_list<std::pair<Int, const Variant>> &list) {
    destroy();
    auto zarr = unwrap_ptr();
    array_init(zarr);
    copyFrom(list);
    return *this;
}

void Array::set(const Variant &key, const Variant &v) {
    if (key.isNull()) {
        append(v);
    } else if (key.isInt() || key.isFloat()) {
        set(key.toInt(), v);
    } else {
        auto zv = NO_CONST_V(v);
        Z_TRY_ADDREF_P(zv);
        auto zarr = unwrap_ptr();
        SEPARATE_ARRAY(zarr);
        auto skey = key.toString();
        zend_symtable_update(Z_ARRVAL_P(zarr), skey.str(), zv);
    }
}

void Array::set(zend_ulong i, const Variant &v) {
    auto zv = NO_CONST_V(v);
    Z_TRY_ADDREF_P(zv);

    auto zarr = unwrap_ptr();
    SEPARATE_ARRAY(zarr);
    add_index_zval(zarr, i, zv);
}

bool Array::del(zend_ulong index) {
    auto zarr = unwrap_ptr();
    SEPARATE_ARRAY(zarr);
    return zend_hash_index_del(Z_ARRVAL_P(zarr), index) == SUCCESS;
}

bool Array::del(const Variant &key) {
    if (key.isInt() || key.isFloat()) {
        return del(key.toInt());
    } else {
        auto zarr = unwrap_ptr();
        SEPARATE_ARRAY(zarr);
        auto skey = key.toString();
        return zend_symtable_del(Z_ARRVAL_P(zarr), skey.str()) == SUCCESS;
    }
}

Variant Array::search(const Variant &_other_var, bool strict) const {
    for (auto i = begin(); i != end(); i++) {
        if (i.value().equals(_other_var, strict)) {
            return i.key();
        }
    }
    return false;
}

bool Array::contains(const Variant &_other_var, bool strict) const {
    for (auto i = begin(); i != end(); i++) {
        if (i.value().equals(_other_var, strict)) {
            return true;
        }
    }
    return false;
}

String Array::join(const String &delim) {
    zval retval;
    php_implode(delim.str(), HASH_OF(unwrap_ptr()), &retval);
    return String::from(&retval);
}

Variant ArrayIterator::key() const {
    if (HT_IS_PACKED(array_)) {
        return (zend_long) idx_;
    } else {
        auto *bucket = HT_HASH_TO_BUCKET(array_, idx_);
        if (bucket->key) {
            return {bucket->key};
        } else {
            return {static_cast<zend_long>(bucket->h)};
        }
    }
}

void ArrayIterator::skipUndefBucket() {
    while (idx_ < array_->nNumUsed) {
        zval *cur = current();
        if (!cur || Z_TYPE_P(cur) == IS_UNDEF) {
            ++idx_;
            continue;
        }
        break;
    }
}

ArrayItem::ArrayItem(Array &_array, zend_ulong _index, const String &_key) : array_(_array), index_(_index) {
    zval *value_;
    key_ = _key;
    zend_array *ht = array_.unwrap_array();

    if (key_.str() != zend_empty_string) {
        value_ = zend_symtable_find(ht, key_.str());
    } else {
        value_ = zend_hash_index_find(ht, index_);
    }
    if (value_) {
        val = *value_;
        addRef();
    } else {
        ZVAL_NULL(&val);
    }
}

ArrayItem &ArrayItem::operator=(const Variant &v) {
    const auto zv = NO_CONST_V(v);
    Z_TRY_ADDREF_P(zv);
    zend_array *ht = array_.unwrap_array();

    if (key_.str() != zend_empty_string) {
        zend_symtable_update(ht, key_.str(), zv);
    } else {
        zend_hash_index_update(ht, index_, zv);
    }

    return *this;
}

Array to_array(const Variant &v) {
    zval result;
    zval *expr = NO_CONST_V(v);

    if (v.isArray()) {
        return Array(expr);
    }

    if (Z_TYPE_P(expr) != IS_OBJECT || Z_OBJCE_P(expr) == zend_ce_closure) {
        if (Z_TYPE_P(expr) != IS_NULL) {
            ZVAL_ARR(&result, zend_new_array(1));
            expr = zend_hash_index_add_new(Z_ARRVAL(result), 0, expr);
            if (IS_CONST == IS_CONST) {
                if (UNEXPECTED(Z_OPT_REFCOUNTED_P(expr))) Z_ADDREF_P(expr);
            } else {
                if (Z_OPT_REFCOUNTED_P(expr)) Z_ADDREF_P(expr);
            }
        } else {
            ZVAL_EMPTY_ARRAY(&result);
        }
    } else if (Z_OBJ_P(expr)->properties == NULL && Z_OBJ_HT_P(expr)->get_properties_for == NULL &&
               Z_OBJ_HT_P(expr)->get_properties == zend_std_get_properties) {
        /* Optimized version without rebuilding properties HashTable */
        ZVAL_ARR(&result, zend_std_build_object_properties_array(Z_OBJ_P(expr)));
    } else {
        HashTable *obj_ht = zend_get_properties_for(expr, ZEND_PROP_PURPOSE_ARRAY_CAST);
        if (obj_ht) {
            /* fast copy */
            ZVAL_ARR(&result,
                     zend_proptable_to_symtable(
                         obj_ht,
                         (Z_OBJCE_P(expr)->default_properties_count ||
                          Z_OBJ_P(expr)->handlers != &std_object_handlers || GC_IS_RECURSIVE(obj_ht))));
            zend_release_properties(obj_ht);
        } else {
            ZVAL_EMPTY_ARRAY(&result);
        }
    }
    return Array(&result, false, false);
}
}  // namespace php
