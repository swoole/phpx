#include "phpx_test.h"

using namespace php;

TEST(exec, func) {
    auto retval = exec("is_dir", "/tmp");
    ASSERT_TRUE(retval.toBool());
}
