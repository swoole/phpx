#include "phpx_test.h"
#include "phpx_std.h"

#include <limits>

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

TEST(std_array, array_merge_reindexes_numeric_keys_in_first_array) {
    Array first;
    first.set(9, "a");
    first.set(-4, "b");
    first.set("name", "first");

    auto single = fn::array_merge(first);
    ASSERT_TRUE(same(single, call("array_merge", {first})));
    ASSERT_EQ(single.length(), 3);
    ASSERT_STREQ(single.get(0).toString().toCString(), "a");
    ASSERT_STREQ(single.get(1).toString().toCString(), "b");
    ASSERT_STREQ(single.get("name").toString().toCString(), "first");
    auto single_keys = fn::array_keys(single);
    ASSERT_EQ(single_keys.get(0).toInt(), 0);
    ASSERT_EQ(single_keys.get(1).toInt(), 1);
    ASSERT_STREQ(single_keys.get(2).toCString(), "name");

    Array second;
    second.set(42, "c");
    second.set("name", "second");

    auto merged = fn::array_merge(first, second);
    ASSERT_TRUE(same(merged, call("array_merge", {first, second})));
    ASSERT_EQ(merged.length(), 4);
    ASSERT_STREQ(merged.get(0).toString().toCString(), "a");
    ASSERT_STREQ(merged.get(1).toString().toCString(), "b");
    ASSERT_STREQ(merged.get(2).toString().toCString(), "c");
    ASSERT_STREQ(merged.get("name").toString().toCString(), "second");
    auto merged_keys = fn::array_keys(merged);
    ASSERT_EQ(merged_keys.get(0).toInt(), 0);
    ASSERT_EQ(merged_keys.get(1).toInt(), 1);
    ASSERT_STREQ(merged_keys.get(2).toCString(), "name");
    ASSERT_EQ(merged_keys.get(3).toInt(), 2);
}

TEST(std_array, array_merge_matches_php_for_holes_tail_deletions_and_empty_input) {
    Array with_hole{"zero", "one", "two"};
    ASSERT_TRUE(with_hole.del(1));
    auto hole_result = fn::array_merge(with_hole);
    ASSERT_TRUE(same(hole_result, call("array_merge", {with_hole})));
    ASSERT_STREQ(hole_result.get(0).toCString(), "zero");
    ASSERT_STREQ(hole_result.get(1).toCString(), "two");

    Array with_deleted_tail{"zero", "one"};
    ASSERT_TRUE(with_deleted_tail.del(1));
    auto tail_result = fn::array_merge(with_deleted_tail);
    ASSERT_TRUE(same(tail_result, call("array_merge", {with_deleted_tail})));
    ASSERT_STREQ(tail_result.get(0).toCString(), "zero");

    Array empty;
    ASSERT_TRUE(same(fn::array_merge(empty), call("array_merge", {empty})));
}

TEST(std_array, array_merge_empty_pair_preserves_php_append_keys) {
    Array with_deleted_tail{"zero", "one"};
    ASSERT_TRUE(with_deleted_tail.del(1));
    Array empty;

    auto empty_second = fn::array_merge(with_deleted_tail, empty);
    ASSERT_TRUE(same(empty_second, call("array_merge", {with_deleted_tail, empty})));
    ASSERT_EQ(empty_second.array(), with_deleted_tail.array());
    empty_second.append("next");
    ASSERT_STREQ(empty_second.get(2).toCString(), "next");
    ASSERT_STREQ(with_deleted_tail.get(0).toCString(), "zero");

    auto empty_first = fn::array_merge(empty, with_deleted_tail);
    ASSERT_TRUE(same(empty_first, call("array_merge", {empty, with_deleted_tail})));
    ASSERT_EQ(empty_first.array(), with_deleted_tail.array());
    empty_first.append("next");
    ASSERT_STREQ(empty_first.get(2).toCString(), "next");

    Array first_empty{"first"};
    ASSERT_TRUE(first_empty.del(0));
    Array second_empty{"first", "second"};
    ASSERT_TRUE(second_empty.del(0));
    ASSERT_TRUE(second_empty.del(1));
    auto both_empty = fn::array_merge(first_empty, second_empty);
    ASSERT_TRUE(same(both_empty, call("array_merge", {first_empty, second_empty})));
    ASSERT_EQ(both_empty.array(), second_empty.array());
    both_empty.append("next");
    ASSERT_STREQ(both_empty.get(2).toCString(), "next");

    Array with_hole{"zero", "one", "two"};
    ASSERT_TRUE(with_hole.del(1));
    auto hole_result = fn::array_merge(with_hole, empty);
    ASSERT_TRUE(same(hole_result, call("array_merge", {with_hole, empty})));
    ASSERT_NE(hole_result.array(), with_hole.array());
    hole_result.append("next");
    ASSERT_STREQ(hole_result.get(2).toCString(), "next");
}

TEST(std_array, array_merge_variadic_does_not_apply_empty_pair_fast_path) {
    Array with_deleted_tail{"zero", "one"};
    ASSERT_TRUE(with_deleted_tail.del(1));
    Array empty;
    Array next;
    next.set(42, "next");

    auto three = fn::array_merge(with_deleted_tail, empty, next);
    ASSERT_TRUE(same(three, call("array_merge", {with_deleted_tail, empty, next})));
    ASSERT_STREQ(three.get(0).toCString(), "zero");
    ASSERT_STREQ(three.get(1).toCString(), "next");
    three.append("after three");
    ASSERT_STREQ(three.get(2).toCString(), "after three");

    auto four = fn::array_merge(with_deleted_tail, empty, empty, next);
    ASSERT_TRUE(same(four, call("array_merge", {with_deleted_tail, empty, empty, next})));
    ASSERT_STREQ(four.get(0).toCString(), "zero");
    ASSERT_STREQ(four.get(1).toCString(), "next");
    four.append("after four");
    ASSERT_STREQ(four.get(2).toCString(), "after four");

    Array empty_with_next_two{"first", "second"};
    ASSERT_TRUE(empty_with_next_two.del(0));
    ASSERT_TRUE(empty_with_next_two.del(1));
    auto trailing_empty = fn::array_merge(empty, empty, empty_with_next_two);
    ASSERT_TRUE(same(trailing_empty, call("array_merge", {empty, empty, empty_with_next_two})));
    trailing_empty.append("next");
    ASSERT_STREQ(trailing_empty.get(0).toCString(), "next");
}

TEST(std_array, array_merge_matches_php_key_and_next_index_matrix) {
    constexpr size_t shape_count = 7;
    const char *shape_names[shape_count] = {
        "fresh_empty", "empty_next_two", "dense_packed", "tail_deleted",
        "holes", "mixed_negative_numeric", "pure_string_stale_next",
    };
    auto make_shape = [](size_t shape) {
        Array array;
        switch (shape) {
        case 0:
            return array;
        case 1:
            array.append("first");
            array.append("second");
            array.del(0);
            array.del(1);
            return array;
        case 2:
            array.append("zero");
            array.append("one");
            return array;
        case 3:
            array.append("zero");
            array.append("one");
            array.del(1);
            return array;
        case 4:
            array.append("zero");
            array.append("one");
            array.append("two");
            array.del(1);
            return array;
        case 5:
            array.set(-4, "negative");
            array.set("name", "named");
            return array;
        case 6:
            array.set("name", "named");
            array.set(4, "numeric");
            array.del(4);
            return array;
        default:
            return array;
        }
    };

    for (size_t first = 0; first < shape_count; first++) {
        for (size_t second = 0; second < shape_count; second++) {
            auto a = make_shape(first);
            auto b = make_shape(second);
            auto actual = fn::array_merge(a, b);
            auto expected = call("array_merge", {a, b}).toArray();
            EXPECT_TRUE(same(actual, expected)) << shape_names[first] << ", " << shape_names[second];
            actual.append("next");
            expected.append("next");
            EXPECT_TRUE(same(actual, expected)) << shape_names[first] << ", " << shape_names[second];
        }
    }

    for (size_t first = 0; first < shape_count; first++) {
        for (size_t second = 0; second < shape_count; second++) {
            for (size_t third = 0; third < shape_count; third++) {
                auto a = make_shape(first);
                auto b = make_shape(second);
                auto c = make_shape(third);
                auto actual = fn::array_merge(a, b, c);
                auto expected = call("array_merge", {a, b, c}).toArray();
                EXPECT_TRUE(same(actual, expected))
                    << shape_names[first] << ", " << shape_names[second] << ", " << shape_names[third];
                actual.append("next");
                expected.append("next");
                EXPECT_TRUE(same(actual, expected))
                    << shape_names[first] << ", " << shape_names[second] << ", " << shape_names[third];
            }
        }
    }
}

TEST(std_array, array_merge_preserves_copy_on_write_and_references) {
    Array input;
    input.set(9, "input");
    Array other;
    other.set(42, "other");
    auto result = fn::array_merge(input, other);

    result.set(0, "result");
    ASSERT_STREQ(input.get(9).toCString(), "input");
    input.set(9, "changed input");
    ASSERT_STREQ(result.get(0).toCString(), "result");
    result.set(1, "changed result");
    ASSERT_STREQ(other.get(42).toCString(), "other");
    other.set(42, "changed other");
    ASSERT_STREQ(result.get(1).toCString(), "changed result");

    Array packed{"packed"};
    auto packed_result = fn::array_merge(packed);
    ASSERT_EQ(packed_result.array(), packed.array());
    packed_result.set(0, "changed packed result");
    ASSERT_STREQ(packed.get(0).toCString(), "packed");

    Variant value = 1;
    Reference reference = value.toReference();
    Variant referenced(reference.const_ptr(), Ctor::CopyRef);
    Array referenced_input;
    referenced_input.set(9, referenced);
    auto referenced_result = fn::array_merge(referenced_input);

    ASSERT_TRUE(referenced_result.get(0).isReference());
    referenced_result[0] = 2;
    ASSERT_EQ(value.toInt(), 2);
    ASSERT_EQ(referenced_input.get(9).toInt(), 2);
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
    try_call([&]() { fn::array_push(not_array, 2); }, "array_push(): Argument #1 ($array) must be of type array");
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
    try_call([]() { fn::array_fill(0, static_cast<php::Int>(INT_MAX) + 1, "x"); },
             "array_fill(): Argument #2 ($count) is too large");
    try_call([]() { fn::array_fill(std::numeric_limits<php::Int>::max(), 2, "x"); },
             "Cannot add element to the array as the next element is already occupied");
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
