#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

TEST(same, int_comparison) {
    // Test same integers
    ASSERT_TRUE(php::same(5L, 5L));
    ASSERT_TRUE(php::same(-10L, -10L));
    ASSERT_TRUE(php::same(0L, 0L));
    ASSERT_TRUE(php::same((php::Int) LONG_MAX, (php::Int) LONG_MAX));
    ASSERT_TRUE(php::same((php::Int) LONG_MIN, (php::Int) LONG_MIN));

    // Test different integers
    ASSERT_FALSE(php::same(5L, 10L));
    ASSERT_FALSE(php::same(-5L, 5L));
    ASSERT_FALSE(php::same(0L, 1L));
    ASSERT_FALSE(php::same((php::Int) LONG_MAX, (php::Int) LONG_MIN));
    ASSERT_FALSE(php::same(100L, -100L));
}

TEST(same, float_comparison) {
    // Test same floats
    ASSERT_TRUE(php::same(3.14, 3.14));
    ASSERT_TRUE(php::same(-2.5, -2.5));
    ASSERT_TRUE(php::same(0.0, 0.0));
    ASSERT_TRUE(php::same(1.0, 1.0));

    // Test different floats
    ASSERT_FALSE(php::same(3.14, 2.71));
    ASSERT_FALSE(php::same(-1.5, 1.5));
    ASSERT_FALSE(php::same(0.0, 0.1));
    ASSERT_FALSE(php::same(10.5, 10.6));

    // Test precision issues
    // Note: 0.1 + 0.2 != 0.3 due to floating-point precision
    ASSERT_FALSE(php::same(0.1 + 0.2, 0.3));  // Expected to be false due to precision
    ASSERT_FALSE(php::same(0.1, 0.1000001));  // Small difference

    // Special values test
    ASSERT_TRUE(php::same(INFINITY, INFINITY));
    ASSERT_TRUE(php::same(-INFINITY, -INFINITY));
    ASSERT_FALSE(php::same(INFINITY, -INFINITY));

    // NaN test (NaN is not equal to any value, including itself)
    ASSERT_FALSE(php::same(NAN, NAN));
    ASSERT_FALSE(php::same(NAN, 0.0));
    ASSERT_FALSE(php::same(0.0, NAN));
}

TEST(same, bool_comparison) {
    // Test same boolean values
    ASSERT_TRUE(php::same(true, true));
    ASSERT_TRUE(php::same(false, false));

    // Test different boolean values
    ASSERT_FALSE(php::same(true, false));
    ASSERT_FALSE(php::same(false, true));

    // Test type conversion
    ASSERT_TRUE(php::same((php::Bool) 1, true));
    ASSERT_TRUE(php::same((php::Bool) 0, false));
    ASSERT_FALSE(php::same((php::Bool) 1, false));
    ASSERT_FALSE(php::same((php::Bool) 0, true));

    // Test comparison with other types (should use explicit conversion)
    ASSERT_TRUE(php::same((php::Bool)(5 != 0), true));
    ASSERT_TRUE(php::same((php::Bool)(0 == 0), true));
}

TEST(same, cross_type_comparison) {
    // Test comparison between different types (these should be compile errors, but test boundary cases at runtime)

    // Integer and float comparison (requires explicit conversion)
    ASSERT_TRUE(php::same((php::Float) 5L, 5.0));
    ASSERT_FALSE(php::same((php::Float) 5L, 5.1));

    // Integer and boolean comparison (requires explicit conversion)
    ASSERT_TRUE(php::same((php::Bool)(1L != 0), true));
    ASSERT_TRUE(php::same((php::Bool)(0L == 0), true));

    // Float and boolean comparison (requires explicit conversion)
    ASSERT_TRUE(php::same((php::Bool)(1.0 != 0.0), true));
    ASSERT_TRUE(php::same((php::Bool)(0.0 == 0.0), true));
}

TEST(same, edge_cases) {
    // Edge cases test

    // Integer boundaries
    ASSERT_TRUE(php::same((php::Int) LONG_MAX, (php::Int) LONG_MAX));
    ASSERT_TRUE(php::same((php::Int) LONG_MIN, (php::Int) LONG_MIN));
    ASSERT_FALSE(php::same((php::Int) LONG_MAX, (php::Int) LONG_MIN));

    // Float boundaries
    ASSERT_TRUE(php::same(DBL_MAX, DBL_MAX));
    ASSERT_TRUE(php::same(-DBL_MAX, -DBL_MAX));
    ASSERT_FALSE(php::same(DBL_MAX, -DBL_MAX));

    // Various representations of zero
    ASSERT_TRUE(php::same(0L, 0L));
    ASSERT_TRUE(php::same(0.0, 0.0));
    ASSERT_TRUE(php::same(-0.0, -0.0));
    ASSERT_TRUE(php::same(-0.0, 0.0));  // In IEEE 754, -0.0 == 0.0

    // Very small values test
    ASSERT_TRUE(php::same(DBL_MIN, DBL_MIN));
    ASSERT_FALSE(php::same(DBL_MIN, 2 * DBL_MIN));
}

TEST(same, performance_simple) {
    // Simple performance test
    const int iterations = 1000000;

    // Integer comparison performance
    volatile bool result_int = true;
    for (int i = 0; i < iterations; i++) {
        result_int &= php::same((php::Int) i, (php::Int) i);
    }
    ASSERT_TRUE(result_int);

    // Float comparison performance
    volatile bool result_float = true;
    for (int i = 0; i < iterations; i++) {
        result_float &= php::same((php::Float) i, (php::Float) i);
    }
    ASSERT_TRUE(result_float);

    // Boolean comparison performance
    volatile bool result_bool = true;
    for (int i = 0; i < iterations; i++) {
        bool val = (i % 2) == 0;
        result_bool &= php::same(val, val);
    }
    ASSERT_TRUE(result_bool);
}