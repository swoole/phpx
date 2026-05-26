#include "phpx.h"
#include "phpx_big_int.h"

namespace php {

Variant BigInt::newInstance(Variant s) {
    return Variant(new BigInt(s.toString().toCString()));
}

Variant BigInt::add(Variant a, Variant b) {
    auto *bi_a = a.toBox<BigInt>();
    auto *bi_b = b.toBox<BigInt>();
    if (UNEXPECTED(!bi_a || !bi_b)) {
        throwError("BigInt::add expects BigInt arguments");
        return nullptr;
    }
    return Variant(new BigInt(bi_a->value + bi_b->value));
}

Variant BigInt::sub(Variant a, Variant b) {
    auto *bi_a = a.toBox<BigInt>();
    auto *bi_b = b.toBox<BigInt>();
    if (UNEXPECTED(!bi_a || !bi_b)) {
        throwError("BigInt::sub expects BigInt arguments");
        return nullptr;
    }
    return Variant(new BigInt(bi_a->value - bi_b->value));
}

Variant BigInt::mul(Variant a, Variant b) {
    auto *bi_a = a.toBox<BigInt>();
    auto *bi_b = b.toBox<BigInt>();
    if (UNEXPECTED(!bi_a || !bi_b)) {
        throwError("BigInt::mul expects BigInt arguments");
        return nullptr;
    }
    return Variant(new BigInt(bi_a->value * bi_b->value));
}

Variant BigInt::div(Variant a, Variant b) {
    auto *bi_a = a.toBox<BigInt>();
    auto *bi_b = b.toBox<BigInt>();
    if (UNEXPECTED(!bi_a || !bi_b)) {
        throwError("BigInt::div expects BigInt arguments");
        return nullptr;
    }
    if (bi_b->value == 0) {
        throwError("Division by zero");
        return nullptr;
    }
    return Variant(new BigInt(bi_a->value / bi_b->value));
}

Variant BigInt::mod(Variant a, Variant b) {
    auto *bi_a = a.toBox<BigInt>();
    auto *bi_b = b.toBox<BigInt>();
    if (UNEXPECTED(!bi_a || !bi_b)) {
        throwError("BigInt::mod expects BigInt arguments");
        return nullptr;
    }
    if (bi_b->value == 0) {
        throwError("Division by zero");
        return nullptr;
    }
    return Variant(new BigInt(bi_a->value % bi_b->value));
}

Variant BigInt::pow(Variant a, Variant b) {
    auto *bi_a = a.toBox<BigInt>();
    auto *bi_b = b.toBox<BigInt>();
    if (UNEXPECTED(!bi_a || !bi_b)) {
        throwError("BigInt::pow expects BigInt arguments");
        return nullptr;
    }
    if (bi_b->value < 0) {
        throwError("Negative exponent not supported");
        return nullptr;
    }
    mpz_class result;
    mpz_pow_ui(result.get_mpz_t(), bi_a->value.get_mpz_t(), bi_b->value.get_ui());
    return Variant(new BigInt(result));
}

Variant BigInt::neg(Variant a) {
    auto *bi_a = a.toBox<BigInt>();
    if (UNEXPECTED(!bi_a)) {
        throwError("BigInt::neg expects BigInt argument");
        return nullptr;
    }
    return Variant(new BigInt(-bi_a->value));
}

Variant BigInt::cmp(Variant a, Variant b) {
    auto *bi_a = a.toBox<BigInt>();
    auto *bi_b = b.toBox<BigInt>();
    if (UNEXPECTED(!bi_a || !bi_b)) {
        throwError("BigInt::cmp expects BigInt arguments");
        return nullptr;
    }
    return Variant(mpz_cmp(bi_a->value.get_mpz_t(), bi_b->value.get_mpz_t()));
}

Variant BigInt::abs(Variant a) {
    auto *bi_a = a.toBox<BigInt>();
    if (UNEXPECTED(!bi_a)) {
        throwError("BigInt::abs expects BigInt argument");
        return nullptr;
    }
    mpz_class r;
    mpz_abs(r.get_mpz_t(), bi_a->value.get_mpz_t());
    return Variant(new BigInt(r));
}

Variant BigInt::gcd(Variant a, Variant b) {
    auto *bi_a = a.toBox<BigInt>();
    auto *bi_b = b.toBox<BigInt>();
    if (UNEXPECTED(!bi_a || !bi_b)) {
        throwError("BigInt::gcd expects BigInt arguments");
        return nullptr;
    }
    mpz_class result;
    mpz_gcd(result.get_mpz_t(), bi_a->value.get_mpz_t(), bi_b->value.get_mpz_t());
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
