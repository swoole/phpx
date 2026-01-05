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
static Variant __construct{ZEND_STRL("__construct"), true};

Variant &Variant::operator=(const zval *v) {
    destroy();
    val = *v;
    addRef();
    return *this;
}

Variant &Variant::operator=(const Variant &v) {
    if (&v == this) {
        return *this;
    }
    destroy();
    ZVAL_COPY_VALUE(ptr(), v.const_ptr());
    addRef();
    return *this;
}

Variant &Variant::operator=(const Variant *v) {
    destroy();
    ZVAL_NEW_REF(&val, v->const_ptr());
    zval_add_ref(Z_REFVAL(val));
    return *this;
}

std::string Variant::toStdString() const {
    zend_string *str = zval_get_string(NO_CONST_Z(const_ptr()));
    auto retval = std::string(ZSTR_VAL(str), ZSTR_LEN(str));
    zend_string_release(str);
    return retval;
}

String Variant::toString() const {
    return String::from(zval_get_string(NO_CONST_Z(const_ptr())));
}

Array Variant::toArray() const {
    if (UNEXPECTED(Z_ISREF_P(const_ptr()))) {
        return Array(Z_REFVAL(val));
    } else {
        return *this;
    }
}

Object Variant::toObject() const {
    return *this;
}

size_t Variant::length() const {
    if (isString()) {
        return Z_STRLEN_P(const_ptr());
    } else if (isArray()) {
        return zend_hash_num_elements(Z_ARRVAL_P(const_ptr()));
    } else {
        return 0;
    }
}

bool Variant::isNumeric() const {
    switch (type()) {
    case IS_LONG:
    case IS_DOUBLE:
        return true;
    case IS_STRING:
        return is_numeric_string(Z_STRVAL(val), Z_STRLEN(val), nullptr, nullptr, false);
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
    php_debug_zval_dump(ptr(), 10);
}
#endif

int Variant::getRefCount() const {
    if (Z_REFCOUNTED_P(const_ptr())) {
        return Z_REFCOUNT_P(const_ptr());
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
    auto zvar = const_ptr();
    ZVAL_DEREF(zvar);

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        return zend_hash_index_find(Z_ARRVAL_P(zvar), offset);
    } else if (Z_TYPE_P(zvar) == IS_STRING) {
        auto str = Z_STR_P(zvar);
        if (UNEXPECTED(ZSTR_LEN(str) < ((offset < 0) ? -(size_t) offset : ((size_t) offset + 1)))) {
            return Variant{"", 0};
        } else {
            auto real_offset = (UNEXPECTED(offset < 0)) /* Handle negative offset */
                                   ? (zend_long) ZSTR_LEN(str) + offset
                                   : offset;
            return Variant{ZSTR_VAL(str) + real_offset, 1};
        }
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        Object tmp(zvar);
        return tmp.exec("offsetGet", offset);
    } else {
        return Variant{};
    }
}

Variant Variant::offsetGet(const Variant &key) const {
    auto zvar = const_ptr();
    ZVAL_DEREF(zvar);

    if (key.isInt() || key.isFloat() || Z_TYPE_P(zvar) == IS_STRING) {
        return offsetGet(key.toInt());
    }
    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        auto skey = key.toString();
        return zend_hash_find(Z_ARRVAL_P(zvar), skey.str());
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        Object tmp(zvar);
        return tmp.exec("offsetGet", key);
    } else {
        return Variant{};
    }
}

bool Variant::offsetExists(zend_long offset) const {
    auto zvar = const_ptr();
    ZVAL_DEREF(zvar);

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        return zend_hash_index_exists(Z_ARRVAL_P(zvar), offset);
    } else if (Z_TYPE_P(zvar) == IS_STRING) {
        if (UNEXPECTED(offset < 0)) {
            offset += (zend_long) Z_STRLEN_P(zvar);
        }
        return EXPECTED(offset >= 0) && (size_t) offset < Z_STRLEN_P(zvar);
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        Object tmp(zvar);
        return tmp.exec("offsetExists", offset).toBool();
    } else {
        return false;
    }
}

bool Variant::offsetExists(const Variant &key) const {
    auto zvar = const_ptr();
    ZVAL_DEREF(zvar);

    if (key.isInt() || key.isFloat() || Z_TYPE_P(zvar) == IS_STRING) {
        return offsetExists(key.toInt());
    }
    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        auto skey = key.toString();
        return zend_hash_exists(Z_ARRVAL_P(zvar), skey.str());
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        Object tmp(zvar);
        return tmp.exec("offsetExists", key).toBool();
    } else {
        return false;
    }
}

/**
 * The runtime copy mechanism of PHP conflicts with the design of phpx, and COW must be disabled to update array
 * elements.
 */
struct NoCowArray {
    zend_array *ht;
    uint32_t ref_count;
    NoCowArray(const zval *zarr) {
        ht = Z_ARRVAL_P(zarr);
        ref_count = GC_REFCOUNT(ht);
        GC_SET_REFCOUNT(ht, 1);
    }
    ~NoCowArray() {
        GC_SET_REFCOUNT(ht, ref_count);
    }
};

static zval *array_update_no_cow(const zval *zarr, zend_long h, zval *zv) {
    NoCowArray array(zarr);
    return zend_hash_index_update(array.ht, h, zv);
}

static zval *array_update_no_cow(const zval *zarr, const Variant &key, zval *zv) {
    auto skey = key.toString();
    NoCowArray array(zarr);
    return zend_symtable_update(array.ht, skey.str(), zv);
}

static zval *array_append_no_cow(const zval *zarr, zval *zv) {
    NoCowArray array(zarr);
    return zend_hash_next_index_insert(array.ht, zv);
}

static zend_result array_delele_no_cow(const zval *zarr, zend_long h) {
    NoCowArray array(zarr);
    return zend_hash_index_del(array.ht, h);
}

static zend_result array_delele_no_cow(const zval *zarr, const Variant &key) {
    NoCowArray array(zarr);
    auto skey = key.toString();
    return zend_hash_del(array.ht, skey.str());
}

void Variant::offsetSet(zend_long offset, const Variant &value) {
    auto zvar = const_ptr();
    ZVAL_DEREF(zvar);

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        auto zv = NO_CONST_V(value);
        Z_TRY_ADDREF_P(zv);
        array_update_no_cow(zvar, offset, zv);
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        Object tmp(zvar);
        tmp.exec("offsetSet", offset, value);
    }
}

void Variant::offsetSet(const Variant &key, const Variant &value) {
    auto zvar = const_ptr();
    ZVAL_DEREF(zvar);

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        auto zv = NO_CONST_V(value);
        Z_TRY_ADDREF_P(zv);
        if (key.isInt() || key.isFloat()) {
            array_update_no_cow(zvar, key.toInt(), zv);
        } else if (key.isNull()) {
            array_append_no_cow(zvar, zv);
        } else {
            array_update_no_cow(zvar, key, zv);
        }
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        Object tmp(zvar);
        tmp.exec("offsetSet", key, value);
    }
}

void Variant::offsetUnset(zend_long offset) {
    auto zvar = const_ptr();
    ZVAL_DEREF(zvar);

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        array_delele_no_cow(zvar, offset);
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        Object tmp(zvar);
        tmp.exec("offsetUnset", offset);
    }
}

void Variant::offsetUnset(const Variant &key) {
    auto zvar = const_ptr();
    ZVAL_DEREF(zvar);

    if (Z_TYPE_P(zvar) == IS_ARRAY) {
        if (key.isInt() || key.isFloat()) {
            array_delele_no_cow(zvar, key.toInt());
        } else {
            array_delele_no_cow(zvar, key);
        }
    } else if (Z_TYPE_P(zvar) == IS_OBJECT) {
        Object tmp(zvar);
        tmp.exec("offsetUnset", key);
    }
}

Variant Variant::getProperty(zend_string *prop_name) const {
    zval rv;
    Variant retval;
    zval *member_p = zend_read_property_ex(ce(), object(), prop_name, false, &rv);
    if (member_p != &rv) {
        ZVAL_COPY(retval.ptr(), member_p);
    } else {
        ZVAL_COPY_VALUE(retval.ptr(), member_p);
    }
    return retval;
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
    op(&result, NO_CONST_Z(op1), NO_CONST_Z(op2));
    return Z_TYPE(result) == IS_TRUE;
}

static inline Variant calc_op(const binary_op_type op, const zval *op1, const zval *op2) {
    Variant result;
    op(result.ptr(), NO_CONST_Z(op1), NO_CONST_Z(op2));
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
    php_var_serialize(&serialized_data, ptr(), &var_hash);
    PHP_VAR_SERIALIZE_DESTROY(var_hash);
    Variant retval(serialized_data.s->val, serialized_data.s->len);
    smart_str_free(&serialized_data);
    return retval;
}

Variant &Variant::operator++() {
    increment_function(ptr());
    return *this;
}

Variant &Variant::operator--() {
    decrement_function(ptr());
    return *this;
}

Variant Variant::operator++(int) {
    auto original = *this;
    increment_function(ptr());
    return original;
}

Variant Variant::operator--(int) {
    auto original = *this;
    decrement_function(ptr());
    return original;
}

Variant &Variant::operator+=(const Variant &v) {
    add_function(ptr(), ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator-=(const Variant &v) {
    sub_function(ptr(), ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator/=(const Variant &v) {
    div_function(ptr(), ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator*=(const Variant &v) {
    mul_function(ptr(), ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator%=(const Variant &v) {
    mod_function(ptr(), ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator<<=(const Variant &v) {
    shift_left_function(ptr(), ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator>>=(const Variant &v) {
    shift_right_function(ptr(), ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator&=(const Variant &v) {
    bitwise_and_function(ptr(), ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator|=(const Variant &v) {
    bitwise_or_function(ptr(), ptr(), NO_CONST_V(v));
    return *this;
}

Variant &Variant::operator^=(const Variant &v) {
    bitwise_xor_function(ptr(), ptr(), NO_CONST_V(v));
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
    bitwise_not_function(result.ptr(), NO_CONST_Z(const_ptr()));
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
    if (isArray()) {
        const_cast<Variant &>(v).addRef();
        SEPARATE_ARRAY(ptr());
        add_next_index_zval(ptr(), const_cast<Variant &>(v).ptr());
    } else {
        convert_to_string(ptr());
        concat_function(ptr(), ptr(), NO_CONST_V(v));
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
    return _call(nullptr, const_ptr());
}

Variant Variant::operator()(const std::initializer_list<Variant> &args) const {
    Args _args;
    for (const auto &arg : args) {
        _args.append(NO_CONST_V(arg));
    }
    return _call(nullptr, const_ptr(), _args);
}

Variant Variant::unserialize() {
    php_unserialize_data_t var_hash;
    Variant retval;

    PHP_VAR_UNSERIALIZE_INIT(var_hash);
    char *data = Z_STRVAL_P(ptr());
    size_t length = Z_STRLEN_P(ptr());
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

    Variant result;
    php_json_encode(&buf, ptr(), (int) options);
    if (EXPECTED(JSON_G(error_code) == PHP_JSON_ERROR_NONE || (options & PHP_JSON_PARTIAL_OUTPUT_ON_ERROR))) {
        smart_str_0(&buf);
        result = buf.s;
    }
    smart_str_free(&buf);
    return result;
}

Variant Variant::jsonDecode(zend_long options, zend_long depth) {
    JSON_G(error_code) = PHP_JSON_ERROR_NONE;

    if (this->length() == 0) {
        JSON_G(error_code) = PHP_JSON_ERROR_SYNTAX;
        return {};
    }

    options |= PHP_JSON_OBJECT_AS_ARRAY;
    Variant retval;
    php_json_decode_ex(retval.ptr(), Z_STRVAL_P(ptr()), Z_STRLEN_P(ptr()), options, depth);
    return retval;
}

bool Variant::isCallable() {
    return zend_is_callable(ptr(), 0, nullptr);
}

Object newObject(const char *name) {
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    if (ce->constructor) {
        _call(object.ptr(), __construct.ptr());
    }
    return object;
}

Object newObject(const char *name, const std::initializer_list<Variant> &args) {
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    Args _args;
    for (const auto &arg : args) {
        _args.append(const_cast<Variant &>(arg).ptr());
    }
    if (ce->constructor) {
        object.call(__construct, _args);
    }
    return object;
}

Variant newReference() {
    Variant ref{};
    ZVAL_NEW_EMPTY_REF(ref.ptr());
    ZVAL_NULL(Z_REFVAL_P(ref.ptr()));
    return ref;
}

String Object::hash() const {
    return String::from(php_spl_object_hash(object()));
}

Variant Object::exec(const Variant &fn, const std::initializer_list<Variant> &args) {
    Args _args;
    for (const auto &arg : args) {
        _args.append(const_cast<Variant &>(arg).ptr());
    }
    return _call(ptr(), fn.const_ptr(), _args);
}

Variant Object::callParentMethod(const String &func, const std::initializer_list<Variant> &args) {
    Args _args;
    for (const auto &arg : args) {
        _args.append(const_cast<Variant &>(arg).ptr());
    }

    Variant retval;
    auto fn = (zend_function *) zend_hash_find_ptr_lc(&parent_ce()->function_table, func.str());
    if (UNEXPECTED(fn == nullptr)) {
        /* error at c-level */
        zend_error_noreturn(
            E_CORE_ERROR, "Couldn't find implementation for method %s::%s", ZSTR_VAL(parent_ce()->name), func.data());
    } else {
        zend_call_known_function(fn, object(), ce(), retval.ptr(), _args.count(), _args.ptr(), nullptr);
    }
    return retval;
}

Variant Object::get(const String &name) const {
    return getProperty(name.str());
}

Object Object::clone() const {
    const auto new_object = zend_objects_clone_obj(object());
    Object retval;
    ZVAL_OBJ(retval.ptr(), new_object);
    return retval;
}
}  // namespace php
