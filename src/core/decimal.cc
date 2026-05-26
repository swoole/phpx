#include "phpx.h"
#include "phpx_decimal.h"
#include <string>

namespace php {

static inline bool extractDecimal(Variant &v, decimal::Decimal &out) {
    if (v.isResource()) {
        auto *d = v.toBox<Decimal>();
        if (d) {
            out = d->value;
            return true;
        }
    }
    if (v.isInt()) {
        out = decimal::Decimal((int64_t)v.toInt());
        return true;
    }
    if (v.isFloat()) {
        out = decimal::Decimal(v.toString().data());
        return true;
    }
    if (v.isString()) {
        out = decimal::Decimal(v.toString().data());
        return true;
    }
    return false;
}

Variant Decimal::newInstance(Variant s) {
    return Variant(new Decimal(s.toString().toCString()));
}

Variant Decimal::add(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        throwError("Decimal::add expects valid Decimal arguments");
        return nullptr;
    }
    return Variant(new Decimal(va + vb));
}

Variant Decimal::sub(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        throwError("Decimal::sub expects valid Decimal arguments");
        return nullptr;
    }
    return Variant(new Decimal(va - vb));
}

Variant Decimal::mul(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        throwError("Decimal::mul expects valid Decimal arguments");
        return nullptr;
    }
    return Variant(new Decimal(va * vb));
}

Variant Decimal::div(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        throwError("Decimal::div expects valid Decimal arguments");
        return nullptr;
    }
    return Variant(new Decimal(va / vb));
}

Variant Decimal::mod(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        throwError("Decimal::mod expects valid Decimal arguments");
        return nullptr;
    }
    return Variant(new Decimal(va % vb));
}

Variant Decimal::neg(Variant a) {
    decimal::Decimal va;
    if (UNEXPECTED(!extractDecimal(a, va))) {
        throwError("Decimal::neg expects Decimal argument");
        return nullptr;
    }
    return Variant(new Decimal(-va));
}

Variant Decimal::cmp(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        throwError("Decimal::cmp expects valid Decimal arguments");
        return nullptr;
    }
    if (va < vb) return Variant(-1);
    if (va > vb) return Variant(1);
    return Variant(0);
}

Variant Decimal::abs(Variant a) {
    decimal::Decimal va;
    if (UNEXPECTED(!extractDecimal(a, va))) {
        throwError("Decimal::abs expects Decimal argument");
        return nullptr;
    }
    return Variant(new Decimal(va.sign() < 0 ? -va : va));
}

Variant Decimal::toString(Variant a) {
    auto *d = a.toBox<Decimal>();
    if (UNEXPECTED(!d)) {
        throwError("Decimal::toString expects Decimal argument");
        return nullptr;
    }
    return Variant(d->value.to_sci());
}

Variant Decimal::toInt(Variant a) {
    auto *d = a.toBox<Decimal>();
    if (UNEXPECTED(!d)) {
        throwError("Decimal::toInt expects Decimal argument");
        return nullptr;
    }
    // Truncate toward zero with traps disabled (truncation sets Inexact flag)
    decimal::Context ctx = decimal::context;
    ctx.clear_traps();
    decimal::Decimal truncated = d->value.trunc(ctx);

    uint32_t status = 0;
    int64_t val = mpd_qget_i64(truncated.getconst(), &status);
    if (status & MPD_Invalid_operation) {
        throwError("Decimal::toInt: value too large for int64");
        return nullptr;
    }
    return Variant((php::Int)val);
}

Variant Decimal::toFloat(Variant a) {
    auto *d = a.toBox<Decimal>();
    if (UNEXPECTED(!d)) {
        throwError("Decimal::toFloat expects Decimal argument");
        return nullptr;
    }
    return Variant((php::Float)std::stod(d->value.to_sci()));
}

Variant Decimal::toBigInt(Variant a) {
    // Placeholder — will be implemented when BigInt<->Decimal conversion is needed
    return a;
}

}  // namespace php
