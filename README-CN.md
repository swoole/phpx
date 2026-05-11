<h1 align=center>
<img width="400" alt="Swoole Logo" src="logo.png" />
</h1>

[![Twitter](https://badgen.net/badge/icon/twitter?icon=twitter&label)](https://twitter.com/phpswoole)
[![Discord](https://badgen.net/badge/icon/discord?icon=discord&label)](https://discord.swoole.dev)
[![Build Status](https://github.com/matyhtf/phpx/workflows/libphpx/badge.svg)](https://github.com/matyhtf/phpx/actions?query=workflow%3Alibphpx)
[![License](https://img.shields.io/badge/license-apache2-blue.svg)](LICENSE)
[![Latest Release](https://img.shields.io/github/release/swoole/phpx.svg)](https://github.com/swoole/phpx/releases/)
[![Codecov](https://codecov.io/gh/swoole/phpx/branch/master/graph/badge.svg)](https://codecov.io/gh/swoole/phpx)

Zend API 的 C++ 封装库

[English](README.md)

## 系统要求

- PHP 8.2 或更高版本
- Linux/macOS/Windows
- GCC 9 或更高版本（支持 C++17）
- Composer

## 安装

### 编译 libphpx.so

```shell
# 标准构建（Release 模式）
cmake .
make -j 4
sudo make install
sudo ldconfig
```

### Debug 模式（用于排查问题）

```shell
# 清理之前的构建
cmake --build . --target clean

# 配置 Debug 模式（包含调试符号和运行时检查）
cmake -DCMAKE_BUILD_TYPE=Debug .

# 编译
make -j 4
sudo make install
sudo ldconfig
```

**Debug 模式特性：**
- ✅ 生成完整的调试符号
- ✅ 禁用编译器优化，便于单步调试
- ✅ 启用运行时错误检查
- ✅ 更详细的编译输出信息

## 快速开始

### 创建新的扩展项目

```shell
# 创建扩展项目
composer create-project swoole/phpx-ext test
cd test
```

### 基本用法示例

以下是展示现代 PHPX 扩展开发的完整示例：

```cpp
#include "phpx_ext.h"

// 包含自动生成的 arginfo 头文件（由 gen_stub.php 生成）
BEGIN_EXTERN_C()
#include "your_extension_arginfo.h"
END_EXTERN_C()

using namespace php;
using namespace std;

// 使用 PHPX_METHOD 宏实现类方法
PHPX_METHOD(MyClass, __construct) {
    // 初始化对象属性
    _this.set("name", args[0].toString());
    _this.set("value", args[1].toInt());
    return nullptr;
}

PHPX_METHOD(MyClass, greet) {
    // 访问对象属性
    auto name = _this.get("name");
    auto value = _this.get("value");
    
    // 返回格式化字符串
    return "Hello, " + name.toStdString() + "! Value: " + to_string(value.toInt());
}

PHPX_METHOD(MyClass, processData) {
    // 使用 Array 类型
    Array input = args[0];
    Array result;
    
    // 迭代并转换
    for (auto &item : input) {
        result.append(item.value.toInt() * 2);
    }
    
    return result;
}

// 使用 PHPX_FUNCTION 宏实现函数
PHPX_FUNCTION(my_extension_func) {
    // Variant - 通用类型容器
    Variant str_var = "Hello PHPX";
    Variant int_var = 42;
    Variant float_var = 3.14159;
    
    // 数组操作
    Array arr;
    arr.set("name", "PHPX");
    arr.set("version", 8.2);
    arr.set("features", Array{"C++17", "Type-safe", "Modern API"});
    
    // 对象创建和方法调用
    Object datetime = newObject("DateTime");
    auto formatted = datetime.call("format", {"Y-m-d H:i:s"});
    
    // Facade 函数 - 直接调用 PHP 函数
    php::var_dump(arr);                    // 调试输出
    php::print_r(datetime);                // 打印对象
    
    // 文件操作
    auto content = php::file_get_contents("/etc/hosts");
    if (content.isString()) {
        echo("File length: ", content.length(), "\n");
    }
    
    // 使用引用进行数组操作
    Array numbers{1, 2, 3, 4, 5};
    Reference ref = numbers.toReference();
    php::sort(ref);                        // 排序数组
    php::array_push(ref, 6, 7, 8);        // 添加元素
    
    RETURN_STRING("PHPX Demo Completed!");
}

// 扩展入口点
PHPX_EXTENSION() {
    Extension *ext = new Extension("my_extension", "1.0.0");
    
    // 注册生命周期回调
    ext->onStart = [ext]() noexcept {
        // 注册常量
        ext->registerConstant("MY_EXT_VERSION", 10000);
        
        // 注册带方法的类
        Class *c = new Class("MyClass");
        c->addProperty("name", "", ZEND_ACC_PUBLIC);
        c->addProperty("value", 0, ZEND_ACC_PUBLIC);
        c->registerFunctions(class_MyClass_methods);  // 来自 arginfo 头文件
        ext->registerClass(c);
        
        // 注册独立函数
        ext->registerFunction(PHPX_FN(my_extension_func));
    };
    
    // PHP info 页面配置
    ext->info({"my_extension support", "enabled"},
              {
                  {"author", "Your Name"},
                  {"version", ext->version},
                  {"github", "https://github.com/your/repo"},
              });
    
    return ext;
}
```

**核心特性：**
- **PHPX_METHOD/PHPX_FUNCTION**: 现代化宏，代码更简洁
- **Extension/Class API**: 面向对象的扩展注册方式
- **Lambda 回调**: 灵活的生命周期管理（`onStart`、`onShutdown` 等）
- **类型安全封装**: `Variant`、`Array`、`Object`、`String` 类
- **Facade 函数**: 通过 `php::` 命名空间直接调用 PHP 函数
- **自动生成 arginfo**: 使用 `gen_stub.php` 生成类型信息

### 生成 ArgInfo 和函数入口

```shell
php vendor/swoole/phpx/bin/gen_stub.php your_stub_dir
```

### 构建你的扩展

```shell
cd test
cmake .
make -j 4
make install
```

### 加载你的扩展

编辑 `php.ini` 并添加：
```ini
extension=test.so
```

### 测试你的扩展

创建测试文件 `test.php`：
```php
<?php
echo hello_world() . "\n";
?>
```

运行它：
```shell
php test.php
```

预期输出：
```
Hello, World!
```

## 高级用法

### 1. Variant 类型使用

Variant 是一个通用类型容器，可以持有任何 PHP 值：

```cpp
#include "phpx.h"

using namespace php;

// 创建不同类型的变量
Variant str_var = "Hello PHPX";
Variant int_var = 42;
Variant float_var = 3.14159;
Variant bool_var = true;
Variant null_var;

// 类型检查
if (str_var.isString()) {
    echo("String: ", str_var.toCString());
}

if (int_var.isInt()) {
    echo("Integer: ", int_var.toInt());
}

// 类型转换
auto str = int_var.toString();      // 转换为字符串
auto num = str_var.toInt();         // 转换为整数（如果不是数字则为 0）

// 比较
if (str_var.equals("Hello PHPX")) {
    echo("Match!");
}

// 序列化
Variant serialized = str_var.serialize();
Variant unserialized = serialized.unserialize();
```

### 2. Array 类型使用

Array 为 PHP 数组提供了 C++ 封装，具有丰富的功能：

```cpp
#include "phpx.h"

using namespace php;

// 创建数组
Array arr;
arr.set("name", "PHPX");
arr.set("version", 8.2);
arr.set("features", Array{"C++17", "Type-safe", "Modern API"});

// 使用列表初始化
Array numbers{1, 2, 3, 4, 5};
Array map{{"key1", "value1"}, {"key2", "value2"}};

// 访问元素
auto name = arr.get("name");
auto first = numbers[0];

// 检查是否存在
if (arr.exists("name")) {
    echo("Name exists");
}

// 迭代数组
for (auto &item : arr) {
    echo(item.key, ": ", item.value, "\n");
}

// 数组操作
arr.append("new_element");          // 添加元素
arr.del("name");                    // 删除元素
auto count = arr.count();           // 获取数量
auto keys = arr.keys();             // 获取所有键

// 嵌套数组
Array nested;
nested.set("level1", Array{
    {"level2", Array{"deep_value"}}
});
auto deep = nested.item("level1").item("level2");

// 使用引用进行修改
Array nums{5, 2, 8, 1, 9};
Reference ref = nums.toReference();
php::sort(ref);                     // 原地排序
php::array_push(ref, 10, 11);       // 添加元素
```

### 3. Object 类型使用

Object 封装了 PHP 对象并提供方法调用功能：

```cpp
#include "phpx.h"

using namespace php;

// 创建对象
Object datetime = newObject("DateTime");

// 调用方法
auto formatted = datetime.call("format", {"Y-m-d H:i:s"});
echo("Current time: ", formatted.toCString());

// 设置属性
Object stdclass = newObject("stdClass");
stdclass.set("name", "test");
stdclass.set("value", 42);

// 获取属性
auto name = stdclass.get("name");
auto value = stdclass.get("value");

// 检查属性是否存在
if (stdclass.exists("name")) {
    echo("Property exists");
}

// 带构造函数参数创建对象
Object arrayObj = newObject("ArrayObject", {
    Array{1, 2, 3, 4, 5}
});

// 调用方法并获取结果
auto count = arrayObj.call("count");
echo("Count: ", count.toInt());

// 静态方法调用
auto result = Object::callStatic("DateTime", "createFromFormat", {
    "Y-m-d", "2024-01-01"
});
```

### 4. Facade 封装 API

PHPX 在 `php::` 命名空间中提供了 facade 函数，用于直接调用 PHP 函数：

```cpp
#include "phpx.h"
#include "phpx_func.h"

using namespace php;

// 调试和输出
php::var_dump(some_variable);           // 调试输出
php::print_r(some_variable);            // 可读打印
php::echo("Hello", " ", "World");      // 输出字符串

// 文件操作
auto content = php::file_get_contents("/path/to/file.txt");
php::file_put_contents("/path/to/file.txt", "content");

// 数组操作（需要引用）
Array arr{5, 2, 8, 1, 9};
Reference ref = arr.toReference();

php::sort(ref);                         // 排序数组
php::rsort(ref);                        // 逆向排序
php::shuffle(ref);                      // 打乱
php::array_push(ref, 10, 11);          // 添加元素
php::array_pop(ref);                    // 弹出元素
php::array_shift(ref);                  // 移出元素
php::array_unshift(ref, 0);            // 压入元素

// 字符串操作
auto upper = php::strtoupper("hello");
auto lower = php::strtolower("HELLO");
auto length = php::strlen("hello");
auto pos = php::strpos("hello world", "world");

// 数学运算
auto max_val = php::max({1, 2, 3, 4, 5});
auto min_val = php::min({1, 2, 3, 4, 5});
auto sum = php::array_sum(Array{1, 2, 3, 4, 5});
auto rand_val = php::rand(1, 100);

// JSON 操作
Array data{{"name", "PHPX"}, {"version", 8.2}};
auto json_str = php::json_encode(data);
auto decoded = php::json_decode(json_str, true);

// 其他实用函数
php::sleep(2);                          // 睡眠 2 秒
auto time = php::time();                // 当前时间戳
auto date = php::date("Y-m-d H:i:s");  // 格式化日期
```

### 5. 内置类的 Facade 封装

PHPX 为流行的 PHP 扩展提供了 facade 类：

```cpp
#include "phpx.h"
#include "phpx_class.h"

using namespace php;

// Redis 示例
Redis redis{};
redis.connect("127.0.0.1", 6379);

// 字符串操作
redis.set("name", "PHPX");
redis.set("version", "8.2");
auto name = redis.get("name");
echo("Name: ", name.toCString());

// 检查是否存在
if (redis.exists("name")) {
    echo("Key exists");
}

// 批量操作
redis.mset({
    {"key1", "value1"},
    {"key2", "value2"},
    {"key3", "value3"}
});

auto values = redis.mget({"key1", "key2", "key3"});

// 列表操作
redis.rpush("mylist", "item1");
redis.rpush("mylist", "item2");
auto list_len = redis.llen("mylist");

// Hash 操作
redis.hset("user:1", "name", "John");
redis.hset("user:1", "email", "john@example.com");
auto user_name = redis.hget("user:1", "name");

// 设置过期时间
redis.expire("name", 3600);  // 1 小时后过期

// 删除键
redis.del("key1", "key2");

// 关闭连接
redis.close();
```

**注意：** 要使用 Redis facade，请确保在 PHP 环境中加载了 Redis 扩展。

## 文档

更多详细文档请查看：
- [架构指南](docs/architecture.md)
- [API 参考](docs/api-reference.md)
- [快速入门](docs/quickstart.md)
- [测试指南](docs/testing-guide.md)
- [调试指南](docs/debugging-guide.md)

## 示例

查看 [examples 目录](examples/) 获取更多综合示例，包括：
- Bloom filter 实现
- 队列数据结构
- RocksDB 集成
- GTK 应用程序
- 以及更多！

## 语言

- [English](README.md)
- [中文](README-CN.md)

## 许可证

PHPX 是根据 [Apache License 2.0](LICENSE) 许可的开源软件。