#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_big_int.h"
#include "bigint_test_data.h"

#include <cstring>

using namespace php;

static inline Variant bi(const char *s) {
    return BigInt::newInstance(Variant(s));
}

static inline Variant bi(php::Int v) {
    return php::toBigInt(v);
}

// ============ bitAnd ============

TEST(bigint_bit, and_basic) {
    auto a = bi(0b1010);  // 10
    auto b = bi(0b1100);  // 12
    auto r = BigInt::bitAnd(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 8);  // 0b1000
}

TEST(bigint_bit, and_large) {
    auto a = bi("0xFFFFFFFF00000000");
    auto b = bi("0xFFFF0000FFFF0000");
    auto expected = bi("0xFFFF000000000000");
    auto r = BigInt::bitAnd(a, b);
    ASSERT_EQ(BigInt::cmp(r, expected).toInt(), 0);
}

TEST(bigint_bit, and_zero) {
    auto a = bi(12345);
    auto b = bi(php::Int(0));
    auto r = BigInt::bitAnd(a, b);
    ASSERT_EQ(BigInt::toInt(r).toInt(), 0);
}

TEST(bigint_bit, and_with_self) {
    auto a = bi("12345678901234567890");
    auto r = BigInt::bitAnd(a, a);
    ASSERT_EQ(BigInt::cmp(r, a).toInt(), 0);
}

// ============ bitOr ============

TEST(bigint_bit, or_basic) {
    auto a = bi(0b1010);  // 10
    auto b = bi(0b0101);  // 5
    auto r = BigInt::bitOr(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 15);  // 0b1111
}

TEST(bigint_bit, or_large) {
    auto a = bi("0xFFFF000000000000");
    auto b = bi("0x0000FFFF00000000");
    auto expected = bi("0xFFFFFFFF00000000");
    auto r = BigInt::bitOr(a, b);
    ASSERT_EQ(BigInt::cmp(r, expected).toInt(), 0);
}

TEST(bigint_bit, or_with_zero) {
    auto a = bi(777);
    auto b = bi(php::Int(0));
    auto r = BigInt::bitOr(a, b);
    ASSERT_EQ(BigInt::cmp(r, bi(777)).toInt(), 0);
}

// ============ bitXor ============

TEST(bigint_bit, xor_basic) {
    auto a = bi(0b1111);  // 15
    auto b = bi(0b1010);  // 10
    auto r = BigInt::bitXor(a, b);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 5);  // 0b0101
}

TEST(bigint_bit, xor_self_is_zero) {
    auto a = bi("9999999999999999999");
    auto r = BigInt::bitXor(a, a);
    ASSERT_EQ(BigInt::toInt(r).toInt(), 0);
}

TEST(bigint_bit, xor_inverse) {
    auto a = bi(255);
    auto b = bi(255);
    auto all_ones = BigInt::bitXor(a, b);
    ASSERT_EQ(BigInt::toInt(all_ones).toInt(), 0);
}

// ============ bitNot ============

TEST(bigint_bit, not_basic) {
    auto a = bi(php::Int(0));
    auto r = BigInt::bitNot(a);
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, -1);
}

TEST(bigint_bit, not_double_not) {
    auto a = bi("12345678901234567890");
    auto not_once = BigInt::bitNot(a);
    auto not_twice = BigInt::bitNot(not_once);
    ASSERT_EQ(BigInt::cmp(not_twice, a).toInt(), 0);
}

TEST(bigint_bit, not_of_not_one) {
    auto a = bi(-1);
    auto r = BigInt::bitNot(a);
    ASSERT_EQ(BigInt::toInt(r).toInt(), 0);
}

// ============ testBit ============

TEST(bigint_bit, test_bit_set) {
    auto a = bi(0b1000);  // bit 3 set
    auto r = BigInt::testBit(a, Variant((php::Int) 3));
    ASSERT_TRUE(r.toBool());
}

TEST(bigint_bit, test_bit_not_set) {
    auto a = bi(0b0111);  // bit 3 not set
    auto r = BigInt::testBit(a, Variant((php::Int) 3));
    ASSERT_FALSE(r.toBool());
}

TEST(bigint_bit, test_bit_zero) {
    auto a = bi(1);  // bit 0 set
    auto r = BigInt::testBit(a, Variant((php::Int) 0));
    ASSERT_TRUE(r.toBool());
}

TEST(bigint_bit, test_bit_high) {
    auto a = bi("0x10000000000000000000");
    auto r = BigInt::testBit(a, Variant((php::Int) 76));
    ASSERT_TRUE(r.toBool());
}

TEST(bigint_bit, test_bit_negative) {
    auto a = bi(-1);  // all bits set in two's complement
    auto r = BigInt::testBit(a, Variant((php::Int) 0));
    ASSERT_TRUE(r.toBool());
}

// ============ popCount ============

TEST(bigint_bit, popcount_zero) {
    auto a = bi(php::Int(0));
    auto r = BigInt::popCount(a);
    ASSERT_EQ(r.toInt(), 0);
}

TEST(bigint_bit, popcount_small) {
    auto a = bi(0b101011);  // bits 0,1,3,5 set = 4 bits
    auto r = BigInt::popCount(a);
    ASSERT_EQ(r.toInt(), 4);
}

TEST(bigint_bit, popcount_all_ones) {
    auto a = bi(255);  // 8 bits
    auto r = BigInt::popCount(a);
    ASSERT_EQ(r.toInt(), 8);
}

TEST(bigint_bit, popcount_large) {
    // 2^80 - 1 = all 80 bits set
    auto two = bi(2);
    auto pow80 = BigInt::pow(two, bi(80));
    auto one = bi(1);
    auto all_ones = BigInt::sub(pow80, one);
    auto r = BigInt::popCount(all_ones);
    ASSERT_EQ(r.toInt(), 80);
}

// ============ bitShiftLeft ============

TEST(bigint_bit, shift_left_basic) {
    auto a = bi(1);
    auto r = BigInt::bitShiftLeft(a, Variant((php::Int) 10));
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 1024);  // 2^10
}

TEST(bigint_bit, shift_left_by_zero) {
    auto a = bi(12345);
    auto r = BigInt::bitShiftLeft(a, Variant((php::Int) 0));
    ASSERT_EQ(BigInt::cmp(r, a).toInt(), 0);
}

TEST(bigint_bit, shift_left_large) {
    auto a = bi(1);
    auto r = BigInt::bitShiftLeft(a, Variant((php::Int) 100));
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, mpz_class(1) << 100);
}

TEST(bigint_bit, shift_left_multi_step) {
    auto a = bi(1);
    auto r1 = BigInt::bitShiftLeft(a, Variant((php::Int) 50));
    auto r2 = BigInt::bitShiftLeft(r1, Variant((php::Int) 50));
    auto expected = BigInt::bitShiftLeft(a, Variant((php::Int) 100));
    ASSERT_EQ(BigInt::cmp(r2, expected).toInt(), 0);
}

// ============ bitShiftRight ============

TEST(bigint_bit, shift_right_basic) {
    auto a = bi(1024);
    auto r = BigInt::bitShiftRight(a, Variant((php::Int) 10));
    auto *bi_ptr = r.toBox<BigInt>();
    ASSERT_NE(bi_ptr, nullptr);
    ASSERT_EQ(bi_ptr->data->value, 1);
}

TEST(bigint_bit, shift_right_by_zero) {
    auto a = bi(12345);
    auto r = BigInt::bitShiftRight(a, Variant((php::Int) 0));
    ASSERT_EQ(BigInt::cmp(r, a).toInt(), 0);
}

TEST(bigint_bit, shift_right_truncate) {
    auto a = bi(0b1011);  // 11
    auto r = BigInt::bitShiftRight(a, Variant((php::Int) 1));
    ASSERT_EQ(BigInt::toInt(r).toInt(), 5);  // 0b101
}

TEST(bigint_bit, shift_right_to_zero) {
    auto a = bi(7);
    auto r = BigInt::bitShiftRight(a, Variant((php::Int) 10));
    ASSERT_EQ(BigInt::toInt(r).toInt(), 0);
}

TEST(bigint_bit, shift_right_negative) {
    auto a = bi(-8);
    auto r = BigInt::bitShiftRight(a, Variant((php::Int) 1));
    ASSERT_EQ(BigInt::toInt(r).toInt(), -4);
}

// ============ Combined bit operations ============

TEST(bigint_bit, bit_field_extraction) {
    // Extract bits [8:16) from a value using bit ops
    auto value = bi("0x12345678");
    auto mask = BigInt::bitShiftLeft(bi(0xFF), Variant((php::Int) 8));
    auto masked = BigInt::bitAnd(value, mask);
    auto result = BigInt::bitShiftRight(masked, Variant((php::Int) 8));
    ASSERT_EQ(BigInt::toInt(result).toInt(), 0x56);
}

TEST(bigint_bit, set_clear_toggle_bit) {
    auto a = bi(php::Int(0));
    // Set bit 5
    auto bit5 = BigInt::bitShiftLeft(bi(1), Variant((php::Int) 5));
    a = BigInt::bitOr(a, bit5);
    ASSERT_TRUE(BigInt::testBit(a, Variant((php::Int) 5)).toBool());
    ASSERT_FALSE(BigInt::testBit(a, Variant((php::Int) 4)).toBool());
    // Clear bit 5 with XOR
    a = BigInt::bitXor(a, bit5);
    ASSERT_FALSE(BigInt::testBit(a, Variant((php::Int) 5)).toBool());
}

TEST(bigint_bit, is_power_of_two) {
    auto pow = BigInt::bitShiftLeft(bi(1), Variant((php::Int) 60));
    // x & (x - 1) == 0 for powers of two
    auto pow_minus_1 = BigInt::sub(pow, bi(1));
    auto result = BigInt::bitAnd(pow, pow_minus_1);
    ASSERT_EQ(BigInt::toInt(result).toInt(), 0);
}
