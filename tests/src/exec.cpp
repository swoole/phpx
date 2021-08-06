#include "phpx_test.h"

using namespace php;

TEST(exec, func) {
    auto retval = exec("is_dir", "/tmp");
    ASSERT_TRUE(retval.toBool());
}

TEST(exec, static_method) {
    auto retval = exec("DateTime::createFromFormat", "j-M-Y", "15-Feb-2009");
    ASSERT_TRUE(retval.isObject());
    Object o(retval);
    auto _date = o.exec("format", "Y-m-d");
    ASSERT_STREQ(_date.toCString(), "2009-02-15");
}

TEST(exec, func_with_namespace) {
    auto retval = exec("\\is_dir", "/tmp");
    ASSERT_TRUE(retval.toBool());
}
