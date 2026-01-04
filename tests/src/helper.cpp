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
