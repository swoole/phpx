#include "phpx.h"

namespace php {
Variant bcadd(const Variant &num1, const Variant &num2, const Variant &scale) {
    return call("bcadd", {num1, num2, scale});
}
Variant bcsub(const Variant &num1, const Variant &num2, const Variant &scale) {
    return call("bcsub", {num1, num2, scale});
}
Variant bcmul(const Variant &num1, const Variant &num2, const Variant &scale) {
    return call("bcmul", {num1, num2, scale});
}
Variant bcdiv(const Variant &num1, const Variant &num2, const Variant &scale) {
    return call("bcdiv", {num1, num2, scale});
}
Variant bcmod(const Variant &num1, const Variant &num2, const Variant &scale) {
    return call("bcmod", {num1, num2, scale});
}
Variant bcdivmod(const Variant &num1, const Variant &num2, const Variant &scale) {
    return call("bcdivmod", {num1, num2, scale});
}
Variant bcpowmod(const Variant &num, const Variant &exponent, const Variant &modulus, const Variant &scale) {
    return call("bcpowmod", {num, exponent, modulus, scale});
}
Variant bcpow(const Variant &num, const Variant &exponent, const Variant &scale) {
    return call("bcpow", {num, exponent, scale});
}
Variant bcsqrt(const Variant &num, const Variant &scale) {
    return call("bcsqrt", {num, scale});
}
Variant bccomp(const Variant &num1, const Variant &num2, const Variant &scale) {
    return call("bccomp", {num1, num2, scale});
}
Variant bcscale(const Variant &scale) {
    return call("bcscale", {scale});
}
Variant bcfloor(const Variant &num) {
    return call("bcfloor", {num});
}
Variant bcceil(const Variant &num) {
    return call("bcceil", {num});
}
Variant bcround(const Variant &num, const Variant &precision, const Variant &mode) {
    return call("bcround", {num, precision, mode});
}
}
