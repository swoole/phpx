/*
  +----------------------------------------------------------------------+
  | Swoole                                                               |
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

extern "C"
{
#include "php.h"
#include "php_ini.h"
#include "php_globals.h"
#include "php_main.h"

#include "zend_API.h"
#include "php_streams.h"
#include "php_network.h"

#if PHP_MAJOR_VERSION < 7
#error "only supports PHP7 or later."
#endif

#include "zend_interfaces.h"
#include "zend_exceptions.h"
#include "zend_variables.h"
#include "zend_inheritance.h"

#include <ext/date/php_date.h>
#include <ext/standard/url.h>
#include <ext/standard/info.h>
#include <ext/standard/php_array.h>
#include "ext/standard/php_var.h"
}

#include <unordered_map>
#include <string>
#include <vector>
#include <functional>

#define PHPX_MAX_ARGC        10
#define PHPX_VAR_DUMP_LEVEL  10

using namespace std;

namespace php
{

void error(int level, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    php_verror(NULL, "", level, format, args);
    va_end(args);
}

void echo(const char *format, ...)
{
    va_list args;
    char *buffer;
    size_t size;

    va_start(args, format);
    size = vspprintf(&buffer, 0, format, args);
    PHPWRITE(buffer, size);
    efree(buffer);
    va_end(args);
}

struct Resource
{
    const char *name;
    int type;
};
static unordered_map<string, Resource *> resource_map;

class Variant
{
public:
    Variant()
    {
        init();
        ZVAL_NULL(&val);
    }
    Variant(nullptr_t v)
    {
        init();
        ZVAL_NULL(&val);
    }
    Variant(long v)
    {
        init();
        ZVAL_LONG(&val, v);
    }
    Variant(int v)
    {
        init();
        ZVAL_LONG(&val, (long )v);
    }
    Variant(const char *str)
    {
        init();
        ZVAL_STRING(&val, str);
    }
    Variant(const char *str, size_t len)
    {
        init();
        ZVAL_STRINGL(&val, str, len);
    }
    Variant(string &str)
    {
        init();
        ZVAL_STRINGL(&val, str.c_str(), str.length());
    }
    Variant(double v)
    {
        init();
        ZVAL_DOUBLE(&val, v);
    }
    Variant(float v)
    {
        init();
        ZVAL_DOUBLE(&val, (double )v);
    }
    Variant(bool v)
    {
        init();
        ZVAL_BOOL(&val, v);
    }
    Variant(zval *v)
    {
        reference = false;
        ref_val = NULL;
        memcpy(&val, v, sizeof(zval));
        zval_add_ref(&val);
    }
    Variant(zval *v, bool ref)
    {
        ref_val = v;
        reference = ref;
    }
    Variant(zend_resource *res)
    {
        init();
        ZVAL_RES(ptr(), res);
    }
    ~Variant()
    {
        if (!reference)
        {
            zval_ptr_dtor(&val);
        }
    }
    void operator =(Variant v)
    {
        copy(v);
    }
    inline zval *ptr(void)
    {
        if (reference)
        {
            return ref_val;
        }
        else
        {
            return &val;
        }
    }
    inline void addRef()
    {
        zval_add_ref(ptr());
    }
    inline void delRef()
    {
        zval_delref_p(ptr());
    }
    inline int getRefCount()
    {
        return GC_REFCOUNT(Z_COUNTED_P(ptr()));
    }
    inline int type()
    {
        return Z_TYPE_P(ptr());
    }
    inline bool isString()
    {
        return Z_TYPE_P(ptr()) == IS_STRING;
    }
    inline bool isArray()
    {
        return Z_TYPE_P(ptr()) == IS_ARRAY;
    }
    inline bool isObject()
    {
        return Z_TYPE_P(ptr()) == IS_OBJECT;
    }
    inline bool isInt()
    {
        return Z_TYPE_P(ptr()) == IS_LONG;
    }
    inline bool isFloat()
    {
        return Z_TYPE_P(ptr()) == IS_DOUBLE;
    }
    inline bool isBool()
    {
        return Z_TYPE_P(ptr()) == IS_TRUE || Z_TYPE_P(ptr()) == IS_FALSE;
    }
    inline bool isNull()
    {
        return Z_TYPE_P(ptr()) == IS_NULL;
    }
    inline bool isResource()
    {
        return Z_TYPE_P(ptr()) == IS_RESOURCE;
    }
    inline bool isReference()
    {
        return Z_TYPE_P(ptr()) == IS_REFERENCE;
    }
    inline string toString()
    {
        if (!isString())
        {
            convert_to_string(ptr());
        }
        return string(Z_STRVAL_P(ptr()), Z_STRLEN_P(ptr()));
    }
    inline char* toCString()
    {
        if (!isString())
        {
            convert_to_string(ptr());
        }
        return Z_STRVAL_P(ptr());
    }
    inline long toInt()
    {
        if (!isInt())
        {
            convert_to_long(ptr());
        }
        return Z_LVAL_P(ptr());
    }
    inline double toFloat()
    {
        if (!isFloat())
        {
            convert_to_double(ptr());
        }
        return Z_DVAL_P(ptr());
    }
    inline bool toBool()
    {
        if (!isBool())
        {
            convert_to_boolean(ptr());
        }
        return Z_TYPE_P(ptr()) == IS_TRUE;
    }
    void copy(Variant &v)
    {
        ZVAL_COPY_VALUE(ptr(), v.ptr());
        addRef();
    }
    void copy(char *str, size_t size)
    {
        ZVAL_STRINGL(ptr(), str, size);
    }
    Variant* dup()
    {
        Variant *v = new Variant(ptr());
        return v;
    }
    inline size_t length()
    {
        if (!isString())
        {
            convert_to_string(ptr());
        }
        return Z_STRLEN_P(ptr());
    }
    template<class T>
    T* toResource(const char *name)
    {
        if (!isResource())
        {
            error(E_WARNING, "This variant is not a resource type.");
            return nullptr;
        }
        void *_ptr = nullptr;
        Resource *_c = resource_map[name];
        if (_c == nullptr)
        {
            error(E_WARNING, "The %s type of resource is undefined.", name);
            return nullptr;
        }
        if ((_ptr = zend_fetch_resource(Z_RES_P(ptr()), name, _c->type)) == NULL)
        {
            error(E_WARNING, "The %s type of resource is undefined.", name);
            return nullptr;
        }
        return static_cast<T *>(_ptr);
    }
    bool equals(Variant &v, bool strict = false)
    {
        if (strict)
        {
            if (fast_is_identical_function(v.ptr(), ptr()))
            {
                return true;
            }
        }
        else
        {
            if (v.isInt())
            {
                if (fast_equal_check_long(v.ptr(), ptr()))
                {
                    return true;
                }
            }
            else if (v.isString())
            {
                if (fast_equal_check_string(v.ptr(), ptr()))
                {
                    return true;
                }
            }
            else
            {
                if (fast_equal_check_function(v.ptr(), ptr()))
                {
                    return true;

                }
            }
        }
        return false;
    }
protected:
    bool reference;
    zval *ref_val;
    zval val;
    inline void init()
    {
        reference = false;
        ref_val = NULL;
        memset(&val, 0, sizeof(val));
    }
};

void var_dump(Variant &v)
{
    php_var_dump(v.ptr(), PHPX_VAR_DUMP_LEVEL);
}

class String
{
public:
    String(const char *str)
    {
        value = zend_string_init(str, strlen(str), 0);
    }
    String(const char *str, size_t len)
    {
        value = zend_string_init(str, len, 0);
    }
    String(string &str)
    {
        value = zend_string_init(str.c_str(), str.length(), 0);
    }
    String(Variant &v)
    {
        if (v.type() != IS_STRING)
        {
            error(E_ERROR, "parameter 1 must be zend_string.");
        }
        value = Z_STR_P(v.ptr());
        free_memory = false;
    }
    ~String()
    {
        if (free_memory)
        {
            zend_string_free(value);
        }
    }
    size_t length()
    {
        return value->len;
    }
    char* c_str()
    {
        return value->val;
    }
    void extend(size_t new_size)
    {
        value = zend_string_extend(value, new_size, 0);
    }
    bool equals(const char *str)
    {
        return memcmp(str, value->val, value->len) == 0;
    }
    bool equals(string &str)
    {
        if (str.length() != value->len)
        {
            return false;
        }
        return memcmp(str.c_str(), value->val, value->len) == 0;
    }
    bool equals(String &str, bool ci = false)
    {
        if (str.length() != value->len)
        {
            return false;
        }
        if (ci)
        {
            return zend_binary_strcasecmp(str.c_str(), str.length(), value->val, value->len) == 0;
        }
        return memcmp(str.c_str(), value->val, value->len) == 0;
    }
    void tolower()
    {
        zend_str_tolower(value->val, value->len);
    }
    String substr(long _offset, long _length = -1)
    {
        if ((_length < 0 && (size_t) (-_length) > this->length()))
        {
            return "";
        }
        else if (_length > (zend_long) this->length())
        {
            _length = this->length();
        }

        if (_offset > (zend_long) this->length())
        {
            return "";
        }
        else if (_offset < 0 && -_offset > this->length())
        {
            _offset = 0;
        }

        if (_length < 0 && (_length + (zend_long) this->length() - _offset) < 0)
        {
            return "";
        }

        /* if "from" position is negative, count start position from the end
         * of the string
         */
        if (_offset < 0)
        {
            _offset = (zend_long) this->length() + _offset;
            if (_offset < 0)
            {
                _offset = 0;
            }
        }

        /* if "length" position is negative, set it to the length
         * needed to stop that many chars from the end of the string
         */
        if (_length < 0)
        {
            _length = ((zend_long) this->length() - _offset) + _length;
            if (_length < 0)
            {
                _length = 0;
            }
        }

        if (_offset > (zend_long) this->length())
        {
            return "";
        }

        if ((_offset + _length) > (zend_long) this->length())
        {
            _length = this->length() - _offset;
        }

        return String(value->val + _offset, _length);
    }
    zend_string* ptr()
    {
        return value;
    }
protected:
    bool free_memory = true;
    zend_string *value;
};

class ArrayIterator
{
public:
    ArrayIterator(Bucket *p)
    {
        _ptr = p;
        _key = _ptr->key;
        _val = &_ptr->val;
        _index = _ptr->h;
        pe = p;
    }
    ArrayIterator(Bucket *p, Bucket *_pe)
    {
        _ptr = p;
        _key = _ptr->key;
        _val = &_ptr->val;
        _index = _ptr->h;
        pe = _pe;
    }
    void operator ++(int i)
    {
        while (1)
        {
            _ptr++;
            _val = &_ptr->val;
            if (_val && Z_TYPE_P(_val) == IS_INDIRECT)
            {
                _val = Z_INDIRECT_P(_val);
            }
            if (UNEXPECTED(Z_TYPE_P(_val) == IS_UNDEF) && pe != _ptr)
            {
                continue;
            }
            if (_ptr->key)
            {
                _key = _ptr->key;
                _index = 0;
            }
            else
            {
                _index = _ptr->h;
                _key = NULL;
            }
            break;
        }
    }
    bool operator !=(ArrayIterator b)
    {
        return b.ptr() != _ptr;
    }
    Variant key()
    {
        if (_key)
        {
            return Variant(_key->val, _key->len);
        }
        else
        {
            return Variant((long) _index);
        }
    }
    Variant value()
    {
        return Variant(_val);
    }
    Bucket *ptr()
    {
        return _ptr;
    }
private:
    zval *_val;
    zend_string *_key;
    Bucket *_ptr;
    Bucket *pe;
    zend_ulong _index;
};

static int array_data_compare(const void *a, const void *b)
{
    Bucket *f;
    Bucket *s;
    zval result;
    zval *first;
    zval *second;

    f = (Bucket *) a;
    s = (Bucket *) b;

    first = &f->val;
    second = &s->val;

    if (UNEXPECTED(Z_TYPE_P(first) == IS_INDIRECT))
    {
        first = Z_INDIRECT_P(first);
    }
    if (UNEXPECTED(Z_TYPE_P(second) == IS_INDIRECT))
    {
        second = Z_INDIRECT_P(second);
    }
    if (compare_function(&result, first, second) == FAILURE)
    {
        return 0;
    }

    ZEND_ASSERT(Z_TYPE(result) == IS_LONG);
    return Z_LVAL(result);
}

class Array: public Variant
{
public:
    Array() :
            Variant()
    {
        array_init(&val);
    }
    Array(zval *v) :
            Variant(v)
    {
        ref_val = v;
        reference = true;
        if (Z_TYPE_P(v) == IS_NULL)
        {
            array_init(v);
        }
        else if (Z_TYPE_P(v) != IS_ARRAY)
        {
            error(E_ERROR, "parameter 1 must be zend_array.");
        }
    }
    Array(Variant &v)
    {
        ref_val = v.ptr();
        reference = true;
        if (v.isNull())
        {
            array_init(ref_val);
        }
        else if (!v.isArray())
        {
            error(E_ERROR, "parameter 1 must be zend_array.");
        }
    }
    void append(Variant v)
    {
        v.addRef();
        add_next_index_zval(ptr(), v.ptr());
    }
    void append(const char *str)
    {
        add_next_index_string(ptr(), str);
    }
    void append(string &str)
    {
        add_next_index_stringl(ptr(), str.c_str(), str.length());
    }
    void append(long v)
    {
        add_next_index_long(ptr(), v);
    }
    void append(int v)
    {
        add_next_index_long(ptr(), (long) v);
    }
    void append(bool v)
    {
        add_next_index_bool(ptr(), v ? 1 : 0);
    }
    void append(double v)
    {
        add_next_index_double(ptr(), (double) v);
    }
    void append(float v)
    {
        add_next_index_double(ptr(), (double) v);
    }
    void append(zval *v)
    {
        zval_add_ref(v);
        add_next_index_zval(ptr(), v);
    }
    void append(void *v)
    {
        add_next_index_null(ptr());
    }
    void append(Array &v)
    {
        zend_array *arr = zend_array_dup(Z_ARR_P(v.ptr()));
        zval array;
        ZVAL_ARR(&array, arr);
        add_next_index_zval(ptr(), &array);
    }
    //------------------assoc-array------------------
    void set(const char *key, Variant &v)
    {
        add_assoc_zval(ptr(), key, v.ptr());
    }
    void set(const char *key, int v)
    {
        add_assoc_long(ptr(), key, (long) v);
    }
    void set(const char *key, long v)
    {
        add_assoc_long(ptr(), key, v);
    }
    void set(const char *key, const char *v)
    {
        add_assoc_string(ptr(), key, (char * )v);
    }
    void set(const char *key, string &v)
    {
        add_assoc_stringl(ptr(), key, (char* )v.c_str(), v.length());
    }
    void set(const char *key, double v)
    {
        add_assoc_double(ptr(), key, v);
    }
    void set(const char *key, float v)
    {
        add_assoc_double(ptr(), key, (double ) v);
    }
    void set(const char *key, bool v)
    {
        add_assoc_bool(ptr(), key, v ? 1 : 0);
    }
    void set(int i, Variant v)
    {
        v.addRef();
        add_index_zval(ptr(), (zend_ulong) i, v.ptr());
    }
    //-------------------------------------------
    Variant operator [](int i)
    {
        zval *ret = zend_hash_index_find(Z_ARRVAL_P(ptr()), (zend_ulong) i);
        if (ret == NULL)
        {
            return Variant(nullptr);
        }
        return Variant(ret);
    }
    Variant operator [](const char *key)
    {
        zval *ret = zend_hash_str_find(Z_ARRVAL_P(ptr()), key, strlen(key));
        if (ret == NULL)
        {
            return Variant(nullptr);
        }
        return Variant(ret);
    }
    bool remove(const char *key)
    {
        String _key(key);
        bool ret = zend_hash_del(Z_ARRVAL_P(ptr()),  _key.ptr()) == SUCCESS;
        return ret;
    }
    void clean()
    {
        zend_hash_clean(Z_ARRVAL_P(ptr()));
    }
    bool exists(const char *key)
    {
        return zend_hash_str_exists(Z_ARRVAL_P(ptr()), key, strlen(key));
    }
    bool exists(string &key)
    {
        return zend_hash_str_exists(Z_ARRVAL_P(ptr()), key.c_str(), key.length());
    }
    ArrayIterator begin()
    {
        return ArrayIterator(Z_ARRVAL_P(ptr())->arData, Z_ARRVAL_P(ptr())->arData + Z_ARRVAL_P(ptr())->nNumUsed);
    }
    ArrayIterator end()
    {
        return ArrayIterator(Z_ARRVAL_P(ptr())->arData + Z_ARRVAL_P(ptr())->nNumUsed);
    }
    inline size_t count()
    {
        return zend_hash_num_elements(Z_ARRVAL_P(ptr()));
    }
    bool empty()
    {
        return count() == 0;
    }
    Variant search(Variant &_other_var, bool strict = false)
    {
        for (auto i = this->begin(); i != this->end(); i++)
        {
            if (i.value().equals(_other_var, strict))
            {
                return i.key();
            }
        }
        return false;
    }
    bool contains(Variant &_other_var, bool strict = false)
    {
        for (auto i = this->begin(); i != this->end(); i++)
        {
            if (i.value().equals(_other_var, strict))
            {
                return true;
            }
        }
        return false;
    }
    void merge(Array &source, bool overwrite = false)
    {
        zend_hash_merge(Z_ARRVAL_P(ptr()), Z_ARRVAL_P(source.ptr()), zval_add_ref, overwrite);
    }
    bool sort()
    {
        return zend_hash_sort(Z_ARRVAL_P(ptr()), array_data_compare, 1) == SUCCESS;
    }
    Array slice(long offset, long length = -1, bool preserve_keys = false)
    {
        size_t num_in = count();

        if (offset > num_in)
        {
            return Array();
        }
        else if (offset < 0 && (offset = (num_in + offset)) < 0)
        {
            offset = 0;
        }

        if (length < 0)
        {
            length = num_in - offset + length;
        }
        else if (((zend_ulong) offset + (zend_ulong) length) > (unsigned) num_in)
        {
            length = num_in - offset;
        }

        if (length <= 0)
        {
            return Array();
        }

        zend_string *string_key;
        zend_ulong num_key;
        zval *entry;

        zval return_value;
        array_init_size(&return_value, (uint32_t ) length);

        /* Start at the beginning and go until we hit offset */
        int pos = 0;
        if (!preserve_keys && (Z_ARRVAL_P(this->ptr())->u.flags & HASH_FLAG_PACKED))
        {
            zend_hash_real_init(Z_ARRVAL_P(&return_value), 1);
            ZEND_HASH_FILL_PACKED(Z_ARRVAL_P(&return_value))
            {
                ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(this->ptr()), entry)
                {
                    pos++;
                    if (pos <= offset)
                    {
                        continue;
                    }
                    if (pos > offset + length)
                    {
                        break;
                    }
                    ZEND_HASH_FILL_ADD(entry);
                    zval_add_ref(entry);
                }
                ZEND_HASH_FOREACH_END();
            }
            ZEND_HASH_FILL_END();
        }
        else
        {
            ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(this->ptr()), num_key, string_key, entry)
            {
                pos++;
                if (pos <= offset)
                {
                    continue;
                }
                if (pos > offset + length)
                {
                    break;
                }

                if (string_key)
                {
                    entry = zend_hash_add_new(Z_ARRVAL_P(&return_value), string_key, entry);
                }
                else
                {
                    if (preserve_keys)
                    {
                        entry = zend_hash_index_add_new(Z_ARRVAL_P(&return_value), num_key, entry);
                    }
                    else
                    {
                        entry = zend_hash_next_index_insert_new(Z_ARRVAL_P(&return_value), entry);
                    }
                }
                zval_add_ref(entry);
            }
            ZEND_HASH_FOREACH_END();
        }
        Array retval(&return_value);
        retval.addRef();
        return retval;
    }
};

static int arg_list_size = 0;
static zval **arg_list = nullptr;

class Args
{
public:
    Args()
    {
        argc = 0;
    }
    void append(zval *v)
    {
        if (argc == arg_list_size)
        {
            int _new_size = arg_list_size == 0 ? PHPX_MAX_ARGC : arg_list_size * 2;
            zval** _new_ptr = (zval**) ecalloc(_new_size, sizeof(zval*));
            if (_new_ptr == nullptr)
            {
                return;
            }
            arg_list = _new_ptr;
            arg_list_size = _new_size;
        }
        arg_list[argc++] = v;
    }
    size_t count()
    {
        return argc;
    }
    bool exists(int i)
    {
        return i < argc;
    }
    bool empty()
    {
        return argc == 0;
    }
    Array toArray()
    {
        Array array;
        for (int i = 0; i < argc; i++)
        {
            array.append(Variant(arg_list[i]));
        }
        array.addRef();
        return array;
    }
    Variant operator [](int i)
    {
        if (i >= argc)
        {
            return Variant(nullptr);
        }
        return Variant(arg_list[i], true);
    }
private:
    int argc;
};

class ArgInfo
{
public:
    ArgInfo(int required_num, bool return_reference = false)
    {
        this->required_num = required_num;
        this->return_reference = return_reference;
        this->info = nullptr;
    }
    void add(const char *name, const char *class_name = nullptr, int type_hint = 0, bool pass_by_reference = false,
            bool allow_null = false, bool variadic = false)
    {
        zend_internal_arg_info val =
        { name, class_name, (zend_uchar)type_hint, pass_by_reference, allow_null, variadic, };
        list.push_back(val);
    }
    zend_internal_arg_info* get()
    {
        if (info != nullptr)
        {
            return info;
        }
        zend_internal_arg_info *_info = (zend_internal_arg_info*) calloc(list.size() + 1,
                sizeof(zend_internal_arg_info));
        if (_info == nullptr)
        {
            return nullptr;
        }
        _info[0].name = (const char*) (zend_uintptr_t) (required_num);
        _info[0].pass_by_reference = return_reference;
        for (int i = 1; i <= list.size(); i++)
        {
            memcpy(&_info[i], &list[i - 1], sizeof(zend_internal_arg_info));
        }
        info = _info;
        return _info;
    }
    size_t count()
    {
        return list.size();
    }
protected:
    int required_num;
    bool return_reference;
    zend_internal_arg_info *info;
    vector<zend_internal_arg_info> list;
};

static inline Variant _call(zval *object, zval *func, Array &args)
{
    Variant retval = false;
    if (args.count() > PHPX_MAX_ARGC)
    {
        return retval;
    }
    zval params[PHPX_MAX_ARGC];
    for (int i = 0; i < args.count(); i++)
    {
        ZVAL_COPY_VALUE(&params[i], args[i].ptr());
    }
    zval _retval;
    if (call_user_function(EG(function_table), object, func, &_retval, args.count(), params) == 0)
    {
        retval = Variant(&_retval);
        retval.addRef();
    }
    return retval;
}

static inline Variant _call(zval *object, zval *func)
{
    Variant retval = false;
    zval _retval;
    if (call_user_function(EG(function_table), object, func, &_retval, 0, NULL) == 0)
    {
        retval = Variant(&_retval);
    }
    return retval;
}

Variant call(Variant &func, Array &args)
{
    func.addRef();
    return _call(NULL, func.ptr(), args);
}

Variant call(Variant &func)
{
    func.addRef();
    return _call(nullptr, func.ptr());
}

Variant call(const char *func, Array &args)
{
    Variant _func(func);
    return _call(NULL, _func.ptr(), args);
}

Variant exec(const char *func)
{
    Variant _func(func);
    Array args;
    return _call(NULL, _func.ptr(), args);
}
/*generator*/
Variant exec(const char *func, Variant v1)
{
    Variant _func(func);
    Array args;
    args.append(v1.ptr());
    return _call(NULL, _func.ptr(), args);
}
Variant exec(const char *func, Variant v1, Variant v2)
{
    Variant _func(func);
    Array args;
    args.append(v1.ptr());
    args.append(v2.ptr());
    return _call(NULL, _func.ptr(), args);
}
Variant exec(const char *func, Variant v1, Variant v2, Variant v3)
{
    Variant _func(func);
    Array args;
    args.append(v1.ptr());
    args.append(v2.ptr());
    args.append(v3.ptr());
    return _call(NULL, _func.ptr(), args);
}
Variant exec(const char *func, Variant v1, Variant v2, Variant v3, Variant v4)
{
    Variant _func(func);
    Array args;
    args.append(v1.ptr());
    args.append(v2.ptr());
    args.append(v3.ptr());
    args.append(v4.ptr());
    return _call(NULL, _func.ptr(), args);
}
Variant exec(const char *func, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5)
{
    Variant _func(func);
    Array args;
    args.append(v1.ptr());
    args.append(v2.ptr());
    args.append(v3.ptr());
    args.append(v4.ptr());
    args.append(v5.ptr());
    return _call(NULL, _func.ptr(), args);
}
Variant exec(const char *func, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6)
{
    Variant _func(func);
    Array args;
    args.append(v1.ptr());
    args.append(v2.ptr());
    args.append(v3.ptr());
    args.append(v4.ptr());
    args.append(v5.ptr());
    args.append(v6.ptr());
    return _call(NULL, _func.ptr(), args);
}
Variant exec(const char *func, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7)
{
    Variant _func(func);
    Array args;
    args.append(v1.ptr());
    args.append(v2.ptr());
    args.append(v3.ptr());
    args.append(v4.ptr());
    args.append(v5.ptr());
    args.append(v6.ptr());
    args.append(v7.ptr());
    return _call(NULL, _func.ptr(), args);
}
Variant exec(const char *func, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7, Variant v8)
{
    Variant _func(func);
    Array args;
    args.append(v1.ptr());
    args.append(v2.ptr());
    args.append(v3.ptr());
    args.append(v4.ptr());
    args.append(v5.ptr());
    args.append(v6.ptr());
    args.append(v7.ptr());
    args.append(v8.ptr());
    return _call(NULL, _func.ptr(), args);
}
Variant exec(const char *func, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7, Variant v8, Variant v9)
{
    Variant _func(func);
    Array args;
    args.append(v1.ptr());
    args.append(v2.ptr());
    args.append(v3.ptr());
    args.append(v4.ptr());
    args.append(v5.ptr());
    args.append(v6.ptr());
    args.append(v7.ptr());
    args.append(v8.ptr());
    args.append(v9.ptr());
    return _call(NULL, _func.ptr(), args);
}
Variant exec(const char *func, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7, Variant v8, Variant v9, Variant v10)
{
    Variant _func(func);
    Array args;
    args.append(v1.ptr());
    args.append(v2.ptr());
    args.append(v3.ptr());
    args.append(v4.ptr());
    args.append(v5.ptr());
    args.append(v6.ptr());
    args.append(v7.ptr());
    args.append(v8.ptr());
    args.append(v9.ptr());
    args.append(v10.ptr());
    return _call(NULL, _func.ptr(), args);
}/*generator*/

static inline zend_class_entry *getClassEntry(const char *name)
{
    String class_name(name, strlen(name));
    return zend_lookup_class(class_name.ptr());
}

void throwException(const char *name, const char *message, int code = 0)
{
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        php_error_docref(NULL, E_WARNING, "class '%s' undefined.", name);
        return;
    }
    zend_throw_exception(ce, message, code TSRMLS_CC);
}

Variant global(const char *name)
{
    zend_string *key = zend_string_init(name, strlen(name), 0);
    zval *var = zend_hash_find_ind(&EG(symbol_table), key);
    if (!var)
    {
        return false;
    }
    return Variant(var, true);
}

class Object: public Variant
{
public:
    Object(Variant &v) :
            Variant()
    {
        if (!v.isObject())
        {
            error(E_ERROR, "parameter 1 must be zend_object.");
            return;
        }
        ref_val = v.ptr();
        reference = true;
        zval_add_ref(ref_val);
    }
    Object(zval *v) :
            Variant(v)
    {

    }
    Object(zval *v, bool ref) :
            Variant(v, ref)
    {

    }
    Object() :
            Variant()
    {

    }
    Variant call(Variant &func, Array &args)
    {
        return _call(ptr(), func.ptr(), args);
    }
    Variant call(const char *func, Array &args)
    {
        Variant _func(func);
        return _call(ptr(), _func.ptr(), args);
    }
    Variant exec(const char *func)
    {
        Variant _func(func);
        return _call(ptr(), _func.ptr());
    }
    /*generator*/
    Variant exec(const char *func, Variant v1)
    {
        Variant _func(func);
        Array args;
        args.append(v1.ptr());
        return _call(ptr(), _func.ptr(), args);
    }
    Variant exec(const char *func, Variant v1, Variant v2)
    {
        Variant _func(func);
        Array args;
        args.append(v1.ptr());
        args.append(v2.ptr());
        return _call(ptr(), _func.ptr(), args);
    }
    Variant exec(const char *func, Variant v1, Variant v2, Variant v3)
    {
        Variant _func(func);
        Array args;
        args.append(v1.ptr());
        args.append(v2.ptr());
        args.append(v3.ptr());
        return _call(ptr(), _func.ptr(), args);
    }
    Variant exec(const char *func, Variant v1, Variant v2, Variant v3, Variant v4)
    {
        Variant _func(func);
        Array args;
        args.append(v1.ptr());
        args.append(v2.ptr());
        args.append(v3.ptr());
        args.append(v4.ptr());
        return _call(ptr(), _func.ptr(), args);
    }
    Variant exec(const char *func, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5)
    {
        Variant _func(func);
        Array args;
        args.append(v1.ptr());
        args.append(v2.ptr());
        args.append(v3.ptr());
        args.append(v4.ptr());
        args.append(v5.ptr());
        return _call(ptr(), _func.ptr(), args);
    }
    Variant exec(const char *func, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6)
    {
        Variant _func(func);
        Array args;
        args.append(v1.ptr());
        args.append(v2.ptr());
        args.append(v3.ptr());
        args.append(v4.ptr());
        args.append(v5.ptr());
        args.append(v6.ptr());
        return _call(ptr(), _func.ptr(), args);
    }
    Variant exec(const char *func, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7)
    {
        Variant _func(func);
        Array args;
        args.append(v1.ptr());
        args.append(v2.ptr());
        args.append(v3.ptr());
        args.append(v4.ptr());
        args.append(v5.ptr());
        args.append(v6.ptr());
        args.append(v7.ptr());
        return _call(ptr(), _func.ptr(), args);
    }
    Variant exec(const char *func, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7, Variant v8)
    {
        Variant _func(func);
        Array args;
        args.append(v1.ptr());
        args.append(v2.ptr());
        args.append(v3.ptr());
        args.append(v4.ptr());
        args.append(v5.ptr());
        args.append(v6.ptr());
        args.append(v7.ptr());
        args.append(v8.ptr());
        return _call(ptr(), _func.ptr(), args);
    }
    Variant exec(const char *func, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7, Variant v8, Variant v9)
    {
        Variant _func(func);
        Array args;
        args.append(v1.ptr());
        args.append(v2.ptr());
        args.append(v3.ptr());
        args.append(v4.ptr());
        args.append(v5.ptr());
        args.append(v6.ptr());
        args.append(v7.ptr());
        args.append(v8.ptr());
        args.append(v9.ptr());
        return _call(ptr(), _func.ptr(), args);
    }
    Variant exec(const char *func, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7, Variant v8, Variant v9, Variant v10)
    {
        Variant _func(func);
        Array args;
        args.append(v1.ptr());
        args.append(v2.ptr());
        args.append(v3.ptr());
        args.append(v4.ptr());
        args.append(v5.ptr());
        args.append(v6.ptr());
        args.append(v7.ptr());
        args.append(v8.ptr());
        args.append(v9.ptr());
        args.append(v10.ptr());
        return _call(ptr(), _func.ptr(), args);
    }
    /*generator*/
    Variant get(const char *name)
    {
        Variant retval;
        zval rv;
        zval *member_p = zend_read_property(Z_OBJCE_P(ptr()), ptr(), name, strlen(name), 0, &rv);
        if (member_p != &rv)
        {
            ZVAL_COPY(retval.ptr(), member_p);
        }
        else
        {
            ZVAL_COPY_VALUE(retval.ptr(), member_p);
        }
        retval.addRef();
        return retval;
    }

    void set(const char *name, Variant &v)
    {
        zend_update_property(Z_OBJCE_P(ptr()), ptr(), name, strlen(name), v.ptr());
    }

    void set(const char *name, Array &v)
    {
        v.addRef();
        zend_update_property(Z_OBJCE_P(ptr()), ptr(), name, strlen(name), v.ptr());
    }
    void set(const char *name, string &v)
    {
        zend_update_property_stringl(Z_OBJCE_P(ptr()), ptr(), name, strlen(name), v.c_str(), v.length());
    }
    void set(const char *name, string v)
    {
        zend_update_property_stringl(Z_OBJCE_P(ptr()), ptr(), name, strlen(name), v.c_str(), v.length());
    }
    void set(const char *name, const char *v)
    {
        zend_update_property_string(Z_OBJCE_P(ptr()), ptr(), name, strlen(name), v);
    }
    void set(const char *name, long v)
    {
        zend_update_property_long(Z_OBJCE_P(ptr()), ptr(), name, strlen(name), v);
    }
    void set(const char *name, double v)
    {
        zend_update_property_double(Z_OBJCE_P(ptr()), ptr(), name, strlen(name), v);
    }
    void set(const char *name, float v)
    {
        zend_update_property_double(Z_OBJCE_P(ptr()), ptr(), name, strlen(name), (double) v);
    }
    void set(const char *name, bool v)
    {
        zend_update_property_bool(Z_OBJCE_P(ptr()), ptr(), name, strlen(name), v ? 1 : 0);
    }
    string getClassName()
    {
        return string(Z_OBJCE_P(ptr())->name->val, Z_OBJCE_P(ptr())->name->len);
    }
    uint32_t getId()
    {
        return Z_OBJ_HANDLE(*ptr());
    }
    bool methodExists(const char *name)
    {
        return zend_hash_str_exists(&Z_OBJCE_P(ptr())->function_table, name, strlen(name));
    }
    bool propertyExists(const char *name)
    {
        return zend_hash_str_exists(&Z_OBJCE_P(ptr())->properties_info, name, strlen(name));
    }
};

Object create(const char *name, Array &args)
{
    zend_class_entry *ce = getClassEntry(name);
    Object object;
    if (ce == NULL)
    {
        php_error_docref(NULL, E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    zval zobject;
    if (object_init_ex(&zobject, ce) == FAILURE)
    {
        return object;
    }
    object = Object(&zobject);
    object.call("__construct", args);
    return object;
}

Object create(const char *name)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        php_error_docref(NULL, E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    zval zobject;
    if (object_init_ex(&zobject, ce) == FAILURE)
    {
        return object;
    }
    object = Object(&zobject);
    return object;
}

#define PHPX_NAME(n)      #n, n
#define PHPX_MNAME(c,m)   c##_##m
#define PHPX_FUNCTION(c)  void c(Args &args, Variant &retval)
#define PHPX_METHOD(c, m) void c##_##m(Object &_this, Args &args, Variant &retval)
#define PHPX_EXTENSION()    extern "C" { ZEND_DLEXPORT Extension* get_module(); } ZEND_DLEXPORT Extension* get_module()

typedef void (*function_t)(Args &, Variant &retval);
typedef void (*resource_dtor)(zend_resource *);
typedef void (*method_t)(Object &, Args &, Variant &retval);
static unordered_map<string, function_t> function_map;
static unordered_map<string, unordered_map<string, method_t> > method_map;

static void _exec_function(zend_execute_data *data, zval *return_value)
{
    string name(data->func->common.function_name->val, data->func->common.function_name->len);
    function_t func = function_map[name];
    Args args;

    zval *param_ptr = ZEND_CALL_ARG(EG(current_execute_data), 1);
    int arg_count = ZEND_CALL_NUM_ARGS(EG(current_execute_data));

    while (arg_count-- > 0)
    {
        args.append(param_ptr);
        param_ptr++;
    }
    Variant _retval(return_value, true);
    func(args, _retval);
}

static void _exec_method(zend_execute_data *data, zval *return_value)
{
    string class_name(data->func->common.scope->name->val, data->func->common.scope->name->len);
    string method_name(data->func->common.function_name->val, data->func->common.function_name->len);

    method_t func = method_map[class_name][method_name];
    Args args;

    Object _this(&data->This, true);

    zval *param_ptr = ZEND_CALL_ARG(EG(current_execute_data), 1);
    int arg_count = ZEND_CALL_NUM_ARGS(EG(current_execute_data));

    while (arg_count-- > 0)
    {
        args.append(param_ptr);
        param_ptr++;
    }
    Variant _retval(return_value, true);
    func(_this, args, _retval);
}

Variant constant(const char *name)
{
    zend_string *_name = zend_string_init(name, strlen(name), 0);
    zval *val = zend_get_constant_ex(_name, NULL, ZEND_FETCH_CLASS_SILENT);
    zend_string_free(_name);
    if (val == NULL)
    {
        return nullptr;
    }
    Variant retval(val);
    return retval;
}

enum ClassFlags
{
    STATIC = ZEND_ACC_STATIC,
    ABSTRACT = ZEND_ACC_ABSTRACT,
    FINAL = ZEND_ACC_FINAL,
    INTERFACE = ZEND_ACC_INTERFACE,
    TRAIT = ZEND_ACC_TRAIT,
    PUBLIC = ZEND_ACC_PUBLIC,
    PROTECTED = ZEND_ACC_PROTECTED,
    PRIVATE = ZEND_ACC_PRIVATE,
    CONSTRUCT = ZEND_ACC_CTOR,
    DESTRUCT = ZEND_ACC_DTOR,
    CLONE = ZEND_ACC_CLONE,
};

enum SortFlags
{
    SORT_REGULAR = 0,
    SORT_NUMERIC = 1,
    SORT_STRING = 2,
    SORT_DESC = 3,
    SORT_ASC = 4,
    SORT_LOCALE_STRING = 5,
    SORT_NATURAL = 6,
    SORT_FLAG_CASE = 8,
};

struct Method
{
    string name;
    int flags;
    method_t method;
    ArgInfo *info;
};

class Class
{
    struct Property
    {
        string name;
        zval value;
        int flags;
    };

    struct Constant
    {
        string name;
        zval value;
    };

public:
    Class(const char *name)
    {
        class_name = name;
        INIT_CLASS_ENTRY_EX(_ce, name, strlen(name), NULL);
        parent_ce = NULL;
        ce = NULL;
        activated = false;
    }
    bool extends(const char *_parent_class)
    {
        if (activated)
        {
            return false;
        }
        parent_class_name = _parent_class;
        parent_ce = getClassEntry(_parent_class);
        return parent_ce != NULL;
    }
    bool extends(Class *parent)
    {
        if (activated)
        {
            return false;
        }
        parent_class_name = parent->getName();
        parent_ce = parent->ptr();
        return parent_ce != NULL;
    }
    bool implements(const char *name)
    {
        if (activated)
        {
            return false;
        }
        if (interfaces.find(name) != interfaces.end())
        {
            return false;
        }
        zend_class_entry *interface_ce = getClassEntry(name);
        if (interface_ce == NULL)
        {
            return false;
        }
        interfaces[name] = interface_ce;
        return true;
    }
    bool implements(zend_class_entry *interface_ce)
    {
        if (activated)
        {
            return false;
        }
        interfaces[interface_ce->name->val] = interface_ce;
        return true;
    }
    bool addConstant(const char *name, Variant v)
    {
        if (activated)
        {
            return false;
        }
        Constant c;
        c.name = name;
        ZVAL_COPY(&c.value, v.ptr());
        constants.push_back(c);
        return true;
    }
    bool addProperty(const char *name, Variant v, int flags = PUBLIC)
    {
        if (activated)
        {
            return false;
        }
        Property p;
        p.name = name;
        ZVAL_COPY(&p.value, v.ptr());
        p.flags = flags;
        propertys.push_back(p);
        return true;
    }
    bool addMethod(const char *name, method_t method, int flags = PUBLIC, ArgInfo *info = nullptr)
    {
        if (activated)
        {
            return false;
        }
        if ((flags & CONSTRUCT) || (flags & DESTRUCT) || !(flags & ZEND_ACC_PPP_MASK))
        {
            flags |= PUBLIC;
        }
        Method m;
        m.flags = flags;
        m.method = method;
        m.name = name;
        m.info = info;
        methods.push_back(m);
        return false;
    }
    bool activate()
    {
        if (activated)
        {
            return false;
        }
        /**
         * register methods
         */
        int n = methods.size();
        zend_function_entry *_methods = (zend_function_entry *) ecalloc(n + 1, sizeof(zend_function_entry));
        for (int i = 0; i < n; i++)
        {
            _methods[i].fname = methods[i].name.c_str();
            _methods[i].handler = _exec_method;
            if (methods[i].info)
            {
                _methods[i].arg_info = methods[i].info->get();
                _methods[i].num_args = methods[i].info->count();
            }
            else
            {
                _methods[i].arg_info = nullptr;
                _methods[i].num_args = 0;
            }
            _methods[i].flags = methods[i].flags;
            method_map[class_name][methods[i].name] = methods[i].method;
        }
        memset(&_methods[n], 0, sizeof(zend_function_entry));
        _ce.info.internal.builtin_functions = _methods;
        if (parent_ce)
        {
            ce = zend_register_internal_class_ex(&_ce, parent_ce);
        }
        else
        {
            ce = zend_register_internal_class(&_ce TSRMLS_CC);
        }
        efree(_methods);
        if (ce == NULL)
        {
            return false;
        }
        /**
         * implements interface
         */
        for (auto i = interfaces.begin(); i != interfaces.end(); i++)
        {
            zend_do_implement_interface(ce, interfaces[i->first]);
        }
        /**
         * register property
         */
        for (int i = 0; i != propertys.size(); i++)
        {
            Property p = propertys[i];
            zval_add_ref(&p.value);
            zend_declare_property(ce, p.name.c_str(), p.name.length(), &p.value, p.flags);
        }
        /**
         * register constant
         */
        for (int i = 0; i != constants.size(); i++)
        {
            if (Z_TYPE(constants[i].value) == IS_STRING)
            {
                zend_declare_class_constant_stringl(ce, constants[i].name.c_str(), constants[i].name.length(),
                        Z_STRVAL(constants[i].value), Z_STRLEN(constants[i].value));
            }
            else
            {
                zend_declare_class_constant(ce, constants[i].name.c_str(), constants[i].name.length(),
                        &constants[i].value);
            }
        }
        activated = true;
        return true;
    }
    bool alias(const char *alias_name)
    {
        if (!activated)
        {
            php_error_docref(NULL, E_WARNING, "Please execute alias method after activate.");
            return false;
        }
        if (zend_register_class_alias_ex(alias_name, strlen(alias_name), ce) < 0)
        {
            return false;
        }
        return true;
    }
    string getName()
    {
        return class_name;
    }
    zend_class_entry* ptr()
    {
        return ce;
    }
    Variant getStaticProperty(string p_name)
    {
        if (!activated)
        {
            return nullptr;
        }
        return Variant(zend_read_static_property(ce, p_name.c_str(), p_name.length(), 1));
    }
    bool setStaticProperty(string p_name, Variant value)
    {
        if (!activated)
        {
            return false;
        }
        value.addRef();
        return zend_update_static_property(ce, p_name.c_str(), p_name.length(), value.ptr()) == SUCCESS;
    }
    static Variant get(const char *name, string p_name)
    {
        zend_class_entry *_tmp_ce = getClassEntry(name);
        if (!_tmp_ce)
        {
            return nullptr;
        }
        return Variant(zend_read_static_property(_tmp_ce, p_name.c_str(), p_name.length(), 1));
    }
    static bool set(const char *name, string p_name, Variant value)
    {
        zend_class_entry *_tmp_ce = getClassEntry(name);
        if (!_tmp_ce)
        {
            return false;
        }
        value.addRef();
        return zend_update_static_property(_tmp_ce, p_name.c_str(), p_name.length(), value.ptr()) == SUCCESS;
    }
protected:
    bool activated;
    string class_name;
    string parent_class_name;
    zend_class_entry *parent_ce;
    zend_class_entry _ce;
    zend_class_entry *ce;
    unordered_map<string, zend_class_entry *> interfaces;
    vector<Method> methods;
    vector<Property> propertys;
    vector<Constant> constants;
};

class Interface
{
public:
    Interface(const char *name)
    {
        this->name = name;
        INIT_CLASS_ENTRY_EX(_ce, name, strlen(name), NULL);
        ce = NULL;
    }
    bool addMethod(const char *name, ArgInfo *info)
    {
        if (activated)
        {
            return false;
        }
        Method m;
        m.flags = 0;
        m.method = nullptr;
        m.name = name;
        m.info = info;
        methods.push_back(m);
        return false;
    }
    string getName()
    {
        return name;
    }
    bool activate()
    {
        if (activated)
        {
            return false;
        }
        /**
         * register methods
         */
        int n = methods.size();
        zend_function_entry *_methods = (zend_function_entry *) ecalloc(n + 1, sizeof(zend_function_entry));
        for (int i = 0; i < n; i++)
        {
            _methods[i].fname = methods[i].name.c_str();
            _methods[i].handler = nullptr;
            _methods[i].arg_info = methods[i].info->get();
            _methods[i].num_args = (uint32_t) methods[i].info->count();
            _methods[i].flags = ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT;
        }
        memset(&_methods[n], 0, sizeof(zend_function_entry));
        _ce.info.internal.builtin_functions = _methods;
        ce = zend_register_internal_interface(&_ce TSRMLS_CC);
        efree(_methods);
        if (ce == nullptr)
        {
            return false;
        }
        activated = true;
        return true;
    }
protected:
    bool activated = false;
    string name;
    zend_class_entry _ce;
    zend_class_entry *ce;
    vector<Method> methods;
};

static unordered_map<string, Class*> class_map;
static unordered_map<string, Interface*> interface_map;

int extension_startup(int type, int module_number);
void extension_info(zend_module_entry *module);
int extension_shutdown(int type, int module_number);
int extension_before_request(int type, int module_number);
int extension_after_request(int type, int module_number);

class Extension
{
protected:
    zend_module_entry module =
    {
    STANDARD_MODULE_HEADER_EX,
    NULL,
    NULL,
    NULL,    //name
    NULL, //functions
    extension_startup, //MINIT
    extension_shutdown,  //MSHUTDOWN
    extension_before_request, //RINIT
    extension_after_request, //RSHUTDOWN
    extension_info, //MINFO
    NULL, //version
    STANDARD_MODULE_PROPERTIES,
    };

public:

    enum StartupStatus
    {
        BEFORE_START, AFTER_START,
    };

    Extension(const char*name, const char *version);

    void checkStartupStatus(enum StartupStatus status, const char *func)
    {
        if (status == AFTER_START && !this->started)
        {
            zend_error(E_CORE_ERROR, "php::%s must be called after startup.", func);
        }
        else if (status == BEFORE_START && this->started)
        {
            zend_error(E_CORE_ERROR, "php::%s must be called before startup.", func);
        }
    }

    bool registerClass(Class *c)
    {
        this->checkStartupStatus(AFTER_START, __func__);
        c->activate();
        class_map[c->getName()] = c;
        return true;
    }

    bool registerInterface(Interface *i)
    {
        this->checkStartupStatus(AFTER_START, __func__);
        i->activate();
        interface_map[i->getName()] = i;
        return true;
    }

    bool registerFunction(const char *name, function_t func, ArgInfo *info = nullptr)
    {
        this->checkStartupStatus(BEFORE_START, __func__);
        if (module.functions == NULL)
        {
            module.functions = (const zend_function_entry*) calloc(16, sizeof(zend_function_entry));
            if (module.functions == NULL)
            {
                return false;
            }
            function_array_size = 16;
        }
        else if (function_count + 1 == function_array_size)
        {
            function_array_size *= 2;
            void* new_array = realloc((void*) module.functions, function_array_size * sizeof(zend_function_entry));
            if (new_array == NULL)
            {
                return false;
            }
            module.functions = (const zend_function_entry*) new_array;
        }

        zend_function_entry *function_array = (zend_function_entry *) module.functions;
        function_array[function_count].fname = name;

        function_array[function_count].handler = _exec_function;
        function_array[function_count].arg_info = NULL;
        function_array[function_count].num_args = 0;
        function_array[function_count].flags = 0;

        function_array[function_count + 1].fname = NULL;
        function_array[function_count + 1].handler = NULL;
        if (info)
        {
            function_array[function_count + 1].arg_info = info->get();
            function_array[function_count + 1].num_args = info->count();
        }
        else
        {
            function_array[function_count + 1].arg_info = NULL;
            function_array[function_count + 1].num_args = 0;
        }
        function_array[function_count + 1].flags = 0;

        function_map[name] = func;

        function_count ++;
        return true;
    }

    bool registerResource(const char *name, resource_dtor dtor)
    {
        this->checkStartupStatus(AFTER_START, __func__);
        Resource *res = new Resource;
        int type = zend_register_list_destructors_ex(dtor, NULL, name, 0);
        if (type < 0)
        {
            return false;
        }
        res->type = type;
        res->name = name;
        resource_map[name] = res;
        return true;
    }

    bool registerConstant(const char *name, long v)
    {
        this->checkStartupStatus(AFTER_START, __func__);
        zend_constant c;
        ZVAL_LONG(&c.value, v);
        c.flags = CONST_CS | CONST_PERSISTENT;
        c.name = zend_string_init(name, strlen(name), c.flags);
        c.module_number = module.module_number;
        return zend_register_constant(&c);
    }

    bool registerConstant(const char *name, int v)
    {
        this->checkStartupStatus(AFTER_START, __func__);
        zend_constant c;
        ZVAL_LONG(&c.value, v);
        c.flags = CONST_CS | CONST_PERSISTENT;
        c.name = zend_string_init(name, strlen(name), c.flags);
        c.module_number = module.module_number;
        return zend_register_constant(&c);
    }

    bool registerConstant(const char *name, bool v)
    {
        this->checkStartupStatus(AFTER_START, __func__);
        zend_constant c;
        if (v)
        {
            ZVAL_TRUE(&c.value);
        }
        else
        {
            ZVAL_FALSE(&c.value);
        }
        c.flags = CONST_CS | CONST_PERSISTENT;
        c.name = zend_string_init(name, strlen(name), c.flags);
        c.module_number = module.module_number;
        return zend_register_constant(&c);
    }

    bool registerConstant(const char *name, double v)
    {
        this->checkStartupStatus(AFTER_START, __func__);
        zend_constant c;
        ZVAL_DOUBLE(&c.value, v);
        c.flags = CONST_CS | CONST_PERSISTENT;
        c.name = zend_string_init(name, strlen(name), c.flags);
        c.module_number = module.module_number;
        return zend_register_constant(&c);
    }

    bool registerConstant(const char *name, float v)
    {
        this->checkStartupStatus(AFTER_START, __func__);
        zend_constant c;
        ZVAL_DOUBLE(&c.value, v);
        c.flags = CONST_CS | CONST_PERSISTENT;
        c.name = zend_string_init(name, strlen(name), c.flags);
        c.module_number = module.module_number;
        return zend_register_constant(&c);
    }

    bool registerConstant(const char *name, const char *v)
    {
        this->checkStartupStatus(AFTER_START, __func__);
        zend_constant c;
        ZVAL_STRING(&c.value, (char* )v);
        c.flags = CONST_CS | CONST_PERSISTENT;
        c.name = zend_string_init(name, strlen(name), c.flags);
        c.module_number = module.module_number;
        return zend_register_constant(&c);
    }

    bool registerConstant(const char *name, string &v)
    {
        this->checkStartupStatus(AFTER_START, __func__);
        zend_constant c;
        ZVAL_STRINGL(&c.value, (char * )v.c_str(), v.length());
        c.flags = CONST_CS | CONST_PERSISTENT;
        c.name = zend_string_init(name, strlen(name), c.flags);
        c.module_number = module.module_number;
        return zend_register_constant(&c);
    }

    bool registerConstant(const char *name, Variant &v)
    {
        this->checkStartupStatus(AFTER_START, __func__);
        zend_constant c;
        ZVAL_COPY(&c.value, v.ptr());
        c.flags = CONST_CS;
        c.name = zend_string_init(name, strlen(name), c.flags);
        c.module_number = module.module_number;
        return zend_register_constant(&c);
    }

    bool require(const char *name, const char *version = nullptr)
    {
        this->checkStartupStatus(BEFORE_START, __func__);
        if (module.deps == NULL)
        {
            module.deps = (const zend_module_dep*) calloc(16, sizeof(zend_module_dep));
            if (module.deps == NULL)
            {
                return false;
            }
            deps_array_size = 16;
        }
        else if (deps_count + 1 == deps_array_size)
        {
            deps_array_size *= 2;
            void* new_array = realloc((void*) module.deps, deps_array_size * sizeof(zend_module_dep));
            if (new_array == NULL)
            {
                return false;
            }
            module.deps = (const zend_module_dep*) new_array;
        }

        zend_module_dep *deps_array = (zend_module_dep *) module.deps;
        deps_array[deps_count].name = name;
        deps_array[deps_count].rel = NULL;
        deps_array[deps_count].version = version;
        deps_array[deps_count].type = MODULE_DEP_REQUIRED;

        deps_array[deps_count + 1].name = NULL;
        deps_array[deps_count + 1].rel = NULL;
        deps_array[deps_count + 1].version = NULL;
        deps_array[deps_count + 1].type = 0;

        deps_count++;
        return true;
    }

    void info(vector<string> header, vector<vector<string> > body)
    {
        this->header = header;
        this->body = body;
    }

    string name;
    string version;
    bool started = false;

    std::function<void(void)> onStart = nullptr;
    std::function<void(void)> onShutdown = nullptr;
    std::function<void(void)> onBeforeRequest = nullptr;
    std::function<void(void)> onAfterRequest = nullptr;

    vector<string> header;
    vector<vector<string> > body;

protected:
    int function_count = 0;
    int function_array_size = 0;
    int deps_count = 0;
    int deps_array_size = 0;
};

static unordered_map<string, Extension*> _name_to_extension;
static unordered_map<int, Extension*> _module_number_to_extension;

Extension::Extension(const char *name, const char *version)
{
    module.name = name;
    module.version = version;
    this->name = name;
    this->version = version;
    _name_to_extension[name] = this;
}

int extension_startup(int type, int module_number)
{
    zend_module_entry *module;
    void *ptr;
    ZEND_HASH_FOREACH_PTR(&module_registry, ptr)
    {
        module = (zend_module_entry *) ptr;
        if (module_number == module->module_number)
        {
            Extension *extension = _name_to_extension[module->name];
            extension->started = true;
            if (extension->onStart)
            {
                extension->onStart();
            }
            _module_number_to_extension[module_number] = extension;
            break;
        }
    }
    ZEND_HASH_FOREACH_END();
    return SUCCESS;
}

void extension_info(zend_module_entry *module)
{
    Extension *extension = _module_number_to_extension[module->module_number];
    if (extension->header.size() > 0 && extension->body.size() > 0)
    {
        php_info_print_table_start();
        auto header = extension->header;
        size_t size = header.size();
        switch (size)
        {
        case 2:
            php_info_print_table_header(size, header[0].c_str(), header[1].c_str());
            break;
        case 3:
            php_info_print_table_header(size, header[0].c_str(), header[1].c_str(), header[2].c_str());
            break;
        default:
            error(E_WARNING, "invalid info header size.");
            return;
        }
        for (auto row : extension->body)
        {
            size = row.size();
            switch (size)
            {
            case 2:
                php_info_print_table_row(size, row[0].c_str(), row[1].c_str());
                break;
            case 3:
                php_info_print_table_row(size, row[0].c_str(), row[1].c_str(), row[2].c_str());
                break;
            default:
                error(E_WARNING, "invalid info row size.");
                return;
            }
        }
        php_info_print_table_end();
    }
}

int extension_shutdown(int type, int module_number)
{
    Extension *extension = _module_number_to_extension[module_number];
    if (extension->onShutdown)
    {
        extension->onShutdown();
    }
    _name_to_extension.erase(extension->name);
    _module_number_to_extension.erase(module_number);
    delete extension;

    return SUCCESS;
}

int extension_before_request(int type, int module_number)
{
    Extension *extension = _module_number_to_extension[module_number];
    if (extension->onBeforeRequest)
    {
        extension->onBeforeRequest();
    }

    return SUCCESS;
}

int extension_after_request(int type, int module_number)
{
    Extension *extension = _module_number_to_extension[module_number];
    if (extension->onAfterRequest)
    {
        extension->onAfterRequest();
    }

    return SUCCESS;
}

template<typename T>
Variant newResource(const char *name, T *v)
{
    Resource *_c = resource_map[name];
    if (!_c)
    {
        error(E_WARNING, "%s type of resource is undefined.", name);
        return nullptr;
    }
    zend_resource *res = zend_register_resource(static_cast<void*>(v), _c->type);
    return Variant(res);
}

Object newObject(const char *name)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        php_error_docref(NULL, E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    zval zobject;
    if (object_init_ex(&zobject, ce) == FAILURE)
    {
        return object;
    }
    object = Object(&zobject);
    Array args;
    object.addRef();
    object.call("__construct", args);
    return object;
}

/*generator*/
Object newObject(const char *name, Variant v1)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    zval zobject;
    if (object_init_ex(&zobject, ce) == FAILURE)
    {
        return object;
    }
    object = Object(&zobject);
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    object.addRef();
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name, Variant v1, Variant v2)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    zval zobject;
    if (object_init_ex(&zobject, ce) == FAILURE)
    {
        return object;
    }
    object = Object(&zobject);
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    object.addRef();
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name, Variant v1, Variant v2, Variant v3)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    zval zobject;
    if (object_init_ex(&zobject, ce) == FAILURE)
    {
        return object;
    }
    object = Object(&zobject);
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    object.addRef();
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name, Variant v1, Variant v2, Variant v3, Variant v4)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    zval zobject;
    if (object_init_ex(&zobject, ce) == FAILURE)
    {
        return object;
    }
    object = Object(&zobject);
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    v4.addRef();
    args.append(v4.ptr());
    object.addRef();
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    zval zobject;
    if (object_init_ex(&zobject, ce) == FAILURE)
    {
        return object;
    }
    object = Object(&zobject);
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    v4.addRef();
    args.append(v4.ptr());
    v5.addRef();
    args.append(v5.ptr());
    object.addRef();
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    zval zobject;
    if (object_init_ex(&zobject, ce) == FAILURE)
    {
        return object;
    }
    object = Object(&zobject);
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    v4.addRef();
    args.append(v4.ptr());
    v5.addRef();
    args.append(v5.ptr());
    v6.addRef();
    args.append(v6.ptr());
    object.addRef();
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    zval zobject;
    if (object_init_ex(&zobject, ce) == FAILURE)
    {
        return object;
    }
    object = Object(&zobject);
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    v4.addRef();
    args.append(v4.ptr());
    v5.addRef();
    args.append(v5.ptr());
    v6.addRef();
    args.append(v6.ptr());
    v7.addRef();
    args.append(v7.ptr());
    object.addRef();
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7, Variant v8)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    zval zobject;
    if (object_init_ex(&zobject, ce) == FAILURE)
    {
        return object;
    }
    object = Object(&zobject);
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    v4.addRef();
    args.append(v4.ptr());
    v5.addRef();
    args.append(v5.ptr());
    v6.addRef();
    args.append(v6.ptr());
    v7.addRef();
    args.append(v7.ptr());
    v8.addRef();
    args.append(v8.ptr());
    object.addRef();
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7, Variant v8, Variant v9)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    zval zobject;
    if (object_init_ex(&zobject, ce) == FAILURE)
    {
        return object;
    }
    object = Object(&zobject);
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    v4.addRef();
    args.append(v4.ptr());
    v5.addRef();
    args.append(v5.ptr());
    v6.addRef();
    args.append(v6.ptr());
    v7.addRef();
    args.append(v7.ptr());
    v8.addRef();
    args.append(v8.ptr());
    v9.addRef();
    args.append(v9.ptr());
    object.addRef();
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7, Variant v8, Variant v9, Variant v10)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    zval zobject;
    if (object_init_ex(&zobject, ce) == FAILURE)
    {
        return object;
    }
    object = Object(&zobject);
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    v4.addRef();
    args.append(v4.ptr());
    v5.addRef();
    args.append(v5.ptr());
    v6.addRef();
    args.append(v6.ptr());
    v7.addRef();
    args.append(v7.ptr());
    v8.addRef();
    args.append(v8.ptr());
    v9.addRef();
    args.append(v9.ptr());
    v10.addRef();
    args.append(v10.ptr());
    object.addRef();
    object.call("__construct", args);
    return object;
}
/*generator*/

//namespace end
}
