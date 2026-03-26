#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant bcadd(const Variant &num1, const Variant &num2, const Variant &scale = {});
Variant bcsub(const Variant &num1, const Variant &num2, const Variant &scale = {});
Variant bcmul(const Variant &num1, const Variant &num2, const Variant &scale = {});
Variant bcdiv(const Variant &num1, const Variant &num2, const Variant &scale = {});
Variant bcmod(const Variant &num1, const Variant &num2, const Variant &scale = {});
Variant bcdivmod(const Variant &num1, const Variant &num2, const Variant &scale = {});
Variant bcpowmod(const Variant &num, const Variant &exponent, const Variant &modulus, const Variant &scale = {});
Variant bcpow(const Variant &num, const Variant &exponent, const Variant &scale = {});
Variant bcsqrt(const Variant &num, const Variant &scale = {});
Variant bccomp(const Variant &num1, const Variant &num2, const Variant &scale = {});
Variant bcscale(const Variant &scale = {});
Variant bcfloor(const Variant &num);
Variant bcceil(const Variant &num);
Variant bcround(const Variant &num, const Variant &precision = 0, const Variant &mode = {});
}  // namespace php
