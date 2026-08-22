#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_decimal.h"

#include <cstring>

using namespace php;

TEST(decimal, conversion_bridge_preserves_boxed_value) {
    Variant value = php::toDecimal("123.75");
    Variant converted = Decimal::toBigInt(value);

    ASSERT_NE(converted.toBox<Decimal>(), nullptr);
    ASSERT_STREQ(Decimal::toString(converted).toCString(), "123.75");
}

// ============ Construction ============

TEST(decimal, construct_from_string) {
    auto a = php::toDecimal("123.456");
    auto *d = a.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    auto str = Decimal::toString(a);
    auto s = str.toCString();
    ASSERT_TRUE(std::strstr(s, "123.456") != nullptr);
}

TEST(decimal, construct_from_int) {
    auto a = php::toDecimal((php::Int) 42);
    auto *d = a.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_EQ(Decimal::toInt(a).toInt(), 42);
}

TEST(decimal, construct_negative) {
    auto a = php::toDecimal("-99.99");
    auto *d = a.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    auto str = Decimal::toString(a);
    auto s = str.toCString();
    ASSERT_EQ(s[0], '-');
}

TEST(decimal, construct_zero) {
    auto a = php::toDecimal("0");
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

TEST(decimal, request_init_restores_default_precision) {
    decimal::context.prec(7);
    request_shutdown();
    request_init();

    ASSERT_EQ(decimal::context.prec(), 50);

    auto one = Decimal::newInstance(Variant(1));
    auto seven = Decimal::newInstance(Variant(7));
    auto result = Decimal::div(one, seven);
    ASSERT_EQ(Decimal::toString(result).toString(), "0.14285714285714285714285714285714285714285714285714");
}

// ============ Arithmetic ============

TEST(decimal, add) {
    auto a = php::toDecimal("100.50");
    auto b = php::toDecimal("200.25");
    auto r = Decimal::add(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 300.75, 0.01);
}

TEST(decimal, add_int_promotion) {
    auto a = php::toDecimal("50.25");
    Variant b(100);
    auto r = Decimal::add(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 150.25, 0.01);
}

TEST(decimal, add_string_promotion) {
    auto a = php::toDecimal("100.0");
    Variant b("0.5");
    auto r = Decimal::add(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 100.5, 0.01);
}

TEST(decimal, sub) {
    auto a = php::toDecimal("100.50");
    auto b = php::toDecimal("30.25");
    auto r = Decimal::sub(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 70.25, 0.01);
}

TEST(decimal, sub_negative_result) {
    auto a = php::toDecimal("10.00");
    auto b = php::toDecimal("50.00");
    auto r = Decimal::sub(a, b);
    auto tmp = Decimal::toString(r);
    auto str = tmp.toCString();
    ASSERT_EQ(str[0], '-');
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), -40.0, 0.01);
}

TEST(decimal, mul) {
    auto a = php::toDecimal("3.5");
    auto b = php::toDecimal("2.0");
    auto r = Decimal::mul(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 7.0, 0.01);
}

TEST(decimal, mul_int) {
    auto a = php::toDecimal("6.25");
    auto b = php::toDecimal((php::Int) 4);
    auto r = Decimal::mul(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 25.0, 0.01);
}

TEST(decimal, mul_zero) {
    auto a = php::toDecimal("123.456");
    auto b = php::toDecimal("0");
    auto r = Decimal::mul(a, b);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 0);
}

TEST(decimal, div) {
    auto a = php::toDecimal("100.0");
    auto b = php::toDecimal("4.0");
    auto r = Decimal::div(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 25.0, 0.01);
}

TEST(decimal, div_non_integer) {
    auto a = php::toDecimal("10.0");
    auto b = php::toDecimal("3.0");
    auto r = Decimal::div(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 3.333, 0.01);
}

TEST(decimal, mod) {
    auto a = php::toDecimal("100.0");
    auto b = php::toDecimal("3.0");
    auto r = Decimal::mod(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 1.0, 0.01);
}

TEST(decimal, mod_by_zero_throws_division_by_zero_error) {
    auto one = php::toDecimal((php::Int) 1);
    auto zero = php::toDecimal((php::Int) 0);
    bool caught = false;

    try {
        (void) Decimal::mod(one, zero);
    } catch (zend_object *ex) {
        caught = true;
        auto exception = catchException();
        ASSERT_TRUE(exception.instanceOf(zend_ce_division_by_zero_error));
    }
    ASSERT_TRUE(caught);
}

TEST(decimal, mod_exact) {
    auto a = php::toDecimal("100.0");
    auto b = php::toDecimal("20.0");
    auto r = Decimal::mod(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 0.0, 0.01);
}

TEST(decimal, neg) {
    auto a = php::toDecimal("100.50");
    auto r = Decimal::neg(a);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), -100.5, 0.01);
}

TEST(decimal, neg_negative) {
    auto a = php::toDecimal("-50.25");
    auto r = Decimal::neg(a);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 50.25, 0.01);
}

TEST(decimal, abs_positive) {
    auto a = php::toDecimal("123.456");
    auto r = Decimal::abs(a);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 123.456, 0.01);
}

TEST(decimal, abs_negative) {
    auto a = php::toDecimal("-123.456");
    auto r = Decimal::abs(a);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 123.456, 0.01);
}

TEST(decimal, abs_zero) {
    auto a = php::toDecimal("0");
    auto r = Decimal::abs(a);
    ASSERT_EQ(Decimal::toInt(r).toInt(), 0);
}

// ============ Comparison ============

TEST(decimal, cmp_greater) {
    auto a = php::toDecimal("200.50");
    auto b = php::toDecimal("100.25");
    auto r = Decimal::cmp(a, b);
    ASSERT_GT(r.toInt(), 0);
}

TEST(decimal, cmp_less) {
    auto a = php::toDecimal("100.00");
    auto b = php::toDecimal("200.00");
    auto r = Decimal::cmp(a, b);
    ASSERT_LT(r.toInt(), 0);
}

TEST(decimal, cmp_equal) {
    auto a = php::toDecimal("100.50");
    auto b = php::toDecimal("100.50");
    auto r = Decimal::cmp(a, b);
    ASSERT_EQ(r.toInt(), 0);
}

TEST(decimal, cmp_negative_vs_positive) {
    auto a = php::toDecimal("-10.0");
    auto b = php::toDecimal("10.0");
    auto r = Decimal::cmp(a, b);
    ASSERT_LT(r.toInt(), 0);
}

TEST(decimal, cmp_both_negative) {
    auto a = php::toDecimal("-10.0");
    auto b = php::toDecimal("-50.0");
    auto r = Decimal::cmp(a, b);
    ASSERT_GT(r.toInt(), 0);
}

// ============ Conversion ============

TEST(decimal, toString) {
    auto a = php::toDecimal("123.456");
    auto r = Decimal::toString(a);
    ASSERT_TRUE(r.isString());
    ASSERT_TRUE(std::strstr(r.toCString(), "123.456") != nullptr);
}

TEST(decimal, toString_integer) {
    auto a = php::toDecimal("42.00");
    auto r = Decimal::toString(a);
    ASSERT_TRUE(r.isString());
    ASSERT_GT(r.length(), 0u);
}

TEST(decimal, toInt) {
    auto a = php::toDecimal("3.14");
    auto r = Decimal::toInt(a);
    ASSERT_TRUE(r.isInt());
    ASSERT_EQ(r.toInt(), 3);
}

TEST(decimal, toInt_negative) {
    auto a = php::toDecimal("-3.14");
    auto r = Decimal::toInt(a);
    ASSERT_EQ(r.toInt(), -3);
}

TEST(decimal, toFloat) {
    auto a = php::toDecimal("3.14");
    auto r = Decimal::toFloat(a);
    ASSERT_NEAR(r.toFloat(), 3.14, 0.001);
}

// ============ Edge cases ============

TEST(decimal, high_precision_string) {
    auto a = php::toDecimal("123.45678901234567890");
    auto tmp = Decimal::toString(a);
    auto s = tmp.toCString();
    ASSERT_TRUE(std::strstr(s, "123.45678901234567890") != nullptr);
}

TEST(decimal, string_promotion) {
    auto a = php::toDecimal("100.50");
    Variant b("50.25");
    auto r = Decimal::add(a, b);
    auto *d = r.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(r).toFloat(), 150.75, 0.01);
}

TEST(decimal, chained_operations) {
    auto a = php::toDecimal("100.0");
    auto b = php::toDecimal("50.0");
    auto sum = Decimal::add(a, b);
    auto prod = Decimal::mul(sum, php::toDecimal("2.0"));
    auto diff = Decimal::sub(prod, php::toDecimal("20.0"));
    auto result = Decimal::div(diff, php::toDecimal("5.0"));
    auto *d = result.toBox<Decimal>();
    ASSERT_NE(d, nullptr);
    ASSERT_NEAR(Decimal::toFloat(result).toFloat(), 56.0, 0.01);
}

TEST(decimal, arithmetic_preserves_fifty_digits) {
    auto a = Decimal::newInstance(Variant("1234567890123456789012345678901234567890123456789"));
    auto result = Decimal::add(a, Variant(1));

    ASSERT_EQ(Decimal::toString(result).toString(), "1234567890123456789012345678901234567890123456790");
}

TEST(decimal, exceptions_do_not_escape_cpp_boundary) {
    auto one = Decimal::newInstance(Variant(1));
    auto zero = Decimal::newInstance(Variant(0));
    bool division_by_zero_caught = false;

    try {
        (void) Decimal::div(one, zero);
    } catch (zend_object *ex) {
        division_by_zero_caught = true;
        auto exception = catchException();
        ASSERT_TRUE(exception.instanceOf(zend_ce_division_by_zero_error));
    }
    ASSERT_TRUE(division_by_zero_caught);

    bool invalid_value_caught = false;
    try {
        (void) Decimal::newInstance(Variant("not-a-decimal"));
    } catch (zend_object *ex) {
        invalid_value_caught = true;
        auto exception = catchException();
        ASSERT_TRUE(exception.instanceOf(zend_ce_value_error));
    }
    ASSERT_TRUE(invalid_value_caught);
}

TEST(decimal, boolean_conversion_uses_numeric_value) {
    auto zero = Decimal::newInstance(Variant("0.00"));
    auto nonzero = Decimal::newInstance(Variant("-0.01"));
    ASSERT_FALSE(Decimal::toBool(zero).toBool());
    ASSERT_TRUE(Decimal::toBool(nonzero).toBool());
}

TEST(decimal, invalid_operands_report_type_errors) {
    Variant invalid = true;
    auto one = Decimal::newInstance(Variant(1));

    try_call([]() { Decimal::newInstance(1.5); }, "Cannot construct Decimal from float");
    try_call([&]() { Decimal::add(invalid, one); }, "expects valid Decimal argument");
    try_call([&]() { Decimal::sub(invalid, one); }, "expects valid Decimal argument");
    try_call([&]() { Decimal::mul(invalid, one); }, "expects valid Decimal argument");
    try_call([&]() { Decimal::div(invalid, one); }, "expects valid Decimal argument");
    try_call([&]() { Decimal::mod(invalid, one); }, "expects valid Decimal argument");
    try_call([&]() { Decimal::neg(invalid); }, "expects valid Decimal argument");
    try_call([&]() { Decimal::cmp(invalid, one); }, "expects valid Decimal argument");
    try_call([&]() { Decimal::abs(invalid); }, "expects valid Decimal argument");
    try_call([&]() { Decimal::pow(invalid, one); }, "expects valid Decimal argument");
    try_call([&]() { Decimal::divmod(invalid, one); }, "expects valid Decimal argument");
    try_call([&]() { Decimal::powmod(invalid, one, one); }, "expects valid Decimal argument");
    try_call([&]() { Decimal::sqrt(invalid); }, "expects valid Decimal argument");
    try_call([&]() { Decimal::floor(invalid); }, "expects valid Decimal argument");
    try_call([&]() { Decimal::ceil(invalid); }, "expects valid Decimal argument");
    try_call([&]() { Decimal::round(invalid); }, "expects valid Decimal argument");
    try_call([&]() { Decimal::toString(invalid); }, "not a resource type");
    try_call([&]() { Decimal::toInt(invalid); }, "not a resource type");
    try_call([&]() { Decimal::toFloat(invalid); }, "not a resource type");
    try_call([&]() { Decimal::toBool(invalid); }, "not a resource type");

    try_call([]() { Decimal::sqrt(Decimal::newInstance(Variant(-1))); }, "invalid operation");
}
