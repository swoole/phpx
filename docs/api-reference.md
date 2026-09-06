# API 参考

本文只列出稳定、常用的公开入口。完整签名以当前版本的
[`include/phpx.h`](../include/phpx.h)、
[`include/phpx_ext.h`](../include/phpx_ext.h) 和
[`include/phpx_std.h`](../include/phpx_std.h) 为准。

## 头文件

```cpp
#include "phpx.h"       // 值、数组、对象、调用等核心 API
#include "phpx_ext.h"   // 编写 PHP 扩展
#include "phpx_std.h"   // 选择性标准函数快速路径
```

不要包含 `src/` 或 `tests/include/`。后者的 Facade 子集只服务 PHPX 自身
Google Test，不是公开 API。

## 基础类型

PHPX 类型位于 `php` 命名空间：

```cpp
using php::Variant;
using php::String;
using php::Array;
using php::Object;
using php::Reference;
using php::Args;
```

另有 `Var`、`Str`、`Ref` 以及小写 `var`、`string`、`array`、`object`
别名。新代码建议优先写完整类型名，减少与应用符号冲突。

### Variant

常用构造和查询：

```cpp
Variant value = 42;
Variant text = "hello";
Variant none = nullptr;

value.isInt();
value.isFloat();
value.isBool();
value.isString();
value.isArray();
value.isObject();
value.isResource();
value.isReference();
value.isNull();
value.isUndef();

value.toInt();
value.toFloat();
value.toBool();
value.toString();
value.toArray();
value.toObject();
```

数组/ArrayAccess 与对象属性的通用入口：

```cpp
Variant item = value.offsetGet("key");
value.offsetSet("key", 10);
value.offsetUnset("key");

Variant property = value.getProperty("name");
value.setProperty("name", "PHPX");
value.unsetProperty("name");
```

方法调用：

```cpp
Variant result = value.call("method", {1, 2});
```

`ptr()`、`unwrap_ptr()`、`array()`、`object()`、`zv()` 等返回 Zend 底层
指针，属于低层接口。除非正在实现 PHPX/Zend 适配层，否则使用上述高级
API。

### String

```cpp
String text = "  Hello World  ";
String trimmed = text.trim();
String lower = trimmed.lower();
String upper = trimmed.upper();
String part = trimmed.substr(0, 5);
Array pieces = trimmed.split(" ");
String encoded = trimmed.base64Encode();
String decoded = encoded.base64Decode();
```

其他公开操作包括 `match()`、`matchAll()`、`escape()`、`unescape()`、
`stripTags()`、`addSlashes()`、`stripSlashes()`、`basename()` 和
`dirname()`。

### Array

```cpp
Array values{1, 2, 3};
values.set("name", "phpx");
values.appendValue(4);

Variant first = values.get(0);
bool found = values.exists("name");
values.del("name");

values.count();
values.empty();
values.isList();
values.contains(2);
values.search(2);
values.sort();
Array subset = values.slice(0, 2);
```

`setValue()` / `appendValue()` 实现普通 PHP 值写入并解除输入的间接借用。
`set()` / `append()` 可以保留显式引用，主要用于需要 `=&` 语义的低层路径。

遍历项包含 `key` 和 `value`：

```cpp
for (const auto &item : values) {
    php::echo(item.key, ": ", item.value, "\n");
}
```

### Object

```cpp
Object date = newObject("DateTime", {"2026-09-06"});
Variant formatted = date.call("format", {"Y-m-d"});

date.get("property");
date.set("property", 1);
date.getProperties();
date.getClassName();
date.getId();
date.methodExists("format");
date.propertyExists("property");
date.instanceOf("DateTimeInterface");
Object copy = date.clone();
```

`Object::offsetGet()` 等接口用于实现 `ArrayAccess` 的对象。

### Reference

```cpp
Reference ref = newReference(10);
Variant value = ref.getRefValue();
```

`Reference` 表示 Zend reference，而不是普通 C++ 引用。需要显式修改 PHP
引用参数时使用它；普通值传递不要无故创建引用。

## PHP 符号调用

### 函数和 callable

```cpp
Variant length = php::call("strlen", {"hello"});

Variant callable = "trim";
Variant result = php::call(callable, {" value "});
```

动态数量参数可以使用 `Args` 或 `Array`；TypePHP 生成的固定参数调用使用
`VarList` / `FixedArgs`，普通扩展通常直接使用初始化列表即可。

### 类和方法

```cpp
Object object = newObject("ArrayObject", {Array{1, 2, 3}});
Variant count = object.call("count");

Variant parsed = callStaticMethod(
    "DateTime",
    "createFromFormat",
    VarList{"Y-m-d", "2026-09-06"}
);
```

若调用者已经安全持有 `zend_class_entry *` 或 `zend_function *`，头文件也
提供相应重载，避免再次按名称查找。这些指针必须属于正确的持久域或当前
request，不能跨请求缓存脚本类和脚本函数。

### 类与函数查找

- `getClassEntry()` / `getClassEntrySafe()`：请求运行期类；
- `getInternalClassEntry()` / `getInternalClassEntrySafe()`：MINIT 中的内置
  类和扩展依赖类；
- `getFunction()` / `getMethod()`：获取 Zend 函数或方法。

`Safe` 版本在目标不存在时产生 PHP 错误；非 Safe 版本返回空指针。

### 常量、全局变量和代码执行

```cpp
Variant value = php::constant("PHP_VERSION_ID");
Variant globalValue = php::global("_SERVER");
Variant included = php::include("file.php", php::REQUIRE_ONCE);
Variant evaluated = php::eval("return 42;");
```

同时提供类常量、更新 TypePHP 常量、初始化/删除全局变量等重载。执行
`include()` 和 `eval()` 时必须遵守当前 request 与异常边界。

## 错误和异常

```cpp
throwError("invalid state: %s", reason);
throwException(zend_ce_runtime_exception, "operation failed");
```

PHPX 抛出的 C++ 控制流必须在 PHPX 的 Zend 边界内转换，扩展代码不得让
C++ 异常直接穿透 Zend VM。`catchException()` 用于 PHPX 内部/高级互操作，
普通扩展优先让 PHP 异常沿 Zend 调用返回。

## 扩展 API

函数和方法实现使用生成的 arginfo 函数表：

```cpp
PHPX_FUNCTION(hello_ext_version) {
    return "0.1.0";
}

PHPX_METHOD(Point, length) {
    return 0.0;
}
```

注册入口：

```cpp
PHPX_EXTENSION() {
    auto *extension = new Extension("hello_ext", "0.1.0");
    extension->registerFunctions(ext_functions);

    extension->onStart = [extension]() noexcept {
        auto *point = new Class("Point");
        point->addProperty("x", 0.0, ZEND_ACC_PUBLIC);
        point->registerFunctions(class_Point_methods);
        extension->registerClass(point);
    };

    extension->info({"hello_ext support", "enabled"}, {
        {"version", extension->version},
    });
    return extension;
}
```

`Extension` 还提供依赖声明 `require()`、INI 注册 `addIniEntry()`、常量、
资源、接口和生命周期回调。调用这些注册 API 的阶段必须符合
[`phpx_ext.h`](../include/phpx_ext.h) 中的约束。
