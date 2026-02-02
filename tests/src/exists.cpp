#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

// ==================== 基本功能测试 ====================

TEST(exists, basic_array_access) {
    // 测试基本数组元素存在性检查
    Array arr;
    arr.set("name", "John");
    arr.set("age", 25);
    arr.set("active", true);
    
    var v = arr;
    
    // 第一个设置的键能正确检测
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "name"}}));
    
    // 不存在的键应该返回 false
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "email"}}));
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "phone"}}));
}

TEST(exists, basic_object_property) {
    // 测试对象属性存在性检查
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);
    
    auto obj = newObject("TestClass");
    obj.set("dynamic_prop", "dynamic value");
    
    var v = obj;
    
    // 测试静态属性（应该不存在于实例中）
    ASSERT_FALSE(exists(v, {{PropertyFetch, "propInt"}}));
    ASSERT_FALSE(exists(v, {{PropertyFetch, "propString"}}));
    
    // 测试公共属性
    ASSERT_FALSE(exists(v, {{PropertyFetch, "propBool"}})); // protected 属性不可访问
    
    // 测试动态添加的属性
    ASSERT_TRUE(exists(v, {{PropertyFetch, "dynamic_prop"}}));
    
    // 测试不存在的属性
    ASSERT_FALSE(exists(v, {{PropertyFetch, "nonexistent"}}));
}

// ==================== 数组维度获取测试 ====================

TEST(exists, array_dim_fetch_basic) {
    // 测试基本数组访问
    Array arr;
    arr.set("key1", "value1");   // 存在且有值
    arr.set("key2", "");         // 存在但为空字符串
    arr.set("key3", 0);          // 存在但为0
    arr.set("key4", false);      // 存在但为false
    arr.set("key5", nullptr);    // 存在但为null

    Variant v = arr;

    // 存在的元素（包括空值）都应该返回true
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "key1"}}));  // 有值
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "key2"}}));  // 空字符串
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "key3"}}));  // 数字0
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "key4"}}));  // 布尔false

    // null值应该返回false
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "key5"}}));

    // 不存在的元素应该返回false
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "nonexistent"}}));
}

TEST(exists, array_dim_fetch_nested) {
    // 测试嵌套数组访问
    Array inner_arr;
    inner_arr.set("inner_key", "inner_value");
    inner_arr.set("empty_key", "");      // 空值但存在
    inner_arr.set("null_key", nullptr);  // null值

    Array outer_arr;
    outer_arr.set("nested", inner_arr);
    outer_arr.set("empty_nested", Array{});
    outer_arr.set("null_nested", nullptr);

    Variant v = outer_arr;

    // 访问存在的嵌套元素（包括空值）
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "nested"}, {ArrayDimFetch, "inner_key"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "nested"}, {ArrayDimFetch, "empty_key"}}));   // 空字符串

    // 访问null值应该返回false
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "nested"}, {ArrayDimFetch, "null_key"}}));

    // 访问空数组中的元素应该返回false
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "empty_nested"}, {ArrayDimFetch, "any_key"}}));

    // 访问null数组应该返回false
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "null_nested"}, {ArrayDimFetch, "any_key"}}));

    // 访问不存在的嵌套路径
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "nonexistent"}, {ArrayDimFetch, "key"}}));
}

TEST(exists, numeric_keys) {
    // 测试数字键的数组访问
    Array numeric_arr;
    numeric_arr.set(0, "first");
    numeric_arr.set(1, "");        // 空字符串
    numeric_arr.set(2, 0);         // 数字0
    numeric_arr.set(3, false);     // 布尔false
    numeric_arr.set(4, nullptr);   // null值

    Variant v = numeric_arr;

    // 存在的数字索引（包括空值）都应该返回true
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 0}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 1}}));  // 空字符串
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 2}}));  // 数字0
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, 3}}));  // false

    // null值应该返回false
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, 4}}));

    // 不存在的数字索引
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, 999}}));
}

TEST(exists, string_numeric_keys) {
    // 测试字符串形式的数字键
    Array mixed_arr;
    mixed_arr.set("0", "string_zero");
    mixed_arr.set("1", "");        // 空字符串
    mixed_arr.set("2", nullptr);   // null值

    Variant v = mixed_arr;

    // 字符串数字键（存在，包括空值）
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "0"}}));
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "1"}}));  // 空字符串

    // null值应该返回false
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "2"}}));

    // 实际数字键（应该找不到）
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, 0}}));
}

// ==================== 属性获取测试 ====================

TEST(exists, property_fetch_basic) {
    // 测试对象属性访问
    auto obj = newObject("stdClass");
    obj.set("prop1", "value1");   // 存在且有值
    obj.set("prop2", "");         // 存在但为空字符串
    obj.set("prop3", 0);          // 存在但为0
    obj.set("prop4", false);      // 存在但为false
    obj.set("prop5", nullptr);    // 存在但为null

    Variant v = obj;

    // 存在的属性（包括空值）都应该返回true
    ASSERT_TRUE(exists(v, {{PropertyFetch, "prop1"}}));
    ASSERT_TRUE(exists(v, {{PropertyFetch, "prop2"}}));  // 空字符串
    ASSERT_TRUE(exists(v, {{PropertyFetch, "prop3"}}));  // 数字0
    ASSERT_TRUE(exists(v, {{PropertyFetch, "prop4"}}));  // 布尔false

    // null值应该返回false
    ASSERT_FALSE(exists(v, {{PropertyFetch, "prop5"}}));

    // 不存在的属性应该返回false
    ASSERT_FALSE(exists(v, {{PropertyFetch, "nonexistent"}}));
}

TEST(exists, property_fetch_nested) {
    // 测试嵌套对象属性访问
    auto inner_obj = newObject("stdClass");
    inner_obj.set("inner_prop", "inner_value");
    inner_obj.set("empty_prop", "");      // 空值但存在
    inner_obj.set("null_prop", nullptr);  // null值

    auto outer_obj = newObject("stdClass");
    outer_obj.set("nested_obj", inner_obj);
    outer_obj.set("null_obj", nullptr);

    Variant v = outer_obj;

    // 访问存在的嵌套属性（包括空值）
    ASSERT_TRUE(exists(v, {{PropertyFetch, "nested_obj"}, {PropertyFetch, "inner_prop"}}));
    ASSERT_TRUE(exists(v, {{PropertyFetch, "nested_obj"}, {PropertyFetch, "empty_prop"}}));  // 空字符串

    // 访问null值应该返回false
    ASSERT_FALSE(exists(v, {{PropertyFetch, "nested_obj"}, {PropertyFetch, "null_prop"}}));

    // 访问null对象的属性应该返回false
    ASSERT_FALSE(exists(v, {{PropertyFetch, "null_obj"}, {PropertyFetch, "any_prop"}}));

    // 访问不存在的对象属性
    ASSERT_FALSE(exists(v, {{PropertyFetch, "nonexistent"}, {PropertyFetch, "prop"}}));
}

// ==================== 混合操作测试 ====================

TEST(exists, mixed_operations) {
    // 测试混合操作：数组中的对象属性
    auto obj = newObject("stdClass");
    obj.set("obj_prop", "object_value");
    obj.set("empty_prop", "");      // 空值但存在
    obj.set("null_prop", nullptr);  // null值

    Array arr;
    arr.set("object_key", obj);
    arr.set("regular_key", "array_value");
    arr.set("empty_key", "");        // 空值但存在
    arr.set("null_key", nullptr);    // null值
    arr.set("null_obj_key", nullptr);

    Variant v = arr;

    // 数组 -> 对象属性（存在且有值）
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "object_key"}, {PropertyFetch, "obj_prop"}}));

    // 数组 -> 对象属性（存在但值为空）
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "object_key"}, {PropertyFetch, "empty_prop"}}));  // 空字符串

    // 数组 -> 对象属性（null值）
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "object_key"}, {PropertyFetch, "null_prop"}}));

    // 直接数组访问（存在且有值）
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "regular_key"}}));

    // 直接数组访问（存在但值为空）
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "empty_key"}}));  // 空字符串

    // 直接数组访问（null值）
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "null_key"}}));

    // 访问null对象
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "null_obj_key"}, {PropertyFetch, "any_prop"}}));

    // 错误的访问顺序（对象 -> 数组）
    auto obj_v = Variant(obj);
    ASSERT_FALSE(exists(obj_v, {{ArrayDimFetch, "any_key"}})); // 对象不支持数组访问
}

TEST(exists, complex_chains) {
    // 测试复杂的访问链

    // 创建复杂的数据结构
    auto deep_obj = newObject("stdClass");
    deep_obj.set("level3_prop", "deep_value");
    deep_obj.set("empty_prop", "");      // 空值但存在
    deep_obj.set("null_prop", nullptr);  // null值

    auto mid_obj = newObject("stdClass");
    mid_obj.set("level2_obj", deep_obj);
    mid_obj.set("null_obj", nullptr);

    Array level1_arr;
    level1_arr.set("level1_obj", mid_obj);
    level1_arr.set("null_arr", nullptr);

    Variant v = level1_arr;

    // 成功的深度访问（有值）
    ASSERT_TRUE(exists(v, {
        {ArrayDimFetch, "level1_obj"},
        {PropertyFetch, "level2_obj"},
        {PropertyFetch, "level3_prop"}
    }));

    // 成功的深度访问（空值但存在）
    ASSERT_TRUE(exists(v, {
        {ArrayDimFetch, "level1_obj"},
        {PropertyFetch, "level2_obj"},
        {PropertyFetch, "empty_prop"}
    }));  // 空字符串

    // 访问null值应该返回false
    ASSERT_FALSE(exists(v, {
        {ArrayDimFetch, "level1_obj"},
        {PropertyFetch, "level2_obj"},
        {PropertyFetch, "null_prop"}
    }));

    // 访问null对象应该返回false
    ASSERT_FALSE(exists(v, {
        {ArrayDimFetch, "level1_obj"},
        {PropertyFetch, "null_obj"},
        {PropertyFetch, "any_prop"}
    }));

    // 访问null数组应该返回false
    ASSERT_FALSE(exists(v, {
        {ArrayDimFetch, "null_arr"},
        {PropertyFetch, "any_prop"}
    }));

    // 在中间层级失败
    ASSERT_FALSE(exists(v, {
        {ArrayDimFetch, "level1_obj"},
        {PropertyFetch, "level2_obj"},
        {PropertyFetch, "nonexistent_prop"}
    }));

    // 在起始层级失败
    ASSERT_FALSE(exists(v, {
        {ArrayDimFetch, "nonexistent_key"},
        {PropertyFetch, "any_prop"}
    }));
}

// ==================== 边界情况测试 ====================

TEST(exists, edge_cases) {
    // 测试边界情况
    
    // 空数组
    Array empty_arr;
    var v1 = empty_arr;
    ASSERT_FALSE(exists(v1, {{ArrayDimFetch, "any_key"}}));
    
    // 空对象
    auto empty_obj = newObject("stdClass");
    var v2 = empty_obj;
    ASSERT_FALSE(exists(v2, {{PropertyFetch, "any_prop"}}));
    
    // null 值
    var v3 = nullptr;
    ASSERT_FALSE(exists(v3, {{ArrayDimFetch, "any"}}));
    ASSERT_FALSE(exists(v3, {{PropertyFetch, "any"}}));
    
    // 字符串值（不支持数组或属性访问）
    var v4 = "test string";
    ASSERT_FALSE(exists(v4, {{ArrayDimFetch, "any"}}));
    ASSERT_FALSE(exists(v4, {{PropertyFetch, "any"}}));
    
    // 数字值
    var v5 = 42;
    ASSERT_FALSE(exists(v5, {{ArrayDimFetch, "any"}}));
    ASSERT_FALSE(exists(v5, {{PropertyFetch, "any"}}));
}

TEST(exists, type_mismatch_scenarios) {
    // 测试类型不匹配的情况
    
    // 尝试在非数组上进行数组访问
    var string_val = "hello";
    ASSERT_FALSE(exists(string_val, {{ArrayDimFetch, "key"}}));
    
    // 尝试在非对象上进行属性访问
    var array_val = create_map();
    ASSERT_FALSE(exists(array_val, {{PropertyFetch, "prop"}}));
    
    // 尝试在数字上进行访问
    var int_val = 123;
    ASSERT_FALSE(exists(int_val, {{ArrayDimFetch, "key"}}));
    ASSERT_FALSE(exists(int_val, {{PropertyFetch, "prop"}}));
    
    // 尝试在布尔值上进行访问
    var bool_val = true;
    ASSERT_FALSE(exists(bool_val, {{ArrayDimFetch, "key"}}));
    ASSERT_FALSE(exists(bool_val, {{PropertyFetch, "prop"}}));
}

// ==================== 对比测试 ====================

TEST(exists, comparison_with_empty) {
    Array arr;
    arr.set("exists_empty", "");     // 存在但为空
    arr.set("exists_zero", 0);       // 存在但为0
    arr.set("exists_false", false);  // 存在但为false
    arr.set("exists_null", nullptr); // 存在但为null
    arr.set("exists_value", "hello"); // 存在且有值
    // "not_exists" 不存在

    Variant v = arr;

    // exists: 只关心是否存在且不为null
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "exists_empty"}}));   // 空字符串 -> true
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "exists_zero"}}));    // 数字0 -> true
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "exists_false"}}));   // false -> true
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "exists_null"}}));   // null -> false
    ASSERT_TRUE(exists(v, {{ArrayDimFetch, "exists_value"}}));   // 有值 -> true
    ASSERT_FALSE(exists(v, {{ArrayDimFetch, "not_exists"}}));    // 不存在 -> false
}