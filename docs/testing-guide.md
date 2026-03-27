# 测试指南

本文档介绍 PHPX 项目的测试框架和测试方法。

## 测试目录结构

```
tests/
├── src/              # C++ 单元测试
│   ├── main.cpp      # 测试入口
│   ├── base.cpp      # 基础功能测试
│   ├── variant.cpp   # Variant 类型测试
│   ├── array.cpp     # Array 类型测试
│   ├── object.cpp    # Object 类型测试
│   └── ...           # 其他测试
├── ext/              # 扩展测试
│   ├── main.cpp      # 扩展示例
│   └── ...           # 扩展功能测试
├── include/          # 测试辅助文件
│   └── phpx_test.h   # 测试头文件
├── unit/             # 单元测试
└── bootstrap.php     # PHP 测试引导
```

---

## 测试框架

### Google Test

PHPX 使用 Google Test (GTest) 作为 C++ 单元测试框架。

#### 安装 GTest

```bash
# Ubuntu/Debian
sudo apt-get install libgtest-dev cmake
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib

# macOS
brew install googletest
```

#### 验证安装

```bash
php-config --includes  # 确保包含 GTest 路径
```

---

## 运行测试

### 编译测试程序

```bash
cd /home/swoole/workspace/projects/phpx
cmake .
make phpx-tests -j 4
```

### 执行测试

```bash
# 运行所有测试
./bin/phpx-tests

# 运行特定测试套件
./bin/phpx-tests --gtest_filter="base.*"
./bin/phpx-tests --gtest_filter="variant.*"
./bin/phpx-tests --gtest_filter="array.*"

# 运行单个测试
./bin/phpx-tests --gtest_filter="base.echo"

# 列出所有测试
./bin/phpx-tests --gtest_list_tests
```

### 测试输出格式

```bash
# 默认输出
./bin/phpx-tests

# 详细输出
./bin/phpx-tests --gtest_print_time=1

# XML 输出（用于 CI）
./bin/phpx-tests --gtest_output=xml:test_results.xml
```

---

## 测试代码结构

### 测试宏定义

```cpp
#include "phpx_test.h"
#include "phpx_func.h"

using namespace php;

// 测试套件定义
TEST(SuiteName, TestCaseName) {
    // 测试代码
}

// 带参数的测试
TEST_P(SuiteName, TestCaseName) {
    // 参数化测试代码
}

// 测试夹具
class SuiteName : public ::testing::Test {
protected:
    void SetUp() override {
        // 每个测试前执行
    }
    
    void TearDown() override {
        // 每个测试后执行
    }
};
```

### 断言宏

```cpp
// 布尔断言
ASSERT_TRUE(condition);
ASSERT_FALSE(condition);

// 相等断言
ASSERT_EQ(expected, actual);
ASSERT_NE(val1, val2);
ASSERT_LT(val1, val2);
ASSERT_LE(val1, val2);
ASSERT_GT(val1, val2);
ASSERT_GE(val1, val2);

// 字符串断言
ASSERT_STREQ(str1, str2);
ASSERT_STRCASEEQ(str1, str2);
ASSERT_STRNE(str1, str2);
ASSERT_STRCASENE(str1, str2);

// 浮点数断言（考虑精度）
ASSERT_FLOAT_EQ(expected, actual);
ASSERT_DOUBLE_EQ(expected, actual);
ASSERT_NEAR(val1, val2, abs_error);

// 异常断言
ASSERT_THROW(statement, exception_type);
ASSERT_NO_THROW(statement);
ASSERT_ANY_THROW(statement);

// 自定义失败
FAIL() << "Error message";
ADD_FAILURE() << "Warning message";
```

---

## 测试示例

### 1. 基础测试 (base.cpp)

```cpp
#include "phpx_test.h"
#include "phpx_func.h"

using namespace php;

// 测试错误输出
TEST(base, error) {
    error(E_WARNING, "php error: %s, ErrorCode: %d", "hello world", 1001);
}

// 测试常量获取
TEST(base, constant) {
    auto c = constant("PHP_VERSION");
    ASSERT_TRUE(c.isString());
    ASSERT_GT(c.length(), 3);
    ASSERT_STREQ(c.toCString(), PHP_VERSION);
}

// 测试多个常量操作
TEST(base, constant2) {
    // 定义常量
    define("IA", 6492);
    auto c = constant("IA");
    ASSERT_TRUE(c.isInt());
    ASSERT_EQ(c.toInt(), 6492);

    // 获取类常量（不存在）
    auto c3 = constant("DateTime", "XXTT2");
    ASSERT_TRUE(c3.isNull());

    // 尝试获取不存在的常量（应抛出异常）
    try_call([]() { 
        auto c4 = constant("XXTT3"); 
    }, "Undefined constant \"XXTT3\"");

    // 获取 PDO 类常量
    auto c4 = constant("PDO", "PARAM_STMT");
    ASSERT_EQ(c4.toInt(), 4);

    // 使用字符串语法
    auto c5 = constant("Pdo::PARAM_STMT");
    ASSERT_EQ(c5.toInt(), 4);

    // 使用类入口
    auto ce = getClassEntrySafe("PDO");
    auto c6 = constant(ce, "PARAM_STMT");
    ASSERT_EQ(c6.toInt(), 4);

    // 获取全局常量
    auto c7 = constant(nullptr, "PHP_VERSION");
    ASSERT_TRUE(c7.isString());
    ASSERT_GT(c7.length(), 3);

    // 获取不存在的类常量
    auto c8 = constant("PDO", "XXTT2");
    ASSERT_TRUE(c8.isNull());
}

// 测试输出函数
TEST(base, echo) {
    // 格式化输出
    echo("php error: %s, ErrorCode: %d\n", "hello world", 1001);

    // 字符串输出
    String s("hello world\n");
    echo(s);

    // 变量输出
    var b = 2026;
    echo(b);
    echo("\n");
    
    echo(1987L);
    echo("\n");
    
    echo(3.1415926);
    echo("\n");
}

// 测试常量定义
TEST(base, define) {
    // 定义字符串常量
    define("test_var1", PHP_VERSION);
    auto c = constant("test_var1");
    ASSERT_TRUE(c.isString());
    ASSERT_GT(c.length(), 0);
    ASSERT_STREQ(c.toCString(), PHP_VERSION);

    // 定义整数常量
    define("test_var2", PHP_VERSION_ID);
    c = constant("test_var2");
    ASSERT_TRUE(c.isInt());
    ASSERT_EQ(c.toInt(), PHP_VERSION_ID);

    // 定义数组常量
    Array array;
    array.set("PHP_MAJOR_VERSION", PHP_MAJOR_VERSION);
    array.set("PHP_MINOR_VERSION", PHP_MINOR_VERSION);
    define("test_var3", array);
    c = constant("test_var3");
    ASSERT_TRUE(c.isArray());
    ASSERT_EQ(c.length(), 2);

    // 验证数组内容
    Array arr2(c);
    ASSERT_EQ(arr2["PHP_MAJOR_VERSION"].toInt(), PHP_MAJOR_VERSION);
}
```

### 2. Variant 测试 (variant.cpp)

```cpp
#include "phpx_test.h"

using namespace php;

// 测试 Variant 构造
TEST(variant, constructor) {
    // 默认构造
    Variant v1;
    ASSERT_TRUE(v1.isNull());
    
    // 整数构造
    Variant v2 = 42;
    ASSERT_TRUE(v2.isInt());
    ASSERT_EQ(v2.toInt(), 42);
    
    // 浮点数构造
    Variant v3 = 3.14;
    ASSERT_TRUE(v3.isFloat());
    ASSERT_FLOAT_EQ(v3.toFloat(), 3.14);
    
    // 字符串构造
    Variant v4 = "hello";
    ASSERT_TRUE(v4.isString());
    ASSERT_STREQ(v4.toCString(), "hello");
    
    // 布尔构造
    Variant v5 = true;
    ASSERT_TRUE(v5.isBool());
    ASSERT_TRUE(v5.toBool());
}

// 测试类型转换
TEST(variant, type_conversion) {
    // 数字转字符串
    Variant num = 123;
    String str = num.toString();
    ASSERT_STREQ(str.data(), "123");
    
    // 字符串转数字
    Variant str_var = "456";
    ASSERT_TRUE(str_var.isNumeric());
    ASSERT_EQ(str_var.toInt(), 456);
    
    // 布尔转换
    Variant zero = 0;
    ASSERT_FALSE(zero.toBool());
    
    Variant non_zero = 100;
    ASSERT_TRUE(non_zero.toBool());
}

// 测试操作符重载
TEST(variant, operators) {
    Variant a = 10;
    Variant b = 3;
    
    // 算术运算
    ASSERT_EQ((a + b).toInt(), 13);
    ASSERT_EQ((a - b).toInt(), 7);
    ASSERT_EQ((a * b).toInt(), 30);
    ASSERT_EQ((a / b).toFloat(), 3.333333);
    ASSERT_EQ((a % b).toInt(), 1);
    
    // 复合赋值
    a += b;
    ASSERT_EQ(a.toInt(), 13);
    
    // 比较运算
    ASSERT_TRUE(a == b);
    ASSERT_TRUE(a > b);
    ASSERT_FALSE(a < b);
}

// 测试引用计数
TEST(variant, reference_counting) {
    Variant v1 = "test";
    ASSERT_EQ(v1.getRefCount(), 1);
    
    // 拷贝构造
    Variant v2 = v1;
    ASSERT_GE(v1.getRefCount(), 1);
    
    // 赋值
    Variant v3;
    v3 = v1;
    ASSERT_GE(v1.getRefCount(), 1);
}
```

### 3. Array 测试 (array.cpp)

```cpp
#include "phpx_test.h"

using namespace php;

// 测试数组创建
TEST(array, creation) {
    // 空数组
    Array arr1;
    ASSERT_EQ(arr1.count(), 0);
    
    // 指定大小
    Array arr2(10);
    ASSERT_GE(arr2.count(), 0);
    
    // 从列表初始化
    Array arr3 = {1, 2, 3, 4, 5};
    ASSERT_EQ(arr3.count(), 5);
}

// 测试元素访问
TEST(array, element_access) {
    Array arr;
    
    // 设置元素
    arr.set("name", "John");
    arr.set("age", 25);
    arr.append("item1");
    arr.append("item2");
    
    // 获取元素
    ASSERT_STREQ(arr["name"].toCString(), "John");
    ASSERT_EQ(arr["age"].toInt(), 25);
    ASSERT_STREQ(arr[0].toCString(), "item1");
    ASSERT_STREQ(arr[1].toCString(), "item2");
    
    // 检查存在性
    ASSERT_TRUE(arr.exists("name"));
    ASSERT_TRUE(arr.exists(0));
    ASSERT_FALSE(arr.exists("not_exists"));
}

// 测试数组操作
TEST(array, operations) {
    Array arr1 = {1, 2, 3};
    Array arr2 = {4, 5, 6};
    
    // 合并
    Array merged = arr1.merge(arr2);
    ASSERT_EQ(merged.count(), 6);
    
    // 推送和弹出
    arr1.push(4);
    ASSERT_EQ(arr1.count(), 4);
    
    Variant popped = arr1.pop();
    ASSERT_EQ(popped.toInt(), 4);
    ASSERT_EQ(arr1.count(), 3);
    
    // 切片
    Array sliced = arr1.slice(1, 2);
    ASSERT_EQ(sliced.count(), 2);
}

// 测试遍历
TEST(array, iteration) {
    Array arr;
    arr.set("a", 1);
    arr.set("b", 2);
    arr.set("c", 3);
    
    std::vector<std::pair<std::string, int>> results;
    
    arr.foreach([&results](Variant &key, Variant &value) {
        results.push_back({key.toStdString(), value.toInt()});
    });
    
    ASSERT_EQ(results.size(), 3);
}
```

### 4. Object 测试 (object.cpp)

```cpp
#include "phpx_test.h"

using namespace php;

// 测试对象创建
TEST(object, creation) {
    // 创建 stdClass
    Object obj = newObject("stdClass");
    ASSERT_STREQ(obj.getClassName().data(), "stdClass");
    
    // 创建 DateTime
    Object date = newObject("DateTime", {"2026-03-27"});
    ASSERT_STREQ(date.getClassName().data(), "DateTime");
}

// 测试属性访问
TEST(object, property_access) {
    Object obj = newObject("stdClass");
    
    // 设置属性
    obj.setProperty("name", "John");
    obj.setProperty("age", 25);
    
    // 获取属性
    ASSERT_STREQ(obj.getProperty("name").toCString(), "John");
    ASSERT_EQ(obj.getProperty("age").toInt(), 25);
    
    // 检查属性
    ASSERT_TRUE(obj.hasProperty("name"));
    ASSERT_FALSE(obj.hasProperty("not_exists"));
}

// 测试方法调用
TEST(object, method_call) {
    Object date = newObject("DateTime", {"2026-03-27 10:30:00"});
    
    // 调用方法
    Variant formatted = date.call("format", {"Y-m-d H:i:s"});
    ASSERT_STREQ(formatted.toCString(), "2026-03-27 10:30:00");
    
    // 调用带返回值的方法
    Variant timestamp = date.call("getTimestamp");
    ASSERT_TRUE(timestamp.isInt());
}

// 测试类型检查
TEST(object, type_checking) {
    Object date = newObject("DateTime");
    
    // instanceOf 检查
    ASSERT_TRUE(date.instanceOf("DateTime"));
    ASSERT_TRUE(date.instanceOf("DateTimeInterface"));
    ASSERT_FALSE(date.instanceOf("stdClass"));
}
```

### 5. 辅助函数测试 (helper.cpp)

```cpp
#include "phpx_test.h"
#include "phpx_helper.h"

using namespace php;

// 测试 INI 配置
TEST(helper, ini_get) {
    auto v = ini_get("post_max_size");
    ASSERT_GE(v.length(), 2);
    ASSERT_GE(v.toInt(), 8);
}

// 测试全局变量
TEST(helper, global) {
    // 获取 _SERVER
    auto server = global("_SERVER");
    ASSERT_TRUE(server.isArray());
    Array array(server);
    ASSERT_TRUE(array.exists("SHELL"));
    
    auto time = array["REQUEST_TIME"];
    ASSERT_TRUE(time.isInt());
    
    // 获取不存在的变量
    auto v2 = global("global_var_not_exists");
    ASSERT_FALSE(v2.toBool());
}

// 测试 eval
TEST(helper, eval) {
    ob_start();
    eval("print_r(PHP_VERSION);");
    auto rs = ob_get_clean();
    ASSERT_TRUE(rs.isString());
    ASSERT_TRUE(str_contains(rs, PHP_VERSION).toBool());
}

// 测试异常捕获
TEST(helper, exception) {
    bool done = false;
    
    try {
        auto e = newObject("RuntimeException", {"phpx error", 1999});
        throwException(e);
    } catch (zend_object *ex) {
        auto e = catchException();
        ASSERT_TRUE(e.getClassName().equals("RuntimeException"));
        done = true;
    }
    
    ASSERT_TRUE(done);
}
```

---

## 编写新测试

### 步骤

1. **创建测试文件**
```bash
touch tests/src/my_feature.cpp
```

2. **添加测试代码**
```cpp
#include "phpx_test.h"
#include "phpx_func.h"

using namespace php;

TEST(my_feature, basic_test) {
    // 测试代码
    Variant result = myFunction();
    ASSERT_TRUE(result.isString());
}

TEST(my_feature, advanced_test) {
    // 更复杂的测试
    Array input = {1, 2, 3};
    Array output = processArray(input);
    ASSERT_EQ(output.count(), 6);
}
```

3. **添加到 CMakeLists.txt**
```cmake
# tests/src/CMakeLists.txt 或主 CMakeLists.txt
file(GLOB_RECURSE TEST_FILES tests/src/*.cpp)
add_executable(phpx-tests ${TEST_FILES})
```

4. **编译并运行**
```bash
cmake .
make phpx-tests
./bin/phpx-tests --gtest_filter="my_feature.*"
```

### 测试模板

```cpp
#include "phpx_test.h"

using namespace php;

// 测试夹具（可选）
class MyFeatureTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 每个测试前执行
    }
    
    void TearDown() override {
        // 每个测试后执行
    }
};

// 简单测试
TEST(MyFeature, BasicTest) {
    // Arrange
    Variant input = createInput();
    
    // Act
    Variant result = process(input);
    
    // Assert
    ASSERT_TRUE(result.isExpectedType());
    EXPECT_EQ(result.getValue(), expectedValue);
}

// 参数化测试
class MyFeatureParamTest 
    : public MyFeatureTest, 
      public ::testing::WithParamInterface<int> {
};

TEST_P(MyFeatureParamTest, HandlesDifferentInput) {
    int param = GetParam();
    // 使用参数进行测试
    ASSERT_GE(process(param), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MyFeatureTests,
    MyFeatureParamTest,
    ::testing::Values(1, 2, 3, 4, 5)
);
```

---

## PHP 测试

### Bootstrap 文件

`tests/bootstrap.php`：
```php
<?php

declare(strict_types=1);

ini_set('display_errors', 'on');
ini_set('display_startup_errors', 'on');

error_reporting(E_ALL & ~E_DEPRECATED);
date_default_timezone_set('Asia/Shanghai');

!defined('BASE_PATH') && define('BASE_PATH', dirname(__DIR__, 1));

define('EXT_NAME', 'phpx_test');

require BASE_PATH . '/vendor/autoload.php';
```

### 运行 PHP 测试

```bash
# 使用 PHPUnit
vendor/bin/phpunit tests/

# 使用内置测试工具
php tests/run-tests.php
```

### 编写 PHP 测试

```php
<?php

namespace Phpx\Tests;

use PHPUnit\Framework\TestCase;

class ExtensionTest extends TestCase
{
    public function testExtensionLoaded(): void
    {
        $this->assertTrue(extension_loaded('phpx_test'));
    }
    
    public function testFunctionExists(): void
    {
        $this->assertTrue(function_exists('test_function'));
    }
    
    public function testFunctionBehavior(): void
    {
        $result = test_function('input');
        $this->assertEquals('expected', $result);
    }
}
```

---

## 测试覆盖率

### 生成覆盖率报告

```bash
# 启用覆盖率编译
cmake . -DCODE_COVERAGE=ON
make clean
make -j 4

# 运行测试
./bin/phpx-tests

# 生成覆盖率报告
gcov -o CMakeFiles/phpx-tests.dir/tests/src/ src/core/*.cc
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory coverage_html
```

### 查看覆盖率

```bash
# 在浏览器中打开
firefox coverage_html/index.html
```

---

## 持续集成

### GitHub Actions

`.github/workflows/test.yml`：
```yaml
name: Tests

on: [push, pull_request]

jobs:
  test:
    runs-on: ubuntu-latest
    
    steps:
    - uses: actions/checkout@v2
    
    - name: Install dependencies
      run: |
        sudo apt-get update
        sudo apt-get install -y php8.1-dev cmake g++ libgtest-dev
    
    - name: Build
      run: |
        cmake .
        make -j 4
    
    - name: Run tests
      run: |
        ./bin/phpx-tests --gtest_output=xml:test_results.xml
    
    - name: Upload test results
      uses: actions/upload-artifact@v2
      with:
        name: test-results
        path: test_results.xml
```

---

## 调试测试

### 使用 GDB

```bash
# 启动 gdb
gdb ./bin/phpx-tests

# 在 gdb 中运行
(gdb) run --gtest_filter="base.error"

# 如果崩溃，查看堆栈
(gdb) bt
```

### 使用 Valgrind

```bash
# 检查内存泄漏
valgrind --leak-check=full ./bin/phpx-tests

# 详细输出
valgrind --leak-check=full --show-leak-kinds=all ./bin/phpx-tests
```

---

## 最佳实践

### 1. 测试命名

```cpp
// 好的命名
TEST(user_validation, validates_email_format)
TEST(user_validation, rejects_invalid_email)
TEST(user_validation, handles_null_input)

// 避免模糊命名
TEST(test1, test)  // ❌
```

### 2. 测试独立性

```cpp
// ✅ 每个测试独立
TEST(suite, test1) {
    setup();
    // 测试代码
    teardown();
}

TEST(suite, test2) {
    setup();
    // 测试代码
    teardown();
}

// ❌ 测试间依赖
TEST(suite, test1) {
    // 设置状态
}

TEST(suite, test2) {
    // 依赖 test1 的状态
}
```

### 3. 测试边界条件

```cpp
TEST(array_edge_cases, empty_array) {
    Array arr;
    ASSERT_EQ(arr.count(), 0);
}

TEST(array_edge_cases, large_array) {
    Array arr(1000000);
    ASSERT_GE(arr.count(), 0);
}

TEST(array_edge_cases, negative_index) {
    Array arr = {1, 2, 3};
    // 测试负索引行为
}
```

### 4. 测试异常

```cpp
TEST(exception_tests, throws_on_invalid_input) {
    ASSERT_THROW({
        dangerousFunction(invalid_input);
    }, InvalidArgumentException);
}

TEST(exception_tests, no_throw_on_valid_input) {
    ASSERT_NO_THROW({
        safeFunction(valid_input);
    });
}
```

---

## 常见问题

### Q: 测试编译失败
```bash
# 清理重新编译
make clean
rm -rf CMakeCache.txt CMakeFiles/
cmake .
make phpx-tests
```

### Q: 测试段错误
```bash
# 使用 gdb 定位
gdb ./bin/phpx-tests
(gdb) run
(gdb) bt  # 查看崩溃堆栈
```

### Q: 如何跳过某些测试
```bash
# 使用过滤器
./bin/phpx-tests --gtest_filter="-slow_test.*"

# 禁用测试
TEST(DISABLED_suite, test) {
    // 这个测试不会被运行
}
```

---

*本文档最后更新：2026-03-27*
