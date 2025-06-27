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

#pragma once

extern "C" {
#include "php.h"
#include "php_ini.h"
#include "php_globals.h"
#include "php_main.h"

#include "zend_API.h"
#include "php_streams.h"
#include "php_network.h"

#if PHP_VERSION_ID < 80000
#error "only supports PHP8 or later."
#endif

#include "zend_interfaces.h"
#include "zend_exceptions.h"
#include "zend_variables.h"
#include "zend_inheritance.h"
#include "zend_types.h"

#include <ext/date/php_date.h>
#include <ext/json/php_json.h>
#include <ext/standard/url.h>
#include <ext/standard/info.h>
#include <ext/standard/html.h>
#include <ext/standard/php_http.h>
#include <ext/standard/php_standard.h>
#include <ext/spl/php_spl.h>
}

#include <unordered_map>
#include <string>
#include <vector>
#include <functional>
#include <map>

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

class Variant {
  public:
    Variant() {
        init();
        ZVAL_NULL(&val);
    }
    Variant(std::nullptr_t v) {
        init();
        ZVAL_NULL(&val);
    }
    Variant(long v) {
        init();
        ZVAL_LONG(&val, v);
    }
    Variant(int v) {
        init();
        ZVAL_LONG(&val, (long) v);
    }
    Variant(const char *str) {
        init();
        ZVAL_STRING(&val, str);
    }
    Variant(const char *str, size_t len) {
        init();
        ZVAL_STRINGL(&val, str, len);
    }
    Variant(const std::string &str) {
        init();
        ZVAL_STRINGL(&val, str.c_str(), str.length());
    }
    Variant(zend_string *str) {
        init();
        ZVAL_STR(&val, str);
    }
    Variant(double v) {
        init();
        ZVAL_DOUBLE(&val, v);
    }
    Variant(float v) {
        init();
        ZVAL_DOUBLE(&val, (double) v);
    }
    Variant(bool v) {
        init();
        ZVAL_BOOL(&val, v);
    }
    Variant(zval *v, bool ref = false) {
        init();
        reference = ref;
        if (reference) {
            ref_val = v;
        } else {
            memcpy(&val, v, sizeof(zval));
            zval_add_ref(&val);
        }
    }
    Variant(zend_resource *res) {
        init();
        ZVAL_RES(ptr(), res);
    }
    Variant(const Variant &v) noexcept {
        init();
        ZVAL_COPY_VALUE(&val, v.const_ptr());
        zval_add_ref(&val);
    }
    Variant(Variant &&v) noexcept {
        init();
        if (v.reference) {
            reference = true;
            ref_val = v.ref_val;
            v.ref_val = nullptr;
        } else {
            reference = false;
            memcpy(&val, &v.val, sizeof(zval));
        }
        v.init();
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
    Variant &operator=(std::nullptr_t _null) {
        destroy();
        ZVAL_NULL(ptr());
        return *this;
    }
    Variant &operator=(const zval *v) {
        destroy();
        memcpy(&val, v, sizeof(zval));
        zval_add_ref(&val);
        return *this;
    }
    Variant &operator=(const Variant &v) {
        if (&v == this) {
            return *this;
        }
        destroy();
        ZVAL_COPY_VALUE(ptr(), const_cast<Variant &>(v).ptr());
        const_cast<Variant &>(v).addRef();
        return *this;
    }
    zval *ptr() {
        if (reference) {
            return ref_val;
        } else {
            return &val;
        }
    }
    const zval *const_ptr() const {
        if (reference) {
            return ref_val;
        } else {
            return &val;
        }
    }
    void addRef() {
        zval_add_ref(ptr());
    }
    void delRef() {
        zval_delref_p(ptr());
    }
    int getRefCount() const {
        const zend_refcounted *counted = Z_COUNTED_P(const_ptr());
        if (!counted) {
            return 0;
        }
        return GC_REFCOUNT(counted);
    }
    int type() const {
        return Z_TYPE_P(const_ptr());
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
    bool isNull() const {
        return Z_TYPE_P(const_ptr()) == IS_NULL;
    }
    bool isResource() const {
        return Z_TYPE_P(const_ptr()) == IS_RESOURCE;
    }
    bool isReference() const {
        return Z_TYPE_P(const_ptr()) == IS_REFERENCE;
    }
#ifdef IS_TYPE_IMMUTABLE
    bool isImmutable() {
        return Z_TYPE_FLAGS_P(ptr()) & IS_TYPE_IMMUTABLE;
    }
#endif
    bool isEmpty();
    std::string toString() {
        zend_string *str = zval_get_string(ptr());
        auto retval = std::string(ZSTR_VAL(str), ZSTR_LEN(str));
        zend_string_release(str);
        return retval;
    }
    /**
     * [Unsafe Operation] When the object is released, this memory is not available
     */
    const char *toCString() {
        if (str_val) {
            zend_string_release(str_val);
        }
        str_val = zval_get_string(ptr());
        return ZSTR_VAL(str_val);
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
    /**
     * dont forget to release the memory
     * @return point of new Object
     */
    Variant *dup() const {
        return new Variant(*this);
    }
    size_t length() const {
        if (isString()) {
            return Z_STRLEN_P(const_ptr());
        } else if (isArray()) {
            return zend_hash_num_elements(Z_ARRVAL_P(const_ptr()));
        } else {
            return 0;
        }
    }
    template <class T>
    T *toResource(const char *name) {
        if (!isResource()) {
            error(E_WARNING, "This variant is not a resource type.");
            return nullptr;
        }
        void *_ptr = nullptr;
        Resource *_c = resource_map[name];
        if (_c == nullptr) {
            error(E_WARNING, "The %s type of resource is undefined.", name);
            return nullptr;
        }
        if ((_ptr = zend_fetch_resource(Z_RES_P(ptr()), name, _c->type)) == nullptr) {
            error(E_WARNING, "The %s type of resource is undefined.", name);
            return nullptr;
        }
        return static_cast<T *>(_ptr);
    }
    Variant toReference() {
        if (isReference()) {
            return this;
        }
        zval zref;
        addRef();
        ZVAL_NEW_REF(&zref, ptr());
        zval_delref_p(&zref);
        Variant ret(&zref, false);
        return ret;
    }
    Variant referenceTo() {
        if (!isReference()) {
            return *this;
        }
        zval zv;
        ZVAL_COPY_VALUE(&zv, Z_REFVAL_P(ptr()));
        return {&zv, false};
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
    bool operator==(std::nullptr_t v) {
        Variant _tmp(v);
        return equals(_tmp);
    }
    bool operator==(const std::string &v) {
        Variant _tmp(v);
        return equals(_tmp);
    }
    bool isZvalRef() const {
        return reference;
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

  protected:
    bool reference;
    zval *ref_val;
    zend_string *str_val;
    zval val;
    void init() {
        reference = false;
        ref_val = nullptr;
        str_val = nullptr;
        memset(&val, 0, sizeof(val));
    }
    void destroy() {
        if (str_val) {
            zend_string_release(str_val);
        }
        if (!reference) {
            zval_ptr_dtor(&val);
            init();
        }
    }
};

template <typename T>
Variant newResource(const char *name, T *v) {
    Resource *_c = resource_map[name];
    if (!_c) {
        error(E_WARNING, "%s type of resource is undefined.", name);
        return nullptr;
    }
    zend_resource *res = zend_register_resource(static_cast<void *>(v), _c->type);
    return {res};
}

PHPX_API static void var_dump(Variant &v) {
    php_var_dump(v.ptr(), PHPX_VAR_DUMP_LEVEL);
}

PHPX_API static bool is_callable(const Variant &fn) {
    return zend_is_callable(const_cast<Variant &>(fn).ptr(), 0, nullptr);
}

PHPX_API Variant include(const std::string &file);

PHPX_API static int version_compare(const std::string &s1, const std::string &s2) {
    return php_version_compare(s1.c_str(), s2.c_str());
}

class String {
  public:
    String(const char *str) {
        value = zend_string_init(str, strlen(str), false);
    }
    String(int v) {
        value = zend_long_to_str(v);
    }
    String(long v) {
        value = zend_long_to_str(v);
    }
    String(float v) {
        value = zend_strpprintf(0, "%.*G", (int) EG(precision), v);
    }
    String(double v) {
        value = zend_strpprintf(0, "%.*G", (int) EG(precision), v);
    }
    String(bool v) {
        value = zend_string_init(v ? "1" : "0", 1, false);
    }
    String(const char *str, size_t len) {
        value = zend_string_init(str, len, false);
    }
    String(const std::string &str) {
        value = zend_string_init(str.c_str(), str.length(), false);
    }
    String(zend_string *str) {
        value = str;
    }
    String(const zval *str, bool ref = false) {
        value = Z_STR_P(str);
        if (ref) {
            free_memory = false;
        }
    }
    String(Variant &v) {
        value = zval_get_string(v.ptr());
    }
    String(String &&s) noexcept {
        value = s.value;
        s.value = nullptr;
        free_memory = s.free_memory;
        s.free_memory = true;
    }
    String(const String &s) {
        value = zend_string_copy(s.value);
        free_memory = true;
    }
    ~String() {
        if (free_memory) {
            zend_string_release(value);
        }
    }
    long toInt() const {
        return ZEND_STRTOL(ZSTR_VAL(value), nullptr, 10);
    }
    double toFloat() const {
        return zend_strtod(ZSTR_VAL(value), nullptr);
    }
    size_t length() const {
        return value->len;
    }
    char *c_str() const {
        return value->val;
    }
    uint64_t hashCode() const {
        return zend_string_hash_val(value);
    }
    void extend(size_t new_size) {
        value = zend_string_extend(value, new_size, false);
    }
    bool equals(const char *str) const {
        return memcmp(str, value->val, value->len) == 0;
    }
    bool equals(std::string &str) const {
        if (str.length() != value->len) {
            return false;
        }
        return memcmp(str.c_str(), value->val, value->len) == 0;
    }
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
    bool equals(const String &str, const bool ci = false) const {
        if (str.length() != value->len) {
            return false;
        }
        if (ci) {
            return zend_binary_strcasecmp(str.c_str(), str.length(), value->val, value->len) == 0;
        }
        return memcmp(str.c_str(), value->val, value->len) == 0;
    }
    String trim(const String &what, int mode = 3) const {
        return php_trim(value, what.c_str(), what.length(), mode);
    }
    void tolower() {
        zend_str_tolower(value->val, value->len);
    }
    String base64Encode(bool raw = false) const {
        return php_base64_decode_ex((const uchar *) value->val, value->len, raw);
    }

    String escape(int flags = ENT_QUOTES | ENT_SUBSTITUTE, const std::string& charset = SG(default_charset)) {
        return php_escape_html_entities((uchar *) value->val, value->len, 0, flags, (char *) charset.c_str());
    }

    String unescape(int flags, const std::string &charset) const {
        return php_unescape_html_entities(value, 1, flags, (char *) charset.c_str());
    }

    Variant split(String &delim, long = ZEND_LONG_MAX) const;
    String substr(long _offset, long _length = -1) const;
    void stripTags(const String &allow, bool allow_tag_spaces = false) const;
    String addSlashes() const;
    void stripSlashes() const;
    String basename(const String &suffix) const;
    String dirname() const;

    void print() const {
        if (value) {
            php_printf("%.*s", (int) value->len, value->val);
        } else {
            php_printf("(null)");
        }
    }

    zend_string *ptr() const {
        return value;
    }

  protected:
    bool free_memory = true;
    zend_string *value;
};

static String ini_get(const String& varname) {
    char *value = zend_ini_string(varname.c_str(), (uint) varname.length(), 0);
    if (!value) {
        return "";
    }
    return value;
}

static Variant get_cfg_name(const String& varname) {
    zval *retval = cfg_get_entry(varname.c_str(), (uint32_t) varname.length());
    if (retval) {
        return retval;
    } else {
        return false;
    }
}

class ArrayIterator {
  public:
    ArrayIterator(Bucket *p) {
        _ptr = p;
        _key = _ptr->key;
        _val = &_ptr->val;
        _index = _ptr->h;
        pe = p;
    }
    ArrayIterator(Bucket *p, Bucket *_pe) {
        _ptr = p;
        _key = _ptr->key;
        _val = &_ptr->val;
        _index = _ptr->h;
        pe = _pe;
        skipUndefBucket();
    }
    void operator++(int i) {
        ++_ptr;
        skipUndefBucket();
    }
    bool operator!=(ArrayIterator b) const {
        return b.ptr() != _ptr;
    }
    Variant key() const {
        if (_key) {
            return {_key->val, _key->len};
        } else {
            return {(long) _index};
        }
    }
    Variant value() {
        return {_val};
    }
    Bucket *ptr() const {
        return _ptr;
    }

  private:
    void skipUndefBucket() {
        while (_ptr != pe) {
            _val = &_ptr->val;
            if (_val && Z_TYPE_P(_val) == IS_INDIRECT) {
                _val = Z_INDIRECT_P(_val);
            }
            if (UNEXPECTED(Z_TYPE_P(_val) == IS_UNDEF)) {
                ++_ptr;
                continue;
            }
            if (_ptr->key) {
                _key = _ptr->key;
                _index = 0;
            } else {
                _index = _ptr->h;
                _key = nullptr;
            }
            break;
        }
    }

    zval *_val;
    zend_string *_key;
    Bucket *_ptr;
    Bucket *pe;
    zend_ulong _index;
};

extern int array_data_compare(Bucket *f, Bucket *s);

PHPX_API String md5(const String &data, bool raw_output = false);
PHPX_API String sha1(const String &data, bool raw_output = false);
PHPX_API String crc32(const String &data, bool raw_output = false);
PHPX_API String hash(const String &algo, const String &data, bool raw_output = false);
PHPX_API String hash_hmac(const String &algo, const String &data, const String &key, bool raw_output = false);

class Array : public Variant {
  public:
    Array() {
        array_init(&val);
    }
    Array(zval *v);
    Array(const Variant &v);
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
        add_assoc_string(ptr(), key, (char *) v);
    }
    void set(const char *key, std::string &v) {
        add_assoc_stringl(ptr(), key, (char *) v.c_str(), v.length());
    }
    void set(const char *key, double v) {
        add_assoc_double(ptr(), key, v);
    }
    void set(const char *key, float v) {
        add_assoc_double(ptr(), key, (double) v);
    }
    void set(const char *key, bool v) {
        add_assoc_bool(ptr(), key, v);
    }
    void set(const String &s, const Variant &v) {
        set(s.c_str(), v);
    }
    void del(const char *key) {
        zend_hash_str_del(Z_ARRVAL_P(ptr()), key, strlen(key));
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
        zend_hash_index_del(Z_ARRVAL_P(ptr()), (zend_ulong) i);
    }
    //-------------------------------------------
    Variant get(const char *key) {
        zval *ret = zend_hash_str_find(Z_ARRVAL_P(ptr()), key, strlen(key));
        if (ret == nullptr) {
            return nullptr;
        }
        return ret;
    }
    Variant get(int i) {
        zval *ret = zend_hash_index_find(Z_ARRVAL_P(ptr()), (zend_ulong) i);
        if (ret == NULL) {
            return nullptr;
        }
        return ret;
    }
    Variant operator[](int i) {
        return get(i);
    }
    Variant operator[](const char *key) {
        return get(key);
    }
    bool remove(const char *key) {
        String _key(key);
        bool ret = zend_hash_del(Z_ARRVAL_P(ptr()), _key.ptr()) == SUCCESS;
        return ret;
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
        return {Z_ARRVAL_P(ptr())->arData, Z_ARRVAL_P(ptr())->arData + Z_ARRVAL_P(ptr())->nNumUsed};
    }
    ArrayIterator end() {
        return {Z_ARRVAL_P(ptr())->arData + Z_ARRVAL_P(ptr())->nNumUsed};
    }
    size_t count() {
        return zend_hash_num_elements(Z_ARRVAL_P(ptr()));
    }
    bool empty() {
        return count() == 0;
    }
    Variant search(Variant &_other_var, bool strict = false) {
        for (auto i = this->begin(); i != this->end(); i++) {
            if (i.value().equals(_other_var, strict)) {
                return i.key();
            }
        }
        return false;
    }
    bool contains(Variant &_other_var, bool strict = false) {
        for (auto i = this->begin(); i != this->end(); i++) {
            if (i.value().equals(_other_var, strict)) {
                return true;
            }
        }
        return false;
    }
    String join(String &delim) {
        Variant retval;
#if PHP_VERSION_ID >= 80000
        php_implode(delim.ptr(), HASH_OF(ptr()), retval.ptr());
#else
        php_implode(delim.ptr(), ptr(), retval.ptr());
#endif
        retval.addRef();
        return retval.ptr();
    }
    void merge(Array &source, bool overwrite = false) {
        zend_hash_merge(Z_ARRVAL_P(ptr()), Z_ARRVAL_P(source.ptr()), zval_add_ref, overwrite);
    }
    void sort(bool renumber = true) {
        zend_hash_sort(Z_ARRVAL_P(ptr()), array_data_compare, renumber);
    }
    Array slice(long offset, long length = -1, bool preserve_keys = false);
};

class Args {
  public:
    ~Args() {
        if (ptr_list) {
            efree(ptr_list);
        }
        if (zval_list) {
            efree(zval_list);
        }
    }
    void append(zval *v) {
        if (UNEXPECTED(argc == size)) {
            if (UNEXPECTED(!extend())) {
                return;
            }
        }
        ptr_list[argc++] = v;
    }
    void append(const Variant &v) {
        if (UNEXPECTED(argc == size)) {
            if (UNEXPECTED(!extend())) {
                return;
            }
        }
        int index = argc++;
        ptr_list[index] = &zval_list[index];
        memcpy(&zval_list[index], const_cast<Variant &>(v).ptr(), sizeof(zval));
        zval_add_ref(ptr_list[index]);
    }
    size_t count() const {
        return argc;
    }
    bool exists(int i) const {
        return i < argc;
    }
    bool empty() const {
        return argc == 0;
    }
    Array toArray() {
        Array array;
        for (int i = 0; i < argc; i++) {
            array.append(Variant(ptr_list[i]));
        }
        return array;
    }
    Variant operator[](int i) {
        if (UNEXPECTED(i >= argc)) {
            return {nullptr};
        }
        zval *value = ptr_list[i];
        return {value, true};
    }

  private:
    bool extend() {
        int _new_size = size == 0 ? PHPX_MAX_ARGC : size * 2;
        zval **_new_ptr = static_cast<zval **>(ecalloc(_new_size, sizeof(zval *)));
        if (UNEXPECTED(_new_ptr == nullptr)) {
            return false;
        }
        zval *_new_zval_ptr = static_cast<zval *>(ecalloc(_new_size, sizeof(zval)));
        if (UNEXPECTED(_new_zval_ptr == nullptr)) {
            efree(_new_ptr);
            return false;
        }
        ptr_list = _new_ptr;
        zval_list = _new_zval_ptr;
        size = _new_size;
        return true;
    }
    int argc = 0;
    int size = 0;
    zval **ptr_list = nullptr;
    zval *zval_list = nullptr;
};

extern Variant _call(zval *object, zval *func, Args &args);
extern Variant _call(zval *object, zval *func);

static Variant call(const Variant &func) {
    return _call(nullptr, const_cast<Variant &>(func).ptr());
}

static Variant call(const Variant &func, Args &args) {
    return _call(NULL, const_cast<Variant &>(func).ptr(), args);
}

static Variant call(const Variant &func, Array &args) {
    Args _args;
    for (size_t i = 0; i < args.count(); i++) {
        _args.append(args[i].ptr());
    }
    return _call(NULL, const_cast<Variant &>(func).ptr(), _args);
}

static Variant exec(const char *func) {
    Variant _func(func);
    Args args;
    return _call(NULL, _func.ptr(), args);
}
/*generator*/
extern Variant exec(const char *func, const Variant &v1);
extern Variant exec(const char *func, const Variant &v1, const Variant &v2);
extern Variant exec(const char *func, const Variant &v1, const Variant &v2, const Variant &v3);
extern Variant exec(const char *func, const Variant &v1, const Variant &v2, const Variant &v3, const Variant &v4);
extern Variant exec(
    const char *func, const Variant &v1, const Variant &v2, const Variant &v3, const Variant &v4, const Variant &v5);
extern Variant exec(const char *func,
                    const Variant &v1,
                    const Variant &v2,
                    const Variant &v3,
                    const Variant &v4,
                    const Variant &v5,
                    const Variant &v6);
extern Variant exec(const char *func,
                    const Variant &v1,
                    const Variant &v2,
                    const Variant &v3,
                    const Variant &v4,
                    const Variant &v5,
                    const Variant &v6,
                    const Variant &v7);
extern Variant exec(const char *func,
                    const Variant &v1,
                    const Variant &v2,
                    const Variant &v3,
                    const Variant &v4,
                    const Variant &v5,
                    const Variant &v6,
                    const Variant &v7,
                    const Variant &v8);
extern Variant exec(const char *func,
                    const Variant &v1,
                    const Variant &v2,
                    const Variant &v3,
                    const Variant &v4,
                    const Variant &v5,
                    const Variant &v6,
                    const Variant &v7,
                    const Variant &v8,
                    const Variant &v9);
extern Variant exec(const char *func,
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
/*generator*/

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

static Variant global(const char *name) {
    zend_string *key = zend_string_init(name, strlen(name), false);
    zend_is_auto_global(key);
    zval *var = zend_hash_find_ind(&EG(symbol_table), key);
    zend_string_free(key);
    if (!var) {
        return false;
    }
    return {var, true};
}

class Object : public Variant {
  public:
    Object(const Variant &v) {
        if (!v.isObject()) {
            error(E_ERROR, "parameter 1 must be zend_object.");
            return;
        }
        ref_val = const_cast<Variant &>(v).ptr();
        reference = true;
    }
    Object(zval *v) : Variant(v) {}
    Object(zval *v, bool ref) : Variant(v, ref) {}
    Object() = default;
    Variant call(Variant &func, Args &args) {
        return _call(ptr(), func.ptr(), args);
    }
    Variant call(const char *func, Args &args) {
        Variant _func(func);
        return _call(ptr(), _func.ptr(), args);
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
    Variant exec(const char *func) {
        Variant _func(func);
        return _call(ptr(), _func.ptr());
    }

    /*generator*/
    Variant exec(const char *func, const Variant &v1);
    Variant exec(const char *func, const Variant &v1, const Variant &v2);
    Variant exec(const char *func, const Variant &v1, const Variant &v2, const Variant &v3);
    Variant exec(const char *func, const Variant &v1, const Variant &v2, const Variant &v3, const Variant &v4);
    Variant exec(const char *func,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5);
    Variant exec(const char *func,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5,
                 const Variant &v6);
    Variant exec(const char *func,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5,
                 const Variant &v6,
                 const Variant &v7);
    Variant exec(const char *func,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5,
                 const Variant &v6,
                 const Variant &v7,
                 const Variant &v8);
    Variant exec(const char *func,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5,
                 const Variant &v6,
                 const Variant &v7,
                 const Variant &v8,
                 const Variant &v9);
    Variant exec(const char *func,
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
    /*generator*/

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
    void set(const char *name, std::string &v) {
        zend_update_property_stringl(ce(), object(), name, strlen(name), v.c_str(), v.length());
    }
    void set(const char *name, std::string v) {
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
        return std::string(Z_OBJCE_P(ptr())->name->val, Z_OBJCE_P(ptr())->name->len);
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

PHPX_API static Object create(const char *name, Args &args) {
    zend_class_entry *ce = getClassEntry(name);
    Object object;
    if (ce == NULL) {
        php_error_docref(NULL, E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    object.call("__construct", args);
    return object;
}

PHPX_API static Object create(const char *name) {
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        php_error_docref(nullptr, E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    return object;
}

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
#define PHPX_ME(c, m) #m, c## _## m

class Function {
    const char *name_;

  public:
    explicit Function(const char *name) {
        name_ = name;
    }
    virtual ~Function() = default;
    virtual void impl(Args &, Variant &) = 0;
};

#define PHPX_FUNCTION(func)                                                                                            \
    class phpx_function_## func : Function {                                                                            \
      public:                                                                                                          \
        void impl(Args &, Variant &retval);                                                                            \
        phpx_function_## func(const char *name) : Function(name) {                                                      \
            function_map[name] = this;                                                                                 \
        }                                                                                                              \
        ~phpx_function_## func() {}                                                                                     \
    };                                                                                                                 \
    static phpx_function_## func f_## func(#func);                                                                       \
    PHP_FUNCTION(func) {}                                                                                              \
    void phpx_function_## func::impl(Args &args, Variant &retval)

class Method {
    const char *class_;
    const char *name_;

  public:
    Method(const char *_class, const char *_name) {
        name_ = _name;
        class_ = _class;
    }
    virtual ~Method() = default;
    virtual void impl(Object &, Args &, Variant &) = 0;
};

#define PHPX_METHOD(class_, method)                                                                                    \
    class phpx_method_## class_## _## method : Method {                                                                   \
      public:                                                                                                          \
        void impl(Object &_this, Args &, Variant &retval);                                                             \
        phpx_method_## class_## _## method(const char *_class, const char *_name) : Method(_class, _name) {               \
            method_map[_class][_name] = this;                                                                          \
        }                                                                                                              \
        ~phpx_method_## class_## _## method() {}                                                                          \
    };                                                                                                                 \
    static phpx_method_## class_## _## method m_## class_## _## method(#class_, #method);                                    \
    PHP_METHOD(class_, method) {}                                                                                      \
    void phpx_method_## class_## _## method::impl(Object &_this, Args &args, Variant &retval)

extern void _exec_function(zend_execute_data *data, zval *return_value);
extern void _exec_method(zend_execute_data *data, zval *return_value);

zend_function_entry *copy_function_entries(const zend_function_entry *_functions);

String number_format(double num, int decimals = 0, char dec_point = '.', char thousands_sep = ',');
Variant http_build_query(const Variant &data,
                         const char *prefix = nullptr,
                         const char *arg_sep = nullptr,
                         int enc_type = PHP_QUERY_RFC1738);

extern Variant constant(const char *name);
extern bool define(const char *name, const Variant &v, bool case_sensitive = true);

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
    bool implements(const char *name);
    bool implements(zend_class_entry *interface_ce);
    bool addConstant(const char *name, Variant v);
    bool addProperty(const char *name, Variant v, int flags);
    bool registerFunctions(const zend_function_entry *functions);
    bool activate();
    bool alias(const char *alias_name);

    const std::string &getName() {
        return class_name;
    }
    zend_class_entry *ptr() const {
        return ce;
    }
    Variant getStaticProperty(const std::string &p_name) {
        if (!activated) {
            return nullptr;
        }
        return {zend_read_static_property(ce, p_name.c_str(), p_name.length(), true)};
    }
    bool setStaticProperty(const std::string &p_name, Variant value) {
        if (!activated) {
            return false;
        }
        value.addRef();
        return zend_update_static_property(ce, p_name.c_str(), p_name.length(), value.ptr()) == SUCCESS;
    }
    static Variant get(const char *name, const std::string &p_name) {
        zend_class_entry *_tmp_ce = getClassEntry(name);
        if (!_tmp_ce) {
            return nullptr;
        }
        return {zend_read_static_property(_tmp_ce, p_name.c_str(), p_name.length(), true)};
    }
    static bool set(const char *class_name, const std::string &p_name, Variant value) {
        zend_class_entry *_tmp_ce = getClassEntry(class_name);
        if (!_tmp_ce) {
            return false;
        }
        value.addRef();
        return zend_update_static_property(_tmp_ce, p_name.c_str(), p_name.length(), value.ptr()) == SUCCESS;
    }

  protected:
    bool activated;
    std::string class_name;
    std::string parent_class_name;
    zend_class_entry *parent_ce;
    zend_class_entry _ce;
    zend_class_entry *ce;
    std::unordered_map<std::string, zend_class_entry *> interfaces;
    zend_function_entry *functions;
    std::vector<Property> propertys;
    std::vector<Constant> constants;
    std::vector<std::string> aliases;
};

class Interface {
  public:
    Interface(const char *name) {
        this->name = name;
        INIT_CLASS_ENTRY_EX(_ce, name, strlen(name), nullptr);
        ce = nullptr;
        functions = nullptr;
    }
    std::string getName() {
        return name;
    }
    void registerFunctions(const zend_function_entry *_functions) {
        functions = _functions;
    }
    bool activate() {
        if (activated) {
            return false;
        }
        _ce.info.internal.builtin_functions = functions;
        ce = zend_register_internal_interface(&_ce TSRMLS_CC);
        if (ce == nullptr) {
            return false;
        }
        activated = true;
        return true;
    }

  protected:
    bool activated = false;
    std::string name;
    zend_class_entry _ce;
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
    friend zend_result extension_startup(int type, int module_number);
    friend zend_result extension_shutdown(int type, int module_number);

  protected:
    zend_module_entry module = {
        STANDARD_MODULE_HEADER_EX,
        nullptr,
        NULL,
        NULL,                      // name
        NULL,                      // functions
        extension_startup,         // MINIT
        extension_shutdown,        // MSHUTDOWN
        extension_before_request,  // RINIT
        extension_after_request,   // RSHUTDOWN
        extension_info,            // MINFO
        NULL,                      // version
        STANDARD_MODULE_PROPERTIES,
    };

    // INI
    struct IniEntry {
        std::string name;
        std::string default_value;
        int modifiable;
    };

    void registerIniEntries(int module_number);
    void unregisterIniEntries(int module_number);

  public:
    enum StartupStatus {
        BEFORE_START,
        AFTER_START,
    };

    Extension(const char *name, const char *version);

    void checkStartupStatus(enum StartupStatus status, const char *func) const {
        if (status == AFTER_START && !this->started) {
            zend_error(E_CORE_ERROR, "php::%s must be called after startup.", func);
        } else if (status == BEFORE_START && this->started) {
            zend_error(E_CORE_ERROR, "php::%s must be called before startup.", func);
        }
    }

    bool registerClass(Class *c);
    bool registerInterface(Interface *i);
    bool registerFunctions(const zend_function_entry *functions);
    bool registerResource(const char *name, resource_dtor dtor);
    void registerConstant(const char *name, long v);
    void registerConstant(const char *name, int v);
    void registerConstant(const char *name, bool v);
    void registerConstant(const char *name, double v);
    void registerConstant(const char *name, float v);
    void registerConstant(const char *name, const char *v);
    void registerConstant(const char *name, const char *v, size_t len);
    void registerConstant(const char *name, std::string &v);

    bool require(const char *name, const char *version = nullptr);

    void info(const std::vector<std::string> &header, const std::vector<std::vector<std::string>> &body) {
        this->header = header;
        this->body = body;
    }

    // modifiable can be one of these:PHP_INI_SYSTEM/PHP_INI_PERDIR/PHP_INI_USER/PHP_INI_ALL
    void addIniEntry(const char *name, const char *default_value = "", int modifiable = PHP_INI_ALL) {
        IniEntry entry;
        entry.name = name;
        entry.default_value = default_value;
        entry.modifiable = modifiable;
        ini_entries.push_back(entry);
    }

    std::string name;
    std::string version;
    bool started = false;

    std::function<void(void)> onStart = nullptr;
    std::function<void(void)> onShutdown = nullptr;
    std::function<void(void)> onBeforeRequest = nullptr;
    std::function<void(void)> onAfterRequest = nullptr;

    std::vector<std::string> header;
    std::vector<std::vector<std::string>> body;

  protected:
    int function_count = 0;
    int function_array_size = 0;
    int deps_count = 0;
    int deps_array_size = 0;

    zend_function_entry *functions;
    std::vector<IniEntry> ini_entries;
};

extern std::unordered_map<std::string, Extension *> _name_to_extension;
extern std::unordered_map<int, Extension *> _module_number_to_extension;

extern Object newObject(const char *name);

/*generator*/
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
/*generator*/

// namespace end
}  // namespace php
