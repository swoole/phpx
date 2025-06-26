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
  | Author: Tianfeng Han  <mikan.tenny@gmail.com>                        |
  +----------------------------------------------------------------------+
*/

#include "phpx.h"

using namespace std;

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
    size_t num_in = count();

    if (offset > num_in) {
        return Array();
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
    if (!preserve_keys && (Z_ARRVAL_P(this->ptr())->u.flags & HASH_FLAG_PACKED)) {
        zend_hash_real_init(Z_ARRVAL_P(&return_value), 1);
        ZEND_HASH_FILL_PACKED(Z_ARRVAL_P(&return_value)) {
            ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(this->ptr()), entry) {
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
        ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(this->ptr()), num_key, string_key, entry) {
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
    Array retval(&return_value);
    zval_ptr_dtor(&return_value);
    return retval;
}

Array::Array(zval *v) : Variant(v) {
    if (isReference()) {
        zval_delref_p(&val);
        ZVAL_COPY(&val, Z_REFVAL_P(&val));
    }
    if (isNull()) {
        array_init(ptr());
    } else if (!isArray()) {
        error(E_ERROR, "parameter 1 must be zend_array.");
    }
}

Array::Array(const Variant &v) {
    reference = v.isZvalRef();

    zval *zv = const_cast<Variant &>(v).ptr();
    if (Z_TYPE_P(zv) == IS_REFERENCE) {
        zv = Z_REFVAL_P(zv);
    }
    if (reference) {
        ref_val = zv;
    } else {
        memcpy(&val, zv, sizeof(*zv));
        addRef();
    }
    if (isNull()) {
        array_init(ptr());
    } else if (!isArray()) {
        error(E_ERROR, "parameter 1 must be zend_array.");
    }
#ifdef HT_ALLOW_COW_VIOLATION
    HT_ALLOW_COW_VIOLATION(Z_ARRVAL_P(ptr()));
#endif
}

Array::Array(const std::initializer_list<const Variant> &list) {
    array_init(&val);
    for (const auto& val : list) {
        append(val);
    }
}

Array::Array(const std::initializer_list<std::pair<const std::string, const Variant>> &list) {
    array_init(&val);
    for (const auto& kv : list) {
        set(kv.first, kv.second);
    }
}

Array::Array(const std::initializer_list<std::pair<Int, const Variant>> &list) {
    array_init(&val);
    for (const auto& kv : list) {
        set(kv.first, kv.second);
    }
}
}  // namespace php
