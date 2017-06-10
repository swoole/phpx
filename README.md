# PHP-X
C++ wrapper for Zend API

![PHP-X](logo.png)
 
## Requirements

- PHP 7.0 or later
- Linux/MacOS/Windows
- GCC 4.8 or later

## Build libphpx.so
```shell
cmake .
make -j 4
sudo make install
```

## Build extension
```shell
cd examples/cpp_ext
make 
sudo make install
```

## Load your extension
Edit `php.ini`, add `extension=cpp_ext.so`

## Run
```shell
php echo.php
```
