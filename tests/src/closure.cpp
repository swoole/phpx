#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

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

TEST(closure, parameter_metadata_preserves_reference_arguments) {
    ClosureFn fn = [](INTERNAL_FUNCTION_PARAMETERS, Object &, Args &) -> Variant {
        auto value = getCallArgByRef(0);
        value = 42;
        return null;
    };

    auto closure = newClosureWithParameters(fn, {}, {}, nullptr, {{"value", true, false, true}});
    Variant value(1);
    auto reference = value.toReference();
    Args args;
    args.append(&reference);
    call(closure, args);

    ASSERT_EQ(value.toInt(), 42);
}

TEST(closure, explicit_strict_types_are_used_by_nested_internal_calls) {
    ClosureFn fn = [](INTERNAL_FUNCTION_PARAMETERS, Object &, Args &) -> Variant {
        return call("sin", {"1"});
    };

    auto weak = newClosureWithParameters(fn, {}, {}, nullptr, {});
    ASSERT_TRUE(weak().isFloat());

    auto strict = newClosureWithParameters(fn, {}, {}, nullptr, {}, ClosureStrictTypes::Enabled);
    try_call([&]() { strict(); }, "must be of type float");
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

TEST(closure, captured_reference_cycle_is_visible_to_zend_gc) {
    ClosureFn fn = [](INTERNAL_FUNCTION_PARAMETERS, Object &, Args &) -> Variant { return null; };

    Variant closure;
    Variant captured;
    closure = newClosure(fn, {captured.toReference()});
    captured = closure;

    Object weak_ref(call(Array{"WeakReference", "create"}, {closure}));
    closure.unset();
    captured.unset();

    zend_gc_collect_cycles();
    ASSERT_TRUE(weak_ref.call("get").isNull());
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

TEST(closure, scoped_callable_preserves_private_and_magic_dispatch) {
    eval(R"PHP(
        class PhpxScopedCallableBase {}
        class PhpxScopedCallableTarget extends PhpxScopedCallableBase {
            private function multiply(int $value): int {
                return $value * 3;
            }

            public function publicMultiply(int $value): int {
                return $value * 4;
            }

            public static function publicStaticMultiply(int $value): int {
                return $value * 5;
            }

            public function __call(string $name, array $args): string {
                return 'magic:' . $name . ':' . $args[0];
            }
        }

        class PhpxScopedCallableForeign {
            public function scopeAnchor(): void {}
        }
        class PhpxScopedCallableChild extends PhpxScopedCallableTarget {}
    )PHP");

    auto object = newObject("PhpxScopedCallableTarget");
    Array callback{object, "multiply"};

    auto *target_scope = getClassEntry("PhpxScopedCallableTarget");
    CallableScope instance_scope{getMethod(target_scope, "multiply"), object.ce(), object.object()};
    auto private_callable = makeScopedCallable(callback, instance_scope);
    ASSERT_TRUE(private_callable.isObject());
    ASSERT_EQ(private_callable({7}).toInt(), 21);

    Array public_callback{object, "publicMultiply"};
    auto public_callable = prepareScopedCallback(public_callback, instance_scope);
    ASSERT_TRUE(public_callable.isArray());
    ASSERT_EQ(call("array_map", {public_callable, Array{2}}).toArray().get(0).toInt(), 8);

    Array relative_public_callback{"self", "publicMultiply"};
    auto relative_public_callable = makeScopedCallable(relative_public_callback, instance_scope);
    ASSERT_TRUE(relative_public_callable.isObject());
    ASSERT_EQ(relative_public_callable({3}).toInt(), 12);

    Array self_callback{"self", "multiply"};
    ASSERT_EQ(callScoped(self_callback, instance_scope, {6}).toInt(), 18);
    auto self_callable = makeScopedCallable(self_callback, instance_scope);
    ASSERT_EQ(self_callable({8}).toInt(), 24);

    auto mapped = call("array_map", {private_callable, Array{1, 2, 3}}).toArray();
    ASSERT_EQ(mapped.get(0).toInt(), 3);
    ASSERT_EQ(mapped.get(1).toInt(), 6);
    ASSERT_EQ(mapped.get(2).toInt(), 9);

    auto *foreign_scope = getClassEntry("PhpxScopedCallableForeign");
    CallableScope foreign_context{getMethod(foreign_scope, "scopeAnchor"), foreign_scope, nullptr};
    auto magic_callable = makeScopedCallable(callback, foreign_context);
    ASSERT_STREQ(magic_callable({5}).toCString(), "magic:multiply:5");
}

TEST(closure, normalize_callable_class_resolves_relative_class_names) {
    auto object = newObject("PhpxScopedCallableChild");
    auto *lexical_scope = getClassEntry("PhpxScopedCallableTarget");
    auto *called_scope = object.ce();
    CallableScope scope{
        getMethod(lexical_scope, "multiply"),
        called_scope,
        object.object(),
    };

    auto self_callback = normalizeCallableClass(Array{"self", "multiply"}, scope).toArray();
    ASSERT_STREQ(self_callback.get(0).toCString(), "PhpxScopedCallableTarget");

    auto static_callback = normalizeCallableClass(Array{"static", "multiply"}, scope).toArray();
    ASSERT_STREQ(static_callback.get(0).toCString(), "PhpxScopedCallableChild");

    auto parent_callback = normalizeCallableClass(Array{"parent", "multiply"}, scope).toArray();
    ASSERT_STREQ(parent_callback.get(0).toCString(), "PhpxScopedCallableBase");

    Array absolute{"PhpxScopedCallableTarget", "multiply"};
    auto unchanged = normalizeCallableClass(absolute, scope).toArray();
    ASSERT_EQ(unchanged.array(), absolute.array());

    Args unpacked{ArgList{Array{"static", "multiply"}, 1}};
    normalizeCallableClass(unpacked, 0, scope);
    ASSERT_STREQ(unpacked.get(0).toArray().get(0).toCString(), "PhpxScopedCallableChild");

    Variant scalar = "strlen";
    ASSERT_TRUE(normalizeCallableClass(scalar, scope).equals(scalar));

    Array incomplete{"self"};
    ASSERT_EQ(normalizeCallableClass(incomplete, scope).toArray().array(), incomplete.array());

    Array non_string_class{object, "multiply"};
    ASSERT_EQ(normalizeCallableClass(non_string_class, scope).toArray().array(), non_string_class.array());

    auto *foreign_scope = getClassEntry("PhpxScopedCallableForeign");
    CallableScope base_context{getMethod(foreign_scope, "scopeAnchor"), foreign_scope, nullptr};
    Array missing_parent{"parent", "multiply"};
    ASSERT_TRUE(normalizeCallableClass(missing_parent, base_context).equals(missing_parent));

    Args unchanged_args{ArgList{1}};
    normalizeCallableClass(unchanged_args, 5, scope);
    ASSERT_EQ(unchanged_args.count(), 1u);
}

TEST(closure, scoped_callable_validates_scope_and_callback) {
    CallableScope invalid_scope{nullptr, nullptr, nullptr};
    try_call([&]() { makeScopedCallable("strlen", invalid_scope); }, "Explicit callable scope must not be null");

    auto *scope_ce = getClassEntry("PhpxScopedCallableTarget");
    Object object = newObject(scope_ce);
    CallableScope scope{getMethod(scope_ce, "multiply"), scope_ce, object.object()};
    try_call([&]() { makeScopedCallable("function_that_does_not_exist", scope); },
             "Invalid callback function_that_does_not_exist");

    Variant existing = eval("return static fn(int $value): int => $value + 1;");
    Variant prepared = prepareScopedCallback(existing, scope);
    ASSERT_EQ(prepared.object(), existing.object());

    Variant public_function = "strlen";
    Variant reusable = prepareScopedCallback(public_function, scope);
    ASSERT_TRUE(reusable.isString());
    ASSERT_EQ(call(reusable, {"phpx"}).toInt(), 4);

    Object static_callable = makeScopedCallable("PhpxScopedCallableTarget::publicStaticMultiply", scope);
    ASSERT_EQ(static_callable({2}).toInt(), 10);

    Object relative_static = prepareScopedCallback("self::publicStaticMultiply", scope).toObject();
    ASSERT_EQ(relative_static({3}).toInt(), 15);
}

TEST(closure, call_is_rejected_without_type_confusion) {
    auto result = run_in_child_capture_stdout([]() -> int {
        ClosureFn fn = [](INTERNAL_FUNCTION_PARAMETERS, Object &this_, Args &) -> Variant { return null; };

        auto closure = newClosure(fn);
        auto target = newObject("stdClass");
        closure.call("call", {target});
        return 0;
    });

    ASSERT_TRUE(result.exited) << result.output;
    ASSERT_EQ(result.exit_code, 1) << result.output;
}
