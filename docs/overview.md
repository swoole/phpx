# 项目概述

## 什么是 PHPX？

PHPX（PHP eXtension）是一个使用现代 C++（C++14）封装 Zend API 的库，旨在简化 PHP 扩展的开发流程。通过提供面向对象的接口和类型安全的封装，PHPX 让开发者能够以更直观、更安全的方式编写 PHP 扩展。

## 主要特性

### 🚀 高性能
- 直接调用 Zend API，零运行时开销
- 编译型语言，执行效率高
- 支持共享内存和持久化资源

### 🛡️ 类型安全
- Variant 类型系统，自动类型转换
- 编译时类型检查
- 智能的资源管理（RAII）

### 💻 现代化设计
- C++14 语法，代码简洁优雅
- 面向对象 API，易于理解和使用
- 完整的错误处理机制

### 🔧 开发友好
- 清晰的错误信息
- 调试模式支持
- 丰富的内置函数封装

## 技术栈

### 核心依赖
- **C++14**：现代 C++ 标准，提供 auto、lambda 表达式等特性
- **PHP 8.1+**：利用最新的 PHP 内核特性
- **Zend Engine**：PHP 的核心引擎

### 构建工具
- **CMake 3.10+**：跨平台构建系统
- **GCC 4.8+** 或 **Clang**：C++ 编译器
- **Composer**：PHP 依赖管理

### 测试框架
- **Google Test**：C++ 单元测试框架
- **PHPUnit**：PHP 测试工具

## 架构组成

### 核心模块

#### 1. Core（核心层）
位于 `src/core/`，提供最基础的数据类型和操作：

- **Variant**：通用变量类型，支持所有 PHP 数据类型
- **Array**：数组操作封装
- **Object**：对象操作封装
- **String**：字符串处理
- **Resource**：资源类型管理
- **Closure**：闭包支持
- **Extension**：扩展管理

#### 2. Function（函数层）
位于 `src/func/`，封装 PHP 内置函数：

- **Standard**：标准函数（字符串、数组、数学等）
- **Date/Time**：日期时间函数
- **Filesystem**：文件系统函数
- **Network**：网络相关函数
- **Encryption**：加密哈希函数
- 以及更多...

#### 3. Class（类层）
位于 `src/class/`，封装 PHP 内置类：

- **DateTime**：日期时间类
- **PDO**：数据库操作类
- **Redis**：Redis 客户端类
- **DOM**：XML 文档对象模型
- **Reflection**：反射类
- **SPL**：标准 PHP 库

#### 4. Constant（常量层）
位于 `src/const/`，定义 PHP 内置常量：

- CURL 常量
- OpenSSL 常量
- Socket 常量
- 其他扩展常量

## 项目结构

```
phpx/
├── src/                      # 源代码目录
│   ├── core/                 # 核心实现 (10 个文件)
│   │   ├── variant.cc        # Variant 类型实现
│   │   ├── array.cc          # Array 类型实现
│   │   ├── object.cc         # Object 类型实现
│   │   ├── string.cc         # String 类型实现
│   │   ├── base.cc           # 基础函数实现
│   │   ├── extension.cc      # 扩展管理实现
│   │   ├── class.cc          # 类操作实现
│   │   ├── closure.cc        # 闭包实现
│   │   ├── literal_string.cc # 字面字符串实现
│   │   └── helper.cc         # 辅助函数实现
│   ├── func/                 # PHP 函数封装 (30 个文件)
│   │   ├── standard.cc       # 标准函数 (61.7KB)
│   │   ├── mbstring.cc       # 多字节字符串函数
│   │   ├── openssl.cc        # OpenSSL 函数
│   │   ├── gd.cc             # GD 图形函数
│   │   └── ...               # 其他函数
│   ├── class/                # PHP 类封装 (25 个文件)
│   │   ├── redis.cc          # Redis 类封装 (71KB)
│   │   ├── spl.cc            # SPL 类封装 (88.7KB)
│   │   ├── dom.cc            # DOM 类封装 (130.7KB)
│   │   ├── reflection.cc     # 反射类封装
│   │   └── ...               # 其他类
│   ├── const/                # 常量定义 (22 个文件)
│   │   ├── curl.cc           # CURL 常量
│   │   ├── sockets.cc        # Socket 常量
│   │   └── ...               # 其他常量
│   └── php/                  # PHP 相关代码
├── include/                  # 头文件目录
│   ├── phpx.h                # 主头文件 (1269 行)
│   ├── phpx_types.h          # 类型定义
│   ├── phpx_func.h           # 函数声明
│   ├── phpx_class.h          # 类声明
│   ├── phpx_ext.h            # 扩展声明
│   └── ...                   # 其他头文件
├── tests/                    # 测试代码
│   ├── src/                  # C++ 单元测试 (18 个文件)
│   │   ├── variant.cpp       # Variant 测试 (35.8KB)
│   │   ├── array.cpp         # Array 测试
│   │   ├── object.cpp        # Object 测试
│   │   ├── base.cpp          # 基础功能测试
│   │   └── ...               # 其他测试
│   ├── ext/                  # 扩展测试
│   ├── include/              # 测试辅助文件
│   └── unit/                 # 单元测试
├── examples/                 # 示例代码
│   ├── test/                 # 基础示例
│   ├── bloom_filter/         # 布隆过滤器示例
│   ├── queue/                # 队列示例
│   ├── rocksdb/              # RocksDB 示例
│   ├── gtk/                  # GTK 示例
│   ├── embed/                # 嵌入示例
│   └── php/                  # PHP 脚本示例
├── bin/                      # 工具脚本
│   ├── gen_stub.php          # 存根生成工具
│   └── gen-cpp-code.php      # C++ 代码生成器
├── docs/                     # 文档目录
├── lib/                      # 编译库文件
│   ├── libphpx.so            # PHPX 动态库
│   └── libext.so             # 示例扩展
└── cmake/                    # CMake 配置
```

## 代码统计

### 源代码规模
- **核心代码**：~500KB
  - `literal_string.cc`: 119.9KB（最大的单文件）
  - `variant.cc`: 25.9KB
  - `base.cc`: 19.5KB
  
- **类封装**：~500KB
  - `dom.cc`: 130.7KB
  - `redis.cc`: 71KB
  - `spl.cc`: 88.7KB
  
- **函数封装**：~200KB
  - `standard.cc`: 61.7KB
  - `mbstring.cc`: 10.6KB
  - `gd.cc`: 18.9KB

### 测试覆盖
- **单元测试**：18 个测试文件
- **测试代码量**：~200KB
- **核心测试**：
  - `variant.cpp`: 35.8KB
  - `exists.cpp`: 18.4KB
  - `object.cpp`: 19.4KB

## 设计哲学

### 1. 零开销抽象
PHPX 的设计遵循"零开销"原则，所有封装都直接映射到 Zend API，不引入额外的运行时成本。

### 2. RAII 资源管理
利用 C++ 的 RAII 特性，自动管理 PHP 变量的引用计数，避免内存泄漏。

### 3. 类型擦除与恢复
Variant 类型可以存储任何 PHP 值，并在需要时安全地转换为具体类型。

### 4. 异常安全
提供完善的错误处理机制，支持 C++ 异常和 PHP 异常的互操作。

## 命名空间

所有 PHPX 代码都在 `php` 命名空间下：

```cpp
namespace php {
    class Variant;
    class Array;
    class Object;
    // ...
}
```

常用类型别名：
```cpp
using var = Variant;
using array = Array;
using object = Object;
using string = String;
```

## 版本历史

### PHPX 2.x
- 支持 PHP 8.1+
- 重构核心架构
- 增强类型系统
- 完善测试覆盖

### PHPX 1.x
- 初始版本
- 支持 PHP 7.x
- 基础类型封装

## 许可证

PHPX 采用 Apache License 2.0，详见 [LICENSE](../LICENSE)。

## 贡献者

主要作者：Tianfeng Han (@rango@swoole.com)

感谢所有为 PHPX 做出贡献的开发者！

---

*本文档最后更新：2026-03-27*
