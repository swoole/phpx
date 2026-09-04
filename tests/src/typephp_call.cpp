#include "phpx_test.h"
#include "typephp_helper.h"

using namespace php;

TEST(typephp_call, function_cache_supports_monomorphic_and_polymorphic_strings) {
    eval(R"PHP(
        function phpx_cached_first(int $value): int { return $value + 1; }
        function phpx_cached_second(int $value): int { return $value + 2; }
    )PHP");

    FunctionCallCacheSlot cache;
    EXPECT_EQ(typephp_call_cached("phpx_cached_first", cache, {1}).toInt(), 2);
    EXPECT_EQ(typephp_call_cached("phpx_cached_first", cache, {2}).toInt(), 3);
    EXPECT_EQ(typephp_call_cached("phpx_cached_second", cache, {3}).toInt(), 5);
    EXPECT_EQ(typephp_call_cached("phpx_cached_first", cache, {4}).toInt(), 5);
}

TEST(typephp_call, non_string_callables_are_not_retained) {
    Variant closure = eval("return static fn (int $value): int => $value + 3;");
    FunctionCallCacheSlot cache;
    const uint32_t references = GC_REFCOUNT(closure.object());

    EXPECT_EQ(typephp_call_cached(closure, cache, {4}).toInt(), 7);
    EXPECT_EQ(GC_REFCOUNT(closure.object()), references);
    closure.unset();
    EXPECT_TRUE(closure.isUndef());
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
