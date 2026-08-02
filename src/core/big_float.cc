#include "phpx_big_float.h"

namespace php {

static inline BigFloat *newBigFloatImpl() {
    return new BigFloat();
}

class BigFloatOperand {
  public:
    mpfr_t temporary;
    mpfr_srcptr value = nullptr;
    bool temporary_initialized = false;

    BigFloatOperand() = default;
    void initTemporary() {
        if (!temporary_initialized) {
            mpfr_init2(temporary, BIG_FLOAT_DEFAULT_PRECISION);
            temporary_initialized = true;
        }
    }
    ~BigFloatOperand() {
        if (temporary_initialized) {
            mpfr_clear(temporary);
        }
    }
    BigFloatOperand(const BigFloatOperand &) = delete;
    BigFloatOperand &operator=(const BigFloatOperand &) = delete;
};

static inline bool extractBigFloat(Variant &v, BigFloatOperand &out) {
    if (v.isResource()) {
        auto *bf = v.toBox<BigFloat>();
        if (bf) {
            out.value = bf->value;
            return true;
        }
    }
    if (v.isInt()) {
        out.initTemporary();
        mpfr_set_sj(out.temporary, v.toInt(), MPFR_RNDN);
        out.value = out.temporary;
        return true;
    }
    if (v.isFloat()) {
        out.initTemporary();
        mpfr_set_str(out.temporary, v.toString().data(), 10, MPFR_RNDN);
        out.value = out.temporary;
        return true;
    }
    if (v.isString()) {
        out.initTemporary();
        if (UNEXPECTED(mpfr_set_str(out.temporary, v.toString().data(), 10, MPFR_RNDN) != 0)) {
            throwException(zend_ce_value_error, "Invalid BigFloat numeric string");
            return false;
        }
        out.value = out.temporary;
        return true;
    }
    throwException(zend_ce_type_error, "expects valid BigFloat argument");
    return false;
}

Variant BigFloat::newInstance(Variant s) {
    if (s.isResource() && s.toBox<BigFloat>()) {
        return s;
    }
    if (s.isInt()) {
        return Variant(new BigFloat(s.toInt()));
    }
    if (s.isFloat()) {
        return Variant(new BigFloat(s.toFloat()));
    }
    return Variant(new BigFloat(s.toString().data()));
}

Variant BigFloat::add(Variant a, Variant b) {
    BigFloatOperand va, vb;
    if (UNEXPECTED(!extractBigFloat(a, va) || !extractBigFloat(b, vb))) {
        return nullptr;
    }
    auto *result = newBigFloatImpl();
    mpfr_add(result->value, va.value, vb.value, MPFR_RNDN);
    return Variant(result);
}

Variant BigFloat::sub(Variant a, Variant b) {
    BigFloatOperand va, vb;
    if (UNEXPECTED(!extractBigFloat(a, va) || !extractBigFloat(b, vb))) {
        return nullptr;
    }
    auto *result = newBigFloatImpl();
    mpfr_sub(result->value, va.value, vb.value, MPFR_RNDN);
    return Variant(result);
}

Variant BigFloat::mul(Variant a, Variant b) {
    BigFloatOperand va, vb;
    if (UNEXPECTED(!extractBigFloat(a, va) || !extractBigFloat(b, vb))) {
        return nullptr;
    }
    auto *result = newBigFloatImpl();
    mpfr_mul(result->value, va.value, vb.value, MPFR_RNDN);
    return Variant(result);
}

Variant BigFloat::div(Variant a, Variant b) {
    BigFloatOperand va, vb;
    if (UNEXPECTED(!extractBigFloat(a, va) || !extractBigFloat(b, vb))) {
        return nullptr;
    }
    if (mpfr_zero_p(vb.value)) {
        throwException(zend_ce_division_by_zero_error, "Division by zero");
        return nullptr;
    }
    auto *result = newBigFloatImpl();
    mpfr_div(result->value, va.value, vb.value, MPFR_RNDN);
    return Variant(result);
}

Variant BigFloat::neg(Variant a) {
    BigFloatOperand va;
    if (UNEXPECTED(!extractBigFloat(a, va))) {
        return nullptr;
    }
    auto *result = newBigFloatImpl();
    mpfr_neg(result->value, va.value, MPFR_RNDN);
    return Variant(result);
}

Variant BigFloat::cmp(Variant a, Variant b) {
    BigFloatOperand va, vb;
    if (UNEXPECTED(!extractBigFloat(a, va) || !extractBigFloat(b, vb))) {
        return nullptr;
    }
    if (mpfr_nan_p(va.value) || mpfr_nan_p(vb.value)) {
        throwException(zend_ce_arithmetic_error, "Cannot compare NaN BigFloat values");
        return nullptr;
    }
    return Variant(mpfr_cmp(va.value, vb.value));
}

Variant BigFloat::abs(Variant a) {
    BigFloatOperand va;
    if (UNEXPECTED(!extractBigFloat(a, va))) {
        return nullptr;
    }
    auto *result = newBigFloatImpl();
    mpfr_abs(result->value, va.value, MPFR_RNDN);
    return Variant(result);
}

Variant BigFloat::sqrt(Variant a) {
    BigFloatOperand va;
    if (UNEXPECTED(!extractBigFloat(a, va))) {
        return nullptr;
    }
    if (mpfr_sgn(va.value) < 0) {
        throwException(zend_ce_type_error, "BigFloat::sqrt: cannot compute square root of negative number");
        return nullptr;
    }
    auto *result = newBigFloatImpl();
    mpfr_sqrt(result->value, va.value, MPFR_RNDN);
    return Variant(result);
}

Variant BigFloat::toString(Variant a) {
    auto *bf = a.toBox<BigFloat>();
    if (UNEXPECTED(!bf)) {
        throwException(zend_ce_type_error, "expects BigFloat argument");
        return nullptr;
    }
    if (mpfr_nan_p(bf->value)) {
        return Variant("NAN");
    }
    if (mpfr_inf_p(bf->value)) {
        return Variant(mpfr_signbit(bf->value) ? "-INF" : "INF");
    }
    if (mpfr_zero_p(bf->value)) {
        return Variant("0");
    }
    mpfr_exp_t exp;
    char *str = mpfr_get_str(nullptr, &exp, 10, BIG_FLOAT_OUTPUT_DIGITS, bf->value, MPFR_RNDN);
    if (!str) {
        return Variant("0");
    }
    std::string result;
    bool negative = (str[0] == '-');
    const char *digits = negative ? str + 1 : str;
    size_t len = strlen(digits);
    constexpr mpfr_exp_t MAX_PLAIN_STRING_EXPONENT = 10000;
    if (exp > MAX_PLAIN_STRING_EXPONENT || exp < -MAX_PLAIN_STRING_EXPONENT) {
        result = digits[0];
        if (len > 1) {
            result += '.';
            result.append(digits + 1);
            while (result.back() == '0') {
                result.pop_back();
            }
            if (result.back() == '.') {
                result.pop_back();
            }
        }
        result += 'E';
        result += std::to_string(exp - 1);
    } else if (exp <= 0) {
        result = "0.";
        for (mpfr_exp_t i = 0; i < -exp; i++) result += '0';
        result += digits;
    } else if ((size_t) exp >= len) {
        result = digits;
        for (size_t i = 0; i < (size_t) exp - len; i++) result += '0';
    } else {
        result = std::string(digits, exp) + "." + (digits + exp);
    }
    if (negative) result = "-" + result;
    mpfr_free_str(str);
    auto dotPos = result.find('.');
    if (dotPos != std::string::npos) {
        while (result.size() > dotPos + 1 && result.back() == '0') {
            result.pop_back();
        }
        if (result.back() == '.') {
            result.pop_back();
        }
    }
    return Variant(result);
}

Variant BigFloat::toInt(Variant a) {
    auto *bf = a.toBox<BigFloat>();
    if (UNEXPECTED(!bf)) {
        throwException(zend_ce_type_error, "expects BigFloat argument");
        return nullptr;
    }
    if (!mpfr_number_p(bf->value) || !mpfr_fits_intmax_p(bf->value, MPFR_RNDZ)) {
        throwException(zend_ce_arithmetic_error, "BigFloat value is outside the PHP int range");
        return nullptr;
    }
    return Variant((php::Int) mpfr_get_sj(bf->value, MPFR_RNDZ));
}

Variant BigFloat::toFloat(Variant a) {
    auto *bf = a.toBox<BigFloat>();
    if (UNEXPECTED(!bf)) {
        throwException(zend_ce_type_error, "expects BigFloat argument");
        return nullptr;
    }
    return Variant((php::Float) mpfr_get_d(bf->value, MPFR_RNDN));
}

Variant BigFloat::toBool(Variant a) {
    auto *bf = a.toBox<BigFloat>();
    if (UNEXPECTED(!bf)) {
        throwException(zend_ce_type_error, "expects BigFloat argument");
        return nullptr;
    }
    return Variant(!mpfr_zero_p(bf->value));
}

}  // namespace php
