#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_big_int.h"
#include "bigint_test_data.h"

#include <cstring>

using namespace php;

// Helper: create a BigInt from a string literal without ambiguity
static inline Variant bi(const char *s) {
    return BigInt::newInstance(Variant(s));
}

static inline Variant bi(php::Int v) {
    return php::toBigInt(v);
}

// ============ Construction ============

TEST(bigint, construct_from_string) {
    auto a = bi("12345678901234567890");
    auto *bi_ptr = a.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_STREQ(bi_ptr->data->value.get_str().c_str(), "12345678901234567890");
}

TEST(bigint, construct_from_int) {
    auto a = php::toBigInt((php::Int) 42);
    auto *bi_ptr = a.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value.get_si(), 42);
}

TEST(bigint, construct_negative) {
    auto a = bi("-9999999999999999999");
    auto *bi_ptr = a.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_STREQ(bi_ptr->data->value.get_str().c_str(), "-9999999999999999999");
}

TEST(bigint, construct_zero) {
    auto a = bi("0");
    auto *bi_ptr = a.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 0);
}

TEST(bigint, newInstance_from_string) {
    Variant s("999888777666555444333222111000");
    auto v = BigInt::newInstance(s);
    auto *bi_ptr = v.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_STREQ(bi_ptr->data->value.get_str().c_str(), "999888777666555444333222111000");
}

TEST(bigint, newInstance_from_int) {
    Variant s((php::Int) 12345);
    auto v = BigInt::newInstance(s);
    auto *bi_ptr = v.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 12345);
}

// ============ Arithmetic ============

TEST(bigint, add) {
    auto a = bi(100);
    auto b = bi(200);
    auto r = BigInt::add(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 300);
}

TEST(bigint, add_int_promotion) {
    auto a = bi(100);
    Variant b((php::Int) 200);
    auto r = BigInt::add(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 300);
}

TEST(bigint, add_large_numbers) {
    auto a = bi("999999999999999999999999999999");
    auto b = bi("1");
    auto r = BigInt::add(a, b);
    auto str = BigInt::toString(r);
    ASSERT_STREQ(str.toCString(), "1000000000000000000000000000000");
}

TEST(bigint, add_negative) {
    auto a = bi(100);
    auto b = bi(-30);
    auto r = BigInt::add(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 70);
}

TEST(bigint, sub) {
    auto a = bi(100);
    auto b = bi(30);
    auto r = BigInt::sub(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 70);
}

TEST(bigint, sub_negative_result) {
    auto a = bi(30);
    auto b = bi(100);
    auto r = BigInt::sub(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, -70);
}

TEST(bigint, mul) {
    auto a = bi(100);
    auto b = bi(5);
    auto r = BigInt::mul(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 500);
}

TEST(bigint, mul_large) {
    auto a = bi("12345678901234567890");
    auto b = bi("98765432109876543210");
    auto r = BigInt::mul(a, b);
    auto tmp = BigInt::toString(r);
    ASSERT_STREQ(tmp.toCString(), "1219326311370217952237463801111263526900");
}

TEST(bigint, mul_zero) {
    auto a = bi(99999);
    auto b = bi((php::Int) 0);
    auto r = BigInt::mul(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 0);
}

TEST(bigint, div) {
    auto a = bi(100);
    auto b = bi(3);
    auto r = BigInt::div(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 33);
}

TEST(bigint, div_exact) {
    auto a = bi(100);
    auto b = bi(5);
    auto r = BigInt::div(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 20);
}

TEST(bigint, div_negative) {
    auto a = bi(-100);
    auto b = bi(3);
    auto r = BigInt::div(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, -33);
}

TEST(bigint, div_by_zero) {
    try_call([]() { BigInt::div(bi(100), bi((php::Int) 0)); }, "Division by zero");
}

TEST(bigint, mod) {
    auto a = bi(100);
    auto b = bi(7);
    auto r = BigInt::mod(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 2);
}

TEST(bigint, mod_exact) {
    auto a = bi(100);
    auto b = bi(20);
    auto r = BigInt::mod(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 0);
}

TEST(bigint, mod_by_zero) {
    try_call([]() { BigInt::mod(bi(100), bi((php::Int) 0)); }, "Division by zero");
}

TEST(bigint, neg) {
    auto a = bi(100);
    auto r = BigInt::neg(a);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, -100);
}

TEST(bigint, neg_negative) {
    auto a = bi(-50);
    auto r = BigInt::neg(a);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 50);
}

TEST(bigint, neg_zero) {
    auto a = bi((php::Int) 0);
    auto r = BigInt::neg(a);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 0);
}

TEST(bigint, pow_small) {
    auto a = bi(2);
    auto b = bi(10);
    auto r = BigInt::pow(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 1024);
}

TEST(bigint, pow_zero) {
    auto a = bi(999);
    auto b = bi((php::Int) 0);
    auto r = BigInt::pow(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 1);
}

TEST(bigint, pow_one) {
    auto a = bi(12345);
    auto b = bi(1);
    auto r = BigInt::pow(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 12345);
}

TEST(bigint, pow_negative_exponent) {
    try_call([]() { BigInt::pow(bi(2), bi(-1)); }, "Negative exponent not supported");
}

TEST(bigint, pow_large) {
    auto a = bi(2);
    auto b = bi(100);
    auto r = BigInt::pow(a, b);
    auto tmp = BigInt::toString(r);
    ASSERT_STREQ(tmp.toCString(), "1267650600228229401496703205376");
}

TEST(bigint, abs_positive) {
    auto a = bi(100);
    auto r = BigInt::abs(a);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 100);
}

TEST(bigint, abs_negative) {
    auto a = bi(-100);
    auto r = BigInt::abs(a);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 100);
}

TEST(bigint, abs_zero) {
    auto a = bi((php::Int) 0);
    auto r = BigInt::abs(a);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 0);
}

// ============ divmod ============

TEST(bigint, divmod_basic) {
    auto a = bi(10);
    auto b = bi(3);
    auto r = BigInt::divmod(a, b);
    ASSERT_TRUE(r.isArray());
    auto arr = r.toArray();
    ASSERT_EQ(BigInt::toInt(arr[0]).toInt(), 3);
    ASSERT_EQ(BigInt::toInt(arr[1]).toInt(), 1);
}

TEST(bigint, divmod_exact) {
    auto a = bi(100);
    auto b = bi(25);
    auto r = BigInt::divmod(a, b);
    auto arr = r.toArray();
    ASSERT_EQ(BigInt::toInt(arr[0]).toInt(), 4);
    ASSERT_EQ(BigInt::toInt(arr[1]).toInt(), 0);
}

TEST(bigint, divmod_negative_dividend) {
    auto a = bi(-10);
    auto b = bi(3);
    auto r = BigInt::divmod(a, b);
    auto arr = r.toArray();
    ASSERT_EQ(BigInt::toInt(arr[0]).toInt(), -3);
    ASSERT_EQ(BigInt::toInt(arr[1]).toInt(), -1);
}

TEST(bigint, divmod_negative_divisor) {
    auto a = bi(10);
    auto b = bi(-3);
    auto r = BigInt::divmod(a, b);
    auto arr = r.toArray();
    ASSERT_EQ(BigInt::toInt(arr[0]).toInt(), -3);
    ASSERT_EQ(BigInt::toInt(arr[1]).toInt(), 1);
}

TEST(bigint, divmod_large) {
    auto a = bi("99999999999999999999");
    auto b = bi("77777777777777777777");
    auto r = BigInt::divmod(a, b);
    auto arr = r.toArray();
    ASSERT_EQ(BigInt::toInt(arr[0]).toInt(), 1);
    auto rem = BigInt::toString(arr[1]);
    ASSERT_STREQ(rem.toCString(), "22222222222222222222");
}

TEST(bigint, divmod_by_zero) {
    try_call([]() { BigInt::divmod(bi(100), bi((php::Int) 0)); }, "Division by zero");
}

// ============ powmod ============

TEST(bigint, powmod_basic) {
    auto r = BigInt::powmod(bi(2), bi(10), bi(1000));
    ASSERT_EQ(BigInt::toInt(r).toInt(), 24);
}

TEST(bigint, powmod_identity) {
    auto r = BigInt::powmod(bi(7), bi(1), bi(100));
    ASSERT_EQ(BigInt::toInt(r).toInt(), 7);
}

TEST(bigint, powmod_large) {
    auto r = BigInt::powmod(bi(3), bi(20), bi(100000));
    ASSERT_EQ(BigInt::toInt(r).toInt(), 84401);
}

TEST(bigint, powmod_zero_exponent) {
    auto r = BigInt::powmod(bi(999), bi((php::Int) 0), bi(100));
    ASSERT_EQ(BigInt::toInt(r).toInt(), 1);
}

TEST(bigint, powmod_mod_one) {
    auto r = BigInt::powmod(bi(12345), bi(100), bi(1));
    ASSERT_EQ(BigInt::toInt(r).toInt(), 0);
}

TEST(bigint, powmod_mod_by_zero) {
    try_call([]() { BigInt::powmod(bi(2), bi(10), bi((php::Int) 0)); }, "Modulo by zero in powmod");
}

TEST(bigint, powmod_negative_exponent) {
    try_call([]() { BigInt::powmod(bi(2), bi(-1), bi(100)); }, "Negative exponent not supported in powmod");
}

// ============ sqrt ============

TEST(bigint, sqrt_perfect_square) {
    auto r = BigInt::sqrt(bi(144));
    ASSERT_EQ(BigInt::toInt(r).toInt(), 12);
}

TEST(bigint, sqrt_non_perfect) {
    auto r = BigInt::sqrt(bi(2));
    ASSERT_EQ(BigInt::toInt(r).toInt(), 1);
}

TEST(bigint, sqrt_zero) {
    auto r = BigInt::sqrt(bi((php::Int) 0));
    ASSERT_EQ(BigInt::toInt(r).toInt(), 0);
}

TEST(bigint, sqrt_one) {
    auto r = BigInt::sqrt(bi(1));
    ASSERT_EQ(BigInt::toInt(r).toInt(), 1);
}

TEST(bigint, sqrt_large) {
    auto a = bi("1000000000000000000000000000000");
    auto r = BigInt::sqrt(a);
    auto s = BigInt::toString(r);
    ASSERT_STREQ(s.toCString(), "1000000000000000");
}

TEST(bigint, sqrt_large_non_perfect) {
    auto a = bi("1000000000000000000000000000002");
    auto r = BigInt::sqrt(a);
    auto s = BigInt::toString(r);
    ASSERT_STREQ(s.toCString(), "1000000000000000");
}

TEST(bigint, sqrt_negative) {
    try_call([]() { BigInt::sqrt(bi(-1)); }, "Cannot compute square root of negative BigInt");
}

TEST(bigint, gcd) {
    auto a = bi(48);
    auto b = bi(18);
    auto r = BigInt::gcd(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 6);
}

TEST(bigint, gcd_coprime) {
    auto a = bi(17);
    auto b = bi(13);
    auto r = BigInt::gcd(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 1);
}

TEST(bigint, gcd_one_zero) {
    auto a = bi((php::Int) 0);
    auto b = bi(42);
    auto r = BigInt::gcd(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 42);
}

// ============ Comparison ============

TEST(bigint, cmp_greater) {
    auto a = bi(200);
    auto b = bi(100);
    auto r = BigInt::cmp(a, b);
    ASSERT_GT(r.toInt(), 0);
}

TEST(bigint, cmp_less) {
    auto a = bi(100);
    auto b = bi(200);
    auto r = BigInt::cmp(a, b);
    ASSERT_LT(r.toInt(), 0);
}

TEST(bigint, cmp_equal) {
    auto a = bi(100);
    auto b = bi(100);
    auto r = BigInt::cmp(a, b);
    ASSERT_EQ(r.toInt(), 0);
}

TEST(bigint, cmp_negative) {
    auto a = bi(-100);
    auto b = bi(100);
    auto r = BigInt::cmp(a, b);
    ASSERT_LT(r.toInt(), 0);
}

TEST(bigint, cmp_both_negative) {
    auto a = bi(-50);
    auto b = bi(-100);
    auto r = BigInt::cmp(a, b);
    ASSERT_GT(r.toInt(), 0);
}

// ============ Conversion ============

TEST(bigint, toString) {
    auto a = bi("12345678901234567890");
    auto r = BigInt::toString(a);
    ASSERT_TRUE(r.isString());
    ASSERT_STREQ(r.toCString(), "12345678901234567890");
}

TEST(bigint, toString_negative) {
    auto a = bi("-1");
    auto r = BigInt::toString(a);
    ASSERT_STREQ(r.toCString(), "-1");
}

TEST(bigint, toInt_small) {
    auto a = bi(42);
    auto r = BigInt::toInt(a);
    ASSERT_TRUE(r.isInt());
    ASSERT_EQ(r.toInt(), 42);
}

TEST(bigint, toFloat) {
    auto a = bi(314);
    auto r = BigInt::toFloat(a);
    ASSERT_NEAR(r.toFloat(), 314.0, 0.001);
}

// ============ Large number stress tests ============

TEST(bigint, very_large_number) {
    auto a = bi("12345678901234567890123456789012345678901234567890"
                "12345678901234567890123456789012345678901234567890");
    auto r = BigInt::toString(a);
    ASSERT_EQ(r.length(), 100);
}

TEST(bigint, chained_operations) {
    auto a = bi(100);
    auto b = bi(200);
    auto sum = BigInt::add(a, b);
    auto prod = BigInt::mul(sum, bi(3));
    auto diff = BigInt::sub(prod, bi(50));
    auto result = BigInt::div(diff, bi(17));
    auto *bi_ptr = result.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 50);
}
