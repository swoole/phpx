# 最佳实践

## 从工具生成项目

新扩展从 `phpx init` 开始，不复制旧示例或手写 `zend_module_entry`：

```bash
mkdir my_ext
cd my_ext
composer require swoole/phpx
vendor/bin/phpx init my_ext
```

项目内只维护业务代码和配置。`build/gen_stub.php` 与 `run-tests.php` 来自
当前 PHP 开发包，由 `.phpx.json` 的 hash 防止工具覆盖用户修改。

## 目录边界

```text
src/       C++ 实现、私有头文件、*.stub.php、生成的 *_arginfo.h
include/   需要安装给其他扩展使用的公共 C/C++ 头文件
tests/     PHPT
build/     CMake 和生成工具输出
```

不要把私有类型放进 `include/`。`phpx install` 会递归发布其中的
`.h/.hh/.hpp/.hxx`，但不会发布 `src/`。

## 让 stub 成为签名来源

PHP 函数、方法和类签名写在 `src/*.stub.php`，实现写在 C++。CMake 应把
stub 与 `build/gen_stub.php` 同时声明为 arginfo 输出依赖。不要手工编辑或
提交生成的 `*_arginfo.h`。

```php
<?php

/** @generate-function-entries */
function my_ext_version(): string {}
```

```cpp
PHPX_FUNCTION(my_ext_version) {
    return "0.1.0";
}
```

## 优先使用 PHPX 所有权 API

使用 `Variant`、`String`、`Array`、`Object` 和 `Reference` 管理 zval。除非
正在实现 Zend 适配层，不保存 `zval *`、`zend_string *` 或属性槽地址。

```cpp
Variant value = source.get("key");       // owned snapshot
String text = value.toString();
```

`item()`、Indirect 构造和裸指针访问器不会保证底层地址在结构修改后仍然
有效。跨操作保存数据时使用普通赋值或 `copyValue()`。

## 区分值写入与引用写入

普通 PHP 赋值优先使用：

```cpp
array.setValue(key, value);
array.appendValue(value);
```

只有需要保留显式 PHP reference 时才使用 `set()` / `append()`。引用语义
必须体现在接口名称或调用点，不能依赖偶然的 zval 状态。

## 不跨请求缓存脚本符号

MINIT 可使用 `getInternalClassEntry()` 获取内置类和扩展依赖类。PHP 脚本
定义的类、函数、对象和普通字符串属于 request，只能在当前 request 缓存，
并在 RSHUTDOWN 清理。

```cpp
zend_class_entry *ce = getInternalClassEntrySafe("DateTime"); // MINIT 可用
```

不要把 request class table 中的 CE 或 function pointer 存入进程级 static。
ZTS 下 thread-local 也不能代替 request 生命周期清理。

## 使用通用调用桥

PHPX 不提供全量 Facade。普通动态调用使用：

```cpp
Variant result = php::call("strlen", {"hello"});
Object object = newObject("DateTime");
Variant value = object.call("format", {"Y-m-d"});
```

只有已经证明稳定并且有真实基准收益时，才缓存 `zend_function *` 或
`zend_class_entry *`。外部输入驱动的随机 callable/method cache 通常没有
收益，反而增加失效和生命周期风险。

## 错误和异常

参数类型应由 stub/arginfo 和 PHPX 检查共同保证。业务错误使用明确的 PHP
异常；不可恢复的 API 误用使用 `throwError()`：

```cpp
if (!value.isString()) {
    throwError("expected string, got %s", value.typeStr());
}
```

C++ 异常不得穿透 Zend VM。生命周期回调尤其需要遵守当前阶段允许的错误
报告方式，不在 MINIT 使用只适用于 request 的对象。

## 构建与 ABI

PHPX 只支持 PHP 8.4/8.5，扩展、PHPX 和 PHP 必须具有一致的：

- PHP minor/API 版本；
- ZTS/NTS；
- CPU 架构；
- Windows toolset/runtime；
- sanitizer/debug ABI（调试场景）。

`phpx build -j N` 只构建当前扩展，不构建、检测或复制 `libphpx`。开发者
负责提前准备 PHPX；缺失头文件和库应让编译器/链接器直接报错。

切换 PHP 后执行：

```bash
vendor/bin/phpx switch /path/to/php-config
vendor/bin/phpx build -j 4
```

## 测试

- PHPX 核心行为：`tests/src/` Google Test；
- 扩展入口：`tests/ext/` + PHPUnit；
- 项目工具：`tests/unit/PhpXCommandTest.php`；
- 用户扩展行为：项目自己的 PHPT。

不要在扩展 PHPT 重复大规模测试 PHPX 编译器特性。重点覆盖模块加载、
依赖、MINIT/RINIT/RSHUTDOWN、多 request 和安装布局。

## 调试顺序

1. 记录 `php -v`、`php --ini`、`php-config --configure-options`；
2. 核对加载的扩展模块和动态库路径；
3. Debug 构建复现；
4. 使用 ASAN/Valgrind 检查内存；
5. 使用 GDB/LLDB 查看首个异常栈；
6. 最后再考虑 cache、JIT 或平台差异。

```bash
gdb --args ./bin/phpx-tests --gtest_filter='suite.test'
valgrind --leak-check=full ./bin/phpx-tests --gtest_filter='suite.test'
```

性能优化必须有基准前后数据，并保持 Zend API 封装、异常安全和生命周期
安全。不要为了边缘兼容或微小收益复制大段 Zend VM 内部代码。
