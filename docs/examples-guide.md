# 示例项目

`examples/` 保留扩展开发和嵌入 PHP 的实际项目。示例不是预编译发布物，
系统依赖和 PHP ABI 由开发者负责准备。

## 扩展示例

- `queue/`：基础 C++ 扩展类和 PHPT；
- `bloom_filter/`：依赖 Swoole 共享内存的 BloomFilter；
- `rocksdb/`：链接 RocksDB 的扩展；
- `gtk/`：链接 GTK3 的桌面示例。

stub 均位于各项目 `src/`。`phpx init` 会安全补齐根目录
`run-tests.php`、`build/gen_stub.php` 和 `.phpx.json`，不会覆盖已有源码：

```bash
cd examples/queue
../../bin/phpx init queue
../../bin/phpx build -j 4
sudo ../../bin/phpx install
sudo ../../bin/phpx enable
php run-tests.php tests
```

Composer 项目将 `../../bin/phpx` 替换为 `vendor/bin/phpx`。

`phpx build` 不构建或检测 `libphpx`。运行示例前必须为目标 PHP 准备匹配
的 PHPX 头文件和库；缺失依赖由编译器或链接器报告。

### Queue

Queue 是推荐的入门示例，覆盖扩展入口、方法实现、stub 方法表、类属性、
C++ 容器和 PHPT。参见 [`examples/queue`](../examples/queue/)。

### BloomFilter

BloomFilter 使用 Swoole 的共享内存能力，适合观察第三方扩展依赖和 C++
资源生命周期。参见
[`examples/bloom_filter`](../examples/bloom_filter/)。

### RocksDB

构建前安装 RocksDB 开发库：

```bash
sudo apt-get install librocksdb-dev
# macOS: brew install rocksdb
```

参见 [`examples/rocksdb`](../examples/rocksdb/)。

### GTK

GTK 示例依赖 GTK3：

```bash
sudo apt-get install libgtk-3-dev
# macOS: brew install gtk+3
```

参见 [`examples/gtk`](../examples/gtk/)。

## Embed 示例

`examples/embed/` 展示在 C++ 程序中嵌入 PHP，需要目标 PHP 提供匹配的
Embed SAPI 库：

```bash
cmake -S examples/embed -B examples/embed/build \
  -DPHP_CONFIG=/path/to/php-config
cmake --build examples/embed/build --parallel 4
```

并非所有 PHP 发行包都提供 `libphp`。缺少时应安装对应开发包或自行构建
PHP，不能链接另一个 PHP 版本的库。

## 新建扩展

新项目应由当前工具生成，不要复制示例中的历史平台配置：

```bash
mkdir my_ext
cd my_ext
composer require swoole/phpx
vendor/bin/phpx init my_ext
```

目录约定：

- `src/*.stub.php`：PHP 声明；
- `src/*_arginfo.h`：自动生成的私有头文件；
- `src/*.h`：私有头文件；
- `include/*.{h,hh,hpp,hxx}`：安装给其他扩展使用的公共头文件；
- `tests/*.phpt`：扩展行为测试。

## 常见故障

### 找不到 `phpx_ext.h`

PHPX 头文件未安装，且 Composer/PHPX_HOME 路径不可用。先准备匹配 PHP 的
PHPX 开发环境。

### 找不到 `-lphpx` 或 `libphpx.so`

编译期链接目录或运行时 loader 路径未配置。`phpx build` 不会自动构建、
复制或选择 PHPX 库。

### arginfo 未更新

检查 stub 是否位于 `src/`，`build/gen_stub.php` 是否存在，以及 CMake 是否
跟踪 stub 和生成器依赖。不要手工修改 `*_arginfo.h`。

### 扩展加载失败

```bash
php -v
php --ini
php -d display_startup_errors=1 -m
ldd /path/to/extension.so       # Linux
otool -L /path/to/extension.so  # macOS
```

优先核对 PHP 版本、ZTS/NTS、CPU 架构和 PHPX 动态库是否一致。
