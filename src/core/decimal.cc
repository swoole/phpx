#include "phpx_decimal.h"

#include <optional>

namespace php {

static constexpr mpd_ssize_t DECIMAL_DEFAULT_PRECISION = 50;

void initDecimalContext() {
    decimal::context.prec(DECIMAL_DEFAULT_PRECISION);
}

template <typename Callable>
static inline Variant decimalBoundary(Callable &&callable) {
    try {
        return std::forward<Callable>(callable)();
    } catch (const decimal::ConversionSyntax &e) {
        return throwException(zend_ce_value_error, e.what());
    } catch (const decimal::ValueError &e) {
        return throwException(zend_ce_value_error, e.what());
    } catch (const decimal::DivisionByZero &e) {
        return throwException(zend_ce_division_by_zero_error, e.what());
    } catch (const decimal::DecimalException &e) {
        return throwException(zend_ce_arithmetic_error, e.what());
    } catch (const std::invalid_argument &e) {
        return throwException(zend_ce_value_error, e.what());
    } catch (const std::out_of_range &e) {
        return throwException(zend_ce_arithmetic_error, e.what());
    }
}

class DecimalOperand {
  public:
    const decimal::Decimal *value = nullptr;
    std::optional<decimal::Decimal> temporary;
};

static inline bool extractDecimal(Variant &v, DecimalOperand &out) {
    if (v.isResource()) {
        auto *d = v.toBox<Decimal>();
        if (d) {
            out.value = &d->value;
            return true;
        }
    }
    if (v.isInt()) {
        out.temporary.emplace((int64_t) v.toInt());
        out.value = &*out.temporary;
        return true;
    }
    if (v.isFloat()) {
        throwException(zend_ce_type_error, "Cannot convert float to Decimal, use string or int instead");
    }
    if (v.isString()) {
        out.temporary.emplace(v.toString().data());
        out.value = &*out.temporary;
        return true;
    }
    throwException(zend_ce_type_error, "expects valid Decimal argument");
    return false;
}

Variant Decimal::newInstance(Variant s) {
    return decimalBoundary([&]() -> Variant {
        if (UNEXPECTED(s.isFloat())) {
            throwException(zend_ce_type_error, "Cannot construct Decimal from float, use string or int instead");
        }
        if (s.isResource() && s.toBox<Decimal>()) {
            return s;
        }
        if (s.isInt()) {
            return Variant(new Decimal(s.toInt()));
        }
        return Variant(new Decimal(s.toString().toCString()));
    });
}

Variant Decimal::add(Variant a, Variant b) {
    return decimalBoundary([&]() -> Variant {
        DecimalOperand va, vb;
        if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
            return nullptr;
        }
        auto result = std::make_unique<Decimal>();
        uint32_t status = 0;
        mpd_qadd(result->value.get(), va.value->getconst(), vb.value->getconst(), decimal::context.getconst(), &status);
        decimal::context.raise(status);
        return Variant(result.release());
    });
}

Variant Decimal::sub(Variant a, Variant b) {
    return decimalBoundary([&]() -> Variant {
        DecimalOperand va, vb;
        if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
            return nullptr;
        }
        auto result = std::make_unique<Decimal>();
        uint32_t status = 0;
        mpd_qsub(result->value.get(), va.value->getconst(), vb.value->getconst(), decimal::context.getconst(), &status);
        decimal::context.raise(status);
        return Variant(result.release());
    });
}

Variant Decimal::mul(Variant a, Variant b) {
    return decimalBoundary([&]() -> Variant {
        DecimalOperand va, vb;
        if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
            return nullptr;
        }
        auto result = std::make_unique<Decimal>();
        uint32_t status = 0;
        mpd_qmul(result->value.get(), va.value->getconst(), vb.value->getconst(), decimal::context.getconst(), &status);
        decimal::context.raise(status);
        return Variant(result.release());
    });
}

Variant Decimal::div(Variant a, Variant b) {
    return decimalBoundary([&]() -> Variant {
        DecimalOperand va, vb;
        if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
            return nullptr;
        }
        auto result = std::make_unique<Decimal>();
        uint32_t status = 0;
        mpd_qdiv(result->value.get(), va.value->getconst(), vb.value->getconst(), decimal::context.getconst(), &status);
        decimal::context.raise(status);
        return Variant(result.release());
    });
}

Variant Decimal::mod(Variant a, Variant b) {
    return decimalBoundary([&]() -> Variant {
        DecimalOperand va, vb;
        if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
            return nullptr;
        }
        auto result = std::make_unique<Decimal>();
        uint32_t status = 0;
        mpd_qrem(result->value.get(), va.value->getconst(), vb.value->getconst(), decimal::context.getconst(), &status);
        decimal::context.raise(status);
        return Variant(result.release());
    });
}

Variant Decimal::neg(Variant a) {
    return decimalBoundary([&]() -> Variant {
        DecimalOperand va;
        if (UNEXPECTED(!extractDecimal(a, va))) {
            return nullptr;
        }
        auto result = std::make_unique<Decimal>();
        uint32_t status = 0;
        mpd_qminus(result->value.get(), va.value->getconst(), decimal::context.getconst(), &status);
        decimal::context.raise(status);
        return Variant(result.release());
    });
}

Variant Decimal::cmp(Variant a, Variant b) {
    return decimalBoundary([&]() -> Variant {
        DecimalOperand va, vb;
        if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
            return nullptr;
        }
        if (va.value->isnan() || vb.value->isnan()) {
            throwException(zend_ce_arithmetic_error, "Cannot compare NaN Decimal values");
            return nullptr;
        }
        uint32_t status = 0;
        int result = mpd_qcmp(va.value->getconst(), vb.value->getconst(), &status);
        decimal::context.raise(status);
        return Variant(result < 0 ? -1 : result > 0 ? 1 : 0);
    });
}

Variant Decimal::abs(Variant a) {
    return decimalBoundary([&]() -> Variant {
        DecimalOperand va;
        if (UNEXPECTED(!extractDecimal(a, va))) {
            return nullptr;
        }
        auto result = std::make_unique<Decimal>();
        uint32_t status = 0;
        mpd_qabs(result->value.get(), va.value->getconst(), decimal::context.getconst(), &status);
        decimal::context.raise(status);
        return Variant(result.release());
    });
}

Variant Decimal::toString(Variant a) {
    return decimalBoundary([&]() -> Variant {
        auto *d = a.toBox<Decimal>();
        if (UNEXPECTED(!d)) {
            throwException(zend_ce_type_error, "expects Decimal argument");
            return nullptr;
        }
        return Variant(d->value.to_sci());
    });
}

Variant Decimal::toInt(Variant a) {
    return decimalBoundary([&]() -> Variant {
        auto *d = a.toBox<Decimal>();
        if (UNEXPECTED(!d)) {
            throwException(zend_ce_type_error, "expects Decimal argument");
            return nullptr;
        }
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
    });
}

Variant Decimal::toFloat(Variant a) {
    return decimalBoundary([&]() -> Variant {
        auto *d = a.toBox<Decimal>();
        if (UNEXPECTED(!d)) {
            throwException(zend_ce_type_error, "expects Decimal argument");
            return nullptr;
        }
        return Variant((php::Float) std::stod(d->value.to_sci()));
    });
}

Variant Decimal::toBool(Variant a) {
    return decimalBoundary([&]() -> Variant {
        auto *d = a.toBox<Decimal>();
        if (UNEXPECTED(!d)) {
            throwException(zend_ce_type_error, "expects Decimal argument");
            return nullptr;
        }
        return Variant(!d->value.iszero());
    });
}

Variant Decimal::pow(Variant base, Variant exp) {
    return decimalBoundary([&]() -> Variant {
        DecimalOperand vb, ve;
        if (UNEXPECTED(!extractDecimal(base, vb) || !extractDecimal(exp, ve))) {
            return nullptr;
        }
        auto result = std::make_unique<Decimal>();
        uint32_t status = 0;
        mpd_qpow(result->value.get(), vb.value->getconst(), ve.value->getconst(), decimal::context.getconst(), &status);
        if (status & MPD_Invalid_operation) {
            throwException(zend_ce_type_error, "Decimal::pow: invalid operation");
            return nullptr;
        }
        decimal::context.raise(status);
        return Variant(result.release());
    });
}

Variant Decimal::divmod(Variant a, Variant b) {
    return decimalBoundary([&]() -> Variant {
        DecimalOperand va, vb;
        if (UNEXPECTED(!extractDecimal(a, va) || !extractDecimal(b, vb))) {
            return nullptr;
        }
        auto q = std::make_unique<Decimal>();
        auto r = std::make_unique<Decimal>();
        uint32_t status = 0;
        mpd_qdivmod(q->value.get(),
                    r->value.get(),
                    va.value->getconst(),
                    vb.value->getconst(),
                    decimal::context.getconst(),
                    &status);
        if (status & MPD_Division_by_zero) {
            throwException(zend_ce_division_by_zero_error, "Division by zero");
            return nullptr;
        }
        decimal::context.raise(status);
        Array result(2);
        result.append(Variant(q.release()));
        result.append(Variant(r.release()));
        return result;
    });
}

Variant Decimal::powmod(Variant base, Variant exp, Variant mod) {
    return decimalBoundary([&]() -> Variant {
        DecimalOperand vb, ve, vm;
        if (UNEXPECTED(!extractDecimal(base, vb) || !extractDecimal(exp, ve) || !extractDecimal(mod, vm))) {
            return nullptr;
        }
        auto result = std::make_unique<Decimal>();
        uint32_t status = 0;
        mpd_qpowmod(result->value.get(),
                    vb.value->getconst(),
                    ve.value->getconst(),
                    vm.value->getconst(),
                    decimal::context.getconst(),
                    &status);
        if (status & MPD_Invalid_operation) {
            throwException(zend_ce_type_error, "Decimal::powmod: invalid operation");
            return nullptr;
        }
        decimal::context.raise(status);
        return Variant(result.release());
    });
}

Variant Decimal::sqrt(Variant a) {
    return decimalBoundary([&]() -> Variant {
        DecimalOperand va;
        if (UNEXPECTED(!extractDecimal(a, va))) {
            return nullptr;
        }
        auto result = std::make_unique<Decimal>();
        uint32_t status = 0;
        mpd_qsqrt(result->value.get(), va.value->getconst(), decimal::context.getconst(), &status);
        if (status & MPD_Invalid_operation) {
            throwException(zend_ce_type_error, "Decimal::sqrt: invalid operation (negative number?)");
            return nullptr;
        }
        decimal::context.raise(status);
        return Variant(result.release());
    });
}

Variant Decimal::floor(Variant a) {
    return decimalBoundary([&]() -> Variant {
        DecimalOperand va;
        if (UNEXPECTED(!extractDecimal(a, va))) {
            return nullptr;
        }
        auto result = std::make_unique<Decimal>();
        uint32_t status = 0;
        mpd_qfloor(result->value.get(), va.value->getconst(), decimal::context.getconst(), &status);
        decimal::context.raise(status);
        return Variant(result.release());
    });
}

Variant Decimal::ceil(Variant a) {
    return decimalBoundary([&]() -> Variant {
        DecimalOperand va;
        if (UNEXPECTED(!extractDecimal(a, va))) {
            return nullptr;
        }
        auto result = std::make_unique<Decimal>();
        uint32_t status = 0;
        mpd_qceil(result->value.get(), va.value->getconst(), decimal::context.getconst(), &status);
        decimal::context.raise(status);
        return Variant(result.release());
    });
}

Variant Decimal::round(Variant a, Variant precision) {
    return decimalBoundary([&]() -> Variant {
        DecimalOperand va;
        if (UNEXPECTED(!extractDecimal(a, va))) {
            return nullptr;
        }
        php::Int prec = precision.toInt();
        auto result = std::make_unique<Decimal>();
        uint32_t status = 0;
        if (prec == 0) {
            mpd_qround_to_int(result->value.get(), va.value->getconst(), decimal::context.getconst(), &status);
            decimal::context.raise(status);
            return Variant(result.release());
        }
        mpd_ssize_t targetExp = -(mpd_ssize_t) prec;
        mpd_qrescale(result->value.get(), va.value->getconst(), targetExp, decimal::context.getconst(), &status);
        if (status & MPD_Invalid_operation) {
            throwException(zend_ce_type_error, "Decimal::round: invalid operation");
            return nullptr;
        }
        decimal::context.raise(status);
        return Variant(result.release());
    });
}

Variant Decimal::toBigInt(Variant a) {
    return a;
}

}  // namespace php
