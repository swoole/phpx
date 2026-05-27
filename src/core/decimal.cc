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
        out = decimal::Decimal((int64_t) v.toInt());
        return true;
    }
    if (v.isFloat()) {
        throwException(zend_ce_type_error, "Cannot convert float to Decimal, use string or int instead");
    }
    if (v.isString()) {
        out = decimal::Decimal(v.toString().data());
        return true;
    }
    throwException(zend_ce_type_error, "expects valid Decimal argument");
    return false;
}

Variant Decimal::newInstance(Variant s) {
    if (UNEXPECTED(s.isFloat())) {
        throwException(zend_ce_type_error, "Cannot construct Decimal from float, use string or int instead");
    }
    return Variant(new Decimal(s.toString().toCString()));
}

Variant Decimal::add(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        return nullptr;
    }
    return Variant(new Decimal(va + vb));
}

Variant Decimal::sub(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        return nullptr;
    }
    return Variant(new Decimal(va - vb));
}

Variant Decimal::mul(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        return nullptr;
    }
    return Variant(new Decimal(va * vb));
}

Variant Decimal::div(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        return nullptr;
    }
    return Variant(new Decimal(va / vb));
}

Variant Decimal::mod(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        return nullptr;
    }
    return Variant(new Decimal(va % vb));
}

Variant Decimal::neg(Variant a) {
    decimal::Decimal va;
    if (UNEXPECTED(!extractDecimal(a, va))) {
        return nullptr;
    }
    return Variant(new Decimal(-va));
}

Variant Decimal::cmp(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        return nullptr;
    }
    if (va < vb) return Variant(-1);
    if (va > vb) return Variant(1);
    return Variant(0);
}

Variant Decimal::abs(Variant a) {
    decimal::Decimal va;
    if (UNEXPECTED(!extractDecimal(a, va))) {
        return nullptr;
    }
    return Variant(new Decimal(va.sign() < 0 ? -va : va));
}

Variant Decimal::toString(Variant a) {
    auto *d = a.toBox<Decimal>();
    if (UNEXPECTED(!d)) {
        throwException(zend_ce_type_error, "expects Decimal argument");
        return nullptr;
    }
    return Variant(d->value.to_sci());
}

Variant Decimal::toInt(Variant a) {
    auto *d = a.toBox<Decimal>();
    if (UNEXPECTED(!d)) {
        throwException(zend_ce_type_error, "expects Decimal argument");
        return nullptr;
    }
    // Truncate toward zero with traps disabled (truncation sets Inexact flag)
    decimal::Context ctx = decimal::context;
    ctx.clear_traps();
    decimal::Decimal truncated = d->value.trunc(ctx);

    uint32_t status = 0;
    int64_t val = mpd_qget_i64(truncated.getconst(), &status);
    if (status & MPD_Invalid_operation) {
        throwException(zend_ce_type_error, "value too large for int64");
        return nullptr;
    }
    return Variant((php::Int) val);
}

Variant Decimal::toFloat(Variant a) {
    auto *d = a.toBox<Decimal>();
    if (UNEXPECTED(!d)) {
        throwException(zend_ce_type_error, "expects Decimal argument");
        return nullptr;
    }
    return Variant((php::Float) std::stod(d->value.to_sci()));
}

Variant Decimal::pow(Variant base, Variant exp) {
    decimal::Decimal vb, ve;
    if (UNEXPECTED(!extractDecimal(base, vb) || !extractDecimal(exp, ve))) {
        return nullptr;
    }
    decimal::Decimal result;
    uint32_t status = 0;
    mpd_qpow(result.get(), vb.getconst(), ve.getconst(), decimal::context.getconst(), &status);
    if (status & MPD_Invalid_operation) {
        throwException(zend_ce_type_error, "Decimal::pow: invalid operation");
        return nullptr;
    }
    return Variant(new Decimal(result));
}

Variant Decimal::divmod(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        return nullptr;
    }
    decimal::Decimal q, r;
    uint32_t status = 0;
    mpd_qdivmod(q.get(), r.get(), va.getconst(), vb.getconst(), decimal::context.getconst(), &status);
    if (status & MPD_Division_by_zero) {
        throwException(zend_ce_type_error, "Division by zero");
        return nullptr;
    }
    Array result(2);
    result.append(Variant(new Decimal(q)));
    result.append(Variant(new Decimal(r)));
    return result;
}

Variant Decimal::powmod(Variant base, Variant exp, Variant mod) {
    decimal::Decimal vb, ve, vm;
    if (UNEXPECTED(!extractDecimal(base, vb) || !extractDecimal(exp, ve) || !extractDecimal(mod, vm))) {
        return nullptr;
    }
    decimal::Decimal result;
    uint32_t status = 0;
    mpd_qpowmod(result.get(), vb.getconst(), ve.getconst(), vm.getconst(), decimal::context.getconst(), &status);
    if (status & MPD_Invalid_operation) {
        throwException(zend_ce_type_error, "Decimal::powmod: invalid operation");
        return nullptr;
    }
    return Variant(new Decimal(result));
}

Variant Decimal::sqrt(Variant a) {
    decimal::Decimal va;
    if (UNEXPECTED(!extractDecimal(a, va))) {
        return nullptr;
    }
    decimal::Decimal result;
    uint32_t status = 0;
    mpd_qsqrt(result.get(), va.getconst(), decimal::context.getconst(), &status);
    if (status & MPD_Invalid_operation) {
        throwException(zend_ce_type_error, "Decimal::sqrt: invalid operation (negative number?)");
        return nullptr;
    }
    return Variant(new Decimal(result));
}

Variant Decimal::floor(Variant a) {
    decimal::Decimal va;
    if (UNEXPECTED(!extractDecimal(a, va))) {
        return nullptr;
    }
    return Variant(new Decimal(va.floor()));
}

Variant Decimal::ceil(Variant a) {
    decimal::Decimal va;
    if (UNEXPECTED(!extractDecimal(a, va))) {
        return nullptr;
    }
    return Variant(new Decimal(va.ceil()));
}

Variant Decimal::round(Variant a, Variant precision) {
    decimal::Decimal va;
    if (UNEXPECTED(!extractDecimal(a, va))) {
        return nullptr;
    }
    php::Int prec = precision.toInt();
    if (prec == 0) {
        return Variant(new Decimal(va.to_integral()));
    }
    // Build quantum = 10^(-prec)
    std::string quantumStr;
    if (prec > 0) {
        quantumStr = "1E-" + std::to_string(prec);
    } else {
        quantumStr = "1E" + std::to_string(-prec);
    }
    decimal::Decimal quantum(quantumStr);
    return Variant(new Decimal(va.quantize(quantum)));
}

Variant Decimal::toBigInt(Variant a) {
    // Placeholder — will be implemented when BigInt<->Decimal conversion is needed
    return a;
}

}  // namespace php
