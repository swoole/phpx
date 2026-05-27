#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_big_float.h"

using namespace php;

// ============ Construction ============

TEST(bigfloat, construct_from_int) {
    auto a = php::newBigFloat((php::Int) 42);
    auto *bf = a.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_EQ(BigFloat::toInt(a).toInt(), 42);
}

TEST(bigfloat, construct_from_float) {
    auto a = php::newBigFloat(3.14);
    auto *bf = a.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(a).toFloat(), 3.14, 0.001);
}

TEST(bigfloat, construct_from_string) {
    auto a = php::newBigFloat(String("123.456"));
    auto *bf = a.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    auto str = BigFloat::toString(a);
    auto s = str.toCString();
    ASSERT_TRUE(std::strstr(s, "123.456") != nullptr);
}

TEST(bigfloat, construct_negative) {
    auto a = php::newBigFloat(-100.5);
    auto *bf = a.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    auto str = BigFloat::toString(a);
    auto s = str.toCString();
    ASSERT_EQ(s[0], '-');
}

TEST(bigfloat, construct_zero) {
    auto a = php::newBigFloat((php::Int) 0);
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
    auto a = php::newBigFloat(100.5);
    auto b = php::newBigFloat(200.25);
    auto r = BigFloat::add(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 300.75, 0.01);
}

TEST(bigfloat, add_int_promotion) {
    auto a = php::newBigFloat(100.5);
    Variant b(200);
    auto r = BigFloat::add(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 300.5, 0.01);
}

TEST(bigfloat, add_float_promotion) {
    auto a = php::newBigFloat(100.0);
    Variant b(0.5);
    auto r = BigFloat::add(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 100.5, 0.01);
}

TEST(bigfloat, add_string_promotion) {
    auto a = php::newBigFloat(100.0);
    Variant b("0.5");
    auto r = BigFloat::add(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 100.5, 0.01);
}

TEST(bigfloat, sub) {
    auto a = php::newBigFloat(100.5);
    auto b = php::newBigFloat(30.25);
    auto r = BigFloat::sub(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 70.25, 0.01);
}

TEST(bigfloat, sub_negative_result) {
    auto a = php::newBigFloat(10.0);
    auto b = php::newBigFloat(50.0);
    auto r = BigFloat::sub(a, b);
    auto tmp = BigFloat::toString(r);
    auto str = tmp.toCString();
    ASSERT_EQ(str[0], '-');
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), -40.0, 0.01);
}

TEST(bigfloat, mul) {
    auto a = php::newBigFloat(3.5);
    auto b = php::newBigFloat(2.0);
    auto r = BigFloat::mul(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 7.0, 0.01);
}

TEST(bigfloat, mul_zero) {
    auto a = php::newBigFloat(123.456);
    auto b = php::newBigFloat((php::Int) 0);
    auto r = BigFloat::mul(a, b);
    ASSERT_EQ(BigFloat::toInt(r).toInt(), 0);
}

TEST(bigfloat, div) {
    auto a = php::newBigFloat(100.0);
    auto b = php::newBigFloat(4.0);
    auto r = BigFloat::div(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 25.0, 0.01);
}

TEST(bigfloat, div_non_integer) {
    auto a = php::newBigFloat(10.0);
    auto b = php::newBigFloat(3.0);
    auto r = BigFloat::div(a, b);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 3.333, 0.01);
}

TEST(bigfloat, neg) {
    auto a = php::newBigFloat(100.5);
    auto r = BigFloat::neg(a);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), -100.5, 0.01);
}

TEST(bigfloat, neg_negative) {
    auto a = php::newBigFloat(-50.25);
    auto r = BigFloat::neg(a);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 50.25, 0.01);
}

TEST(bigfloat, abs_positive) {
    auto a = php::newBigFloat(123.456);
    auto r = BigFloat::abs(a);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 123.456, 0.01);
}

TEST(bigfloat, abs_negative) {
    auto a = php::newBigFloat(-123.456);
    auto r = BigFloat::abs(a);
    auto *bf = r.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(r).toFloat(), 123.456, 0.01);
}

TEST(bigfloat, abs_zero) {
    auto a = php::newBigFloat((php::Int) 0);
    auto r = BigFloat::abs(a);
    ASSERT_EQ(BigFloat::toInt(r).toInt(), 0);
}

// ============ Comparison ============

TEST(bigfloat, cmp_greater) {
    auto a = php::newBigFloat(200.5);
    auto b = php::newBigFloat(100.25);
    auto r = BigFloat::cmp(a, b);
    ASSERT_GT(r.toInt(), 0);
}

TEST(bigfloat, cmp_less) {
    auto a = php::newBigFloat(100.0);
    auto b = php::newBigFloat(200.0);
    auto r = BigFloat::cmp(a, b);
    ASSERT_LT(r.toInt(), 0);
}

TEST(bigfloat, cmp_equal) {
    auto a = php::newBigFloat(100.5);
    auto b = php::newBigFloat(100.5);
    auto r = BigFloat::cmp(a, b);
    ASSERT_EQ(r.toInt(), 0);
}

TEST(bigfloat, cmp_negative) {
    auto a = php::newBigFloat(-10.0);
    auto b = php::newBigFloat(10.0);
    auto r = BigFloat::cmp(a, b);
    ASSERT_LT(r.toInt(), 0);
}

TEST(bigfloat, cmp_both_negative) {
    auto a = php::newBigFloat(-10.0);
    auto b = php::newBigFloat(-50.0);
    auto r = BigFloat::cmp(a, b);
    ASSERT_GT(r.toInt(), 0);
}

// ============ Conversion ============

TEST(bigfloat, toString) {
    auto a = php::newBigFloat(123.456);
    auto r = BigFloat::toString(a);
    ASSERT_TRUE(r.isString());
    ASSERT_TRUE(std::strstr(r.toCString(), "123.456") != nullptr);
}

TEST(bigfloat, toString_integer) {
    auto a = php::newBigFloat((php::Int) 42);
    auto r = BigFloat::toString(a);
    ASSERT_TRUE(r.isString());
    ASSERT_TRUE(std::strstr(r.toCString(), "42") != nullptr);
}

TEST(bigfloat, toInt) {
    auto a = php::newBigFloat(3.14);
    auto r = BigFloat::toInt(a);
    ASSERT_TRUE(r.isInt());
    ASSERT_EQ(r.toInt(), 3);
}

TEST(bigfloat, toFloat) {
    auto a = php::newBigFloat(3.14);
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
    auto a = php::newBigFloat(100.0);
    auto b = php::newBigFloat(50.0);
    auto sum = BigFloat::add(a, b);
    auto prod = BigFloat::mul(sum, php::newBigFloat(2.0));
    auto diff = BigFloat::sub(prod, php::newBigFloat(20.0));
    auto result = BigFloat::div(diff, php::newBigFloat(5.0));
    auto *bf = result.toBox<BigFloat>();
    ASSERT_NE(bf, nullptr);
    ASSERT_NEAR(BigFloat::toFloat(result).toFloat(), 56.0, 0.01);
}
