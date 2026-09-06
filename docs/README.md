# PHPX 文档

PHPX 是面向 PHP 8.4/8.5 的 C++17 Zend API 封装，当前聚焦两项能力：

1. 作为 TypePHP 生成代码的运行时；
2. 为 C++ PHP 扩展提供类型封装、生命周期注册和项目工具。

## 用户文档

- [项目概述](overview.md)
- [快速开始](quickstart.md)
- [扩展与运行时架构](architecture.md)
- [API 参考](api-reference.md)
- [核心类型与所有权](core-classes.md)
- [示例项目](examples-guide.md)
- [最佳实践](best-practices.md)

## 开发文档

- [测试指南](testing-guide.md)
- [调试指南](debugging-guide.md)
- [调试命令速查](debugging-quick-reference.md)

## 版本和平台

- PHP：8.4、8.5
- C++：C++17
- 平台：Linux、macOS、Windows
- 构建：CMake 3.10+

PHPX 不再提供覆盖全部 PHP 内置函数和类的 Facade API。常用且具备明确
收益的操作位于 `php::` 类型方法或 `phpx_std.h`；其他 PHP 符号通过
`php::call()`、`newObject()`、`Object::call()` 和
`callStaticMethod()` 动态调用。

公开 API 的最终依据是 [`include/`](../include/) 中的安装头文件。文档
不会重复所有内部签名；`src/` 和 `tests/include/` 中的符号均不属于公开
API。

## 项目目录

```text
phpx/
├── bin/phpx       # 扩展项目管理工具
├── include/       # 安装并发布的 PHPX 头文件
├── src/core/      # Zend 值、对象、调用及扩展基础实现
├── src/std/       # 有明确收益的标准函数快速路径
├── src/typephp/   # TypePHP 专用运行时
├── tests/         # C++、扩展和 CLI 测试
└── examples/      # 扩展示例和嵌入示例
```

如文档示例与当前头文件产生差异，应以相同版本的安装头文件为准，并提交
[GitHub Issue](https://github.com/swoole/phpx/issues)。
