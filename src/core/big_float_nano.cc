#include "phpx_big_float.h"
#include "bcmath_nano.h"

#include <algorithm>
#include <cstdlib>
#include <string>

namespace php {

namespace {

using detail::NanoBcNumber;

bc_num parseBigFloat(const char *value, bool *valid = nullptr) {
    std::string normalized;
    const bool normalized_ok = detail::nanoBcNormalizeDecimal(value, normalized);
    bool parsed_ok = false;
    bc_num result = normalized_ok
        ? detail::nanoBcParse(
            normalized.data(), normalized.size(), BIG_FLOAT_DEFAULT_SCALE, false, &parsed_ok)
        : detail::nanoBcZero();
    if (valid != nullptr) {
        *valid = normalized_ok && parsed_ok;
    }
    return result;
}

class BigFloatOperand final {
  public:
    bc_num value = nullptr;
    bool owned = false;

    ~BigFloatOperand() {
        if (owned) {
            bc_free_num(&value);
        }
    }

    BigFloatOperand(const BigFloatOperand &) = delete;
    BigFloatOperand &operator=(const BigFloatOperand &) = delete;
    BigFloatOperand() = default;
};

bool extractBigFloat(Variant &variant, BigFloatOperand &operand) {
    if (variant.isResource()) {
        auto *boxed = variant.toBox<BigFloat>();
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
    if (variant.isFloat() || variant.isString()) {
        String text = variant.toString();
        bool valid = false;
        operand.value = parseBigFloat(text.data(), &valid);
        operand.owned = true;
        if (valid) {
            return true;
        }
        throwException(zend_ce_value_error, "Invalid BigFloat numeric string");
        return false;
    }
    throwException(zend_ce_type_error, "expects valid BigFloat argument");
    return false;
}

BigFloat *newBigFloatWith(bc_num value) {
    auto *result = new BigFloat();
    detail::nanoBcReplace(&result->value, value);
    return result;
}

size_t compareScale(bc_num left, bc_num right) {
    return std::max(left->n_scale, right->n_scale);
}

} // namespace

BigFloat::BigFloat() : value(detail::nanoBcZero()) {}

BigFloat::BigFloat(const String &string) : BigFloat(string.data()) {}

BigFloat::BigFloat(const char *string) {
    bool valid = false;
    value = parseBigFloat(string, &valid);
    if (!valid) {
        throwException(zend_ce_value_error, "Invalid BigFloat numeric string");
    }
}

BigFloat::BigFloat(php::Int integer) : value(bc_long2num(integer)) {}

BigFloat::BigFloat(php::Float number) {
    Variant variant(number);
    String text = variant.toString();
    bool valid = false;
    value = parseBigFloat(text.data(), &valid);
    if (!valid) {
        throwException(zend_ce_value_error, "Invalid BigFloat value");
    }
}

BigFloat::BigFloat(const BigFloat &other) : value(detail::nanoBcCopy(other.value)) {}

BigFloat::~BigFloat() {
    bc_free_num(&value);
}

Variant BigFloat::newInstance(Variant input) {
    if (input.isResource() && input.toBox<BigFloat>() != nullptr) {
        return input;
    }
    if (input.isInt()) {
        return Variant(new BigFloat(input.toInt()));
    }
    if (input.isFloat()) {
        return Variant(new BigFloat(input.toFloat()));
    }
    return Variant(new BigFloat(input.toString()));
}

Variant BigFloat::add(Variant a, Variant b) {
    BigFloatOperand left, right;
    if (!extractBigFloat(a, left) || !extractBigFloat(b, right)) {
        return nullptr;
    }
    return Variant(newBigFloatWith(bc_add(left.value, right.value, BIG_FLOAT_DEFAULT_SCALE)));
}

Variant BigFloat::sub(Variant a, Variant b) {
    BigFloatOperand left, right;
    if (!extractBigFloat(a, left) || !extractBigFloat(b, right)) {
        return nullptr;
    }
    return Variant(newBigFloatWith(bc_sub(left.value, right.value, BIG_FLOAT_DEFAULT_SCALE)));
}

Variant BigFloat::mul(Variant a, Variant b) {
    BigFloatOperand left, right;
    if (!extractBigFloat(a, left) || !extractBigFloat(b, right)) {
        return nullptr;
    }
    return Variant(newBigFloatWith(
        bc_multiply(left.value, right.value, BIG_FLOAT_DEFAULT_SCALE)));
}

Variant BigFloat::div(Variant a, Variant b) {
    BigFloatOperand left, right;
    if (!extractBigFloat(a, left) || !extractBigFloat(b, right)) {
        return nullptr;
    }
    if (bc_is_zero(right.value)) {
        throwException(zend_ce_division_by_zero_error, "Division by zero");
        return nullptr;
    }
    auto *result = new BigFloat();
    (void) bc_divide(left.value, right.value, &result->value, BIG_FLOAT_DEFAULT_SCALE);
    return Variant(result);
}

Variant BigFloat::neg(Variant a) {
    BigFloatOperand value;
    if (!extractBigFloat(a, value)) {
        return nullptr;
    }
    return Variant(newBigFloatWith(detail::nanoBcNegatedCopy(value.value)));
}

Variant BigFloat::cmp(Variant a, Variant b) {
    BigFloatOperand left, right;
    if (!extractBigFloat(a, left) || !extractBigFloat(b, right)) {
        return nullptr;
    }
    return Variant(static_cast<php::Int>(
        bc_compare(left.value, right.value, compareScale(left.value, right.value))));
}

Variant BigFloat::abs(Variant a) {
    BigFloatOperand value;
    if (!extractBigFloat(a, value)) {
        return nullptr;
    }
    return Variant(newBigFloatWith(detail::nanoBcAbsCopy(value.value)));
}

Variant BigFloat::sqrt(Variant a) {
    BigFloatOperand value;
    if (!extractBigFloat(a, value)) {
        return nullptr;
    }
    if (bc_is_neg(value.value)) {
        throwException(zend_ce_type_error, "BigFloat::sqrt: cannot compute square root of negative number");
        return nullptr;
    }
    auto *result = newBigFloatWith(detail::nanoBcCopy(value.value));
    (void) bc_sqrt(&result->value, BIG_FLOAT_DEFAULT_SCALE);
    return Variant(result);
}

Variant BigFloat::toString(Variant a) {
    auto *value = a.toBox<BigFloat>();
    if (value == nullptr) {
        throwException(zend_ce_type_error, "expects BigFloat argument");
        return nullptr;
    }
    return Variant(detail::nanoBcToStdString(value->value, value->value->n_scale, true));
}

Variant BigFloat::toInt(Variant a) {
    auto *value = a.toBox<BigFloat>();
    if (value == nullptr) {
        throwException(zend_ce_type_error, "expects BigFloat argument");
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
        throwException(zend_ce_arithmetic_error, "BigFloat value is outside the PHP int range");
        return nullptr;
    }
    const std::string text = detail::nanoBcToStdString(value->value, 0, false);
    return Variant(static_cast<php::Int>(std::strtoll(text.c_str(), nullptr, 10)));
}

Variant BigFloat::toFloat(Variant a) {
    auto *value = a.toBox<BigFloat>();
    if (value == nullptr) {
        throwException(zend_ce_type_error, "expects BigFloat argument");
        return nullptr;
    }
    const std::string text = detail::nanoBcToStdString(
        value->value, value->value->n_scale, false);
    return Variant(static_cast<php::Float>(std::strtod(text.c_str(), nullptr)));
}

Variant BigFloat::toBool(Variant a) {
    auto *value = a.toBox<BigFloat>();
    if (value == nullptr) {
        throwException(zend_ce_type_error, "expects BigFloat argument");
        return nullptr;
    }
    return Variant(!bc_is_zero(value->value));
}

} // namespace php
