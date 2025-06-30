#include "phpx_test.h"
#include "phpx_func.h"

using namespace php;

TEST(function, http_build_query) {
    Array arr1;
    arr1.set("hello", "world");
    arr1.set("count", 182);
    auto query = http_build_query(arr1, null, "&", PHP_QUERY_RFC1738);

    ASSERT_TRUE(query.isString());
    ASSERT_GT(query.length(), 10);

    String expected = "hello=world&count=182";
    ASSERT_STREQ(query.toCString(), expected.c_str());
}
