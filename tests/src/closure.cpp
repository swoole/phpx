#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

TEST(closure, base) {
    ClosureFn fn = [](INTERNAL_FUNCTION_PARAMETERS, Object &this_, Array &vars_) {
        ZVAL_LONG(return_value, 1000);

        auto arg_0 = getCallArg(0);
        ASSERT_STREQ(arg_0.toCString(), "java");

        auto arg_1 = getCallArg(1);
        ASSERT_STREQ(arg_1.toCString(), "php");
    };

    auto o = newClosure(fn, {"hello", "swoole"});
    auto rs = o("java", "php");
    ASSERT_EQ(rs.toInt(), 1000);
}
