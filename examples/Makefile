PHP_INCLUDE = `php-config --includes`
PHP_LIBS = `php-config --libs`
PHP_LDFLAGS = `php-config --ldflags`
PHP_INCLUDE_DIR = `php-config --include-dir`
PHP_EXTENSION_DIR = `php-config --extension-dir`
PHPX_INCLUDE_DIR = "/home/htf/workspace/php-x/include"

cpp_ext.so: extension.cpp
	c++ -DHAVE_CONFIG_H -g -o cpp_ext.so -O0 -fPIC -shared extension.cpp -std=c++11 ${PHP_INCLUDE} -I${PHP_INCLUDE_DIR}\
	 -I${PHPX_INCLUDE_DIR} -I${PHP_INCLUDE_DIR}/ext/swoole/include -I${PHP_INCLUDE_DIR}/ext/swoole ${PHP_LDFLAGS}
embed: embed.cpp
	c++ -DHAVE_CONFIG_H -g -o embed -O0 embed.cpp -fPIC -std=c++11 ${PHP_INCLUDE} -I${PHP_INCLUDE_DIR} \
	-I${PHPX_INCLUDE_DIR} ${PHP_LDFLAGS} ${PHP_LIBS}  -lphp7
install: cpp_ext.so
	cp cpp_ext.so ${PHP_EXTENSION_DIR}/
clean:
	rm *.so
