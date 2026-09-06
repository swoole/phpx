# 快速开始

PHPX 当前支持 PHP 8.4 和 PHP 8.5。开发环境需要对应版本的 PHP CLI、
PHP 开发包（必须提供 `php-config`）、C++17 编译器、CMake 3.16+ 和 Composer。

## 创建扩展项目

```bash
mkdir hello_ext
cd hello_ext
composer require swoole/phpx
vendor/bin/phpx init
```

`init` 默认使用 `PATH` 中的 `php-config`。存在多个 PHP 版本时，可以在
初始化时指定准确路径：

```bash
vendor/bin/phpx init --php-config=/opt/php-8.5/bin/php-config
```

初始化后的主要目录如下：

```text
hello_ext/
├── .phpx.json                 # PHPX 项目及 PHP 版本配置
├── CMakeLists.txt
├── build/
│   └── gen_stub.php           # 来自所选 PHP 开发包
├── include/                   # 可发布的公共 C/C++ 头文件
├── run-tests.php              # 来自所选 PHP 开发包
├── src/
│   ├── hello_ext.cc
│   └── hello_ext.stub.php
└── tests/
    └── hello_ext.phpt
```

`init` 也可以补齐已有扩展项目中缺失的工具和配置。它不会覆盖已有的
CMake、源码、头文件、stub、测试或用户修改过的构建工具。

## 目录约定

- 所有 `.stub.php` 文件只放在 `src/`。
- `build` 会在对应 stub 旁生成 `src/*_arginfo.h`。
- `src/` 下的 `.h` 和生成的 arginfo 都是私有实现，不会安装。
- 只有显式放在 `include/` 下的 C/C++ 头文件是公共 API。
- `install` 将公共头文件安装到
  `$(php-config --include-dir)/ext/<extension-name>/`。

## 构建

```bash
vendor/bin/phpx build
```

`build` 会先按项目选择的 `php-config` 增量构建 `libphpx`，再构建扩展。
只有 `.stub.php` 或生成器发生变化时，才会重新生成 arginfo。

可调整构建类型和并行度：

```bash
vendor/bin/phpx build --type=Debug --jobs=4
```

## 安装和启用

```bash
sudo vendor/bin/phpx install
sudo vendor/bin/phpx enable
```

`install` 将扩展模块、匹配的 PHPX 运行库及公共头文件安装到当前项目
选择的 PHP。`enable` 在该 PHP 的 `php.ini` 中启用扩展；需要停用时执行：

```bash
sudo vendor/bin/phpx disable
```

也可以显式传入已经构建的模块：

```bash
sudo vendor/bin/phpx install /path/to/hello_ext.so
```

## 运行 PHPT

```bash
php run-tests.php tests
```

根目录的 `run-tests.php` 与 `build/gen_stub.php` 均来自当前 PHP 开发包，
无需在 PHPX 仓库中维护 PHP 源码副本。

## 切换 PHP 版本

```bash
vendor/bin/phpx switch /opt/php-8.4/bin/php-config
```

`switch` 会完成以下操作：

1. 校验目标 PHP 版本；
2. 为目标 PHP 重新构建 PHPX 运行库；
3. 重新配置扩展的 CMake 构建目录；
4. 更新 `gen_stub.php` 和 `run-tests.php`；
5. 将新路径保存到 `.phpx.json`。

如果官方构建工具已被用户修改，`switch` 会停止并报错，不会覆盖文件。
之后的 `build`、`install`、`enable` 和 `disable` 都自动使用新的 PHP。

## 命令摘要

```text
phpx init [name] [--target=DIR] [--php-config=PATH]
phpx build [--type=Release] [--jobs=4]
phpx switch <php-config>
phpx install [module.so|module.dll]
phpx enable [extension-name]
phpx disable [extension-name]
```

所有命令均可通过 `--php-config=/path/to/php-config` 临时指定 PHP；项目内
通常无需重复提供，因为 `init` 和 `switch` 已将选择保存在 `.phpx.json`。
