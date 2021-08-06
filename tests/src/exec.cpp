#include "phpx_test.h"

using namespace php;

TEST(variant, toCString) {
    std::string s1("hello world");
    Variant s2("hello world");
    ASSERT_STREQ(s1.c_str(), s2.toCString());
}
