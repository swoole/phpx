#include "phpx_test.h"
#include "typephp_helper.h"

using namespace php;

TEST(typephp_call, function_cache_supports_monomorphic_and_polymorphic_strings) {
    eval(R"PHP(
        function phpx_cached_first(int $value): int { return $value + 1; }
        function phpx_cached_second(int $value): int { return $value + 2; }
        function phpx_cached_many(int $a, int $b, int $c, int $d, int $e): int {
            return $a + $b + $c + $d + $e;
        }
    )PHP");

    FunctionCallCacheSlot cache;
    std::array<Variant, 1> one_arg{1};
    EXPECT_EQ(typephp_call_cached("phpx_cached_first", cache, one_arg).toInt(), 2);
    one_arg[0] = 2;
    EXPECT_EQ(typephp_call_cached("phpx_cached_first", cache, one_arg).toInt(), 3);
    one_arg[0] = 3;
    EXPECT_EQ(typephp_call_cached("phpx_cached_second", cache, one_arg).toInt(), 5);
    one_arg[0] = 4;
    EXPECT_EQ(typephp_call_cached("phpx_cached_first", cache, one_arg).toInt(), 5);

    std::array<Variant, 5> five_args{1, 2, 3, 4, 5};
    EXPECT_EQ(typephp_call_cached("phpx_cached_many", cache, five_args).toInt(), 15);
}

TEST(typephp_call, var_list_deduces_fixed_argument_storage) {
    static_assert(std::is_same_v<decltype(VarList{"phpx_cached_first", 1}), VarList<2>>);

    eval(R"PHP(
        function phpx_var_list_target(int $value): int { return $value + 1; }
        function phpx_var_list_increment(int &$value): int { return ++$value; }
        function phpx_var_list_no_args(): int { return 42; }
    )PHP");
    FunctionCallCacheSlot cache;
    EXPECT_EQ(typephp_call_cached("phpx_var_list_target", cache, VarList{4}).toInt(), 5);

    Variant value = 10;
    Reference reference = value.toReference();
    EXPECT_EQ(typephp_call_cached("phpx_var_list_increment", cache, VarList{&reference}).toInt(), 11);
    EXPECT_EQ(value.toInt(), 11);

    EXPECT_EQ(typephp_call_cached("phpx_var_list_no_args", cache, VarList{}).toInt(), 42);
}

TEST(typephp_call, fixed_argument_path_preserves_references_and_exceptions) {
    eval(R"PHP(
        function phpx_cached_increment(int &$value): int { return ++$value; }
        function phpx_cached_throw(): never { throw new RuntimeException('cached failure'); }
    )PHP");

    FunctionCallCacheSlot cache;
    Variant value = 10;
    Reference reference = value.toReference();
    std::array<Variant, 1> args{&reference};
    EXPECT_EQ(typephp_call_cached("phpx_cached_increment", cache, args).toInt(), 11);
    EXPECT_EQ(value.toInt(), 11);

    try {
        typephp_call_cached("phpx_cached_throw", cache);
        FAIL() << "expected php::Exception";
    } catch (zend_object *) {
        Object exception = catchException();
        EXPECT_STREQ(exception.call("getMessage").toCString(), "cached failure");
    }
}

TEST(typephp_call, non_string_callables_are_not_retained) {
    Variant closure = eval("return static fn (int $value): int => $value + 3;");
    Variant alternate = eval("return static fn (int $value): int => $value + 5;");
    FunctionCallCacheSlot cache;
    const uint32_t references = GC_REFCOUNT(closure.object());
    const uint32_t alternate_references = GC_REFCOUNT(alternate.object());

    EXPECT_EQ(typephp_call_cached(closure, cache, {4}).toInt(), 7);
    EXPECT_EQ(typephp_call_cached(alternate, cache, {4}).toInt(), 9);
    EXPECT_EQ(typephp_call_cached(closure, cache, {5}).toInt(), 8);
    EXPECT_EQ(GC_REFCOUNT(closure.object()), references);
    EXPECT_EQ(GC_REFCOUNT(alternate.object()), alternate_references);
    closure.unset();
    alternate.unset();
    EXPECT_TRUE(closure.isUndef());
    EXPECT_TRUE(alternate.isUndef());
}

TEST(typephp_call, closure_fast_path_preserves_binding_named_arguments_and_references) {
    Variant bound = eval(R"PHP(
        class PhpxCachedClosureBase {
            protected int $value = 10;
            public function make(): Closure {
                return function (int $increment): string {
                    return static::class . ':' . ($this->value + $increment);
                };
            }
        }
        class PhpxCachedClosureChild extends PhpxCachedClosureBase {}
        return (new PhpxCachedClosureChild())->make();
    )PHP");
    FunctionCallCacheSlot cache;
    Array named_args;
    named_args.set("increment", 4);
    std::array<Variant, 0> no_positional_args{};
    EXPECT_EQ(typephp_call_cached(bound, cache, no_positional_args, named_args.array()).toString(),
              "PhpxCachedClosureChild:14");

    Variant by_reference = eval("return static function (int &$value): int { return ++$value; };");
    Variant value = 20;
    Reference reference = value.toReference();
    std::array<Variant, 1> args{&reference};
    EXPECT_EQ(typephp_call_cached(by_reference, cache, args).toInt(), 21);
    EXPECT_EQ(value.toInt(), 21);
}

TEST(typephp_call, method_cache_guards_class_name_and_magic_trampolines) {
    eval(R"PHP(
        class PhpxCachedMethodFirst {
            public function run(int $value): string { return 'first:' . $value; }
        }
        class PhpxCachedMethodSecond {
            public function run(int $value): string { return 'second:' . $value; }
        }
        class PhpxCachedMagicMethod {
            public function __call(string $name, array $args): string {
                return 'magic-' . $name . ':' . $args[0];
            }
        }
    )PHP");

    Variant first = eval("return new PhpxCachedMethodFirst();");
    Variant second = eval("return new PhpxCachedMethodSecond();");
    Variant magic = eval("return new PhpxCachedMagicMethod();");
    MethodCallCacheSlot cache;

    EXPECT_EQ(typephp_call_method_cached(first, "run", cache, {1}).toString(), "first:1");
    EXPECT_EQ(typephp_call_method_cached(first, "run", cache, {2}).toString(), "first:2");
    EXPECT_EQ(typephp_call_method_cached(second, "run", cache, {3}).toString(), "second:3");
    EXPECT_EQ(typephp_call_method_cached(magic, "missing", cache, {4}).toString(), "magic-missing:4");
}

TEST(typephp_call, scoped_method_cache_guards_lexical_and_called_scope) {
    eval(R"PHP(
        class PhpxScopedCachedMethod {
            public function scopeAnchor(): void {}
            private function hidden(int $value): string { return 'private:' . $value; }
            public function __call(string $name, array $args): string {
                return 'magic-' . $name . ':' . $args[0];
            }
        }
        class PhpxScopedCachedForeign {
            public function scopeAnchor(): void {}
        }
    )PHP");

    Variant target = eval("return new PhpxScopedCachedMethod();");
    auto *target_ce = getClassEntry("PhpxScopedCachedMethod");
    auto *foreign_ce = getClassEntry("PhpxScopedCachedForeign");
    CallableScope target_scope{getMethod(target_ce, "scopeAnchor"), target_ce, target.object()};
    CallableScope foreign_scope{getMethod(foreign_ce, "scopeAnchor"), foreign_ce, nullptr};
    MethodCallCacheSlot cache;

    EXPECT_EQ(typephp_call_method_scoped_cached(target, "hidden", target_scope, cache, {1}).toString(), "private:1");
    EXPECT_EQ(typephp_call_method_scoped_cached(target, "hidden", target_scope, cache, {2}).toString(), "private:2");
    EXPECT_EQ(typephp_call_method_cached(target, "hidden", cache, {3}).toString(), "magic-hidden:3");
    EXPECT_EQ(typephp_call_method_scoped_cached(target, "hidden", foreign_scope, cache, {4}).toString(),
              "magic-hidden:4");
}

TEST(typephp_call, call_caches_accept_indirect_receivers_and_names) {
    eval(R"PHP(
        class PhpxIndirectCachedCall {
            public function run(int $value): string { return 'run:' . $value; }
        }
        function phpx_indirect_cached_function(int $value): string { return 'function:' . $value; }
    )PHP");

    Array values;
    values.set("object", eval("return new PhpxIndirectCachedCall();"));
    values.set("method", "run");
    values.set("function", "phpx_indirect_cached_function");
    Variant object = values.item("object", true);
    Variant method = values.item("method", true);
    Variant function = values.item("function", true);
    ASSERT_TRUE(object.isIndirect());
    ASSERT_TRUE(method.isIndirect());
    ASSERT_TRUE(function.isIndirect());

    MethodCallCacheSlot method_cache;
    EXPECT_EQ(typephp_call_method_cached(object, method, method_cache, {1}).toString(), "run:1");
    EXPECT_EQ(typephp_call_method_cached(object, method, method_cache, {2}).toString(), "run:2");

    FunctionCallCacheSlot function_cache;
    EXPECT_EQ(typephp_call_cached(function, function_cache, {3}).toString(), "function:3");
    EXPECT_EQ(typephp_call_cached(function, function_cache, {4}).toString(), "function:4");
}
