#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_decimal.h"

using namespace php;

// ============ Construction ============

TEST(decimal, construct_from_string) {
    auto a = php::newDecimal("123.456");
    auto *d = a.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    auto str = Decimal::toString(a);
    auto s = str.toCString();
    ASSERT_TRUE(std::strstr(s, "123.456") != nullptr);
}

TEST(decimal, construct_from_int) {
    auto a = php::newDecimal((php::Int) 42);
    auto *d = a.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_EQ(Decimal::toInt(a).toInt(), 42);
}

TEST(decimal, construct_negative) {
    auto a = php::newDecimal("-99.99");
    auto *d = a.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    auto str = Decimal::toString(a);
    auto s = str.toCString();
    ASSERT_EQ(s[0], '-');
}

TEST(decimal, construct_zero) {
    auto a = php::newDecimal("0");
    auto *d = a.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_EQ(Decimal::toInt(a).toInt(), 0);
}

TEST(decimal, newInstance_from_string) {
    Variant s("12345.6789");
    auto v = Decimal::newInstance(s);
    auto *d = v.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    auto tmp = Decimal::toString(v);
    auto str = tmp.toCString();
    ASSERT_TRUE(std::strstr(str, "12345.6789") != nullptr);
}

TEST(decimal, newInstance_from_int) {
    Variant s((php::Int) 100);
    auto v = Decimal::newInstance(s);
    auto *d = v.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_EQ(Decimal::toInt(v).toInt(), 100);
}

// ============ Arithmetic ============

TEST(decimal, add) {
    auto a = php::newDecimal("100.50");
    auto b = php::newDecimal("200.25");
    auto r = Decimal::add(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 300.75, 0.01);
}

TEST(decimal, add_int_promotion) {
    auto a = php::newDecimal("50.25");
    Variant b(100);
    auto r = Decimal::add(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 150.25, 0.01);
}

TEST(decimal, add_string_promotion) {
    auto a = php::newDecimal("100.0");
    Variant b("0.5");
    auto r = Decimal::add(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 100.5, 0.01);
}

TEST(decimal, sub) {
    auto a = php::newDecimal("100.50");
    auto b = php::newDecimal("30.25");
    auto r = Decimal::sub(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 70.25, 0.01);
}

TEST(decimal, sub_negative_result) {
    auto a = php::newDecimal("10.00");
    auto b = php::newDecimal("50.00");
    auto r = Decimal::sub(a, b);
    auto tmp = Decimal::toString(r);
    auto str = tmp.toCString();
    ASSERT_EQ(str[0], '-');
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), -40.0, 0.01);
}

TEST(decimal, mul) {
    auto a = php::newDecimal("3.5");
    auto b = php::newDecimal("2.0");
    auto r = Decimal::mul(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 7.0, 0.01);
}

TEST(decimal, mul_int) {
    auto a = php::newDecimal("6.25");
    auto b = php::newDecimal((php::Int) 4);
    auto r = Decimal::mul(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 25.0, 0.01);
}

TEST(decimal, mul_zero) {
    auto a = php::newDecimal("123.456");
    auto b = php::newDecimal("0");
    auto r = Decimal::mul(a, b);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 0);
}

TEST(decimal, div) {
    auto a = php::newDecimal("100.0");
    auto b = php::newDecimal("4.0");
    auto r = Decimal::div(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 25.0, 0.01);
}

TEST(decimal, div_non_integer) {
    auto a = php::newDecimal("10.0");
    auto b = php::newDecimal("3.0");
    auto r = Decimal::div(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 3.333, 0.01);
}

TEST(decimal, mod) {
    auto a = php::newDecimal("100.0");
    auto b = php::newDecimal("3.0");
    auto r = Decimal::mod(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 1.0, 0.01);
}

TEST(decimal, mod_exact) {
    auto a = php::newDecimal("100.0");
    auto b = php::newDecimal("20.0");
    auto r = Decimal::mod(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 0.0, 0.01);
}

TEST(decimal, neg) {
    auto a = php::newDecimal("100.50");
    auto r = Decimal::neg(a);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), -100.5, 0.01);
}

TEST(decimal, neg_negative) {
    auto a = php::newDecimal("-50.25");
    auto r = Decimal::neg(a);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 50.25, 0.01);
}

TEST(decimal, abs_positive) {
    auto a = php::newDecimal("123.456");
    auto r = Decimal::abs(a);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 123.456, 0.01);
}

TEST(decimal, abs_negative) {
    auto a = php::newDecimal("-123.456");
    auto r = Decimal::abs(a);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 123.456, 0.01);
}

TEST(decimal, abs_zero) {
    auto a = php::newDecimal("0");
    auto r = Decimal::abs(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 0);
}

// ============ Comparison ============

TEST(decimal, cmp_greater) {
    auto a = php::newDecimal("200.50");
    auto b = php::newDecimal("100.25");
    auto r = Decimal::cmp(a, b);
    ASSERT_GT(r.toInt(), 0);
}

TEST(decimal, cmp_less) {
    auto a = php::newDecimal("100.00");
    auto b = php::newDecimal("200.00");
    auto r = Decimal::cmp(a, b);
    ASSERT_LT(r.toInt(), 0);
}

TEST(decimal, cmp_equal) {
    auto a = php::newDecimal("100.50");
    auto b = php::newDecimal("100.50");
    auto r = Decimal::cmp(a, b);
    ASSERT_EQ(r.toInt(), 0);
}

TEST(decimal, cmp_negative_vs_positive) {
    auto a = php::newDecimal("-10.0");
    auto b = php::newDecimal("10.0");
    auto r = Decimal::cmp(a, b);
    ASSERT_LT(r.toInt(), 0);
}

TEST(decimal, cmp_both_negative) {
    auto a = php::newDecimal("-10.0");
    auto b = php::newDecimal("-50.0");
    auto r = Decimal::cmp(a, b);
    ASSERT_GT(r.toInt(), 0);
}

// ============ Conversion ============

TEST(decimal, toString) {
    auto a = php::newDecimal("123.456");
    auto r = Decimal::toString(a);
    ASSERT_TRUE(r.isString());
    ASSERT_TRUE(std::strstr(r.toCString(), "123.456") != nullptr);
}

TEST(decimal, toString_integer) {
    auto a = php::newDecimal("42.00");
    auto r = Decimal::toString(a);
    ASSERT_TRUE(r.isString());
    ASSERT_GT(r.length(), 0u);
}

TEST(decimal, toInt) {
    auto a = php::newDecimal("3.14");
    auto r = Decimal::toInt(a);
    ASSERT_TRUE(r.isInt());
    ASSERT_EQ(r.toInt(), 3);
}

TEST(decimal, toInt_negative) {
    auto a = php::newDecimal("-3.14");
    auto r = Decimal::toInt(a);
    ASSERT_EQ(r.toInt(), -3);
}

TEST(decimal, toFloat) {
    auto a = php::newDecimal("3.14");
    auto r = Decimal::toFloat(a);
    ASSERT_NEAR(r.toFloat(), 3.14, 0.001);
}

// ============ Edge cases ============

TEST(decimal, high_precision_string) {
    auto a = php::newDecimal("123.45678901234567890");
    auto tmp = Decimal::toString(a);
    auto s = tmp.toCString();
    ASSERT_TRUE(std::strstr(s, "123.45678901234567890") != nullptr);
}

TEST(decimal, string_promotion) {
    auto a = php::newDecimal("100.50");
    Variant b("50.25");
    auto r = Decimal::add(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 150.75, 0.01);
}

TEST(decimal, chained_operations) {
    auto a = php::newDecimal("100.0");
    auto b = php::newDecimal("50.0");
    auto sum = Decimal::add(a, b);
    auto prod = Decimal::mul(sum, php::newDecimal("2.0"));
    auto diff = Decimal::sub(prod, php::newDecimal("20.0"));
    auto result = Decimal::div(diff, php::newDecimal("5.0"));
    auto *d = result.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(result).toFloat(), 56.0, 0.01);
}
