#include "phpx_test.h"
#include "phpx_std.h"

using namespace php;

TEST(std_array, in_array) {
    Array a{1, 2, 3, "hello"};

    ASSERT_TRUE(fn::in_array(2, a));
    ASSERT_TRUE(fn::in_array("hello", a));
    ASSERT_FALSE(fn::in_array(99, a));

    // strict mode
    ASSERT_TRUE(fn::in_array("2", a));
    ASSERT_FALSE(fn::in_array("2", a, true));
    ASSERT_TRUE(fn::in_array(2, a, true));
}

TEST(std_array, array_key_exists) {
    Array a;
    a.set(String("name"), "php");
    a.set(Variant(0), "zero");
    a.set(String("age"), 30);

    ASSERT_TRUE(fn::array_key_exists("name", a));
    ASSERT_TRUE(fn::array_key_exists(0, a));
    ASSERT_FALSE(fn::array_key_exists("missing", a));
    ASSERT_FALSE(fn::array_key_exists(99, a));
}

TEST(std_array, array_search) {
    Array a{1, 2, 3, "hello"};

    auto r1 = fn::array_search(2, a);
    ASSERT_TRUE(r1.isInt());
    ASSERT_EQ(r1.toInt(), 1);

    auto r2 = fn::array_search("hello", a);
    ASSERT_TRUE(r2.isInt());
    ASSERT_EQ(r2.toInt(), 3);

    auto r3 = fn::array_search(99, a);
    ASSERT_TRUE(r3.isFalse());

    // strict mode
    auto r4 = fn::array_search("2", a);
    ASSERT_TRUE(r4.isInt());
    auto r5 = fn::array_search("2", a, true);
    ASSERT_TRUE(r5.isFalse());

    Array keyed;
    keyed.set("named", 7);
    keyed.set(11, "eleven");
    ASSERT_STREQ(fn::array_search(7, keyed, true).toCString(), "named");
    ASSERT_EQ(fn::array_search("eleven", keyed, true).toInt(), 11);
    ASSERT_STREQ(fn::array_search("7", keyed).toCString(), "named");
}

TEST(std_array, array_keys) {
    Array a;
    a.set(String("x"), 1);
    a.set(String("y"), 2);
    a.set(Variant(0), "zero");

    auto keys = fn::array_keys(a);
    ASSERT_EQ(keys.length(), 3);

    auto packed_keys = fn::array_keys(Array{"a", "b", "c"});
    ASSERT_EQ(packed_keys.get(0).toInt(), 0);
    ASSERT_EQ(packed_keys.get(2).toInt(), 2);
    ASSERT_TRUE(fn::array_keys(Array{}).empty());
}

TEST(std_array, array_values) {
    Array a;
    a.set(String("x"), 1);
    a.set(String("y"), 2);

    auto vals = fn::array_values(a);
    ASSERT_EQ(vals.length(), 2);

    Array packed{1, 2};
    auto packed_values = fn::array_values(packed);
    ASSERT_EQ(packed_values.array(), packed.array());
    ASSERT_TRUE(fn::array_values(Array{}).empty());
}

TEST(std_array, array_key_first_last) {
    Array a;
    a.set(String("a"), 1);
    a.set(String("b"), 2);
    a.set(String("c"), 3);

    auto first = fn::array_key_first(a);
    ASSERT_STREQ(first.toString().toCString(), "a");

    auto last = fn::array_key_last(a);
    ASSERT_STREQ(last.toString().toCString(), "c");

    // Empty array
    Array empty;
    auto ef = fn::array_key_first(empty);
    ASSERT_TRUE(ef.isNull());
    auto el = fn::array_key_last(empty);
    ASSERT_TRUE(el.isNull());

    Array numeric;
    numeric.set(4, "first");
    numeric.set(9, "last");
    ASSERT_EQ(fn::array_key_first(numeric).toInt(), 4);
    ASSERT_EQ(fn::array_key_last(numeric).toInt(), 9);
}

TEST(std_array, array_merge) {
    Array a1;
    a1.set(String("color"), "red");
    a1.set(Variant(0), 1);

    Array a2;
    a2.set(String("color"), "green");
    a2.set(Variant(1), 2);

    // Two arrays
    auto m1 = fn::array_merge(a1, a2);
    ASSERT_GE(m1.length(), 3);
    ASSERT_STREQ(m1.get("color").toString().toCString(), "green");

    // Single array
    auto m2 = fn::array_merge(a1);
    ASSERT_GE(m2.length(), 2);

    // No args
    auto m3 = fn::array_merge();
    ASSERT_EQ(m3.length(), 0);
}

TEST(std_array, array_merge_variadic) {
    Array a1;
    a1.set(Variant(0), "a");
    Array a2;
    a2.set(Variant(0), "b");
    Array a3;
    a3.set(Variant(0), "c");

    auto m = fn::array_merge(a1, a2, a3);
    ASSERT_GE(m.length(), 3);
}

TEST(std_array, count) {
    Array a{1, 2, 3};
    ASSERT_EQ(fn::count(a), 3);

    Array empty;
    ASSERT_EQ(fn::count(empty), 0);

    // Countable object
    var obj = newObject("ArrayObject");
    obj.offsetSet(null, 10);
    obj.offsetSet(null, 20);
    ASSERT_EQ(fn::count(obj), 2);

    eval(R"(
        class PhpxStdArrayCountable implements Countable {
            public function __construct(private array $items) {}
            public function count(): int { return count($this->items); }
        }
    )");
    var countable = eval("return new PhpxStdArrayCountable([1, 2, 3, 4]);");
    ASSERT_EQ(fn::count(countable), 4);
    ASSERT_EQ(fn::count(countable, 1), 4);

    // Var argument
    var v = Array{10, 20, 30};
    ASSERT_EQ(fn::count(v), 3);

    Array nested{Array{1, 2}, Array{3}};
    ASSERT_EQ(fn::count(nested, 1), 5);
}

TEST(std_array, count_exception) {
    try_call([]() { fn::count(12345); }, "count(): Argument #1 ($value) must be of type Countable|array");
    auto plain_object = newObject("stdClass");
    try_call([&plain_object]() { fn::count(plain_object); },
             "count(): Argument #1 ($value) must be of type Countable|array");

    eval(R"(
        class PhpxStdArrayThrowingCountable implements Countable {
            public function count(): int { throw new RuntimeException('std count failed'); }
        }
    )");
    var obj = eval("return new PhpxStdArrayThrowingCountable();");
    try_call([&obj]() { fn::count(obj); }, "std count failed");
}

TEST(std_array, array_is_list) {
    Array listLike;
    listLike.append(1);
    listLike.append(2);
    listLike.append(3);
    ASSERT_TRUE(fn::array_is_list(listLike));

    Array assoc;
    assoc.set(String("a"), 1);
    ASSERT_FALSE(fn::array_is_list(assoc));

    Array empty;
    ASSERT_TRUE(fn::array_is_list(empty));
}

TEST(std_array, array_push) {
    var arr = Array{1, 2};
    Int count = fn::array_push(arr, 3, 4, 5);
    ASSERT_EQ(count, 5);
    ASSERT_EQ(arr.length(), 5);

    // Single push
    var arr2 = Array{"a"};
    fn::array_push(arr2, "b");
    ASSERT_EQ(arr2.length(), 2);

    Variant not_array = 1;
    try_call([&]() { fn::array_push(not_array, 2); },
             "array_push(): Argument #1 ($array) must be of type array");
}

TEST(std_array, array_fill) {
    auto a = fn::array_fill(0, 3, "x");
    ASSERT_EQ(a.length(), 3);
    ASSERT_STREQ(a.get(0).toString().toCString(), "x");
    ASSERT_STREQ(a.get(1).toString().toCString(), "x");
    ASSERT_STREQ(a.get(2).toString().toCString(), "x");

    // Non-zero start
    auto b = fn::array_fill(5, 2, "y");
    ASSERT_EQ(b.length(), 2);
    ASSERT_STREQ(b.get(5).toString().toCString(), "y");
    ASSERT_STREQ(b.get(6).toString().toCString(), "y");

    // Zero count
    auto c = fn::array_fill(0, 0, "z");
    ASSERT_EQ(c.length(), 0);

    try_call([]() { fn::array_fill(0, -1, "x"); },
             "array_fill(): Argument #2 ($count) must be greater than or equal to 0");
}

TEST(std_array, array_keys_filter) {
    Array a;
    a.set(String("a"), 1);
    a.set(String("b"), 2);
    a.set(String("c"), 2);
    a.set(String("d"), 3);

    // non-strict: find all keys with value 2
    auto keys = fn::array_keys_filter(a, 2);
    ASSERT_EQ(keys.length(), 2);
    ASSERT_STREQ(keys.get(0).toString().toCString(), "b");
    ASSERT_STREQ(keys.get(1).toString().toCString(), "c");

    // strict: "2" != int(2)
    auto strict = fn::array_keys_filter(a, Variant("2"), true);
    ASSERT_EQ(strict.length(), 0);

    // no matches
    auto none = fn::array_keys_filter(a, 999);
    ASSERT_EQ(none.length(), 0);

    // empty array
    Array empty;
    auto emptyKeys = fn::array_keys_filter(empty, 1);
    ASSERT_EQ(emptyKeys.length(), 0);

    Array mixed;
    mixed.set(4, 2);
    mixed.set("named", 2);
    auto strict_keys = fn::array_keys_filter(mixed, 2, true);
    ASSERT_EQ(strict_keys.get(0).toInt(), 4);
    ASSERT_STREQ(strict_keys.get(1).toCString(), "named");

    auto loose_keys = fn::array_keys_filter(mixed, "2");
    ASSERT_EQ(loose_keys.get(0).toInt(), 4);
    ASSERT_STREQ(loose_keys.get(1).toCString(), "named");
}
