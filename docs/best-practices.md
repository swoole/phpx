# 最佳实践

本文档总结 PHPX 开发中的最佳实践、常见陷阱和性能优化技巧。

## 目录

- [代码组织](#代码组织)
- [内存管理](#内存管理)
- [错误处理](#错误处理)
- [性能优化](#性能优化)
- [调试技巧](#调试技巧)
- [测试策略](#测试策略)
- [安全考虑](#安全考虑)
- [常见问题](#常见问题)

---

## 代码组织

### 1. 文件结构

推荐的项目结构：

```
myext/
├── src/
│   ├── myext.cc          # 扩展入口
│   ├── functions/        # 函数实现
│   │   ├── string.cc
│   │   ├── array.cc
│   │   └── math.cc
│   ├── classes/          # 类实现
│   │   ├── MyClass.cc
│   │   └── YourClass.cc
│   └── helpers/          # 辅助函数
│       └── utils.cc
├── include/
│   ├── myext.h           # 主头文件
│   ├── functions.h
│   ├── classes.h
│   └── utils.h
├── tests/                # 测试代码
├── examples/             # 示例代码
└── CMakeLists.txt        # 构建配置
```

### 2. 命名规范

#### 函数命名
```cpp
// ✅ 使用小写字母和下划线
PHPX_FUNCTION(my_function);
PHPX_FUNCTION(array_helper);
PHPX_FUNCTION(process_data);

// ❌ 避免驼峰命名
PHPX_FUNCTION(myFunction);  // 不推荐
```

#### 类命名
```cpp
// ✅ 使用大写字母开头
class MyClass : public Class {
    // ...
};

// 注册时使用驼峰
ext.registerClass(new MyClass("MyClass"));
```

#### 变量命名
```cpp
// ✅ 使用驼峰命名
Variant myVariable;
Array dataList;
Object userObject;

// ✅ 使用有意义的名称
Variant userAge;      // ✅
Variant ua;           // ❌
```

### 3. 代码注释

```cpp
/**
 * 处理用户数据
 * 
 * @param args[0] string 用户名
 * @param args[1] int 年龄
 * @return Variant 处理后的用户对象
 * 
 * @throws InvalidArgumentException 参数无效时
 */
PHPX_FUNCTION(process_user) {
    // 参数验证
    if (args.size() < 2) {
        throwError("Expected 2 parameters");
        return;
    }
    
    String name = args[0].toString();
    Int age = args[1].toInt();
    
    // 业务逻辑
    Object user = createUser(name, age);
    
    return user;
}
```

---

## 内存管理

### 1. 智能指针使用

```cpp
// ✅ 使用 RAII 管理资源
void example() {
    std::unique_ptr<Resource> res(createResource());
    // 自动释放，无需手动 delete
}

// ✅ 使用 shared_ptr 共享所有权
std::shared_ptr<Data> data1 = std::make_shared<Data>();
std::shared_ptr<Data> data2 = data1;  // 引用计数增加
```

### 2. Variant 使用注意事项

```cpp
// ✅ 正确的 Variant 使用
void good_example() {
    Variant var = "hello";
    echo(var.toString());
    // 析构时自动释放
}

// ❌ 避免内存泄漏
void bad_example() {
    zval *zv = new zval;  // 手动分配
    ZVAL_STRING(zv, "test");
    // 忘记释放 - 内存泄漏！
}

// ✅ 如果必须使用原始 zval
void safe_zval_usage() {
    zval zv;
    ZVAL_STRING(&zv, "test");
    // 使用完后释放
    zval_ptr_dtor(&zv);
}
```

### 3. 引用计数管理

```cpp
// ✅ 理解引用计数
void reference_counting() {
    Variant var1 = "hello";  // refcount = 1
    Variant var2 = var1;     // refcount = 2
    
    var1.unset();            // refcount = 1
    // var2 仍然有效
}

// ⚠️ 注意循环引用
void circular_reference() {
    Array arr1;
    Array arr2;
    
    arr1.set("child", arr2);  // arr2 refcount++
    arr2.set("parent", arr1); // arr1 refcount++
    // 可能导致内存泄漏
}
```

### 4. 字符串处理

```cpp
// ✅ 使用 String 类
String str = "hello world";
echo(str.data());

// ✅ 长字符串使用 std::string
std::string long_str = createLongString();
Variant var = long_str.c_str();

// ⚠️ 注意字符串生命周期
void string_lifetime() {
    const char *data;
    {
        String temp = "temporary";
        data = temp.data();  // ⚠️ temp 销毁后 data 无效
    }
    echo(data);  // ❌ 未定义行为
}
```

---

## 错误处理

### 1. 参数验证

```cpp
PHPX_FUNCTION(validate_params) {
    // 检查参数数量
    if (args.size() < 1) {
        throwError("At least one parameter required");
        return;
    }
    
    // 检查参数类型
    if (!args[0].isString()) {
        throwError("Parameter 1 must be string");
        return;
    }
    
    if (!args[1].isInt()) {
        throwError("Parameter 2 must be integer");
        return;
    }
    
    // 检查参数范围
    Int value = args[1].toInt();
    if (value < 0 || value > 100) {
        throwError("Parameter 2 must be between 0 and 100");
        return;
    }
    
    // 检查空值
    if (args[0].length() == 0) {
        throwError("Parameter 1 cannot be empty");
        return;
    }
    
    // 正常处理
    process(args[0], args[1]);
}
```

### 2. 异常抛出策略

```cpp
// ✅ 使用具体的异常类型
void throw_specific_exception() {
    if (invalid_argument) {
        throwException(
            "InvalidArgumentException", 
            "Invalid argument provided"
        );
    } else if (not_found) {
        throwException(
            "RuntimeException", 
            "Resource not found"
        );
    }
}

// ✅ 提供有用的错误信息
void informative_error() {
    String param = args[0].toString();
    throwError(
        "User '%s' not found in database", 
        param.data()
    );
}

// ❌ 避免模糊的错误信息
void vague_error() {
    throwError("Error occurred");  // ❌ 无用信息
}
```

### 3. 错误恢复

```cpp
// ✅ 尝试 - 回退模式
PHPX_FUNCTION(safe_operation) {
    try {
        return riskyOperation();
    } catch (zend_object *ex) {
        // 记录错误
        error(E_WARNING, "Operation failed, using fallback");
        
        // 回退到默认值
        return getDefaultValue();
    }
}

// ✅ 条件执行
PHPX_FUNCTION(conditional_exec) {
    if (canExecuteSafely()) {
        execute();
    } else {
        throwError("Cannot execute safely");
    }
}
```

---

## 性能优化

### 1. 避免不必要的拷贝

```cpp
// ✅ 使用引用传递
void processLargeData(const Variant &data) {
    // 不会复制数据
    String str = data.toString();
}

// ❌ 值传递会复制
void processLargeDataBad(Variant data) {
    // 会复制整个数据
}

// ✅ 使用 move 语义
Variant createData() {
    Variant result = generateData();
    return result;  // RVO 优化
}
```

### 2. 缓存常用对象

```cpp
// ✅ 缓存类入口
static zend_class_entry *cached_ce = nullptr;

if (!cached_ce) {
    cached_ce = getClassEntry("DateTime");
}

Object date = newObject(cached_ce);

// ✅ 缓存函数
static zend_function *cached_func = nullptr;

if (!cached_func) {
    cached_func = findFunction("strlen");
}

Variant result = call(cached_func, args);
```

### 3. 批量操作

```cpp
// ✅ 预分配数组大小
Array createLargeArray() {
    Array arr(1000);  // 预分配空间
    
    for (int i = 0; i < 1000; i++) {
        arr.set(i, i * 2);
    }
    
    return arr;
}

// ✅ 批量插入数据库
void batchInsert(const Array &items) {
    startTransaction();
    
    for (const auto &item : items) {
        insertItem(item);
    }
    
    commit();  // 一次提交，而不是每次插入都提交
}
```

### 4. 减少类型转换

```cpp
// ✅ 直接使用正确类型
Variant num = 42;  // 直接创建整数

// ❌ 避免字符串转数字
Variant num_bad = "42";  // 创建字符串
Int val = num_bad.toInt();  // 需要转换

// ✅ 复用变量
void reuse_variables() {
    Variant buffer;
    
    for (int i = 0; i < 100; i++) {
        buffer = i;  // 复用已有变量
        process(buffer);
    }
}
```

### 5. 延迟加载

```cpp
// ✅ 只在需要时计算
class LazyLoader {
private:
    mutable Variant cached_data;
    mutable bool loaded = false;
    
public:
    Variant getData() const {
        if (!loaded) {
            cached_data = expensiveComputation();
            loaded = true;
        }
        return cached_data;
    }
};
```

---

## 调试技巧

### 1. 使用调试宏

```cpp
// ✅ 启用调试模式
enableDebugInfo(true);

// ✅ 输出变量信息
void debug_example() {
    Variant var = getValue();
    
    printf("Type: %d\n", var.type());
    printf("Refcount: %d\n", var.getRefCount());
    
    var.debug();  // 输出详细信息
    var.print();  // var_dump 格式
}
```

### 2. 日志记录

```cpp
// ✅ 分级日志
#define LOG_DEBUG(fmt, ...) \
    error(E_NOTICE, "[DEBUG] " fmt, ##__VA_ARGS__)

#define LOG_INFO(fmt, ...) \
    error(E_INFO, "[INFO] " fmt, ##__VA_ARGS__)

#define LOG_ERROR(fmt, ...) \
    error(E_ERROR, "[ERROR] " fmt, ##__VA_ARGS__)

void example() {
    LOG_DEBUG("Starting function with param=%s", param.data());
    
    // ... 业务逻辑
    
    LOG_INFO("Function completed");
}
```

### 3. 性能分析

```cpp
// ✅ 测量执行时间
#include <chrono>

void profile_function() {
    auto start = std::chrono::high_resolution_clock::now();
    
    // 要测量的代码
    processData();
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
        end - start
    );
    
    LOG_INFO("Execution time: %ld μs", duration.count());
}
```

---

## 测试策略

### 1. 单元测试

```cpp
// ✅ 测试边界条件
TEST(array_test, boundary_conditions) {
    Array arr;
    
    // 空数组
    ASSERT_EQ(arr.count(), 0);
    
    // 单个元素
    arr.append(1);
    ASSERT_EQ(arr.count(), 1);
    
    // 大量元素
    for (int i = 0; i < 10000; i++) {
        arr.append(i);
    }
    ASSERT_GE(arr.count(), 10000);
}

// ✅ 测试异常情况
TEST(divide_test, division_by_zero) {
    ASSERT_THROW({
        divide(10, 0);
    }, InvalidArgumentException);
}
```

### 2. 集成测试

```php
<?php
// ✅ 测试完整流程
class IntegrationTest extends TestCase {
    public function testFullWorkflow() {
        // 创建用户
        $userId = create_user('john', 25);
        
        // 获取用户
        $user = get_user($userId);
        $this->assertEquals('john', $user['name']);
        
        // 更新用户
        update_user($userId, ['age' => 26]);
        
        // 验证更新
        $user = get_user($userId);
        $this->assertEquals(26, $user['age']);
        
        // 删除用户
        delete_user($userId);
        
        // 验证删除
        $this->assertNull(get_user($userId));
    }
}
```

### 3. 性能测试

```cpp
// ✅ 基准测试
TEST(performance_test, array_operations) {
    Array arr;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < 100000; i++) {
        arr.append(i);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
        end - start
    );
    
    printf("Append 100k items: %ld ms\n", duration.count());
    ASSERT_LT(duration.count(), 1000);  // 应该小于 1 秒
}
```

---

## 安全考虑

### 1. 输入验证

```cpp
// ✅ 严格验证所有输入
PHPX_FUNCTION(safe_function) {
    // 类型检查
    if (!args[0].isString()) {
        throwError("Parameter must be string");
        return;
    }
    
    // 长度检查
    String input = args[0].toString();
    if (input.length() > MAX_LENGTH) {
        throwError("Input too long");
        return;
    }
    
    // 内容检查
    if (!isValidFormat(input)) {
        throwError("Invalid input format");
        return;
    }
    
    // SQL 注入防护
    String sanitized = escapeSql(input);
    executeQuery(sanitized);
}
```

### 2. 资源限制

```cpp
// ✅ 限制资源使用
PHPX_FUNCTION(read_file) {
    String filename = args[0].toString();
    
    // 检查文件大小
    struct stat st;
    if (stat(filename.data(), &st) != 0) {
        throwError("File not found");
        return;
    }
    
    if (st.st_size > MAX_FILE_SIZE) {
        throwError("File too large");
        return;
    }
    
    // 读取文件
    String content = file_get_contents(filename);
    return content;
}
```

### 3. 内存限制

```cpp
// ✅ 检查内存使用
void* safe_alloc(size_t size) {
    static size_t total_allocated = 0;
    
    if (total_allocated + size > MAX_MEMORY) {
        throwError("Memory limit exceeded");
        return nullptr;
    }
    
    void *ptr = malloc(size);
    if (ptr) {
        total_allocated += size;
    }
    
    return ptr;
}
```

---

## 常见问题

### Q1: 段错误（Segmentation Fault）

**原因：**
- 访问已释放的内存
- 空指针解引用
- 数组越界

**解决方法：**
```bash
# 使用 gdb 调试
gdb php core.php
(gdb) run
(gdb) bt  # 查看堆栈

# 使用 valgrind 检查
valgrind --leak-check=full php test.php
```

### Q2: 内存泄漏

**检测：**
```bash
valgrind --leak-check=full --show-leak-kinds=all php test.php
```

**预防：**
```cpp
// ✅ 使用 RAII
void safe_function() {
    Variant var = createValue();
    // 自动释放
}

// ❌ 手动管理容易泄漏
void unsafe_function() {
    zval *zv = new zval;
    // 忘记 delete
}
```

### Q3: 引用计数问题

**症状：**
- 变量意外改变
- 数据损坏

**解决：**
```cpp
// ✅ 正确复制
Variant copy = original;  // 增加引用计数

// ✅ 分离副本
zval_copy_ctor(&dest);
```

### Q4: 线程安全问题

**检查：**
```bash
php -i | grep "Thread Safety"
```

**处理：**
```cpp
#ifdef ZTS
#define THREAD_LOCAL thread_local
#else
#define THREAD_LOCAL
#endif

THREAD_LOCAL static int counter = 0;
```

---

## 代码审查清单

### 功能性
- [ ] 参数验证完整
- [ ] 错误处理适当
- [ ] 返回值正确
- [ ] 边界条件处理

### 性能
- [ ] 无不必要的拷贝
- [ ] 使用了缓存
- [ ] 批量操作优化
- [ ] 无内存泄漏

### 安全
- [ ] 输入已验证
- [ ] SQL 已转义
- [ ] 路径已清理
- [ ] 资源有限制

### 可维护性
- [ ] 代码有注释
- [ ] 命名清晰
- [ ] 函数简短
- [ ] 有单元测试

---

## 学习资源

### 官方文档
- [PHP Internals Book](https://www.phpinternalsbook.com/)
- [Zend Engine Documentation](https://www.php.net/manual/en/internals2.php)

### 相关项目
- [Swoole](https://github.com/swoole/swoole-src)
- [php-cpp](http://www.php-cpp.com/)

### 书籍
- 《PHP 内核剖析》
- 《深入理解 PHP 内核》

---

*本文档最后更新：2026-03-27*
