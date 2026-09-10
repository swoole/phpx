#include "phpx_decimal.h"
#include "bcmath_nano.h"

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <string>

namespace php {

namespace {

using detail::NanoBcNumber;

constexpr size_t DECIMAL_NANO_SCALE = 50;

bc_num parseDecimal(const char *input, bool *valid = nullptr) {
    std::string normalized;
    const bool normalized_ok = detail::nanoBcNormalizeDecimal(input, normalized);
    bool parsed_ok = false;
    bc_num result = normalized_ok
        ? detail::nanoBcParse(
            normalized.data(), normalized.size(), DECIMAL_NANO_SCALE, false, &parsed_ok)
        : detail::nanoBcZero();
    if (valid != nullptr) {
        *valid = normalized_ok && parsed_ok;
    }
    return result;
}

class DecimalOperand final {
  public:
    bc_num value = nullptr;
    bool owned = false;

    ~DecimalOperand() {
        if (owned) {
            bc_free_num(&value);
        }
    }

    DecimalOperand(const DecimalOperand &) = delete;
    DecimalOperand &operator=(const DecimalOperand &) = delete;
    DecimalOperand() = default;
};

bool extractDecimal(Variant &variant, DecimalOperand &operand) {
    if (variant.isResource()) {
        auto *boxed = variant.toBox<Decimal>();
        if (boxed != nullptr) {
            operand.value = boxed->value;
            return true;
        }
    }
    if (variant.isInt()) {
        operand.value = bc_long2num(variant.toInt());
        operand.owned = true;
        return true;
    }
    if (variant.isFloat()) {
        throwException(zend_ce_type_error, "Cannot convert float to Decimal, use string or int instead");
        return false;
    }
    if (variant.isString()) {
        String text = variant.toString();
        bool valid = false;
        operand.value = parseDecimal(text.data(), &valid);
        operand.owned = true;
        if (valid) {
            return true;
        }
        throwException(zend_ce_value_error, "Invalid Decimal numeric string");
        return false;
    }
    throwException(zend_ce_type_error, "expects valid Decimal argument");
    return false;
}

Decimal *newDecimalWith(bc_num value) {
    auto *result = new Decimal();
    detail::nanoBcReplace(&result->value, value);
    return result;
}

size_t compareScale(bc_num left, bc_num right) {
    return std::max(left->n_scale, right->n_scale);
}

} // namespace

Decimal::Decimal() : value(detail::nanoBcZero()) {}

Decimal::Decimal(const String &string) {
    bool valid = false;
    value = parseDecimal(string.data(), &valid);
    if (!valid) {
        throwException(zend_ce_value_error, "Invalid Decimal numeric string");
    }
}

Decimal::Decimal(php::Int integer) : value(bc_long2num(integer)) {}

Decimal::~Decimal() {
    bc_free_num(&value);
}

Variant Decimal::newInstance(Variant input) {
    if (input.isFloat()) {
        throwException(zend_ce_type_error, "Cannot construct Decimal from float, use string or int instead");
        return nullptr;
    }
    if (input.isResource() && input.toBox<Decimal>() != nullptr) {
        return input;
    }
    if (input.isInt()) {
        return Variant(new Decimal(input.toInt()));
    }
    return Variant(new Decimal(input.toString()));
}

Variant Decimal::add(Variant a, Variant b) {
    DecimalOperand left, right;
    if (!extractDecimal(a, left) || !extractDecimal(b, right)) {
        return nullptr;
    }
    return Variant(newDecimalWith(bc_add(left.value, right.value, DECIMAL_NANO_SCALE)));
}

Variant Decimal::sub(Variant a, Variant b) {
    DecimalOperand left, right;
    if (!extractDecimal(a, left) || !extractDecimal(b, right)) {
        return nullptr;
    }
    return Variant(newDecimalWith(bc_sub(left.value, right.value, DECIMAL_NANO_SCALE)));
}

Variant Decimal::mul(Variant a, Variant b) {
    DecimalOperand left, right;
    if (!extractDecimal(a, left) || !extractDecimal(b, right)) {
        return nullptr;
    }
    return Variant(newDecimalWith(
        bc_multiply(left.value, right.value, DECIMAL_NANO_SCALE)));
}

Variant Decimal::div(Variant a, Variant b) {
    DecimalOperand left, right;
    if (!extractDecimal(a, left) || !extractDecimal(b, right)) {
        return nullptr;
    }
    if (bc_is_zero(right.value)) {
        throwException(zend_ce_division_by_zero_error, "Division by zero");
        return nullptr;
    }
    auto *result = new Decimal();
    (void) bc_divide(left.value, right.value, &result->value, DECIMAL_NANO_SCALE);
    return Variant(result);
}

Variant Decimal::mod(Variant a, Variant b) {
    DecimalOperand left, right;
    if (!extractDecimal(a, left) || !extractDecimal(b, right)) {
        return nullptr;
    }
    if (bc_is_zero(right.value)) {
        throwException(zend_ce_division_by_zero_error, "Modulo by zero");
        return nullptr;
    }
    auto *result = new Decimal();
    (void) bc_modulo(left.value, right.value, &result->value, DECIMAL_NANO_SCALE);
    return Variant(result);
}

Variant Decimal::neg(Variant a) {
    DecimalOperand value;
    if (!extractDecimal(a, value)) {
        return nullptr;
    }
    return Variant(newDecimalWith(detail::nanoBcNegatedCopy(value.value)));
}

Variant Decimal::cmp(Variant a, Variant b) {
    DecimalOperand left, right;
    if (!extractDecimal(a, left) || !extractDecimal(b, right)) {
        return nullptr;
    }
    return Variant(static_cast<php::Int>(
        bc_compare(left.value, right.value, compareScale(left.value, right.value))));
}

Variant Decimal::abs(Variant a) {
    DecimalOperand value;
    if (!extractDecimal(a, value)) {
        return nullptr;
    }
    return Variant(newDecimalWith(detail::nanoBcAbsCopy(value.value)));
}

Variant Decimal::pow(Variant base, Variant exponent) {
    DecimalOperand base_value, exponent_value;
    if (!extractDecimal(base, base_value) || !extractDecimal(exponent, exponent_value)) {
        return nullptr;
    }
    if (exponent_value.value->n_scale != 0) {
        throwException(zend_ce_type_error, "Decimal::pow requires an integer exponent in nano mode");
        return nullptr;
    }
    const long numeric_exponent = bc_num2long(exponent_value.value);
    if (numeric_exponent == 0 && !bc_is_zero(exponent_value.value)) {
        throwException(zend_ce_value_error, "Decimal exponent is too large");
        return nullptr;
    }
    auto *result = new Decimal();
    const bc_raise_status status = bc_raise(
        base_value.value, numeric_exponent, &result->value, DECIMAL_NANO_SCALE);
    if (status == BC_RAISE_STATUS_DIVIDE_BY_ZERO) {
        delete result;
        throwException(zend_ce_division_by_zero_error, "Division by zero");
        return nullptr;
    }
    if (status != BC_RAISE_STATUS_OK) {
        delete result;
        throwException(zend_ce_arithmetic_error, "Decimal exponentiation result is too large");
        return nullptr;
    }
    return Variant(result);
}

Variant Decimal::divmod(Variant a, Variant b) {
    DecimalOperand left, right;
    if (!extractDecimal(a, left) || !extractDecimal(b, right)) {
        return nullptr;
    }
    if (bc_is_zero(right.value)) {
        throwException(zend_ce_division_by_zero_error, "Division by zero");
        return nullptr;
    }
    auto *quotient = new Decimal();
    auto *remainder = new Decimal();
    (void) bc_divmod(
        left.value, right.value, &quotient->value, &remainder->value, DECIMAL_NANO_SCALE);
    Array result(2);
    result.append(Variant(quotient));
    result.append(Variant(remainder));
    return result;
}

Variant Decimal::powmod(Variant base, Variant exponent, Variant modulus) {
    DecimalOperand base_value, exponent_value, modulus_value;
    if (!extractDecimal(base, base_value)
        || !extractDecimal(exponent, exponent_value)
        || !extractDecimal(modulus, modulus_value)) {
        return nullptr;
    }
    if (bc_is_zero(modulus_value.value)) {
        throwException(zend_ce_division_by_zero_error, "Modulo by zero");
        return nullptr;
    }
    auto *result = new Decimal();
    const raise_mod_status status = bc_raisemod(
        base_value.value, exponent_value.value, modulus_value.value,
        &result->value, DECIMAL_NANO_SCALE);
    if (status != OK) {
        delete result;
        throwException(zend_ce_type_error, "Decimal::powmod requires integer operands and a non-negative exponent");
        return nullptr;
    }
    return Variant(result);
}

Variant Decimal::sqrt(Variant a) {
    DecimalOperand value;
    if (!extractDecimal(a, value)) {
        return nullptr;
    }
    if (bc_is_neg(value.value)) {
        throwException(zend_ce_type_error, "Decimal::sqrt: invalid operation (negative number?)");
        return nullptr;
    }
    auto *result = newDecimalWith(detail::nanoBcCopy(value.value));
    (void) bc_sqrt(&result->value, DECIMAL_NANO_SCALE);
    return Variant(result);
}

Variant Decimal::floor(Variant a) {
    DecimalOperand value;
    if (!extractDecimal(a, value)) {
        return nullptr;
    }
    return Variant(newDecimalWith(bc_floor_or_ceil(value.value, true)));
}

Variant Decimal::ceil(Variant a) {
    DecimalOperand value;
    if (!extractDecimal(a, value)) {
        return nullptr;
    }
    return Variant(newDecimalWith(bc_floor_or_ceil(value.value, false)));
}

Variant Decimal::round(Variant a, Variant precision) {
    DecimalOperand value;
    if (!extractDecimal(a, value)) {
        return nullptr;
    }
    if (!precision.isInt()) {
        throwException(zend_ce_type_error, "Decimal::round precision must be int");
        return nullptr;
    }
    auto *result = new Decimal();
    (void) bc_round(
        value.value,
        precision.toInt(),
        ZEND_ENUM_RoundingMode_HalfEven,
        &result->value);
    return Variant(result);
}

Variant Decimal::toString(Variant a) {
    auto *value = a.toBox<Decimal>();
    if (value == nullptr) {
        throwException(zend_ce_type_error, "expects Decimal argument");
        return nullptr;
    }
    return Variant(detail::nanoBcToStdString(value->value, value->value->n_scale, true));
}

Variant Decimal::toInt(Variant a) {
    auto *value = a.toBox<Decimal>();
    if (value == nullptr) {
        throwException(zend_ce_type_error, "expects Decimal argument");
        return nullptr;
    }
    const std::string min_text = std::to_string(ZEND_LONG_MIN);
    const std::string max_text = std::to_string(ZEND_LONG_MAX);
    bool valid = false;
    NanoBcNumber minimum(detail::nanoBcParse(
        min_text.data(), min_text.size(), 0, false, &valid));
    NanoBcNumber maximum(detail::nanoBcParse(
        max_text.data(), max_text.size(), 0, false, &valid));
    const size_t scale = std::max(value->value->n_scale, minimum.get()->n_scale);
    if (bc_compare(value->value, minimum.get(), scale) == BCMATH_RIGHT_GREATER
        || bc_compare(value->value, maximum.get(), scale) == BCMATH_LEFT_GREATER) {
        throwException(zend_ce_type_error, "value too large for int64");
        return nullptr;
    }
    const std::string text = detail::nanoBcToStdString(value->value, 0, false);
    return Variant(static_cast<php::Int>(std::strtoll(text.c_str(), nullptr, 10)));
}

Variant Decimal::toFloat(Variant a) {
    auto *value = a.toBox<Decimal>();
    if (value == nullptr) {
        throwException(zend_ce_type_error, "expects Decimal argument");
        return nullptr;
    }
    const std::string text = detail::nanoBcToStdString(
        value->value, value->value->n_scale, false);
    return Variant(static_cast<php::Float>(std::strtod(text.c_str(), nullptr)));
}

Variant Decimal::toBool(Variant a) {
    auto *value = a.toBox<Decimal>();
    if (value == nullptr) {
        throwException(zend_ce_type_error, "expects Decimal argument");
        return nullptr;
    }
    return Variant(!bc_is_zero(value->value));
}

Variant Decimal::toBigInt(Variant a) {
    return a;
}

} // namespace php
