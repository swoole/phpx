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
#include "php_globals.h"
#include "php_main.h"

#include "zend_API.h"
#include "php_streams.h"
#include "php_network.h"

#if PHP_VERSION_ID < 80100
#error "only supports PHP-8.1 or later."
#endif

#include "zend_interfaces.h"
#include "zend_exceptions.h"
#include "zend_variables.h"
#include "zend_inheritance.h"
#include "zend_types.h"

#include <ext/json/php_json.h>
#include <ext/standard/html.h>
#include <ext/standard/php_standard.h>
#include <ext/spl/php_spl.h>
}

#include <unordered_map>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <memory>

typedef unsigned char uchar;

#define PHPX_MAX_ARGC 10
#define PHPX_VAR_DUMP_LEVEL 10

#if PHP_VERSION_ID >= 80000
#define TSRMLS_CC
#else
typedef int zend_result;
#endif

#ifndef ZEND_ABSTRACT_ME_WITH_FLAGS
#define ZEND_ABSTRACT_ME_WITH_FLAGS(classname, name, arg_info, flags) ZEND_RAW_FENTRY(#name, NULL, arg_info, flags)
#endif

#define PHPX_API

namespace php {
typedef zend_long Int;
typedef double Float;

PHPX_API void error(int level, const char *format, ...);
PHPX_API void echo(const char *format, ...);

struct Resource {
    const char *name;
    int type;
};

extern std::unordered_map<std::string, Resource *> resource_map;
extern std::map<int, void *> object_array;

class Variant;

class String {
    zend_string *str;

  public:
    String(const char *v) {
        str = zend_string_init(v, strlen(v), false);
    }
    String(int v) {
        str = zend_long_to_str(v);
    }
    String(long v) {
        str = zend_long_to_str(v);
    }
    String(float v) {
        str = zend_strpprintf(0, "%.*G", (int) EG(precision), v);
    }
    String(double v) {
        str = zend_strpprintf(0, "%.*G", (int) EG(precision), v);
    }
    String(bool v) {
        str = zend_string_init(v ? "1" : "0", 1, false);
    }
    String(const char *v, size_t len, bool persistent = false) {
        str = zend_string_init(v, len, persistent);
    }
    String(const std::string &v) {
        str = zend_string_init(v.c_str(), v.length(), false);
    }
    String(zend_string *v) {
        str = zend_string_copy(v);
    }
    String(const zval *v) {
        str = zend_string_copy(Z_STR_P(v));
    }
    String(Variant &v);
    String(String &&s) noexcept {
        str = s.str;
        s.str = nullptr;
    }
    String(const String &s) {
        str = zend_string_copy(s.str);
    }
    ~String() {
        if (str) {
            zend_string_release(str);
        }
    }
    long toInt() const {
        return ZEND_STRTOL(ZSTR_VAL(str), nullptr, 10);
    }
    double toFloat() const {
        return zend_strtod(ZSTR_VAL(str), nullptr);
    }
    size_t length() const {
        return str->len;
    }
    char *c_str() const {
        return str->val;
    }
    uint64_t hashCode() const {
        return zend_string_hash_val(str);
    }
    void extend(size_t new_size) {
        str = zend_string_extend(str, new_size, false);
    }
    bool equals(const char *s, size_t slen) const {
        return length() == slen && memcmp(ZSTR_VAL(str), s, slen) == 0;
    }
    bool equals(const std::string &s) const {
        return equals(s.c_str(), s.length());
    }
    bool equals(const char *s) const {
        return equals(s, strlen(s));
    }
    bool equals(const String &s, const bool ci = false) const;
    bool operator==(const String &v) const {
        return equals(v);
    }
    static String format(const char *format, ...) {
        va_list args;
        va_start(args, format);
        zend_string *s = vstrpprintf(0, format, args);
        va_end(args);
        return s;
    }
    String trim(const String &what, int mode = 3) const {
        return php_trim(str, what.c_str(), what.length(), mode);
    }
    void tolower() const {
        zend_str_tolower(str->val, str->len);
    }
    String base64Encode(bool raw = false) const {
        return php_base64_decode_ex((uchar *) str->val, str->len, raw);
    }
    String escape(int flags = ENT_QUOTES | ENT_SUBSTITUTE, const std::string &charset = SG(default_charset)) const {
        return php_escape_html_entities((uchar *) str->val, str->len, 0, flags, charset.c_str());
    }
    String unescape(int flags, const std::string &charset) const {
        return php_unescape_html_entities(str, 1, flags, charset.c_str());
    }

    Variant split(const String &delim, long = ZEND_LONG_MAX) const;
    String substr(long _offset, long _length = -1) const;
    void stripTags(const String &allow, bool allow_tag_spaces = false) const;
    String addSlashes() const;
    void stripSlashes() const;
    String basename(const String &suffix) const;
    String dirname() const;
    void print() const;

    uint32_t getRefCount() const {
        return zend_string_refcount(ptr());
    }

    zend_string *ptr() const {
        return str;
    }
};

class Variant {
  protected:
    zval val = {};
    void destroy() {
        zval_ptr_dtor(&val);
    }

  public:
    Variant() {
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
     * !!! Please note that this approach is intended solely for global constant objects.
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
    Variant(zend_string *str) {
        ZVAL_STR(&val, str);
    }
    Variant(double v) {
        ZVAL_DOUBLE(&val, v);
    }
    Variant(float v) {
        ZVAL_DOUBLE(&val, (double) v);
    }
    Variant(bool v) {
        ZVAL_BOOL(&val, v);
    }
    Variant(const zval *v) noexcept {
        ZVAL_COPY_VALUE(&val, v);
        addRef();
    }
    Variant(const Variant &v) : Variant(v.const_ptr()) {}
    Variant(Variant &&v) noexcept {
        memcpy(&val, &v.val, sizeof(zval));
        v.val = {};
    }
    /**
     * res is a new reference passed in from outside;
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
    Variant &operator=(zend_string *str) {
        destroy();
        ZVAL_STR(ptr(), str);
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
    Variant &operator=(float v) {
        destroy();
        ZVAL_DOUBLE(ptr(), (double) v);
        return *this;
    }
    Variant &operator=(bool v) {
        destroy();
        ZVAL_BOOL(ptr(), v);
        return *this;
    }
    Variant &operator=(const zval *v);
    Variant &operator=(const Variant &v);
    Variant(const Variant *v) {
        ZVAL_NEW_REF(&val, v->const_ptr());
        zval_add_ref(Z_REFVAL(val));
    }
    Variant &operator=(const Variant *v);
    zval *ptr() {
        return &val;
    }
    void debug();
    const zval *const_ptr() const {
        return &val;
    }
    void addRef() {
        zval_add_ref(ptr());
    }
    void delRef() {
        zval_delref_p(ptr());
    }
    int getRefCount() const;
    int type() const {
        return Z_TYPE_P(const_ptr());
    }
    uint32_t refcount() {
        return Z_REFCOUNT(val);
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
    bool empty();
    std::string toString();
    const char *toCString() {
        convert_to_string(&val);
        return Z_STRVAL(val);
    }
    long toInt() {
        return zval_get_long(ptr());
    }
    double toFloat() {
        return zval_get_double(ptr());
    }
    bool toBool() {
        return zval_is_true(ptr());
    }
    size_t length() const;
    template <class T>
    T *toResource(const char *name) {
        if (!isResource()) {
            error(E_WARNING, "This variant is not a resource type.");
            return nullptr;
        }
        void *_ptr = nullptr;
        Resource *_c = resource_map[name];
        if (_c == nullptr) {
            error(E_WARNING, "The `%s` type of resource is undefined.", name);
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
    bool operator==(Variant &v) {
        return equals(v);
    }
    bool operator==(bool v) {
        Variant _tmp(v);
        return equals(_tmp);
    }
    bool operator==(int v) {
        Variant _tmp(v);
        return equals(_tmp);
    }
    bool operator==(long v) {
        Variant _tmp(v);
        return equals(_tmp);
    }
    bool operator==(float v) {
        Variant _tmp(v);
        return equals(_tmp);
    }
    bool operator==(double v) {
        Variant _tmp(v);
        return equals(_tmp);
    }
    bool operator==(const std::string &v) {
        Variant _tmp(v);
        return equals(_tmp);
    }
    bool equals(Variant &v, bool strict = false);
    bool same(Variant &v) {
        return equals(v, true);
    }
    Variant jsonEncode(zend_long options = 0, zend_long depth = PHP_JSON_PARSER_DEFAULT_DEPTH);
    Variant jsonDecode(zend_long options = 0, zend_long depth = PHP_JSON_PARSER_DEFAULT_DEPTH);
    Variant serialize();
    Variant unserialize();
    bool isCallable();

    Variant &operator++();
    Variant &operator--();
    Int operator++(int);
    Int operator--(int);
    Variant &operator+=(Int v);
    Variant &operator-=(Int v);
    Variant operator()() const;
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
    const Resource *_c = resource_map[name];
    if (!_c) {
        error(E_WARNING, "%s type of resource is undefined.", name);
        return {};
    }
    zend_resource *res = zend_register_resource(static_cast<void *>(v), _c->type);
    return {res};
}

PHPX_API Variant include(const std::string &file);

#ifndef ZEND_HASH_ELEMENT
#define ZEND_HASH_ELEMENT(ht, idx) &HT_HASH_TO_BUCKET(ht, idx)->val
#endif

class ArrayIterator {
    zend_array *array_;
    zend_ulong idx_;

  public:
    ArrayIterator(zend_array *array, zend_ulong idx) {
        array_ = array;
        idx_ = idx;
        skipUndefBucket();
    }
    void operator++(int i) {
        ++idx_;
        skipUndefBucket();
    }
    bool operator!=(const ArrayIterator b) const {
        return b.index() != index();
    }
    bool operator==(const ArrayIterator b) const {
        return b.index() == index();
    }
    Variant key() const {
#if PHP_VERSION_ID >= 80100
        if (HT_IS_PACKED(array_)) {
            return (zend_long) idx_;
        } else
#endif
        {
            auto *bucket = HT_HASH_TO_BUCKET(array_, idx_);
            if (bucket->key) {
                return zend_string_copy(bucket->key);
            } else {
                return (zend_long) bucket->h;
            }
        }
    }
    Variant value() const {
        return current();
    }
    zend_ulong index() const {
        return idx_;
    }
    zval *current() const {
        return ZEND_HASH_ELEMENT(array_, idx_);
    }

  private:
    void skipUndefBucket() {
        while (idx_ < array_->nNumUsed - 1) {
            if (Z_TYPE_P(current()) == IS_UNDEF) {
                idx_++;
            } else {
                break;
            }
        }
    }
};

extern int array_data_compare(Bucket *f, Bucket *s);

class Array : public Variant {
  public:
    Array() {
        array_init(&val);
    }
    Array(const zval *v);
    Array(const Variant &v);
    Array(Variant &&v) : Variant(std::move(v)) {
        if (!isArray()) {
            error(E_ERROR, "parameter 1 must be zend_array.");
        }
    }
    Array(const std::initializer_list<const Variant> &list);
    Array(const std::initializer_list<std::pair<const std::string, const Variant>> &list);
    Array(const std::initializer_list<std::pair<Int, const Variant>> &list);
    void separate() {
        SEPARATE_ARRAY(ptr());
    }
    void append(const Variant &v) {
        const_cast<Variant &>(v).addRef();
        add_next_index_zval(ptr(), const_cast<Variant &>(v).ptr());
    }
    void append(const char *str) {
        add_next_index_string(ptr(), str);
    }
    void append(const std::string &str) {
        add_next_index_stringl(ptr(), str.c_str(), str.length());
    }
    void append(long v) {
        add_next_index_long(ptr(), v);
    }
    void append(int v) {
        add_next_index_long(ptr(), (long) v);
    }
    void append(bool v) {
        add_next_index_bool(ptr(), v);
    }
    void append(double v) {
        add_next_index_double(ptr(), (double) v);
    }
    void append(zval *v) {
        zval_add_ref(v);
        add_next_index_zval(ptr(), v);
    }
    void append(void *v) {
        add_next_index_null(ptr());
    }
    void append(Array &v) {
        zend_array *arr = zend_array_dup(Z_ARR_P(v.ptr()));
        zval array;
        ZVAL_ARR(&array, arr);
        add_next_index_zval(ptr(), &array);
    }
    //------------------assoc-array------------------
    void set(const char *key, const Variant &v) {
        const_cast<Variant &>(v).addRef();
        add_assoc_zval(ptr(), key, const_cast<Variant &>(v).ptr());
    }
    void set(const char *key, int v) {
        add_assoc_long(ptr(), key, (long) v);
    }
    void set(const char *key, long v) {
        add_assoc_long(ptr(), key, v);
    }
    void set(const char *key, const char *v) {
        add_assoc_string(ptr(), key, v);
    }
    void set(const char *key, const std::string &v) {
        add_assoc_stringl(ptr(), key, v.c_str(), v.length());
    }
    void set(const char *key, double v) {
        add_assoc_double(ptr(), key, v);
    }
    void set(const char *key, float v) {
        add_assoc_double(ptr(), key, v);
    }
    void set(const char *key, bool v) {
        add_assoc_bool(ptr(), key, v);
    }
    void set(const String &s, const Variant &v) {
        const_cast<Variant &>(v).addRef();
        add_assoc_zval_ex(ptr(), s.c_str(), s.length(), const_cast<Variant &>(v).ptr());
    }
    void del(const char *key) {
        zend_hash_str_del(Z_ARRVAL_P(ptr()), key, strlen(key));
    }
    void del(const std::string &key) {
        zend_hash_str_del(Z_ARRVAL_P(ptr()), key.c_str(), key.length());
    }
    void del(const String &key) {
        zend_hash_del(Z_ARRVAL_P(ptr()), key.ptr());
    }
    //------------------index-array------------------
    void set(zend_ulong i, const Variant &v) {
        const_cast<Variant &>(v).addRef();
        add_index_zval(ptr(), i, const_cast<Variant &>(v).ptr());
    }
    void del(zend_ulong i) {
        zend_hash_index_del(Z_ARRVAL_P(ptr()), i);
    }
    //-------------------------------------------
    Variant get(const char *key) const {
        zval *ret = zend_hash_str_find(Z_ARRVAL_P(const_ptr()), key, strlen(key));
        if (ret == nullptr) {
            return {};
        }
        return ret;
    }
    Variant get(int i) const {
        zval *ret = zend_hash_index_find(Z_ARRVAL_P(const_ptr()), i);
        if (ret == nullptr) {
            return {};
        }
        return ret;
    }
    Variant operator[](int i) const {
        return get(i);
    }
    Variant operator[](const char *key) const {
        return get(key);
    }
    bool remove(const char *key) {
        String _key(key);
        return zend_hash_del(Z_ARRVAL_P(ptr()), _key.ptr()) == SUCCESS;
    }
    void clean() {
        zend_hash_clean(Z_ARRVAL_P(ptr()));
    }
    bool exists(const char *key) {
        return zend_hash_str_exists(Z_ARRVAL_P(ptr()), key, strlen(key));
    }
    bool exists(const std::string &key) {
        return zend_hash_str_exists(Z_ARRVAL_P(ptr()), key.c_str(), key.length());
    }
    ArrayIterator begin() {
        return {Z_ARRVAL_P(ptr()), 0};
    }
    ArrayIterator end() {
        const auto ht = Z_ARRVAL_P(ptr());
        return {ht, ht->nNumUsed};
    }
    size_t count() const {
        return zend_hash_num_elements(Z_ARRVAL_P(const_ptr()));
    }
    bool empty() const {
        return count() == 0;
    }
    Variant search(Variant &_other_var, bool strict = false);
    bool contains(Variant &_other_var, bool strict = false);
    String join(const String &delim);
    void merge(Array &source, bool overwrite = false) {
        zend_hash_merge(Z_ARRVAL_P(ptr()), Z_ARRVAL_P(source.ptr()), zval_add_ref, overwrite);
    }
    void sort(bool renumber = true) {
        zend_hash_sort(Z_ARRVAL_P(ptr()), array_data_compare, renumber);
    }
    Array slice(long offset, long length = -1, bool preserve_keys = false);
};

class Args {
    std::vector<zval> params;

  public:
    void append(const Variant &v) {
        params.push_back(*v.const_ptr());
    }
    size_t count() const {
        return params.size();
    }
    bool exists(int i) const {
        return i < count();
    }
    bool empty() const {
        return params.empty();
    }
    zval *ptr() {
        return params.data();
    }
    Array toArray() const {
        Array array;
        for (const auto &param : params) {
            array.append(Variant(&param));
        }
        return array;
    }
    Variant operator[](int i) const {
        auto zv = params.at(i);
        return {&zv};
    }
};

extern Variant _call(const zval *object, const zval *func, Args &args);
extern Variant _call(const zval *object, const zval *func);

static Variant call(const Variant &func) {
    return _call(nullptr, func.const_ptr());
}

extern Variant call(const Variant &func, const Array &args);
extern Variant call(const Variant &func, const std::initializer_list<Variant> &args);

static zend_class_entry *getClassEntry(const char *name) {
    String class_name(name, strlen(name));
    return zend_lookup_class(class_name.ptr());
}

static void throwException(const char *name, const char *message, int code = 0) {
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        php_error_docref(nullptr, E_WARNING, "class '%s' undefined.", name);
        return;
    }
    zend_throw_exception(ce, message, code);
}

static Variant getException() {
    zval zv;
    ZVAL_OBJ(&zv, EG(exception));
    return {&zv};
}

static Variant global(const char *name) {
    zend_string *key = zend_string_init(name, strlen(name), false);
    zend_is_auto_global(key);
    zval *var = zend_hash_find_ind(&EG(symbol_table), key);
    zend_string_free(key);
    if (!var) {
        return false;
    }
    return {var};
}

class Object : public Variant {
  public:
    Object(const zval *v) : Variant(v) {
        if (!isUndef() && !isObject()) {
            error(E_ERROR, "parameter 1 must be object.");
            return;
        }
    }
    Object(const Variant &v) : Object(v.const_ptr()) {}
    Object() = default;
    Variant call(const Variant &func, Args &args) {
        return _call(ptr(), func.const_ptr(), args);
    }
    zend_object *object() {
        return Z_OBJ_P(ptr());
    }
    zend_class_entry *parent_ce() {
        return Z_OBJCE_P(ptr())->parent;
    }
    zend_class_entry *ce() {
        return Z_OBJCE_P(ptr());
    }
    Variant callParentMethod(const char *func) {
        Variant retval;
        zend_call_method_with_0_params(object(), parent_ce(), nullptr, func, retval.ptr());
        return retval;
    }
    Variant callParentMethod(const char *func, const Variant &v1) {
        Variant retval;
        zend_call_method_with_1_params(
            object(), parent_ce(), nullptr, func, retval.ptr(), const_cast<Variant &>(v1).ptr());
        return retval;
    }
    Variant callParentMethod(const char *func, const Variant &v1, const Variant &v2) {
        Variant retval;
        zend_call_method_with_2_params(object(),
                                       parent_ce(),
                                       nullptr,
                                       func,
                                       retval.ptr(),
                                       const_cast<Variant &>(v1).ptr(),
                                       const_cast<Variant &>(v2).ptr());
        return retval;
    }
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

    Variant get(const char *name) {
        Variant retval;
        zval rv;
        zval *member_p = zend_read_property(ce(), object(), name, strlen(name), false, &rv);
        if (member_p != &rv) {
            ZVAL_COPY(retval.ptr(), member_p);
        } else {
            ZVAL_COPY_VALUE(retval.ptr(), member_p);
        }
        return retval;
    }
    void set(const char *name, const Variant &v) {
        zend_update_property(ce(), object(), name, strlen(name), const_cast<Variant &>(v).ptr());
    }
    void set(const char *name, Array &v) {
        zend_update_property(ce(), object(), name, strlen(name), v.ptr());
    }
    void set(const char *name, const std::string &v) {
        zend_update_property_stringl(ce(), object(), name, strlen(name), v.c_str(), v.length());
    }
    void set(const char *name, const char *v) {
        zend_update_property_string(ce(), object(), name, strlen(name), v);
    }
    void set(const char *name, int v) {
        zend_update_property_long(ce(), object(), name, strlen(name), v);
    }
    void set(const char *name, long v) {
        zend_update_property_long(ce(), object(), name, strlen(name), v);
    }
    void set(const char *name, double v) {
        zend_update_property_double(ce(), object(), name, strlen(name), v);
    }
    void set(const char *name, float v) {
        zend_update_property_double(ce(), object(), name, strlen(name), (double) v);
    }
    void set(const char *name, bool v) {
        zend_update_property_bool(ce(), object(), name, strlen(name), v ? 1 : 0);
    }
    template <class T>
    T *oGet(const char *key, const char *resource_name) {
        Variant p = this->get(key);
        return p.toResource<T>(resource_name);
    }
    template <class T>
    void oSet(const char *key, const char *resource_name, T *ptr) {
        Variant res = newResource<T>(resource_name, ptr);
        this->set(key, res);
    }
    template <class T>
    T *oPtr(const char *key, const char *resource_name) {
        Variant p = this->get(key);
        return p.toResource<T>(resource_name);
    }
    template <class T>
    void store(T *ptr) {
        if (ptr == nullptr) {
            object_array.erase(getId());
            delete ptr;
        } else {
            object_array[getId()] = ptr;
        }
    }
    template <class T>
    T *fetch() {
        return static_cast<T *>(object_array[this->getId()]);
    }
    std::string getClassName() {
        return {Z_OBJCE_P(ptr())->name->val, Z_OBJCE_P(ptr())->name->len};
    }
    uint32_t getId() {
        return Z_OBJ_HANDLE(*ptr());
    }
    String hash() {
#if PHP_VERSION_ID >= 80100
        return php_spl_object_hash(Z_OBJ_P(ptr()));
#else
        return php_spl_object_hash(ptr());
#endif
    }
    bool methodExists(const char *name) {
        return zend_hash_str_exists(&Z_OBJCE_P(ptr())->function_table, name, strlen(name));
    }
    bool propertyExists(const char *name) {
        return zend_hash_str_exists(&Z_OBJCE_P(ptr())->properties_info, name, strlen(name));
    }
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

extern std::unordered_map<std::string, Class *> class_map;
extern std::unordered_map<std::string, Interface *> interface_map;

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
};

extern std::unordered_map<std::string, std::shared_ptr<Extension>> _name_to_extension;
extern std::unordered_map<int, std::shared_ptr<Extension>> _module_number_to_extension;

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
