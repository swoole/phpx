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

TEST(closure, named_arguments_use_declared_parameter_names) {
    ClosureFn fn = [](INTERNAL_FUNCTION_PARAMETERS, Object &, Args &) -> Variant {
        return getCallArg(0).concat(getCallArg(1));
    };

    auto closure = newClosure(fn, {}, {}, nullptr, {"left", "right"});
    Args positional;
    positional.append("left:");
    Array named;
    named.set("right", "7");

    auto result = call(closure, positional, named.array());
    ASSERT_STREQ(result.toCString(), "left:7");
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
    ClosureFn fn = [](INTERNAL_FUNCTION_PARAMETERS, Object &this_, Args &vars_) -> Variant { return vars_.get(0); };

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

TEST(closure, preserves_lexical_scope) {
    eval(R"PHP(
        class PhpxClosureScopeParent {}
        class PhpxClosureScopeChild extends PhpxClosureScopeParent {}
    )PHP");

    auto *lexical_scope = getClassEntrySafe("PhpxClosureScopeParent");
    auto object = newObject("PhpxClosureScopeChild");
    ClosureFn fn = [](INTERNAL_FUNCTION_PARAMETERS, Object &, Args &) -> Variant {
        return String{zend_get_executed_scope()->name};
    };

    auto closure = newClosure(fn, {}, object, lexical_scope);
    ASSERT_STREQ(closure().toCString(), "PhpxClosureScopeParent");
}

TEST(closure, call_is_rejected_without_type_confusion) {
    auto result = run_in_child_capture_stdout([]() -> int {
        eval("class PhpxClosureCallPublicTarget { public string $value = 'bound'; }");
        ClosureFn fn = [](INTERNAL_FUNCTION_PARAMETERS, Object &this_, Args &) -> Variant {
            return this_.get("value");
        };

        auto closure = newClosure(fn);
        auto target = newObject("PhpxClosureCallPublicTarget");
        closure.call("call", {target});
        return 0;
    });

    ASSERT_TRUE(result.exited) << result.output;
    ASSERT_EQ(result.exit_code, 1) << result.output;
}
#endif
