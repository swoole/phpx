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

BEGIN_EXTERN_C()
#include "zend_smart_str.h"
#include <ext/spl/php_spl.h>
END_EXTERN_C()

#include <cmath>

namespace php {
Variant null = {};
Int zero = 0L;

void Variant::copyFrom(const zval *src) {
    zval_ptr_dtor(direct_ptr());
    ZVAL_COPY(direct_ptr(), src);
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

Variant &Variant::operator=(const Variant *v) {
    destroy();
    ZVAL_NEW_REF(&val, v->const_ptr());
    zval_add_ref(Z_REFVAL(val));
    return *this;
}

std::string Variant::toStdString() const {
    zend_string *str = zval_get_string(NO_CONST_Z(unwrap_ptr()));
    auto retval = std::string(ZSTR_VAL(str), ZSTR_LEN(str));
    zend_string_release(str);
    return retval;
}

String Variant::toString() const {
    return String(zval_get_string(NO_CONST_Z(unwrap_ptr())), Ctor::Move);
}

Reference Variant::toReference() {
    Variant tmp{this};
    return Reference{tmp.const_ptr()};
}

Array Variant::toArray() const {
    return Array(unwrap_ptr());
}

Object Variant::toObject() const {
    return Object(unwrap_ptr());
}

size_t Variant::length() const {
    auto zv = unwrap_ptr();
    if (Z_TYPE_P(zv) == IS_STRING) {
        return Z_STRLEN_P(zv);
    } else if (Z_TYPE_P(zv) == IS_ARRAY) {
        return zend_hash_num_elements(Z_ARRVAL_P(zv));
    } else if (Z_TYPE_P(zv) == IS_OBJECT) {
        Object tmp(zv, Ctor::Indirect);
        return tmp.count();
    } else {
        return 0;
    }
}

void Variant::unset() {
    if (isIndirect()) {
        zval_ptr_dtor(Z_INDIRECT(val));
        *Z_INDIRECT(val) = {};
    } else {
        zval_ptr_dtor(&val);
    }
    val = {};
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
        printf("value=%ld\n", Z_LVAL_P(_val));
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
    ZVAL_COPY_VALUE(&zv, Z_REFVAL_P(const_ptr()));
    return {&zv};
}

Variant Variant::offsetGet(zend_long offset) const {
    auto zvar = unwrap_ptr();

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        return zend_hash_index_find(Z_ARRVAL_P(zvar), offset);
    } else if (Z_TYPE_P(zvar) == IS_STRING) {
        String tmp(zvar, Ctor::Indirect);
        return tmp.offsetGet(offset);
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        Object tmp(zvar);
        return tmp.offsetGet(offset);
    } else {
        return Variant{};
    }
}

Variant Variant::offsetGet(const Variant &key) const {
    if (key.isInt() || key.isFloat() || key.isNumeric()) {
        return offsetGet(key.toInt());
    }

    auto zvar = unwrap_ptr();
    if (Z_TYPE_P(zvar) == IS_STRING) {
        String tmp(zvar, Ctor::Indirect);
        return tmp.offsetGet(key.toInt());
    } else if (Z_TYPE_P(zvar) == IS_ARRAY) {
        auto skey = key.toString();
        Array tmp(zvar);
        return tmp.get(skey);
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        Object tmp(zvar);
        return tmp.offsetGet(key);
    } else {
        return Variant{};
    }
}

bool Variant::offsetExists(zend_long offset) const {
    auto zvar = unwrap_ptr();

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        return zend_hash_index_exists(Z_ARRVAL_P(zvar), offset);
    } else if (Z_TYPE_P(zvar) == IS_STRING) {
        String tmp(zvar, Ctor::Indirect);
        return tmp.offset(offset) != -1;
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        Object tmp(zvar);
        return tmp.offsetExists(offset);
    } else {
        return false;
    }
}

bool Variant::offsetExists(const Variant &key) const {
    if (key.isInt() || key.isFloat() || key.isNumeric()) {
        return offsetExists(key.toInt());
    }

    auto zvar = unwrap_ptr();
    if (Z_TYPE_P(zvar) == IS_STRING) {
        String tmp(zvar, Ctor::Indirect);
        return tmp.offset(key.toInt()) != -1;
    } else if (Z_TYPE_P(zvar) == IS_ARRAY) {
        auto skey = key.toString();
        return zend_hash_exists(Z_ARRVAL_P(zvar), skey.str());
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
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

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        Array tmp(zvar, Ctor::Indirect);
        tmp.set(offset, value);
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        Object tmp(zvar);
        tmp.offsetSet(offset, NO_CONST_V(value));
    } else if (Z_TYPE_P(zvar) == IS_STRING) {
        String tmp(zvar, Ctor::Indirect);
        tmp.offsetSet(offset, value);
    }
}

void Variant::offsetSet(const Variant &key, const Variant &value) {
    auto zvar = unwrap_ptr();

    if (Z_TYPE_P(zvar) == IS_UNDEF || Z_TYPE_P(zvar) == IS_NULL) {
        array_init(zvar);
    }

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        Array tmp(zvar, Ctor::Indirect);
        tmp.set(key, value);
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        Object tmp(zvar);
        tmp.offsetSet(key, value);
    } else if (Z_TYPE_P(zvar) == IS_STRING) {
        if (key.isNull()) {
            throwError("[] operator not supported for strings");
        }
        String tmp(zvar, Ctor::Indirect);
        tmp.offsetSet(key.toInt(), value);
    }
}

void Variant::offsetUnset(zend_long offset) {
    auto zvar = unwrap_ptr();

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        Array tmp(zvar, Ctor::Indirect);
        tmp.del(offset);
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        Object tmp(zvar);
        tmp.offsetUnset(offset);
    } else {
        throwError("Cannot unset offsets");
    }
}

void Variant::offsetUnset(const Variant &key) {
    auto zvar = unwrap_ptr();

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        Array tmp(zvar, Ctor::Indirect);
        tmp.del(key);
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        Object tmp(zvar);
        tmp.offsetUnset(key);
    } else {
        throwError("Cannot unset offsets");
    }
}

Variant Variant::getProperty(zend_string *prop_name) const {
    zval rv;
    zval *member_p = zend_read_property_ex(ce(), object(), prop_name, false, &rv);
    member_p = unwrap_zval(member_p);
    return {member_p};
}

void Variant::setProperty(zend_string *prop_name, const Variant &value) const {
    auto zv = NO_CONST_V(value);
    zend_update_property_ex(ce(), object(), prop_name, zv);
}

Variant Variant::getProperty(const Variant &name) const {
    if (UNEXPECTED(!isObject())) {
        return {};
    }
    auto zk = NO_CONST_V(name);
    auto prop_name = zval_get_string(zk);
    auto prop_value = getProperty(prop_name);
    zend_string_release(prop_name);
    return prop_value;
}

void Variant::setProperty(const Variant &name, const Variant &value) const {
    auto zk = NO_CONST_V(name);
    auto prop_name = zval_get_string(zk);
    setProperty(prop_name, value);
    zend_string_release(prop_name);
}

void Variant::unsetProperty(zend_string *prop_name) {
    auto old_scope = EG(fake_scope);
    EG(fake_scope) = ce();
    object()->handlers->unset_property(object(), prop_name, 0);
    EG(fake_scope) = old_scope;
}

void Variant::unsetProperty(const Variant &name) {
    auto zk = NO_CONST_V(name);
    auto prop_name = zval_get_string(zk);
    unsetProperty(prop_name);
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
    return Z_TYPE(result) == IS_TRUE;
}

static inline Variant calc_op(const binary_op_type op, const zval *op1, const zval *op2) {
    Variant result;
    op(result.ptr(), NO_CONST_UNWRAP_Z(op1), NO_CONST_UNWRAP_Z(op2));
    return result;
}

static zend_result ZEND_FASTCALL is_greater_function(zval *result, zval *op1, zval *op2) {
    return is_smaller_function(result, op2, op1);
}

static zend_result ZEND_FASTCALL is_greater_or_equal_function(zval *result, zval *op1, zval *op2) {
    return is_smaller_or_equal_function(result, op2, op1);
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
    Variant retval(serialized_data.s->val, serialized_data.s->len);
    smart_str_free(&serialized_data);
    return retval;
}

Variant &Variant::operator++() {
    increment_function(unwrap_ptr());
    return *this;
}

Variant &Variant::operator--() {
    decrement_function(unwrap_ptr());
    return *this;
}

Variant Variant::operator++(int) {
    auto original = *this;
    increment_function(unwrap_ptr());
    return original;
}

Variant Variant::operator--(int) {
    auto original = *this;
    decrement_function(unwrap_ptr());
    return original;
}

Variant &Variant::operator+=(const Variant &v) {
    add_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator-=(const Variant &v) {
    sub_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator/=(const Variant &v) {
    div_function(ptr(), unwrap_ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator*=(const Variant &v) {
    mul_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator%=(const Variant &v) {
    mod_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator<<=(const Variant &v) {
    shift_left_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator>>=(const Variant &v) {
    shift_right_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator&=(const Variant &v) {
    bitwise_and_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator|=(const Variant &v) {
    bitwise_or_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator^=(const Variant &v) {
    bitwise_xor_function(unwrap_ptr(), unwrap_ptr(), NO_CONST_V(v));
    return *this;
}

Variant Variant::operator+(const Variant &v) const {
    return calc_op(add_function, const_ptr(), v.const_ptr());
}

Variant Variant::operator-(const Variant &v) const {
    return calc_op(sub_function, const_ptr(), v.const_ptr());
}

Variant Variant::operator*(const Variant &v) const {
    return calc_op(mul_function, const_ptr(), v.const_ptr());
}

Variant Variant::operator/(const Variant &v) const {
    return calc_op(div_function, const_ptr(), v.const_ptr());
}

Variant Variant::operator%(const Variant &v) const {
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

Variant Variant::concat(const Variant &v) const {
    return calc_op(concat_function, const_ptr(), v.const_ptr());
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
    } else {
        throwError("Cannot append element to an `%s`", typeStr());
    }
}

bool Variant::operator<(const Variant &v) const {
    return compare_op(is_smaller_function, const_ptr(), v.const_ptr());
}

bool Variant::operator<=(const Variant &v) const {
    return compare_op(is_smaller_or_equal_function, const_ptr(), v.const_ptr());
}

bool Variant::operator>(const Variant &v) const {
    return compare_op(is_greater_function, const_ptr(), v.const_ptr());
}

bool Variant::operator>=(const Variant &v) const {
    return compare_op(is_greater_or_equal_function, const_ptr(), v.const_ptr());
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

    PHP_VAR_UNSERIALIZE_INIT(var_hash);
    char *data = Z_STRVAL_P(zv);
    size_t length = Z_STRLEN_P(zv);
    auto rs = php_var_unserialize(retval.ptr(), (const uchar **) &data, (const uchar *) data + length, &var_hash);
    PHP_VAR_UNSERIALIZE_DESTROY(var_hash);

    if (rs) {
        return retval;
    } else {
        return {};
    }
}

Variant Variant::jsonEncode(zend_long options, zend_long depth) {
    smart_str buf = {};
    JSON_G(error_code) = PHP_JSON_ERROR_NONE;
    JSON_G(encode_max_depth) = (int) depth;
    auto zv = unwrap_ptr();

    Variant result;
    php_json_encode(&buf, zv, (int) options);
    if (EXPECTED(JSON_G(error_code) == PHP_JSON_ERROR_NONE || (options & PHP_JSON_PARTIAL_OUTPUT_ON_ERROR))) {
        smart_str_0(&buf);
        result = buf.s;
    }
    smart_str_free(&buf);
    return result;
}

Variant Variant::jsonDecode(zend_long options, zend_long depth) {
    JSON_G(error_code) = PHP_JSON_ERROR_NONE;
    auto zv = unwrap_ptr();

    if (length() == 0) {
        JSON_G(error_code) = PHP_JSON_ERROR_SYNTAX;
        return {};
    }

    options |= PHP_JSON_OBJECT_AS_ARRAY;
    Variant retval;
    php_json_decode_ex(retval.ptr(), Z_STRVAL_P(zv), Z_STRLEN_P(zv), options, depth);
    return retval;
}

bool Variant::isCallable() {
    return zend_is_callable(unwrap_ptr(), 0, nullptr);
}

Variant Variant::item(zend_long offset, bool update) {
    auto zvar = unwrap_zval(ptr());
    zval *retval;
    zval rv;

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        retval = zend_hash_index_find(Z_ARRVAL_P(zvar), offset);
        if (retval == nullptr) {
            if (update) {
                SEPARATE_ARRAY(zvar);
                retval = zend_hash_index_update(Z_ARRVAL_P(zvar), offset, undef());
            } else {
                return Variant{undef()};
            }
        }
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        auto obj = object();
        zval dim;
        ZVAL_LONG(&dim, offset);
        retval = obj->handlers->read_dimension(obj, &dim, BP_VAR_RW, &rv);
        if (UNEXPECTED(retval == NULL || retval == &EG(uninitialized_zval) || retval == &rv)) {
            return Variant{retval};
        }
    } else if (Z_TYPE_P(zvar) == IS_STRING) {
        return offsetGet(offset);
    } else {
        if (update) {
            array_init(zvar);
            retval = zend_hash_index_update(Z_ARRVAL_P(zvar), offset, undef());
        } else {
            throwError("Only array/object/string support the item(%ld) method, got `%s`", offset, typeStr());
            return Variant{undef()};
        }
    }

    return Variant{retval, Ctor::Indirect};
}

Variant Variant::item(const Variant &key, bool update) {
    auto zvar = unwrap_zval(ptr());
    zval *retval;
    zval rv;

    if (key.isInt() || key.isFloat() || key.isNumeric() || Z_TYPE_P(zvar) == IS_STRING) {
        return item(key.toInt(), update);
    }

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        auto skey = key.toString();
        retval = zend_hash_find(Z_ARRVAL_P(zvar), skey.str());
        if (retval == nullptr) {
            if (update) {
                SEPARATE_ARRAY(zvar);
                retval = zend_hash_update(Z_ARRVAL_P(zvar), skey.str(), undef());
            } else {
                return Variant{undef()};
            }
        }
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        auto obj = object();
        auto dim = NO_CONST_V(key);
        retval = obj->handlers->read_dimension(obj, dim, BP_VAR_RW, &rv);
        if (UNEXPECTED(retval == NULL || retval == &EG(uninitialized_zval) || retval == &rv)) {
            return Variant{retval};
        }
    } else {
        if (update) {
            array_init(zvar);
            auto skey = key.toString();
            retval = zend_hash_update(Z_ARRVAL_P(zvar), skey.str(), undef());
        } else {
            throwError("Only array/object/string support the item() method");
            return Variant{undef()};
        }
    }

    return Variant{retval, Ctor::Indirect};
}

Variant Variant::newItem() {
    auto zvar = unwrap_zval(ptr());
    zval *retval;
    zval rv;

    if (Z_TYPE_P(zvar) == IS_UNDEF || Z_TYPE_P(zvar) == IS_NULL) {
        array_init(zvar);
    }

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        SEPARATE_ARRAY(zvar);
        retval = zend_hash_next_index_insert(Z_ARRVAL_P(zvar), undef());
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        auto obj = object();
        zval key;
        ZVAL_LONG(&key, length());
        obj->handlers->write_dimension(obj, &key, undef());
        retval = obj->handlers->read_dimension(obj, &key, BP_VAR_RW, &rv);
        if (UNEXPECTED(retval == NULL || retval == &EG(uninitialized_zval) || retval == &rv)) {
            return Variant{retval};
        }
    } else if (Z_TYPE_P(zvar) == IS_STRING) {
        throwError("[] operator not supported for strings");
        return Variant{};
    } else {
        throwError("Only array/object support the newItem() method");
        return Variant{};
    }

    return Variant{retval, Ctor::Indirect};
}
}  // namespace php
