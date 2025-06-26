#include "phpx_test.h"

using namespace php;

TEST(string, substr) {
    String str("Hello, World!");
    ASSERT_EQ(str.substr(0, 5), "Hello");
    ASSERT_EQ(str.substr(7, 5), "World");
    ASSERT_EQ(str.substr(-6, 5), "World");
    ASSERT_EQ(str.substr(7, -1), "World");
    ASSERT_EQ(str.substr(-6, -1), "World");
    ASSERT_EQ(str.substr(0, 20), "Hello, World!");
    ASSERT_EQ(str.substr(20, 5), "");
    ASSERT_EQ(str.substr(-20, 5), "Hello");
    ASSERT_EQ(str.substr(-20, -1), "Hello, World");
}

TEST(string, split) {
    String str("one,two,three,four");
    String dim(",");
    Array result = str.split(dim, 2);
    ASSERT_EQ(result.length(), 2);
    ASSERT_STREQ(result[0].toCString(), "one");
    ASSERT_STREQ(result[1].toCString(), "two,three,four");

    result = str.split(dim);
    ASSERT_EQ(result.length(), 4);
    ASSERT_STREQ(result[0].toCString(), "one");
    ASSERT_STREQ(result[1].toCString(), "two");
    ASSERT_STREQ(result[2].toCString(), "three");
    ASSERT_STREQ(result[3].toCString(), "four");
}