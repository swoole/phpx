PHP_INCLUDE = `php-config --includes`
PHP_LIBS = `php-config --libs`
PHP_LDFLAGS = `php-config --ldflags`
PHP_INCLUDE_DIR = `php-config --include-dir`
PHP_EXTENSION_DIR = `php-config --extension-dir`
PHPX_SRC = "/home/htf/workspace/php-x"

extension: extension.cpp
	c++ -DHAVE_CONFIG_H -g -o cpp_ext.so -O0 -fPIC -shared extension.cpp -std=c++11 ${PHP_INCLUDE} -I${PHPX_SRC} -I${PHPX_SRC}/include ${PHP_LDFLAGS}
embed: embed.cpp
	c++ -DHAVE_CONFIG_H -g -o embed -O0 embed.cpp -std=c++11 ${PHP_INCLUDE} -I${PHP_INCLUDE_DIR}/ext/swoole -I${PHP_INCLUDE_DIR}/ext/swoole/include ${PHP_LDFLAGS} -lphp7 ${PHP_LIBS}
clean:
	rm *.so
