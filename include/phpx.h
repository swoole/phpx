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

#pragma once

extern "C" {
#include "php.h"
#include "php_ini.h"
#include "php_main.h"

#if PHP_VERSION_ID < 80100
#error "only supports PHP-8.1 or later."
#endif

#include "zend_API.h"
#include "zend_interfaces.h"
#include "zend_exceptions.h"
#include "zend_variables.h"
#include "zend_types.h"

#include <ext/json/php_json.h>
#include <ext/standard/html.h>
#include <ext/standard/php_standard.h>
}

#if PHP_VERSION_ID < 80200
#define zend_string_toupper php_string_toupper
#endif

#include <unordered_map>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <memory>

#define PHPX_MAX_ARGC 10
#define PHPX_VAR_DUMP_LEVEL 10
#define PHPX_API PHPAPI
#define PHPX_UNSAFE

/**
 * !!! Unsafe conversion, discarding const modifier. There are many errors in the php src source code.
 * Many function parameters are read-only zvals, and the const modifier should be added.
 * However, the php code does not do this, resulting in C++ code unable to implement safe const functions.
 */
#define NO_CONST_V(_v) const_cast<zval *>(_v.const_ptr())
#define NO_CONST_Z(_z) const_cast<zval *>(_z)

namespace php {
typedef unsigned char uchar;
typedef zend_long Int;
typedef double Float;
typedef bool Bool;

struct Resource {
    const char *name;
    int type;
};

class Variant;
class Array;
class Object;
class String;
class Args;

using var = Variant;
using array = Array;
using object = Object;
using string = String;

using Var = Variant;
using Str = String;

enum TrimMode {
    TRIM_LEFT = 1,
    TRIM_RIGHT = 2,
    TRIM_BOTH = 3,
};

enum ZvalType {
    TYPE_UNDEF = IS_UNDEF,
    TYPE_NULL = IS_NULL,
    TYPE_FALSE = IS_FALSE,
    TYPE_TRUE = IS_TRUE,
    TYPE_LONG = IS_LONG,
    TYPE_DOUBLE = IS_DOUBLE,
    TYPE_STRING = IS_STRING,
    TYPE_ARRAY = IS_ARRAY,
    TYPE_OBJECT = IS_OBJECT,
    TYPE_RESOURCE = IS_RESOURCE,
    TYPE_REFERENCE = IS_REFERENCE,
};

PHPX_API void error(int level, const char *format, ...);
PHPX_API void echo(const char *format, ...);
PHPX_API void echo(const String &str);
PHPX_API void echo(const Variant &val);
PHPX_API void echo(Int val);
PHPX_API void echo(Float val);
PHPX_API Variant global(const String &name);
PHPX_API Variant include(const String &file);
PHPX_API Variant include_once(const String &file);
PHPX_API Variant require(const String &file);
PHPX_API Variant require_once(const String &file);
PHPX_API Variant eval(const String &script);
PHPX_API Variant call(const Variant &func, Args &args);
PHPX_API Variant call(const Variant &func, Array &args);
PHPX_API Variant call(const Variant &func, const std::initializer_list<Variant> &args);
PHPX_API void throwException(const char *name, const char *message, int code = 0);
PHPX_API Object catchException();
PHPX_API Variant concat(const Variant &a, const Variant &b);
PHPX_API Variant concat(const std::initializer_list<Variant> &args);
PHPX_API void exit(const Variant &status);
PHPX_API bool same(const Variant &a, const Variant &b);

static inline bool equals(Int a, Int b) {
    return a == b;
}

static inline bool equals(Float a, Float b) {
    return a == b;
}

PHPX_API bool equals(const Variant &a, const Variant &b);
PHPX_API int compare(const Variant &a, const Variant &b);

Int atoi(const String &str);
Resource *getResource(const std::string &name);

class Variant {
  protected:
    zval val;
    void destroy() {
        zval_ptr_dtor(&val);
    }
    void addRef() {
        Z_TRY_ADDREF_P(ptr());
    }
    void delRef() {
        Z_TRY_DELREF_P(ptr());
    }

  public:
    Variant() {
        ZVAL_NULL(&val);
    }
    Variant(nullptr_t) {
        ZVAL_NULL(&val);
    }
    Variant(long v) {
        ZVAL_LONG(&val, v);
    }
    Variant(int v) {
        ZVAL_LONG(&val, (long) v);
    }
    Variant(const char *str) {
        ZVAL_STRING(&val, str);
    }
    Variant(const char *str, size_t len) {
        ZVAL_STRINGL(&val, str, len);
    }
    /**
     * !!! [UNSAFE] `persistent` argument
     * When `persistent` is `true`, it will never be released until the process exits.
     * Please note that this approach is intended solely for global constant objects.
     */
    Variant(const char *str, size_t len, bool persistent) {
        ZVAL_NEW_STR(&val, zend_string_init(str, len, persistent));
        /**
         * There is a flaw in PHP's design: persistent strings cause assertion failures upon destruction.
         * By incrementing the reference count once, these strings are never released,
         * and are instead reclaimed automatically by the operating system when the process terminates.
         */
        if (persistent) {
            addRef();
        }
    }
    Variant(const std::string &str) {
        ZVAL_STRINGL(&val, str.c_str(), str.length());
    }
    Variant(double v) {
        ZVAL_DOUBLE(&val, v);
    }
    Variant(bool v) {
        ZVAL_BOOL(&val, v);
    }
    Variant(const zval *v) noexcept {
        if (UNEXPECTED(!v)) {
            ZVAL_NULL(&val);
        } else {
            ZVAL_COPY(&val, v);
        }
    }
    Variant(zend_string *s) noexcept {
        ZVAL_STR(&val, zend_string_copy(s));
    }
    Variant(const Variant &v) : Variant(v.const_ptr()) {}
    Variant(Variant &&v) noexcept {
        memcpy(&val, &v.val, sizeof(zval));
        v.val = {};
    }
    Variant(const Variant *v) {
        ZVAL_NEW_REF(&val, v->const_ptr());
        zval_add_ref(Z_REFVAL(val));
    }
    /**
     * !!! [UNSAFE]
     * This constructor is unsafe and should be used with caution.
     * The `res` Must be a new reference passed in from outside;
     * it no longer requires adding application logic and is solely used for the newResource invocation.
     */
    Variant(zend_resource *res) {
        ZVAL_RES(ptr(), res);
    }
    ~Variant() {
        destroy();
    }
    Variant &operator=(int v) {
        destroy();
        ZVAL_LONG(ptr(), (long) v);
        return *this;
    }
    Variant &operator=(long v) {
        destroy();
        ZVAL_LONG(ptr(), v);
        return *this;
    }
    Variant &operator=(const std::string &str) {
        destroy();
        ZVAL_STRINGL(ptr(), str.c_str(), str.length());
        return *this;
    }
    Variant &operator=(const char *str) {
        destroy();
        ZVAL_STRING(ptr(), str);
        return *this;
    }
    Variant &operator=(double v) {
        destroy();
        ZVAL_DOUBLE(ptr(), v);
        return *this;
    }
    Variant &operator=(bool v) {
        destroy();
        ZVAL_BOOL(ptr(), v);
        return *this;
    }
    Variant &operator=(zend_string *v) {
        destroy();
        ZVAL_STR(ptr(), zend_string_copy(v));
        return *this;
    }
    Variant &operator=(const zval *v);
    Variant &operator=(const Variant &v);
    Variant &operator=(const Variant *v);
    Variant &operator=(nullptr_t) {
        destroy();
        ZVAL_NULL(&val);
        return *this;
    }
    void unset() {
        destroy();
        val = {};
    }
    zval *ptr() {
        return &val;
    }
    static PHPX_UNSAFE Variant from(zval *v) {
        Variant retval{v};
        zval_ptr_dtor(v);
        return retval;
    }
    zend_array *array() const {
        return Z_ARRVAL_P(&val);
    }
    zend_class_entry *ce() const {
        return Z_OBJCE_P(&val);
    }
    zend_object *object() const {
        return Z_OBJ_P(&val);
    }
    const zval *const_ptr() const {
        return &val;
    }
    void debug();
    void print() {
        php_var_dump(&val, 10);
    }
    int getRefCount() const;
    int type() const {
        return Z_TYPE_P(const_ptr());
    }
    const char *typeStr() const {
        return zend_get_type_by_const(type());
    }
    bool isString() const {
        return Z_TYPE_P(const_ptr()) == IS_STRING;
    }
    bool isArray() const {
        return Z_TYPE_P(const_ptr()) == IS_ARRAY;
    }
    bool isObject() const {
        return Z_TYPE_P(const_ptr()) == IS_OBJECT;
    }
    bool isInt() const {
        return Z_TYPE_P(const_ptr()) == IS_LONG;
    }
    bool isFloat() const {
        return Z_TYPE_P(const_ptr()) == IS_DOUBLE;
    }
    bool isBool() const {
        return Z_TYPE_P(const_ptr()) == IS_TRUE || Z_TYPE_P(const_ptr()) == IS_FALSE;
    }
    bool isFalse() const {
        return Z_TYPE_P(const_ptr()) == IS_FALSE;
    }
    bool isTrue() const {
        return Z_TYPE_P(const_ptr()) == IS_TRUE;
    }
    bool isNull() const {
        return Z_TYPE_P(const_ptr()) == IS_NULL;
    }
    bool isUndef() const {
        return Z_TYPE_P(const_ptr()) == IS_UNDEF;
    }
    bool isResource() const {
        return Z_TYPE_P(const_ptr()) == IS_RESOURCE;
    }
    bool isReference() const {
        return Z_TYPE_P(const_ptr()) == IS_REFERENCE;
    }
    bool isNumeric() const;
    bool empty() const {
        return toBool() == false;
    }
    std::string toStdString() const;
    String toString() const;
    /**
     * This function is not read-only.
     * If the current variable is not a string, it will be auto converted to a string
     */
    PHPX_UNSAFE const char *toCString() {
        convert_to_string(&val);
        return Z_STRVAL(val);
    }
    Int toInt() const {
        return zval_get_long(const_cast<zval *>(&val));
    }
    double toFloat() const {
        return zval_get_double(const_cast<zval *>(&val));
    }
    bool toBool() const {
        return zval_is_true(const_cast<zval *>(&val));
    }
    Array toArray() const;
    Object toObject() const;
    size_t length() const;
    template <class T>
    T *toResource(const char *name) {
        if (!isResource()) {
            error(E_WARNING, "This variant is not a resource type.");
            return nullptr;
        }
        void *_ptr = nullptr;
        Resource *_c = getResource(name);
        if (_c == nullptr) {
            return nullptr;
        }
        if ((_ptr = zend_fetch_resource(Z_RES_P(ptr()), name, _c->type)) == nullptr) {
            error(E_WARNING, "The `%s` type of resource is undefined.", name);
            return nullptr;
        }
        return static_cast<T *>(_ptr);
    }
    Variant toReference() {
        if (isReference()) {
            return *this;
        }
        return {this};
    }
    Variant getRefValue() const;
    Variant operator*() const {
        return getRefValue();
    }
    void moveTo(zval *dest) {
        ZVAL_COPY_VALUE(dest, &val);
        val = {};
    }

    Variant offsetGet(zend_long offset) const;
    Variant offsetGet(const Variant &key) const;
    bool offsetExists(zend_long offset) const;
    bool offsetExists(const Variant &key) const;
    void offsetSet(zend_long offset, const Variant &value);
    void offsetSet(const Variant &key, const Variant &value);
    void offsetUnset(zend_long offset);
    void offsetUnset(const Variant &key);

    Variant getProperty(const Variant &name) const;
    void setProperty(const Variant &name, const Variant &value) const;
    Variant readProperty(zend_string *prop_name) const;
    void updateProperty(zend_string *prop_name, const Variant &value) const;
    void unsetProperty(const Variant &name);
    void deleteProperty(zend_string *prop_name);

    bool operator==(const Variant &v) const {
        return equals(v);
    }
    bool operator!=(const Variant &v) const {
        return !equals(v);
    }
    bool operator<(const Variant &v) const;
    bool operator>(const Variant &v) const;
    bool operator<=(const Variant &v) const;
    bool operator>=(const Variant &v) const;

    bool equals(const Variant &v, bool strict = false) const;
    bool almostEquals(const Variant &v, double eps = 1e-9) const {
        return std::fabs(toFloat() - v.toFloat()) <= eps;
    }

    bool same(const Variant &v) const {
        return equals(v, true);
    }
    Variant jsonEncode(zend_long options = 0, zend_long depth = PHP_JSON_PARSER_DEFAULT_DEPTH);
    Variant jsonDecode(zend_long options = 0, zend_long depth = PHP_JSON_PARSER_DEFAULT_DEPTH);
    Variant serialize();
    Variant unserialize();
    bool isCallable();

    // Incrementing/Decrementing Operators
    Variant &operator++();
    Variant &operator--();
    Variant operator++(int);
    Variant operator--(int);
    // Binary operators
    Variant &operator+=(const Variant &);
    Variant &operator-=(const Variant &);
    Variant &operator/=(const Variant &);
    Variant &operator*=(const Variant &);
    Variant &operator%=(const Variant &);
    Variant &operator<<=(const Variant &);
    Variant &operator>>=(const Variant &);
    Variant &operator&=(const Variant &);
    Variant &operator|=(const Variant &);
    Variant &operator^=(const Variant &);
    Variant operator+(const Variant &) const;
    Variant operator-(const Variant &) const;
    Variant operator*(const Variant &) const;
    Variant operator/(const Variant &) const;
    Variant operator%(const Variant &) const;
    Variant operator<<(const Variant &) const;
    Variant operator>>(const Variant &) const;
    Variant operator&(const Variant &) const;
    Variant operator|(const Variant &) const;
    Variant operator^(const Variant &) const;
    // Unary operators
    Variant operator~() const;
    Variant operator-() const;
    bool operator!() const noexcept {
        return !toBool();
    }
    // Exponential expression
    Variant pow(const Variant &) const;
    // Concatenates two strings, return new string.
    Variant concat(const Variant &) const;
    /**
     * Concatenates the specified string to the end of this string.
     * This function is unsafe, only supporting array and string types.
     * If the type is an array, it will append elements;
     * otherwise, if the variable is not a string type, this variable will be converted into a string
     */
    PHPX_UNSAFE void append(const Variant &);

    Variant operator()() const;
    explicit operator bool() const noexcept {
        return toBool();
    }
    Variant operator()(const std::initializer_list<Variant> &args) const;

    /* generator */
    Variant operator()(const Variant &v1) const;
    Variant operator()(const Variant &v1, const Variant &v2) const;
    Variant operator()(const Variant &v1, const Variant &v2, const Variant &v3) const;
    Variant operator()(const Variant &v1, const Variant &v2, const Variant &v3, const Variant &v4) const;
    Variant operator()(
        const Variant &v1, const Variant &v2, const Variant &v3, const Variant &v4, const Variant &v5) const;
    Variant operator()(const Variant &v1,
                       const Variant &v2,
                       const Variant &v3,
                       const Variant &v4,
                       const Variant &v5,
                       const Variant &v6) const;
    Variant operator()(const Variant &v1,
                       const Variant &v2,
                       const Variant &v3,
                       const Variant &v4,
                       const Variant &v5,
                       const Variant &v6,
                       const Variant &v7) const;
    Variant operator()(const Variant &v1,
                       const Variant &v2,
                       const Variant &v3,
                       const Variant &v4,
                       const Variant &v5,
                       const Variant &v6,
                       const Variant &v7,
                       const Variant &v8) const;
    Variant operator()(const Variant &v1,
                       const Variant &v2,
                       const Variant &v3,
                       const Variant &v4,
                       const Variant &v5,
                       const Variant &v6,
                       const Variant &v7,
                       const Variant &v8,
                       const Variant &v9) const;
    Variant operator()(const Variant &v1,
                       const Variant &v2,
                       const Variant &v3,
                       const Variant &v4,
                       const Variant &v5,
                       const Variant &v6,
                       const Variant &v7,
                       const Variant &v8,
                       const Variant &v9,
                       const Variant &v10) const;
    /* generator */
};

extern Variant null;

template <typename T>
Variant newResource(const char *name, T *v) {
    const auto _c = getResource(name);
    if (!_c) {
        error(E_WARNING, "%s type of resource is undefined.", name);
        return {};
    }
    zend_resource *res = zend_register_resource(static_cast<void *>(v), _c->type);
    return {res};
}

Variant newReference();

#ifndef ZEND_HASH_ELEMENT
#define ZEND_HASH_ELEMENT(ht, idx) &HT_HASH_TO_BUCKET(ht, idx)->val
#endif

template <typename T>
static inline Variant operator+(T a, const Variant &b) {
    return Variant(a) + b;
}

template <typename T>
static inline Variant operator-(T a, const Variant &b) {
    return Variant(a) - b;
}

template <typename T>
static inline Variant operator*(T a, const Variant &b) {
    return Variant(a) * b;
}

template <typename T>
static inline Variant operator/(T a, const Variant &b) {
    return Variant(a) / b;
}

template <typename T>
static inline Variant operator%(T a, const Variant &b) {
    return Variant(a) % b;
}

template <typename T>
static inline Variant operator<<(T a, const Variant &b) {
    return Variant(a) << b;
}

template <typename T>
static inline Variant operator>>(T a, const Variant &b) {
    return Variant(a) >> b;
}

template <typename T>
static inline Variant operator&(T a, const Variant &b) {
    return Variant(a) & b;
}

template <typename T>
static inline Variant operator|(T a, const Variant &b) {
    return Variant(a) | b;
}

template <typename T>
static inline Variant operator^(T a, const Variant &b) {
    return Variant(a) ^ b;
}

template <typename T>
static inline Variant operator<=(T a, const Variant &b) {
    return Variant(a) <= b;
}

template <typename T>
static inline Variant operator<(T a, const Variant &b) {
    return Variant(a) < b;
}

template <typename T>
static inline Variant operator>=(T a, const Variant &b) {
    return Variant(a) >= b;
}

template <typename T>
static inline Variant operator>(T a, const Variant &b) {
    return Variant(a) > b;
}

template <typename T>
static inline Variant operator==(T a, const Variant &b) {
    return Variant(a) == b;
}

class String : public Variant {
  public:
    String() {
        ZVAL_EMPTY_STRING(&val);
    }
    String(const zval *v);
    String(const Variant &v);
    String(int v) {
        ZVAL_STR(ptr(), zend_long_to_str(v));
    }
    String(long v) {
        ZVAL_STR(ptr(), zend_long_to_str(v));
    }
    String(double v) {
        ZVAL_STR(ptr(), zend_strpprintf(0, "%.*G", (int) EG(precision), v));
    }
    String(bool v) {
        ZVAL_STR(ptr(), zend_string_init(v ? "1" : "0", 1, false));
    }
    String(zend_string *v) {
        ZVAL_STR(ptr(), zend_string_copy(v));
    }
    String(const std::string &v) : Variant(v) {}
    String(const char *v) : Variant(v) {}
    String(const char *str, size_t len) : Variant(str, len) {}
    String(const char *str, size_t len, bool persistent) : Variant(str, len, persistent) {}
    ~String() {
        /**
         * There are some design flaws in ZendVM's garbage collection. The destructor checks whether an object is a root
         * object, and assertions only allow for array or object types; string types will crash directly. Strings do not
         * have circular references, so they can be manually released to bypass the garbage collector's check for
         * circular references.
         */
        zend_string_release(str());
        val = {};
    }
    bool isNumeric() const {
        return is_numeric_string(data(), length(), nullptr, nullptr, false);
    }
    size_t length() const {
        return Z_STRLEN(val);
    }
    const char *data() const {
        return Z_STRVAL(val);
    }
    uint64_t hashCode() const {
        return zend_string_hash_val(str());
    }
    bool equals(const char *s, size_t slen) const {
        return length() == slen && memcmp(data(), s, slen) == 0;
    }
    bool equals(const std::string &s) const {
        return equals(s.c_str(), s.length());
    }
    bool equals(const char *s) const {
        return equals(s, strlen(s));
    }
    bool equals(const String &s, bool ci = false) const;
    bool equals(const Variant &v, bool ci = false) const {
        return Variant::equals(v, ci);
    }
    bool operator==(const String &v) const {
        return equals(v);
    }
    static String format(const char *format, ...);
    String trim(const char *what = " \t\n\r\v\0", TrimMode mode = TRIM_BOTH) const;
    String lower() const {
        return from(zend_string_tolower(str()));
    }
    String upper() const {
        return from(zend_string_toupper(str()));
    }
    String base64Encode() const {
        return from(php_base64_encode_str(str()));
    }
    String base64Decode() const {
        return from(php_base64_decode_str(str()));
    }
    String escape(const int flags = ENT_QUOTES | ENT_SUBSTITUTE, const char *charset = PHP_DEFAULT_CHARSET) const {
        return from(php_escape_html_entities((uchar *) data(), length(), 0, flags, charset));
    }
    String unescape(const int flags = ENT_QUOTES | ENT_SUBSTITUTE, const char *charset = PHP_DEFAULT_CHARSET) const {
        return from(php_unescape_html_entities(str(), 1, flags, charset));
    }

    Array split(const String &delim, long = ZEND_LONG_MAX) const;
    String substr(long _offset, long _length = -1) const;
    String stripTags(const String &allow, bool allow_tag_spaces = false) const;
    String addSlashes() const;
    String stripSlashes() const;
    String basename(const String &suffix) const;
    String dirname() const;
    void print() const;

    zend_string *str() const {
        return Z_STR(val);
    }
    /**
     * This function is unsafe, lacks GC, and takes a new reference to a `zend_string`.
     * The String object will acquire its ownership, and the external code must not use the `zend_string` pointer again.
     * The second from method below behaves in the same way as this method,
     * except it takes a new reference to a zval and is not repeated here.
     */
    PHPX_UNSAFE static String from(zend_string *v) {
        String result{v};
        zend_string_release(v);
        return result;
    }
    PHPX_UNSAFE static String from(zval *v) {
        String result{v};
        zval_ptr_dtor(v);
        return result;
    }
};

class ArrayKeyValue {
  public:
    Variant key;
    Variant value;
    ArrayKeyValue(Variant _key, Variant _value) : key(std::move(_key)), value(std::move(_value)) {}
};

class ArrayIterator {
    zend_array *array_;
    zend_ulong idx_;

  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = ArrayKeyValue;
    using difference_type = std::ptrdiff_t;
    using reference = value_type;
    using pointer = void;

    ArrayIterator(zend_array *array, zend_ulong idx) {
        array_ = array;
        idx_ = idx;
        skipUndefBucket();
    }
    ArrayIterator operator++(int) {
        ArrayIterator tmp = *this;
        next();
        return tmp;
    }
    ArrayIterator &operator++() {
        next();
        return *this;
    }
    value_type operator*() const {
        return {key(), value()};
    }
    bool operator!=(const ArrayIterator &b) const {
        return b.index() != index();
    }
    bool operator==(const ArrayIterator &b) const {
        return b.index() == index();
    }
    Variant key() const;
    Variant value() const {
        return current();
    }
    zend_ulong index() const {
        return idx_;
    }
    void next() {
        ++idx_;
        skipUndefBucket();
    }
    zval *current() const {
        if (UNEXPECTED(!array_ || idx_ >= array_->nNumUsed)) {
            return nullptr;
        } else {
            return ZEND_HASH_ELEMENT(array_, idx_);
        }
    }

  private:
    void skipUndefBucket();
};

class ArrayItem : public Variant {
  private:
    Array &array_;
    zend_ulong index_;
    zend_string *key_;

  public:
    ArrayItem(Array &_array, zend_ulong _index, zend_string *_key);
    ~ArrayItem() {
        if (key_) {
            zend_string_release(key_);
        }
    }
    ArrayItem &operator=(const Variant &v);
};

extern int array_data_compare(Bucket *f, Bucket *s);

class Array : public Variant {
    void copyFrom(const std::initializer_list<const Variant> &list);
    void copyFrom(const std::initializer_list<std::pair<const std::string, const Variant>> &list);
    void copyFrom(const std::initializer_list<std::pair<Int, const Variant>> &list);

  public:
    Array() {
        array_init(&val);
    }
    Array(const zval *v);
    Array(const Variant &v);
    Array(const std::initializer_list<const Variant> &list);
    Array(const std::initializer_list<std::pair<const std::string, const Variant>> &list);
    Array(const std::initializer_list<std::pair<Int, const Variant>> &list);

    Array &operator=(const std::initializer_list<const Variant> &list);
    Array &operator=(const std::initializer_list<std::pair<const std::string, const Variant>> &list);
    Array &operator=(const std::initializer_list<std::pair<Int, const Variant>> &list);

    void set(const String &s, const Variant &v);
    void set(zend_ulong i, const Variant &v);
    Variant get(const String &key) const {
        return zend_hash_find(Z_ARRVAL_P(const_ptr()), key.str());
    }
    Variant get(zend_ulong i) const {
        return zend_hash_index_find(Z_ARRVAL_P(const_ptr()), i);
    }
    ArrayItem operator[](zend_ulong i) {
        return {*this, i, nullptr};
    }
    ArrayItem operator[](int i) {
        return {*this, (zend_ulong) i, nullptr};
    }
    ArrayItem operator[](const String &key) {
        return {*this, 0, key.str()};
    }
    bool del(zend_ulong index) {
        SEPARATE_ARRAY(ptr());
        return zend_hash_index_del(Z_ARRVAL_P(ptr()), index) == SUCCESS;
    }
    bool del(const String &key) {
        SEPARATE_ARRAY(ptr());
        return zend_hash_del(Z_ARRVAL_P(ptr()), key.str()) == SUCCESS;
    }
    void clean() {
        SEPARATE_ARRAY(ptr());
        zend_hash_clean(Z_ARRVAL_P(ptr()));
    }
    bool exists(zend_ulong index) const {
        return zend_hash_index_exists(Z_ARRVAL_P(const_ptr()), index);
    }
    bool exists(const String &key) const {
        return zend_hash_exists(Z_ARRVAL_P(const_ptr()), key.str());
    }
    ArrayIterator begin() const {
        return {Z_ARRVAL_P(const_ptr()), 0};
    }
    ArrayIterator end() const {
        const auto ht = Z_ARRVAL_P(const_ptr());
        return {ht, ht->nNumUsed};
    }
    size_t count() const {
        return zend_hash_num_elements(Z_ARRVAL_P(const_ptr()));
    }
    bool empty() const {
        return count() == 0;
    }
    Variant search(const Variant &_other_var, bool strict = false) const;
    bool contains(const Variant &_other_var, bool strict = false) const;
    String join(const String &delim);
    void merge(const Array &source) {
        SEPARATE_ARRAY(ptr());
        php_array_merge(array(), source.array());
    }
    void sort(bool renumber = true) {
        SEPARATE_ARRAY(ptr());
        zend_hash_sort(Z_ARRVAL_P(ptr()), array_data_compare, renumber);
    }
    Array slice(long offset, long length = -1, bool preserve_keys = false);
};

class Args {
    std::vector<Variant> params;

  public:
    Args() {}
    Args(size_t n) {
        params.reserve(n);
    }
    void append(const Variant &v) {
        params.emplace_back(v);
    }
    size_t count() const {
        return params.size();
    }
    bool exists(const size_t i) const {
        return i < count();
    }
    bool empty() const {
        return params.empty();
    }
    zval *ptr() {
        return reinterpret_cast<zval *>(params.data());
    }
    Variant get(size_t i) const;
    Array toArray() const;
    Variant operator[](size_t i) const {
        return get(i);
    }
};

extern Variant _call(const zval *object, const zval *func, Args &args);
extern Variant _call(const zval *object, const zval *func);

static inline Variant call(const Variant &func) {
    return _call(nullptr, func.const_ptr());
}

static inline zend_class_entry *getClassEntry(const String &name) {
    return zend_lookup_class(name.str());
}

class Object : public Variant {
  public:
    Object(const zval *v) : Variant(v) {
        if (!isUndef() && !isObject()) {
            error(E_ERROR, "parameter 1 must be `object`, got `%s`", typeStr());
        }
    }
    Object(const Variant &v) : Object(v.const_ptr()) {}
    Object() = default;
    Variant call(const Variant &func, Args &args) {
        return _call(ptr(), func.const_ptr(), args);
    }
    zend_class_entry *parent_ce() {
        return Z_OBJCE_P(ptr())->parent;
    }
    Variant callParentMethod(const String &func, const std::initializer_list<Variant> &args);
    Variant exec(const Variant &fn) {
        return _call(ptr(), fn.const_ptr());
    }
    Variant exec(const Variant &fn, const std::initializer_list<Variant> &args);

    /* generator */
    Variant exec(const Variant &fn, const Variant &v1);
    Variant exec(const Variant &fn, const Variant &v1, const Variant &v2);
    Variant exec(const Variant &fn, const Variant &v1, const Variant &v2, const Variant &v3);
    Variant exec(const Variant &fn, const Variant &v1, const Variant &v2, const Variant &v3, const Variant &v4);
    Variant exec(const Variant &fn,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5);
    Variant exec(const Variant &fn,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5,
                 const Variant &v6);
    Variant exec(const Variant &fn,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5,
                 const Variant &v6,
                 const Variant &v7);
    Variant exec(const Variant &fn,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5,
                 const Variant &v6,
                 const Variant &v7,
                 const Variant &v8);
    Variant exec(const Variant &fn,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5,
                 const Variant &v6,
                 const Variant &v7,
                 const Variant &v8,
                 const Variant &v9);
    Variant exec(const Variant &fn,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5,
                 const Variant &v6,
                 const Variant &v7,
                 const Variant &v8,
                 const Variant &v9,
                 const Variant &v10);
    /* generator */

    Variant get(const String &name) const;
    void set(const String &name, const Variant &v) const {
        updateProperty(name.str(), v);
    }
    template <class T>
    T *oGet(const String &name, const char *resource_name) {
        auto prop = get(name);
        return prop.toResource<T>(resource_name);
    }
    template <class T>
    void oSet(const String &name, const char *resource_name, T *ptr) {
        set(name, newResource<T>(resource_name, ptr));
    }
    String getClassName() const {
        return ce()->name;
    }
    uint32_t getId() const {
        return Z_OBJ_HANDLE(val);
    }
    String hash() const;
    bool methodExists(const String &name) const {
        return zend_hash_exists(&ce()->function_table, name.str());
    }
    bool propertyExists(const String &name) const {
        return zend_hash_exists(&ce()->properties_info, name.str());
    }
    bool instanceOf(const String &name) const {
        return instanceof_function(ce(), getClassEntry(name));
    }
    bool instanceOf(const zend_class_entry *ce_) const {
        return instanceof_function(ce(), ce_);
    }
    Object clone() const;
};

typedef void (*resource_dtor)(zend_resource *);

#define PHPX_EXTENSION()                                                                                               \
    extern "C" {                                                                                                       \
    ZEND_DLEXPORT Extension *get_module();                                                                             \
    }                                                                                                                  \
    ZEND_DLEXPORT Extension *get_module()

struct StrCmp {
    bool operator()(const char *s1, const char *s2) const {
        return strcmp(s1, s2) < 0;
    }
};

class Function;
class Method;

extern std::map<const char *, std::map<const char *, Method *, StrCmp>, StrCmp> method_map;
extern std::map<const char *, Function *, StrCmp> function_map;

#define PHPX_FN(n) #n, n
#define PHPX_ME(c, m) #m, c##_##m

class Function {
    const char *name_;

  public:
    explicit Function(const char *name) {
        name_ = name;
    }
    virtual ~Function() = default;
    virtual Variant impl(Args &) = 0;
};

#define PHPX_FUNCTION(func)                                                                                            \
    class phpx_function_##func : Function {                                                                            \
      public:                                                                                                          \
        Variant impl(Args &);                                                                                          \
        explicit phpx_function_##func(const char *name) : Function(name) {                                             \
            function_map[name] = this;                                                                                 \
        }                                                                                                              \
        ~phpx_function_##func() {}                                                                                     \
    };                                                                                                                 \
    static phpx_function_##func f_##func(#func);                                                                       \
    PHP_FUNCTION(func) {}                                                                                              \
    Variant phpx_function_##func::impl(Args &args)

class Method {
    const char *class_;
    const char *name_;

  public:
    Method(const char *_class, const char *_name) {
        name_ = _name;
        class_ = _class;
    }
    virtual ~Method() = default;
    virtual Variant impl(Object &, Args &) = 0;
};

#define PHPX_METHOD(class_, method)                                                                                    \
    class phpx_method_##class_##_##method : Method {                                                                   \
      public:                                                                                                          \
        Variant impl(Object &_this, Args &);                                                                           \
        phpx_method_##class_##_##method(const char *_class, const char *_name) : Method(_class, _name) {               \
            method_map[_class][_name] = this;                                                                          \
        }                                                                                                              \
        ~phpx_method_##class_##_##method() {}                                                                          \
    };                                                                                                                 \
    static phpx_method_##class_##_##method m_##class_##_##method(#class_, #method);                                    \
    PHP_METHOD(class_, method) {}                                                                                      \
    Variant phpx_method_##class_##_##method::impl(Object &_this, Args &args)

extern void _exec_function(zend_execute_data *data, zval *return_value);
extern void _exec_method(zend_execute_data *data, zval *return_value);

zend_function_entry *copy_function_entries(const zend_function_entry *_functions);

enum ClassFlags {
    STATIC = ZEND_ACC_STATIC,
    ABSTRACT = ZEND_ACC_ABSTRACT,
    FINAL = ZEND_ACC_FINAL,
    INTERFACE = ZEND_ACC_INTERFACE,
    TRAIT = ZEND_ACC_TRAIT,
    PUBLIC = ZEND_ACC_PUBLIC,
    PROTECTED = ZEND_ACC_PROTECTED,
    PRIVATE = ZEND_ACC_PRIVATE,
    CONSTRUCT = ZEND_ACC_CTOR,
#ifdef ZEND_ACC_DTOR
    DESTRUCT = ZEND_ACC_DTOR,
#else
    DESTRUCT = 0,
#endif
#ifdef ZEND_ACC_CLONE
    CLONE = ZEND_ACC_CLONE,
#else
    CLONE = 0,
#endif
};

enum SortFlags {
    SORT_REGULAR = 0,
    SORT_NUMERIC = 1,
    SORT_STRING = 2,
    SORT_DESC = 3,
    SORT_ASC = 4,
    SORT_LOCALE_STRING = 5,
    SORT_NATURAL = 6,
    SORT_FLAG_CASE = 8,
};

class Interface;

class Class {
    struct Property {
        std::string name;
        zval value;
        int flags;
    };

    struct Constant {
        std::string name;
        zval value;
    };

  public:
    explicit Class(const char *name);
    bool extends(zend_class_entry *_parent_class);
    bool extends(Class *parent);
    bool implements(zend_class_entry *if_ce);
    bool implements(const Interface *);
    bool addConstant(const char *name, const Variant &v);
    bool addProperty(const char *name, const Variant &v, int flags);
    bool addStaticProperty(const char *name, const Variant &v, int flags);
    bool registerFunctions(const zend_function_entry *functions);
    bool activate();
    bool alias(const char *alias_name);

    const std::string &getName() {
        return class_name;
    }

    zend_class_entry *ptr() const {
        return ce;
    }

    static Variant getStaticProperty(const char *name, const std::string &prop);
    static bool setStaticProperty(const char *name, const std::string &prop, const Variant &value);

  protected:
    bool activated;
    std::string class_name;
    std::string parent_class_name;
    zend_class_entry *parent_ce;
    zend_class_entry _ce{};
    zend_class_entry *ce;
    std::vector<zend_class_entry *> interfaces;
    zend_function_entry *functions;
    std::vector<Property> properties;
    std::vector<Constant> constants;
    std::vector<std::string> aliases;
};

class Interface {
  public:
    explicit Interface(const char *name);
    std::string getName() {
        return name;
    }
    void registerFunctions(const zend_function_entry *_functions) {
        functions = _functions;
    }
    bool activate();

    zend_class_entry *ptr() const {
        return ce;
    }

  protected:
    bool activated = false;
    std::string name;
    zend_class_entry _ce{};
    zend_class_entry *ce;
    const zend_function_entry *functions;
};

static inline Int to_int(Int v) {
    return v;
}

static inline Int to_int(const Variant &v) {
    return v.toInt();
}

static inline Float to_float(Float v) {
    return v;
}

static inline Float to_float(const Variant &v) {
    return v.toFloat();
}

Array to_array(const Variant &v);

static inline bool to_bool(bool v) {
    return v;
}

static inline bool to_bool(const Variant &v) {
    return v.toBool();
}

static inline void echo(int val) {
    echo((Int) val);
}

extern zend_result extension_startup(int type, int module_number);
extern void extension_info(zend_module_entry *module);
extern zend_result extension_shutdown(int type, int module_number);
extern zend_result extension_before_request(int type, int module_number);
extern zend_result extension_after_request(int type, int module_number);

class Extension {
    struct IniEntry {
        std::string name;
        std::string default_value;
        int modifiable;
    };

  protected:
    zend_module_entry module = {
        STANDARD_MODULE_HEADER_EX,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        extension_startup,
        extension_shutdown,
        extension_before_request,
        extension_after_request,
        extension_info,
        nullptr,
        STANDARD_MODULE_PROPERTIES,
    };

    friend zend_result extension_startup(int type, int module_number);
    friend zend_result extension_shutdown(int type, int module_number);
    bool started = false;

    int function_count = 0;
    int deps_count = 0;
    int function_array_size = 0;

    zend_function_entry *functions;
    std::vector<IniEntry> ini_entries;
    std::vector<zend_module_dep> deps_;

    void registerIniEntries(int module_number);
    void unregisterIniEntries(int module_number) const;

  public:
    enum StartupStatus {
        BEFORE_START,
        AFTER_START,
    };

    std::string name;
    std::string version;

    std::function<void()> onStart = nullptr;
    std::function<void()> onShutdown = nullptr;
    std::function<void()> onBeforeRequest = nullptr;
    std::function<void()> onAfterRequest = nullptr;

    std::vector<std::string> header;
    std::vector<std::vector<std::string>> body;

    Extension(const char *name, const char *version);
    void checkStartupStatus(StartupStatus status, const char *func) const;

    bool registerClass(Class *c) const;
    bool registerInterface(Interface *i) const;
    bool registerFunctions(const zend_function_entry *functions);
    bool registerResource(const char *name, resource_dtor dtor) const;
    void registerConstant(const char *name, long v) const;
    void registerConstant(const char *name, int v) const;
    void registerConstant(const char *name, bool v) const;
    void registerConstant(const char *name, double v) const;
    void registerConstant(const char *name, const char *v) const;
    void registerConstant(const char *name, const char *v, size_t len) const;
    void registerConstant(const char *name, const std::string &v) const;

    void require(const char *name, const char *version = nullptr);

    void info(const std::vector<std::string> &header, const std::vector<std::vector<std::string>> &body) {
        this->header = header;
        this->body = body;
    }

    // modifiable can be one of these:PHP_INI_SYSTEM/PHP_INI_PERDIR/PHP_INI_USER/PHP_INI_ALL
    void addIniEntry(const char *name, const char *default_value = "", int modifiable = PHP_INI_ALL);
    void printInfo() const;
};

extern Object newObject(const char *name);
extern Object newObject(const char *name, const std::initializer_list<Variant> &args);
/* generator */
extern Object newObject(const char *name, const Variant &v1);
extern Object newObject(const char *name, const Variant &v1, const Variant &v2);
extern Object newObject(const char *name, const Variant &v1, const Variant &v2, const Variant &v3);
extern Object newObject(const char *name, const Variant &v1, const Variant &v2, const Variant &v3, const Variant &v4);
extern Object newObject(
    const char *name, const Variant &v1, const Variant &v2, const Variant &v3, const Variant &v4, const Variant &v5);
extern Object newObject(const char *name,
                        const Variant &v1,
                        const Variant &v2,
                        const Variant &v3,
                        const Variant &v4,
                        const Variant &v5,
                        const Variant &v6);
extern Object newObject(const char *name,
                        const Variant &v1,
                        const Variant &v2,
                        const Variant &v3,
                        const Variant &v4,
                        const Variant &v5,
                        const Variant &v6,
                        const Variant &v7);
extern Object newObject(const char *name,
                        const Variant &v1,
                        const Variant &v2,
                        const Variant &v3,
                        const Variant &v4,
                        const Variant &v5,
                        const Variant &v6,
                        const Variant &v7,
                        const Variant &v8);
extern Object newObject(const char *name,
                        const Variant &v1,
                        const Variant &v2,
                        const Variant &v3,
                        const Variant &v4,
                        const Variant &v5,
                        const Variant &v6,
                        const Variant &v7,
                        const Variant &v8,
                        const Variant &v9);
extern Object newObject(const char *name,
                        const Variant &v1,
                        const Variant &v2,
                        const Variant &v3,
                        const Variant &v4,
                        const Variant &v5,
                        const Variant &v6,
                        const Variant &v7,
                        const Variant &v8,
                        const Variant &v9,
                        const Variant &v10);
/* generator */
}  // namespace php
