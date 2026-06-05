#include "phpx_big_float.h"

namespace php {

static inline BigFloat *newBigFloatImpl() {
    return new BigFloat();
}
static inline BigFloat *newBigFloatImplCopy(mpfr_t src) {
    auto *bf = new BigFloat();
    mpfr_set(bf->value, src, MPFR_RNDN);
    return bf;
}

static inline bool extractBigFloat(Variant &v, mpfr_t &out) {
    if (v.isResource()) {
        auto *bf = v.toBox<BigFloat>();
        if (bf) {
            mpfr_set(out, bf->value, MPFR_RNDN);
            return true;
        }
    }
    if (v.isInt()) {
        mpfr_set_sj(out, v.toInt(), MPFR_RNDN);
        return true;
    }
    if (v.isFloat()) {
        mpfr_set_d(out, v.toFloat(), MPFR_RNDN);
        return true;
    }
    if (v.isString()) {
        mpfr_set_str(out, v.toString().data(), 10, MPFR_RNDN);
        return true;
    }
    throwException(zend_ce_type_error, "expects valid BigFloat argument");
    return false;
}

Variant BigFloat::newInstance(Variant s) {
    if (s.isResource() && s.toBox<BigFloat>()) {
        return s;
    }
    return Variant(new BigFloat(s.toString().data()));
}

Variant BigFloat::add(Variant a, Variant b) {
    mpfr_t va, vb, vr;
    mpfr_inits(va, vb, vr, (mpfr_ptr) nullptr);
    if (UNEXPECTED(!extractBigFloat(a, va) || !extractBigFloat(b, vb))) {
        mpfr_clears(va, vb, vr, (mpfr_ptr) nullptr);
        return nullptr;
    }
    mpfr_add(vr, va, vb, MPFR_RNDN);
    auto *result = newBigFloatImplCopy(vr);
    mpfr_clears(va, vb, vr, (mpfr_ptr) nullptr);
    return Variant(result);
}

Variant BigFloat::sub(Variant a, Variant b) {
    mpfr_t va, vb, vr;
    mpfr_inits(va, vb, vr, (mpfr_ptr) nullptr);
    if (UNEXPECTED(!extractBigFloat(a, va) || !extractBigFloat(b, vb))) {
        mpfr_clears(va, vb, vr, (mpfr_ptr) nullptr);
        return nullptr;
    }
    mpfr_sub(vr, va, vb, MPFR_RNDN);
    auto *result = newBigFloatImplCopy(vr);
    mpfr_clears(va, vb, vr, (mpfr_ptr) nullptr);
    return Variant(result);
}

Variant BigFloat::mul(Variant a, Variant b) {
    mpfr_t va, vb, vr;
    mpfr_inits(va, vb, vr, (mpfr_ptr) nullptr);
    if (UNEXPECTED(!extractBigFloat(a, va) || !extractBigFloat(b, vb))) {
        mpfr_clears(va, vb, vr, (mpfr_ptr) nullptr);
        return nullptr;
    }
    mpfr_mul(vr, va, vb, MPFR_RNDN);
    auto *result = newBigFloatImplCopy(vr);
    mpfr_clears(va, vb, vr, (mpfr_ptr) nullptr);
    return Variant(result);
}

Variant BigFloat::div(Variant a, Variant b) {
    mpfr_t va, vb, vr;
    mpfr_inits(va, vb, vr, (mpfr_ptr) nullptr);
    if (UNEXPECTED(!extractBigFloat(a, va) || !extractBigFloat(b, vb))) {
        mpfr_clears(va, vb, vr, (mpfr_ptr) nullptr);
        return nullptr;
    }
    mpfr_div(vr, va, vb, MPFR_RNDN);
    auto *result = newBigFloatImplCopy(vr);
    mpfr_clears(va, vb, vr, (mpfr_ptr) nullptr);
    return Variant(result);
}

Variant BigFloat::neg(Variant a) {
    mpfr_t va;
    mpfr_init(va);
    if (UNEXPECTED(!extractBigFloat(a, va))) {
        mpfr_clear(va);
        return nullptr;
    }
    auto *result = newBigFloatImpl();
    mpfr_neg(result->value, va, MPFR_RNDN);
    mpfr_clear(va);
    return Variant(result);
}

Variant BigFloat::cmp(Variant a, Variant b) {
    mpfr_t va, vb;
    mpfr_inits(va, vb, (mpfr_ptr) nullptr);
    if (UNEXPECTED(!extractBigFloat(a, va) || !extractBigFloat(b, vb))) {
        mpfr_clears(va, vb, (mpfr_ptr) nullptr);
        return nullptr;
    }
    int result = mpfr_cmp(va, vb);
    mpfr_clears(va, vb, (mpfr_ptr) nullptr);
    return Variant(result);
}

Variant BigFloat::abs(Variant a) {
    mpfr_t va;
    mpfr_init(va);
    if (UNEXPECTED(!extractBigFloat(a, va))) {
        mpfr_clear(va);
        return nullptr;
    }
    auto *result = newBigFloatImpl();
    mpfr_abs(result->value, va, MPFR_RNDN);
    mpfr_clear(va);
    return Variant(result);
}

Variant BigFloat::sqrt(Variant a) {
    mpfr_t va;
    mpfr_init(va);
    if (UNEXPECTED(!extractBigFloat(a, va))) {
        mpfr_clear(va);
        return nullptr;
    }
    if (mpfr_sgn(va) < 0) {
        mpfr_clear(va);
        throwException(zend_ce_type_error, "BigFloat::sqrt: cannot compute square root of negative number");
        return nullptr;
    }
    auto *result = newBigFloatImpl();
    mpfr_sqrt(result->value, va, MPFR_RNDN);
    mpfr_clear(va);
    return Variant(result);
}

Variant BigFloat::toString(Variant a) {
    auto *bf = a.toBox<BigFloat>();
    if (UNEXPECTED(!bf)) {
        throwException(zend_ce_type_error, "expects BigFloat argument");
        return nullptr;
    }
    mpfr_exp_t exp;
    char *str = mpfr_get_str(nullptr, &exp, 10, 0, bf->value, MPFR_RNDN);
    if (!str) {
        return Variant("0");
    }
    std::string result;
    bool negative = (str[0] == '-');
    const char *digits = negative ? str + 1 : str;
    size_t len = strlen(digits);
    if (exp <= 0) {
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

}  // namespace php
