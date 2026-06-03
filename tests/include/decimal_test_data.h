#pragma once

#include <decimal.hh>

namespace php {

struct Decimal::Data {
    decimal::Decimal value;
    Data() = default;
    explicit Data(const char *s) : value(s) {}
    explicit Data(const decimal::Decimal &v) : value(v) {}
    explicit Data(php::Int v) : value((int64_t) v) {}
};

}  // namespace php
