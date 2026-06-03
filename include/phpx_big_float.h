#pragma once

#include "phpx.h"

namespace php {

class BigFloat : public Box {
    struct Data;
  public:
    Data *data = nullptr;
    BigFloat();
    explicit BigFloat(const String &s);
    explicit BigFloat(const char *s);
    explicit BigFloat(php::Int v);
    explicit BigFloat(php::Float v);
    BigFloat(const BigFloat &other);
    ~BigFloat() override;

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
