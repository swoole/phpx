#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant bcadd(const Variant &num1, const Variant &num2, const Variant &scale) {
    return call(LITERAL_STRING[0], {num1, num2, scale});
}
Variant bcsub(const Variant &num1, const Variant &num2, const Variant &scale) {
    return call(LITERAL_STRING[1], {num1, num2, scale});
}
Variant bcmul(const Variant &num1, const Variant &num2, const Variant &scale) {
    return call(LITERAL_STRING[2], {num1, num2, scale});
}
Variant bcdiv(const Variant &num1, const Variant &num2, const Variant &scale) {
    return call(LITERAL_STRING[3], {num1, num2, scale});
}
Variant bcmod(const Variant &num1, const Variant &num2, const Variant &scale) {
    return call(LITERAL_STRING[4], {num1, num2, scale});
}
Variant bcdivmod(const Variant &num1, const Variant &num2, const Variant &scale) {
    return call(LITERAL_STRING[5], {num1, num2, scale});
}
Variant bcpowmod(const Variant &num, const Variant &exponent, const Variant &modulus, const Variant &scale) {
    return call(LITERAL_STRING[6], {num, exponent, modulus, scale});
}
Variant bcpow(const Variant &num, const Variant &exponent, const Variant &scale) {
    return call(LITERAL_STRING[7], {num, exponent, scale});
}
Variant bcsqrt(const Variant &num, const Variant &scale) {
    return call(LITERAL_STRING[8], {num, scale});
}
Variant bccomp(const Variant &num1, const Variant &num2, const Variant &scale) {
    return call(LITERAL_STRING[9], {num1, num2, scale});
}
Variant bcscale(const Variant &scale) {
    return call(LITERAL_STRING[10], {scale});
}
Variant bcfloor(const Variant &num) {
    return call(LITERAL_STRING[11], {num});
}
Variant bcceil(const Variant &num) {
    return call(LITERAL_STRING[12], {num});
}
Variant bcround(const Variant &num, const Variant &precision, const Variant &mode) {
    return call(LITERAL_STRING[13], {num, precision, mode});
}
}  // namespace php
