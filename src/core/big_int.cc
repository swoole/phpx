#include "phpx_big_int.h"

#include <optional>

namespace php {

class BigIntOperand {
  public:
    const mpz_class *value = nullptr;
    std::optional<mpz_class> temporary;
};

static inline bool extractBigInt(Variant &v, BigIntOperand &out) {
    if (v.isResource()) {
        auto *bi = v.toBox<BigInt>();
        if (bi) {
            out.value = &bi->value;
            return true;
        }
    }
    if (v.isInt()) {
        out.temporary.emplace();
        detail::setBigIntFromPhpInt(*out.temporary, v.toInt());
        out.value = &*out.temporary;
        return true;
    }
    throwException(zend_ce_type_error, "expects BigInt argument");
    return false;
}

Variant BigInt::newInstance(Variant s) {
    if (UNEXPECTED(s.isFloat())) {
        throwException(zend_ce_type_error, "Cannot construct BigInt from float, use string or int instead");
        return null;
    }
    if (s.isResource() && s.toBox<BigInt>()) {
        return s;
    }
    if (s.isInt()) {
        return Variant(new BigInt(s.toInt()));
    }
    return Variant(new BigInt(s.toString().toCString()));
}

Variant BigInt::add(Variant a, Variant b) {
    BigIntOperand va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_add(result->value.get_mpz_t(), va.value->get_mpz_t(), vb.value->get_mpz_t());
    return Variant(result);
}

Variant BigInt::sub(Variant a, Variant b) {
    BigIntOperand va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_sub(result->value.get_mpz_t(), va.value->get_mpz_t(), vb.value->get_mpz_t());
    return Variant(result);
}

Variant BigInt::mul(Variant a, Variant b) {
    BigIntOperand va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_mul(result->value.get_mpz_t(), va.value->get_mpz_t(), vb.value->get_mpz_t());
    return Variant(result);
}

Variant BigInt::div(Variant a, Variant b) {
    BigIntOperand va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    if (mpz_sgn(vb.value->get_mpz_t()) == 0) {
        throwException(zend_ce_division_by_zero_error, "Division by zero");
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_tdiv_q(result->value.get_mpz_t(), va.value->get_mpz_t(), vb.value->get_mpz_t());
    return Variant(result);
}

Variant BigInt::mod(Variant a, Variant b) {
    BigIntOperand va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    if (mpz_sgn(vb.value->get_mpz_t()) == 0) {
        throwException(zend_ce_division_by_zero_error, "Division by zero");
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_tdiv_r(result->value.get_mpz_t(), va.value->get_mpz_t(), vb.value->get_mpz_t());
    return Variant(result);
}

Variant BigInt::pow(Variant a, Variant b) {
    BigIntOperand va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    if (mpz_sgn(vb.value->get_mpz_t()) < 0) {
        throwException(zend_ce_type_error, "Negative exponent not supported");
        return nullptr;
    }
    if (!mpz_fits_ulong_p(vb.value->get_mpz_t())) {
        throwException(zend_ce_value_error, "BigInt exponent is too large");
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_pow_ui(result->value.get_mpz_t(), va.value->get_mpz_t(), mpz_get_ui(vb.value->get_mpz_t()));
    return Variant(result);
}

Variant BigInt::neg(Variant a) {
    BigIntOperand va;
    if (UNEXPECTED(!extractBigInt(a, va))) {
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_neg(result->value.get_mpz_t(), va.value->get_mpz_t());
    return Variant(result);
}

Variant BigInt::cmp(Variant a, Variant b) {
    BigIntOperand va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    return Variant(mpz_cmp(va.value->get_mpz_t(), vb.value->get_mpz_t()));
}

Variant BigInt::abs(Variant a) {
    BigIntOperand va;
    if (UNEXPECTED(!extractBigInt(a, va))) {
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_abs(result->value.get_mpz_t(), va.value->get_mpz_t());
    return Variant(result);
}

Variant BigInt::gcd(Variant a, Variant b) {
    BigIntOperand va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_gcd(result->value.get_mpz_t(), va.value->get_mpz_t(), vb.value->get_mpz_t());
    return Variant(result);
}

Variant BigInt::toString(Variant a) {
    auto *bi_a = a.toBox<BigInt>();
    if (UNEXPECTED(!bi_a)) {
        throwException(zend_ce_type_error, "BigInt::toString expects BigInt argument");
        return nullptr;
    }
    return Variant(bi_a->value.get_str());
}

Variant BigInt::toInt(Variant a) {
    auto *bi_a = a.toBox<BigInt>();
    if (UNEXPECTED(!bi_a)) {
        throwException(zend_ce_type_error, "BigInt::toInt expects BigInt argument");
        return nullptr;
    }
    static const mpz_class minValue(std::to_string(ZEND_LONG_MIN));
    static const mpz_class maxValue(std::to_string(ZEND_LONG_MAX));
    if (bi_a->value < minValue || bi_a->value > maxValue) {
        throwException(zend_ce_arithmetic_error, "BigInt value is outside the PHP int range");
        return nullptr;
    }
    return Variant((php::Int) std::stoll(bi_a->value.get_str()));
}

Variant BigInt::toFloat(Variant a) {
    auto *bi_a = a.toBox<BigInt>();
    if (UNEXPECTED(!bi_a)) {
        throwException(zend_ce_type_error, "BigInt::toFloat expects BigInt argument");
        return nullptr;
    }
    return Variant(bi_a->value.get_d());
}

Variant BigInt::toBool(Variant a) {
    auto *bi_a = a.toBox<BigInt>();
    if (UNEXPECTED(!bi_a)) {
        throwException(zend_ce_type_error, "BigInt::toBool expects BigInt argument");
        return nullptr;
    }
    return Variant(mpz_sgn(bi_a->value.get_mpz_t()) != 0);
}

Variant BigInt::divmod(Variant a, Variant b) {
    BigIntOperand va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    if (mpz_sgn(vb.value->get_mpz_t()) == 0) {
        throwException(zend_ce_division_by_zero_error, "Division by zero");
        return nullptr;
    }
    auto *q = new BigInt();
    auto *r = new BigInt();
    mpz_tdiv_qr(q->value.get_mpz_t(), r->value.get_mpz_t(), va.value->get_mpz_t(), vb.value->get_mpz_t());
    Array result(2);
    result.append(Variant(q));
    result.append(Variant(r));
    return result;
}

Variant BigInt::powmod(Variant base, Variant exp, Variant mod) {
    BigIntOperand vb, ve, vm;
    if (UNEXPECTED(!extractBigInt(base, vb) || !extractBigInt(exp, ve) || !extractBigInt(mod, vm))) {
        return nullptr;
    }
    if (mpz_sgn(vm.value->get_mpz_t()) == 0) {
        throwException(zend_ce_division_by_zero_error, "Modulo by zero in powmod");
        return nullptr;
    }
    if (mpz_sgn(ve.value->get_mpz_t()) < 0) {
        throwException(zend_ce_type_error, "Negative exponent not supported in powmod");
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_powm(result->value.get_mpz_t(), vb.value->get_mpz_t(), ve.value->get_mpz_t(), vm.value->get_mpz_t());
    return Variant(result);
}

Variant BigInt::sqrt(Variant a) {
    BigIntOperand va;
    if (UNEXPECTED(!extractBigInt(a, va))) {
        return nullptr;
    }
    if (mpz_sgn(va.value->get_mpz_t()) < 0) {
        throwException(zend_ce_type_error, "Cannot compute square root of negative BigInt");
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_sqrt(result->value.get_mpz_t(), va.value->get_mpz_t());
    return Variant(result);
}

Variant BigInt::bitAnd(Variant a, Variant b) {
    BigIntOperand va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_and(result->value.get_mpz_t(), va.value->get_mpz_t(), vb.value->get_mpz_t());
    return Variant(result);
}

Variant BigInt::bitOr(Variant a, Variant b) {
    BigIntOperand va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_ior(result->value.get_mpz_t(), va.value->get_mpz_t(), vb.value->get_mpz_t());
    return Variant(result);
}

Variant BigInt::bitXor(Variant a, Variant b) {
    BigIntOperand va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_xor(result->value.get_mpz_t(), va.value->get_mpz_t(), vb.value->get_mpz_t());
    return Variant(result);
}

Variant BigInt::bitNot(Variant a) {
    BigIntOperand va;
    if (UNEXPECTED(!extractBigInt(a, va))) {
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_com(result->value.get_mpz_t(), va.value->get_mpz_t());
    return Variant(result);
}

Variant BigInt::testBit(Variant a, Variant index) {
    BigIntOperand va;
    if (UNEXPECTED(!extractBigInt(a, va))) {
        return nullptr;
    }
    if (!index.isInt()) {
        throwException(zend_ce_type_error, "testBit expects int index");
        return nullptr;
    }
    if (index.toInt() < 0) {
        throwException(zend_ce_value_error, "testBit index must be non-negative");
        return nullptr;
    }
    return Variant(mpz_tstbit(va.value->get_mpz_t(), (mp_bitcnt_t) index.toInt()));
}

Variant BigInt::popCount(Variant a) {
    BigIntOperand va;
    if (UNEXPECTED(!extractBigInt(a, va))) {
        return nullptr;
    }
    if (mpz_sgn(va.value->get_mpz_t()) < 0) {
        throwException(zend_ce_value_error, "popCount is undefined for negative BigInt values");
        return nullptr;
    }
    mp_bitcnt_t count = mpz_popcount(va.value->get_mpz_t());
    if (count > (mp_bitcnt_t) ZEND_LONG_MAX) {
        throwException(zend_ce_arithmetic_error, "BigInt popCount exceeds the PHP int range");
        return nullptr;
    }
    return Variant((php::Int) count);
}

Variant BigInt::bitShiftLeft(Variant a, Variant n) {
    BigIntOperand va;
    if (UNEXPECTED(!extractBigInt(a, va))) {
        return nullptr;
    }
    if (UNEXPECTED(!n.isInt())) {
        throwException(zend_ce_type_error, "bitShiftLeft expects int shift amount");
        return nullptr;
    }
    php::Int shift = n.toInt();
    if (shift < 0) {
        throwException(zend_ce_value_error, "bitShiftLeft shift amount must be non-negative");
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_mul_2exp(result->value.get_mpz_t(), va.value->get_mpz_t(), (mp_bitcnt_t) shift);
    return Variant(result);
}

Variant BigInt::bitShiftRight(Variant a, Variant n) {
    BigIntOperand va;
    if (UNEXPECTED(!extractBigInt(a, va))) {
        return nullptr;
    }
    if (UNEXPECTED(!n.isInt())) {
        throwException(zend_ce_type_error, "bitShiftRight expects int shift amount");
        return nullptr;
    }
    php::Int shift = n.toInt();
    if (shift < 0) {
        throwException(zend_ce_value_error, "bitShiftRight shift amount must be non-negative");
        return nullptr;
    }
    auto *result = new BigInt();
    mpz_fdiv_q_2exp(result->value.get_mpz_t(), va.value->get_mpz_t(), (mp_bitcnt_t) shift);
    return Variant(result);
}

Variant BigInt::toBigDecimal(Variant a) {
    return a;
}

}  // namespace php
