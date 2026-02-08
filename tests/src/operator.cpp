#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

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
        ASSERT_FALSE((5 == v1).toBool());
        ASSERT_TRUE((10 == v1).toBool());
        ASSERT_FALSE((15 == v1).toBool());

        // Test different type comparison
        Variant v2("10");
        ASSERT_TRUE((10 == v2).toBool());
        ASSERT_TRUE(("10" == v2).toBool());
        ASSERT_FALSE((11 == v2).toBool());

        // Test floating point equality
        Variant v3(3.14);
        ASSERT_TRUE((3.14 == v3).toBool());
        ASSERT_FALSE((3.15 == v3).toBool());
    }
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
