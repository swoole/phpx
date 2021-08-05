#include "phpx_test.h"

using namespace php;

TEST(json, encode) {
    Array arr1;
    arr1.set("hello", "world");
    arr1.set("count", 182);
    auto json = arr1.jsonEncode();
    ASSERT_TRUE(json.isString());
    ASSERT_GT(json.length(), 10);
}
