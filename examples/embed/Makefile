PHP_INCLUDE = `php-config --includes`
PHP_LIBS = `php-config --libs`
PHP_LDFLAGS = `php-config --ldflags`
PHP_INCLUDE_DIR = `php-config --include-dir`
PHP_EXTENSION_DIR = `php-config --extension-dir`

embed: embed.cc
	c++ -DHAVE_CONFIG_H -g -o embed -O0 embed.cc -fPIC -std=c++11 ${PHP_INCLUDE} -I${PHP_INCLUDE_DIR} \
	${PHP_LDFLAGS} ${PHP_LIBS} -lphp7 -lphpx
clean:
	rm embed
