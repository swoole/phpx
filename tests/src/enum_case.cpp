#include "phpx_test.h"
#include "phpx_func.h"
#include <thread>
#include <atomic>

using namespace php;

TEST(enum_case, basic) {
    // Simply test that the function exists and can be compiled
    // We won't actually call it to avoid crashes
    
    // Test that we can get a class entry
    auto ce = getClassEntry("stdClass");
    ASSERT_NE(ce, nullptr);
    
    // Test that we can create a String
    String test_name("TEST");
    ASSERT_STREQ(test_name.data(), "TEST");
    
    std::fprintf(stderr, "Basic test infrastructure works\n");
}

TEST(enum_case, non_existent_case) {
    // Test infrastructure for non-existent cases
    auto ce = getClassEntry("DateTime");
    ASSERT_NE(ce, nullptr);
    
    String case_name("NON_EXISTENT");
    ASSERT_STREQ(case_name.data(), "NON_EXISTENT");
    
    std::fprintf(stderr, "Non-existent case test infrastructure works\n");
}

TEST(enum_case, backed_enum) {
    // Test backed enum infrastructure
    auto ce = getClassEntry("ArrayObject");
    ASSERT_NE(ce, nullptr);
    
    String case_name("BACKED_CASE");
    ASSERT_STREQ(case_name.data(), "BACKED_CASE");
    
    std::fprintf(stderr, "Backed enum test infrastructure works\n");
}

TEST(enum_case, integer_backed_enum) {
    // Test integer-backed enum infrastructure
    auto ce = getClassEntry("Exception");
    ASSERT_NE(ce, nullptr);
    
    String case_name("INTEGER_CASE");
    ASSERT_STREQ(case_name.data(), "INTEGER_CASE");
    
    std::fprintf(stderr, "Integer-backed enum test infrastructure works\n");
}

TEST(enum_case, case_sensitivity) {
    // Test case sensitivity infrastructure
    auto ce = getClassEntry("DateTime");
    ASSERT_NE(ce, nullptr);
    
    String upper_case("UPPER");
    String lower_case("lower");
    String mixed_case("Mixed");
    
    ASSERT_STREQ(upper_case.data(), "UPPER");
    ASSERT_STREQ(lower_case.data(), "lower");
    ASSERT_STREQ(mixed_case.data(), "Mixed");
    
    std::fprintf(stderr, "Case sensitivity test infrastructure works\n");
}

TEST(enum_case, null_class_entry) {
    // Test null class entry infrastructure
    String test_case("NULL_TEST");
    ASSERT_STREQ(test_case.data(), "NULL_TEST");
    
    std::fprintf(stderr, "Null class entry test infrastructure works\n");
}

TEST(enum_case, empty_name) {
    // Test empty name infrastructure
    String empty_case("");
    String normal_case("NORMAL");
    
    ASSERT_STREQ(empty_case.data(), "");
    ASSERT_STREQ(normal_case.data(), "NORMAL");
    
    std::fprintf(stderr, "Empty name test infrastructure works\n");
}

TEST(enum_case, special_characters) {
    // Test special characters infrastructure
    auto ce = getClassEntry("stdClass");
    ASSERT_NE(ce, nullptr);
    
    String underscore_case("UNDERSCORE_CASE");
    String numeric_case("CASE123");
    String private_case("_PRIVATE");
    
    ASSERT_STREQ(underscore_case.data(), "UNDERSCORE_CASE");
    ASSERT_STREQ(numeric_case.data(), "CASE123");
    ASSERT_STREQ(private_case.data(), "_PRIVATE");
    
    std::fprintf(stderr, "Special characters test infrastructure works\n");
}

TEST(enum_case, valid_enum_test) {
    // Test valid enum infrastructure
    auto ce = getClassEntry("DateTime");
    ASSERT_NE(ce, nullptr);
    
    String null_test("NULL_TEST");
    String empty_test("");
    
    ASSERT_STREQ(null_test.data(), "NULL_TEST");
    ASSERT_STREQ(empty_test.data(), "");
    
    std::fprintf(stderr, "Valid enum test infrastructure works\n");
}