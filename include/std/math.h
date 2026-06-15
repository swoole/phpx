/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP math functions               |
  +----------------------------------------------------------------------+
  | round via PHPAPI _php_math_round()                                    |
  +----------------------------------------------------------------------+
*/

#pragma once

#include "phpx.h"

extern "C" {
#include "ext/standard/php_math.h"
}

namespace php::fn {

// Scalar overloads (dispatch before the Variant overload)
inline Int abs(Int v) {
    return std::abs(v);
}

inline Float abs(Float v) {
    return std::fabs(v);
}

// round(mixed $num, int $precision = 0, int $mode = PHP_ROUND_HALF_UP): float
Float round(const Variant &value, Int precision = 0, Int mode = PHP_ROUND_HALF_UP);

// abs(mixed $value): int|float
inline Variant abs(const Variant &value) {
    if (value.isInt()) {
        Int v = value.toInt();
        if (v == ZEND_LONG_MIN) {
            return Variant(static_cast<Float>(-static_cast<double>(ZEND_LONG_MIN)));
        }
        return Variant(v >= 0 ? v : -v);
    }
    return Variant(static_cast<Float>(::fabs(value.toFloat())));
}

// floor(float $num): float
inline Float floor(const Variant &value) {
    return static_cast<Float>(::floor(value.toFloat()));
}

// ceil(float $num): float
inline Float ceil(const Variant &value) {
    return static_cast<Float>(::ceil(value.toFloat()));
}

// ========================
// Trigonometric functions
// ========================

inline Float sin(const Variant &value) {
    return static_cast<Float>(::sin(value.toFloat()));
}

inline Float cos(const Variant &value) {
    return static_cast<Float>(::cos(value.toFloat()));
}

inline Float tan(const Variant &value) {
    return static_cast<Float>(::tan(value.toFloat()));
}

inline Float asin(const Variant &value) {
    return static_cast<Float>(::asin(value.toFloat()));
}

inline Float acos(const Variant &value) {
    return static_cast<Float>(::acos(value.toFloat()));
}

inline Float atan(const Variant &value) {
    return static_cast<Float>(::atan(value.toFloat()));
}

inline Float atan2(const Variant &y, const Variant &x) {
    return static_cast<Float>(::atan2(y.toFloat(), x.toFloat()));
}

// ========================
// Hyperbolic functions
// ========================

inline Float sinh(const Variant &value) {
    return static_cast<Float>(::sinh(value.toFloat()));
}

inline Float cosh(const Variant &value) {
    return static_cast<Float>(::cosh(value.toFloat()));
}

inline Float tanh(const Variant &value) {
    return static_cast<Float>(::tanh(value.toFloat()));
}

inline Float asinh(const Variant &value) {
    return static_cast<Float>(::asinh(value.toFloat()));
}

inline Float acosh(const Variant &value) {
    return static_cast<Float>(::acosh(value.toFloat()));
}

inline Float atanh(const Variant &value) {
    return static_cast<Float>(::atanh(value.toFloat()));
}

// ========================
// pi
// ========================

inline Float pi() {
    return M_PI;
}

// ========================
// Exponential and logarithmic
// ========================

inline Float exp(const Variant &value) {
    return static_cast<Float>(::exp(value.toFloat()));
}

inline Float expm1(const Variant &value) {
    return static_cast<Float>(::expm1(value.toFloat()));
}

inline Float log(const Variant &num) {
    return static_cast<Float>(::log(num.toFloat()));
}

inline Float log(const Variant &num, Float base) {
    if (base == 2.0) {
        return static_cast<Float>(::log2(num.toFloat()));
    }
    if (base == 10.0) {
        return static_cast<Float>(::log10(num.toFloat()));
    }
    if (base == 1.0) {
        return NAN;
    }
    if (base <= 0.0) {
        php::throwException(zend_ce_value_error, "log(): Argument #2 ($base) must be greater than 0");
        return 0.0;
    }
    return static_cast<Float>(::log(num.toFloat()) / ::log(base));
}

inline Float log10(const Variant &value) {
    return static_cast<Float>(::log10(value.toFloat()));
}

inline Float log1p(const Variant &value) {
    return static_cast<Float>(::log1p(value.toFloat()));
}

inline Float sqrt(const Variant &value) {
    return static_cast<Float>(::sqrt(value.toFloat()));
}

// ========================
// hypot, deg2rad, rad2deg
// ========================

inline Float hypot(const Variant &x, const Variant &y) {
    return static_cast<Float>(::hypot(x.toFloat(), y.toFloat()));
}

inline Float deg2rad(const Variant &value) {
    return static_cast<Float>((value.toFloat() / 180.0) * M_PI);
}

inline Float rad2deg(const Variant &value) {
    return static_cast<Float>((value.toFloat() / M_PI) * 180);
}

// ========================
// fmod, fdiv, pow
// ========================

inline Float fmod(const Variant &num1, const Variant &num2) {
    return static_cast<Float>(::fmod(num1.toFloat(), num2.toFloat()));
}

inline Variant mod(const Variant &a, const Variant &b) {
    return a % b;
}

inline Float fdiv(const Variant &dividend, const Variant &divisor) {
    return static_cast<Float>(dividend.toFloat() / divisor.toFloat());
}

inline Variant pow(const Variant &base, const Variant &exp) {
    zval ret;
    pow_function(&ret, NO_CONST_V(base), NO_CONST_V(exp));
    return Variant(&ret, Ctor::Move);
}

inline Float fpow(const Variant &base, const Variant &exponent) {
    return static_cast<Float>(::pow(base.toFloat(), exponent.toFloat()));
}

inline Int intdiv(const Variant &dividend, const Variant &divisor) {
    zend_long d1 = dividend.toInt();
    zend_long d2 = divisor.toInt();
    if (d2 == 0) {
        throwExceptionEx(zend_ce_division_by_zero_error, 0, "Division by zero");
        return 0;
    }
    if (d2 == -1 && d1 == ZEND_LONG_MIN) {
        throwExceptionEx(zend_ce_arithmetic_error, 0, "Division of PHP_INT_MIN by -1 is not an integer");
        return 0;
    }
    return static_cast<Int>(d1 / d2);
}

// ========================
// is_finite, is_infinite, is_nan
// ========================

inline bool is_finite(const Variant &value) {
    return isfinite(value.toFloat());
}

inline bool is_infinite(const Variant &value) {
    return isinf(value.toFloat());
}

inline bool is_nan(const Variant &value) {
    return isnan(value.toFloat());
}

// ========================
// Base conversion (PHPAPI)
// ========================

inline String decbin(Int arg) {
    return String(_php_math_longtobase(arg, 2), Ctor::Move);
}

inline String decoct(Int arg) {
    return String(_php_math_longtobase(arg, 8), Ctor::Move);
}

inline String dechex(Int arg) {
    return String(_php_math_longtobase(arg, 16), Ctor::Move);
}

inline Variant bindec(const String &s) {
    zval ret;
    _php_math_basetozval(Z_STR_P(NO_CONST_V(s)), 2, &ret);
    return Variant(&ret, Ctor::Move);
}

inline Variant hexdec(const String &s) {
    zval ret;
    _php_math_basetozval(Z_STR_P(NO_CONST_V(s)), 16, &ret);
    return Variant(&ret, Ctor::Move);
}

inline Variant octdec(const String &s) {
    zval ret;
    _php_math_basetozval(Z_STR_P(NO_CONST_V(s)), 8, &ret);
    return Variant(&ret, Ctor::Move);
}

inline String base_convert(const String &number, Int frombase, Int tobase) {
    if (frombase < 2 || frombase > 36) {
        php::throwException(zend_ce_value_error,
                            "base_convert(): Argument #2 ($from_base) must be between 2 and 36 (inclusive)");
        return String();
    }
    if (tobase < 2 || tobase > 36) {
        php::throwException(zend_ce_value_error,
                            "base_convert(): Argument #3 ($to_base) must be between 2 and 36 (inclusive)");
        return String();
    }
    zval temp;
    _php_math_basetozval(Z_STR_P(NO_CONST_V(number)), (int) frombase, &temp);
    zend_string *result = _php_math_zvaltobase(&temp, (int) tobase);
    if (!result) {
        return String();
    }
    return String(result, Ctor::Move);
}

// number_format
inline String number_format(const Variant &num,
                            Int decimals = 0,
                            const String &dec_point = String(".", 1),
                            const String &thousand_sep = String(",", 1)) {
    zend_string *result = _php_math_number_format_ex(num.toFloat(),
                                                     (int) decimals,
                                                     dec_point.data(),
                                                     dec_point.length(),
                                                     thousand_sep.data(),
                                                     thousand_sep.length());
    return String(result, Ctor::Move);
}

}  // namespace php::fn
