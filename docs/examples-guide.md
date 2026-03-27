# 示例使用指南

本文档介绍如何使用 PHPX 提供的各种示例代码。

## 示例目录结构

```
examples/
├── test/           # 基础功能测试示例
├── bloom_filter/   # 布隆过滤器扩展示例
├── queue/          # 队列实现示例
├── rocksdb/        # RocksDB 数据库示例
├── gtk/            # GTK GUI 示例
├── embed/          # 嵌入 PHP 解释器示例
└── php/            # PHP 脚本示例
```

---

## test - 基础功能示例

这个目录包含基础的 PHPX 功能演示。

### 文件说明

- `test.cpp` - C++ 测试代码
- `echo.php` - 输出测试
- `class_def.php` - 类定义示例
- `dispatch.php` - 路由分发示例
- `empty.php` - empty() 函数测试
- `immutable.php` - 不可变对象测试
- `include.php` - 文件包含测试
- `run.php` - 运行测试脚本
- `tcp.php` - TCP 网络测试

### 运行示例

```bash
cd examples/test
make
php echo.php
php class_def.php
```

### 代码示例

#### 1. Echo 测试 (echo.php)
```php
<?php
echo __FILE__ . "\n";
// 输出当前文件路径
```

#### 2. 类定义 (class_def.php)
```php
<?php
class ClassDef {
    public $var = 'hello';

    public function say() {
        return $this->var;
    }
}

$obj = new ClassDef();
echo $obj->say() . "\n";  // 输出：hello
```

#### 3. Empty 测试 (empty.php)
```php
<?php
var_dump(empty($undefined));  // true
var_dump(empty(0));           // true
var_dump(empty(""));          // true
var_dump(empty(false));       // true
var_dump(empty("hello"));     // false
```

---

## bloom_filter - 布隆过滤器示例

基于共享内存的 BloomFilter 实现。

### 特性

- 支持添加元素
- 支持检查元素是否存在
- 支持数据持久化
- 基于共享内存，多进程安全

### 安装

```bash
cd examples/bloom_filter
cmake .
make && make install
```

编辑 `php.ini` 添加：
```ini
extension=BloomFilter.so
```

### 使用示例

```php
<?php
// 创建容量为 1024 的布隆过滤器
$b = new BloomFilter(1024);

// 添加元素
echo "Add elements\n";
$b->add("hello");
$b->add("world");
$b->add("rango");

// 检查元素存在性
var_dump($b->has("hello"));      // true
var_dump($b->has("world"));      // true
var_dump($b->has("rango"));      // true
var_dump($b->has("test"));       // false (可能)
var_dump($b->has(" world "));    // false (注意空格)

// 持久化到文件
$b->dump(__DIR__."/bf.data");

// 从文件加载
// $b->load(__DIR__."/bf.data");
```

### 原理说明

布隆过滤器使用多个哈希函数和位数组来高效地判断元素是否存在于集合中：

1. **添加元素**：使用 k 个哈希函数计算元素位置，将位数组对应位置设为 1
2. **查询元素**：检查 k 个位置是否都为 1
   - 如果都为 1：可能存在
   - 如果有 0：一定不存在

### 应用场景

- 黑名单过滤
- URL 去重
- 缓存穿透防护
- 大数据集快速查找

---

## queue - 队列实现示例

高性能队列实现，支持多种操作。

### 特性

- FIFO（先进先出）
- LIFO（后进先出）
- 优先级队列
- 阻塞队列

### 安装

```bash
cd examples/queue
cmake .
make && make install
```

### 使用示例

```php
<?php
$queue = new Queue();

// 入队
$queue->push("item1");
$queue->push("item2");
$queue->push("item3");

// 出队（FIFO）
echo $queue->pop() . "\n";  // item1
echo $queue->pop() . "\n";  // item2

// 查看队列大小
echo "Size: " . $queue->size() . "\n";  // Size: 1

// 清空队列
$queue->clear();
```

### 优先级队列示例

```php
<?php
$pq = new PriorityQueue();

// 添加带优先级的元素
$pq->push("low priority", 1);
$pq->push("high priority", 10);
$pq->push("medium priority", 5);

// 按优先级出队
echo $pq->pop() . "\n";  // high priority
echo $pq->pop() . "\n";  // medium priority
echo $pq->pop() . "\n";  // low priority
```

---

## rocksdb - RocksDB 数据库示例

RocksDB 键值存储封装。

### 特性

- 持久化键值存储
- 支持范围查询
- 支持批量操作
- 高性能读写

### 依赖

需要安装 RocksDB：
```bash
# Ubuntu/Debian
sudo apt-get install librocksdb-dev

# macOS
brew install rocksdb
```

### 安装

```bash
cd examples/rocksdb
cmake .
make && make install
```

### 基本使用

```php
<?php
$db = new RocksDB("/tmp/test.db");

// 写入数据
$db->set("name", "John");
$db->set("age", "25");
$db->set("city", "Beijing");

// 读取数据
echo $db->get("name") . "\n";  // John
echo $db->get("age") . "\n";   // 25

// 删除数据
$db->delete("city");

// 检查键是否存在
var_dump($db->has("name"));    // true
var_dump($db->has("city"));    // false

// 范围查询
$iterator = $db->iterator();
foreach ($iterator as $key => $value) {
    echo "$key => $value\n";
}
```

### 批量操作

```php
<?php
$db = new RocksDB("/tmp/test.db");

// 批量写入
$batch = [
    ["key1", "value1"],
    ["key2", "value2"],
    ["key3", "value3"],
];

foreach ($batch as [$key, $value]) {
    $db->set($key, $value);
}

// 批量读取
$keys = ["key1", "key2", "key3"];
foreach ($keys as $key) {
    echo "$key => " . $db->get($key) . "\n";
}
```

---

## gtk - GTK GUI 示例

使用 PHPX 开发 GTK 图形界面应用。

### 依赖

```bash
# Ubuntu/Debian
sudo apt-get install libgtk-3-dev php-gtk

# macOS
brew install gtk+3
```

### 安装

```bash
cd examples/gtk
cmake .
make && make install
```

### 简单窗口示例

```php
<?php
$window = new GtkWindow();
$window->set_title("PHPX GTK Example");
$window->set_default_size(400, 300);
$window->connect("destroy", function() {
    Gtk::main_quit();
});

$button = new GtkButton("Click me!");
$button->connect("clicked", function() {
    echo "Button clicked!\n";
});

$window->add($button);
$window->show_all();

Gtk::main();
```

### Glade 界面示例

```php
<?php
// 加载 Glade 文件
$builder = new GtkBuilder();
$builder->add_from_file("test.glade");

// 获取窗口
$window = $builder->getObject("main_window");
$window->connect("destroy", function() {
    Gtk::main_quit();
});

// 获取按钮并连接信号
$button = $builder->getObject("button1");
$button->connect("clicked", function() {
    echo "Button from Glade clicked!\n";
});

$window->show_all();
Gtk::main();
```

---

## embed - 嵌入 PHP 解释器示例

在 C++ 应用中嵌入 PHP 解释器。

### 特性

- 在 C++ 程序中执行 PHP 代码
- C++ 与 PHP 双向调用
- 共享变量和数据

### 安装

```bash
cd examples/embed
cmake .
make
```

### C++ 代码示例

```cpp
#include "phpx.h"

using namespace php;

int main(int argc, char *argv[]) {
    // 初始化 PHP 环境
    php_embed_init(argc, argv);
    
    // 执行 PHP 代码
    eval("$result = 'Hello from PHP!'; echo $result;");
    
    // 获取 PHP 变量
    Variant result = global("result");
    echo(result.toString());
    
    // 关闭 PHP 环境
    php_embed_shutdown();
    
    return 0;
}
```

### PHP 脚本示例 (embed.php)

```php
<?php
// 被 C++ 调用的 PHP 脚本

function greet($name) {
    return "Hello, $name! Welcome to PHPX.";
}

$version = PHP_VERSION;
echo "Running on PHP $version\n";
```

---

## php - PHP 脚本示例

简单的 PHP 功能演示脚本。

### count.php - 计数示例

```php
<?php
$arr = [1, 2, 3, 4, 5];
echo "Count: " . count($arr) . "\n";  // Count: 5

$str = "Hello";
echo "Length: " . strlen($str) . "\n";  // Length: 5
```

### empty.php - Empty 测试

```php
<?php
// 测试 empty() 函数
$tests = [
    null,
    false,
    0,
    0.0,
    "",
    "0",
    [],
    [1, 2, 3],
    "hello",
    42,
];

foreach ($tests as $test) {
    var_dump(empty($test));
}
```

### ref.php - 引用示例

```php
<?php
// 引用传递示例
function increment(&$value) {
    $value++;
}

$num = 10;
echo "Before: $num\n";  // Before: 10
increment($num);
echo "After: $num\n";   // After: 11
```

---

## 运行所有示例

### 通用步骤

1. **进入示例目录**
```bash
cd examples/<example_name>
```

2. **编译**
```bash
cmake .
make -j 4
```

3. **安装（可选）**
```bash
sudo make install
```

4. **运行测试**
```bash
php <test_file>.php
```

### 测试脚本

大多数示例都提供了 `run-tests.php`：

```bash
php run-tests.php
```

或使用项目自带的测试工具：

```bash
../../bin/phpx-tests run-tests.php
```

---

## 示例代码分析

### BloomFilter 实现分析

```cpp
// src/BloomFilter.cc 核心逻辑

class BloomFilter {
private:
    size_t size;
    uchar *bitmap;
    int hash_count;
    
public:
    BloomFilter(size_t size) {
        this->size = size;
        this->bitmap = new uchar[size / 8 + 1]();
        this->hash_count = 7;  // 使用 7 个哈希函数
    }
    
    void add(const String &item) {
        for (int i = 0; i < hash_count; i++) {
            size_t pos = hash(item, i) % size;
            bitmap[pos / 8] |= (1 << (pos % 8));
        }
    }
    
    bool has(const String &item) {
        for (int i = 0; i < hash_count; i++) {
            size_t pos = hash(item, i) % size;
            if (!(bitmap[pos / 8] & (1 << (pos % 8)))) {
                return false;
            }
        }
        return true;
    }
};
```

### Queue 实现分析

```cpp
// src/Queue.cc 核心逻辑

class Queue {
private:
    std::deque<Variant> data;
    
public:
    void push(const Variant &item) {
        data.push_back(item);
    }
    
    Variant pop() {
        if (data.empty()) {
            throwError("Queue is empty");
            return {};
        }
        Variant item = data.front();
        data.pop_front();
        return item;
    }
    
    size_t size() const {
        return data.size();
    }
};
```

---

## 最佳实践

### 1. 错误处理

```php
<?php
try {
    $result = $expensiveOperation();
} catch (Exception $e) {
    echo "Error: " . $e->getMessage() . "\n";
    // 回退逻辑
}
```

### 2. 资源管理

```php
<?php
// 及时释放不需要的资源
$largeData = processData();
use($largeData);
unset($largeData);  // 手动释放

// 使用完数据库后关闭连接
$db->close();
```

### 3. 性能优化

```php
<?php
// 预分配数组大小
$arr = array_fill(0, 1000, null);

// 使用引用避免复制
function processLargeArray(&$array) {
    // 直接修改原数组
}

// 批量操作
$batch = [];
foreach ($items as $item) {
    $batch[] = transform($item);
    if (count($batch) >= 100) {
        saveBatch($batch);
        $batch = [];
    }
}
```

---

## 故障排除

### 常见问题

#### Q: 扩展加载失败
```bash
# 检查扩展是否在正确位置
php --ini | grep extension_dir

# 检查 php.ini 配置
php -i | grep extension
```

#### Q: 编译错误
```bash
# 清理构建缓存
make clean
rm -rf CMakeCache.txt CMakeFiles/

# 重新配置
cmake . -DCMAKE_BUILD_TYPE=Debug

# 查看详细错误信息
make VERBOSE=1
```

#### Q: 段错误
```bash
# 使用 gdb 调试
gdb php
(gdb) run test.php
(gdb) bt  # 查看堆栈跟踪

# 使用 valgrind 检查内存
valgrind php test.php
```

---

*本文档最后更新：2026-03-27*
