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

namespace php {

ForeachIterator::ForeachIterator(const Variant &iterable, bool by_ref, zend_class_entry *scope)
    : scope_(scope), by_ref_(by_ref) {
    if (iterable.isArray()) {
        if (by_ref_) {
            zval *array_ref = const_cast<Variant &>(iterable).direct_ptr();
            zval *array = array_ref;
            if (Z_ISREF_P(array_ref)) {
                array = Z_REFVAL_P(array_ref);
            } else {
                ZVAL_NEW_REF(array_ref, array_ref);
                array = Z_REFVAL_P(array_ref);
            }
            SEPARATE_ARRAY(array);

            Variant owner(array_ref, Ctor::CopyRef);
            iterable_.rebindReference(owner);
            hash_table_ = Z_ARRVAL_P(iterable_.unwrap_ptr());
            hash_iterator_ = zend_hash_iterator_add(hash_table_, 0);
            mode_ = Mode::HashTable;
        } else {
            array_ = Variant(iterable.unwrap_ptr(), Ctor::CopyRef);
            mode_ = Mode::ArraySnapshot;
        }
        return;
    }

    if (UNEXPECTED(!iterable.isObject())) {
        throwExceptionEx(zend_ce_type_error,
                         0,
                         "foreach() argument must be of type array|object, %s given",
                         zend_zval_type_name(iterable.unwrap_ptr()));
        return;
    }

    iterable_ = Variant(iterable.const_ptr(), Ctor::CopyRef);
    zend_object *object = Z_OBJ_P(iterable_.unwrap_ptr());
    zend_class_entry *ce = object->ce;
    if (ce->get_iterator) {
        object_iterator_ = ce->get_iterator(ce, iterable_.direct_ptr(), by_ref_ ? 1 : 0);
        if (UNEXPECTED(!object_iterator_) || UNEXPECTED(EG(exception))) {
            if (object_iterator_) {
                zend_iterator_dtor(object_iterator_);
                object_iterator_ = nullptr;
            }
            if (!EG(exception)) {
                throwExceptionEx(
                    zend_ce_exception, 0, "Object of type %s did not create an Iterator", ZSTR_VAL(ce->name));
            } else {
                throwErrorIfOccurred();
            }
            return;
        }

        object_iterator_->index = static_cast<zend_ulong>(-1);
        if (object_iterator_->funcs->rewind) {
            try {
                object_iterator_->funcs->rewind(object_iterator_);
            } catch (zend_object *exception) {
                zend_iterator_dtor(object_iterator_);
                object_iterator_ = nullptr;
                throw exception;
            }
            if (UNEXPECTED(EG(exception))) {
                zend_iterator_dtor(object_iterator_);
                object_iterator_ = nullptr;
                throwErrorIfOccurred();
                return;
            }
        }
        mode_ = Mode::ObjectIterator;
        return;
    }

    HashTable *properties = object->properties;
    if (properties) {
        if (UNEXPECTED(GC_REFCOUNT(properties) > 1) && EXPECTED(!(GC_FLAGS(properties) & IS_ARRAY_IMMUTABLE))) {
            GC_DELREF(properties);
            properties = object->properties = zend_array_dup(properties);
        }
    } else {
        properties = object->handlers->get_properties(object);
    }

    hash_table_ = properties;
    hash_iterator_ = zend_hash_iterator_add(hash_table_, 0);
    plain_object_ = true;
    mode_ = Mode::HashTable;
}

ForeachIterator::~ForeachIterator() {
    if (hash_iterator_ != UINT32_MAX) {
        zend_hash_iterator_del(hash_iterator_);
    }
    if (object_iterator_) {
        zend_iterator_dtor(object_iterator_);
    }
}

bool ForeachIterator::nextArraySnapshot() {
    zend_array *array = Z_ARRVAL_P(array_.unwrap_ptr());
    if (HT_IS_PACKED(array)) {
        while (position_ < array->nNumUsed) {
            zend_ulong index = position_++;
            zval *value = array->arPacked + index;
            if (UNEXPECTED(Z_TYPE_P(value) == IS_UNDEF)) {
                continue;
            }
            current_position_ = index;
            value_ = value;
            return true;
        }
        value_ = nullptr;
        return false;
    }

    while (position_ < array->nNumUsed) {
        zend_ulong index = position_++;
        Bucket *bucket = array->arData + index;
        if (UNEXPECTED(Z_TYPE(bucket->val) == IS_UNDEF)) {
            continue;
        }
        current_position_ = index;
        value_ = &bucket->val;
        return true;
    }

    value_ = nullptr;
    return false;
}

bool ForeachIterator::isPropertyVisible(const Bucket *bucket, const zval *value) const {
    if (!plain_object_ || !bucket->key || ZSTR_VAL(bucket->key)[0] != '\0') {
        return true;
    }
    if (!scope_) {
        return false;
    }

    zend_object *object = Z_OBJ_P(iterable_.unwrap_ptr());
    zend_property_info *property_info = zend_get_property_info_for_slot(object, const_cast<zval *>(value));
    if (!property_info) {
        return false;
    }
    if (property_info->flags & ZEND_ACC_PUBLIC) {
        return true;
    }
    if (property_info->flags & ZEND_ACC_PRIVATE) {
        return property_info->ce == scope_;
    }
    return zend_check_protected(property_info->ce, scope_);
}

bool ForeachIterator::nextHashTable() {
    declared_property_ = false;
    HashPosition position = zend_hash_iterator_pos(hash_iterator_, hash_table_);
    if (HT_IS_PACKED(hash_table_)) {
        while (position < hash_table_->nNumUsed) {
            zend_ulong index = position++;
            zval *value = hash_table_->arPacked + index;
            if (UNEXPECTED(Z_TYPE_P(value) == IS_UNDEF)) {
                continue;
            }
            EG(ht_iterators)[hash_iterator_].pos = position;
            current_position_ = index;
            value_ = value;
            return true;
        }
        value_ = nullptr;
        return false;
    }

    while (position < hash_table_->nNumUsed) {
        zend_ulong index = position++;
        Bucket *bucket = hash_table_->arData + index;
        zval *value = &bucket->val;
        if (UNEXPECTED(Z_TYPE_P(value) == IS_UNDEF)) {
            continue;
        }
        if (plain_object_ && Z_TYPE_P(value) == IS_INDIRECT) {
            value = Z_INDIRECT_P(value);
            if (UNEXPECTED(Z_TYPE_P(value) == IS_UNDEF) || UNEXPECTED(!isPropertyVisible(bucket, value))) {
                continue;
            }
            declared_property_ = true;
        } else if (UNEXPECTED(!isPropertyVisible(bucket, value))) {
            continue;
        }

        EG(ht_iterators)[hash_iterator_].pos = position;
        current_position_ = index;
        value_ = value;
        return true;
    }

    value_ = nullptr;
    return false;
}

bool ForeachIterator::nextObject() {
    const zend_object_iterator_funcs *funcs = object_iterator_->funcs;
    if (started_) {
        ++object_iterator_->index;
        funcs->move_forward(object_iterator_);
        if (UNEXPECTED(EG(exception))) {
            throwErrorIfOccurred();
            return false;
        }
    } else {
        started_ = true;
        object_iterator_->index = 0;
    }

    if (funcs->valid(object_iterator_) != SUCCESS) {
        if (UNEXPECTED(EG(exception))) {
            throwErrorIfOccurred();
        }
        value_ = nullptr;
        return false;
    }

    value_ = funcs->get_current_data(object_iterator_);
    if (UNEXPECTED(EG(exception))) {
        throwErrorIfOccurred();
        return false;
    }
    return value_ != nullptr;
}

bool ForeachIterator::next() {
    key_ready_ = false;
    switch (mode_) {
    case Mode::ArraySnapshot:
        return nextArraySnapshot();
    case Mode::HashTable:
        return nextHashTable();
    case Mode::ObjectIterator:
        return nextObject();
    default:
        return false;
    }
}

Variant ForeachIterator::getHashKey() const {
    if (HT_IS_PACKED(hash_table_ ? hash_table_ : Z_ARRVAL_P(array_.unwrap_ptr()))) {
        return static_cast<zend_long>(current_position_);
    }

    HashTable *table = hash_table_ ? hash_table_ : Z_ARRVAL_P(array_.unwrap_ptr());
    const Bucket *bucket = table->arData + current_position_;
    if (!bucket->key) {
        return static_cast<zend_long>(bucket->h);
    }
    if (!plain_object_ || ZSTR_VAL(bucket->key)[0] != '\0') {
        return bucket->key;
    }

    const char *class_name;
    const char *property_name;
    size_t property_name_length;
    zend_unmangle_property_name_ex(bucket->key, &class_name, &property_name, &property_name_length);
    return Variant(property_name, property_name_length);
}

Variant ForeachIterator::key() {
    if (key_ready_) {
        return key_;
    }

    if (mode_ == Mode::ArraySnapshot || mode_ == Mode::HashTable) {
        key_ = getHashKey();
    } else if (mode_ == Mode::ObjectIterator) {
        const zend_object_iterator_funcs *funcs = object_iterator_->funcs;
        if (funcs->get_current_key) {
            zval current_key;
            ZVAL_UNDEF(&current_key);
            funcs->get_current_key(object_iterator_, &current_key);
            if (UNEXPECTED(EG(exception))) {
                if (!Z_ISUNDEF(current_key)) {
                    zval_ptr_dtor(&current_key);
                }
                throwErrorIfOccurred();
                return {};
            }
            key_ = &current_key;
            zval_ptr_dtor(&current_key);
        } else {
            key_ = static_cast<zend_long>(object_iterator_->index);
        }
    } else {
        return {};
    }

    key_ready_ = true;
    return key_;
}

Variant ForeachIterator::value() const {
    return Variant(value_);
}

Reference ForeachIterator::valueRef() {
    if (UNEXPECTED(!by_ref_) || UNEXPECTED(!value_)) {
        throwException(zend_ce_error, "Cannot use & with foreach");
        return {};
    }

    zend_property_info *property_info = nullptr;
    if (declared_property_ && Z_TYPE_P(value_) != IS_REFERENCE) {
        property_info = zend_get_property_info_for_slot(Z_OBJ_P(iterable_.unwrap_ptr()), value_);
        if (property_info && UNEXPECTED(property_info->flags & ZEND_ACC_READONLY)) {
            throwExceptionEx(zend_ce_error,
                             0,
                             "Cannot acquire reference to readonly property %s::$%s",
                             ZSTR_VAL(property_info->ce->name),
                             ZSTR_VAL(property_info->name));
            return {};
        }
    }

    Variant value(value_, Ctor::Indirect);
    Reference reference = value.toReference();
    if (property_info && ZEND_TYPE_IS_SET(property_info->type)) {
        ZEND_REF_ADD_TYPE_SOURCE(Z_REF_P(value_), property_info);
    }
    return reference;
}

void ForeachIterator::assignValueRef(Variant &target) {
    Reference reference = valueRef();
    target.rebindReference(reference);
}

}  // namespace php
