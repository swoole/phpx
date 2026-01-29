#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

TEST(helper, empty_str_to_int) {
    auto i = php::toInt("");
    ASSERT_EQ(i, 0);
}

TEST(helper, toInt) {
    auto v = php::atoi("512k");
    ASSERT_EQ(v, 512 * 1024);
}

TEST(helper, toArray) {
    auto o = newObject("ArrayObject");
    o.offsetSet(null, 1987);
    o.offsetSet(null, 2026);
    o.offsetSet(2, 1999);

    auto a2 = toArray(o);
    ASSERT_EQ(a2.length(), 3);
}

TEST(helper, instanceOf) {
    var b = newObject("ArrayObject");
    ASSERT_FALSE(instanceOf(b, "NotExistsClass"));
    ASSERT_TRUE(instanceOf(b, "ArrayObject"));
}

TEST(helper, abs) {
    var a = "-10";
    ASSERT_EQ(php::math::abs(a).toInt(), 10);

    var b = -3.1415;
    ASSERT_EQ(php::math::abs(b).toFloat(), 3.1415);

    var c = 199;
    ASSERT_EQ(php::math::abs(c).toInt(), 199);
}
