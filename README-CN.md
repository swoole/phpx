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

以下是使用 PHPX 创建 PHP 扩展的简单示例：

```cpp
#include "phpx.h"

using namespace std;
using namespace phpx;

// 定义一个简单的函数
ZEND_FUNCTION(hello_world)
{
    RETURN_STRING("Hello, World!");
}

// 模块初始化
ZEND_MINIT_FUNCTION(test)
{
    // 注册函数
    REGISTER_FUNCTION(hello_world);
    
    return SUCCESS;
}
```

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