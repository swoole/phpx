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
#include "func/core.h"

namespace php {

ForeachIterator::ForeachIterator(const Variant &iterable, bool by_ref)
    : iterable_(iterable.const_ptr(), Ctor::CopyRef), by_ref_(by_ref) {
    if (iterable_.isArray()) {
        array_ = Variant(iterable_.const_ptr(), Ctor::CopyRef);
        mode_ = Mode::Array;
        return;
    }

    if (UNEXPECTED(!iterable_.isObject())) {
        throwException(zend_ce_type_error, "foreach() argument must be of type array|object");
        return;
    }

    if (UNEXPECTED(by_ref_)) {
        throwException(zend_ce_error, "Cannot use & with foreach");
        return;
    }

    zend_class_entry *ce = Z_OBJCE_P(iterable_.unwrap_ptr());
    if (ce->get_iterator) {
        object_iterator_ = ce->get_iterator(ce, iterable_.direct_ptr(), by_ref_ ? 1 : 0);
        if (UNEXPECTED(!object_iterator_) || UNEXPECTED(EG(exception))) {
            if (object_iterator_) {
                OBJ_RELEASE(&object_iterator_->std);
                object_iterator_ = nullptr;
            }
            if (!EG(exception)) {
                throwExceptionEx(zend_ce_exception,
                                 0,
                                 "Object of type %s did not create an Iterator",
                                 ZSTR_VAL(ce->name));
            } else {
                throwErrorIfOccurred();
            }
            return;
        }

        object_iterator_->index = static_cast<zend_ulong>(-1);
        if (object_iterator_->funcs->rewind) {
            object_iterator_->funcs->rewind(object_iterator_);
            if (UNEXPECTED(EG(exception))) {
                OBJ_RELEASE(&object_iterator_->std);
                object_iterator_ = nullptr;
                throwErrorIfOccurred();
                return;
            }
        }
        mode_ = Mode::Object;
        return;
    }

    array_ = get_object_vars(iterable_);
    mode_ = Mode::Array;
}

ForeachIterator::~ForeachIterator() {
    if (object_iterator_) {
        OBJ_RELEASE(&object_iterator_->std);
    }
}

bool ForeachIterator::nextArray() {
    zend_array *array = Z_ARRVAL_P(array_.unwrap_ptr());
    if (HT_IS_PACKED(array)) {
        while (position_ < array->nNumUsed) {
            zend_ulong index = position_++;
            zval *value = array->arPacked + index;
            if (UNEXPECTED(Z_TYPE_P(value) == IS_UNDEF)) {
                continue;
            }
            key_ = static_cast<zend_long>(index);
            value_ = value;
            return true;
        }
        value_ = nullptr;
        return false;
    }

    while (position_ < array->nNumUsed) {
        Bucket *bucket = array->arData + position_++;
        if (UNEXPECTED(Z_TYPE(bucket->val) == IS_UNDEF)) {
            continue;
        }

        if (bucket->key) {
            key_ = bucket->key;
        } else {
            key_ = static_cast<zend_long>(bucket->h);
        }
        value_ = &bucket->val;
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
    if (!value_) {
        return false;
    }

    if (funcs->get_current_key) {
        zval current_key;
        ZVAL_UNDEF(&current_key);
        funcs->get_current_key(object_iterator_, &current_key);
        if (UNEXPECTED(EG(exception))) {
            if (!Z_ISUNDEF(current_key)) {
                zval_ptr_dtor(&current_key);
            }
            throwErrorIfOccurred();
            return false;
        }
        key_ = &current_key;
        zval_ptr_dtor(&current_key);
    } else {
        key_ = static_cast<zend_long>(object_iterator_->index);
    }
    return true;
}

bool ForeachIterator::next() {
    switch (mode_) {
    case Mode::Array:
        return nextArray();
    case Mode::Object:
        return nextObject();
    default:
        return false;
    }
}

Variant ForeachIterator::key() const {
    return key_;
}

Variant ForeachIterator::value() const {
    return Variant(value_);
}

Reference ForeachIterator::valueRef() {
    if (UNEXPECTED(mode_ != Mode::Array) || UNEXPECTED(!value_)) {
        throwException(zend_ce_error, "Cannot use & with foreach");
        return {};
    }
    Variant value(value_, Ctor::Indirect);
    return value.toReference();
}

}  // namespace php
