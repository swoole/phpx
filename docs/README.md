# PHPX 文档索引

欢迎来到 PHPX 项目的文档中心。PHPX 是一个使用 C++ 封装 Zend API 的强大工具，让 PHP 扩展开发更加简单高效。

## 文档目录

### 基础文档
- [项目概述](./overview.md) - 项目介绍、特性和技术栈
- [快速开始](./quickstart.md) - 安装和快速上手指南
- [架构设计](./architecture.md) - 系统架构和设计原理

### 开发文档
- [API 参考](./api-reference.md) - 完整的 API 接口文档
- [核心类说明](./core-classes.md) - 核心类的详细说明
- [函数手册](./functions.md) - 内置函数使用手册

### 实践文档
- [示例指南](./examples-guide.md) - 示例代码使用说明
- [测试指南](./testing-guide.md) - 测试框架和测试方法
- [最佳实践](./best-practices.md) - 开发最佳实践

## 项目结构

```
phpx/
├── src/           # 源代码目录
│   ├── core/      # 核心实现（Variant, Array, Object 等）
│   ├── func/      # PHP 函数封装
│   ├── class/     # PHP 类封装
│   └── const/     # 常量定义
├── include/       # 头文件
├── tests/         # 测试代码
├── examples/      # 示例代码
└── docs/          # 本文档目录
```

## 核心特性

- **C++14 封装**：现代化的 C++ 语法，简洁安全
- **类型安全**：Variant 类型系统，自动类型转换
- **易于使用**：面向对象的 API 设计
- **高性能**：直接调用 Zend API，无额外开销
- **完整测试**：单元测试覆盖核心功能

## 快速链接

- [GitHub 仓库](https://github.com/swoole/phpx)
- [安装指南](./quickstart.md#安装)
- [Hello World 示例](./quickstart.md#第一个扩展)
- [API 文档](./api-reference.md)

## 支持的 PHP 版本

- PHP 8.1+
- 支持 Linux/macOS/Windows 平台

## 社区与支持

- Twitter: [@phpswoole](https://twitter.com/phpswoole)
- Discord: [Swoole 社区](https://discord.swoole.dev)
- Issue Tracker: GitHub Issues

---

*最后更新：2026-03-27*
