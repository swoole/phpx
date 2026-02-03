#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

TEST(exists, null) {
    var v1;
    ASSERT_FALSE(exists(v1, {}));

    var v2(undef());
    ASSERT_FALSE(exists(v2, {}));
}

TEST(exists, basic_array_access) {
    Array arr;
    arr.set("name", "John");
    arr.set("age", 25);
    arr.set("active", true);

    var v = arr;

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "name"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "email"}}));
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "phone"}}));
}

TEST(exists, basic_object_property) {
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);

    auto obj = newObject("TestClass");
    obj.set("dynamic_prop", "dynamic value");

    var v = obj;

    ASSERT_FALSE(exists(v, {{PropertyFetch, "propInt"}}));
    ASSERT_FALSE(exists(v, {{PropertyFetch, "propString"}}));

    ASSERT_TRUE(exists(v, {{PropertyFetch, "propBool"}}));

    ASSERT_TRUE(exists(v, {{PropertyFetch, "dynamic_prop"}}));

    ASSERT_FALSE(exists(v, {{PropertyFetch, "nonexistent"}}));
}

TEST(exists, array_dim_fetch_basic) {
    Array arr;
    arr.set("key1", "value1");
    arr.set("key2", "");
    arr.set("key3", 0);
    arr.set("key4", false);
    arr.set("key5", nullptr);

    Variant v = arr;

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "key1"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "key2"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "key3"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "key4"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "key5"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "nonexistent"}}));
}

TEST(exists, array_dim_fetch_nested) {
    Array inner_arr;
    inner_arr.set("inner_key", "inner_value");
    inner_arr.set("empty_key", "");
    inner_arr.set("null_key", nullptr);

    Array outer_arr;
    outer_arr.set("nested", inner_arr);
    outer_arr.set("empty_nested", Array{});
    outer_arr.set("null_nested", nullptr);

    Variant v = outer_arr;

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "nested"}, {ArrayDimFetch, "inner_key"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "nested"}, {ArrayDimFetch, "empty_key"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "nested"}, {ArrayDimFetch, "null_key"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "empty_nested"}, {ArrayDimFetch, "any_key"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "null_nested"}, {ArrayDimFetch, "any_key"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "nonexistent"}, {ArrayDimFetch, "key"}}));
}

TEST(exists, numeric_keys) {
    Array numeric_arr;
    numeric_arr.set(0, "first");
    numeric_arr.set(1, "");
    numeric_arr.set(2, 0);
    numeric_arr.set(3, false);
    numeric_arr.set(4, nullptr);

    Variant v = numeric_arr;

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 0}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 1}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 2}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 3}}));  // false

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, 4}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, 999}}));
}

TEST(exists, string_numeric_keys) {
    Array mixed_arr;
    mixed_arr.set("0", "string_zero");
    mixed_arr.set("1", "");
    mixed_arr.set("2", nullptr);
    mixed_arr.set("0x", "string_0x");

    Variant v = mixed_arr;

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "0"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 0}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "1"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 1}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "2"}}));
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, 2}}));

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "0x"}}));
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "99"}}));
}

TEST(exists, property_fetch_basic) {
    auto obj = newObject("stdClass");
    obj.set("prop1", "value1");
    obj.set("prop2", "");
    obj.set("prop3", 0);
    obj.set("prop4", false);
    obj.set("prop5", nullptr);

    Variant v = obj;

    ASSERT_TRUE(exists(v, {{PropertyFetch, "prop1"}}));
    ASSERT_TRUE(exists(v, {{PropertyFetch, "prop2"}}));
    ASSERT_TRUE(exists(v, {{PropertyFetch, "prop3"}}));
    ASSERT_TRUE(exists(v, {{PropertyFetch, "prop4"}}));

    ASSERT_FALSE(exists(v, {{PropertyFetch, "prop5"}}));

    ASSERT_FALSE(exists(v, {{PropertyFetch, "nonexistent"}}));
}

TEST(exists, property_fetch_nested) {
    auto inner_obj = newObject("stdClass");
    inner_obj.set("inner_prop", "inner_value");
    inner_obj.set("empty_prop", "");
    inner_obj.set("null_prop", nullptr);

    auto outer_obj = newObject("stdClass");
    outer_obj.set("nested_obj", inner_obj);
    outer_obj.set("null_obj", nullptr);

    Variant v = outer_obj;

    ASSERT_TRUE(exists(v, {{PropertyFetch, "nested_obj"}, {PropertyFetch, "inner_prop"}}));
    ASSERT_TRUE(exists(v, {{PropertyFetch, "nested_obj"}, {PropertyFetch, "empty_prop"}}));

    ASSERT_FALSE(exists(v, {{PropertyFetch, "nested_obj"}, {PropertyFetch, "null_prop"}}));

    ASSERT_FALSE(exists(v, {{PropertyFetch, "null_obj"}, {PropertyFetch, "any_prop"}}));

    ASSERT_FALSE(exists(v, {{PropertyFetch, "nonexistent"}, {PropertyFetch, "prop"}}));
}

TEST(exists, mixed_operations) {
    auto obj = newObject("stdClass");
    obj.set("obj_prop", "object_value");
    obj.set("empty_prop", "");
    obj.set("null_prop", nullptr);

    Array arr;
    arr.set("object_key", obj);
    arr.set("regular_key", "array_value");
    arr.set("empty_key", "");
    arr.set("null_key", nullptr);
    arr.set("null_obj_key", nullptr);

    Variant v = arr;

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "object_key"}, {PropertyFetch, "obj_prop"}}));

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "object_key"}, {PropertyFetch, "empty_prop"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "object_key"}, {PropertyFetch, "null_prop"}}));

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "regular_key"}}));

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "empty_key"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "null_key"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "null_obj_key"}, {PropertyFetch, "any_prop"}}));

    auto obj_v = Variant(obj);
    ASSERT_FALSE(exists(obj_v, {{ArrayDimFetch, "any_key"}}));
}

TEST(exists, complex_chains) {
    auto deep_obj = newObject("stdClass");
    deep_obj.set("level3_prop", "deep_value");
    deep_obj.set("empty_prop", "");
    deep_obj.set("null_prop", nullptr);

    auto mid_obj = newObject("stdClass");
    mid_obj.set("level2_obj", deep_obj);
    mid_obj.set("null_obj", nullptr);

    Array level1_arr;
    level1_arr.set("level1_obj", mid_obj);
    level1_arr.set("null_arr", nullptr);

    Variant v = level1_arr;

    ASSERT_TRUE(
        exists(v, {{ArrayDimFetch, "level1_obj"}, {PropertyFetch, "level2_obj"}, {PropertyFetch, "level3_prop"}}));

    ASSERT_TRUE(
        exists(v, {{ArrayDimFetch, "level1_obj"}, {PropertyFetch, "level2_obj"}, {PropertyFetch, "empty_prop"}}));

    ASSERT_FALSE(
        exists(v, {{ArrayDimFetch, "level1_obj"}, {PropertyFetch, "level2_obj"}, {PropertyFetch, "null_prop"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "level1_obj"}, {PropertyFetch, "null_obj"}, {PropertyFetch, "any_prop"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "null_arr"}, {PropertyFetch, "any_prop"}}));

    ASSERT_FALSE(
        exists(v, {{ArrayDimFetch, "level1_obj"}, {PropertyFetch, "level2_obj"}, {PropertyFetch, "nonexistent_prop"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "nonexistent_key"}, {PropertyFetch, "any_prop"}}));
}

TEST(exists, edge_cases) {
    Array empty_arr;
    var v1 = empty_arr;
    ASSERT_FALSE(exists(v1, {{ArrayDimFetch, "any_key"}}));

    auto empty_obj = newObject("stdClass");
    var v2 = empty_obj;
    ASSERT_FALSE(exists(v2, {{PropertyFetch, "any_prop"}}));

    var v3 = nullptr;
    ASSERT_FALSE(exists(v3, {{ArrayDimFetch, "any"}}));
    ASSERT_FALSE(exists(v3, {{PropertyFetch, "any"}}));

    var v4 = "test string";
    ASSERT_FALSE(exists(v4, {{ArrayDimFetch, "any"}}));
    ASSERT_FALSE(exists(v4, {{PropertyFetch, "any"}}));

    var v5 = 42;
    ASSERT_FALSE(exists(v5, {{ArrayDimFetch, "any"}}));
    ASSERT_FALSE(exists(v5, {{PropertyFetch, "any"}}));
}

TEST(exists, type_mismatch_scenarios) {
    var string_val = "hello";
    ASSERT_FALSE(exists(string_val, {{ArrayDimFetch, "key"}}));

    var array_val = create_map();
    ASSERT_FALSE(exists(array_val, {{PropertyFetch, "prop"}}));

    var int_val = 123;
    ASSERT_FALSE(exists(int_val, {{ArrayDimFetch, "key"}}));
    ASSERT_FALSE(exists(int_val, {{PropertyFetch, "prop"}}));

    var bool_val = true;
    ASSERT_FALSE(exists(bool_val, {{ArrayDimFetch, "key"}}));
    ASSERT_FALSE(exists(bool_val, {{PropertyFetch, "prop"}}));
}

TEST(exists, comparison_with_empty) {
    Array arr;
    arr.set("exists_empty", "");
    arr.set("exists_zero", 0);
    arr.set("exists_false", false);
    arr.set("exists_null", nullptr);
    arr.set("exists_value", "hello");

    Variant v = arr;

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "exists_empty"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "exists_zero"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "exists_false"}}));  // false -> true
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "exists_null"}}));  // null -> false
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "exists_value"}}));
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "not_exists"}}));
}

TEST(exists, string_offset_access) {
    var v = "hello";

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, 0}}));
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, 4}}));
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, -1}}));
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, 100}}));
}

TEST(exists, special_key_names) {
    Array arr;

    arr.set("", "empty_key_value");

    arr.set("key with spaces", "space_value");

    arr.set("key\nwith\nnewlines", "newline_value");
    arr.set("key\twith\ttabs", "tab_value");
    arr.set("key!@#$%^&*()", "special_chars");

    arr.set("键名", "chinese_value");
    arr.set("🔑", "emoji_value");

    Variant v = arr;

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, ""}}));

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "key with spaces"}}));

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "key\nwith\nnewlines"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "key\twith\ttabs"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "key!@#$%^&*()"}}));

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "键名"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "🔑"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, " "}}));
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "\n"}}));
}

TEST(exists, float_keys) {
    Array arr;

    arr.set(1, "int_one");
    arr.set(2, "int_two");

    Variant v = arr;

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 1.0}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 1.9}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 2.0}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 2.1}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, 3.0}}));
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, 0.5}}));
}

TEST(exists, negative_indices) {
    Array arr;
    arr.set(0, "zero");
    arr.set(1, "one");
    arr.set(-1, "negative_one");
    arr.set(-5, "negative_five");

    Variant v = arr;

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 0}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 1}}));

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, -1}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, -5}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, -2}}));
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, -100}}));
}

TEST(exists, boundary_values) {
    Array arr;

    arr.set(0, "zero");
    arr.set(1000000, "million");
    arr.set(LONG_MAX, "max_long");

    Variant v = arr;

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 0}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 1000000}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, LONG_MAX}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, 999999}}));
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, LONG_MAX - 1}}));
}

TEST(exists, very_deep_nesting) {
    auto level6_obj = newObject("stdClass");
    level6_obj.set("level6_value", "deep_value");

    auto level5_obj = newObject("stdClass");
    level5_obj.set("level6", level6_obj);

    Array level4_arr;
    level4_arr.set("level5", level5_obj);

    auto level3_obj = newObject("stdClass");
    level3_obj.set("level4", level4_arr);

    Array level2_arr;
    level2_arr.set("level3", level3_obj);

    Array level1_arr;
    level1_arr.set("level2", level2_arr);

    Variant v = level1_arr;

    ASSERT_TRUE(exists(v,
                       {{ArrayDimFetch, "level2"},
                        {ArrayDimFetch, "level3"},
                        {PropertyFetch, "level4"},
                        {ArrayDimFetch, "level5"},
                        {PropertyFetch, "level6"},
                        {PropertyFetch, "level6_value"}}));

    ASSERT_FALSE(exists(v,
                        {{ArrayDimFetch, "level2"},
                         {ArrayDimFetch, "level3"},
                         {PropertyFetch, "level4"},
                         {ArrayDimFetch, "nonexistent"},
                         {PropertyFetch, "level6"},
                         {PropertyFetch, "level6_value"}}));

    ASSERT_FALSE(exists(v,
                        {{ArrayDimFetch, "level2"},
                         {ArrayDimFetch, "level3"},
                         {PropertyFetch, "level4"},
                         {ArrayDimFetch, "level5"},
                         {PropertyFetch, "level6"},
                         {PropertyFetch, "nonexistent"}}));
}

TEST(exists, complex_mixed_paths) {
    Array innermost_arr;
    innermost_arr.set("final_key", "final_value");
    innermost_arr.set("empty_final", "");
    innermost_arr.set("null_final", nullptr);

    auto obj2 = newObject("stdClass");
    obj2.set("inner_arr", innermost_arr);

    Array mid_arr;
    mid_arr.set("obj2", obj2);
    mid_arr.set("direct_value", 123);

    auto obj1 = newObject("stdClass");
    obj1.set("mid_arr", mid_arr);

    Array outer_arr;
    outer_arr.set("obj1", obj1);

    Variant v = outer_arr;

    ASSERT_TRUE(exists(v,
                       {{ArrayDimFetch, "obj1"},
                        {PropertyFetch, "mid_arr"},
                        {ArrayDimFetch, "obj2"},
                        {PropertyFetch, "inner_arr"},
                        {ArrayDimFetch, "final_key"}}));

    ASSERT_TRUE(exists(v,
                       {{ArrayDimFetch, "obj1"},
                        {PropertyFetch, "mid_arr"},
                        {ArrayDimFetch, "obj2"},
                        {PropertyFetch, "inner_arr"},
                        {ArrayDimFetch, "empty_final"}}));

    ASSERT_FALSE(exists(v,
                        {{ArrayDimFetch, "obj1"},
                         {PropertyFetch, "mid_arr"},
                         {ArrayDimFetch, "obj2"},
                         {PropertyFetch, "inner_arr"},
                         {ArrayDimFetch, "null_final"}}));

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "obj1"}, {PropertyFetch, "mid_arr"}, {ArrayDimFetch, "direct_value"}}));
}

TEST(exists, array_with_various_types) {
    Array arr;
    arr.set("string", "value");
    arr.set("int", 42);
    arr.set("float", 3.14);
    arr.set("bool_true", true);
    arr.set("bool_false", false);
    arr.set("null", nullptr);
    arr.set("array", Array{});
    arr.set("object", newObject("stdClass"));

    Variant v = arr;

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "string"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "int"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "float"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "bool_true"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "bool_false"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "array"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "object"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "null"}}));
}

TEST(exists, object_with_various_types) {
    auto obj = newObject("stdClass");
    obj.set("string", "value");
    obj.set("int", 42);
    obj.set("float", 3.14);
    obj.set("bool_true", true);
    obj.set("bool_false", false);
    obj.set("null", nullptr);
    obj.set("array", Array{});
    obj.set("object", newObject("stdClass"));

    Variant v = obj;

    ASSERT_TRUE(exists(v, {{PropertyFetch, "string"}}));
    ASSERT_TRUE(exists(v, {{PropertyFetch, "int"}}));
    ASSERT_TRUE(exists(v, {{PropertyFetch, "float"}}));
    ASSERT_TRUE(exists(v, {{PropertyFetch, "bool_true"}}));
    ASSERT_TRUE(exists(v, {{PropertyFetch, "bool_false"}}));
    ASSERT_TRUE(exists(v, {{PropertyFetch, "array"}}));
    ASSERT_TRUE(exists(v, {{PropertyFetch, "object"}}));

    ASSERT_FALSE(exists(v, {{PropertyFetch, "null"}}));
}

TEST(exists, wrong_operation_order) {
    Array arr;
    arr.set("key", "value");
    var v1 = arr;
    ASSERT_FALSE(exists(v1, {{PropertyFetch, "key"}}));

    auto obj = newObject("stdClass");
    obj.set("prop", "value");
    var v2 = obj;
    ASSERT_FALSE(exists(v2, {{ArrayDimFetch, "prop"}}));

    var v3 = 123;
    ASSERT_FALSE(exists(v3, {{ArrayDimFetch, "key"}, {PropertyFetch, "prop"}}));

    var v4 = "string";
    ASSERT_FALSE(exists(v4, {{PropertyFetch, "prop"}, {ArrayDimFetch, "key"}}));
}

TEST(exists, empty_containers_nested_access) {
    Array empty_arr;
    var v1 = empty_arr;
    ASSERT_FALSE(exists(v1, {{ArrayDimFetch, "key1"}, {ArrayDimFetch, "key2"}}));

    auto empty_obj = newObject("stdClass");
    var v2 = empty_obj;
    ASSERT_FALSE(exists(v2, {{PropertyFetch, "prop1"}, {PropertyFetch, "prop2"}}));

    Array outer;
    outer.set("inner", Array{});
    var v3 = outer;
    ASSERT_TRUE(exists(v3, {{ArrayDimFetch, "inner"}}));
    ASSERT_FALSE(exists(v3, {{ArrayDimFetch, "inner"}, {ArrayDimFetch, "key"}}));
}

TEST(exists, numeric_string_vs_int_keys) {
    Array arr;

    arr.set(0, "int_zero");
    arr.set(1, "int_one");
    arr.set(42, "int_42");

    arr.set("100", "string_100");
    arr.set("0x", "string_0x");

    Variant v = arr;

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 0}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 1}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 42}}));

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "0"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "1"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "42"}}));

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "100"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 100}}));

    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "0x"}}));

    ASSERT_FALSE(exists(v, {{ArrayDimFetch, 999}}));
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "99"}}));
}
