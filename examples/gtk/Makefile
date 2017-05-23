PHP_INCLUDE = `php-config --includes`
PHP_LIBS = `php-config --libs`
PHP_LDFLAGS = `php-config --ldflags`
PHP_INCLUDE_DIR = `php-config --include-dir`
PHP_EXTENSION_DIR = `php-config --extension-dir`
PHPX_INCLUDE_DIR = "/home/htf/workspace/php-x/include"
GTK_FLAGS = `pkg-config --cflags --libs gtk+-3.0`

gtk.so: gtk.cc
	c++ -DHAVE_CONFIG_H -g -o gtk.so -O0 -fPIC -shared gtk.cc -std=c++11 ${PHP_INCLUDE} -I${PHP_INCLUDE_DIR}\
	 -I${PHPX_INCLUDE_DIR} ${GTK_FLAGS}
install: gtk.so
	cp gtk.so ${PHP_EXTENSION_DIR}/
clean:
	rm *.so
