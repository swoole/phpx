PHP_INCLUDE = `php-config --includes`
PHP_LIBS = `php-config --libs`
PHP_LDFLAGS = `php-config --ldflags`
PHP_INCLUDE_DIR = `php-config --include-dir`
PHP_EXTENSION_DIR = `php-config --extension-dir`

BloomFilter.so: BloomFilter.cpp spooky.o MurmurHash3.o
	c++ -DHAVE_CONFIG_H -g -o BloomFilter.so -O2 -fPIC -shared BloomFilter.cpp spooky.o MurmurHash3.o -std=c++11 -lphpx ${PHP_INCLUDE} -I${PHP_INCLUDE_DIR} -I${PHP_INCLUDE_DIR}/ext/swoole -I${PHP_INCLUDE_DIR}/ext/swoole/include ${PHP_LIBS} ${PHP_LDFLAGS}
spooky.o: deps/spookyhash/spooky.cpp
	c++ -c -fPIC -O2 -g -o spooky.o deps/spookyhash/spooky.cpp
MurmurHash3.o: deps/murmurhash/MurmurHash3.cpp
	c++ -c -fPIC -O2 -g -o MurmurHash3.o deps/murmurhash/MurmurHash3.cpp
install: BloomFilter.so
	cp BloomFilter.so ${PHP_EXTENSION_DIR}/
clean:
	rm *.o
	rm *.so

