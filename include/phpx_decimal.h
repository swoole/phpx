#pragma once

#include "phpx.h"
#include <decimal.hh>

namespace php {

class Decimal : public Box {
  public:
    decimal::Decimal value;

    Decimal() = default;
    Decimal(const String &s) : value(s.data()) {}
    Decimal(const decimal::Decimal &v) : value(v) {}
    Decimal(php::Int v) : value((int64_t)v) {}

    static Variant newInstance(Variant s);
    static Variant add(Variant a, Variant b);
    static Variant sub(Variant a, Variant b);
    static Variant mul(Variant a, Variant b);
    static Variant div(Variant a, Variant b);
    static Variant mod(Variant a, Variant b);
    static Variant neg(Variant a);
    static Variant cmp(Variant a, Variant b);
    static Variant abs(Variant a);

    static Variant toString(Variant a);
    static Variant toInt(Variant a);
    static Variant toFloat(Variant a);
    static Variant toBigInt(Variant a);
};

static inline Variant newDecimal(const String &s) {
    return Variant(new Decimal(s));
}

static inline Variant newDecimal(php::Int v) {
    return Variant(new Decimal(v));
}

}  // namespace php
