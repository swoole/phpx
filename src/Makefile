PHP_INCLUDE = `php-config --includes`
PHP_LIBS = `php-config --libs`
PHP_LDFLAGS = `php-config --ldflags`
PHP_INCLUDE_DIR = `php-config --include-dir`
PHP_EXTENSION_DIR = `php-config --extension-dir`

so: array.cc base.cc class.cc extension.cc hash.cc string.cc variant.cc
	c++ -g -O2 -o libphpx.so array.cc  base.cc  class.cc  extension.cc  hash.cc  string.cc  variant.cc \
	-fPIC -shared -std=c++11 -I../include ${PHP_INCLUDE} -I${PHP_INCLUDE_DIR}
install:
	sudo cp libphpx.so /usr/local/lib/
	sudo cp include/phpx.h /usr/local/include
	sudo cp include/phpx_embed.h /usr/local/include
