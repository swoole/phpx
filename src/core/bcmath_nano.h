#pragma once

#ifndef PHPX_NANO
#error "bcmath_nano.h is only available in PHPX Nano builds"
#endif

extern "C" {
#include "ext/bcmath/libbcmath/src/bcmath.h"
}

#include <cstring>
#include <cstdint>
#include <limits>
#include <string>

namespace php::detail {

class NanoBcNumber final {
  public:
    NanoBcNumber() : value_(bc_copy_num(BCG(_zero_))) {}
    explicit NanoBcNumber(bc_num value) : value_(value) {}
    ~NanoBcNumber() {
        bc_free_num(&value_);
    }

    NanoBcNumber(const NanoBcNumber &) = delete;
    NanoBcNumber &operator=(const NanoBcNumber &) = delete;

    bc_num get() const noexcept {
        return value_;
    }

    bc_num *out() noexcept {
        return &value_;
    }

    bc_num release() noexcept {
        bc_num value = value_;
        value_ = nullptr;
        return value;
    }

    void reset(bc_num value) noexcept {
        bc_free_num(&value_);
        value_ = value;
    }

  private:
    bc_num value_;
};

inline bc_num nanoBcZero() {
    return bc_copy_num(BCG(_zero_));
}

inline bc_num nanoBcCopy(bc_num value) {
    return bc_copy_num(value);
}

inline void nanoBcReplace(bc_num *target, bc_num value) {
    bc_free_num(target);
    *target = value;
}

inline bc_num nanoBcParse(
    const char *value,
    size_t length,
    size_t scale,
    bool auto_scale,
    bool *valid = nullptr) {
    bc_num result = nullptr;
    const bool ok = value != nullptr
        && bc_str2num(&result, value, value + length, scale, nullptr, auto_scale);
    if (valid != nullptr) {
        *valid = ok;
    }
    if (result == nullptr) {
        return nanoBcZero();
    }
    return result;
}

inline bool nanoBcNormalizeDecimal(const char *input, std::string &output) {
    if (input == nullptr || *input == '\0') {
        return false;
    }
    const char *cursor = input;
    const bool negative = *cursor == '-';
    if (*cursor == '+' || *cursor == '-') {
        ++cursor;
    }

    std::string digits;
    size_t integer_digits = 0;
    bool saw_digit = false;
    bool saw_point = false;
    while (*cursor != '\0' && *cursor != 'e' && *cursor != 'E') {
        if (*cursor == '.') {
            if (saw_point) {
                return false;
            }
            saw_point = true;
            ++cursor;
            continue;
        }
        if (*cursor < '0' || *cursor > '9') {
            return false;
        }
        saw_digit = true;
        digits.push_back(*cursor++);
        if (!saw_point) {
            ++integer_digits;
        }
    }
    if (!saw_digit) {
        return false;
    }

    int64_t exponent = 0;
    bool exponent_negative = false;
    if (*cursor == 'e' || *cursor == 'E') {
        ++cursor;
        if (*cursor == '+' || *cursor == '-') {
            exponent_negative = *cursor == '-';
            ++cursor;
        }
        if (*cursor == '\0') {
            return false;
        }
        for (; *cursor != '\0'; ++cursor) {
            if (*cursor < '0' || *cursor > '9') {
                return false;
            }
            const int digit = *cursor - '0';
            if (exponent > (std::numeric_limits<int64_t>::max() - digit) / 10) {
                return false;
            }
            exponent = exponent * 10 + digit;
        }
        if (exponent_negative) {
            exponent = -exponent;
        }
    }

    if (integer_digits > static_cast<size_t>(std::numeric_limits<int64_t>::max())) {
        return false;
    }
    const int64_t integer_position = static_cast<int64_t>(integer_digits);
    if (exponent > 0
        && integer_position > std::numeric_limits<int64_t>::max() - exponent) {
        return false;
    }
    const int64_t decimal_position = integer_position + exponent;
    output.clear();
    if (negative) {
        output.push_back('-');
    }
    if (decimal_position <= 0) {
        output += "0.";
        output.append(static_cast<size_t>(-decimal_position), '0');
        output += digits;
    } else if (static_cast<uint64_t>(decimal_position) >= digits.size()) {
        output += digits;
        output.append(static_cast<size_t>(decimal_position) - digits.size(), '0');
    } else {
        const size_t point = static_cast<size_t>(decimal_position);
        output.append(digits.data(), point);
        output.push_back('.');
        output.append(digits.data() + point, digits.size() - point);
    }
    return true;
}

inline std::string nanoBcToStdString(bc_num value, size_t scale, bool trim_fraction) {
    zend_string *encoded = bc_num2str_ex(value, scale);
    std::string result(ZSTR_VAL(encoded), ZSTR_LEN(encoded));
    zend_string_release(encoded);

    if (trim_fraction) {
        const size_t point = result.find('.');
        if (point != std::string::npos) {
            while (result.size() > point + 1 && result.back() == '0') {
                result.pop_back();
            }
            if (result.back() == '.') {
                result.pop_back();
            }
        }
    }
    return result;
}

inline bc_num nanoBcAbsCopy(bc_num value) {
    bc_num result = nanoBcCopy(value);
    result->n_sign = PLUS;
    return result;
}

inline bc_num nanoBcNegatedCopy(bc_num value) {
    bc_num result = nanoBcCopy(value);
    if (!bc_is_zero(result)) {
        result->n_sign = result->n_sign == PLUS ? MINUS : PLUS;
    }
    return result;
}

} // namespace php::detail
