#include "phpx_decimal.h"
#include <decimal.hh>
#include <string>

namespace php {

struct Decimal::Data {
    decimal::Decimal value;
    Data() = default;
    explicit Data(const char *s) : value(s) {}
    explicit Data(const decimal::Decimal &v) : value(v) {}
    explicit Data(php::Int v) : value((int64_t) v) {}
};

Decimal::Decimal() : data(new Data()) {}
Decimal::Decimal(const String &s) : data(new Data(s.data())) {}
Decimal::Decimal(php::Int v) : data(new Data(v)) {}
Decimal::~Decimal() { delete data; }

static inline Decimal *newDecimalImpl(const decimal::Decimal &v) {
    auto *d = new Decimal();
    d->data->value = v;
    return d;
}

static inline bool extractDecimal(Variant &v, decimal::Decimal &out) {
    if (v.isResource()) {
        auto *d = v.toBox<Decimal>();
        if (d && d->data) {
            out = d->data->value;
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
    if (s.isResource() && s.toBox<Decimal>()) {
        return s;
    }
    return Variant(new Decimal(s.toString().toCString()));
}

Variant Decimal::add(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        return nullptr;
    }
    return Variant(newDecimalImpl(va + vb));
}

Variant Decimal::sub(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        return nullptr;
    }
    return Variant(newDecimalImpl(va - vb));
}

Variant Decimal::mul(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        return nullptr;
    }
    return Variant(newDecimalImpl(va * vb));
}

Variant Decimal::div(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        return nullptr;
    }
    return Variant(newDecimalImpl(va / vb));
}

Variant Decimal::mod(Variant a, Variant b) {
    decimal::Decimal va, vb;
    if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
        return nullptr;
    }
    return Variant(newDecimalImpl(va % vb));
}

Variant Decimal::neg(Variant a) {
    decimal::Decimal va;
    if (UNEXPECTED(!extractDecimal(a, va))) {
        return nullptr;
    }
    return Variant(newDecimalImpl(-va));
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
    return Variant(newDecimalImpl(va.sign() < 0 ? -va : va));
}

Variant Decimal::toString(Variant a) {
    auto *d = a.toBox<Decimal>();
    if (UNEXPECTED(!d || !d->data)) {
        throwException(zend_ce_type_error, "expects Decimal argument");
        return nullptr;
    }
    return Variant(d->data->value.to_sci());
}

Variant Decimal::toInt(Variant a) {
    auto *d = a.toBox<Decimal>();
    if (UNEXPECTED(!d || !d->data)) {
        throwException(zend_ce_type_error, "expects Decimal argument");
        return nullptr;
    }
    decimal::Context ctx = decimal::context;
    ctx.clear_traps();
    decimal::Decimal truncated = d->data->value.trunc(ctx);

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
    if (UNEXPECTED(!d || !d->data)) {
        throwException(zend_ce_type_error, "expects Decimal argument");
        return nullptr;
    }
    return Variant((php::Float) std::stod(d->data->value.to_sci()));
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
    return Variant(newDecimalImpl(result));
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
    result.append(Variant(newDecimalImpl(q)));
    result.append(Variant(newDecimalImpl(r)));
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
    return Variant(newDecimalImpl(result));
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
    return Variant(newDecimalImpl(result));
}

Variant Decimal::floor(Variant a) {
    decimal::Decimal va;
    if (UNEXPECTED(!extractDecimal(a, va))) {
        return nullptr;
    }
    return Variant(newDecimalImpl(va.floor()));
}

Variant Decimal::ceil(Variant a) {
    decimal::Decimal va;
    if (UNEXPECTED(!extractDecimal(a, va))) {
        return nullptr;
    }
    return Variant(newDecimalImpl(va.ceil()));
}

Variant Decimal::round(Variant a, Variant precision) {
    decimal::Decimal va;
    if (UNEXPECTED(!extractDecimal(a, va))) {
        return nullptr;
    }
    php::Int prec = precision.toInt();
    if (prec == 0) {
        return Variant(newDecimalImpl(va.to_integral()));
    }
    decimal::Decimal result;
    uint32_t status = 0;
    mpd_ssize_t targetExp = -(mpd_ssize_t) prec;
    mpd_qrescale(result.get(), va.getconst(), targetExp, decimal::context.getconst(), &status);
    if (status & MPD_Invalid_operation) {
        throwException(zend_ce_type_error, "Decimal::round: invalid operation");
        return nullptr;
    }
    return Variant(newDecimalImpl(result));
}

Variant Decimal::toBigInt(Variant a) {
    // Placeholder — will be implemented when BigInt<->Decimal conversion is needed
    return a;
}

}  // namespace php
