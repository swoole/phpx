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
    EXPECT_EQ(typephp_call_cached("phpx_cached_first", cache, {1}).toInt(), 2);
    EXPECT_EQ(typephp_call_cached("phpx_cached_first", cache, {2}).toInt(), 3);
    EXPECT_EQ(typephp_call_cached("phpx_cached_second", cache, {3}).toInt(), 5);
    EXPECT_EQ(typephp_call_cached("phpx_cached_first", cache, {4}).toInt(), 5);
    EXPECT_EQ(typephp_call_cached("phpx_cached_many", cache, {1, 2, 3, 4, 5}).toInt(), 15);
}

TEST(typephp_call, small_argument_path_preserves_references_and_exceptions) {
    eval(R"PHP(
        function phpx_cached_increment(int &$value): int { return ++$value; }
        function phpx_cached_throw(): never { throw new RuntimeException('cached failure'); }
    )PHP");

    FunctionCallCacheSlot cache;
    Variant value = 10;
    Reference reference = value.toReference();
    EXPECT_EQ(typephp_call_cached("phpx_cached_increment", cache, {&reference}).toInt(), 11);
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
