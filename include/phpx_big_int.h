#pragma once

#include "phpx.h"

namespace php {

class BigInt : public Box {
    struct Data;

  public:
    Data *data = nullptr;
    BigInt();
    explicit BigInt(const String &s);
    explicit BigInt(php::Int v);
    ~BigInt() override;

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
    static Variant toBigDecimal(Variant a);
};

static inline Variant toBigInt(php::Int v) {
    return Variant(new BigInt(v));
}

static inline Variant toBigInt(const String &s) {
    return Variant(new BigInt(s));
}

}  // namespace php
