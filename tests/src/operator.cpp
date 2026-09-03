#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

#include <cmath>
#include <cstdint>
#include <limits>
#include <type_traits>
#include <vector>

using namespace php;

static bool zend_ordered_compare(const Variant &left, const Variant &right, bool inclusive) {
    zval result;
    const auto op = inclusive ? is_smaller_or_equal_function : is_smaller_function;
    EXPECT_EQ(op(&result, NO_CONST_V(left), NO_CONST_V(right)), SUCCESS);
    return Z_TYPE(result) == IS_TRUE;
}

static void expect_relational_operators_match_zend(const Variant &left, const Variant &right) {
    EXPECT_EQ(left < right, zend_ordered_compare(left, right, false));
    EXPECT_EQ(left <= right, zend_ordered_compare(left, right, true));
    EXPECT_EQ(left > right, zend_ordered_compare(right, left, false));
    EXPECT_EQ(left >= right, zend_ordered_compare(right, left, true));
}

// Test all arithmetic operators (+, -, *, /, %)
TEST(operator_arithmetic, all_operators) {
    // Addition operator test
    {
        Variant v1(10);
        Variant result = 5 + v1;
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 15);

        // Test floating point addition
        Variant result2 = 3.14 + v1;
        ASSERT_TRUE(result2.isFloat());
        ASSERT_NEAR(result2.toFloat(), 13.14, 0.001);

        // Test string number addition
        Variant v2("20");
        Variant result3 = 5 + v2;
        ASSERT_TRUE(result3.isInt());
        ASSERT_EQ(result3.toInt(), 25);

        // Test negative number addition
        Variant v3(-5);
        Variant result4 = 10 + v3;
        ASSERT_TRUE(result4.isInt());
        ASSERT_EQ(result4.toInt(), 5);
    }

    // Subtraction operator test
    {
        Variant v1(10);
        Variant result = 15 - v1;
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 5);

        Variant result2 = 20.5 - v1;
        ASSERT_TRUE(result2.isFloat());
        ASSERT_NEAR(result2.toFloat(), 10.5, 0.001);

        // Test negative number subtraction
        Variant v2(-3);
        Variant result3 = 8 - v2;
        ASSERT_TRUE(result3.isInt());
        ASSERT_EQ(result3.toInt(), 11);
    }

    // Multiplication operator test
    {
        Variant v1(5);
        Variant result = 3 * v1;
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 15);

        Variant result2 = 2.5 * v1;
        ASSERT_TRUE(result2.isFloat());
        ASSERT_NEAR(result2.toFloat(), 12.5, 0.001);

        // Test zero multiplication
        Variant v2(0);
        Variant result3 = 100 * v2;
        ASSERT_TRUE(result3.isInt());
        ASSERT_EQ(result3.toInt(), 0);
    }

    // Division operator test
    {
        Variant v1(4);
        Variant result = 20 / v1;
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 5);

        Variant v2(3);
        Variant result2 = 10 / v2;
        ASSERT_TRUE(result2.isFloat());
        ASSERT_NEAR(result2.toFloat(), 3.333, 0.001);

        // Test division by 1
        Variant v3(1);
        Variant result3 = 42 / v3;
        ASSERT_TRUE(result3.isInt());
        ASSERT_EQ(result3.toInt(), 42);
    }

    // Modulo operator test
    {
        Variant v1(3);
        Variant result = 10 % v1;
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 1);

        // Test Float specialization version
        Variant result2 = 10.5 % v1;
        ASSERT_TRUE(result2.isInt());
        ASSERT_EQ(result2.toInt(), 1);

        // Test large number modulo
        Variant v2(7);
        Variant result3 = 100 % v2;
        ASSERT_TRUE(result3.isInt());
        ASSERT_EQ(result3.toInt(), 2);
    }
}

TEST(operator_arithmetic, signed_overflow_detection_uses_signed_semantics) {
    Variant negative_one(-1);
    Variant positive_one(1);
    Variant zero(0);

    Variant sum = negative_one + positive_one;
    ASSERT_TRUE(sum.isInt());
    ASSERT_EQ(sum.toInt(), 0);

    Variant difference = zero - positive_one;
    ASSERT_TRUE(difference.isInt());
    ASSERT_EQ(difference.toInt(), -1);

    negative_one += positive_one;
    ASSERT_TRUE(negative_one.isInt());
    ASSERT_EQ(negative_one.toInt(), 0);

    zero -= positive_one;
    ASSERT_TRUE(zero.isInt());
    ASSERT_EQ(zero.toInt(), -1);

    Variant maximum(ZEND_LONG_MAX);
    Variant minimum(ZEND_LONG_MIN);
    ASSERT_TRUE((maximum + positive_one).isFloat());
    ASSERT_TRUE((minimum - positive_one).isFloat());
}

TEST(operator_arithmetic, increment_decrement_overflow_to_float) {
    // ++ on ZEND_LONG_MAX should overflow to double
    Variant max_plus(ZEND_LONG_MAX);
    ++max_plus;
    ASSERT_TRUE(max_plus.isFloat());
    ASSERT_DOUBLE_EQ(max_plus.toFloat(), static_cast<double>(ZEND_LONG_MAX) + 1.0);

    // -- on ZEND_LONG_MIN should underflow to double
    Variant min_minus(ZEND_LONG_MIN);
    --min_minus;
    ASSERT_TRUE(min_minus.isFloat());
    ASSERT_DOUBLE_EQ(min_minus.toFloat(), static_cast<double>(ZEND_LONG_MIN) - 1.0);

    // postfix ++ overflow
    Variant max_post(ZEND_LONG_MAX);
    Variant before = max_post++;
    ASSERT_TRUE(before.isInt());
    ASSERT_EQ(before.toInt(), ZEND_LONG_MAX);
    ASSERT_TRUE(max_post.isFloat());
    ASSERT_DOUBLE_EQ(max_post.toFloat(), static_cast<double>(ZEND_LONG_MAX) + 1.0);

    // postfix -- underflow
    Variant min_post(ZEND_LONG_MIN);
    Variant before2 = min_post--;
    ASSERT_TRUE(before2.isInt());
    ASSERT_EQ(before2.toInt(), ZEND_LONG_MIN);
    ASSERT_TRUE(min_post.isFloat());
    ASSERT_DOUBLE_EQ(min_post.toFloat(), static_cast<double>(ZEND_LONG_MIN) - 1.0);
}

TEST(operator_arithmetic, increment_decrement_normal_paths) {
    // IS_LONG normal increment
    Variant a(41);
    ++a;
    ASSERT_TRUE(a.isInt());
    ASSERT_EQ(a.toInt(), 42);

    // IS_LONG normal decrement
    Variant b(43);
    --b;
    ASSERT_TRUE(b.isInt());
    ASSERT_EQ(b.toInt(), 42);

    // IS_DOUBLE increment
    Variant c(1.5);
    ++c;
    ASSERT_TRUE(c.isFloat());
    ASSERT_DOUBLE_EQ(c.toFloat(), 2.5);

    // IS_DOUBLE decrement
    Variant d(3.5);
    --d;
    ASSERT_TRUE(d.isFloat());
    ASSERT_DOUBLE_EQ(d.toFloat(), 2.5);

    // chained increment
    Variant e(10);
    ++(++e);
    ASSERT_TRUE(e.isInt());
    ASSERT_EQ(e.toInt(), 12);
}

TEST(operator_arithmetic, inline_integral_fast_paths_preserve_dynamic_semantics) {
    Variant sum(10);
    sum += 5L;
    ASSERT_TRUE(sum.isInt());
    ASSERT_EQ(sum.toInt(), 15);

    Variant difference(10);
    difference -= 3L;
    ASSERT_TRUE(difference.isInt());
    ASSERT_EQ(difference.toInt(), 7);

    Variant product(10);
    product *= 4L;
    ASSERT_TRUE(product.isInt());
    ASSERT_EQ(product.toInt(), 40);

    Variant maximum(ZEND_LONG_MAX);
    maximum += 1L;
    ASSERT_TRUE(maximum.isFloat());

    Variant minimum(ZEND_LONG_MIN);
    minimum -= 1L;
    ASSERT_TRUE(minimum.isFloat());

    Variant multiply_overflow(ZEND_LONG_MAX);
    multiply_overflow *= 2L;
    ASSERT_TRUE(multiply_overflow.isFloat());

    Variant fractional(10);
    fractional += 2.5;
    ASSERT_TRUE(fractional.isFloat());
    ASSERT_DOUBLE_EQ(fractional.toFloat(), 12.5);

    Variant numeric_string("10");
    numeric_string += 2L;
    ASSERT_TRUE(numeric_string.isInt());
    ASSERT_EQ(numeric_string.toInt(), 12);

    Variant left(7);
    Variant added = left + 5L;
    Variant subtracted = left - 2L;
    Variant multiplied = left * 3L;
    Variant divided_exact = Variant(12) / 3L;
    Variant divided_fractional = Variant(10) / 4L;
    ASSERT_EQ(added.toInt(), 12);
    ASSERT_EQ(subtracted.toInt(), 5);
    ASSERT_EQ(multiplied.toInt(), 21);
    ASSERT_TRUE(divided_exact.isInt());
    ASSERT_EQ(divided_exact.toInt(), 4);
    ASSERT_TRUE(divided_fractional.isFloat());
    ASSERT_DOUBLE_EQ(divided_fractional.toFloat(), 2.5);
    ASSERT_TRUE((Variant(ZEND_LONG_MAX) + 1L).isFloat());
    ASSERT_TRUE((Variant(ZEND_LONG_MIN) - 1L).isFloat());
    ASSERT_TRUE((Variant(ZEND_LONG_MAX) * 2L).isFloat());
    ASSERT_TRUE((Variant(ZEND_LONG_MIN) / -1L).isFloat());

    Variant divide_assign_exact(12);
    divide_assign_exact /= 3L;
    ASSERT_TRUE(divide_assign_exact.isInt());
    ASSERT_EQ(divide_assign_exact.toInt(), 4);

    Variant divide_assign_fractional(10);
    divide_assign_fractional /= 4L;
    ASSERT_TRUE(divide_assign_fractional.isFloat());
    ASSERT_DOUBLE_EQ(divide_assign_fractional.toFloat(), 2.5);

    bool division_by_zero_caught = false;
    try {
        Variant result = Variant(10) / 0L;
    } catch (zend_object *) {
        division_by_zero_caught = true;
        catchException();
    }
    ASSERT_TRUE(division_by_zero_caught);
}

// Test all bitwise operators (<<, >>, &, |, ^)
TEST(operator_bitwise, all_operators) {
    // Left shift operator test
    {
        Variant v1(static_cast<long>(2));
        Variant result = static_cast<long>(4) << v1;
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 16);  // 4 << 2 = 16

        // Test left shift by 0
        Variant v2(static_cast<long>(0));
        Variant result2 = static_cast<long>(42) << v2;
        ASSERT_TRUE(result2.isInt());
        ASSERT_EQ(result2.toInt(), 42);

        // Test large number left shift
        Variant v3(static_cast<long>(3));
        Variant result3 = static_cast<long>(1000) << v3;
        ASSERT_TRUE(result3.isInt());
        ASSERT_EQ(result3.toInt(), 8000);
    }

    // Right shift operator test
    {
        Variant v1(static_cast<long>(2));
        Variant result = static_cast<long>(16) >> v1;
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 4);  // 16 >> 2 = 4

        // Test right shift by 0
        Variant v2(static_cast<long>(0));
        Variant result2 = static_cast<long>(42) >> v2;
        ASSERT_TRUE(result2.isInt());
        ASSERT_EQ(result2.toInt(), 42);

        // Test odd number right shift
        Variant v3(static_cast<long>(1));
        Variant result3 = static_cast<long>(15) >> v3;
        ASSERT_TRUE(result3.isInt());
        ASSERT_EQ(result3.toInt(), 7);
    }

    // Bitwise AND operator test
    {
        Variant v1(12);            // 1100 in binary
        Variant result = 10 & v1;  // 1010 in binary
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 8);  // 1000 in binary

        // Test AND with 0
        Variant v2(0);
        Variant result2 = 255 & v2;
        ASSERT_TRUE(result2.isInt());
        ASSERT_EQ(result2.toInt(), 0);

        // Test AND with all 1s
        Variant v3(255);
        Variant result3 = 170 & v3;  // 170 = 10101010
        ASSERT_TRUE(result3.isInt());
        ASSERT_EQ(result3.toInt(), 170);
    }

    // Bitwise OR operator test
    {
        Variant v1(12);            // 1100 in binary
        Variant result = 10 | v1;  // 1010 in binary
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 14);  // 1110 in binary

        // Test OR with 0
        Variant v2(0);
        Variant result2 = 42 | v2;
        ASSERT_TRUE(result2.isInt());
        ASSERT_EQ(result2.toInt(), 42);

        // Test OR with all 1s
        Variant v3(255);
        Variant result3 = 10 | v3;
        ASSERT_TRUE(result3.isInt());
        ASSERT_EQ(result3.toInt(), 255);
    }

    // Bitwise XOR operator test
    {
        Variant v1(12);            // 1100 in binary
        Variant result = 10 ^ v1;  // 1010 in binary
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 6);  // 0110 in binary

        // Test same value XOR
        Variant v2(42);
        Variant result2 = 42 ^ v2;
        ASSERT_TRUE(result2.isInt());
        ASSERT_EQ(result2.toInt(), 0);

        // Test XOR with 0
        Variant v3(0);
        Variant result3 = 123 ^ v3;
        ASSERT_TRUE(result3.isInt());
        ASSERT_EQ(result3.toInt(), 123);
    }
}

// Test all comparison operators (<=, <, >=, >, ==)
TEST(operator_comparison, all_operators) {
    // Less than or equal operator test
    {
        Variant v1(10);
        ASSERT_TRUE((5 <= v1).toBool());
        ASSERT_TRUE((10 <= v1).toBool());
        ASSERT_FALSE((15 <= v1).toBool());

        // Test floating point
        Variant v2(3.14);
        ASSERT_TRUE((2.5 <= v2).toBool());
        ASSERT_TRUE((3.14 <= v2).toBool());
        ASSERT_FALSE((4.0 <= v2).toBool());

        // Test negative numbers
        Variant v3(-5);
        ASSERT_TRUE((-10 <= v3).toBool());  // -10 <= -5 is true
        ASSERT_TRUE((-5 <= v3).toBool());   // -5 <= -5 is true
        ASSERT_FALSE((0 <= v3).toBool());   // 0 <= -5 is false
    }

    // Less than operator test
    {
        Variant v1(10);
        ASSERT_TRUE((5 < v1).toBool());
        ASSERT_FALSE((10 < v1).toBool());
        ASSERT_FALSE((15 < v1).toBool());

        // Test string comparison
        Variant v2("15");
        ASSERT_TRUE((10 < v2).toBool());
        ASSERT_FALSE((20 < v2).toBool());
    }

    // Greater than or equal operator test
    {
        Variant v1(10);
        ASSERT_FALSE((5 >= v1).toBool());
        ASSERT_TRUE((10 >= v1).toBool());
        ASSERT_TRUE((15 >= v1).toBool());

        // Test boundary cases
        Variant v2(0);
        ASSERT_TRUE((0 >= v2).toBool());
        ASSERT_FALSE((-1 >= v2).toBool());
    }

    // Greater than operator test
    {
        Variant v1(10);
        ASSERT_FALSE((5 > v1).toBool());
        ASSERT_FALSE((10 > v1).toBool());
        ASSERT_TRUE((15 > v1).toBool());

        // Test floating point
        Variant v2(2.5);
        ASSERT_FALSE((2.0 > v2).toBool());
        ASSERT_FALSE((2.5 > v2).toBool());
        ASSERT_TRUE((3.0 > v2).toBool());
    }

    // Equal operator test
    {
        Variant v1(10);
        static_assert(std::is_same_v<decltype(10 == v1), bool>);
        static_assert(std::is_same_v<decltype(v1 == 10), bool>);
        ASSERT_FALSE(5 == v1);
        ASSERT_TRUE(10 == v1);
        ASSERT_FALSE(15 == v1);
        ASSERT_FALSE(v1 == 5);
        ASSERT_TRUE(v1 == 10);
        ASSERT_FALSE(v1 == 15);

        // Test different type comparison
        Variant v2("10");
        ASSERT_TRUE(10 == v2);
        ASSERT_TRUE("10" == v2);
        ASSERT_FALSE(11 == v2);

        // Test floating point equality
        Variant v3(3.14);
        ASSERT_TRUE(3.14 == v3);
        ASSERT_FALSE(3.15 == v3);
    }
}

TEST(operator_comparison, integral_fast_paths) {
    {
        Variant a(10);
        Variant b(20);
        ASSERT_TRUE(a < b);
        ASSERT_FALSE(b < a);
        ASSERT_FALSE(a < a);
        ASSERT_TRUE(a <= b);
        ASSERT_TRUE(a <= a);
        ASSERT_FALSE(b <= a);
        ASSERT_FALSE(a > b);
        ASSERT_TRUE(b > a);
        ASSERT_FALSE(a > a);
        ASSERT_FALSE(a >= b);
        ASSERT_TRUE(b >= a);
        ASSERT_TRUE(a >= a);
    }
    {
        Variant neg(-5);
        Variant pos(5);
        ASSERT_TRUE(neg < pos);
        ASSERT_FALSE(pos < neg);
        ASSERT_TRUE(neg <= pos);
        ASSERT_FALSE(pos <= neg);
        ASSERT_FALSE(neg > pos);
        ASSERT_TRUE(pos > neg);
        ASSERT_FALSE(neg >= pos);
        ASSERT_TRUE(pos >= neg);
    }
    {
        Variant max_val(ZEND_LONG_MAX);
        Variant min_val(ZEND_LONG_MIN);
        Variant zero(0);
        ASSERT_TRUE(min_val < max_val);
        ASSERT_FALSE(max_val < min_val);
        ASSERT_TRUE(min_val <= max_val);
        ASSERT_FALSE(max_val <= min_val);
        ASSERT_FALSE(min_val > max_val);
        ASSERT_TRUE(max_val > min_val);
        ASSERT_FALSE(min_val >= max_val);
        ASSERT_TRUE(max_val >= min_val);
        ASSERT_TRUE(zero >= min_val);
        ASSERT_TRUE(zero <= max_val);
    }
    {
        Variant int_val(10);
        Variant float_val(10.5);
        ASSERT_TRUE(int_val < float_val);
        ASSERT_FALSE(float_val < int_val);
        ASSERT_TRUE(int_val <= float_val);
        ASSERT_FALSE(float_val <= int_val);
        ASSERT_FALSE(int_val > float_val);
        ASSERT_TRUE(float_val > int_val);
        ASSERT_FALSE(int_val >= float_val);
        ASSERT_TRUE(float_val >= int_val);
    }
    {
        Variant int_val(10);
        Variant str_val("15");
        ASSERT_TRUE(int_val < str_val);
        ASSERT_FALSE(str_val < int_val);
    }
}

TEST(operator_comparison, mixed_type_fast_paths) {
    {
        Variant float_val(3.14);
        Variant int_val(5);
        ASSERT_TRUE(float_val < int_val);
        ASSERT_FALSE(int_val < float_val);
        ASSERT_TRUE(float_val <= int_val);
        ASSERT_FALSE(int_val <= float_val);
        ASSERT_FALSE(float_val > int_val);
        ASSERT_TRUE(int_val > float_val);
        ASSERT_FALSE(float_val >= int_val);
        ASSERT_TRUE(int_val >= float_val);
    }
    {
        Variant int_val(5);
        Variant float_val(3.14);
        ASSERT_FALSE(int_val < float_val);
        ASSERT_TRUE(float_val < int_val);
        ASSERT_FALSE(int_val <= float_val);
        ASSERT_TRUE(float_val <= int_val);
        ASSERT_TRUE(int_val > float_val);
        ASSERT_FALSE(float_val > int_val);
        ASSERT_TRUE(int_val >= float_val);
        ASSERT_FALSE(float_val >= int_val);
    }
    {
        Variant a(5.0);
        Variant b(5.0);
        ASSERT_FALSE(a < b);
        ASSERT_TRUE(a <= b);
        ASSERT_FALSE(a > b);
        ASSERT_TRUE(a >= b);
    }
    {
        Variant neg_float(-1.5);
        Variant pos_int(1);
        ASSERT_TRUE(neg_float < pos_int);
        ASSERT_FALSE(pos_int < neg_float);
        ASSERT_TRUE(neg_float <= pos_int);
        ASSERT_FALSE(pos_int <= neg_float);
    }
}

TEST(operator_comparison, primitive_overloads) {
    {
        Variant v(10);
        ASSERT_TRUE(v < 20L);
        ASSERT_FALSE(v < 10L);
        ASSERT_FALSE(v < 5L);
        ASSERT_TRUE(v > 5L);
        ASSERT_FALSE(v > 10L);
        ASSERT_FALSE(v > 20L);
        ASSERT_TRUE(v <= 10L);
        ASSERT_TRUE(v <= 20L);
        ASSERT_FALSE(v <= 5L);
        ASSERT_TRUE(v >= 10L);
        ASSERT_TRUE(v >= 5L);
        ASSERT_FALSE(v >= 20L);
    }
    {
        Variant v(3.14);
        ASSERT_TRUE(v < 5.0);
        ASSERT_FALSE(v < 3.14);
        ASSERT_FALSE(v < 2.0);
        ASSERT_TRUE(v > 2.0);
        ASSERT_FALSE(v > 3.14);
        ASSERT_FALSE(v > 5.0);
        ASSERT_TRUE(v <= 3.14);
        ASSERT_TRUE(v <= 5.0);
        ASSERT_FALSE(v <= 2.0);
        ASSERT_TRUE(v >= 3.14);
        ASSERT_TRUE(v >= 2.0);
        ASSERT_FALSE(v >= 5.0);
    }
    {
        Variant neg(-5);
        ASSERT_TRUE(neg < 0L);
        ASSERT_TRUE(neg < -1L);
        ASSERT_FALSE(neg < -10L);
        ASSERT_TRUE(neg > -10L);
        ASSERT_FALSE(neg > 0L);
    }
}

TEST(operator_comparison, fast_paths_match_zend_at_numeric_boundaries) {
    std::vector<Variant> values = {
        Variant(ZEND_LONG_MIN),
        Variant(-1),
        Variant(0),
        Variant(1),
        Variant(ZEND_LONG_MAX),
        Variant(-std::numeric_limits<double>::infinity()),
        Variant(-0.0),
        Variant(0.0),
        Variant(0.5),
        Variant(std::numeric_limits<double>::infinity()),
        Variant(std::numeric_limits<double>::quiet_NaN()),
    };
    if constexpr (sizeof(Int) >= sizeof(int64_t)) {
        values.emplace_back(static_cast<Int>(INT64_C(9007199254740991)));
        values.emplace_back(static_cast<Int>(INT64_C(9007199254740992)));
        values.emplace_back(static_cast<Int>(INT64_C(9007199254740993)));
        values.emplace_back(9007199254740992.0);
    }

    for (const auto &left : values) {
        for (const auto &right : values) {
            expect_relational_operators_match_zend(left, right);
        }
    }
}

TEST(operator_comparison, references_indirect_values_and_fallback_match_zend) {
    Variant referenced_value(42);
    Reference reference = referenced_value.toReference();
    Variant other(42.5);
    expect_relational_operators_match_zend(reference, other);
    expect_relational_operators_match_zend(other, reference);

    Array values;
    values.appendValue(42);
    Variant indirect = values.item(0);
    ASSERT_TRUE(indirect.isIndirect());
    expect_relational_operators_match_zend(indirect, other);
    expect_relational_operators_match_zend(other, indirect);

    const std::vector<Variant> fallback_values = {
        Variant(nullptr),
        Variant(false),
        Variant(true),
        Variant("0"),
        Variant("10.5"),
        Variant("text"),
    };
    for (const auto &left : fallback_values) {
        for (const auto &right : fallback_values) {
            expect_relational_operators_match_zend(left, right);
        }
    }
}

TEST(operator_comparison, primitive_overloads_preserve_variant_conversion_semantics) {
    const std::vector<Variant> left_values = {
        Variant(10),
        Variant(10.5),
        Variant("10"),
    };
    const auto check = [&left_values](auto raw) {
        const Variant boxed(raw);
        for (const auto &left : left_values) {
            EXPECT_EQ(left < raw, left < boxed);
            EXPECT_EQ(left <= raw, left <= boxed);
            EXPECT_EQ(left > raw, left > boxed);
            EXPECT_EQ(left >= raw, left >= boxed);
            EXPECT_EQ((raw < left).toBool(), boxed < left);
            EXPECT_EQ((raw <= left).toBool(), boxed <= left);
            EXPECT_EQ((raw > left).toBool(), boxed > left);
            EXPECT_EQ((raw >= left).toBool(), boxed >= left);
        }
    };

    check(int8_t{-1});
    check(int32_t{10});
    check(int64_t{11});
    check(uint32_t{12});
    check(std::numeric_limits<uint64_t>::max());
    check(9.5F);
    check(10.5);
    check(11.5L);
    check(std::numeric_limits<double>::quiet_NaN());
}

// Test mixed type operations
TEST(operator_mixed_types, arithmetic_operations) {
    // Integer and floating point operations
    {
        Variant v1(10.5);  // Float
        Variant result = 5 + v1;
        ASSERT_TRUE(result.isFloat());
        ASSERT_NEAR(result.toFloat(), 15.5, 0.001);

        Variant result2 = 20 - v1;
        ASSERT_TRUE(result2.isFloat());
        ASSERT_NEAR(result2.toFloat(), 9.5, 0.001);

        Variant result3 = 2 * v1;
        ASSERT_TRUE(result3.isFloat());
        ASSERT_NEAR(result3.toFloat(), 21.0, 0.001);
    }

    // String number operations
    {
        Variant v1("15");
        Variant result = 5 + v1;
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 20);

        Variant result2 = 25 - v1;
        ASSERT_TRUE(result2.isInt());
        ASSERT_EQ(result2.toInt(), 10);

        Variant result3 = 3 * v1;
        ASSERT_TRUE(result3.isInt());
        ASSERT_EQ(result3.toInt(), 45);

        Variant result4 = 30 / v1;
        ASSERT_TRUE(result4.isInt());
        ASSERT_EQ(result4.toInt(), 2);
    }

    // Boolean operations
    {
        Variant v1(true);
        Variant result = 1 + v1;  // true converts to 1
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 2);

        Variant v2(false);
        Variant result2 = 5 + v2;  // false converts to 0
        ASSERT_TRUE(result2.isInt());
        ASSERT_EQ(result2.toInt(), 5);

        Variant result3 = 3 - v1;
        ASSERT_TRUE(result3.isInt());
        ASSERT_EQ(result3.toInt(), 2);
    }

    // Null operations
    {
        Variant v1(nullptr);
        Variant result = 5 + v1;  // nullptr converts to 0
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 5);
    }
}

// Test edge cases and exception cases
TEST(operator_edge_cases, boundary_conditions) {
    // Zero value operations
    {
        Variant v1(0);
        Variant result = 10 + v1;
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 10);

        Variant result2 = 10 * v1;
        ASSERT_TRUE(result2.isInt());
        ASSERT_EQ(result2.toInt(), 0);

        // Test modulo zero - PHP throws DivisionByZeroError
        bool exception_caught = false;
        try {
            Variant result3 = 10 % v1;
        } catch (zend_object *ex) {
            exception_caught = true;
            catchException();  // Clear the exception
        }
        ASSERT_TRUE(exception_caught) << "Expected DivisionByZeroError for modulo by zero";
    }

    // Negative value operations
    {
        Variant v1(-5);
        Variant result = 10 + v1;
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 5);

        Variant result2 = 10 - v1;
        ASSERT_TRUE(result2.isInt());
        ASSERT_EQ(result2.toInt(), 15);

        Variant result3 = 3 * v1;
        ASSERT_TRUE(result3.isInt());
        ASSERT_EQ(result3.toInt(), -15);
    }

    // Large value operations
    {
        Variant v1(1000000L);
        Variant result = 2000000L + v1;
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 3000000L);

        Variant result2 = 5000000L - v1;
        ASSERT_TRUE(result2.isInt());
        ASSERT_EQ(result2.toInt(), 4000000L);
    }

    // Extreme bitwise operations
    {
        Variant v1(static_cast<long>(31));  // Close to max shift bits for int
        Variant result = static_cast<long>(1) << v1;
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), static_cast<long>(1) << 31);  // 2^31

        Variant v2(static_cast<long>(0));
        Variant result2 = static_cast<long>(0xFFFFFFFF) >> v2;  // Right shift by 0
        ASSERT_TRUE(result2.isInt());
        ASSERT_EQ(result2.toInt(), static_cast<long>(0xFFFFFFFF));
    }
}

// Test special Float template specialization
TEST(operator_specialization, float_modulo) {
    // Test Float type modulo operation specialization
    {
        Float f1 = 10.7;
        Variant v1(3);
        Variant result = f1 % v1;
        // The result type may vary, just check it's numeric
        ASSERT_TRUE(result.isNumeric());
        ASSERT_EQ(result.toInt(), 1);  // 10.7 % 3 = 1

        Float f2 = 15.2;
        Variant v2(4);
        Variant result2 = f2 % v2;
        ASSERT_TRUE(result2.isNumeric());
        ASSERT_EQ(result2.toInt(), 3);  // 15.2 % 4 = 3
    }

    // Test negative Float modulo - PHP uses mathematical modulo
    {
        Float f1 = -7.3;
        Variant v1(3);
        Variant result = f1 % v1;
        ASSERT_TRUE(result.isNumeric());
        int result_int = result.toInt();
        ASSERT_TRUE(result_int = -1);
    }
}

// Test operator precedence and associativity
TEST(operator_precedence, precedence_and_associativity) {
    // Test operator precedence
    {
        Variant v1(2);
        Variant v2(3);

        // Multiplication precedes addition: 5 + 2 * 3 = 5 + 6 = 11
        Variant result = 5 + v1 * v2;
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 11);

        // Use parentheses to change precedence: (5 + 2) * 3 = 7 * 3 = 21
        Variant result2 = (5 + v1) * v2;
        ASSERT_TRUE(result2.isInt());
        ASSERT_EQ(result2.toInt(), 21);
    }

    // Test left associativity
    {
        Variant v1(10);
        Variant v2(2);
        Variant v3(3);

        // Left associative: (100 - 10) - 2 = 90 - 2 = 88
        Variant result = 100 - v1 - v2;
        ASSERT_TRUE(result.isInt());
        ASSERT_EQ(result.toInt(), 88);

        // Left associative: (100 / 10) / 2 = 10 / 2 = 5
        Variant result2 = 100 / v1 / v2;
        ASSERT_TRUE(result2.isInt());
        ASSERT_EQ(result2.toInt(), 5);
    }
}

TEST(operator_comparison, equality_fast_paths) {
    // IS_LONG × IS_LONG
    {
        Variant a(42);
        Variant b(42);
        Variant c(43);
        EXPECT_TRUE(a == b);
        EXPECT_FALSE(a == c);
        EXPECT_FALSE(a != b);
        EXPECT_TRUE(a != c);
    }

    // IS_DOUBLE × IS_DOUBLE
    {
        Variant a(3.14);
        Variant b(3.14);
        Variant c(2.71);
        EXPECT_TRUE(a == b);
        EXPECT_FALSE(a == c);
        EXPECT_FALSE(a != b);
        EXPECT_TRUE(a != c);
    }

    // Mixed IS_LONG × IS_DOUBLE
    {
        Variant a(2);
        Variant b(2.0);
        Variant c(2.1);
        EXPECT_TRUE(a == b);
        EXPECT_FALSE(a == c);
        EXPECT_FALSE(a != b);
        EXPECT_TRUE(a != c);
    }

    // Primitive type overloads: Variant == int
    {
        Variant a(42);
        EXPECT_TRUE(a == 42);
        EXPECT_FALSE(a == 43);
        EXPECT_FALSE(a != 42);
        EXPECT_TRUE(a != 43);
    }

    // Primitive type overloads: Variant == float
    {
        Variant a(3.14);
        EXPECT_TRUE(a == 3.14);
        EXPECT_FALSE(a == 2.71);
        EXPECT_FALSE(a != 3.14);
        EXPECT_TRUE(a != 2.71);
    }

    // Reverse: primitive == Variant (int == Variant)
    {
        Variant a(42);
        EXPECT_TRUE(42 == a);
        EXPECT_FALSE(43 == a);
    }

    // Reverse: primitive == Variant (float == Variant)
    {
        Variant a(3.14);
        EXPECT_TRUE(3.14 == a);
        EXPECT_FALSE(2.71 == a);
    }

    // String fallback
    {
        Variant a("hello");
        Variant b("hello");
        Variant c("world");
        EXPECT_TRUE(a == b);
        EXPECT_FALSE(a == c);
        EXPECT_TRUE(a != c);
    }

    // php::equals free function
    {
        Variant a(42);
        Variant b(42);
        Variant c(43);
        EXPECT_TRUE(php::equals(a, b));
        EXPECT_FALSE(php::equals(a, c));
    }
}
