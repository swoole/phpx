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

#include "zend_smart_str.h"

namespace php {
Variant null = {};

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

std::string Variant::toString() {
    zend_string *str = zval_get_string(ptr());
    auto retval = std::string(ZSTR_VAL(str), ZSTR_LEN(str));
    zend_string_release(str);
    return retval;
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
               _val->value.arr,
               zend_hash_num_elements(Z_ARRVAL_P(_val)));
    } else if (Z_TYPE_P(_val) == IS_OBJECT) {
        printf("object[rc=%d]=%p, class=%s\n", Z_REFCOUNT_P(_val), _val->value.obj, ZSTR_VAL(Z_OBJCE_P(_val)->name));
    } else if (Z_TYPE_P(_val) == IS_RESOURCE) {
        printf("resource=%p, type=%d\n", _val->value.res, _val->value.res->type);
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

bool Variant::empty() {
    switch (type()) {
    case IS_UNDEF:
    case IS_NULL:
    case IS_FALSE:
        return true;
    case IS_LONG:
        return toInt() == 0;
    case IS_DOUBLE:
        return toFloat() == 0.0;
    case IS_STRING:
        return length() == 0;
    case IS_ARRAY:
        return Z_ARRVAL_P(const_ptr())->nNumOfElements == 0;
    default:
        return false;
    }
}

Variant Variant::getRefValue() const {
    if (!isReference()) {
        return *this;
    }
    zval zv;
    ZVAL_COPY_VALUE(&zv, Z_REFVAL_P(const_ptr()));
    return {&zv};
}

bool Variant::equals(Variant &v, bool strict) {
    if (strict) {
        if (fast_is_identical_function(v.ptr(), ptr())) {
            return true;
        }
    } else {
        if (v.isInt()) {
            if (fast_equal_check_long(v.ptr(), ptr())) {
                return true;
            }
        } else if (v.isString()) {
            if (fast_equal_check_string(v.ptr(), ptr())) {
                return true;
            }
        } else {
            if (fast_equal_check_function(v.ptr(), ptr())) {
                return true;
            }
        }
    }
    return false;
}

Variant Variant::serialize() {
    smart_str serialized_data = {};
    php_serialize_data_t var_hash;
    PHP_VAR_SERIALIZE_INIT(var_hash);
    php_var_serialize(&serialized_data, ptr(), &var_hash TSRMLS_CC);
    PHP_VAR_SERIALIZE_DESTROY(var_hash);
    Variant retval(serialized_data.s->val, serialized_data.s->len);
    smart_str_free(&serialized_data);
    return retval;
}

Variant &Variant::operator++() {
    convert_to_long(ptr());
    ++Z_LVAL_P(ptr());
    return *this;
}

Variant &Variant::operator--() {
    convert_to_long(ptr());
    --Z_LVAL_P(ptr());
    return *this;
}

Int Variant::operator++(int) {
    convert_to_long(ptr());
    auto val = toInt();
    ++Z_LVAL_P(ptr());
    return val;
}

Int Variant::operator--(int) {
    convert_to_long(ptr());
    auto val = toInt();
    --Z_LVAL_P(ptr());
    return val;
}

Variant &Variant::operator+=(Int v) {
    convert_to_long(ptr());
    Z_LVAL_P(ptr()) += v;
    return *this;
}

Variant &Variant::operator-=(Int v) {
    convert_to_long(ptr());
    Z_LVAL_P(ptr()) -= v;
    return *this;
}

Variant Variant::operator()() const {
    return _call(nullptr, const_ptr());
}

Variant Variant::operator()(const std::initializer_list<Variant> &args) const {
    Args _args;
    for (const auto &arg : args) {
        _args.append(const_cast<Variant &>(arg).ptr());
    }
    return _call(nullptr, const_ptr(), _args);
}

Variant Variant::unserialize() {
    php_unserialize_data_t var_hash;
    Variant retval;
    PHP_VAR_UNSERIALIZE_INIT(var_hash);

    char *data = Z_STRVAL_P(ptr());
    size_t length = Z_STRLEN_P(ptr());
    if (php_var_unserialize(retval.ptr(), (const uchar **) &data, (const uchar *) data + length, &var_hash)) {
        return retval;
    } else {
        return {};
    }
}

Variant Variant::jsonEncode(zend_long options, zend_long depth) {
    smart_str buf = {};
    JSON_G(error_code) = PHP_JSON_ERROR_NONE;
    JSON_G(encode_max_depth) = (int) depth;

    php_json_encode(&buf, ptr(), (int) options);

    if (JSON_G(error_code) != PHP_JSON_ERROR_NONE && !(options & PHP_JSON_PARTIAL_OUTPUT_ON_ERROR)) {
        smart_str_free(&buf);
        return false;
    } else {
        smart_str_0(&buf);
        return buf.s;
    }
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
    Args args;
    object.call("__construct", args);
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
    object.call("__construct", _args);
    return object;
}

Variant Object::exec(const Variant &fn, const std::initializer_list<Variant> &args) {
    Args _args;
    for (const auto &arg : args) {
        _args.append(const_cast<Variant &>(arg).ptr());
    }
    return _call(ptr(), fn.const_ptr(), _args);
}
}  // namespace php
