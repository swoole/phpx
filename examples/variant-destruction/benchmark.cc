#include <phpx.h>
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
    const long iterations = argc > 1 ? std::strtol(argv[1], nullptr, 10) : 30000000;
    php::Int checksum = 0;
    for (long i = 0; i < iterations; ++i) {
        php::Variant value(static_cast<php::Int>(i % 100));
        checksum += value.toInt();
    }
    std::cout << checksum << '\n';
}
