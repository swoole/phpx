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

### 创建类

```cpp
// 定义一个类
Class myClass("MyClass");
myClass.addMethod("greet", ZEND_FN(greet_method));
myClass.registerClass();

ZEND_METHOD(MyClass, greet_method)
{
    RETURN_STRING("Hello from MyClass!");
}
```

### 数组操作

```cpp
ZEND_FUNCTION(array_example)
{
    Array arr;
    arr.set("key1", "value1");
    arr.set("key2", 123);
    arr.set("key3", true);
    
    RETURN_ARRAY(arr);
}
```

### 错误处理

```cpp
ZEND_FUNCTION(error_example)
{
    if (some_condition) {
        zend_throw_error(NULL, "出错了！");
        RETURN_FALSE;
    }
    
    RETURN_TRUE;
}
```

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