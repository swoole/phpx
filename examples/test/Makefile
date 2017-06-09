PHP_INCLUDE = `php-config --includes`
PHP_LIBS = `php-config --libs`
PHP_LDFLAGS = `php-config --ldflags`
PHP_INCLUDE_DIR = `php-config --include-dir`
PHP_EXTENSION_DIR = `php-config --extension-dir`

test.so: test.cpp
	c++ -DHAVE_CONFIG_H -g -o test.so -O3 -fPIC -shared test.cpp -std=c++11 ${PHP_INCLUDE} -I${PHP_INCLUDE_DIR} -lphpx\
	 -I${PHP_INCLUDE_DIR}/ext/swoole/include -I${PHP_INCLUDE_DIR}/ext/swoole
install: test.so
	cp test.so ${PHP_EXTENSION_DIR}/
clean:
	rm *.so
