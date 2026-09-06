# 测试指南

PHPX 使用三类测试，分别保护 C++ 核心、扩展入口和 Composer CLI。

## C++ Google Test

测试源码位于 `tests/src/`，测试专用工具位于 `tests/include/`。其中
`phpx_test_facade.h` 只为减少历史测试改动而保留，不属于 PHPX 公开 API。

### 构建

```bash
cmake -S . -B build \
  -DCMAKE_BUILD_TYPE=Debug \
  -DBUILD_TESTS=ON \
  -DPHP_CONFIG=/path/to/php-config
cmake --build build --target phpx-tests --parallel 4
```

GTest 可执行文件统一输出到仓库 `bin/phpx-tests`；共享库输出到 `lib/`。

### 运行

```bash
./bin/phpx-tests
./bin/phpx-tests --gtest_list_tests
./bin/phpx-tests --gtest_filter='array.*'
./bin/phpx-tests --gtest_output=xml:test-results.xml
```

测试程序使用 PHP Embed SAPI。若扩展安装在 CLI 的附加 ini 目录，显式传递：

```bash
PHP_INI_SCAN_DIR="$(php-config --ini-dir)" ./bin/phpx-tests
```

PHPX 的 Python bridge、Redis、cURL、FFI 等测试依赖对应扩展或服务。缺少可选
依赖时应按测试设计 skip；CI 会安装完整依赖以运行全部路径。

### 新增测试

在 `tests/src/` 添加 `.cpp` 即可被 CMake 的测试源文件 glob 收集。测试应：

- 使用唯一 suite/test 名；
- 同时覆盖正常返回和 Zend 异常；
- 检查引用计数、copy-on-write 或 request 生命周期时写出明确前置条件；
- 不把测试 Facade 用法写入用户文档或公共头文件；
- 不保存跨 request 的裸 `zval *`、脚本类 CE 或脚本函数指针。

## 扩展测试

`tests/ext/` 构建测试扩展 `ext`，用于 PHPUnit 验证扩展入口、函数表和 PHP
调用行为。启用 `BUILD_EXT` 后构建：

```bash
cmake -S . -B build -DBUILD_EXT=ON -DPHP_CONFIG=/path/to/php-config
cmake --build build --target ext --parallel 4
```

运行 PHPUnit 前，将生成的扩展复制到目标 PHP 的 extension directory，并
在该 PHP 的 ini scan directory 中启用。CI 的 `.github/workflows/test.yml`
提供了可执行示例。

## PHP CLI / PHPUnit

CLI 和扩展的 PHP 单元测试位于 `tests/unit/`：

```bash
composer install
composer test
```

仅测试 `bin/phpx` 时：

```bash
vendor/bin/phpunit --filter PhpXCommandTest tests/unit/PhpXCommandTest.php
```

`PhpXCommandTest` 使用临时目录和假的 `php-config` / CMake 命令验证：

- `init` 不覆盖已有项目文件；
- PHP 构建工具 hash 保护；
- `build -j N` 的并行参数传递；
- `build` 不隐式构建或检测 `libphpx`；
- `install` 只发布 `include/` 公共头文件；
- `enable` / `disable` 对 php.ini 的修改。

## 扩展项目 PHPT

`phpx init` 从所选 PHP 开发包复制官方 `run-tests.php` 到项目根目录：

```bash
vendor/bin/phpx build -j 4
sudo vendor/bin/phpx install
sudo vendor/bin/phpx enable
php run-tests.php tests
```

stub 位于 `src/`，arginfo 也生成到 `src/`。PHPT 放在项目 `tests/`，不要
依赖 PHPX 仓库中的共享 `run-tests.php`。

## Sanitizer 与覆盖率

AddressSanitizer：

```bash
cmake -S . -B build-asan \
  -DCMAKE_BUILD_TYPE=Debug \
  -Denable_asan=ON \
  -DBUILD_TESTS=ON
cmake --build build-asan --target phpx-tests --parallel 4
ASAN_OPTIONS=detect_leaks=1 ./bin/phpx-tests
```

覆盖率：

```bash
cmake -S . -B build-coverage \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCODE_COVERAGE=ON \
  -DBUILD_TESTS=ON
cmake --build build-coverage --target phpx-tests --parallel 4
./bin/phpx-tests
lcov --directory build-coverage --capture --output-file coverage.info
```

不要同时用 Release 优化结果判断 sanitizer 问题，也不要把 PHP/Zend 系统
头文件覆盖率计入 PHPX 指标。

## 调试失败

```bash
gdb --args ./bin/phpx-tests --gtest_filter='suite.test'
valgrind --leak-check=full ./bin/phpx-tests --gtest_filter='suite.test'
```

涉及 request shutdown、持久表或 ZTS 的问题必须在与 CI 相同的 PHP ABI、
扩展集合和 ini 配置下复现。至少记录 `php -v`、`php --ini`、
`php-config --configure-options` 和 CPU 架构。
