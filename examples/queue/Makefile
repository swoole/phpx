PHP_INCLUDE = `php-config --includes`
PHP_LIBS = `php-config --libs`
PHP_LDFLAGS = `php-config --ldflags`
PHP_INCLUDE_DIR = `php-config --include-dir`
PHP_EXTENSION_DIR = `php-config --extension-dir`

queue.so: queue.cpp
	c++ -DHAVE_CONFIG_H -g -o queue.so -O0 -fPIC -shared queue.cpp -std=c++11 -lphpx ${PHP_INCLUDE} -I${PHP_INCLUDE_DIR} ${PHP_LIBS} ${PHP_LDFLAGS}
install: queue.so
	cp queue.so ${PHP_EXTENSION_DIR}/
clean:
	rm *.so
