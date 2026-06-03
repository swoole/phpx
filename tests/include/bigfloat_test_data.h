#pragma once

#include <mpfr.h>

namespace php {

struct BigFloat::Data {
    mpfr_t value;
    Data() { mpfr_init(value); }
    Data(const Data &other) {
        mpfr_init(value);
        mpfr_set(value, other.value, MPFR_RNDN);
    }
    ~Data() { mpfr_clear(value); }
};

}  // namespace php
