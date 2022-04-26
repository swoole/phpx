<h1 align=center>
<img width="400" alt="Swoole Logo" src="logo.png" />
</h1>

[![Build Status](https://github.com/matyhtf/phpx/workflows/libphpx/badge.svg)](https://github.com/matyhtf/phpx/actions?query=workflow%3Alibphpx)
[![License](https://img.shields.io/badge/license-apache2-blue.svg)](LICENSE)

C++ wrapper for Zend API

## Requirements

- PHP 7.2 or later
- Linux/MacOS/Windows
- GCC 4.8 or later
- Composer

## Build phpx (bin)
```shell
./build.sh
sudo cp bin/phpx /usr/local/bin
```

## Build libphpx.so
```shell
cmake .
make -j 4
sudo make install
```

## Create Project
```shell
phpx create cpp_ext
```

## Generate ArgInfo & Function Entires
```shell
php script/gen_stub.php your_stub_dir
```

## Build extension
```shell
cd examples/cpp_ext
phpx build -v
sudo phpx install
```

## Load your extension
Edit `php.ini`, add `extension=cpp_ext.so`

## Run
```shell
php echo.php
```
