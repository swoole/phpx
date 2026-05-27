#pragma once

#include "phpx.h"
#include <mpfr.h>
#include <string>

namespace php {

class BigFloat : public Box {
  public:
    mpfr_t value;

    BigFloat() {
        mpfr_init(value);
    }
    BigFloat(const String &s) : BigFloat(s.data()) {}
    BigFloat(const char *s) {
        mpfr_init(value);
        mpfr_set_str(value, s, 10, MPFR_RNDN);
    }
    BigFloat(php::Int v) {
        mpfr_init(value);
        mpfr_set_sj(value, v, MPFR_RNDN);
    }
    BigFloat(php::Float v) {
        mpfr_init(value);
        mpfr_set_d(value, v, MPFR_RNDN);
    }
    BigFloat(const BigFloat &other) {
        mpfr_init(value);
        mpfr_set(value, other.value, MPFR_RNDN);
    }
    ~BigFloat() override {
        mpfr_clear(value);
    }

    static Variant newInstance(Variant s);
    static Variant add(Variant a, Variant b);
    static Variant sub(Variant a, Variant b);
    static Variant mul(Variant a, Variant b);
    static Variant div(Variant a, Variant b);
    static Variant neg(Variant a);
    static Variant cmp(Variant a, Variant b);
    static Variant abs(Variant a);

    static Variant toString(Variant a);
    static Variant toInt(Variant a);
    static Variant toFloat(Variant a);
};

static inline Variant newBigFloat(const String &s) {
    return Variant(new BigFloat(s));
}

static inline Variant newBigFloat(php::Int v) {
    return Variant(new BigFloat(v));
}

static inline Variant newBigFloat(php::Float v) {
    return Variant(new BigFloat(v));
}

}  // namespace php
