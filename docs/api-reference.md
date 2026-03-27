# API 参考

本文档提供 PHPX 的完整 API 参考。

## 目录

- [核心类型](#核心类型)
  - [Variant](#variant)
  - [Array](#array)
  - [Object](#object)
  - [String](#string)
  - [Reference](#reference)
- [基础函数](#基础函数)
- [数组操作](#数组操作)
- [对象操作](#对象操作)
- [字符串处理](#字符串处理)
- [数学函数](#数学函数)
- [错误处理](#错误处理)

---

## 核心类型

### Variant

通用变量类型，可以存储任何 PHP 值。

#### 构造函数

```cpp
// 默认构造（空值）
Variant();

// 从整数构造
Variant(Int value);
Variant(int64_t value);

// 从浮点数构造
Variant(Float value);
Variant(double value);

// 从布尔值构造
Variant(bool value);

// 从字符串构造
Variant(const char *value);
Variant(const std::string &value);
Variant(zend_string *value);

// 从数组构造
Variant(const Array &value);

// 从对象构造
Variant(const Object &value);

// 从 zval 构造
Variant(zval *v, Ctor ctor);
Variant(const zval *v, Ctor ctor);

// 拷贝构造
Variant(const Variant &other);
```

#### 类型转换方法

```cpp
// 转换为整数
Int toInt() const;
int64_t toInt64() const;

// 转换为浮点数
Float toFloat() const;
double toDouble() const;

// 转换为字符串
String toString() const;
std::string toStdString() const;
const char *toCString() const;
zend_string *toStringValue() const;

// 转换为数组
Array toArray() const;

// 转换为对象
Object toObject() const;
Object toObject(const String &className) const;

// 转换为布尔值
Bool toBool() const;

// 转换为引用
Reference toReference();
```

#### 类型检查方法

```cpp
// 基本类型检查
bool isNull() const;
bool isBool() const;
bool isTrue() const;
bool isFalse() const;
bool isInt() const;
bool isFloat() const;
bool isDouble() const;
bool isString() const;
bool isArray() const;
bool isObject() const;
bool isResource() const;
bool isReference() const;

// 特殊类型检查
bool isIndirect() const;
bool isCallable() const;
bool isIterable() const;
bool isScalar() const;
bool isEmpty() const;

// 数值检查
bool isNumeric() const;
bool isNaN() const;
bool isInf() const;
```

#### 操作符重载

```cpp
// 赋值操作符
Variant &operator=(const Variant &other);
Variant &operator=(const zval *v);
Variant &operator=(zval *v);
Variant &operator=(Variant *v);

// 算术操作符
Variant operator+(const Variant &other) const;
Variant operator-(const Variant &other) const;
Variant operator*(const Variant &other) const;
Variant operator/(const Variant &other) const;
Variant operator%(const Variant &other) const;
Variant operator-() const;  // 负号

// 复合赋值操作符
Variant &operator+=(const Variant &other);
Variant &operator-=(const Variant &other);
Variant &operator*=(const Variant &other);
Variant &operator/=(const Variant &other);
Variant &operator%=(const Variant &other);

// 比较操作符
bool operator==(const Variant &other) const;
bool operator!=(const Variant &other) const;
bool operator<(const Variant &other) const;
bool operator<=(const Variant &other) const;
bool operator>(const Variant &other) const;
bool operator>=(const Variant &other) const;

// 数组访问操作符
Variant operator[](const Variant &offset) const;
Reference operator[](const Variant &offset);
```

#### 其他方法

```cpp
// 获取长度
size_t length() const;

// 获取引用计数
int getRefCount() const;

// 销毁变量
void unset();

// 调试输出
void debug();
void print() const;

// 获取底层 zval
zval *ptr();
const zval *ptr() const;
const zval *const_ptr() const;
zval *unwrap_ptr() const;
```

#### 使用示例

```cpp
// 创建变量
Variant v1;              // null
Variant v2 = 42;         // integer
Variant v3 = 3.14;       // float
Variant v4 = "hello";    // string
Variant v5 = true;       // boolean

// 类型检查
if (v2.isInt()) {
    echo("Integer: %ld\n", v2.toInt());
}

// 类型转换
String str = v4.toString();
Int num = v2.toInt();

// 算术运算
Variant result = v2 + 10;  // 52

// 比较
if (v2 == 42) {
    echo("Answer to life\n");
}
```

---

### Array

PHP 数组的 C++ 封装。

#### 构造函数

```cpp
// 默认构造（空数组）
Array();

// 指定初始大小
Array(size_t size);

// 从 Variant 构造
Array(const Variant &value);

// 从 zend_array 构造
Array(zend_array *arr, Ctor ctor);
Array(const zend_array *arr, Ctor ctor);
```

#### 元素访问

```cpp
// 获取元素
Variant offsetGet(const Variant &offset);
Variant operator[](const Variant &offset);
const Variant operator[](const Variant &offset) const;

// 设置元素
void offsetSet(const Variant &offset, const Variant &value);
void operator[](const Variant &offset) = const Variant &value;

// 检查元素是否存在
bool offsetExists(const Variant &offset);
bool exists(const Variant &offset) const;

// 删除元素
void offsetUnset(const Variant &offset);
```

#### 数组操作

```cpp
// 获取数组大小
size_t count() const;
size_t length() const;

// 合并数组
Array merge(const Array &other) const;

// 追加元素
void append(const Variant &value);
void push(const Variant &value);

// 弹出元素
Variant pop();
Variant shift();

// 获取键名
Array keys() const;

// 获取值
Array values() const;

// 反转数组
Array reverse() const;

// 切片
Array slice(long offset, long length = 0) const;
```

#### 遍历

```cpp
// 使用 foreach
void foreach(std::function<void(Variant &key, Variant &value)> func);

// 获取迭代器
zend_array_iterator *getIterator() const;
```

#### 其他方法

```cpp
// 获取底层 zend_array
zend_array *ptr();
const zend_array *ptr() const;

// 增加引用计数
void addRef();

// 减少引用计数
void release();

// 分离数组（写时复制）
void separate();

// 是否为空
bool isEmpty() const;

// 排序
void sort();
void rsort();
void ksort();
void asort();
```

#### 使用示例

```cpp
// 创建数组
Array arr;
arr.set("name", "John");
arr.set("age", 25);
arr.append("item1");
arr.append("item2");

// 访问元素
Variant name = arr["name"];
Variant age = arr.offsetGet("age");

// 修改元素
arr["age"] = 26;

// 遍历
arr.foreach([](Variant &key, Variant &value) {
    echo("%s: ", key.toString().data());
    value.print();
});

// 数组合并
Array arr2;
arr2.set("city", "Beijing");
Array merged = arr.merge(arr2);

// 切片
Array sliced = arr.slice(1, 2);
```

---

### Object

PHP 对象的 C++ 封装。

#### 构造函数

```cpp
// 默认构造
Object();

// 从 Variant 构造
Object(const Variant &value);

// 从 zend_object 构造
Object(zend_object *obj, Ctor ctor);
Object(const zend_object *obj, Ctor ctor);
```

#### 静态方法

```cpp
// 创建新对象
static Object newObject(const String &className, Args args = {});
static Object newObject(zend_class_entry *ce, Args args = {});

// 获取类入口
static zend_class_entry *getClassEntry(const String &className);
```

#### 属性访问

```cpp
// 获取属性
Variant getProperty(const String &name);
Variant operator[](const String &name);

// 设置属性
void setProperty(const String &name, const Variant &value);
void operator[](const String &name) = const Variant &value;

// 检查属性是否存在
bool hasProperty(const String &name) const;
bool propertyExists(const String &name) const;

// 删除属性
void unsetProperty(const String &name);

// 获取静态属性
static Variant getStaticProperty(const String &className, const String &prop);
static Variant getStaticProperty(zend_class_entry *ce, uint32_t offset);
static bool setStaticProperty(const String &className, const String &prop, const Variant &value);
```

#### 方法调用

```cpp
// 调用实例方法
Variant call(const String &method, Args args = {});
Variant call(const String &method, const ArgList &args);

// 调用静态方法
static Variant callStatic(const String &className, const String &method, Args args = {});
Variant callStatic(const String &method, Args args = {});

// 调用魔术方法
Variant __call(const String &method, Args args);
```

#### 类信息

```cpp
// 获取类名
String getClassName() const;

// 获取类入口
zend_class_entry *getClassEntry() const;

// 检查是否是类的实例
bool instanceOf(const String &className) const;
bool instanceof(zend_class_entry *ce) const;

// 获取父类
Object getParentClass() const;

// 获取接口
Array getInterfaceNames() const;
```

#### 其他方法

```cpp
// 获取引用计数
int getRefCount() const;

// 获取句柄
zend_object_handle getHandle() const;

// 克隆对象
Object clone() const;

// 获取底层对象
zend_object *ptr();
const zend_object *ptr() const;
```

#### 使用示例

```cpp
// 创建对象
Object date = newObject("DateTime", {"2026-03-27"});

// 设置属性
date.setProperty("timezone", "Asia/Shanghai");

// 获取属性
Variant tz = date.getProperty("timezone");

// 调用方法
Variant formatted = date.call("format", {"Y-m-d H:i:s"});

// 检查类型
if (date.instanceOf("DateTime")) {
    echo("Is DateTime\n");
}

// 调用静态方法
Variant staticResult = Object::callStatic("DateTime", "createFromFormat", {"Y-m-d", "2026-03-27"});
```

---

### String

PHP 字符串的 C++ 封装。

#### 构造函数

```cpp
// 默认构造（空字符串）
String();

// 从 C 字符串构造
String(const char *s);
String(const char *s, size_t len);

// 从 std::string 构造
String(const std::string &s);

// 从 zend_string 构造
String(zend_string *str, Ctor ctor);
```

#### 访问方法

```cpp
// 获取数据
const char *data() const;
char *data();

// 获取长度
size_t length() const;

// 转换为 C 字符串
const char *c_str() const;

// 转换为 std::string
std::string toStdString() const;

// 转换为 zend_string
zend_string *toStringValue() const;
```

#### 字符串操作

```cpp
// 连接
String concat(const String &other) const;
String operator+(const String &other) const;

// 子串
String substr(size_t start, size_t length = -1) const;

// 查找位置
Int strpos(const String &needle, size_t offset = 0) const;
Int stripos(const String &needle, size_t offset = 0) const;

// 替换
String replace(const String &search, const String &replace) const;

// 大小写转换
String strtoupper() const;
String strtolower() const;
String ucfirst() const;
String ucwords() const;

// 修剪
String trim() const;
String ltrim() const;
String rtrim() const;
String trim(const String &character_mask) const;
```

#### 类型转换

```cpp
// 转换为数值
Int toInt() const;
Float toFloat() const;
Double toDouble() const;

// 数值格式化
String numberFormat(int decimals = 0, 
                   const String &dec_point = ".", 
                   const String &thousands_sep = ",") const;
```

#### 其他方法

```cpp
// 重复字符串
String repeat(size_t multiplier) const;

// 反转字符串
String strrev() const;

// 填充字符串
String pad(int len, const String &pad_string = " ", int pad_type = STR_PAD_RIGHT) const;

// 分割数组
Array explode(const String &delimiter) const;

// 获取字符
String chr(size_t index) const;
Int ord(size_t index = 0) const;
```

#### 使用示例

```cpp
// 创建字符串
String str = "Hello World";

// 字符串操作
String upper = str.strtoupper();  // "HELLO WORLD"
String lower = str.strtolower();  // "hello world"
String sub = str.substr(0, 5);    // "Hello"

// 查找
Int pos = str.strpos("World");    // 6

// 替换
String replaced = str.replace("World", "PHPX");  // "Hello PHPX"

// 连接
String greeting = str + " from PHPX!";

// 分割
Array parts = str.explode(" ");  // ["Hello", "World"]
```

---

### Reference

PHP 引用的封装。

#### 构造函数

```cpp
// 从 Variant 构造
Reference(const Variant &value);

// 从 zval 构造
Reference(zval *value);
```

#### 方法

```cpp
// 获取引用值
Variant getValue() const;

// 设置引用值
void setValue(const Variant &value);

// 获取底层 zval
zval *ptr();
const zval *ptr() const;

// 转换为 Variant
operator Variant() const;
```

#### 使用示例

```cpp
// 创建引用
Variant var = 100;
Reference ref = var.toReference();

// 修改引用值
ref.setValue(200);
echo(var.toInt());  // 输出 200

// 通过引用传递
function test(Reference param) {
    param.setValue(param.getValue() + 1);
}
```

---

## 基础函数

### 输出函数

```cpp
// 格式化输出
void echo(const char *format, ...);
void echo(const String &str);
void echo(const Variant &val);
void echo(Int val);
void echo(Float val);

// 打印变量
void var_dump(const Variant &var);
void print_r(const Variant &var);
```

### 全局变量

```cpp
// 获取全局变量
Variant global(const String &name);

// 初始化全局变量
void initGlobal(const String &name, Variant &var);

// 删除全局变量
void unsetGlobal(const String &name);
```

### 常量操作

```cpp
// 获取常量
Variant constant(const String &name);
Variant constant(const String &cls, const String &name);
Variant constant(zend_class_entry *ce, const String &name);

// 定义常量
void define(const String &name, const Variant &value);
```

### 包含文件

```cpp
// 包含文件
Variant include(const String &file, IncludeType type = INCLUDE);
Variant eval(const String &script);

// 包含类型
enum IncludeType {
    INCLUDE = ZEND_INCLUDE,
    INCLUDE_ONCE = ZEND_INCLUDE_ONCE,
    REQUIRE = ZEND_REQUIRE,
    REQUIRE_ONCE = ZEND_REQUIRE_ONCE,
};
```

### 函数调用

```cpp
// 调用 PHP 函数
Variant call(const Variant &func, Args &args);
Variant call(const Variant &func, Array &args);
Variant call(const Variant &func, const ArgList &args);

// 调用 zend_function
Variant call(zend_function *func);
Variant call(zend_function *func, Args &_args);
Variant call(zend_function *func, Array &args);
Variant call(zend_function *func, const ArgList &args);

// 调用类方法
Variant call(zend_class_entry *ce, zend_function *func);
Variant call(zend_class_entry *ce, zend_function *func, const ArgList &args);
```

### 退出

```cpp
// 退出程序
void exit(const Variant &status);
```

---

## 数组操作

### 创建数组

```cpp
// 创建空数组
Array arr;

// 创建指定大小的数组
Array arr(10);

// 使用初始化列表
Array arr = {1, 2, 3, 4, 5};
```

### 添加元素

```cpp
// 关联数组
arr.set("key", "value");
arr["name"] = "John";

// 索引数组
arr.append("item");
arr.push(100);

// 批量添加
arr.merge({{"a", 1}, {"b", 2}});
```

### 删除元素

```cpp
// 删除指定元素
arr.offsetUnset("key");
arr.pop();
arr.shift();
```

### 数组排序

```cpp
// 索引排序
arr.sort();   // 升序
arr.rsort();  // 降序

// 键名排序
arr.ksort();  // 按键名升序
arr.asort();  // 按值升序
```

### 数组切片

```cpp
// 获取切片
Array sliced = arr.slice(0, 5);  // 前 5 个元素
Array last = arr.slice(-3);      // 最后 3 个元素
```

---

## 对象操作

### 创建对象

```cpp
// 创建内置类对象
Object date = newObject("DateTime", {"2026-03-27"});
Object arrayObj = newObject("ArrayObject", {arr});

// 创建自定义类对象
Object myObj = newObject("MyClass", {param1, param2});
```

### 属性访问

```cpp
// 读取属性
Variant value = obj.getProperty("name");
Variant value = obj["property"];

// 设置属性
obj.setProperty("name", "value");
obj["property"] = newValue;

// 检查属性
if (obj.hasProperty("name")) {
    // ...
}
```

### 方法调用

```cpp
// 调用实例方法
Variant result = obj.call("methodName", {arg1, arg2});

// 调用静态方法
Variant result = Object::callStatic("ClassName", "staticMethod", {args});
```

---

## 字符串处理

### 字符串连接

```cpp
String str1 = "Hello";
String str2 = "World";

// 使用 + 操作符
String result = str1 + " " + str2;

// 使用 concat 方法
String result = str1.concat(" ").concat(str2);
```

### 字符串查找

```cpp
String str = "Hello World";

// 查找位置
Int pos = str.strpos("World");     // 6
Int pos = str.stripos("world");    // 6 (不区分大小写)

// 查找最后一次出现
Int pos = str.strrpos("o");        // 7
```

### 字符串修改

```cpp
String str = "  Hello World  ";

// 修剪
String trimmed = str.trim();       // "Hello World"
String leftTrimmed = str.ltrim();  // "Hello World  "
String rightTrimmed = str.rtrim(); // "  Hello World"

// 大小写
String upper = str.strtoupper();   // "  HELLO WORLD  "
String lower = str.strtolower();   // "  hello world  "

// 首字母大写
String ucfirst_result = str.ucfirst();  // "  Hello World  "
String ucwords_result = str.ucwords();  // "  Hello World  "
```

### 字符串替换

```cpp
String str = "Hello World";

// 简单替换
String replaced = str.replace("World", "PHPX");

// 子串
String sub = str.substr(0, 5);  // "Hello"
```

---

## 数学函数

### 基本运算

```cpp
Variant a = 10;
Variant b = 3;

// 加减乘除
Variant sum = a + b;        // 13
Variant diff = a - b;       // 7
Variant prod = a * b;       // 30
Variant quot = a / b;       // 3.333...
Variant mod = a % b;        // 1

// 复合赋值
a += b;  // 13
a -= b;  // 7
a *= b;  // 30
a /= b;  // 3.333...
```

### 数学函数

```cpp
// 绝对值
Variant abs = Variant(-10).abs();  // 10

// 取整
Variant rounded = Variant(3.7).round();  // 4
Variant floored = Variant(3.7).floor();  // 3
Variant ceiled = Variant(3.2).ceil();    // 4

// 幂运算
Variant pow = Variant(2).pow(3);  // 8
Variant sqrt = Variant(16).sqrt();// 4

// 三角函数
Variant sin_val = Variant(0).sin();  // 0
Variant cos_val = Variant(0).cos();  // 1
Variant tan_val = Variant(0).tan();  // 0
```

### 随机数

```cpp
// 生成随机整数
Variant rand = random_int(1, 100);

// 生成随机浮点数
Variant rand_float = random_float(0.0, 1.0);
```

---

## 错误处理

### 抛出异常

```cpp
// 抛出错误
throwError("Something went wrong");
throwError("Invalid parameter: %s", param);

// 抛出特定异常
throwException("RuntimeException", "Error message", error_code);
throwException("InvalidArgumentException", "Invalid argument");
```

### 捕获异常

```cpp
try {
    // 可能抛出异常的代码
    riskyOperation();
} catch (zend_object *ex) {
    // 捕获异常
    Object e = catchException();
    echo(e.getProperty("message").toString());
    echo(e.getProperty("code").toInt());
}
```

### 条件抛出

```cpp
// 如果已发生异常则抛出
throwErrorIfOccurred();

// 尝试执行，失败回退
try_call([]() {
    constant("NOT_EXISTS");
}, "Fallback value");
```

---

## 调试 API

### 变量调试

```cpp
Variant var = getValue();

// 打印调试信息
var.debug();

// 使用 var_dump 格式
var.print();
```

### 引用计数

```cpp
// 获取引用计数
int rc = var.getRefCount();

// 检查是否为引用
if (var.isReference()) {
    // 处理引用
}
```

### 调试模式

```cpp
// 启用调试模式
enableDebugInfo(true);

// 跟踪位置
traceDebugInfo(__FILE__, __LINE__);
```

---

*本文档最后更新：2026-03-27*
