#include "phpx_big_int.h"
#include "bcmath_nano.h"

#include <climits>
#include <cstdlib>
#include <cstring>

namespace php {

namespace {

using detail::NanoBcNumber;

bool isDecimalInteger(const char *value, size_t length) {
    if (value == nullptr || length == 0) {
        return false;
    }
    size_t index = value[0] == '+' || value[0] == '-' ? 1 : 0;
    if (index == length) {
        return false;
    }
    for (; index < length; ++index) {
        if (value[index] < '0' || value[index] > '9') {
            return false;
        }
    }
    return true;
}

bc_num parseBigInt(const char *value, size_t length, bool *valid = nullptr) {
    bool ok = isDecimalInteger(value, length);
    bc_num result = ok
        ? detail::nanoBcParse(value, length, 0, false, &ok)
        : detail::nanoBcZero();
    if (valid != nullptr) {
        *valid = ok;
    }
    return result;
}

class BigIntOperand final {
  public:
    bc_num value = nullptr;
    bool owned = false;

    ~BigIntOperand() {
        if (owned) {
            bc_free_num(&value);
        }
    }

    BigIntOperand(const BigIntOperand &) = delete;
    BigIntOperand &operator=(const BigIntOperand &) = delete;
    BigIntOperand() = default;
};

bool extractBigInt(Variant &variant, BigIntOperand &operand) {
    if (variant.isResource()) {
        auto *boxed = variant.toBox<BigInt>();
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
    throwException(zend_ce_type_error, "expects BigInt argument");
    return false;
}

BigInt *newBigIntWith(bc_num value) {
    auto *result = new BigInt();
    detail::nanoBcReplace(&result->value, value);
    return result;
}

bc_num subtractOneFromMagnitude(bc_num negative) {
    NanoBcNumber magnitude(detail::nanoBcAbsCopy(negative));
    return bc_sub(magnitude.get(), BCG(_one_), 0);
}

bc_num complementNonNegative(bc_num value) {
    NanoBcNumber incremented(bc_add(value, BCG(_one_), 0));
    return detail::nanoBcNegatedCopy(incremented.get());
}

enum class PositiveBitOp {
    And,
    Or,
    Xor,
};

bc_num positiveBitOp(bc_num left, bc_num right, PositiveBitOp operation) {
    NanoBcNumber a(detail::nanoBcCopy(left));
    NanoBcNumber b(detail::nanoBcCopy(right));
    NanoBcNumber result;
    NanoBcNumber place(detail::nanoBcCopy(BCG(_one_)));

    while (!bc_is_zero(a.get()) || !bc_is_zero(b.get())) {
        const bool a_bit = !bc_is_zero(a.get())
            && (a.get()->n_value[a.get()->n_len - 1] & 1) != 0;
        const bool b_bit = !bc_is_zero(b.get())
            && (b.get()->n_value[b.get()->n_len - 1] & 1) != 0;
        const bool output_bit = operation == PositiveBitOp::And
            ? a_bit && b_bit
            : operation == PositiveBitOp::Or ? a_bit || b_bit : a_bit != b_bit;

        if (output_bit) {
            result.reset(bc_add(result.get(), place.get(), 0));
        }

        NanoBcNumber next_a;
        NanoBcNumber next_b;
        (void) bc_divide(a.get(), BCG(_two_), next_a.out(), 0);
        (void) bc_divide(b.get(), BCG(_two_), next_b.out(), 0);
        a.reset(next_a.release());
        b.reset(next_b.release());
        if (!bc_is_zero(a.get()) || !bc_is_zero(b.get())) {
            place.reset(bc_multiply(place.get(), BCG(_two_), 0));
        }
    }
    return result.release();
}

bc_num signedBitOp(bc_num left, bc_num right, PositiveBitOp operation) {
    const bool left_negative = bc_is_neg(left);
    const bool right_negative = bc_is_neg(right);
    if (!left_negative && !right_negative) {
        return positiveBitOp(left, right, operation);
    }

    NanoBcNumber left_complement(
        left_negative ? subtractOneFromMagnitude(left) : detail::nanoBcCopy(left));
    NanoBcNumber right_complement(
        right_negative ? subtractOneFromMagnitude(right) : detail::nanoBcCopy(right));

    if (left_negative && right_negative) {
        if (operation == PositiveBitOp::Xor) {
            return positiveBitOp(left_complement.get(), right_complement.get(), operation);
        }
        NanoBcNumber value(positiveBitOp(
            left_complement.get(),
            right_complement.get(),
            operation == PositiveBitOp::And ? PositiveBitOp::Or : PositiveBitOp::And));
        return complementNonNegative(value.get());
    }

    bc_num negative_complement = left_negative
        ? left_complement.get() : right_complement.get();
    bc_num positive = left_negative ? right_complement.get() : left_complement.get();
    if (operation == PositiveBitOp::And) {
        NanoBcNumber overlap(positiveBitOp(
            positive, negative_complement, PositiveBitOp::And));
        return bc_sub(positive, overlap.get(), 0);
    }
    if (operation == PositiveBitOp::Or) {
        NanoBcNumber overlap(positiveBitOp(
            negative_complement, positive, PositiveBitOp::And));
        NanoBcNumber retained(bc_sub(negative_complement, overlap.get(), 0));
        return complementNonNegative(retained.get());
    }
    NanoBcNumber value(positiveBitOp(
        negative_complement, positive, PositiveBitOp::Xor));
    return complementNonNegative(value.get());
}

bool testPositiveBit(bc_num value, php::Int index) {
    if (index < 0) {
        return false;
    }
    /* Four binary digits per decimal digit is a strict upper bound. */
    if (static_cast<uint64_t>(index)
        >= static_cast<uint64_t>(value->n_len) * UINT64_C(4)) {
        return false;
    }
    NanoBcNumber current(detail::nanoBcCopy(value));
    for (php::Int position = 0; position < index && !bc_is_zero(current.get()); ++position) {
        NanoBcNumber quotient;
        (void) bc_divide(current.get(), BCG(_two_), quotient.out(), 0);
        current.reset(quotient.release());
    }
    return !bc_is_zero(current.get())
        && (current.get()->n_value[current.get()->n_len - 1] & 1) != 0;
}

bc_num powerOfTwo(php::Int exponent, bool *valid) {
    NanoBcNumber result;
    const bc_raise_status status = exponent > LONG_MAX
        ? BC_RAISE_STATUS_LEN_IS_OVERFLOW
        : bc_raise(BCG(_two_), static_cast<long>(exponent), result.out(), 0);
    *valid = status == BC_RAISE_STATUS_OK;
    return result.release();
}

} // namespace

BigInt::BigInt() : value(detail::nanoBcZero()) {}

BigInt::BigInt(const String &string) {
    bool valid = false;
    value = parseBigInt(string.data(), string.length(), &valid);
    if (UNEXPECTED(!valid)) {
        throwException(zend_ce_value_error, "Invalid BigInt numeric string");
    }
}

BigInt::BigInt(php::Int integer) : value(bc_long2num(integer)) {}

BigInt::~BigInt() {
    bc_free_num(&value);
}

Variant BigInt::newInstance(Variant input) {
    if (UNEXPECTED(input.isFloat())) {
        throwException(zend_ce_type_error, "Cannot construct BigInt from float, use string or int instead");
        return null;
    }
    if (input.isResource() && input.toBox<BigInt>() != nullptr) {
        return input;
    }
    if (input.isInt()) {
        return Variant(new BigInt(input.toInt()));
    }
    return Variant(new BigInt(input.toString()));
}

Variant BigInt::add(Variant a, Variant b) {
    BigIntOperand left, right;
    if (!extractBigInt(a, left) || !extractBigInt(b, right)) {
        return nullptr;
    }
    return Variant(newBigIntWith(bc_add(left.value, right.value, 0)));
}

Variant BigInt::sub(Variant a, Variant b) {
    BigIntOperand left, right;
    if (!extractBigInt(a, left) || !extractBigInt(b, right)) {
        return nullptr;
    }
    return Variant(newBigIntWith(bc_sub(left.value, right.value, 0)));
}

Variant BigInt::mul(Variant a, Variant b) {
    BigIntOperand left, right;
    if (!extractBigInt(a, left) || !extractBigInt(b, right)) {
        return nullptr;
    }
    return Variant(newBigIntWith(bc_multiply(left.value, right.value, 0)));
}

Variant BigInt::div(Variant a, Variant b) {
    BigIntOperand left, right;
    if (!extractBigInt(a, left) || !extractBigInt(b, right)) {
        return nullptr;
    }
    if (bc_is_zero(right.value)) {
        throwException(zend_ce_division_by_zero_error, "Division by zero");
        return nullptr;
    }
    auto *result = new BigInt();
    (void) bc_divide(left.value, right.value, &result->value, 0);
    return Variant(result);
}

Variant BigInt::mod(Variant a, Variant b) {
    BigIntOperand left, right;
    if (!extractBigInt(a, left) || !extractBigInt(b, right)) {
        return nullptr;
    }
    if (bc_is_zero(right.value)) {
        throwException(zend_ce_division_by_zero_error, "Division by zero");
        return nullptr;
    }
    auto *result = new BigInt();
    (void) bc_modulo(left.value, right.value, &result->value, 0);
    return Variant(result);
}

Variant BigInt::pow(Variant a, Variant b) {
    BigIntOperand base, exponent;
    if (!extractBigInt(a, base) || !extractBigInt(b, exponent)) {
        return nullptr;
    }
    if (bc_is_neg(exponent.value)) {
        throwException(zend_ce_type_error, "Negative exponent not supported");
        return nullptr;
    }
    const long exponent_value = bc_num2long(exponent.value);
    if (exponent_value == 0 && !bc_is_zero(exponent.value)) {
        throwException(zend_ce_value_error, "BigInt exponent is too large");
        return nullptr;
    }
    auto *result = new BigInt();
    if (bc_raise(base.value, exponent_value, &result->value, 0) != BC_RAISE_STATUS_OK) {
        delete result;
        throwException(zend_ce_arithmetic_error, "BigInt exponentiation result is too large");
        return nullptr;
    }
    return Variant(result);
}

Variant BigInt::neg(Variant a) {
    BigIntOperand value;
    if (!extractBigInt(a, value)) {
        return nullptr;
    }
    return Variant(newBigIntWith(detail::nanoBcNegatedCopy(value.value)));
}

Variant BigInt::cmp(Variant a, Variant b) {
    BigIntOperand left, right;
    if (!extractBigInt(a, left) || !extractBigInt(b, right)) {
        return nullptr;
    }
    return Variant(static_cast<php::Int>(bc_compare(left.value, right.value, 0)));
}

Variant BigInt::abs(Variant a) {
    BigIntOperand value;
    if (!extractBigInt(a, value)) {
        return nullptr;
    }
    return Variant(newBigIntWith(detail::nanoBcAbsCopy(value.value)));
}

Variant BigInt::gcd(Variant a, Variant b) {
    BigIntOperand left, right;
    if (!extractBigInt(a, left) || !extractBigInt(b, right)) {
        return nullptr;
    }
    NanoBcNumber x(detail::nanoBcAbsCopy(left.value));
    NanoBcNumber y(detail::nanoBcAbsCopy(right.value));
    while (!bc_is_zero(y.get())) {
        NanoBcNumber remainder;
        (void) bc_modulo(x.get(), y.get(), remainder.out(), 0);
        x.reset(y.release());
        y.reset(remainder.release());
    }
    return Variant(newBigIntWith(x.release()));
}

Variant BigInt::divmod(Variant a, Variant b) {
    BigIntOperand left, right;
    if (!extractBigInt(a, left) || !extractBigInt(b, right)) {
        return nullptr;
    }
    if (bc_is_zero(right.value)) {
        throwException(zend_ce_division_by_zero_error, "Division by zero");
        return nullptr;
    }
    auto *quotient = new BigInt();
    auto *remainder = new BigInt();
    (void) bc_divmod(left.value, right.value, &quotient->value, &remainder->value, 0);
    Array result(2);
    result.append(Variant(quotient));
    result.append(Variant(remainder));
    return result;
}

Variant BigInt::powmod(Variant base, Variant exponent, Variant modulus) {
    BigIntOperand base_value, exponent_value, modulus_value;
    if (!extractBigInt(base, base_value)
        || !extractBigInt(exponent, exponent_value)
        || !extractBigInt(modulus, modulus_value)) {
        return nullptr;
    }
    if (bc_is_zero(modulus_value.value)) {
        throwException(zend_ce_division_by_zero_error, "Modulo by zero in powmod");
        return nullptr;
    }
    if (bc_is_neg(exponent_value.value)) {
        throwException(zend_ce_type_error, "Negative exponent not supported in powmod");
        return nullptr;
    }
    auto *result = new BigInt();
    const raise_mod_status status = bc_raisemod(
        base_value.value, exponent_value.value, modulus_value.value, &result->value, 0);
    if (status != OK) {
        delete result;
        throwException(zend_ce_arithmetic_error, "BigInt powmod failed");
        return nullptr;
    }
    return Variant(result);
}

Variant BigInt::sqrt(Variant a) {
    BigIntOperand value;
    if (!extractBigInt(a, value)) {
        return nullptr;
    }
    if (bc_is_neg(value.value)) {
        throwException(zend_ce_type_error, "Cannot compute square root of negative BigInt");
        return nullptr;
    }
    auto *result = newBigIntWith(detail::nanoBcCopy(value.value));
    (void) bc_sqrt(&result->value, 0);
    return Variant(result);
}

Variant BigInt::bitAnd(Variant a, Variant b) {
    BigIntOperand left, right;
    if (!extractBigInt(a, left) || !extractBigInt(b, right)) {
        return nullptr;
    }
    return Variant(newBigIntWith(signedBitOp(left.value, right.value, PositiveBitOp::And)));
}

Variant BigInt::bitOr(Variant a, Variant b) {
    BigIntOperand left, right;
    if (!extractBigInt(a, left) || !extractBigInt(b, right)) {
        return nullptr;
    }
    return Variant(newBigIntWith(signedBitOp(left.value, right.value, PositiveBitOp::Or)));
}

Variant BigInt::bitXor(Variant a, Variant b) {
    BigIntOperand left, right;
    if (!extractBigInt(a, left) || !extractBigInt(b, right)) {
        return nullptr;
    }
    return Variant(newBigIntWith(signedBitOp(left.value, right.value, PositiveBitOp::Xor)));
}

Variant BigInt::bitNot(Variant a) {
    BigIntOperand value;
    if (!extractBigInt(a, value)) {
        return nullptr;
    }
    NanoBcNumber negated(detail::nanoBcNegatedCopy(value.value));
    return Variant(newBigIntWith(bc_sub(negated.get(), BCG(_one_), 0)));
}

Variant BigInt::testBit(Variant a, Variant index) {
    BigIntOperand value;
    if (!extractBigInt(a, value)) {
        return nullptr;
    }
    if (!index.isInt()) {
        throwException(zend_ce_type_error, "testBit expects int index");
        return nullptr;
    }
    const php::Int bit_index = index.toInt();
    if (bit_index < 0) {
        throwException(zend_ce_value_error, "testBit index must be non-negative");
        return nullptr;
    }
    if (!bc_is_neg(value.value)) {
        return Variant(static_cast<php::Int>(testPositiveBit(value.value, bit_index)));
    }
    NanoBcNumber complement(subtractOneFromMagnitude(value.value));
    return Variant(static_cast<php::Int>(!testPositiveBit(complement.get(), bit_index)));
}

Variant BigInt::popCount(Variant a) {
    BigIntOperand value;
    if (!extractBigInt(a, value)) {
        return nullptr;
    }
    if (bc_is_neg(value.value)) {
        throwException(zend_ce_value_error, "popCount is undefined for negative BigInt values");
        return nullptr;
    }
    NanoBcNumber current(detail::nanoBcCopy(value.value));
    php::Int count = 0;
    while (!bc_is_zero(current.get())) {
        if ((current.get()->n_value[current.get()->n_len - 1] & 1) != 0) {
            if (count == ZEND_LONG_MAX) {
                throwException(zend_ce_arithmetic_error, "BigInt popCount exceeds the PHP int range");
                return nullptr;
            }
            ++count;
        }
        NanoBcNumber quotient;
        (void) bc_divide(current.get(), BCG(_two_), quotient.out(), 0);
        current.reset(quotient.release());
    }
    return Variant(count);
}

Variant BigInt::bitShiftLeft(Variant a, Variant n) {
    BigIntOperand value;
    if (!extractBigInt(a, value)) {
        return nullptr;
    }
    if (!n.isInt()) {
        throwException(zend_ce_type_error, "bitShiftLeft expects int shift amount");
        return nullptr;
    }
    const php::Int shift = n.toInt();
    if (shift < 0) {
        throwException(zend_ce_value_error, "bitShiftLeft shift amount must be non-negative");
        return nullptr;
    }
    bool valid = false;
    NanoBcNumber factor(powerOfTwo(shift, &valid));
    if (!valid) {
        throwException(zend_ce_arithmetic_error, "BigInt shift amount is too large");
        return nullptr;
    }
    return Variant(newBigIntWith(bc_multiply(value.value, factor.get(), 0)));
}

Variant BigInt::bitShiftRight(Variant a, Variant n) {
    BigIntOperand value;
    if (!extractBigInt(a, value)) {
        return nullptr;
    }
    if (!n.isInt()) {
        throwException(zend_ce_type_error, "bitShiftRight expects int shift amount");
        return nullptr;
    }
    const php::Int shift = n.toInt();
    if (shift < 0) {
        throwException(zend_ce_value_error, "bitShiftRight shift amount must be non-negative");
        return nullptr;
    }
    bool valid = false;
    NanoBcNumber factor(powerOfTwo(shift, &valid));
    if (!valid) {
        /* Every finite non-negative integer becomes 0; negative values become -1. */
        return Variant(new BigInt(bc_is_neg(value.value) ? -1 : 0));
    }
    NanoBcNumber quotient;
    NanoBcNumber remainder;
    (void) bc_divmod(value.value, factor.get(), quotient.out(), remainder.out(), 0);
    if (bc_is_neg(value.value) && !bc_is_zero(remainder.get())) {
        quotient.reset(bc_sub(quotient.get(), BCG(_one_), 0));
    }
    return Variant(newBigIntWith(quotient.release()));
}

Variant BigInt::toString(Variant a) {
    auto *value = a.toBox<BigInt>();
    if (value == nullptr) {
        throwException(zend_ce_type_error, "BigInt::toString expects BigInt argument");
        return nullptr;
    }
    return Variant(detail::nanoBcToStdString(value->value, 0, false));
}

Variant BigInt::toInt(Variant a) {
    auto *value = a.toBox<BigInt>();
    if (value == nullptr) {
        throwException(zend_ce_type_error, "BigInt::toInt expects BigInt argument");
        return nullptr;
    }
    const std::string min_text = std::to_string(ZEND_LONG_MIN);
    const std::string max_text = std::to_string(ZEND_LONG_MAX);
    NanoBcNumber minimum(parseBigInt(min_text.data(), min_text.size()));
    NanoBcNumber maximum(parseBigInt(max_text.data(), max_text.size()));
    if (bc_compare(value->value, minimum.get(), 0) == BCMATH_RIGHT_GREATER
        || bc_compare(value->value, maximum.get(), 0) == BCMATH_LEFT_GREATER) {
        throwException(zend_ce_arithmetic_error, "BigInt value is outside the PHP int range");
        return nullptr;
    }
    const std::string text = detail::nanoBcToStdString(value->value, 0, false);
    return Variant(static_cast<php::Int>(std::strtoll(text.c_str(), nullptr, 10)));
}

Variant BigInt::toFloat(Variant a) {
    auto *value = a.toBox<BigInt>();
    if (value == nullptr) {
        throwException(zend_ce_type_error, "BigInt::toFloat expects BigInt argument");
        return nullptr;
    }
    const std::string text = detail::nanoBcToStdString(value->value, 0, false);
    return Variant(static_cast<php::Float>(std::strtod(text.c_str(), nullptr)));
}

Variant BigInt::toBool(Variant a) {
    auto *value = a.toBox<BigInt>();
    if (value == nullptr) {
        throwException(zend_ce_type_error, "BigInt::toBool expects BigInt argument");
        return nullptr;
    }
    return Variant(!bc_is_zero(value->value));
}

Variant BigInt::toBigDecimal(Variant a) {
    return a;
}

} // namespace php
