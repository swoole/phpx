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
    auto rs = o({"java", "php"});
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

TEST(closure, return_reference_capture_as_value) {
    ClosureFn fn = [](INTERNAL_FUNCTION_PARAMETERS, Object &this_, Args &vars_) -> Variant {
        return vars_.get(0);
    };

    var v("captured");
    auto f = newClosure(fn, {v.toReference()});
    auto rv = f();
    ASSERT_TRUE(rv.isString());
    ASSERT_STREQ(rv.toCString(), "captured");

    rv = "changed";
    ASSERT_STREQ(v.toCString(), "captured");
}

TEST(closure, use_value_and_reference_capture) {
    ClosureFn by_value = [](INTERNAL_FUNCTION_PARAMETERS, Object &this_, Args &vars_) -> Variant {
        auto v = vars_.get(0);
        v = 1000;
        return v;
    };

    var copied(2020);
    auto f1 = newClosure(by_value, {copied});
    ASSERT_EQ(f1().toInt(), 1000);
    ASSERT_EQ(copied.toInt(), 2020);

    ClosureFn by_ref = [](INTERNAL_FUNCTION_PARAMETERS, Object &this_, Args &vars_) -> Variant {
        auto v = vars_.get(0);
        v = 3000;
        return null;
    };

    var referenced(2020);
    auto f2 = newClosure(by_ref, {referenced.toReference()});
    f2();
    ASSERT_EQ(referenced.toInt(), 3000);
}
#endif
