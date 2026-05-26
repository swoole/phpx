#pragma once

#include "phpx.h"
#include <gmpxx.h>

namespace php {

class BigInt : public Box {
  public:
    mpz_class value;

    BigInt() = default;
    BigInt(const std::string &s, int base = 10) : value(s, base) {}
    BigInt(const char *s, int base = 10) : value(s, base) {}
    BigInt(const mpz_class &v) : value(v) {}
    BigInt(php::Int v) : value((signed long)v) {}

    static Variant newInstance(Variant s);
    static Variant add(Variant a, Variant b);
    static Variant sub(Variant a, Variant b);
    static Variant mul(Variant a, Variant b);
    static Variant div(Variant a, Variant b);
    static Variant mod(Variant a, Variant b);
    static Variant pow(Variant a, Variant b);
    static Variant neg(Variant a);
    static Variant cmp(Variant a, Variant b);
    static Variant abs(Variant a);
    static Variant gcd(Variant a, Variant b);

    static Variant toString(Variant a);
    static Variant toInt(Variant a);
    static Variant toFloat(Variant a);
    static Variant toBigDecimal(Variant a);
};

static inline Variant newBigInt(const std::string &s, int base = 10) {
    return Variant(new BigInt(s, base));
}

static inline Variant newBigInt(php::Int v) {
    return Variant(new BigInt(v));
}

static inline Variant newBigInt(const String &s) {
    return Variant(new BigInt(s.data()));
}

}  // namespace php
