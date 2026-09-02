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
#include "phpx_fake_scope_guard.h"

BEGIN_EXTERN_C()
#include "zend_smart_str.h"
#include <ext/spl/php_spl.h>
END_EXTERN_C()

#include <cmath>

namespace php {
Variant null = {};
Object null_object;
Int zero = 0L;
Variant true_ = true;
Variant false_ = false;

Variant::Variant(const Reference *ref) {
    val = *ref->const_ptr();
    addRef();
}

void Variant::copyFrom(const zval *src) {
    if (UNEXPECTED(isByteOfStr())) {
        if (!zval_is_string(src) || Z_STRLEN_P(src) != 1) {
            throwError("Can only be assigned a single-byte string to a string offset");
        } else {
            setByteOfStr(Z_STRVAL_P(src)[0]);
        }
    } else {
        if (UNEXPECTED(isReference() && ZEND_REF_HAS_TYPE_SOURCES(Z_REF_P(ptr())))) {
            zval value;
            zval_copy(&value, src);
            if (UNEXPECTED(zend_try_assign_typed_ref(Z_REF_P(ptr()), &value) == FAILURE)) {
                throwErrorIfOccurred();
            }
            return;
        }
        auto zv = unwrap_ptr();
        zval tmp = *zv;
        zval_copy(zv, src);
        zval_ptr_dtor(&tmp);
        throwErrorIfOccurred();
    }
}

void Variant::copyRef(Variant *v) {
    zval *source = v->direct_ptr();
    zval replacement;
    if (v->isReference()) {
        zval_copy(&replacement, source);
    } else {
        ZVAL_NEW_REF(&replacement, source);
        zval_copy_value(source, &replacement);
        zval_try_add_ref(source);
    }

    // Reference assignment rebinds the destination slot. It must release the
    // old reference wrapper itself rather than destroy only its dereferenced
    // value. ZVAL_COPY_VALUE preserves HashTable bucket metadata when target
    // is an indirect array element and also makes self-rebinding safe.
    zval *target = direct_ptr();
    zval old;
    ZVAL_COPY_VALUE(&old, target);
    ZVAL_COPY_VALUE(target, &replacement);
    zval_ptr_dtor(&old);
    throwErrorIfOccurred();
}

Variant &Variant::operator=(const zval *v) {
    copyFrom(unwrap_zval(v));
    return *this;
}

Variant &Variant::operator=(const Variant &v) {
    if (&v != this) {
        copyFrom(v.unwrap_ptr());
    }
    return *this;
}

Variant &Variant::operator=(Variant &&v) {
    if (&v == this) {
        return *this;
    }

    // PHP assignment must update indirect values and references rather than
    // rebind their wrappers. These cases deliberately retain copy semantics,
    // including typed-reference validation performed by copyFrom().
    if (isIndirect() || isReference() || v.isIndirect() || v.isReference()) {
        copyFrom(v.unwrap_ptr());
        return *this;
    }

    // Both wrappers own ordinary zvals, so ownership can be transferred
    // without changing PHP reference semantics or touching refcounts.
    zval old = val;
    zval_copy_value(&val, &v.val);
    ZVAL_UNDEF(&v.val);
    zval_ptr_dtor(&old);
    throwErrorIfOccurred();
    return *this;
}

Variant &Variant::operator=(Variant *v) {
    copyRef(v);
    return *this;
}

void Variant::moveTo(zval *dest) {
    if (dest == &val) {
        return;
    }

    if (isIndirect()) {
        zval *source = direct_ptr();
        if (dest != source) {
            zval_copy(dest, source);
        }
        ZVAL_UNDEF(&val);
        return;
    }

    zval_copy_value(dest, &val);
    ZVAL_UNDEF(&val);
}

void Variant::rebindReference(const Variant &reference) {
    if (UNEXPECTED(!reference.isReference())) {
        throwError("Expected a reference, got %s", reference.typeStr());
        return;
    }
    if (UNEXPECTED(isIndirect())) {
        throwError("Cannot rebind an indirect value");
        return;
    }

    zval old = val;
    zval_copy(&val, reference.const_ptr());
    zval_ptr_dtor(&old);
    throwErrorIfOccurred();
}

std::string Variant::toStdString() const {
    zend_string *str = zval_get_string(NO_CONST_Z(unwrap_ptr()));
    if (UNEXPECTED(EG(exception) != nullptr)) {
        zend_string_release(str);
        throwErrorIfOccurred();
        return {};
    }
    auto retval = std::string(ZSTR_VAL(str), ZSTR_LEN(str));
    zend_string_release(str);
    return retval;
}

String Variant::toString() const {
    zend_string *str = zval_get_string(NO_CONST_Z(unwrap_ptr()));
    if (UNEXPECTED(EG(exception) != nullptr)) {
        zend_string_release(str);
        throwErrorIfOccurred();
        return {};
    }
    return String(str, Ctor::Move);
}

Reference Variant::toReference() {
    if (isReference()) {
        return Reference{direct_ptr(), Ctor::CopyRef};
    } else {
        Variant tmp{this};
        return Reference{tmp.const_ptr()};
    }
}

Array Variant::toArray() const {
    return Array(unwrap_ptr());
}

Object Variant::toObject() const {
    return Object(unwrap_ptr());
}

size_t Variant::length() const {
    auto zv = unwrap_ptr();
    if (zval_is_string(zv)) {
        return Z_STRLEN_P(zv);
    } else if (zval_is_array(zv)) {
        return zend_hash_num_elements(Z_ARRVAL_P(zv));
    } else if (zval_is_object(zv)) {
        Object tmp(zv, Ctor::Indirect);
        return tmp.count();
    } else {
        return 0;
    }
}

void Variant::unset() {
    const bool indirect = isIndirect();
    zval *target = indirect ? Z_INDIRECT(val) : &val;
    zval old;
    ZVAL_COPY_VALUE(&old, target);
    if (indirect) {
        // HashTable buckets store their collision-chain link in zval.u2.
        ZVAL_UNDEF(target);
    }
    val = {};
    zval_ptr_dtor(&old);
    throwErrorIfOccurred();
}

Variant::~Variant() {
    if (!isIndirect()) {
        zval_ptr_dtor(&val);
    }
}

bool Variant::isNumeric() const {
    auto zv = unwrap_ptr();
    switch (Z_TYPE_P(zv)) {
    case IS_LONG:
    case IS_DOUBLE:
        return true;
    case IS_STRING:
        return is_numeric_string(Z_STRVAL_P(zv), Z_STRLEN_P(zv), nullptr, nullptr, false);
    default:
        return false;
    }
}

#if ZEND_DEBUG
void Variant::debug() {
    printf("zval=%p, type=%d, refcount=%d, is_ref=%d\n", const_ptr(), type(), getRefCount(), isReference());
    const zval *_val;
    if (isReference()) {
        _val = Z_REFVAL_P(const_ptr());
        printf("ref=%p, rc=%d\n", Z_REF_P(const_ptr()), Z_REFCOUNT_P(const_ptr()));
    } else {
        _val = const_ptr();
    }
    if (Z_TYPE_P(_val) == IS_NULL) {
        printf("value=null\n");
    } else if (Z_TYPE_P(_val) == IS_UNDEF) {
        printf("value=undefined\n");
    } else if (Z_TYPE_P(_val) == IS_FALSE) {
        printf("value=false\n");
    } else if (Z_TYPE_P(_val) == IS_TRUE) {
        printf("value=true\n");
    } else if (Z_TYPE_P(_val) == IS_LONG) {
        printf("value=" ZEND_LONG_FMT "\n", Z_LVAL_P(_val));
    } else if (Z_TYPE_P(_val) == IS_DOUBLE) {
        printf("value=%f\n", Z_DVAL_P(_val));
    } else if (Z_TYPE_P(_val) == IS_STRING) {
        printf("value=\"%.*s\"\n", (int) Z_STRLEN_P(_val), Z_STRVAL_P(_val));
    } else if (Z_TYPE_P(_val) == IS_ARRAY) {
        printf("array[rc=%d]=%p, count=%u\n",
               Z_REFCOUNT_P(_val),
               Z_ARRVAL_P(_val),
               zend_hash_num_elements(Z_ARRVAL_P(_val)));
    } else if (Z_TYPE_P(_val) == IS_OBJECT) {
        printf("object[rc=%d]=%p, class=%s\n", Z_REFCOUNT_P(_val), Z_OBJ_P(_val), ZSTR_VAL(Z_OBJCE_P(_val)->name));
    } else if (Z_TYPE_P(_val) == IS_RESOURCE) {
        printf("resource=%p, type=%d\n", Z_RES_P(_val), Z_RES_P(_val)->type);
    }
}
#else
void Variant::debug() {
    php_debug_zval_dump(unwrap_ptr(), 10);
}
#endif

void Variant::print() const {
    php_var_dump((zval *) unwrap_ptr(), 10);
}

int Variant::getRefCount() const {
    auto zv = const_ptr();
    ZVAL_DEINDIRECT(zv);
    if (Z_REFCOUNTED_P(zv)) {
        return Z_REFCOUNT_P(zv);
    }
    return 0;
}

Variant Variant::getRefValue() const {
    if (!isReference()) {
        return *this;
    }
    zval zv;
    zval_copy_value(&zv, Z_REFVAL_P(const_ptr()));
    return {&zv};
}

Variant Variant::offsetGet(zend_long offset) const {
    auto zvar = unwrap_ptr();

    if (zval_is_array(zvar)) {
        return zend_hash_index_find(Z_ARRVAL_P(zvar), offset);
    } else if (zval_is_string(zvar)) {
        String tmp(zvar, Ctor::Indirect);
        return tmp.offsetGet(offset);
    } else if (zval_is_object(zvar)) {
        Object tmp(zvar);
        return tmp.offsetGet(offset);
    } else {
        return Variant{};
    }
}

Variant Variant::offsetGet(const Variant &key) const {
    if (key.isInt()) {
        return offsetGet(key.toInt());
    }

    auto zvar = unwrap_ptr();
    if (zval_is_string(zvar)) {
        String tmp(zvar, Ctor::Indirect);
        return tmp.offsetGet(key.toInt());
    } else if (zval_is_array(zvar)) {
        auto skey = key.toString();
        Array tmp(zvar);
        return tmp.get(skey);
    } else if (zval_is_object(zvar)) {
        Object tmp(zvar);
        return tmp.offsetGet(key);
    } else {
        return Variant{};
    }
}

bool Variant::offsetExists(zend_long offset) const {
    auto zvar = unwrap_ptr();

    if (zval_is_array(zvar)) {
        return zend_hash_index_exists(Z_ARRVAL_P(zvar), offset);
    } else if (zval_is_string(zvar)) {
        String tmp(zvar, Ctor::Indirect);
        return tmp.offset(offset) != -1;
    } else if (zval_is_object(zvar)) {
        Object tmp(zvar);
        return tmp.offsetExists(offset);
    } else {
        return false;
    }
}

bool Variant::offsetExists(const Variant &key) const {
    if (key.isInt() || key.isFloat()) {
        return offsetExists(key.toInt());
    }

    auto zvar = unwrap_ptr();
    if (zval_is_string(zvar)) {
        if (!key.isBool() && !key.isNumeric()) {
            return false;
        }
        String tmp(zvar, Ctor::Indirect);
        return tmp.offset(key.toInt()) != -1;
    } else if (zval_is_array(zvar)) {
        auto skey = key.toString();
        return zend_symtable_exists(Z_ARRVAL_P(zvar), skey.str());
    } else if (zval_is_object(zvar)) {
        Object tmp(zvar);
        return tmp.offsetExists(key);
    } else {
        return false;
    }
}

void Variant::offsetSet(zend_long offset, const Variant &value) {
    auto zvar = unwrap_ptr();

    if (Z_TYPE_P(zvar) == IS_UNDEF || Z_TYPE_P(zvar) == IS_NULL) {
        array_init(zvar);
    }

    if (zval_is_array(zvar)) {
        Array tmp(zvar, Ctor::Indirect);
        tmp.set(offset, value);
    } else if (zval_is_object(zvar)) {
        Object tmp(zvar);
        tmp.offsetSet(offset, NO_CONST_V(value));
    } else if (zval_is_string(zvar)) {
        String tmp(zvar, Ctor::Indirect);
        tmp.offsetSet(offset, value);
    }
}

void Variant::offsetSet(const Variant &key, const Variant &value) {
    auto zvar = unwrap_ptr();

    if (Z_TYPE_P(zvar) == IS_UNDEF || Z_TYPE_P(zvar) == IS_NULL) {
        array_init(zvar);
    }

    if (zval_is_array(zvar)) {
        Array tmp(zvar, Ctor::Indirect);
        tmp.set(key, value);
    } else if (zval_is_object(zvar)) {
        Object tmp(zvar);
        tmp.offsetSet(key, value);
    } else if (zval_is_string(zvar)) {
        if (key.isNull()) {
            throwError("[] operator not supported for strings");
        }
        String tmp(zvar, Ctor::Indirect);
        tmp.offsetSet(key.toInt(), value);
    }
}

void Variant::offsetUnset(zend_long offset) {
    auto zvar = unwrap_ptr();

    if (zval_is_array(zvar)) {
        Array tmp(zvar, Ctor::Indirect);
        tmp.del(offset);
    } else if (zval_is_object(zvar)) {
        Object tmp(zvar);
        tmp.offsetUnset(offset);
    } else {
        throwError("Cannot unset offsets");
    }
}

void Variant::offsetUnset(const Variant &key) {
    auto zvar = unwrap_ptr();

    if (zval_is_array(zvar)) {
        Array tmp(zvar, Ctor::Indirect);
        tmp.del(key);
    } else if (zval_is_object(zvar)) {
        Object tmp(zvar);
        tmp.offsetUnset(key);
    } else {
        throwError("Cannot unset offsets");
    }
}

Variant Variant::getProperty(zend_string *prop_name) const {
    auto obj = checkedObject("Attempt to read property");
    zval rv;
    zval *member_p = zend_read_property_ex(obj->ce, obj, prop_name, false, &rv);
    throwErrorIfOccurred();
    if (member_p == &rv) {
        return Variant{member_p, Ctor::Move};
    } else {
        return Variant{member_p, zval_wrap(member_p)};
    }
}

void Variant::setProperty(zend_string *prop_name, const Variant &value) const {
    auto obj = checkedObject("Attempt to write property");
    zend_update_property_ex(obj->ce, obj, prop_name, NO_CONST_V(value));
    throwErrorIfOccurred();
}

Variant Variant::getProperty(const Variant &name) const {
    if (UNEXPECTED(!isObject())) {
        return {};
    }
    auto zk = NO_CONST_V(name);
    auto prop_name = zval_get_string(zk);
    Variant prop_value;
    try {
        prop_value = getProperty(prop_name);
    } catch (...) {
        zend_string_release(prop_name);
        throw;
    }
    zend_string_release(prop_name);
    return prop_value;
}

void Variant::setProperty(const Variant &name, const Variant &value) const {
    checkedObject("Attempt to write property");
    auto zk = NO_CONST_V(name);
    auto prop_name = zval_get_string(zk);
    try {
        setProperty(prop_name, value);
    } catch (...) {
        zend_string_release(prop_name);
        throw;
    }
    zend_string_release(prop_name);
}

void Variant::unsetProperty(zend_string *prop_name) {
    auto obj = checkedObject("Attempt to unset property");
    do {
        FakeScopeGuard fake_scope_guard{obj->ce};
        obj->handlers->unset_property(obj, prop_name, 0);
    } while (0);
    throwErrorIfOccurred();
}

void Variant::unsetProperty(const Variant &name) {
    checkedObject("Attempt to unset property");
    auto zk = NO_CONST_V(name);
    auto prop_name = zval_get_string(zk);
    try {
        unsetProperty(prop_name);
    } catch (...) {
        zend_string_release(prop_name);
        throw;
    }
    zend_string_release(prop_name);
}

/**
 * The comparison function never returns a failure
 * Including:
 * is_identical_function
 * is_equal_function
 * is_smaller_function
 * is_smaller_or_equal_function
 */
static inline bool compare_op(const binary_op_type op, const zval *op1, const zval *op2) {
    zval result;
    op(&result, NO_CONST_UNWRAP_Z(op1), NO_CONST_UNWRAP_Z(op2));
    throwErrorIfOccurred();
    return Z_TYPE(result) == IS_TRUE;
}

static inline Variant calc_op(const binary_op_type op, const zval *op1, const zval *op2) {
    Variant result;
    op(result.ptr(), NO_CONST_UNWRAP_Z(op1), NO_CONST_UNWRAP_Z(op2));
    throwErrorIfOccurred();
    return result;
}

template <detail::CompareRelation Relation>
static bool compare_fast_impl(const Variant &a, const Variant &b) {
    const zval *left = a.unwrap_ptr();
    const zval *right = b.unwrap_ptr();
    const uint8_t left_type = Z_TYPE_P(left);
    const uint8_t right_type = Z_TYPE_P(right);

    if (EXPECTED(left_type == IS_LONG)) {
        if (EXPECTED(right_type == IS_LONG)) {
            return detail::compareRelation<Relation>(Z_LVAL_P(left), Z_LVAL_P(right));
        }
        if (EXPECTED(right_type == IS_DOUBLE)) {
            return detail::compareRelation<Relation>(static_cast<double>(Z_LVAL_P(left)), Z_DVAL_P(right));
        }
    } else if (EXPECTED(left_type == IS_DOUBLE)) {
        if (EXPECTED(right_type == IS_DOUBLE)) {
            return detail::compareRelation<Relation>(Z_DVAL_P(left), Z_DVAL_P(right));
        }
        if (EXPECTED(right_type == IS_LONG)) {
            return detail::compareRelation<Relation>(Z_DVAL_P(left), static_cast<double>(Z_LVAL_P(right)));
        }
    }

    constexpr binary_op_type op =
        detail::compare_relation_is_inclusive_v<Relation> ? is_smaller_or_equal_function : is_smaller_function;
    if constexpr (detail::compare_relation_is_reverse_v<Relation>) {
        return compare_op(op, right, left);
    } else {
        return compare_op(op, left, right);
    }
}

bool Variant::equals(const Variant &v, bool strict) const {
    if (strict) {
        return compare_op(is_identical_function, const_ptr(), v.const_ptr());
    } else {
        return compare_op(is_equal_function, const_ptr(), v.const_ptr());
    }
}

Variant Variant::serialize() {
    smart_str serialized_data = {};
    php_serialize_data_t var_hash;
    PHP_VAR_SERIALIZE_INIT(var_hash);
    php_var_serialize(&serialized_data, unwrap_ptr(), &var_hash);
    PHP_VAR_SERIALIZE_DESTROY(var_hash);

    if (UNEXPECTED(EG(exception) != nullptr)) {
        smart_str_free(&serialized_data);
        throwErrorIfOccurred();
        return {};
    }
    if (UNEXPECTED(serialized_data.s == nullptr)) {
        throwError("failed to serialize value");
        return {};
    }

    Variant retval(serialized_data.s->val, serialized_data.s->len);
    smart_str_free(&serialized_data);
    return retval;
}

Variant &Variant::operator++() {
    zval *p = unwrap_ptr();
    if (EXPECTED(Z_TYPE_P(p) == IS_LONG)) {
        const zend_long val = Z_LVAL_P(p);
        zend_long result;
        if (UNEXPECTED(detail::intAddOverflow(val, 1, &result))) {
            ZVAL_DOUBLE(p, static_cast<double>(val) + 1.0);
        } else {
            ZVAL_LONG(p, result);
        }
        return *this;
    }
    if (EXPECTED(Z_TYPE_P(p) == IS_DOUBLE)) {
        Z_DVAL_P(p) += 1.0;
        return *this;
    }
    increment_function(p);
    throwErrorIfOccurred();
    return *this;
}

Variant &Variant::operator--() {
    zval *p = unwrap_ptr();
    if (EXPECTED(Z_TYPE_P(p) == IS_LONG)) {
        const zend_long val = Z_LVAL_P(p);
        zend_long result;
        if (UNEXPECTED(detail::intSubOverflow(val, 1, &result))) {
            ZVAL_DOUBLE(p, static_cast<double>(val) - 1.0);
        } else {
            ZVAL_LONG(p, result);
        }
        return *this;
    }
    if (EXPECTED(Z_TYPE_P(p) == IS_DOUBLE)) {
        Z_DVAL_P(p) -= 1.0;
        return *this;
    }
    decrement_function(p);
    throwErrorIfOccurred();
    return *this;
}

Variant Variant::operator++(int) {
    auto original = *this;
    ++(*this);
    return original;
}

Variant Variant::operator--(int) {
    auto original = *this;
    --(*this);
    return original;
}

Variant &Variant::operator+=(const Variant &v) {
    return addAssign(v);
}

Variant &Variant::operator-=(const Variant &v) {
    if (isInt() && v.isInt()) {
        zend_long a = Z_LVAL_P(unwrap_ptr());
        zend_long b = Z_LVAL_P(v.unwrap_ptr());
        zend_long result;
        if (detail::intSubOverflow(a, b, &result)) {
            ZVAL_DOUBLE(unwrap_ptr(), (double) a - (double) b);
        } else {
            ZVAL_LONG(unwrap_ptr(), result);
        }
        return *this;
    }
    sub_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    throwErrorIfOccurred();
    return *this;
}

Variant &Variant::operator/=(const Variant &v) {
    if (isInt() && v.isInt()) {
        zend_long a = Z_LVAL_P(unwrap_ptr());
        zend_long b = Z_LVAL_P(v.unwrap_ptr());
        if (UNEXPECTED(b == 0)) {
            div_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
            throwErrorIfOccurred();
            return *this;
        }
        if (UNEXPECTED(a == ZEND_LONG_MIN && b == -1)) {
            ZVAL_DOUBLE(unwrap_ptr(), (double) a / (double) b);
        } else if (a % b == 0) {
            ZVAL_LONG(unwrap_ptr(), a / b);
        } else {
            ZVAL_DOUBLE(unwrap_ptr(), (double) a / (double) b);
        }
        return *this;
    }
    div_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    throwErrorIfOccurred();
    return *this;
}

Variant &Variant::operator*=(const Variant &v) {
    if (isInt() && v.isInt()) {
        zend_long a = Z_LVAL_P(unwrap_ptr());
        zend_long b = Z_LVAL_P(v.unwrap_ptr());
        zend_long result;
        if (detail::intMulOverflow(a, b, &result)) {
            ZVAL_DOUBLE(unwrap_ptr(), (double) a * (double) b);
        } else {
            ZVAL_LONG(unwrap_ptr(), result);
        }
        return *this;
    }
    mul_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    throwErrorIfOccurred();
    return *this;
}

Variant &Variant::operator%=(const Variant &v) {
    if (isInt() && v.isInt()) {
        zend_long a = Z_LVAL_P(unwrap_ptr());
        zend_long b = Z_LVAL_P(v.unwrap_ptr());
        if (UNEXPECTED(b == 0)) {
            mod_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
            throwErrorIfOccurred();
            return *this;
        }
        if (UNEXPECTED(a == ZEND_LONG_MIN && b == -1)) {
            ZVAL_LONG(unwrap_ptr(), 0);
            return *this;
        }
        ZVAL_LONG(unwrap_ptr(), a % b);
        return *this;
    }
    mod_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    throwErrorIfOccurred();
    return *this;
}

Variant &Variant::operator<<=(const Variant &v) {
    shift_left_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    throwErrorIfOccurred();
    return *this;
}

Variant &Variant::operator>>=(const Variant &v) {
    shift_right_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    throwErrorIfOccurred();
    return *this;
}

Variant &Variant::operator&=(const Variant &v) {
    bitwise_and_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    throwErrorIfOccurred();
    return *this;
}

Variant &Variant::operator|=(const Variant &v) {
    bitwise_or_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    throwErrorIfOccurred();
    return *this;
}

Variant &Variant::operator^=(const Variant &v) {
    bitwise_xor_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    throwErrorIfOccurred();
    return *this;
}

Variant Variant::operator+(const Variant &v) const {
    if (isInt() && v.isInt()) {
        zend_long a = Z_LVAL_P(unwrap_ptr());
        zend_long b = Z_LVAL_P(v.unwrap_ptr());
        zend_long result;
        if (detail::intAddOverflow(a, b, &result)) {
            return Variant((double) a + (double) b);
        }
        return Variant(result);
    }
    return calc_op(add_function, const_ptr(), v.const_ptr());
}

Variant Variant::operator-(const Variant &v) const {
    if (isInt() && v.isInt()) {
        zend_long a = Z_LVAL_P(unwrap_ptr());
        zend_long b = Z_LVAL_P(v.unwrap_ptr());
        zend_long result;
        if (detail::intSubOverflow(a, b, &result)) {
            return Variant((double) a - (double) b);
        }
        return Variant(result);
    }
    return calc_op(sub_function, const_ptr(), v.const_ptr());
}

Variant Variant::operator*(const Variant &v) const {
    if (isInt() && v.isInt()) {
        zend_long a = Z_LVAL_P(unwrap_ptr());
        zend_long b = Z_LVAL_P(v.unwrap_ptr());
        zend_long result;
        if (detail::intMulOverflow(a, b, &result)) {
            return Variant((double) a * (double) b);
        }
        return Variant(result);
    }
    return calc_op(mul_function, const_ptr(), v.const_ptr());
}

Variant Variant::operator/(const Variant &v) const {
    if (isInt() && v.isInt()) {
        zend_long a = Z_LVAL_P(unwrap_ptr());
        zend_long b = Z_LVAL_P(v.unwrap_ptr());
        if (UNEXPECTED(b == 0)) {
            return calc_op(div_function, const_ptr(), v.const_ptr());
        }
        if (UNEXPECTED(a == ZEND_LONG_MIN && b == -1)) {
            return Variant((double) a / (double) b);
        }
        if (a % b == 0) {
            // Exact division — return int (PHP 8.0+)
            return Variant(a / b);
        }
        return Variant((double) a / (double) b);
    }
    return calc_op(div_function, const_ptr(), v.const_ptr());
}

Variant Variant::operator%(const Variant &v) const {
    if (isInt() && v.isInt()) {
        zend_long a = Z_LVAL_P(unwrap_ptr());
        zend_long b = Z_LVAL_P(v.unwrap_ptr());
        if (UNEXPECTED(b == 0)) {
            return calc_op(mod_function, const_ptr(), v.const_ptr());
        }
        if (UNEXPECTED(a == ZEND_LONG_MIN && b == -1)) {
            return Variant((zend_long) 0);
        }
        return Variant(a % b);
    }
    return calc_op(mod_function, const_ptr(), v.const_ptr());
}

Variant Variant::operator<<(const Variant &v) const {
    return calc_op(shift_left_function, const_ptr(), v.const_ptr());
}

Variant Variant::operator>>(const Variant &v) const {
    return calc_op(shift_right_function, const_ptr(), v.const_ptr());
}

Variant Variant::operator&(const Variant &v) const {
    return calc_op(bitwise_and_function, const_ptr(), v.const_ptr());
}

Variant Variant::operator|(const Variant &v) const {
    return calc_op(bitwise_or_function, const_ptr(), v.const_ptr());
}

Variant Variant::operator^(const Variant &v) const {
    return calc_op(bitwise_xor_function, const_ptr(), v.const_ptr());
}

Variant Variant::operator~() const {
    Variant result{};
    bitwise_not_function(result.ptr(), NO_CONST_Z(unwrap_ptr()));
    throwErrorIfOccurred();
    return result;
}

Variant Variant::operator-() const {
    zval tmp;
    ZVAL_LONG(&tmp, -1);
    return calc_op(mul_function, const_ptr(), &tmp);
}

Variant Variant::pow(const Variant &v) const {
    return calc_op(pow_function, const_ptr(), v.const_ptr());
}

String Variant::concat(const Variant &v) const {
    return String(calc_op(concat_function, const_ptr(), v.const_ptr()));
}

void Variant::append(const Variant &v) {
    auto zvalue = NO_CONST_V(v);
    auto zresult = unwrap_ptr();
    if (isArray()) {
        Array tmp(zresult, Ctor::Indirect);
        tmp.append(v);
    } else if (isObject()) {
        Object tmp(zresult);
        tmp.offsetSet(null, v);
    } else if (isString()) {
        concat_function(zresult, zresult, zvalue);
        throwErrorIfOccurred();
    } else {
        throwError("Cannot append element to an `%s`", typeStr());
    }
}

bool Variant::operator<(const Variant &v) const {
    return compare_fast_impl<detail::CompareRelation::Less>(*this, v);
}

bool Variant::operator<=(const Variant &v) const {
    return compare_fast_impl<detail::CompareRelation::LessOrEqual>(*this, v);
}

bool Variant::operator>(const Variant &v) const {
    return compare_fast_impl<detail::CompareRelation::Greater>(*this, v);
}

bool Variant::operator>=(const Variant &v) const {
    return compare_fast_impl<detail::CompareRelation::GreaterOrEqual>(*this, v);
}

Variant Variant::operator()() const {
    return call_impl(nullptr, unwrap_ptr());
}

Variant Variant::operator()(const std::initializer_list<Variant> &args) const {
    Args _args;
    for (const auto &arg : args) {
        _args.append(NO_CONST_V(arg));
    }
    return call_impl(nullptr, unwrap_ptr(), _args);
}

Variant Variant::unserialize() {
    php_unserialize_data_t var_hash;
    Variant retval;
    auto zv = unwrap_ptr();

    if (UNEXPECTED(Z_TYPE_P(zv) != IS_STRING)) {
        zend_type_error("php::Variant::unserialize() expects a string, %s given", zend_zval_type_name(zv));
        throwErrorIfOccurred();
        return {};
    }

    PHP_VAR_UNSERIALIZE_INIT(var_hash);
    const unsigned char *data = reinterpret_cast<const unsigned char *>(Z_STRVAL_P(zv));
    size_t length = Z_STRLEN_P(zv);
    const unsigned char *end = data + length;
    auto rs = php_var_unserialize(retval.ptr(), &data, end, &var_hash);
    PHP_VAR_UNSERIALIZE_DESTROY(var_hash);

    if (UNEXPECTED(EG(exception) != nullptr)) {
        throwErrorIfOccurred();
        return {};
    }

    if (rs) {
        return retval;
    } else {
        return {};
    }
}

bool Variant::isCallable() {
    return zend_is_callable(unwrap_ptr(), 0, nullptr);
}

Variant Variant::item(zend_long offset, bool update) {
    auto zvar = unwrap_zval(ptr());
    zval *retval;
    zval rv;
    ZVAL_UNDEF(&rv);

    if (zval_is_array(zvar)) {
        if (update) {
            SEPARATE_ARRAY(zvar);
        }
        retval = zend_hash_index_find(Z_ARRVAL_P(zvar), offset);
        if (retval == nullptr) {
            if (update) {
                retval = zend_hash_index_update(Z_ARRVAL_P(zvar), offset, undef());
            } else {
                return Variant{undef()};
            }
        }
    } else if (zval_is_object(zvar)) {
        auto obj = object();
        zval dim;
        ZVAL_LONG(&dim, offset);
        retval = obj->handlers->read_dimension(obj, &dim, update ? BP_VAR_RW : BP_VAR_R, &rv);
        if (UNEXPECTED(EG(exception) != nullptr)) {
            if (!Z_ISUNDEF(rv)) {
                zval_ptr_dtor(&rv);
            }
            throwErrorIfOccurred();
            return {};
        }
        if (UNEXPECTED(retval == &rv)) {
            return Variant{retval, Ctor::Move};
        }
        if (UNEXPECTED(retval == NULL || retval == &EG(uninitialized_zval))) {
            return Variant{retval};
        }
    } else if (zval_is_string(zvar)) {
        if (update) {
            const Int normalized_offset = String::normalizeOffset(offset, Z_STRLEN_P(zvar));
            if (normalized_offset < 0 || normalized_offset >= UINT_MAX) {
                throwError("String offset `" ZEND_LONG_FMT "` out of range", offset);
                return {};
            }
            // Z_FE_POS is uint32_t. Store only the checked, non-negative
            // physical position; casting a PHP negative offset directly here
            // would turn -1 into a far out-of-bounds write in setByteOfStr().
            return Variant{zvar, normalized_offset, Ctor::Indirect};
        } else {
            String tmp(zvar, Ctor::Indirect);
            return tmp.offsetGet(offset);
        }
    } else {
        if (update) {
            array_init(zvar);
            retval = zend_hash_index_update(Z_ARRVAL_P(zvar), offset, undef());
        } else {
            throwError(
                "Only array/object/string support the item(" ZEND_LONG_FMT ") method, got `%s`", offset, typeStr());
            return Variant{undef()};
        }
    }

    return Variant{retval, zval_wrap(retval)};
}

Variant Variant::item(const Variant &key, bool update) {
    auto zvar = unwrap_ptr();
    zval *retval;
    zval rv;
    ZVAL_UNDEF(&rv);

    if (key.isBool() || key.isInt() || key.isFloat() || zval_is_string(zvar)) {
        return item(key.toInt(), update);
    }

    if (zval_is_array(zvar)) {
        if (update) {
            SEPARATE_ARRAY(zvar);
        }
        if (key.isNull() && update) {
            retval = zend_hash_next_index_insert(Z_ARRVAL_P(zvar), undef());
        } else {
            auto skey = key.toString();
            retval = zend_symtable_find(Z_ARRVAL_P(zvar), skey.str());
            if (retval == nullptr) {
                if (update) {
                    retval = zend_symtable_update(Z_ARRVAL_P(zvar), skey.str(), undef());
                } else {
                    return Variant{undef()};
                }
            }
        }
    } else if (zval_is_object(zvar)) {
        auto obj = object();
        auto dim = NO_CONST_V(key);
        retval = obj->handlers->read_dimension(obj, dim, update ? BP_VAR_RW : BP_VAR_R, &rv);
        if (UNEXPECTED(EG(exception) != nullptr)) {
            if (!Z_ISUNDEF(rv)) {
                zval_ptr_dtor(&rv);
            }
            throwErrorIfOccurred();
            return {};
        }
        if (UNEXPECTED(retval == &rv)) {
            return Variant{retval, Ctor::Move};
        }
        if (UNEXPECTED(retval == NULL || retval == &EG(uninitialized_zval))) {
            return Variant{retval};
        }
    } else {
        if (update) {
            array_init(zvar);
            if (key.isNull()) {
                retval = zend_hash_next_index_insert(Z_ARRVAL_P(zvar), undef());
            } else {
                auto skey = key.toString();
                retval = zend_hash_update(Z_ARRVAL_P(zvar), skey.str(), undef());
            }
        } else {
            throwError("Only array/object/string support the item() method, type `%s` given", typeStr());
            return Variant{undef()};
        }
    }

    return Variant{retval, zval_wrap(retval)};
}

Reference Variant::itemRef(zend_long offset) {
    auto v = item(offset, true);
    if (zval_is_ref(v.const_ptr())) {
        return Reference(v.const_ptr());
    } else if (!v.isIndirect()) {
        return {};
    } else {
        return v.toReference();
    }
}

Reference Variant::itemRef(const Variant &key) {
    auto v = item(key, true);
    if (zval_is_ref(v.const_ptr())) {
        return Reference(v.const_ptr());
    } else if (!v.isIndirect()) {
        return {};
    } else {
        return v.toReference();
    }
}

Reference Variant::attrRef(const String &prop_name) {
    auto member = attr(prop_name, AttrMode::Update);
    if (zval_is_ref(member.const_ptr())) {
        return Reference(member.const_ptr());
    } else if (!member.isIndirect()) {
        return {};
    }

    auto ref = member.toReference();
    auto obj = object();
    auto slot = member.direct_ptr();
    if (slot >= obj->properties_table && slot < obj->properties_table + obj->ce->default_properties_count) {
        auto prop_info = zend_get_property_info_for_slot(obj, slot);
        if (prop_info && ZEND_TYPE_IS_SET(prop_info->type)) {
            ZEND_REF_ADD_TYPE_SOURCE(ref.reference(), prop_info);
        }
    }
    return ref;
}

Variant Variant::attr(const String &name, AttrMode mode) const {
    if (UNEXPECTED(!isObject())) {
        throwError("Attempt to read property `%s` on %s", name.toCString(), typeStr());
        return {};
    }

    auto prop_name = name.str();
    zval rv;
    zval *member_p;
    if (mode == AttrMode::Update) {
        // zend_read_property_ex() only exposes BP_VAR_R and BP_VAR_IS. Indirect
        // modification must use BP_VAR_RW so overloaded properties invoke
        // __get() directly and can return a writable reference.
        do {
            FakeScopeGuard fake_scope_guard{ce()};
            member_p = object()->handlers->read_property(object(), prop_name, BP_VAR_RW, nullptr, &rv);
        } while (0);
    } else {
        // BP_VAR_IS is needed by empty() and by intermediate property reads in
        // an isset() chain. A final isset() uses has_property() instead.
        member_p = zend_read_property_ex(ce(), object(), prop_name, mode == AttrMode::Isset, &rv);
    }
    throwErrorIfOccurred();

    if (zval_is_null(member_p) && mode == AttrMode::Update) {
        do {
            FakeScopeGuard fake_scope_guard{ce()};
            member_p = object()->handlers->write_property(object(), prop_name, undef(), NULL);
        } while (0);
        throwErrorIfOccurred();

        if (member_p == undef()) {
            throwError("Dynamic property `%s` assignment is not supported", ZSTR_VAL(prop_name));
        }
    }

    if (member_p == &rv) {
        return Variant{member_p, Ctor::Move};
    } else {
        return Variant{member_p, zval_wrap(member_p)};
    }
}

Variant Variant::newItem() {
    auto zvar = unwrap_ptr();
    zval *retval;
    zval rv;
    ZVAL_UNDEF(&rv);

    if (zval_is_undef(zvar) || zval_is_null(zvar)) {
        array_init(zvar);
    }

    if (zval_is_array(zvar)) {
        SEPARATE_ARRAY(zvar);
        retval = zend_hash_next_index_insert(Z_ARRVAL_P(zvar), undef());
    } else if (zval_is_object(zvar)) {
        auto obj = object();
        zval key;
        ZVAL_LONG(&key, length());
        obj->handlers->write_dimension(obj, &key, undef());
        throwErrorIfOccurred();
        retval = obj->handlers->read_dimension(obj, &key, BP_VAR_RW, &rv);
        if (UNEXPECTED(EG(exception) != nullptr)) {
            if (!Z_ISUNDEF(rv)) {
                zval_ptr_dtor(&rv);
            }
            throwErrorIfOccurred();
            return {};
        }
        if (UNEXPECTED(retval == &rv)) {
            return Variant{retval, Ctor::Move};
        }
        if (UNEXPECTED(retval == NULL || retval == &EG(uninitialized_zval))) {
            return Variant{retval};
        }
    } else if (zval_is_string(zvar)) {
        throwError("[] operator not supported for strings");
        return Variant{};
    } else {
        throwError("Only array/object support the newItem() method");
        return Variant{};
    }

    return Variant{retval, Ctor::Indirect};
}

Variant Variant::call(const Variant &fn, const ArgList &args, zend_array *named_args) {
    if (UNEXPECTED(!isObject())) {
        throwError("call method `%s` on %s", fn.toCString(), typeStr());
        return {};
    }
    Args _args(args);
    return call_impl(unwrap_ptr(), fn.unwrap_ptr(), _args, named_args);
}

Variant Variant::call(const Variant &fn, Array &args, zend_array *named_args) {
    Args _args(args);
    return call(fn, _args, named_args);
}

Variant Variant::call(zend_function *fn) {
    auto obj = checkedObject("Call to a member function");
    Variant retval{};
    zend_call_known_function(fn, obj, obj->ce, retval.ptr(), 0, nullptr, nullptr);
    throwErrorIfOccurred();
    return retval;
}

Variant Variant::call(zend_function *fn, Args &_args, zend_array *named_args) {
    auto obj = checkedObject("Call to a member function");
    Variant retval{};
    zend_call_known_function(fn, obj, obj->ce, retval.ptr(), _args.count(), _args.ptr(), named_args);
    throwErrorIfOccurred();
    return retval;
}

Variant Variant::call(zend_function *fn, Array &args, zend_array *named_args) {
    Args _args(args);
    return call(fn, _args, named_args);
}

Variant Variant::call(zend_function *fn, const ArgList &args, zend_array *named_args) {
    Args _args(args);
    return call(fn, _args, named_args);
}

void Reference::copyRef(const zval *zv) {
    zval replacement;
    zval_copy(&replacement, zv);
    zval old = val;
    ZVAL_COPY_VALUE(&val, &replacement);
    zval_ptr_dtor(&old);
    throwErrorIfOccurred();
}

Reference &Reference::operator=(const Reference &v) {
    if (&v != this) {
        zval replacement;
        zval_copy(&replacement, v.const_ptr());
        zval old = val;
        ZVAL_COPY_VALUE(&val, &replacement);
        zval_ptr_dtor(&old);
        throwErrorIfOccurred();
    }
    return *this;
}

Reference &Reference::operator=(Reference &&v) {
    if (&v != this) {
        zval old = val;
        zval_copy_value(&val, &v.val);
        ZVAL_UNDEF(&v.val);
        zval_ptr_dtor(&old);
        throwErrorIfOccurred();
    }
    return *this;
}

Reference &Reference::operator=(Reference *v) {
    if (v != this) {
        copyRef(v->const_ptr());
    }
    return *this;
}

Reference &Reference::operator=(const Variant &v) {
    if (&v != this) {
        if (v.isReference()) {
            // Two wrappers may already point at the same zend_reference (for
            // example, a typed by-reference variadic element normalized from
            // int to float). Destroying the destination value before copying
            // that same reference would turn the shared value into UNDEF.
            if (isReference() && Z_REF_P(ptr()) == Z_REF_P(v.direct_ptr())) {
                return *this;
            }
            destroy();
            copyRef(v.direct_ptr());
        } else {
            // An unset reference degenerates to a normal variable on reassignment.
            if (UNEXPECTED(!isReference())) {
                destroy();
                zval_copy(ptr(), v.direct_ptr());
            } else if (UNEXPECTED(ZEND_REF_HAS_TYPE_SOURCES(Z_REF_P(ptr())))) {
                zval value;
                zval_copy(&value, v.direct_ptr());
                if (UNEXPECTED(zend_try_assign_typed_ref(Z_REF_P(ptr()), &value) == FAILURE)) {
                    throwErrorIfOccurred();
                }
            } else {
                zval *target = refval();
                zval old = *target;
                zval_copy(target, v.direct_ptr());
                zval_ptr_dtor(&old);
                throwErrorIfOccurred();
            }
        }
    }
    return *this;
}
}  // namespace php
