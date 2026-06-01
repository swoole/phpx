#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_decimal.h"

#include <cstring>

using namespace php;

static inline Variant dc(const char *s) {
    return php::newDecimal(s);
}

static inline Variant dc(php::Int v) {
    return php::newDecimal(v);
}

// ============ round ============

TEST(decimal_adv, round_integer) {
    auto a = dc("123.456");
    auto r = Decimal::round(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 123);
}

TEST(decimal_adv, round_precision_1) {
    auto a = dc("123.456");
    auto r = Decimal::round(a, Variant((php::Int) 1));
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 123.5, 0.1);
}

TEST(decimal_adv, round_precision_2) {
    auto a = dc("123.456");
    auto r = Decimal::round(a, Variant((php::Int) 2));
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 123.46, 0.01);
}

TEST(decimal_adv, round_half_even) {
    auto a = dc("2.5");
    auto r = Decimal::round(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 2);  // ROUND_HALF_EVEN: 2.5 → 2
}

TEST(decimal_adv, round_half_down) {
    auto a = dc("2.4999999");
    auto r = Decimal::round(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 2);
}

TEST(decimal_adv, round_negative_half_up) {
    auto a = dc("-2.5");
    auto r = Decimal::round(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), -2);  // ROUND_HALF_EVEN: -2.5 → -2
}

TEST(decimal_adv, round_high_precision) {
    auto a = dc("123.45678901234567890123456789");
    auto r = Decimal::round(a, Variant((php::Int) 10));
    auto s = Decimal::toString(r).toCString();
    ASSERT_TRUE(std::strstr(s, "123.4567890123") != nullptr);
}

TEST(decimal_adv, round_zero_value) {
    auto a = dc("0.00");
    auto r = Decimal::round(a, Variant((php::Int) 5));
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 0.0, 0.001);
}

// ============ floor ============

TEST(decimal_adv, floor_positive) {
    auto a = dc("123.999");
    auto r = Decimal::floor(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 123);
}

TEST(decimal_adv, floor_negative) {
    auto a = dc("-123.001");
    auto r = Decimal::floor(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), -124);
}

TEST(decimal_adv, floor_integer) {
    auto a = dc("42.0");
    auto r = Decimal::floor(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 42);
}

TEST(decimal_adv, floor_near_zero_positive) {
    auto a = dc("0.999");
    auto r = Decimal::floor(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 0);
}

TEST(decimal_adv, floor_near_zero_negative) {
    auto a = dc("-0.001");
    auto r = Decimal::floor(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), -1);
}

// ============ ceil ============

TEST(decimal_adv, ceil_positive) {
    auto a = dc("123.001");
    auto r = Decimal::ceil(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 124);
}

TEST(decimal_adv, ceil_negative) {
    auto a = dc("-123.999");
    auto r = Decimal::ceil(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), -123);
}

TEST(decimal_adv, ceil_integer) {
    auto a = dc("42.0");
    auto r = Decimal::ceil(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 42);
}

TEST(decimal_adv, ceil_near_zero_positive) {
    auto a = dc("0.001");
    auto r = Decimal::ceil(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 1);
}

TEST(decimal_adv, ceil_near_zero_negative) {
    auto a = dc("-0.999");
    auto r = Decimal::ceil(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 0);
}

// ============ divmod ============

TEST(decimal_adv, divmod_basic) {
    auto a = dc("10.0");
    auto b = dc("3.0");
    auto r = Decimal::divmod(a, b);
    ASSERT_TRUE(r.isArray());
    auto arr = r.toArray();
    // quotient = 3, remainder = 1
    ASSERT_EQ(Decimal::toInt(arr[0]).toInt(), 3);
    ASSERT_EQ(Decimal::toInt(arr[1]).toInt(), 1);
}

TEST(decimal_adv, divmod_exact) {
    auto a = dc("100.0");
    auto b = dc("25.0");
    auto r = Decimal::divmod(a, b);
    auto arr = r.toArray();
    ASSERT_EQ(Decimal::toInt(arr[0]).toInt(), 4);
    ASSERT_EQ(Decimal::toInt(arr[1]).toInt(), 0);
}

TEST(decimal_adv, divmod_with_fractional) {
    auto a = dc("10.5");
    auto b = dc("3.2");
    auto r = Decimal::divmod(a, b);
    auto arr = r.toArray();
    // quotient = trunc(10.5 / 3.2) = 3
    ASSERT_EQ(Decimal::toInt(arr[0]).toInt(), 3);
    // remainder should exist
    ASSERT_NE(Decimal::toFloat(arr[1]).toFloat(), 0.0);
}

// ============ powmod ============

TEST(decimal_adv, powmod_basic) {
    auto base = dc("2.0");
    auto exp = dc("10.0");
    auto mod = dc("1000.0");
    auto r = Decimal::powmod(base, exp, mod);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 24);  // 2^10 % 1000 = 1024 % 1000 = 24
}

TEST(decimal_adv, powmod_identity) {
    auto base = dc("7.0");
    auto exp = dc("1.0");
    auto mod = dc("100.0");
    auto r = Decimal::powmod(base, exp, mod);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 7);  // 7^1 % 100 = 7
}

TEST(decimal_adv, powmod_large) {
    auto base = dc("3.0");
    auto exp = dc("20.0");
    auto mod = dc("100000.0");
    auto r = Decimal::powmod(base, exp, mod);
    // 3^20 = 3486784401, % 100000 = 84401
    ASSERT_EQ(Decimal::toInt(r).toInt(), 84401);
}

// ============ sqrt ============

TEST(decimal_adv, sqrt_perfect_square) {
    auto a = dc("144.0");
    auto r = Decimal::sqrt(a);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 12.0, 0.001);
}

TEST(decimal_adv, sqrt_non_perfect) {
    auto a = dc("2.0");
    auto r = Decimal::sqrt(a);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 1.4142, 0.001);
}

TEST(decimal_adv, sqrt_zero) {
    auto a = dc("0.0");
    auto r = Decimal::sqrt(a);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 0.0, 0.001);
}

TEST(decimal_adv, sqrt_one) {
    auto a = dc("1.0");
    auto r = Decimal::sqrt(a);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 1.0, 0.001);
}

TEST(decimal_adv, sqrt_large) {
    auto a = dc("1000000.0");
    auto r = Decimal::sqrt(a);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 1000.0, 0.1);
}

// ============ round / floor / ceil consistency ============

TEST(decimal_adv, round_vs_floor_vs_ceil) {
    auto a = dc("6.789");
    auto r_floor = Decimal::toInt(Decimal::floor(a)).toInt();
    auto r_ceil = Decimal::toInt(Decimal::ceil(a)).toInt();
    ASSERT_EQ(r_floor, 6);
    ASSERT_EQ(r_ceil, 7);
}

TEST(decimal_adv, round_does_not_throw) {
    // High precision should not crash
    auto a = dc("89.97");
    auto r = Decimal::round(a, Variant((php::Int) 20));
    auto s = Decimal::toString(r).toCString();
    ASSERT_TRUE(std::strstr(s, "89.97") != nullptr);
}
