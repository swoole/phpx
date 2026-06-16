#include "phpx_test.h"
#include "phpx_std.h"

using namespace php;

TEST(std_math, abs) {
    var a = "-10";
    ASSERT_EQ(fn::abs(a).toInt(), 10);

    var b = -3.1415;
    ASSERT_EQ(fn::abs(b).toFloat(), 3.1415);

    var c = 199;
    ASSERT_EQ(fn::abs(c).toInt(), 199);

    ASSERT_EQ(fn::abs(-100L), 100L);
    ASSERT_EQ(fn::abs(100L), 100L);

    ASSERT_EQ(fn::abs(-100.09), 100.09);
    ASSERT_EQ(fn::abs(100.09), 100.09);

    // Edge: PHP_INT_MIN returns float
    var minInt = std::numeric_limits<zend_long>::min();
    ASSERT_TRUE(fn::abs(minInt).isFloat());
}

TEST(std_math, pow) {
    var e = 3;
    var d = 4;
    ASSERT_EQ(fn::pow(e, d).toInt(), std::pow(3, 4));

    ASSERT_EQ(fn::pow(2, 10).toInt(), 1024);
    ASSERT_DOUBLE_EQ(fn::pow(2, -1).toFloat(), 0.5);
}

TEST(std_math, mod) {
    var f = 13;
    var h = 3;
    ASSERT_EQ(fn::mod(f, h).toInt(), 1);

    ASSERT_EQ(fn::mod(10, 3).toInt(), 1);
    ASSERT_EQ(fn::mod(10, -3).toInt(), 1);
    ASSERT_EQ(fn::mod(-10, 3).toInt(), -1);
}

TEST(std_math, round) {
    ASSERT_DOUBLE_EQ(fn::round(3.4), 3.0);
    ASSERT_DOUBLE_EQ(fn::round(3.5), 4.0);
    ASSERT_DOUBLE_EQ(fn::round(3.6), 4.0);
    ASSERT_DOUBLE_EQ(fn::round(-3.4), -3.0);
    ASSERT_DOUBLE_EQ(fn::round(-3.5), -4.0);

    // Precision
    ASSERT_DOUBLE_EQ(fn::round(3.14159, 2), 3.14);
    ASSERT_DOUBLE_EQ(fn::round(3.14159, 4), 3.1416);

    // Mode: PHP_ROUND_HALF_DOWN
    ASSERT_DOUBLE_EQ(fn::round(3.5, 0, PHP_ROUND_HALF_DOWN), 3.0);
    ASSERT_DOUBLE_EQ(fn::round(3.51, 0, PHP_ROUND_HALF_DOWN), 4.0);

    // Mode: PHP_ROUND_HALF_EVEN
    ASSERT_DOUBLE_EQ(fn::round(3.5, 0, PHP_ROUND_HALF_EVEN), 4.0);
    ASSERT_DOUBLE_EQ(fn::round(4.5, 0, PHP_ROUND_HALF_EVEN), 4.0);

    // Mode: PHP_ROUND_HALF_ODD
    ASSERT_DOUBLE_EQ(fn::round(3.5, 0, PHP_ROUND_HALF_ODD), 3.0);
    ASSERT_DOUBLE_EQ(fn::round(4.5, 0, PHP_ROUND_HALF_ODD), 5.0);
}

TEST(std_math, floor_ceil) {
    ASSERT_DOUBLE_EQ(fn::floor(3.14), 3.0);
    ASSERT_DOUBLE_EQ(fn::floor(3.99), 3.0);
    ASSERT_DOUBLE_EQ(fn::floor(-3.14), -4.0);

    ASSERT_DOUBLE_EQ(fn::ceil(3.14), 4.0);
    ASSERT_DOUBLE_EQ(fn::ceil(3.01), 4.0);
    ASSERT_DOUBLE_EQ(fn::ceil(-3.14), -3.0);
}

TEST(std_math, trig) {
    ASSERT_DOUBLE_EQ(fn::sin(0), 0.0);
    ASSERT_DOUBLE_EQ(fn::sin(M_PI / 2), 1.0);
    ASSERT_NEAR(fn::sin(M_PI), 0.0, 1e-15);

    ASSERT_DOUBLE_EQ(fn::cos(0), 1.0);
    ASSERT_NEAR(fn::cos(M_PI / 2), 0.0, 1e-15);
    ASSERT_DOUBLE_EQ(fn::cos(M_PI), -1.0);

    ASSERT_NEAR(fn::tan(0), 0.0, 1e-15);
    ASSERT_NEAR(fn::tan(M_PI / 4), 1.0, 1e-15);

    // Var variants
    var v = M_PI / 6;
    ASSERT_DOUBLE_EQ(fn::sin(v), 0.5);
    ASSERT_NEAR(fn::cos(v), std::sqrt(3.0) / 2.0, 1e-15);
}

TEST(std_math, arc_trig) {
    ASSERT_DOUBLE_EQ(fn::asin(0), 0.0);
    ASSERT_DOUBLE_EQ(fn::asin(1), M_PI / 2);
    ASSERT_DOUBLE_EQ(fn::asin(-1), -M_PI / 2);

    ASSERT_DOUBLE_EQ(fn::acos(1), 0.0);
    ASSERT_DOUBLE_EQ(fn::acos(0), M_PI / 2);
    ASSERT_DOUBLE_EQ(fn::acos(-1), M_PI);

    ASSERT_DOUBLE_EQ(fn::atan(0), 0.0);
    ASSERT_DOUBLE_EQ(fn::atan(1), M_PI / 4);

    ASSERT_DOUBLE_EQ(fn::atan2(1, 0), M_PI / 2);
    ASSERT_DOUBLE_EQ(fn::atan2(0, -1), M_PI);
    ASSERT_DOUBLE_EQ(fn::atan2(1, 1), M_PI / 4);
}

TEST(std_math, hyperbolic) {
    ASSERT_DOUBLE_EQ(fn::sinh(0), 0.0);
    ASSERT_NEAR(fn::sinh(1), std::sinh(1.0), 1e-15);

    ASSERT_DOUBLE_EQ(fn::cosh(0), 1.0);
    ASSERT_NEAR(fn::cosh(1), std::cosh(1.0), 1e-15);

    ASSERT_DOUBLE_EQ(fn::tanh(0), 0.0);
    ASSERT_NEAR(fn::tanh(1), std::tanh(1.0), 1e-15);

    ASSERT_DOUBLE_EQ(fn::asinh(0), 0.0);

    ASSERT_DOUBLE_EQ(fn::acosh(1), 0.0);

    ASSERT_DOUBLE_EQ(fn::atanh(0), 0.0);
}

TEST(std_math, pi) {
    ASSERT_DOUBLE_EQ(fn::pi(), M_PI);
}

TEST(std_math, exp_log) {
    ASSERT_DOUBLE_EQ(fn::exp(0), 1.0);
    ASSERT_DOUBLE_EQ(fn::exp(1), M_E);

    ASSERT_NEAR(fn::expm1(0), 0.0, 1e-15);
    ASSERT_NEAR(fn::expm1(1), M_E - 1.0, 1e-15);

    ASSERT_DOUBLE_EQ(fn::log(1), 0.0);
    ASSERT_DOUBLE_EQ(fn::log(M_E), 1.0);

    // log with base
    ASSERT_DOUBLE_EQ(fn::log(8, 2), 3.0);
    ASSERT_DOUBLE_EQ(fn::log(100, 10), 2.0);

    ASSERT_DOUBLE_EQ(fn::log10(1), 0.0);
    ASSERT_DOUBLE_EQ(fn::log10(100), 2.0);

    ASSERT_DOUBLE_EQ(fn::log1p(0), 0.0);
    ASSERT_NEAR(fn::log1p(M_E - 1), 1.0, 1e-15);

    ASSERT_DOUBLE_EQ(fn::sqrt(0), 0.0);
    ASSERT_DOUBLE_EQ(fn::sqrt(4), 2.0);
    ASSERT_DOUBLE_EQ(fn::sqrt(2), std::sqrt(2.0));
}

TEST(std_math, hypot_deg) {
    ASSERT_DOUBLE_EQ(fn::hypot(3, 4), 5.0);
    ASSERT_DOUBLE_EQ(fn::hypot(0, 0), 0.0);

    ASSERT_DOUBLE_EQ(fn::deg2rad(0), 0.0);
    ASSERT_DOUBLE_EQ(fn::deg2rad(180), M_PI);
    ASSERT_DOUBLE_EQ(fn::deg2rad(360), 2 * M_PI);

    ASSERT_DOUBLE_EQ(fn::rad2deg(0), 0.0);
    ASSERT_DOUBLE_EQ(fn::rad2deg(M_PI), 180.0);
    ASSERT_DOUBLE_EQ(fn::rad2deg(2 * M_PI), 360.0);

    // Round-trip
    ASSERT_NEAR(fn::rad2deg(fn::deg2rad(90)), 90.0, 1e-14);
}

TEST(std_math, float_ops) {
    ASSERT_DOUBLE_EQ(fn::fmod(5.7, 1.3), ::fmod(5.7, 1.3));
    ASSERT_DOUBLE_EQ(fn::fmod(10, 3.5), 3.0);

    ASSERT_DOUBLE_EQ(fn::fdiv(10, 3), 10.0 / 3.0);
    ASSERT_DOUBLE_EQ(fn::fdiv(1, 2), 0.5);

    ASSERT_DOUBLE_EQ(fn::fpow(2, 10), 1024.0);
    ASSERT_DOUBLE_EQ(fn::fpow(9, 0.5), 3.0);

    ASSERT_EQ(fn::intdiv(10, 3), 3);
    ASSERT_EQ(fn::intdiv(-10, 3), -3);
    ASSERT_EQ(fn::intdiv(10, -3), -3);
    ASSERT_EQ(fn::intdiv(100, 1), 100);
}

TEST(std_math, intdiv_exceptions) {
    try_call([]() { fn::intdiv(1, 0); }, "Division by zero");
    try_call([]() {
        auto min = std::numeric_limits<zend_long>::min();
        fn::intdiv(min, -1);
    }, "Division of PHP_INT_MIN by -1 is not an integer");
}

TEST(std_math, log_exceptions) {
    try_call([]() { fn::log(1, 0); }, "Argument #2 ($base) must be greater than 0");
    try_call([]() { fn::log(1, -1); }, "Argument #2 ($base) must be greater than 0");
    try_call([]() { fn::log(1, 1); }, "");  // log(1, 1) returns NAN, not exception
}

TEST(std_math, float_check) {
    ASSERT_TRUE(fn::is_finite(1.0));
    ASSERT_TRUE(fn::is_finite(0.0));
    ASSERT_FALSE(fn::is_finite(INFINITY));
    ASSERT_FALSE(fn::is_finite(NAN));

    ASSERT_TRUE(fn::is_infinite(INFINITY));
    ASSERT_TRUE(fn::is_infinite(-INFINITY));
    ASSERT_FALSE(fn::is_infinite(0.0));
    ASSERT_FALSE(fn::is_infinite(NAN));

    ASSERT_TRUE(fn::is_nan(NAN));
    ASSERT_FALSE(fn::is_nan(0.0));
    ASSERT_FALSE(fn::is_nan(INFINITY));

    // Var variants
    var inf = INFINITY;
    ASSERT_TRUE(fn::is_infinite(inf));
    var zero = 0.0;
    ASSERT_FALSE(fn::is_nan(zero));
}

TEST(std_math, base_conv_to_string) {
    auto s1 = fn::decbin(10);
    ASSERT_STREQ(s1.toCString(), "1010");
    auto s2 = fn::decbin(0);
    ASSERT_STREQ(s2.toCString(), "0");

    auto s3 = fn::decoct(10);
    ASSERT_STREQ(s3.toCString(), "12");
    auto s4 = fn::decoct(8);
    ASSERT_STREQ(s4.toCString(), "10");

    auto s5 = fn::dechex(10);
    ASSERT_STREQ(s5.toCString(), "a");
    auto s6 = fn::dechex(255);
    ASSERT_STREQ(s6.toCString(), "ff");
    auto s7 = fn::dechex(0);
    ASSERT_STREQ(s7.toCString(), "0");
}

TEST(std_math, base_conv_from_string) {
    ASSERT_EQ(fn::bindec("1010").toInt(), 10);
    ASSERT_EQ(fn::bindec("0").toInt(), 0);

    ASSERT_EQ(fn::hexdec("a").toInt(), 10);
    ASSERT_EQ(fn::hexdec("ff").toInt(), 255);
    ASSERT_EQ(fn::hexdec("FF").toInt(), 255);

    ASSERT_EQ(fn::octdec("12").toInt(), 10);
    ASSERT_EQ(fn::octdec("10").toInt(), 8);
}

TEST(std_math, base_convert) {
    auto r1 = fn::base_convert("1010", 2, 10);
    ASSERT_STREQ(r1.toCString(), "10");

    auto r2 = fn::base_convert("10", 10, 2);
    ASSERT_STREQ(r2.toCString(), "1010");

    auto r3 = fn::base_convert("ff", 16, 10);
    ASSERT_STREQ(r3.toCString(), "255");

    auto r4 = fn::base_convert("255", 10, 16);
    ASSERT_STREQ(r4.toCString(), "ff");
}

TEST(std_math, base_convert_exceptions) {
    try_call([]() { fn::base_convert("10", 1, 10); },
             "base_convert(): Argument #2 ($from_base) must be between 2 and 36");
    try_call([]() { fn::base_convert("10", 37, 10); },
             "base_convert(): Argument #2 ($from_base) must be between 2 and 36");
    try_call([]() { fn::base_convert("10", 10, 1); },
             "base_convert(): Argument #3 ($to_base) must be between 2 and 36");
    try_call([]() { fn::base_convert("10", 10, 37); },
             "base_convert(): Argument #3 ($to_base) must be between 2 and 36");
}

TEST(std_math, number_format) {
    auto r1 = fn::number_format(1234.56);
    ASSERT_STREQ(r1.toCString(), "1,235");

    auto r2 = fn::number_format(1234.56, 2);
    ASSERT_STREQ(r2.toCString(), "1,234.56");

    auto r3 = fn::number_format(1234.56, 2, ".", "");
    ASSERT_STREQ(r3.toCString(), "1234.56");

    auto r4 = fn::number_format(1234.56, 2, ",", " ");
    ASSERT_STREQ(r4.toCString(), "1 234,56");

    auto r5 = fn::number_format(0);
    ASSERT_STREQ(r5.toCString(), "0");

    auto r6 = fn::number_format(-1234.56, 1);
    ASSERT_STREQ(r6.toCString(), "-1,234.6");
}
