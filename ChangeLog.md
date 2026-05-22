# PHPX v2.2.0 ChangeLog

## 环境要求升级

1. `PHP` 最低版本要求从 `8.1` 提升至 `PHP 8.2`
2. `C++` 编译器要求从 `C++14` 提升至 `C++17`

---

## Facade API 重构

`2.2`版本对 `Facade API` 进行了重新设计，现在 `Facade API` 对参数和返回值进行类型转换，
在`C++`代码中可以使用强类型作为参数和返回值，而不是使用`Variant`动态类型。使得`PHPX C++`代码可以像
`PHP`代码一样直观。

### `2.1` 版本
```cpp
var dsn = "mysql:dbname=test;host=127.0.0.1";
var user = "root";
var password = "root";

PDO dbh(dsn, user, password);
PDOStatement stmt = dbh.query("show tables", PDO::FETCH_NUM);

while (var result = stmt.fetch()) {
    var table_name = result.item(0);
    std::cout << table_name.toCString() << std::endl;
}
```

### 性能优化

所有 `Facade` 方法/函数使用线程局部变量缓存 `zend_function` 指针，避免每次调用时查询 `function_table`。
提高了性能。

---
## 核心类型系统

### 命名参数支持

`call()` 和 `newObject()` 新增 `zend_array *named_args` 参数，支持 `PHP 8` 命名参数调用。

```cpp
// 普通调用
php::call(func, {arg1, arg2});

// 带命名参数的调用
Array named_args;
named_args.set("mode", 0);
named_args.set("flags", ENT_QUOTES);
php::call(func, {str}, named_args.array());
```

### empty / exists 结果捕获

`empty()` 和 `exists()` 新增重载，支持同时获取中间检查结果。

```cpp
Variant result;
if (php::empty($data, {"key1", "key2"}, result)) {
    // result 包含最后一步的检查值
}
```

---

## Array 增强

### 反向迭代器

```cpp
Array arr{1, 2, 3, 4, 5};

// 反向遍历
for (auto it = arr.rbegin(); it != arr.rend(); it--) {
    std::cout << it.value().toInt() << std::endl;  // 5, 4, 3, 2, 1
}

// 支持含空洞的数组
Array sparse;
sparse.set(zend_ulong(0), Variant("a"));
sparse.set(zend_ulong(10), Variant("b"));
sparse.set(zend_ulong(20), Variant("c"));
// rbegin() 从 idx 20 开始反向遍历
```

### item — 矩阵式嵌套访问

```cpp
// 构建二维矩阵
auto arr = array_fill(0, row + 1, array_fill(0, col + 1, 0));
arr.item(1, true).item(1, true) = 99;  // arr[1][1] = 99
arr.item(2, true).item(0, true) = 88;  // arr[2][0] = 88

// 读取
int val = arr.item(1).item(1).toInt();  // 99
```

### offsetUnset 方法

```cpp
Array a{{"x", 1}, {"y", 2}, {"z", 3}};
a.offsetUnset("y");  // 删除键 "y"
// a 现在为 {"x": 1, "z": 3}
```

### toReference — 数组引用创建

```cpp
Array numbers{99, 10, 7};
auto ref = numbers.toReference();
sort(ref);                              // 通过引用原地排序
ASSERT_EQ(ref.offsetGet(0).toInt(), 7);  // 已排序
```

### ArrayItem 构造改进

`ArrayItem` 构造函数传入字符串 key 时改用 `zend_symtable_find` 查找，正确处理键名冲突。

---

## Object 增强

### getProperties() — 获取对象属性表

```cpp
auto obj = newObject("stdClass");
obj.set("name", "test");
obj.set("value", 42);

Array props = obj.getProperties();
ASSERT_EQ(props.count(), 2);

// 支持正向和反向遍历
for (auto it = props.rbegin(); it != props.rend(); it--) {
    // 反向遍历属性
}
```

### 命名参数构造对象

```cpp
// 带命名参数的对象构造
Array named;
named.set("flags", JSON_UNESCAPED_UNICODE);
auto obj = newObject("SomeClass", {arg1, arg2}, named.array());
```

---

## 调试信息栈

全新的调试信息栈跟踪机制，支持多层函数调用栈记录。

```cpp
// 启用调试信息（默认开启）
php::enableDebugInfo(true);

// 入栈：进入函数时记录
php::pushDebugFrame(__FILE__, __LINE__, "my_function");

// 更新栈顶位置（代码执行到新行时）
php::traceDebugInfo(__FILE__, __LINE__);

// 出栈：函数返回时调用
php::popDebugFrame();

// 禁用调试信息
php::enableDebugInfo(false);
```

`Debug` 模式下，`throwError` 和 `throwErrorIfOccurred` 宏会自动调用 `augmentException()` 将调试栈信息附加到异常中。

---

## 其他改进

- 新增 `MSVC` 编译器支持，提高 `Windows` 平台兼容性
- 添加 `phpx_compat.h` 处理 `Windows` 宏冲突
- `CMake` 构建设置优化以支持 `ZTS` 和非 `ZTS` `PHP` 版本
- `Box` 类型增强，新增 `type_info` 和 `extra_info` 属性
