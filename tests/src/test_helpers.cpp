#include "phpx_test.h"
#include <gtest/gtest-spi.h>

#include <cstdio>

php::String get_runtime_php_version() {
    return php::call("phpversion").toString();
}

php::Int get_runtime_php_version_id() {
    const php::String version = get_runtime_php_version();
    int major = 0;
    int minor = 0;
    int patch = 0;
    if (std::sscanf(version.data(), "%d.%d.%d", &major, &minor, &patch) != 3) {
        return -1;
    }
    return major * 10000 + minor * 100 + patch;
}

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
