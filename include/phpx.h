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

/**
 * Do not trust any header files of PHP, its internal implementation is very chaotic,
 * which must be wrapped in extern "C" {}
 */
extern "C" {
#include "php.h"
#include "zend_ini.h"
#include "zend_interfaces.h"
#include "zend_exceptions.h"

#include <ext/standard/php_standard.h>
#include <ext/json/php_json.h>
}

#include "phpx_types.h"

#if PHP_VERSION_ID < 80100
#error "only supports PHP-8.1 or later."
#endif

#include <unordered_map>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <memory>

#define PHPX_MAX_ARGC 10

/**
 * All API names must be in lowercase camel case.
 */
#define PHPX_API PHPAPI
#define PHPX_UNSAFE

/**
 * !!! Unsafe conversion, discarding const modifier. There are many errors in the php src source code.
 * Many function parameters are read-only zvals, and the const modifier should be added.
 * However, the php code does not do this, resulting in C++ code unable to implement safe const functions.
 */
#define NO_CONST_V(_v) const_cast<zval *>(_v.unwrap_ptr())
#define NO_CONST_Z(_z) const_cast<zval *>(_z)
#define NO_CONST_UNWRAP_Z(_z) const_cast<zval *>(unwrap_zval(_z))

namespace php {

enum TrimMode {
    TRIM_LEFT = 1,
    TRIM_RIGHT = 2,
    TRIM_BOTH = 3,
};

enum IncludeType {
    INCLUDE = ZEND_INCLUDE,
    INCLUDE_ONCE = ZEND_INCLUDE_ONCE,
    REQUIRE = ZEND_REQUIRE,
    REQUIRE_ONCE = ZEND_REQUIRE_ONCE,
};

enum Operation {
    ArrayDimFetch,
    PropertyFetch,
};

PHPX_API void error(int level, const char *format, ...);
PHPX_API void echo(const char *format, ...);
PHPX_API void echo(const String &str);
PHPX_API void echo(const Variant &val);
PHPX_API void echo(Int val);
PHPX_API void echo(Float val);
PHPX_API Variant global(const String &name);
PHPX_API Variant constant(const String &name);
PHPX_API Variant constant(zend_class_entry *ce, const String &name);
PHPX_API void initGlobal(const String &name, Variant &var);
PHPX_API void unsetGlobal(const String &name);
PHPX_API Variant include(const String &file, IncludeType type = INCLUDE);
PHPX_API Variant eval(const String &script);
PHPX_API Variant call(const Variant &func, Args &args);
PHPX_API Variant call(const Variant &func, Array &args);
PHPX_API Variant call(const Variant &func, const ArgList &args);
PHPX_API Variant call(zend_function *func);
PHPX_API Variant call(zend_function *func, const ArgList &args);
PHPX_API Variant call(zend_class_entry *ce, zend_function *func);
PHPX_API Variant call(zend_class_entry *ce, zend_function *func, const ArgList &args);
PHPX_API void throwException(const String &class_name, const char *message, int code = 0);
PHPX_API void throwException(const Object &e);
PHPX_API bool empty(const Variant &v, const std::initializer_list<std::pair<Operation, const Variant>> &list);
PHPX_API bool exists(const Variant &v, const std::initializer_list<std::pair<Operation, const Variant>> &list);

void setDebugInfo();

#define throwError(format, ...)                                                                                        \
    do {                                                                                                               \
        zend_throw_error(NULL, format, ##__VA_ARGS__);                                                                 \
        setDebugInfo();                                                                                                \
        if (throw_impl) {                                                                                              \
            throw_impl(EG(exception));                                                                                 \
        }                                                                                                              \
    } while (0)

#define throwErrorIfOccurred()                                                                                         \
    do {                                                                                                               \
        if (UNEXPECTED(EG(exception) != nullptr && throw_impl != nullptr)) {                                           \
            setDebugInfo();                                                                                            \
            throw_impl(EG(exception));                                                                                 \
        }                                                                                                              \
    } while (0)

PHPX_API Object catchException();
PHPX_API Variant concat(const Variant &a, const Variant &b);
PHPX_API Variant concat(const ArgList &args);
PHPX_API void exit(const Variant &status);
PHPX_API bool same(const Variant &a, const Variant &b);
PHPX_API bool equals(const Variant &a, const Variant &b);
PHPX_API int compare(const Variant &a, const Variant &b);
PHPX_API Variant getStaticProperty(const String &class_name, const String &prop);
PHPX_API Variant getStaticProperty(zend_class_entry *ce, uint32_t offset);
PHPX_API bool setStaticProperty(const String &class_name, const String &prop, const Variant &value);
PHPX_API bool hasStaticProperty(const String &class_name, const String &prop);
PHPX_API uint32_t getPropertyOffset(const String &class_name, const String &prop);
PHPX_API uint32_t getPropertyOffset(zend_class_entry *ce, const String &prop);

Int atoi(const String &str);
Array toArray(const Variant &v);
Object toObject(const Variant &v);
Object toObject(const Variant &v, const String &class_name);
Resource *getResource(const std::string &name);

void request_init();
void request_shutdown();

bool is_callable_ex(zval *callable,
                    zend_object *object,
                    uint32_t check_flags,
                    zend_string **callable_name,
                    zend_fcall_info_cache *fcc,
                    char **error);
int array_data_compare(Bucket *f, Bucket *s);

extern std::function<void(zend_object *)> throw_impl;
extern int box_res_id;
extern const char *box_res_name;

struct DebugInfo {
    bool enable;
    const char *php_file;
    int php_line;
    int cpp_line;
};

extern DebugInfo debug_info;

static inline const zval *unwrap_zval(const zval *val) {
    switch (Z_TYPE_P(val)) {
    case IS_REFERENCE:
        return Z_REFVAL_P(val);
    case IS_INDIRECT:
        return Z_INDIRECT_P(val);
    default:
        return val;
    }
}

static inline zval *unwrap_zval(zval *val) {
    return const_cast<zval *>(unwrap_zval(const_cast<const zval *>(val)));
}

static inline zval *undef() {
    return &EG(uninitialized_zval);
}

static inline bool zval_is_string(const zval *v) {
    return Z_TYPE_P(v) == IS_STRING;
}

static inline bool zval_is_array(const zval *v) {
    return Z_TYPE_P(v) == IS_ARRAY;
}

static inline bool zval_is_object(const zval *v) {
    return Z_TYPE_P(v) == IS_OBJECT;
}

static inline bool zval_is_undef(const zval *v) {
    return Z_TYPE_P(v) == IS_UNDEF;
}

static inline bool zval_is_null(const zval *v) {
    return Z_TYPE_P(v) == IS_NULL;
}

enum class Ctor {
    Copy,
    CopyRef,
    Indirect,
    Move,
};

class Variant {
  protected:
    zval val;
    void destroy() {
        zval_ptr_dtor(unwrap_ptr());
    }
    void addRef() {
        Z_TRY_ADDREF_P(&val);
    }
    void delRef() {
        Z_TRY_DELREF_P(&val);
    }
    static void strOffsetSet(zval *zv, char c);
    static bool isStrOffsetSet(zval *zv) {
        return GC_FLAGS(Z_STR_P(zv)) & IS_STR_PERMANENT;
    }

  public:
    Variant() noexcept {
        ZVAL_NULL(&val);
    }
    Variant(std::nullptr_t) noexcept {
        ZVAL_NULL(&val);
    }
    Variant(long v) noexcept {
        ZVAL_LONG(&val, v);
    }
    Variant(int v) noexcept {
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
    Variant(double v) noexcept {
        ZVAL_DOUBLE(&val, v);
    }
    Variant(bool v) noexcept {
        ZVAL_BOOL(&val, v);
    }
    Variant(const zval *v, Ctor method = Ctor::Copy) noexcept {
        /**
         * Many ZendAPIs return null-pointer instead of null value, and it is too laborious to carefully
         * discern whether each API will return an empty pointer. Therefore, it is necessary to detect whether the
         * incoming zval pointer is empty in the constructor, and if so, initialize it to null.
         */
        if (UNEXPECTED(v == nullptr)) {
            ZVAL_NULL(&val);
            return;
        }

        ZVAL_DEINDIRECT(v);
        switch (method) {
        case Ctor::Copy:
            ZVAL_DEREF(v);
            ZVAL_COPY(&val, v);
            break;
        case Ctor::CopyRef:
            ZVAL_COPY(&val, v);
            break;
            /**
             * The value of v must be the address of an array element, or the address of an object property
             */
        case Ctor::Indirect:
            ZVAL_INDIRECT(&val, const_cast<zval *>(v));
            break;
            /**
             * The v must be a new reference, created using `array_init()` or `object_init()`, or `zend_string_init()`,
             * after which the ownership of the zval pointer is transferred to the Variant.
             */
        case Ctor::Move:
        default:
            memcpy(&val, v, sizeof(val));
            break;
        }
    }
    Variant(zend_array *arr, Ctor method = Ctor::Copy) noexcept {
        switch (method) {
        case Ctor::Copy:
            ZVAL_ARR(&val, arr);
            addRef();
            break;
        case Ctor::Move:
        default:
            ZVAL_ARR(&val, arr);
            break;
        }
    }
    Variant(zend_string *s) noexcept {
        ZVAL_STR(&val, zend_string_copy(s));
    }
    Variant(const Variant &v) : Variant(v.unwrap_ptr()) {}
    Variant(Variant &&v) noexcept {
        if (v.isIndirect()) {
            memcpy(&val, v.zv(), sizeof(zval));
            addRef();
        } else {
            memcpy(&val, v.const_ptr(), sizeof(zval));
        }
        v.val = {};
    }
    Variant(Variant *v) {
        if (v->isReference()) {
            val = *v->ptr();
            addRef();
        } else {
            auto zv = v->unwrap_ptr();
            ZVAL_NEW_REF(&val, zv);
            *zv = val;
            Z_TRY_ADDREF_P(zv);
        }
    }
    Variant(Box *v) {
        zend_resource *res = zend_register_resource(v, box_res_id);
        ZVAL_RES(&val, res);
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
        if (isReference()) {
            zval_ptr_dtor(&val);
        } else if (!isIndirect()) {
            destroy();
        }
    }
    Variant &operator=(int v) {
        destroy();
        ZVAL_LONG(unwrap_ptr(), (long) v);
        return *this;
    }
    Variant &operator=(long v) {
        destroy();
        ZVAL_LONG(unwrap_ptr(), v);
        return *this;
    }
    Variant &operator=(const std::string &str) {
        if (isIndirect() && isString() && isStrOffsetSet(zv())) {
            strOffsetSet(zv(), str.c_str()[0]);
        } else {
            destroy();
            ZVAL_STRINGL(unwrap_ptr(), str.c_str(), str.length());
        }
        return *this;
    }
    Variant &operator=(const char *str) {
        if (isIndirect() && isString() && isStrOffsetSet(zv())) {
            strOffsetSet(zv(), str[0]);
        } else {
            destroy();
            ZVAL_STRING(unwrap_ptr(), str);
        }
        return *this;
    }
    Variant &operator=(double v) {
        destroy();
        ZVAL_DOUBLE(unwrap_ptr(), v);
        return *this;
    }
    Variant &operator=(bool v) {
        destroy();
        ZVAL_BOOL(unwrap_ptr(), v);
        return *this;
    }
    Variant &operator=(zend_string *v) {
        destroy();
        ZVAL_STR(unwrap_ptr(), zend_string_copy(v));
        return *this;
    }
    void copyFrom(const zval *src);
    Variant &operator=(const zval *v);
    Variant &operator=(const Variant &v);
    Variant &operator=(const Variant *v);
    Variant &operator=(nullptr_t) {
        destroy();
        ZVAL_NULL(unwrap_ptr());
        return *this;
    }
    void unset();
    zval *ptr() noexcept {
        return &val;
    }
    PHPX_UNSAFE zend_array *array() const noexcept {
        return Z_ARRVAL_P(unwrap_ptr());
    }
    PHPX_UNSAFE zend_reference *reference() const noexcept {
        return Z_REF(val);
    }
    PHPX_UNSAFE zval *refval() const noexcept {
        return Z_REFVAL(val);
    }
    PHPX_UNSAFE zend_class_entry *ce() const noexcept {
        return Z_OBJCE_P(unwrap_ptr());
    }
    PHPX_UNSAFE zend_object *object() const noexcept {
        return Z_OBJ_P(unwrap_ptr());
    }
    PHPX_UNSAFE zval *zv() const noexcept {
        return Z_INDIRECT(val);
    }
    const zval *const_ptr() const noexcept {
        return &val;
    }
    const zval *unwrap_ptr() const {
        return unwrap_zval(&val);
    }
    const zval *direct_ptr() const {
        return isIndirect() ? zv() : &val;
    }
    zval *unwrap_ptr() noexcept {
        return unwrap_zval(&val);
    }
    zval *direct_ptr() {
        return isIndirect() ? zv() : &val;
    }
    void debug();
    void print() const;
    int getRefCount() const;
    int type() const {
        return Z_TYPE_P(unwrap_ptr());
    }
    const char *typeStr() const {
        return zend_get_type_by_const(type());
    }
    bool isString() const {
        return Z_TYPE_P(unwrap_ptr()) == IS_STRING;
    }
    bool isArray() const {
        return Z_TYPE_P(unwrap_ptr()) == IS_ARRAY;
    }
    bool isObject() const {
        return Z_TYPE_P(unwrap_ptr()) == IS_OBJECT;
    }
    bool isInt() const {
        return Z_TYPE_P(unwrap_ptr()) == IS_LONG;
    }
    bool isFloat() const {
        return Z_TYPE_P(unwrap_ptr()) == IS_DOUBLE;
    }
    bool isBool() const {
        return Z_TYPE_P(unwrap_ptr()) == IS_TRUE || Z_TYPE_P(unwrap_ptr()) == IS_FALSE;
    }
    bool isFalse() const {
        return Z_TYPE_P(unwrap_ptr()) == IS_FALSE;
    }
    bool isTrue() const {
        return Z_TYPE_P(unwrap_ptr()) == IS_TRUE;
    }
    bool isNull() const {
        return Z_TYPE_P(unwrap_ptr()) == IS_NULL;
    }
    bool isUndef() const {
        return Z_TYPE_P(unwrap_ptr()) == IS_UNDEF;
    }
    bool isResource() const {
        return Z_TYPE_P(const_ptr()) == IS_RESOURCE;
    }
    bool isReference() const {
        return Z_TYPE_P(const_ptr()) == IS_REFERENCE;
    }
    bool isIndirect() const {
        return Z_TYPE_P(const_ptr()) == IS_INDIRECT;
    }

    bool isScalar() const {
        return isBool() || isInt() || isFloat() || isString();
    }

    bool isNumeric() const;
    bool empty() const {
        return toBool() == false;
    }
    std::string toStdString() const;
    String toString() const;
    const char *toCString() const {
        if (!isString()) {
            return "";
        }
        return Z_STRVAL_P(unwrap_ptr());
    }
    Int toInt() const {
        return zval_get_long(const_cast<zval *>(unwrap_ptr()));
    }
    double toFloat() const {
        return zval_get_double(const_cast<zval *>(unwrap_ptr()));
    }
    bool toBool() const {
        return zval_is_true(const_cast<zval *>(unwrap_ptr()));
    }
    Array toArray() const;
    Object toObject() const;
    size_t length() const;
    template <class T>
    T *toResource(const char *name) {
        if (!isResource()) {
            throwError("This variant is not a resource type.");
            return nullptr;
        }
        void *_ptr = nullptr;
        Resource *_c = getResource(name);
        if (_c == nullptr) {
            return nullptr;
        }
        if ((_ptr = zend_fetch_resource(Z_RES_P(ptr()), name, _c->type)) == nullptr) {
            throwError("The `%s` type of resource is undefined.", name);
            return nullptr;
        }
        return static_cast<T *>(_ptr);
    }
    template <class T>
    T *toBox() {
        if (!isResource()) {
            throwError("This variant is not a resource type.");
            return nullptr;
        }
        auto res = Z_RES(val);
        if (res->type != box_res_id) {
            throwError("This resource is not type of `%s`.", box_res_name);
            return nullptr;
        }
        return static_cast<T *>(res->ptr);
    }
    Reference toReference();
    Variant getRefValue() const;
    Variant operator*() const {
        return getRefValue();
    }

    void moveTo(zval *dest) {
        ZVAL_COPY_VALUE(dest, &val);
        val = {};
    }

    void redirect(const Variant &v) {
        if (v.isIndirect()) {
            redirect(zv());
        } else {
            throwError("Cannot redirect to a non-indirect value.");
        }
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
    Variant getProperty(zend_string *prop_name) const;
    void setProperty(const Variant &name, const Variant &value) const;
    void setProperty(zend_string *prop_name, const Variant &value) const;
    void unsetProperty(const Variant &name);
    void unsetProperty(zend_string *prop_name);

    /**
     * These methods are unsafe. They only support arrays or objects, and will use the address of the zval in the
     * These array elements or object properties to return an Indirect object. When assigning a value to this object, it
     * will directly modify the values of the array elements or object properties. These methods are not safe; it is
     * essential to ensure that the zval pointer already exists and has not been unset. Please note that after
     * performing write operations on an array or object, the address of the zend_array or object property table may
     * change, and the zval address pointed to by the Indirect object may become an invalid address.
     */
    Variant item(zend_long offset, bool update = false);
    Variant item(const Variant &key, bool update = false);
    Reference itemRef(zend_long offset);
    Reference itemRef(const Variant &key);
    Variant newItem();

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
    // String: Adding a substring to the end of a string,
    // Array: Appending elements to an array,
    // Object: If there is an offsetSet method, it indicates that elements are being appended.
    // Other type: throw exception
    void append(const Variant &);

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
extern Object null_object;
extern Int zero;

template <typename T>
Variant newResource(const char *name, T *v) {
    const auto _c = getResource(name);
    if (!_c) {
        throwError("%s type of resource is undefined.", name);
        return {};
    }
    zend_resource *res = zend_register_resource(static_cast<void *>(v), _c->type);
    return {res};
}

#ifndef ZEND_HASH_ELEMENT
#define ZEND_HASH_ELEMENT(ht, idx) &HT_HASH_TO_BUCKET(ht, idx)->val
#endif

class String : public Variant {
    void checkString() {
        if (!isString()) {
            auto zv = unwrap_ptr();
            auto new_str = zval_get_string(zv);
            destroy();
            ZVAL_STR(zv, new_str);
        }
    }

  public:
    String() {
        ZVAL_EMPTY_STRING(&val);
    }
    String(const zval *v, Ctor method = Ctor::Copy) : Variant(v, method) {
        checkString();
    }
    String(const Variant &v) : String(v.const_ptr()) {}
    explicit String(int v) {
        ZVAL_STR(ptr(), zend_long_to_str(v));
    }
    explicit String(long v) {
        ZVAL_STR(ptr(), zend_long_to_str(v));
    }
    explicit String(double v) {
        ZVAL_STR(ptr(), zend_strpprintf(0, "%.*G", (int) EG(precision), v));
    }
    explicit String(bool v) {
        ZVAL_STR(ptr(), zend_string_init(v ? "1" : "0", 1, false));
    }
    String(zend_string *v, Ctor method = Ctor::Copy) {
        if (method == Ctor::Copy) {
            ZVAL_STR(ptr(), zend_string_copy(v));
        } else {
            ZVAL_STR(ptr(), v);
        }
    }
    String(const std::string &v) : Variant(v) {}
    String(const char *v) : Variant(v) {}
    String(const char *str, size_t len) : Variant(str, len) {}
    String(const char *str, size_t len, bool persistent) : Variant(str, len, persistent) {}
    bool isNumeric() const {
        return is_numeric_string(data(), length(), nullptr, nullptr, false);
    }
    size_t length() const {
        return Z_STRLEN_P(unwrap_ptr());
    }
    const char *data() const {
        return Z_STRVAL_P(unwrap_ptr());
    }
    String offsetGet(zend_long _offset) const;
    String offsetGet(const Variant &_offset) const {
        return offsetGet(_offset.toInt());
    }
    void offsetSet(zend_long _offset, const Variant &value);
    void offsetSet(const Variant &_offset, const Variant &value) {
        offsetSet(_offset.toInt(), value);
    }
    uint64_t hashCode() const {
        return zend_string_hash_val(str());
    }
    zend_long offset(zend_long _offset) const {
        if (UNEXPECTED(length() < ((_offset < 0) ? -(size_t) _offset : ((size_t) _offset + 1)))) {
            return -1;
        }
        return _offset < 0 ? (zend_long) length() + _offset : _offset;
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
    String lower() const;
    String upper() const;
    String base64Encode() const;
    String base64Decode() const;
    String escape(const int flags = ENT_QUOTES | ENT_SUBSTITUTE, const char *charset = PHP_DEFAULT_CHARSET) const;
    String unescape(const int flags = ENT_QUOTES | ENT_SUBSTITUTE, const char *charset = PHP_DEFAULT_CHARSET) const;
    zend_string *str() const {
        return Z_STR_P(unwrap_ptr());
    }
    Array split(const String &delim, long = ZEND_LONG_MAX) const;
    String substr(long _offset, long _length = -1) const;
    String stripTags(const String &allow, bool allow_tag_spaces = false) const;
    String addSlashes() const;
    String stripSlashes() const;
    String basename(const String &suffix) const;
    String dirname() const;
    void print() const;
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
    String key_;

  public:
    ArrayItem(Array &_array, zend_ulong _index, const String &_key);
    ArrayItem &operator=(const Variant &v);
};

class Array : public Variant {
    void copyFrom(const ArgList &list);
    void copyFrom(const std::initializer_list<std::pair<const std::string, const Variant>> &list);
    void copyFrom(const std::initializer_list<std::pair<Int, const Variant>> &list);
    void checkArray() {
        if (isNull() || isUndef()) {
            array_init(unwrap_ptr());
        } else if (!isArray()) {
            throwError("parameter 1 must be `array`, got `%s`", typeStr());
        }
    }

  public:
    Array() {
        array_init(&val);
    }
    Array(const zval *v, Ctor method = Ctor::Copy) : Variant(v, method) {
        checkArray();
    }
    Array(const Variant &v) : Array(v.const_ptr()) {}
    Array(const ArgList &list);
    Array(const std::initializer_list<std::pair<const std::string, const Variant>> &list);
    Array(const std::initializer_list<std::pair<Int, const Variant>> &list);
    Array(Variant *v) : Variant(v) {}

    Array &operator=(const ArgList &list);
    Array &operator=(const std::initializer_list<std::pair<const std::string, const Variant>> &list);
    Array &operator=(const std::initializer_list<std::pair<Int, const Variant>> &list);

    zend_array *unwrap_array() {
        return Z_ARRVAL_P(unwrap_ptr());
    }
    void set(zend_ulong i, const Variant &v);
    void set(const Variant &key, const Variant &v);
    void append(const Variant &v);
    Variant get(const String &key) const {
        return zend_hash_find(Z_ARRVAL_P(const_ptr()), key.str());
    }
    Variant get(zend_ulong i) const {
        return zend_hash_index_find(Z_ARRVAL_P(const_ptr()), i);
    }
    ArrayItem operator[](zend_ulong i) {
        return {*this, i, String{}};
    }
    ArrayItem operator[](const String &key) {
        return {*this, 0, key};
    }
    bool del(zend_ulong index);
    bool del(const Variant &key);
    void clean() {
        auto zarr = unwrap_ptr();
        SEPARATE_ARRAY(zarr);
        zend_hash_clean(Z_ARRVAL_P(zarr));
    }
    bool exists(zend_ulong index) const {
        return zend_hash_index_exists(Z_ARRVAL_P(unwrap_ptr()), index);
    }
    bool exists(const String &key) const {
        return zend_hash_exists(Z_ARRVAL_P(unwrap_ptr()), key.str());
    }
    ArrayIterator begin() const {
        return {Z_ARRVAL_P(unwrap_ptr()), 0};
    }
    ArrayIterator end() const {
        const auto ht = Z_ARRVAL_P(unwrap_ptr());
        return {ht, ht->nNumUsed};
    }
    size_t count() const {
        return zend_hash_num_elements(Z_ARRVAL_P(unwrap_ptr()));
    }
    bool empty() const {
        return count() == 0;
    }
    bool isList() const {
        return zend_array_is_list(Z_ARRVAL_P(unwrap_ptr()));
    }
    Variant search(const Variant &_other_var, bool strict = false) const;
    bool contains(const Variant &_other_var, bool strict = false) const;
    String join(const String &delim);
    void merge(const Array &source);
    void sort(bool renumber = true);
    Array slice(long offset, long length = -1, bool preserve_keys = false);
};

class Args {
    std::vector<Variant> params;

  public:
    Args() = default;
    explicit Args(size_t n) {
        params.reserve(n);
    }
    explicit Args(const ArgList &args) : Args(args.size()) {
        for (const auto &arg : args) {
            append(arg.const_ptr());
        }
    }
    void append(const zval *zv) {
        params.emplace_back(zv, Ctor::CopyRef);
    }
    void append(const Variant &v) {
        append(v.const_ptr());
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

PHPX_API extern zend_function *getFunction(const String &name);
PHPX_API extern zend_function *getMethod(zend_class_entry *ce, const String &name);
extern Variant call_impl(const zval *object, const zval *func, Args &args);
extern Variant call_impl(const zval *object, const zval *func);

static inline Variant call(const Variant &func) {
    return call_impl(nullptr, func.const_ptr());
}

static inline zend_class_entry *getClassEntry(const String &name) {
    return zend_lookup_class(name.str());
}

static inline zend_class_entry *getClassEntrySafe(const String &name) {
    zend_class_entry *ce = getClassEntry(name);
    if (UNEXPECTED(!ce)) {
        throwError("class '%s' is undefined.", name.data());
    }
    return ce;
}

class Object : public Variant {
    void checkObject() const {
        if (!isUndef() && !isNull() && !isObject()) {
            throwError("parameter 1 must be `object`, got `%s`", typeStr());
        }
    }

  public:
    Object(const zval *v, Ctor method = Ctor::Copy) : Variant(v, method) {
        checkObject();
    }
    Object(const Variant &v, Ctor method = Ctor::Copy) : Object(v.unwrap_ptr(), method) {}
    Object() = default;
    Variant call(const Variant &func, Args &args) {
        return call_impl(ptr(), func.const_ptr(), args);
    }
    zend_class_entry *parent_ce() {
        return Z_OBJCE_P(unwrap_ptr())->parent;
    }
    Variant callParentMethod(const String &func) {
        return callParentMethod(func, {});
    }
    Variant callParentMethod(const String &func, const ArgList &args);
    Variant exec(const Variant &fn) {
        return call_impl(unwrap_ptr(), fn.const_ptr());
    }
    Variant exec(const Variant &fn, const ArgList &args);

    Reference attrRef(const String &name);
    Variant attr(const Variant &name, bool update = false) const;
    Variant attr(uintptr_t offset, bool update = false) const {
        return Variant{OBJ_PROP(object(), offset), Ctor::Indirect};
    }

    void appendArrayProperty(const String &name, const Variant &value);
    void updateArrayProperty(const String &name, zend_long offset, const Variant &value);
    void updateArrayProperty(const String &name, const Variant &key, const Variant &value);

    bool offsetExists(const Variant &offset) const {
        return object()->handlers->has_dimension(object(), NO_CONST_V(offset), 0);
    }
    bool offsetExists(zend_long offset) {
        zval tmp;
        ZVAL_LONG(&tmp, offset);
        return object()->handlers->has_dimension(object(), &tmp, 0);
    }
    Variant offsetGet(const Variant &offset, int type = BP_VAR_R) {
        zval rv;
        return Variant{object()->handlers->read_dimension(object(), NO_CONST_V(offset), type, &rv)};
    }
    Variant offsetGet(zend_long offset, int type = BP_VAR_R) {
        zval tmp;
        ZVAL_LONG(&tmp, offset);
        zval rv;
        return Variant{object()->handlers->read_dimension(object(), &tmp, type, &rv)};
    }
    void offsetSet(const Variant &offset, const Variant &value) {
        object()->handlers->write_dimension(object(), NO_CONST_V(offset), NO_CONST_V(value));
    }
    void offsetSet(zend_long offset, const Variant &value) {
        zval tmp;
        ZVAL_LONG(&tmp, offset);
        object()->handlers->write_dimension(object(), &tmp, NO_CONST_V(value));
    }
    void offsetUnset(const Variant &offset) {
        object()->handlers->unset_dimension(object(), NO_CONST_V(offset));
    }
    void offsetUnset(zend_long offset) {
        zval tmp;
        ZVAL_LONG(&tmp, offset);
        object()->handlers->unset_dimension(object(), &tmp);
    }

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
        setProperty(name.str(), v);
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
    zend_long count();
    bool methodExists(const String &name) const {
        return zend_hash_exists(&ce()->function_table, name.str());
    }
    bool propertyExists(const String &name) const {
        return zend_hash_exists(&ce()->properties_info, name.str());
    }
    bool instanceOf(const String &name) const;
    bool instanceOf(const zend_class_entry *ce_) const {
        return instanceof_function(ce(), ce_);
    }
    Object clone() const;
};

class Reference : public Variant {
    void checkRef() {
        if (isNull() || isUndef()) {
            ref_init(&val);
        } else if (!isReference()) {
            throwError("parameter 1 must be `reference`, got `%s`", typeStr());
        }
    }

    static void ref_init(zval *arg) {
        ZVAL_NEW_EMPTY_REF(arg);
        ZVAL_NULL(Z_REFVAL_P(arg));
    }

  public:
    Reference() noexcept {
        ref_init(&val);
    }
    Reference(const Reference &v) noexcept {
        ZVAL_COPY(&val, v.const_ptr());
    }
    Reference(Reference &&v) noexcept = default;
    Reference(const zval *v, Ctor method = Ctor::CopyRef) : Variant(v, method) {
        checkRef();
    }
    Reference &operator=(const Reference &v) noexcept {
        if (&v != this) {
            zval_ptr_dtor(&val);
            ZVAL_COPY(&val, v.const_ptr());
        }
        return *this;
    }
    Reference &operator=(const Variant &v) {
        if (&v != this) {
            destroy();
            ZVAL_COPY(refval(), v.direct_ptr());
        }
        return *this;
    }
};

class Box {
  public:
    Box() = default;
    void destroy() const {
        delete this;
    }

  protected:
    virtual ~Box() = default;
};

static inline Reference newReference() {
    return Reference{};
}

extern Object newObject(zend_class_entry *ce);
extern Object newObject(zend_class_entry *ce, const ArgList &args);

static inline Object newObject(const char *name) {
    return newObject(getClassEntrySafe(name));
}

static inline Object newObject(const char *name, const ArgList &args) {
    return newObject(getClassEntrySafe(name), args);
}

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
