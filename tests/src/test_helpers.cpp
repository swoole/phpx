#include "phpx_test.h"
#include <gtest/gtest-spi.h>

TEST(test_helpers, try_call_requires_an_exception) {
    EXPECT_NONFATAL_FAILURE(try_call([]() {}, "missing exception"), "Expected a PHP exception");
}

TEST(test_helpers, try_call_accepts_a_matching_exception) {
    try_call([]() { php::eval("throw new RuntimeException('expected message');"); }, "expected message");
    EXPECT_EQ(EG(exception), nullptr);
}

TEST(test_helpers, try_call_rejects_a_mismatched_exception) {
    EXPECT_NONFATAL_FAILURE(
        try_call([]() { php::eval("throw new RuntimeException('different message');"); }, "expected message"),
        "expected");
    EXPECT_EQ(EG(exception), nullptr);
}
