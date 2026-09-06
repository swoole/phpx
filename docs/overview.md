# 项目概述

## 定位

PHPX 使用 C++17 对 PHP 8.4/8.5 Zend API 进行边界清晰的封装。它不是一套
独立 PHP 运行时，也不尝试复制 Zend VM 的全部内部实现。PHPX 主要服务于：

- TypePHP AOT 代码的运行时支持；
- 使用 C++ 编写和维护 PHP 扩展。

项目优先保证生命周期、引用计数、异常边界和 ZTS 安全。只有能够通过
Zend 公共 API 或可证明的静态条件实现时，才增加性能快速路径。

## 主要组成

### 值封装

`Variant`、`String`、`Array`、`Object` 和 `Reference` 封装 `zval` 及其
引用计数。默认构造和复制路径拥有自己的值；标记为 Indirect 或直接暴露
Zend 指针的接口属于低层接口，调用者必须保证被借用存储的生命周期。

### PHP 调用桥

- `php::call()` 调用 PHP 函数或 callable；
- `newObject()` 创建 PHP 对象；
- `Object::call()` 调用对象方法；
- `callStaticMethod()` 调用静态方法。

PHPX 不再生成覆盖所有 PHP 内置符号的 Facade。`src/std/` 只保留高频且
具有明确类型或性能收益的封装，其余符号走通用调用桥。

### 扩展开发

`phpx_ext.h` 提供 `PHPX_EXTENSION()`、`PHPX_FUNCTION()`、
`PHPX_METHOD()`、`Extension`、`Class` 和 `Interface`。PHP 函数与方法签名
写入 `src/*.stub.php`，官方 `gen_stub.php` 在相同目录生成
`src/*_arginfo.h`，扩展注册生成的函数表。

### TypePHP 运行时

`src/typephp/` 和 `include/typephp_*.h` 包含 TypePHP 专用的属性、调用、
Trait、Fiber/Generator 和运行时辅助逻辑。这些接口不是普通扩展开发所需
的 Facade。

### 项目工具

Composer 安装的 `vendor/bin/phpx` 提供：

- `init`：创建新扩展或安全补齐已有项目；
- `build`：配置并并行构建当前扩展；
- `switch`：切换项目使用的 `php-config`；
- `install`：安装扩展模块和公共头文件；
- `enable` / `disable`：修改所选 PHP 的 `php.ini`。

工具不会自动构建、检测或安装 `libphpx`。开发者负责为所选 PHP 准备匹配
的 PHPX 头文件和库；依赖问题由 C++ 编译器或链接器直接报告。

## 依赖和平台

- PHP 8.4 或 8.5 开发环境；
- CMake 3.10+；
- 支持 C++17 的 GCC、Clang 或 MSVC；
- GMP、MPFR；
- mpdecimal（Unix 构建使用仓库内源码，Windows 使用 PHP SDK 库）。

Linux 和 macOS 通过 `php-config` 选择 PHP。Windows 构建使用带 SDK 的
`PHP_HOME`。具体扩展项目流程参见[快速开始](quickstart.md)。

## 公开与私有文件

PHPX 仓库的 `include/` 是安装接口，`src/` 是实现。对于使用 `phpx init`
创建的扩展项目：

- `src/*.stub.php`：PHP 声明；
- `src/*_arginfo.h`：生成的私有头文件；
- `src/*.h`：私有扩展头文件；
- `include/*.{h,hh,hpp,hxx}`：由 `phpx install` 发布的公共头文件。

不要让外部代码依赖 PHPX `src/`、测试 Facade 或 TypePHP 内部实现细节。
