#pragma once

#include <gmpxx.h>

namespace php {

struct BigInt::Data {
    mpz_class value;
    Data() = default;
    explicit Data(const char *s, int base = 0) : value(s, base) {}
    explicit Data(php::Int v) : value((signed long) v) {}
};

}  // namespace php
