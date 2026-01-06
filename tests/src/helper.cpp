#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

TEST(helper, empty_str_to_int) {
    auto i = php::to_int("");
    ASSERT_EQ(i, 0);
}

TEST(helper, to_int) {
    auto v = php::atoi("512k");
    ASSERT_EQ(v, 512 * 1024);
}

TEST(helper, to_array) {
    auto o = newObject("ArrayObject");
    o.offsetSet(null, 1987);
    o.offsetSet(null, 2026);
    o.offsetSet(2, 1999);

    auto a2 = to_array(o);
    ASSERT_EQ(a2.length(), 3);
}

TEST(helper, instanceOf) {
    var b = newObject("ArrayObject");
    ASSERT_FALSE(instanceOf(b, "NotExistsClass"));
    ASSERT_TRUE(instanceOf(b, "ArrayObject"));
}
