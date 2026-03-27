# 快速开始

本指南将帮助您快速安装 PHPX 并创建第一个 PHP 扩展。

## 环境要求

在开始之前，请确保您的系统满足以下要求：

### 必需软件
- **PHP 8.1** 或更高版本
- **GCC 4.8+** 或 **Clang**
- **CMake 3.10+**
- **Composer**

### 可选工具
- **GTest**（用于运行测试）
- **Git**（用于克隆仓库）

## 安装步骤

### 1. 安装依赖

#### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install php8.1-dev php8.1-cli cmake g++ git composer
```

#### CentOS/RHEL
```bash
sudo yum install php-devel php-cli cmake gcc-c++ git composer
```

#### macOS
```bash
brew install php@8.1 cmake composer
```

### 2. 克隆项目
```bash
git clone https://github.com/swoole/phpx.git
cd phpx
```

### 3. 编译安装
```bash
cmake .
make -j 4
sudo make install
sudo ldconfig
```

### 4. 验证安装
```bash
php-config --includes  # 应显示包含 phpx 头文件的路径
ls /usr/local/include/phpx/  # 应看到 PHPX 头文件
```

## 创建第一个扩展

### 方法一：使用 Composer 模板（推荐）

```bash
# 创建扩展项目
composer create-project swoole/phpx-ext test
cd test

# 构建扩展
cmake .
make -j 4
sudo make install
```

### 方法二：手动创建

#### 1. 创建项目结构
```bash
mkdir myext
cd myext
mkdir src
```

#### 2. 创建 CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.10)
project(myext)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest)

execute_process(COMMAND php-config --prefix 
    OUTPUT_VARIABLE PHP_PREFIX OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND php-config --includes 
    OUTPUT_VARIABLE PHP_INCLUDES OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND php-config --extension-dir 
    OUTPUT_VARIABLE PHP_EXTENSION_DIR OUTPUT_STRIP_TRAILING_WHITESPACE)

include_directories(${PHP_PREFIX}/include/phpx)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${PHP_INCLUDES}")

add_library(myext SHARED src/myext.cc)
target_link_libraries(myext phpx)

install(TARGETS myext LIBRARY DESTINATION ${PHP_EXTENSION_DIR})
```

#### 3. 创建扩展代码 (src/myext.cc)

```cpp
#include "phpx.h"

using namespace php;

// 定义一个简单的函数
PHPX_FUNCTION(hello) {
    return "Hello from PHPX!";
}

// 模块入口
void php_myext_MINFO_FUNC(zend_module_entry *module) {
    php_info_print_table_start();
    php_info_print_table_row(2, "myext support", "enabled");
    php_info_print_table_end();
}

// 扩展定义
Extension ext("myext", "1.0.0");

extern "C" {
    zend_module_entry myext_module_entry = {
        STANDARD_MODULE_HEADER,
        "myext",                    // 扩展名称
        nullptr,                    // 函数列表（由 PHPX 自动填充）
        nullptr,                    // MINIT
        nullptr,                    // MSHUTDOWN
        nullptr,                    // RINIT
        nullptr,                    // RSHUTDOWN
        php_myext_MINFO_FUNC,       // MINFO
        "1.0.0",                    // 版本号
        STANDARD_MODULE_PROPERTIES
    };
}

#ifdef COMPILE_DL_MYEXT
ZEND_GET_MODULE(myext)
#endif

// 注册函数
extern "C" void startup_extension() {
    ext.registerFunction("hello", hello);
}
```

#### 4. 编译安装
```bash
cmake .
make -j 4
sudo make install
```

#### 5. 启用扩展
编辑 `php.ini`，添加：
```ini
extension=myext.so
```

#### 6. 测试
创建测试文件 `test.php`：
```php
<?php
echo hello() . "\n";
// 输出：Hello from PHPX!
```

运行：
```bash
php test.php
```

## 生成函数存根

PHPX 提供了工具来自动生成函数信息和函数入口：

### 1. 创建存根文件 (myext.stub.php)
```php
<?php

/**
 * @generate-function-entries
 */

/**
 * Say hello
 * 
 * @return string
 */
function hello(): string {}
```

### 2. 生成代码
```bash
php vendor/swoole/phpx/bin/gen_stub.php myext.stub.php
```

这将生成：
- `myext_arginfo.h` - 参数信息
- `myext_legacy_arginfo.h` - 兼容旧版本的参数信息

## 常用示例

### 1. 处理参数
```cpp
PHPX_FUNCTION(greet) {
    String name = args[0].toString();
    Int age = args[1].toInt();
    
    return String("Hello ") + name + ", age: " + std::to_string(age);
}
```

### 2. 数组操作
```cpp
PHPX_FUNCTION(array_test) {
    Array arr;
    arr.set("name", "John");
    arr.set("age", 25);
    arr.set(0, "first");
    
    return arr;
}
```

### 3. 对象创建
```cpp
PHPX_FUNCTION(create_object) {
    Object obj = newObject("stdClass");
    obj.setProperty("name", "Test");
    return obj;
}
```

### 4. 错误处理
```cpp
PHPX_FUNCTION(divide) {
    double a = args[0].toDouble();
    double b = args[1].toDouble();
    
    if (b == 0) {
        throwError("Division by zero");
        return;
    }
    
    return a / b;
}
```

### 5. 调用 PHP 函数
```cpp
PHPX_FUNCTION(call_php_func) {
    Variant result = call("strlen", {"Hello World"});
    return result;  // 11
}
```

## 调试技巧

### 启用调试模式
```cpp
enableDebugInfo(true);
```

### 输出调试信息
```cpp
Variant var = getValue();
var.debug();  // 打印变量信息
var.print();  // 使用 var_dump 格式打印
```

### 查看引用计数
```cpp
printf("Refcount: %d\n", var.getRefCount());
```

## 常见问题

### Q: 编译时找不到 phpx.h
A: 确保已正确安装 PHPX，并且 `include_directories` 指向正确的路径。

### Q: 扩展加载失败
A: 检查：
1. 扩展文件是否在正确的目录
2. `php.ini` 中的路径是否正确
3. 是否有权限问题

### Q: 段错误（Segmentation Fault）
A: 常见原因：
1. 未正确初始化变量
2. 引用计数错误
3. 访问已释放的内存

使用 `valgrind` 或 `gdb` 进行调试。

### Q: 如何查看扩展是否加载成功
```bash
php -m | grep myext
# 或
php --ri myext
```

## 下一步

完成快速开始后，您可以：

1. 阅读 [API 参考](./api-reference.md) 了解详细的 API
2. 查看 [示例指南](./examples-guide.md) 学习更多实践
3. 研究 [架构设计](./architecture.md) 深入理解原理

## 资源链接

- [GitHub 仓库](https://github.com/swoole/phpx)
- [示例代码](../examples/)
- [测试代码](../tests/)

---

*需要帮助？查看 [常见问题](#常见问题) 或提交 Issue。*
