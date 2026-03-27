# 架构设计

本文档详细介绍 PHPX 的系统架构和设计原理。

## 整体架构

```
┌─────────────────────────────────────────────────────────┐
│                    PHP Extension                        │
├─────────────────────────────────────────────────────────┤
│                     PHPX Layer                          │
│  ┌──────────────┬──────────────┬──────────────────────┐ │
│  │   Class      │    Func      │      Constant        │ │
│  │   Layer      │    Layer     │       Layer          │ │
│  └──────────────┴──────────────┴──────────────────────┘ │
├─────────────────────────────────────────────────────────┤
│                      Core Layer                         │
│  ┌──────────┬──────────┬──────────┬──────────────────┐  │
│  │ Variant  │  Array   │  Object  │     String       │  │
│  │ Resource │  Closure │  Box     │     Helper       │  │
│  └──────────┴──────────┴──────────┴──────────────────┘  │
├─────────────────────────────────────────────────────────┤
│                    Zend Engine API                      │
└─────────────────────────────────────────────────────────┘
```

## 核心层（Core Layer）

核心层是 PHPX 的基础，提供了所有数据类型的封装。

### Variant 类型系统

`Variant` 是 PHPX 中最核心的类，它可以表示任何 PHP 值。

#### 数据结构
```cpp
class Variant {
private:
    zval val;  // Zend 引擎的 zval 结构

public:
    // 构造函数
    Variant();                    // 空值
    Variant(zval *v, Ctor);       // 从 zval 构造
    Variant(const Variant &v);    // 拷贝构造

    // 类型转换
    Int toInt() const;
    Double toFloat() const;
    String toString() const;
    Array toArray() const;
    Object toObject() const;
    Bool toBool() const;

    // 类型判断
    bool isNull() const;
    bool isBool() const;
    bool isInt() const;
    bool isFloat() const;
    bool isString() const;
    bool isArray() const;
    bool isObject() const;
    bool isResource() const;
    bool isReference() const;
    bool isIndirect() const;

    // 操作符重载
    Variant &operator=(const Variant &v);
    Variant &operator=(const zval *v);
    // ...
};
```

#### 内存管理
PHPX 使用 RAII（Resource Acquisition Is Initialization）模式自动管理内存：

```cpp
// Variant 析构时自动减少引用计数
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

#### 引用处理
```cpp
// 创建引用
Reference ref = var.toReference();

// 检查是否为引用
if (var.isReference()) {
    // 处理引用
}
```

### Array 类

封装 PHP 数组操作：

```cpp
class Array {
    // 创建
    Array();
    Array(size_t size);

    // 访问元素
    Variant offsetGet(const Variant &offset);
    void offsetSet(const Variant &offset, const Variant &value);
    bool offsetExists(const Variant &offset);
    void offsetUnset(const Variant &offset);

    // 遍历
    void foreach(std::function<void(Variant&, Variant&)> func);

    // 数组操作
    size_t count() const;
    Array merge(const Array &other);
    Variant pop();
    void push(const Variant &value);
    // ...
};
```

### Object 类

封装 PHP 对象操作：

```cpp
class Object {
    // 创建对象
    static Object newObject(const String &className, Args args = {});

    // 属性访问
    Variant getProperty(const String &name);
    void setProperty(const String &name, const Variant &value);
    bool hasProperty(const String &name);

    // 方法调用
    Variant call(const String &method, Args args = {});
    Variant callStatic(const String &method, Args args = {});

    // 类信息
    String getClassName() const;
    zend_class_entry *getClassEntry() const;
    bool instanceOf(const String &className) const;
    // ...
};
```

### String 类

字符串处理：

```cpp
class String {
    // 构造
    String();
    String(const char *s);
    String(const std::string &s);

    // 操作
    size_t length() const;
    const char *data() const;
    std::string toStdString() const;

    String concat(const String &other);
    String substr(size_t start, size_t length = -1);
    Int toInt() const;
    Double toFloat() const;
    // ...
};
```

## 函数层（Function Layer）

函数层封装了 PHP 的所有内置函数。

### 函数注册机制

```cpp
// 函数定义宏
#define PHPX_FUNCTION(name) \
    void name(INTERNAL_FUNCTION_PARAMETERS, Args &args)

// 示例
PHPX_FUNCTION(strtoupper) {
    String str = args[0].toString();
    // ... 实现
    return result;
}

// 注册到扩展
ext.registerFunction("strtoupper", strtoupper);
```

### 参数处理

```cpp
PHPX_FUNCTION(example) {
    // 获取参数
    Variant param1 = args[0];
    Variant param2 = args[1];

    // 可选参数
    if (args.size() > 2) {
        Variant param3 = args[2];
    }

    // 参数类型检查
    if (!args[0].isString()) {
        throwError("Parameter 1 must be string");
        return;
    }

    // 返回结果
    return result;
}
```

### 函数分类

#### 1. 标准函数（standard.cc - 61.7KB）
- 字符串处理：`strlen`, `strpos`, `substr` 等
- 数组操作：`array_push`, `array_pop`, `array_merge` 等
- 数学函数：`abs`, `round`, `rand` 等
- 变量处理：`isset`, `empty`, `unset` 等

#### 2. 多字节字符串（mbstring.cc - 10.6KB）
- `mb_strlen`, `mb_substr`, `mb_strpos`
- 编码转换：`mb_convert_encoding`
- 字符检测：`mb_detect_encoding`

#### 3. 图形处理（gd.cc - 18.9KB）
- 图像创建：`imagecreate`, `imagecreatetruecolor`
- 绘图函数：`imageline`, `imagerectangle`
- 图像处理：`imagecopy`, `imagerotate`

#### 4. 加密哈希（openssl.cc - 16.0KB）
- `openssl_encrypt`, `openssl_decrypt`
- `openssl_sign`, `openssl_verify`
- 证书处理

## 类层（Class Layer）

类层封装了 PHP 的内置类。

### Redis 类封装（redis.cc - 71KB）

```cpp
// 连接
$redis->connect('127.0.0.1', 6379);

// 字符串操作
$redis->set('key', 'value');
$value = $redis->get('key');

// 哈希操作
$redis->hSet('hash', 'field', 'value');
$value = $redis->hGet('hash', 'field');

// 列表操作
$redis->lPush('list', 'item');
$item = $redis->lPop('list');

// 集合操作
$redis->sAdd('set', 'member');
$members = $redis->sMembers('set');

// 有序集合
$redis->zAdd('zset', 1, 'member');
$members = $redis->zRange('zset', 0, -1);
```

### SPL 类封装（spl.cc - 88.7KB）

```cpp
// ArrayIterator
$arr = new ArrayIterator([1, 2, 3]);

// SplQueue
$queue = new SplQueue();
$queue->enqueue('item');
$item = $queue->dequeue();

// SplStack
$stack = new SplStack();
$stack->push('item');
$item = $stack->pop();

// SplFixedArray
$fixed = new SplFixedArray(5);
```

### DOM 类封装（dom.cc - 130.7KB）

```cpp
// 创建文档
$doc = new DOMDocument();

// 加载 XML
$doc->loadXML('<root><child/></root>');

// 遍历节点
$xpath = new DOMXPath($doc);
$nodes = $xpath->query('//child');

// 修改文档
$element = $doc->createElement('new');
$doc->documentElement->appendChild($element);
```

### DateTime 类封装（date.cc - 19.4KB）

```cpp
// 创建日期对象
$date = new DateTime('2026-03-27 10:30:00');

// 格式化输出
echo $date->format('Y-m-d H:i:s');

// 日期计算
$date->modify('+1 day');
$date->add(new DateInterval('P1M'));

// 时区处理
$date->setTimezone(new DateTimeZone('Asia/Shanghai'));
```

## 常量层（Constant Layer）

定义 PHP 扩展的各种常量。

### CURL 常量（curl.cc - 23.4KB）
```cpp
// 选项常量
CURLOPT_URL
CURLOPT_RETURNTRANSFER
CURLOPT_TIMEOUT
CURLOPT_POST

// 信息常量
CURLINFO_HTTP_CODE
CURLINFO_TOTAL_TIME
```

### Socket 常量（sockets.cc - 2.9KB）
```cpp
// 地址族
AF_INET
AF_INET6
AF_UNIX

// Socket 类型
SOCK_STREAM
SOCK_DGRAM
SOCK_RAW

// Socket 选项
SO_REUSEADDR
SO_KEEPALIVE
SO_BROADCAST
```

## 扩展管理机制

### Extension 类

```cpp
class Extension {
private:
    zend_module_entry module;
    std::string name;
    std::string version;
    bool started;

public:
    Extension(const char *name, const char *version);

    // 注册函数
    bool registerFunctions(const zend_function_entry *functions);

    // 注册类
    bool registerClass(Class *c);
    bool registerInterface(Interface *i);

    // 注册资源
    bool registerResource(const char *name, resource_dtor dtor);

    // 注册常量
    void registerConstant(const char *name, long v);
    void registerConstant(const char *name, const char *v);
    void registerConstant(const char *name, bool v);
    void registerConstant(const char *name, double v);

    // 依赖管理
    void require(const char *name, const char *version);

    // INI 配置
    void addIniEntry(const char *name, const char *default_value, int modifiable);
    void registerIniEntries(int module_number);
    void unregisterIniEntries(int module_number);

    // 模块信息
    void printInfo() const;
};
```

### 模块生命周期

```
MINIT (Module Init)
  ↓
MSHUTDOWN (Module Shutdown)
  ↓
RINIT (Request Init) - 每个请求
  ↓
RSHUTDOWN (Request Shutdown) - 每个请求
  ↓
MINFO (Module Info)
```

## 命名空间设计

### php 命名空间

所有 PHPX 代码都在 `php` 命名空间下：

```cpp
namespace php {
    // 核心类型
    class Variant;
    class Array;
    class Object;
    class String;
    class Reference;
    class Resource;
    class Closure;
    class Box;

    // 辅助类型
    class Args;
    class ArgList;
    class OperationChain;

    // 函数指针类型
    using ClosureFn = std::function<Variant(INTERNAL_FUNCTION_PARAMETERS, Object &, Args &)>;
    using resource_dtor = void (*)(zend_resource *);
}
```

### 类型别名

为了方便使用，提供了多种类型别名：

```cpp
using var = Variant;
using array = Array;
using object = Object;
using string = String;

using Var = Variant;
using Str = String;
using Ref = Reference;
```

## 错误处理机制

### 异常抛出

```cpp
// 抛出 PHP 异常
throwError("Error message: %s", detail);

// 带错误码
throwException("RuntimeException", "Something went wrong", 500);

// 如果已发生异常则抛出
throwErrorIfOccurred();
```

### 异常捕获

```cpp
try {
    // 可能抛出异常的代码
    riskyOperation();
} catch (zend_object *ex) {
    // 捕获异常
    auto e = catchException();
    echo(e.getProperty("message").toString());
}
```

### 静默模式

```cpp
// 尝试调用，不抛出异常
try_call([]() {
    constant("NOT_EXISTS");
}, "Fallback value");
```

## 调试支持

### 调试信息

```cpp
struct DebugInfo {
    bool enable;      // 是否启用
    const char *file; // 文件名
    int line;         // 行号
};
```

### 调试 API

```cpp
// 启用调试模式
enableDebugInfo(true);

// 跟踪调试信息
traceDebugInfo(__FILE__, __LINE__);

// 设置调试信息
setDebugInfo();
```

### 变量调试

```cpp
Variant var = getValue();

// 打印调试信息
var.debug();

// 使用 var_dump 格式
var.print();
```

## 性能优化

### 1. 字符串字面量缓存

`literal_string.cc` (119.9KB) 实现了字符串字面量的缓存机制：

```cpp
// 使用预注册的字符串，避免重复分配
static String cached_string;

// 初始化时注册
cached_string = registerLiteralString("cached");
```

### 2. 函数缓存

```cpp
// 缓存函数查找结果
static zend_function *cached_func;

if (!cached_func) {
    cached_func = findFunction("function_name");
}

// 直接使用缓存的函数指针
call(cached_func, args);
```

### 3. 类入口缓存

```cpp
// 缓存类入口
static zend_class_entry *cached_ce;

if (!cached_ce) {
    cached_ce = getClassEntry("ClassName");
}

// 直接使用缓存的类入口
Object obj = newObject(cached_ce);
```

## 线程安全

### ZTS 支持

```cpp
#ifdef ZTS
#define THREAD_LOCAL thread_local
#else
#define THREAD_LOCAL
#endif

// 线程局部存储
THREAD_LOCAL static bool request_init_called = false;
THREAD_LOCAL int box_res_id;
```

### 资源隔离

每个请求有独立的资源：

```cpp
void request_init() {
    if (request_init_called) {
        return;
    }
    request_init_called = true;

    // 注册请求级资源
    box_res_id = zend_register_list_destructors_ex(
        box_dtor, nullptr, box_res_name, 0
    );
}

void request_shutdown() {
    if (request_shutdown_called) {
        return;
    }
    request_shutdown_called = true;

    // 清理请求级资源
}
```

## 内存模型

### 引用计数

PHPX 遵循 PHP 的引用计数机制：

```cpp
// 增加引用计数
void Variant::addRef() {
    zval *zv = unwrap_ptr();
    if (Z_REFCOUNTED_P(zv)) {
        Z_TRY_ADDREF_P(zv);
    }
}

// 减少引用计数
void Variant::destroy() {
    zval_ptr_dtor(&val);
}
```

### 写时复制（Copy-on-Write）

```cpp
// 分离容器，实现写时复制
SEPARATE_ARRAY(zv);
SEPARATE_STRING(zv);
```

### 智能指针

使用 C++ 智能指针管理资源：

```cpp
std::unique_ptr<Resource> res;
std::shared_ptr<Class> cls;
```

---

*本文档最后更新：2026-03-27*
