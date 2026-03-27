#include "phpx.h"
#include "class/bcmath.h"

namespace php {
BcMath_Number::BcMath_Number(const Variant &num) {
    this_ = newObject(LITERAL_STRING[15], {num});
}
Variant BcMath_Number::add(const Variant &num, const Variant &scale) {
    return this_.call(LITERAL_STRING[16], {num, scale});
}
Variant BcMath_Number::sub(const Variant &num, const Variant &scale) {
    return this_.call(LITERAL_STRING[17], {num, scale});
}
Variant BcMath_Number::mul(const Variant &num, const Variant &scale) {
    return this_.call(LITERAL_STRING[18], {num, scale});
}
Variant BcMath_Number::div(const Variant &num, const Variant &scale) {
    return this_.call(LITERAL_STRING[19], {num, scale});
}
Variant BcMath_Number::mod(const Variant &num, const Variant &scale) {
    return this_.call(LITERAL_STRING[20], {num, scale});
}
Variant BcMath_Number::divmod(const Variant &num, const Variant &scale) {
    return this_.call(LITERAL_STRING[21], {num, scale});
}
Variant BcMath_Number::powmod(const Variant &exponent, const Variant &modulus, const Variant &scale) {
    return this_.call(LITERAL_STRING[22], {exponent, modulus, scale});
}
Variant BcMath_Number::pow(const Variant &exponent, const Variant &scale) {
    return this_.call(LITERAL_STRING[23], {exponent, scale});
}
Variant BcMath_Number::sqrt(const Variant &scale) {
    return this_.call(LITERAL_STRING[24], {scale});
}
Variant BcMath_Number::floor() {
    return this_.call(LITERAL_STRING[25], {});
}
Variant BcMath_Number::ceil() {
    return this_.call(LITERAL_STRING[26], {});
}
Variant BcMath_Number::round(const Variant &precision, const Variant &mode) {
    return this_.call(LITERAL_STRING[27], {precision, mode});
}
Variant BcMath_Number::compare(const Variant &num, const Variant &scale) {
    return this_.call(LITERAL_STRING[28], {num, scale});
}
Variant BcMath_Number::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant BcMath_Number::__serialize() {
    return this_.call(LITERAL_STRING[30], {});
}
Variant BcMath_Number::__unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[31], {data});
}
}  // namespace php
