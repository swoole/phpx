PHP_INCLUDE = `php-config --includes`
PHP_LIBS = `php-config --libs`
PHP_LDFLAGS = `php-config --ldflags`
PHP_INCLUDE_DIR = `php-config --include-dir`
PHP_EXTENSION_DIR = `php-config --extension-dir`

php-rocksdb.so: rocksdb.cpp
	c++ -DHAVE_CONFIG_H -g -o php-rocksdb.so -O0 -fPIC -shared rocksdb.cpp -std=c++11 -lphpx -lrocksdb  ${PHP_INCLUDE} -I${PHP_INCLUDE_DIR}
install: php-rocksdb.so
	cp php-rocksdb.so ${PHP_EXTENSION_DIR}/
clean:
	rm *.so