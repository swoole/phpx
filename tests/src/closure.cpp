#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

#if PHP_VERSION_ID >= 80200
TEST(closure, base) {
    ClosureFn fn = [](INTERNAL_FUNCTION_PARAMETERS, Object &this_, Args &vars_) -> Variant {
        auto arg_0 = getCallArg(0);
        EXPECT_STREQ(arg_0.toCString(), "java");

        auto arg_1 = getCallArg(1);
        EXPECT_STREQ(arg_1.toCString(), "php");

        auto arg_0_2 = getCallArg(0, "golang");
        EXPECT_STREQ(arg_0_2.toCString(), "java");

        return 1000;
    };

    auto o = newClosure(fn, {"hello", "swoole"});
    auto rs = o("java", "php");
    ASSERT_EQ(rs.toInt(), 1000);
}

TEST(closure, ref) {
    ClosureFn fn = [](INTERNAL_FUNCTION_PARAMETERS, Object &this_, Args &vars_) -> Variant {
        auto v = vars_.get(0);
        v = 1000;
        return null;
    };

    var v(2020);
    auto _f = newClosure(fn, {v.toReference()});
    _f();
    ASSERT_EQ(v.toInt(), 1000);
}
#endif
