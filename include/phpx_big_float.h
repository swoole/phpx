#pragma once

#include "phpx.h"
#include <mpfr.h>
#include <string>

namespace php {

inline constexpr mpfr_prec_t BIG_FLOAT_DEFAULT_PRECISION = 256;
inline constexpr size_t BIG_FLOAT_OUTPUT_DIGITS = 64;

class BigFloat : public Box {
  public:
    mpfr_t value;

    BigFloat() {
        mpfr_init2(value, BIG_FLOAT_DEFAULT_PRECISION);
    }
    explicit BigFloat(const String &s) {
        mpfr_init2(value, BIG_FLOAT_DEFAULT_PRECISION);
        if (UNEXPECTED(mpfr_set_str(value, s.data(), 10, MPFR_RNDN) != 0)) {
            mpfr_clear(value);
            throwException(zend_ce_value_error, "Invalid BigFloat numeric string");
        }
    }
    explicit BigFloat(const char *s) {
        mpfr_init2(value, BIG_FLOAT_DEFAULT_PRECISION);
        if (UNEXPECTED(s == nullptr || mpfr_set_str(value, s, 10, MPFR_RNDN) != 0)) {
            mpfr_clear(value);
            throwException(zend_ce_value_error, "Invalid BigFloat numeric string");
        }
    }
    explicit BigFloat(php::Int v) {
        mpfr_init2(value, BIG_FLOAT_DEFAULT_PRECISION);
        mpfr_set_sj(value, v, MPFR_RNDN);
    }
    explicit BigFloat(php::Float v) {
        mpfr_init2(value, BIG_FLOAT_DEFAULT_PRECISION);
        Variant number(v);
        mpfr_set_str(value, number.toString().data(), 10, MPFR_RNDN);
    }
    BigFloat(const BigFloat &other) {
        mpfr_init2(value, mpfr_get_prec(other.value));
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

    static Variant sqrt(Variant a);
    static Variant toString(Variant a);
    static Variant toInt(Variant a);
    static Variant toFloat(Variant a);
    static Variant toBool(Variant a);
};

static inline Variant toBigFloat(const String &s) {
    return Variant(new BigFloat(s));
}

static inline Variant toBigFloat(php::Int v) {
    return Variant(new BigFloat(v));
}

static inline Variant toBigFloat(php::Float v) {
    return Variant(new BigFloat(v));
}

}  // namespace php
