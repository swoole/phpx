#pragma once

#include "phpx.h"
#include <gmpxx.h>

namespace php {

namespace detail {

static inline void setBigIntFromPhpInt(mpz_class &result, php::Int value) noexcept {
    using UnsignedInt = std::make_unsigned_t<php::Int>;

    const bool negative = value < 0;
    const UnsignedInt magnitude = negative ? UnsignedInt(-(value + 1)) + UnsignedInt(1) : UnsignedInt(value);

    mpz_import(result.get_mpz_t(), 1, 1, sizeof(magnitude), 0, 0, &magnitude);
    if (negative) {
        mpz_neg(result.get_mpz_t(), result.get_mpz_t());
    }
}

}  // namespace detail

class BigInt : public Box {
  public:
    mpz_class value;
    BigInt() = default;
    explicit BigInt(const String &s) {
        if (UNEXPECTED(value.set_str(s.data(), 0) != 0)) {
            throwException(zend_ce_value_error, "Invalid BigInt numeric string");
        }
    }
    explicit BigInt(php::Int v) {
        detail::setBigIntFromPhpInt(value, v);
    }

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
    static Variant divmod(Variant a, Variant b);
    static Variant powmod(Variant base, Variant exp, Variant mod);
    static Variant sqrt(Variant a);
    static Variant bitAnd(Variant a, Variant b);
    static Variant bitOr(Variant a, Variant b);
    static Variant bitXor(Variant a, Variant b);
    static Variant bitNot(Variant a);
    static Variant testBit(Variant a, Variant index);
    static Variant popCount(Variant a);
    static Variant bitShiftLeft(Variant a, Variant n);
    static Variant bitShiftRight(Variant a, Variant n);

    static Variant toString(Variant a);
    static Variant toInt(Variant a);
    static Variant toFloat(Variant a);
    static Variant toBool(Variant a);
    static Variant toBigDecimal(Variant a);
};

static inline Variant toBigInt(php::Int v) {
    return Variant(new BigInt(v));
}

static inline Variant toBigInt(const String &s) {
    return Variant(new BigInt(s));
}

}  // namespace php
