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
        out = mpz_class((signed long)v.toInt());
        return true;
    }
    return false;
}

Variant BigInt::newInstance(Variant s) {
    return Variant(new BigInt(s.toString().toCString()));
}

Variant BigInt::add(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        throwError("BigInt::add expects BigInt arguments");
        return nullptr;
    }
    return Variant(new BigInt(va + vb));
}

Variant BigInt::sub(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        throwError("BigInt::sub expects BigInt arguments");
        return nullptr;
    }
    return Variant(new BigInt(va - vb));
}

Variant BigInt::mul(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        throwError("BigInt::mul expects BigInt arguments");
        return nullptr;
    }
    return Variant(new BigInt(va * vb));
}

Variant BigInt::div(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        throwError("BigInt::div expects BigInt arguments");
        return nullptr;
    }
    if (vb == 0) {
        throwError("Division by zero");
        return nullptr;
    }
    return Variant(new BigInt(va / vb));
}

Variant BigInt::mod(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        throwError("BigInt::mod expects BigInt arguments");
        return nullptr;
    }
    if (vb == 0) {
        throwError("Division by zero");
        return nullptr;
    }
    return Variant(new BigInt(va % vb));
}

Variant BigInt::pow(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        throwError("BigInt::pow expects BigInt arguments");
        return nullptr;
    }
    if (vb < 0) {
        throwError("Negative exponent not supported");
        return nullptr;
    }
    mpz_class result;
    mpz_pow_ui(result.get_mpz_t(), va.get_mpz_t(), vb.get_ui());
    return Variant(new BigInt(result));
}

Variant BigInt::neg(Variant a) {
    mpz_class va;
    if (UNEXPECTED(!extractBigInt(a, va))) {
        throwError("BigInt::neg expects BigInt argument");
        return nullptr;
    }
    return Variant(new BigInt(-va));
}

Variant BigInt::cmp(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        throwError("BigInt::cmp expects BigInt arguments");
        return nullptr;
    }
    return Variant(mpz_cmp(va.get_mpz_t(), vb.get_mpz_t()));
}

Variant BigInt::abs(Variant a) {
    mpz_class va;
    if (UNEXPECTED(!extractBigInt(a, va))) {
        throwError("BigInt::abs expects BigInt argument");
        return nullptr;
    }
    mpz_class r;
    mpz_abs(r.get_mpz_t(), va.get_mpz_t());
    return Variant(new BigInt(r));
}

Variant BigInt::gcd(Variant a, Variant b) {
    mpz_class va, vb;
    if (UNEXPECTED(!extractBigInt(a, va) || !extractBigInt(b, vb))) {
        throwError("BigInt::gcd expects BigInt arguments");
        return nullptr;
    }
    mpz_class result;
    mpz_gcd(result.get_mpz_t(), va.get_mpz_t(), vb.get_mpz_t());
    return Variant(new BigInt(result));
}

Variant BigInt::toString(Variant a) {
    auto *bi_a = a.toBox<BigInt>();
    if (UNEXPECTED(!bi_a)) {
        throwError("BigInt::toString expects BigInt argument");
        return nullptr;
    }
    return Variant(bi_a->value.get_str());
}

Variant BigInt::toInt(Variant a) {
    auto *bi_a = a.toBox<BigInt>();
    if (UNEXPECTED(!bi_a)) {
        throwError("BigInt::toInt expects BigInt argument");
        return nullptr;
    }
    return Variant((php::Int)bi_a->value.get_si());
}

Variant BigInt::toFloat(Variant a) {
    auto *bi_a = a.toBox<BigInt>();
    if (UNEXPECTED(!bi_a)) {
        throwError("BigInt::toFloat expects BigInt argument");
        return nullptr;
    }
    return Variant(bi_a->value.get_d());
}

Variant BigInt::toBigDecimal(Variant a) {
    // Placeholder — will be implemented when BigDecimal is added
    return a;
}

}  // namespace php
