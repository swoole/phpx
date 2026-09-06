# 扩展与运行时架构

## 分层

```text
TypePHP 生成代码             C++ PHP 扩展
        │                         │
        ├──── TypePHP helpers ────┤
        │                         │
        └──────── PHPX ───────────┘
                    │
             Zend Engine API
```

PHPX 的核心实现分为三层：

- `src/core/`：`zval` 所有权、数组、对象、动态调用、扩展生命周期等；
- `src/std/`：少量高频 PHP 标准操作的类型安全快速路径；
- `src/typephp/`：TypePHP 生成代码使用的专有运行时。

普通扩展包含 `phpx_ext.h`；需要通用值和调用 API 时可包含 `phpx.h`；需要
标准快速路径时再包含 `phpx_std.h`。不应包含 PHPX 的 `src/` 文件。

## 值和所有权

`Variant` 的内存布局围绕 `zval` 构建，并通过 RAII 管理引用计数。常规
构造、复制、返回值和容器写入都应使用 PHPX 类型，不要求扩展直接操作裸
`zval *`。

PHPX 仍提供少量与 Zend 交互所必需的低层访问器，例如 `unwrap_ptr()`、
`array()`、`object()`。这些接口不延长目标生命周期，也不会替调用者验证
所有 Zend 不变量，因此只应在无法使用高级接口时使用。

`Reference` 表示 PHP 引用。`Array::set()` / `Array::append()` 可用于明确
保留引用语义的低层场景；普通值写入优先使用 `setValue()` /
`appendValue()`，避免意外传播引用。

## 动态调用

通用调用最终进入 Zend 调用 API：

```cpp
Variant result = php::call("strlen", {"hello"});
Object date = newObject("DateTime", {"2026-09-06"});
Variant formatted = date.call("format", {"Y-m-d"});
Variant parsed = callStaticMethod("DateTime", "createFromFormat",
                                  VarList{"Y-m-d", "2026-09-06"});
```

TypePHP 可以在静态证明目标稳定时生成更直接的调用或缓存路径。显式动态的
类名、方法名和 callable 仍由 Zend 在运行时解析；PHPX 不复制 Zend VM 的
opcode cache 实现来追求边缘兼容或低命中缓存。

## 扩展注册

扩展入口返回一个 `Extension`：

```cpp
PHPX_EXTENSION() {
    auto *extension = new Extension("hello_ext", "0.1.0");
    extension->registerFunctions(ext_functions);
    extension->onStart = [extension]() noexcept {
        extension->registerConstant("HELLO_EXT_VERSION", 100);
    };
    return extension;
}
```

`ext_functions` 和类方法表由当前 PHP 开发包中的 `gen_stub.php` 根据
`src/*.stub.php` 生成。PHPX 不维护 legacy arginfo，也不要求项目手写
`zend_module_entry`。

`Extension` 的生命周期回调与 Zend 阶段对应：

- `onStart`：MINIT；
- `onShutdown`：MSHUTDOWN；
- `onBeforeRequest`：RINIT；
- `onAfterRequest`：RSHUTDOWN。

MINIT 创建的扩展、类和函数信息属于持久状态。请求中解析的动态 PHP 类、
函数、对象和 request cache 不得泄漏到下一个请求；TypePHP 运行时在请求
关闭阶段主动清理其 request 级状态。

## 类和接口

`Class` 用于注册扩展类的常量、属性、方法表、父类和接口；`Interface`
注册接口方法表。它们必须在扩展启动阶段激活，不能作为请求级动态类系统。

```cpp
extension->onStart = [extension]() noexcept {
    auto *point = new Class("Point");
    point->addProperty("x", 0.0, ZEND_ACC_PUBLIC);
    point->registerFunctions(class_Point_methods);
    extension->registerClass(point);
};
```

## 项目构建

`phpx init` 生成的项目保存准确的 `php-config` 路径。`phpx build` 配置并
并行构建扩展，但不会构建或检测 `libphpx`；开发者必须保证头文件和链接库
与目标 PHP ABI 匹配。stub 依赖由 CMake 跟踪，仅在输入改变时重新生成
arginfo。

`phpx install` 只安装：

- 扩展 `.so` / `.dll`；
- 项目 `include/` 下的公共 C/C++ 头文件。

`src/` 下的头文件、stub 和 arginfo 始终是私有文件。

## ZTS 和异常边界

PHPX 同时构建 NTS/ZTS ABI，但二进制必须与目标 PHP 完全匹配。进程级共享
状态不得保存 request memory 指针；线程局部状态也必须按请求生命周期
初始化和清理。

C++ 异常不能穿透 Zend VM。PHPX 的扩展和 TypePHP 边界负责将异常转换为
PHP 异常或 fatal error。扩展代码应使用 PHPX 提供的 `throwError()`、
`throwException()` 等接口，并遵守当前生命周期阶段的限制。
