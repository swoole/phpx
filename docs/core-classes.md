# 核心类详解

本文档详细介绍 PHPX 的核心类及其内部实现。

## 目录

- [Variant](#variant) - 通用变量类型
- [Array](#array) - 数组封装
- [Object](#object) - 对象封装
- [String](#string) - 字符串封装
- [Reference](#reference) - 引用封装
- [Resource](#resource) - 资源封装
- [Closure](#closure) - 闭包封装
- [Box](#box) - 容器封装

---

## Variant

`Variant` 是 PHPX 中最核心的类，可以存储任何 PHP 值（null、bool、int、float、string、array、object、resource）。

### 内部结构

```cpp
class Variant {
protected:
    zval val;  // Zend 引擎的 zval 结构
    
public:
    // 构造函数
    Variant();
    Variant(zval *v, Ctor ctor);
    Variant(const Variant &v);
    
    // 析构函数
    ~Variant();
    
    // ... 其他方法
};
```

### 构造与析构

#### 默认构造
```cpp
Variant::Variant() {
    ZVAL_UNDEF(&val);
}
```

#### 从 zval 构造
```cpp
Variant::Variant(zval *v, Ctor ctor) {
    if (ctor == Ctor::Copy) {
        ZVAL_COPY(&val, v);
    } else if (ctor == Ctor::Move) {
        val = *v;
        ZVAL_NULL(v);
    } else if (ctor == Ctor::Indirect) {
        ZVAL_INDIRECT(&val, v);
    }
}
```

#### 析构函数
```cpp
Variant::~Variant() {
    destroy();
}

void Variant::destroy() {
    if (isIndirect()) {
        zval_ptr_dtor(Z_INDIRECT(val));
        *Z_INDIRECT(val) = {};
    } else {
        zval_ptr_dtor(&val);
    }
    val = {};
}
```

### 内存管理

#### 引用计数
```cpp
int Variant::getRefCount() const {
    auto zv = const_ptr();
    ZVAL_DEINDIRECT(zv);
    if (Z_REFCOUNTED_P(zv)) {
        return Z_REFCOUNT_P(zv);
    }
    return 0;
}

void Variant::addRef() {
    zval *zv = unwrap_ptr();
    if (Z_REFCOUNTED_P(zv)) {
        Z_TRY_ADDREF_P(zv);
    }
}
```

#### 写时复制（Copy-on-Write）
```cpp
void Variant::copyFrom(const zval *src) {
    zval *zv = unwrap_ptr();
    if (UNEXPECTED(zval_is_string(zv) && isStrOffsetSet(zv) && zval_is_string(src))) {
        strOffsetSet(zv, Z_STRVAL_P(src)[0]);
    } else {
        zval tmp = *zv;
        ZVAL_COPY(zv, src);
        zval_ptr_dtor(&tmp);
    }
}
```

### 类型转换实现

#### 转换为整数
```cpp
Int Variant::toInt() const {
    zval *zv = const_cast<zval *>(unwrap_ptr());
    if (Z_TYPE_P(zv) == IS_STRING) {
        // 字符串转整数
        zend_long result;
        if (zend_strtod_long(Z_STRVAL_P(zv), Z_STRLEN_P(zv), &result)) {
            return result;
        }
        return 0;
    }
    return zval_get_long(zv);
}
```

#### 转换为字符串
```cpp
String Variant::toString() const {
    zend_string *str = zval_get_string(NO_CONST_Z(unwrap_ptr()));
    return String(str, Ctor::Move);
}
```

#### 转换为布尔值
```cpp
Bool Variant::toBool() const {
    auto zv = unwrap_ptr();
    switch (Z_TYPE_P(zv)) {
    case IS_FALSE:
        return false;
    case IS_TRUE:
        return true;
    case IS_LONG:
        return Z_LVAL_P(zv) != 0;
    case IS_DOUBLE:
        return !zend_isnan(Z_DVAL_P(zv)) && Z_DVAL_P(zv) != 0.0;
    case IS_STRING:
        return Z_STRLEN_P(zv) > 0 && 
               (Z_STRLEN_P(zv) > 1 || Z_STRVAL_P(zv)[0] != '0');
    case IS_ARRAY:
        return zend_hash_num_elements(Z_ARRVAL_P(zv)) > 0;
    case IS_OBJECT:
        return true;
    default:
        return false;
    }
}
```

### 操作符实现

#### 赋值操作符
```cpp
Variant &Variant::operator=(const Variant &v) {
    if (&v != this) {
        copyFrom(v.unwrap_ptr());
    }
    return *this;
}

Variant &Variant::operator=(const zval *v) {
    copyFrom(unwrap_zval(v));
    return *this;
}
```

#### 算术操作符
```cpp
Variant Variant::operator+(const Variant &other) const {
    zval result;
    fast_add_function(&result, 
                      const_cast<zval *>(&val), 
                      const_cast<zval *>(&other.val));
    return Variant(&result, Ctor::Copy);
}
```

#### 比较操作符
```cpp
bool Variant::operator==(const Variant &other) const {
    return equals(other);
}

bool Variant::equals(const Variant &other) const {
    zval *zv1 = const_cast<zval *>(unwrap_ptr());
    zval *zv2 = const_cast<zval *>(other.unwrap_ptr());
    
    if (strict) {
        return zend_is_identical(zv1, zv2);
    } else {
        return zend_is_equal(zv1, zv2);
    }
}
```

### 调试功能

```cpp
void Variant::debug() {
    printf("zval=%p, type=%d, refcount=%d, is_ref=%d\n", 
           const_ptr(), type(), getRefCount(), isReference());
    
    const zval *_val;
    if (isReference()) {
        _val = Z_REFVAL_P(const_ptr());
        printf("ref=%p, rc=%d\n", Z_REF_P(const_ptr()), Z_REFCOUNT_P(const_ptr()));
    } else {
        _val = const_ptr();
    }
    
    if (Z_TYPE_P(_val) == IS_NULL) {
        printf("value=null\n");
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
        printf("object[rc=%d]=%p, class=%s\n", 
               Z_REFCOUNT_P(_val), 
               Z_OBJ_P(_val), 
               ZSTR_VAL(Z_OBJCE_P(_val)->name));
    }
}
```

---

## Array

`Array` 类封装了 PHP 的数组功能，提供面向对象的接口。

### 内部结构

```cpp
class Array {
protected:
    zval val;
    
public:
    // 构造和析构
    Array();
    Array(size_t size);
    Array(const Variant &value);
    ~Array();
    
    // ... 其他方法
};
```

### 构造实现

#### 默认构造
```cpp
Array::Array() {
    array_init(&val);
}
```

#### 指定大小构造
```cpp
Array::Array(size_t size) {
    array_init_size(&val, size);
}
```

#### 从 Variant 构造
```cpp
Array::Array(const Variant &value) {
    if (value.isArray()) {
        ZVAL_COPY(&val, value.ptr());
    } else {
        array_init(&val);
    }
}
```

### 元素访问实现

#### offsetGet
```cpp
Variant Array::offsetGet(const Variant &offset) {
    zval *value;
    zval *zv = const_cast<zval *>(&val);
    
    if (offset.isInt()) {
        value = zend_hash_index_find(Z_ARRVAL_P(zv), offset.toInt());
    } else {
        String key = offset.toString();
        value = zend_hash_find(Z_ARRVAL_P(zv), key.str());
    }
    
    if (!value) {
        return {};
    }
    
    return Variant(value, Ctor::Indirect);
}
```

#### offsetSet
```cpp
void Array::offsetSet(const Variant &offset, const Variant &value) {
    zval *zv = const_cast<zval *>(&val);
    
    if (offset.isNull()) {
        // 追加到数组末尾
        zend_hash_next_index_insert(Z_ARRVAL_P(zv), value.ptr());
    } else if (offset.isInt()) {
        zend_hash_index_update(Z_ARRVAL_P(zv), offset.toInt(), value.ptr());
    } else {
        String key = offset.toString();
        zend_symbool_update(Z_ARRVAL_P(zv), key.str(), value.ptr());
    }
}
```

#### offsetExists
```cpp
bool Array::offsetExists(const Variant &offset) {
    zval *zv = const_cast<zval *>(&val);
    
    if (offset.isInt()) {
        return zend_hash_index_exists(Z_ARRVAL_P(zv), offset.toInt());
    } else {
        String key = offset.toString();
        return zend_symbool_exists(Z_ARRVAL_P(zv), key.str());
    }
}
```

### 数组操作实现

#### merge
```cpp
Array Array::merge(const Array &other) const {
    Array result;
    zend_array *arr = Z_ARRVAL(result.val);
    
    // 合并第一个数组
    zend_hash_merge(arr, Z_ARRVAL(val), zval_add_ref, true);
    
    // 合并第二个数组
    zend_hash_merge(arr, Z_ARRVAL(other.val), zval_add_ref, true);
    
    return result;
}
```

#### slice
```cpp
Array Array::slice(long offset, long length) const {
    Array result;
    
    zend_array *input = Z_ARRVAL(val);
    zend_array *output = Z_ARRVAL(result.val);
    
    // 计算实际偏移
    if (offset < 0) {
        offset = zend_hash_num_elements(input) + offset;
    }
    
    // 计算实际长度
    if (length <= 0) {
        length = zend_hash_num_elements(input) - offset;
    }
    
    // 复制元素
    Bucket *p;
    long i = 0;
    ZEND_HASH_FOREACH_BUCKET(input, p) {
        if (i >= offset && i < offset + length) {
            zval_add_ref(&p->val);
            if (p->key) {
                zend_hash_add_new(output, p->key, &p->val);
            } else {
                zend_hash_index_add_new(output, p->h, &p->val);
            }
        }
        i++;
    } ZEND_HASH_FOREACH_END();
    
    return result;
}
```

### 遍历实现

```cpp
void Array::foreach(std::function<void(Variant&, Variant&)> func) {
    zend_array *arr = Z_ARRVAL(val);
    Bucket *p;
    
    ZEND_HASH_FOREACH_BUCKET(arr, p) {
        Variant key, value;
        
        if (p->key) {
            key = Variant(p->key, Ctor::Indirect);
        } else {
            key = Variant((Int)p->h);
        }
        
        value = Variant(&p->val, Ctor::Indirect);
        
        func(key, value);
    } ZEND_HASH_FOREACH_END();
}
```

---

## Object

`Object` 类封装了 PHP 的对象操作。

### 内部结构

```cpp
class Object {
protected:
    zval val;
    
public:
    // 构造和析构
    Object();
    Object(zend_object *obj, Ctor ctor);
    ~Object();
    
    // ... 其他方法
};
```

### 对象创建实现

```cpp
Object Object::newObject(const String &className, Args args) {
    Object result;
    
    zend_class_entry *ce = getClassEntry(className);
    if (!ce) {
        throwError("Class %s does not exist", className.data());
        return result;
    }
    
    // 创建对象实例
    if (args.size() == 0) {
        object_init_ex(&result.val, ce);
    } else {
        // 调用构造函数
        zend_object *obj = zend_objects_new(ce);
        ZVAL_OBJ(&result.val, obj);
        
        // 调用 __construct
        zend_function *constructor = zend_std_get_constructor(ce, &result.val, nullptr);
        if (constructor) {
            call(ce, constructor, args);
        }
    }
    
    return result;
}
```

### 属性访问实现

#### getProperty
```cpp
Variant Object::getProperty(const String &name) {
    zval *zv = const_cast<zval *>(&val);
    zend_string *prop_name = name.str();
    
    zval rv;
    zval *value = read_property(
        Z_OBJ_P(zv), 
        prop_name, 
        BP_VAR_R, 
        nullptr, 
        &rv
    );
    
    if (!value) {
        return {};
    }
    
    return Variant(value, Ctor::Indirect);
}
```

#### setProperty
```cpp
void Object::setProperty(const String &name, const Variant &value) {
    zval *zv = const_cast<zval *>(&val);
    zend_string *prop_name = name.str();
    
    write_property(
        Z_OBJ_P(zv), 
        prop_name, 
        value.ptr(), 
        nullptr
    );
}
```

### 方法调用实现

```cpp
Variant Object::call(const String &method, Args args) {
    zval *zv = const_cast<zval *>(&val);
    zend_string *method_name = method.str();
    
    // 查找方法
    zend_function *func = zend_fetch_method(
        Z_OBJCE_P(zv), 
        method_name, 
        nullptr
    );
    
    if (!func) {
        throwError("Method %s does not exist", method.data());
        return {};
    }
    
    // 调用方法
    return call(Z_OBJCE_P(zv), func, args);
}
```

### 静态属性操作

```cpp
Variant Object::getStaticProperty(const String &className, const String &prop) {
    zend_class_entry *ce = getClassEntry(className);
    if (!ce) {
        return {};
    }
    
    zend_string *prop_name = prop.str();
    zval *property = zend_read_static_property(ce, prop_name, 1);
    
    if (!property) {
        return {};
    }
    
    return Variant(property, Ctor::Indirect);
}

bool Object::setStaticProperty(const String &className, const String &prop, const Variant &value) {
    zend_class_entry *ce = getClassEntry(className);
    if (!ce) {
        return false;
    }
    
    zend_string *prop_name = prop.str();
    return zend_update_static_property(ce, prop_name, value.ptr()) == SUCCESS;
}
```

---

## String

`String` 类封装了 PHP 的字符串处理。

### 内部结构

```cpp
class String {
protected:
    zend_string *str;
    
public:
    // 构造和析构
    String();
    String(const char *s);
    String(zend_string *s, Ctor ctor);
    ~String();
    
    // ... 其他方法
};
```

### 构造实现

```cpp
String::String(const char *s) {
    str = zend_string_init(s, strlen(s), 0);
}

String::String(zend_string *s, Ctor ctor) {
    if (ctor == Ctor::Copy) {
        str = zend_string_copy(s);
    } else if (ctor == Ctor::Move) {
        str = s;
    }
}

String::~String() {
    if (str) {
        zend_string_release(str);
    }
}
```

### 字符串操作实现

#### concat
```cpp
String String::concat(const String &other) const {
    zend_string *result = zend_string_concat(str, other.str);
    return String(result, Ctor::Move);
}

// 操作符重载
String String::operator+(const String &other) const {
    return concat(other);
}
```

#### substr
```cpp
String String::substr(size_t start, size_t length) const {
    if (start >= ZSTR_LEN(str)) {
        return String();
    }
    
    if (length == -1 || start + length > ZSTR_LEN(str)) {
        length = ZSTR_LEN(str) - start;
    }
    
    zend_string *result = zend_string_init(
        ZSTR_VAL(str) + start, 
        length, 
        0
    );
    
    return String(result, Ctor::Move);
}
```

#### strtoupper
```cpp
String String::strtoupper() const {
    zend_string *result = zend_string_init(
        ZSTR_VAL(str), 
        ZSTR_LEN(str), 
        0
    );
    
    php_strtoupper(ZSTR_VAL(result), ZSTR_LEN(result));
    
    return String(result, Ctor::Move);
}
```

---

## Reference

`Reference` 类封装了 PHP 的引用机制。

### 内部结构

```cpp
class Reference {
protected:
    zval *ref;
    
public:
    Reference(const Variant &value);
    Reference(zval *value);
    
    // ... 其他方法
};
```

### 构造实现

```cpp
Reference::Reference(const Variant &value) {
    Variant tmp{value};
    ZVAL_NEW_REF(&val, tmp.ptr());
    ref = &val;
}

Reference::Reference(zval *value) {
    if (Z_TYPE_P(value) != IS_REFERENCE) {
        ZVAL_NEW_REF(&val, value);
    } else {
        val = *value;
    }
    ref = &val;
}
```

### 引用操作

```cpp
Variant Reference::getValue() const {
    return Variant(Z_REFVAL_P(ref), Ctor::Indirect);
}

void Reference::setValue(const Variant &value) {
    zval_ptr_dtor(Z_REFVAL_P(ref));
    ZVAL_COPY(Z_REFVAL_P(ref), value.ptr());
}
```

---

## Resource

`Resource` 类封装了 PHP 的资源类型。

### 内部结构

```cpp
class Resource {
protected:
    zval val;
    int type;
    
public:
    Resource(int type);
    void *getData() const;
    void setData(void *data);
    
    // ... 其他方法
};
```

### 资源注册

```cpp
bool Extension::registerResource(const char *name, resource_dtor dtor) const {
    auto *res = new Resource;
    int type = zend_register_list_destructors_ex(dtor, nullptr, name, 0);
    if (type < 0) {
        return false;
    }
    res->type = type;
    res->name = name;
    resource_map[name] = res;
    return true;
}
```

### 资源获取

```cpp
Resource *getResource(const std::string &name) {
    auto it = resource_map.find(name);
    if (it == resource_map.end()) {
        return nullptr;
    }
    return it->second;
}
```

---

## Box

`Box` 是一个容器类，用于在请求间共享数据。

### 内部结构

```cpp
class Box {
protected:
    Array data;
    zend_resource *res;
    
public:
    Box();
    ~Box();
    
    void set(const String &key, const Variant &value);
    Variant get(const String &key);
    bool has(const String &key);
    void destroy();
    
    // ... 其他方法
};
```

### 资源管理

```cpp
static void box_dtor(zend_resource *res) {
    auto box = static_cast<Box *>(res->ptr);
    box->destroy();
}

THREAD_LOCAL int box_res_id;

void request_init() {
    box_res_id = zend_register_list_destructors_ex(
        box_dtor, 
        nullptr, 
        box_res_name, 
        0
    );
}
```

### Box 操作

```cpp
Box::Box() {
    res = zend_register_resource(this, box_res_id);
}

void Box::set(const String &key, const Variant &value) {
    data.offsetSet(key, value);
}

Variant Box::get(const String &key) {
    return data.offsetGet(key);
}

void Box::destroy() {
    data.unset();
}
```

---

## 性能优化技术

### 1. 字符串缓存

```cpp
// literal_string.cc 实现了字符串字面量缓存
static std::unordered_map<std::string, zend_string*> cached_strings;

zend_string* get_cached_string(const std::string &key) {
    auto it = cached_strings.find(key);
    if (it != cached_strings.end()) {
        return it->second;
    }
    
    zend_string *str = zend_string_init(key.c_str(), key.length(), 1);
    cached_strings[key] = str;
    return str;
}
```

### 2. 函数缓存

```cpp
static zend_function* cache_function(const char *name) {
    static std::unordered_map<std::string, zend_function*> func_cache;
    
    auto it = func_cache.find(name);
    if (it != func_cache.end()) {
        return it->second;
    }
    
    zend_function *func = find_function(name);
    func_cache[name] = func;
    return func;
}
```

### 3. 类入口缓存

```cpp
static zend_class_entry* cache_class_entry(const char *name) {
    static std::unordered_map<std::string, zend_class_entry*> ce_cache;
    
    auto it = ce_cache.find(name);
    if (it != ce_cache.end()) {
        return it->second;
    }
    
    zend_class_entry *ce = getClassEntry(name);
    ce_cache[name] = ce;
    return ce;
}
```

---

*本文档最后更新：2026-03-27*
