#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_big_float.h"

#include <cstring>

using namespace php;

// ============ Construction ============

TEST(bigfloat, construct_from_int) {
    auto a = php::toBigFloat((php::Int) 42);
    auto *bf = a.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_EQ(BigFloat::toInt(a).toInt(), 42);
}

TEST(bigfloat, construct_from_float) {
    auto a = php::toBigFloat(3.14);
    auto *bf = a.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(a).toFloat(), 3.14, 0.001);
}

TEST(bigfloat, construct_from_string) {
    auto a = php::toBigFloat(String("123.456"));
    auto *bf = a.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    auto str = BigFloat::toString(a);
    auto s = str.toCString();
    ASSERT_TRUE(std::strstr(s, "123.456") != nullptr);
}

TEST(bigfloat, construct_negative) {
    auto a = php::toBigFloat(-100.5);
    auto *bf = a.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    auto str = BigFloat::toString(a);
    auto s = str.toCString();
    ASSERT_EQ(s[0], '-');
}

TEST(bigfloat, construct_zero) {
    auto a = php::toBigFloat((php::Int) 0);
    auto *bf = a.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_EQ(BigFloat::toInt(a).toInt(), 0);
}

TEST(bigfloat, newInstance_from_string) {
    Variant s("3.14159265358979323846");
    auto v = BigFloat::newInstance(s);
    auto *bf = v.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    auto tmp = BigFloat::toString(v);
    auto str = tmp.toCString();
    ASSERT_TRUE(std::strstr(str, "3.14") != nullptr);
}

TEST(bigfloat, newInstance_from_int) {
    Variant s((php::Int) 42);
    auto v = BigFloat::newInstance(s);
    auto *bf = v.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_EQ(BigFloat::toInt(v).toInt(), 42);
}

// ============ Arithmetic ============

TEST(bigfloat, add) {
    auto a = php::toBigFloat(100.5);
    auto b = php::toBigFloat(200.25);
    auto r = BigFloat::add(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 300.75, 0.01);
}

TEST(bigfloat, add_int_promotion) {
    auto a = php::toBigFloat(100.5);
    Variant b(200);
    auto r = BigFloat::add(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 300.5, 0.01);
}

TEST(bigfloat, add_float_promotion) {
    auto a = php::toBigFloat(100.0);
    Variant b(0.5);
    auto r = BigFloat::add(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 100.5, 0.01);
}

TEST(bigfloat, add_string_promotion) {
    auto a = php::toBigFloat(100.0);
    Variant b("0.5");
    auto r = BigFloat::add(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 100.5, 0.01);
}

TEST(bigfloat, sub) {
    auto a = php::toBigFloat(100.5);
    auto b = php::toBigFloat(30.25);
    auto r = BigFloat::sub(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 70.25, 0.01);
}

TEST(bigfloat, sub_negative_result) {
    auto a = php::toBigFloat(10.0);
    auto b = php::toBigFloat(50.0);
    auto r = BigFloat::sub(a, b);
    auto tmp = BigFloat::toString(r);
    auto str = tmp.toCString();
    ASSERT_EQ(str[0], '-');
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), -40.0, 0.01);
}

TEST(bigfloat, mul) {
    auto a = php::toBigFloat(3.5);
    auto b = php::toBigFloat(2.0);
    auto r = BigFloat::mul(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 7.0, 0.01);
}

TEST(bigfloat, mul_zero) {
    auto a = php::toBigFloat(123.456);
    auto b = php::toBigFloat((php::Int) 0);
    auto r = BigFloat::mul(a, b);
    ASSERT_EQ(BigFloat::toInt(r).toInt(), 0);
}

TEST(bigfloat, div) {
    auto a = php::toBigFloat(100.0);
    auto b = php::toBigFloat(4.0);
    auto r = BigFloat::div(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 25.0, 0.01);
}

TEST(bigfloat, div_non_integer) {
    auto a = php::toBigFloat(10.0);
    auto b = php::toBigFloat(3.0);
    auto r = BigFloat::div(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 3.333, 0.01);
}

TEST(bigfloat, neg) {
    auto a = php::toBigFloat(100.5);
    auto r = BigFloat::neg(a);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), -100.5, 0.01);
}

TEST(bigfloat, neg_negative) {
    auto a = php::toBigFloat(-50.25);
    auto r = BigFloat::neg(a);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 50.25, 0.01);
}

TEST(bigfloat, abs_positive) {
    auto a = php::toBigFloat(123.456);
    auto r = BigFloat::abs(a);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 123.456, 0.01);
}

TEST(bigfloat, abs_negative) {
    auto a = php::toBigFloat(-123.456);
    auto r = BigFloat::abs(a);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 123.456, 0.01);
}

TEST(bigfloat, abs_zero) {
    auto a = php::toBigFloat((php::Int) 0);
    auto r = BigFloat::abs(a);
    ASSERT_EQ(BigFloat::toInt(r).toInt(), 0);
}

// ============ Sqrt ============

TEST(bigfloat, sqrt_perfect_square) {
    auto a = php::toBigFloat(4.0);
    auto r = BigFloat::sqrt(a);
    ASSERT_EQ(BigFloat::toString(r).toString(), "2");
}

TEST(bigfloat, sqrt_fractional) {
    auto a = php::toBigFloat(2.25);
    auto r = BigFloat::sqrt(a);
    ASSERT_EQ(BigFloat::toString(r).toString(), "1.5");
}

TEST(bigfloat, sqrt_zero) {
    auto a = php::toBigFloat((php::Int) 0);
    auto r = BigFloat::sqrt(a);
    ASSERT_EQ(BigFloat::toString(r).toString(), "0");
}

// ============ Comparison ============

TEST(bigfloat, cmp_greater) {
    auto a = php::toBigFloat(200.5);
    auto b = php::toBigFloat(100.25);
    auto r = BigFloat::cmp(a, b);
    ASSERT_GT(r.toInt(), 0);
}

TEST(bigfloat, cmp_less) {
    auto a = php::toBigFloat(100.0);
    auto b = php::toBigFloat(200.0);
    auto r = BigFloat::cmp(a, b);
    ASSERT_LT(r.toInt(), 0);
}

TEST(bigfloat, cmp_equal) {
    auto a = php::toBigFloat(100.5);
    auto b = php::toBigFloat(100.5);
    auto r = BigFloat::cmp(a, b);
    ASSERT_EQ(r.toInt(), 0);
}

TEST(bigfloat, cmp_negative) {
    auto a = php::toBigFloat(-10.0);
    auto b = php::toBigFloat(10.0);
    auto r = BigFloat::cmp(a, b);
    ASSERT_LT(r.toInt(), 0);
}

TEST(bigfloat, cmp_both_negative) {
    auto a = php::toBigFloat(-10.0);
    auto b = php::toBigFloat(-50.0);
    auto r = BigFloat::cmp(a, b);
    ASSERT_GT(r.toInt(), 0);
}

// ============ Conversion ============

TEST(bigfloat, toString) {
    auto a = php::toBigFloat(123.456);
    auto r = BigFloat::toString(a);
    ASSERT_TRUE(r.isString());
    ASSERT_TRUE(std::strstr(r.toCString(), "123.456") != nullptr);
}

TEST(bigfloat, toString_integer) {
    auto a = php::toBigFloat((php::Int) 42);
    auto r = BigFloat::toString(a);
    ASSERT_TRUE(r.isString());
    ASSERT_TRUE(std::strstr(r.toCString(), "42") != nullptr);
}

TEST(bigfloat, toInt) {
    auto a = php::toBigFloat(3.14);
    auto r = BigFloat::toInt(a);
    ASSERT_TRUE(r.isInt());
    ASSERT_EQ(r.toInt(), 3);
}

TEST(bigfloat, toFloat) {
    auto a = php::toBigFloat(3.14);
    auto r = BigFloat::toFloat(a);
    ASSERT_NEAR(r.toFloat(), 3.14, 0.001);
}

// ============ Edge cases ============

TEST(bigfloat, large_values) {
    auto a = BigFloat::newInstance(Variant("1e30"));
    auto b = BigFloat::newInstance(Variant("1e20"));
    auto r = BigFloat::div(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 1e10, 1e8);
}

TEST(bigfloat, very_small_values) {
    auto a = BigFloat::newInstance(Variant("0.000000001"));
    auto b = BigFloat::newInstance(Variant("1000.0"));
    auto r = BigFloat::mul(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 0.000001, 0.0000001);
}

TEST(bigfloat, chained_operations) {
    auto a = php::toBigFloat(100.0);
    auto b = php::toBigFloat(50.0);
    auto sum = BigFloat::add(a, b);
    auto prod = BigFloat::mul(sum, php::toBigFloat(2.0));
    auto diff = BigFloat::sub(prod, php::toBigFloat(20.0));
    auto result = BigFloat::div(diff, php::toBigFloat(5.0));
    auto *bf = result.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(result).toFloat(), 56.0, 0.01);
}

TEST(bigfloat, preserves_precision_beyond_double) {
    auto large = BigFloat::newInstance(Variant("1000000000000000000000000000000"));
    auto one = BigFloat::newInstance(Variant("1"));
    auto sum = BigFloat::add(large, one);
    auto result = BigFloat::sub(sum, large);

    ASSERT_EQ(BigFloat::toString(result).toString(), "1");
    ASSERT_GE(mpfr_get_prec(result.toBox<BigFloat>()->value), 256);
}

TEST(bigfloat, invalid_numeric_string_throws_value_error) {
    bool exception_caught = false;
    try {
        (void) BigFloat::newInstance(Variant("not-a-number"));
    } catch (zend_object *ex) {
        exception_caught = true;
        auto exception = catchException();
        ASSERT_TRUE(exception.instanceOf(zend_ce_value_error));
    }
    ASSERT_TRUE(exception_caught);
}

TEST(bigfloat, conversions_and_division_check_boundaries) {
    auto zero = BigFloat::newInstance(Variant("0"));
    auto one = BigFloat::newInstance(Variant("1"));
    ASSERT_FALSE(BigFloat::toBool(zero).toBool());
    ASSERT_TRUE(BigFloat::toBool(one).toBool());

    bool division_exception = false;
    try {
        (void) BigFloat::div(one, zero);
    } catch (zend_object *ex) {
        division_exception = true;
        auto exception = catchException();
        ASSERT_TRUE(exception.instanceOf(zend_ce_division_by_zero_error));
    }
    ASSERT_TRUE(division_exception);

    auto tooLarge = BigFloat::newInstance(Variant("1e100"));
    bool range_exception = false;
    try {
        (void) BigFloat::toInt(tooLarge);
    } catch (zend_object *ex) {
        range_exception = true;
        auto exception = catchException();
        ASSERT_TRUE(exception.instanceOf(zend_ce_arithmetic_error));
    }
    ASSERT_TRUE(range_exception);
}

TEST(bigfloat, huge_exponent_uses_bounded_scientific_notation) {
    auto huge = BigFloat::newInstance(Variant("1e1000001"));
    auto output = BigFloat::toString(huge).toString();
    ASSERT_LT(output.length(), 100u);
    ASSERT_NE(std::strstr(output.data(), "E1000001"), nullptr);
}

TEST(bigfloat, invalid_operands_report_type_errors) {
    Variant invalid = Array{};
    auto one = BigFloat::newInstance(Variant(1));

    try_call([&]() { BigFloat::newInstance(invalid); }, "expects valid BigFloat argument");
    try_call([&]() { BigFloat::add(invalid, one); }, "expects valid BigFloat argument");
    try_call([&]() { BigFloat::sub(invalid, one); }, "expects valid BigFloat argument");
    try_call([&]() { BigFloat::mul(invalid, one); }, "expects valid BigFloat argument");
    try_call([&]() { BigFloat::div(invalid, one); }, "expects valid BigFloat argument");
    try_call([&]() { BigFloat::neg(invalid); }, "expects valid BigFloat argument");
    try_call([&]() { BigFloat::cmp(invalid, one); }, "expects valid BigFloat argument");
    try_call([&]() { BigFloat::abs(invalid); }, "expects valid BigFloat argument");
    try_call([&]() { BigFloat::sqrt(invalid); }, "expects valid BigFloat argument");
    try_call([&]() { BigFloat::toString(invalid); }, "expects BigFloat argument");
    try_call([&]() { BigFloat::toInt(invalid); }, "expects BigFloat argument");
    try_call([&]() { BigFloat::toFloat(invalid); }, "expects BigFloat argument");
    try_call([&]() { BigFloat::toBool(invalid); }, "expects BigFloat argument");

    try_call([]() { BigFloat::sqrt(BigFloat::newInstance(Variant(-1))); }, "square root of negative number");
}
