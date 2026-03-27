<h1 align=center>
<img width="400" alt="Swoole Logo" src="logo.png" />
</h1>

[![Twitter](https://badgen.net/badge/icon/twitter?icon=twitter&label)](https://twitter.com/phpswoole)
[![Discord](https://badgen.net/badge/icon/discord?icon=discord&label)](https://discord.swoole.dev)
[![Build Status](https://github.com/matyhtf/phpx/workflows/libphpx/badge.svg)](https://github.com/matyhtf/phpx/actions?query=workflow%3Alibphpx)
[![License](https://img.shields.io/badge/license-apache2-blue.svg)](LICENSE)
[![Latest Release](https://img.shields.io/github/release/swoole/phpx.svg)](https://github.com/swoole/phpx/releases/)
[![Codecov](https://codecov.io/gh/swoole/phpx/branch/master/graph/badge.svg)](https://codecov.io/gh/swoole/phpx)

C++ wrapper for Zend API

## Requirements

- PHP 8.1 or later
- Linux/macOS/Windows
- GCC 4.8 or later
- Composer

## Build libphpx.so
```shell
cmake .
make -j 4
sudo make install
sudo ldconfig
```

## Create Project
```shell
# extension
composer create-project swoole/phpx-ext test
```

## Generate ArgInfo & Function Entires
```shell
php vendor/swoole/phpx/bin/gen_stub.php your_stub_dir
```

## Build extension
```shell
cd test
cmake .
make -j 4
make install
```

## Load your extension
Edit `php.ini`, add `extension=test.so`

## Run
```shell
php echo.php
```
