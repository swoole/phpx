#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {

Variant bcadd(const Variant &num1, const Variant &num2, const Variant &scale = nullptr);
Variant bcsub(const Variant &num1, const Variant &num2, const Variant &scale = nullptr);
Variant bcmul(const Variant &num1, const Variant &num2, const Variant &scale = nullptr);
Variant bcdiv(const Variant &num1, const Variant &num2, const Variant &scale = nullptr);
Variant bcmod(const Variant &num1, const Variant &num2, const Variant &scale = nullptr);
Variant bcdivmod(const Variant &num1, const Variant &num2, const Variant &scale = nullptr);
Variant bcpowmod(const Variant &num, const Variant &exponent, const Variant &modulus, const Variant &scale = nullptr);
Variant bcpow(const Variant &num, const Variant &exponent, const Variant &scale = nullptr);
Variant bcsqrt(const Variant &num, const Variant &scale = nullptr);
Variant bccomp(const Variant &num1, const Variant &num2, const Variant &scale = nullptr);
Variant bcscale(const Variant &scale = nullptr);
Variant bcfloor(const Variant &num);
Variant bcceil(const Variant &num);
Variant bcround(const Variant &num, const Variant &precision = 0, const Variant &mode = {});

}  // namespace php
