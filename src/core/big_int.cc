#include "phpx.h"
#include "phpx_big_int.h"

namespace php {

static inline bool extractBigInt(Variant &v, mpz_class &out) {
    if (v.isResource()) {
        auto *bi = v.toBox<BigInt>();
        if (bi) {
            out = bi->value;
            return true;
        }
    }
    if (v.isInt()) {
        out = mpz_class((signed long) v.toInt());
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
    return Variant(new BigInt(s.toString().toCString()));
}

Variant BigInt::add(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    return Variant(new BigInt(va + vb));
}

Variant BigInt::sub(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    return Variant(new BigInt(va - vb));
}

Variant BigInt::mul(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    return Variant(new BigInt(va * vb));
}

Variant BigInt::div(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    if (vb == 0) {
        throwException(zend_ce_type_error, "Division by zero");
        return nullptr;
    }
    return Variant(new BigInt(va / vb));
}

Variant BigInt::mod(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    if (vb == 0) {
        throwException(zend_ce_type_error, "Division by zero");
        return nullptr;
    }
    return Variant(new BigInt(va % vb));
}

Variant BigInt::pow(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    if (vb < 0) {
        throwException(zend_ce_type_error, "Negative exponent not supported");
        return nullptr;
    }
    mpz_class result;
    mpz_pow_ui(result.get_mpz_t(), va.get_mpz_t(), vb.get_ui());
    return Variant(new BigInt(result));
}

Variant BigInt::neg(Variant a) {
    mpz_class va;
    if (UNEXPECTED(!extractBigInt(a, va))) {
        return nullptr;
    }
    return Variant(new BigInt(-va));
}

Variant BigInt::cmp(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    return Variant(mpz_cmp(va.get_mpz_t(), vb.get_mpz_t()));
}

Variant BigInt::abs(Variant a) {
    mpz_class va;
    if (UNEXPECTED(!extractBigInt(a, va))) {
        return nullptr;
    }
    mpz_class r;
    mpz_abs(r.get_mpz_t(), va.get_mpz_t());
    return Variant(new BigInt(r));
}

Variant BigInt::gcd(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    mpz_class result;
    mpz_gcd(result.get_mpz_t(), va.get_mpz_t(), vb.get_mpz_t());
    return Variant(new BigInt(result));
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
    return Variant((php::Int) bi_a->value.get_si());
}

Variant BigInt::toFloat(Variant a) {
    auto *bi_a = a.toBox<BigInt>();
    if (UNEXPECTED(!bi_a)) {
        throwException(zend_ce_type_error, "BigInt::toFloat expects BigInt argument");
        return nullptr;
    }
    return Variant(bi_a->value.get_d());
}

Variant BigInt::divmod(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        return nullptr;
    }
    if (vb == 0) {
        throwException(zend_ce_type_error, "Division by zero");
        return nullptr;
    }
    mpz_class q, r;
    mpz_tdiv_qr(q.get_mpz_t(), r.get_mpz_t(), va.get_mpz_t(), vb.get_mpz_t());
    Array result(2);
    result.append(Variant(new BigInt(q)));
    result.append(Variant(new BigInt(r)));
    return result;
}

Variant BigInt::powmod(Variant base, Variant exp, Variant mod) {
    mpz_class vb, ve, vm;
    if (UNEXPECTED(!extractBigInt(base, vb) || !extractBigInt(exp, ve) || !extractBigInt(mod, vm))) {
        return nullptr;
    }
    if (vm == 0) {
        throwException(zend_ce_type_error, "Modulo by zero in powmod");
        return nullptr;
    }
    if (ve < 0) {
        throwException(zend_ce_type_error, "Negative exponent not supported in powmod");
        return nullptr;
    }
    mpz_class result;
    mpz_powm(result.get_mpz_t(), vb.get_mpz_t(), ve.get_mpz_t(), vm.get_mpz_t());
    return Variant(new BigInt(result));
}

Variant BigInt::sqrt(Variant a) {
    mpz_class va;
    if (UNEXPECTED(!extractBigInt(a, va))) {
        return nullptr;
    }
    if (va < 0) {
        throwException(zend_ce_type_error, "Cannot compute square root of negative BigInt");
        return nullptr;
    }
    mpz_class result;
    mpz_sqrt(result.get_mpz_t(), va.get_mpz_t());
    return Variant(new BigInt(result));
}

Variant BigInt::toBigDecimal(Variant a) {
    // Placeholder — will be implemented when BigDecimal is added
    return a;
}

}  // namespace php
