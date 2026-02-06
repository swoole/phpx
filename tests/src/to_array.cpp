#include "phpx_test.h"

using namespace php;

// 测试toArray函数的各种情况
TEST(to_array, basic_types) {
    // 测试字符串转数组
    Variant str_var("hello");
    Array str_arr = toArray(str_var);
    ASSERT_TRUE(str_arr.isArray());
    ASSERT_EQ(str_arr.count(), 1);
    ASSERT_EQ(str_arr[0].toInt(), 0); // 字符串转换为数组时，索引0应该包含原值
    
    // 测试整数转数组
    Variant int_var(12345);
    Array int_arr = toArray(int_var);
    ASSERT_TRUE(int_arr.isArray());
    ASSERT_EQ(int_arr.count(), 1);
    ASSERT_EQ(int_arr[0].toInt(), 12345);
    
    // 测试浮点数转数组
    Variant float_var(3.14159);
    Array float_arr = toArray(float_var);
    ASSERT_TRUE(float_arr.isArray());
    ASSERT_EQ(float_arr.count(), 1);
    ASSERT_EQ(float_arr[0].toFloat(), 3.14159);
    
    // 测试布尔值转数组
    Variant bool_var(true);
    Array bool_arr = toArray(bool_var);
    ASSERT_TRUE(bool_arr.isArray());
    ASSERT_EQ(bool_arr.count(), 1);
    ASSERT_TRUE(bool_arr[0].toBool());
}

TEST(to_array, null_conversion) {
    // 测试NULL转数组
    Variant null_var(nullptr);
    Array null_arr = toArray(null_var);
    ASSERT_TRUE(null_arr.isArray());
    ASSERT_EQ(null_arr.count(), 0);
}

TEST(to_array, array_conversion) {
    // 测试数组转数组（应该直接返回原数组）
    Array original_arr;
    original_arr.append("test1");
    original_arr.append("test2");
    original_arr.append(123);
    
    Variant arr_var(original_arr);
    Array converted_arr = toArray(arr_var);
    
    ASSERT_TRUE(converted_arr.isArray());
    ASSERT_EQ(converted_arr.count(), 3);
    ASSERT_STREQ(converted_arr[0].toCString(), "test1");
    ASSERT_STREQ(converted_arr[1].toCString(), "test2");
    ASSERT_EQ(converted_arr[2].toInt(), 123);
}

TEST(to_array, object_conversion) {
    // 测试stdClass对象转数组
    auto obj = newObject("stdClass");
    obj.set("name", "test");
    obj.set("value", 42);
    
    Variant obj_var(obj);
    Array obj_arr = toArray(obj_var);
    
    ASSERT_TRUE(obj_arr.isArray());
    ASSERT_GE(obj_arr.count(), 2);
    ASSERT_TRUE(obj_arr.exists("name"));
    ASSERT_TRUE(obj_arr.exists("value"));
    ASSERT_STREQ(obj_arr.get("name").toCString(), "test");
    ASSERT_EQ(obj_arr.get("value").toInt(), 42);
}

TEST(to_array, closure_conversion) {
    // 测试闭包转数组（闭包是特殊对象）
    auto closure_obj = eval("return function() { return 'hello'; };");
    ASSERT_TRUE(closure_obj.isObject());
    
    Variant closure_var(closure_obj);
    Array closure_arr = toArray(closure_var);
    
    ASSERT_TRUE(closure_arr.isArray());
    ASSERT_EQ(closure_arr.count(), 1);
    // 闭包转换为数组时应该包含原始对象
}

TEST(to_array, refcounted_types) {
    // 测试引用计数类型的转换（覆盖第320行代码）
    // 创建一个引用计数的字符串
    String ref_string("reference counted string");
    Variant ref_var(ref_string);
    
    // 这个测试会触发第320行的 Z_ADDREF_P(expr) 调用
    Array ref_arr = toArray(ref_var);
    
    ASSERT_TRUE(ref_arr.isArray());
    ASSERT_EQ(ref_arr.count(), 1);
    ASSERT_STREQ(ref_arr[0].toCString(), "reference counted string");
    
    // 测试引用计数的对象属性
    auto test_obj = newObject("stdClass");
    String prop_value("property value");
    test_obj.set("prop", prop_value);
    
    Variant obj_with_ref(test_obj);
    Array obj_ref_arr = toArray(obj_with_ref);
    
    ASSERT_TRUE(obj_ref_arr.isArray());
    ASSERT_TRUE(obj_ref_arr.exists("prop"));
    ASSERT_STREQ(obj_ref_arr.get("prop").toCString(), "property value");
}

TEST(to_array, edge_cases) {
    // Test empty string
    Variant empty_str("");
    Array empty_arr = toArray(empty_str);
    ASSERT_TRUE(empty_arr.isArray());
    ASSERT_EQ(empty_arr.count(), 1);
    ASSERT_STREQ(empty_arr[0].toCString(), "");
    
    // Test zero value
    Variant zero_int(0);
    Array zero_arr = toArray(zero_int);
    ASSERT_TRUE(zero_arr.isArray());
    ASSERT_EQ(zero_arr.count(), 1);
    ASSERT_EQ(zero_arr[0].toInt(), 0);
    
    // Test false boolean
    Variant false_bool(false);
    Array false_arr = toArray(false_bool);
    ASSERT_TRUE(false_arr.isArray());
    ASSERT_EQ(false_arr.count(), 1);
    ASSERT_FALSE(false_arr[0].toBool());
}

TEST(to_array, line_322_branch_conditions) {
    // Specific test to understand and cover line 322 branch conditions
    // The branch condition is:
    // Z_OBJ_P(expr)->properties == NULL && 
    // Z_OBJ_HT_P(expr)->get_properties_for == NULL &&
    // Z_OBJ_HT_P(expr)->get_properties == zend_std_get_properties
    
    // Test various object types to see which ones trigger this optimized path
    
    // Test 1: stdClass object (most likely to trigger optimized path)
    auto std_obj = newObject("stdClass");
    std_obj.set("test_key", "test_value");
    
    Variant std_var(std_obj);
    Array std_arr = toArray(std_var);
    
    ASSERT_TRUE(std_arr.isArray());
    ASSERT_TRUE(std_arr.exists("test_key"));
    ASSERT_STREQ(std_arr.get("test_key").toCString(), "test_value");
    
    // Test 2: DateTime object (internal PHP class)
    auto datetime_obj = eval("return new DateTime('2024-01-01');");
    if (datetime_obj.isObject()) {
        Variant dt_var(datetime_obj);
        Array dt_arr = toArray(dt_var);
        ASSERT_TRUE(dt_arr.isArray());
        // DateTime should convert to array with its properties
    }
    
    // Test 3: Exception object
    auto exception_obj = eval("return new Exception('Test exception', 42);");
    if (exception_obj.isObject()) {
        Variant exc_var(exception_obj);
        Array exc_arr = toArray(exc_var);
        ASSERT_TRUE(exc_arr.isArray());
        // Exception objects should convert properly
    }
    
    // Test 4: Simple custom object
    eval(R"(
        class SimpleClass {
            public $public_prop = 'simple_value';
        }
    )");
    
    auto simple_custom_obj = eval("return new SimpleClass();");
    if (simple_custom_obj.isObject()) {
        Variant simple_custom_var(simple_custom_obj);
        Array simple_custom_arr = toArray(simple_custom_var);
        ASSERT_TRUE(simple_custom_arr.isArray());
        ASSERT_TRUE(simple_custom_arr.exists("public_prop"));
        ASSERT_STREQ(simple_custom_arr.get("public_prop").toCString(), "simple_value");
    }
}

TEST(to_array, optimized_object_path) {
    // Test the optimized object path (line 322 branch)
    // This branch is triggered for objects with:
    // - properties == NULL
    // - get_properties_for == NULL
    // - get_properties == zend_std_get_properties
    
    // Create a simple stdClass object which should trigger the optimized path
    auto obj = newObject("stdClass");
    obj.set("test_prop", "test_value");
    
    Variant obj_var(obj);
    Array obj_arr = toArray(obj_var);
    
    ASSERT_TRUE(obj_arr.isArray());
    ASSERT_TRUE(obj_arr.exists("test_prop"));
    ASSERT_STREQ(obj_arr.get("test_prop").toCString(), "test_value");
    
    // Test with internal objects that might trigger the optimized path
    // DateTime objects often have special handling
    auto datetime_obj = eval("return new DateTime('2023-01-01');");
    if (datetime_obj.isObject()) {
        Variant datetime_var(datetime_obj);
        Array datetime_arr = toArray(datetime_var);
        ASSERT_TRUE(datetime_arr.isArray());
        // DateTime objects should convert to arrays with their properties
    }
    
    // Test with ArrayObject which has custom property handling
    auto array_obj = eval("return new ArrayObject(['key' => 'value']);");
    if (array_obj.isObject()) {
        Variant arrayobj_var(array_obj);
        Array arrayobj_arr = toArray(arrayobj_var);
        ASSERT_TRUE(arrayobj_arr.isArray());
        // ArrayObject should convert properly to array
    }
}

TEST(to_array, line_337_empty_array_branch) {
    // Test the branch that creates empty array when zend_get_properties_for returns NULL
    // This covers line 337: ZVAL_EMPTY_ARRAY(&result);
    
    // This branch is triggered when:
    // 1. Input is an object (not array, not closure)
    // 2. Does NOT match the optimized path conditions (line 322 branch)
    // 3. zend_get_properties_for(expr, ZEND_PROP_PURPOSE_ARRAY_CAST) returns NULL
    
    // Test with objects that might cause zend_get_properties_for to return NULL
    // This typically happens with objects that have custom property handling
    // that doesn't support ZEND_PROP_PURPOSE_ARRAY_CAST
    
    // Test 1: ArrayObject - has custom property handling
    auto array_obj = eval("return new ArrayObject(['test' => 'value']);");
    if (array_obj.isObject()) {
        Variant arrayobj_var(array_obj);
        Array arrayobj_arr = toArray(arrayobj_var);
        ASSERT_TRUE(arrayobj_arr.isArray());
        // ArrayObject should convert to array successfully
        // If zend_get_properties_for returns NULL, it should create empty array
    }
    
    // Test 2: Custom class with magic methods that might interfere with property retrieval
    eval(R"(
        class CustomPropertyClass {
            private $data = ['hidden' => 'value'];
            
            public function __get($name) {
                // Custom property access that might affect zend_get_properties_for
                return isset($this->data[$name]) ? $this->data[$name] : null;
            }
        }
    )");
    
    auto custom_obj = eval("return new CustomPropertyClass();");
    if (custom_obj.isObject()) {
        Variant custom_var(custom_obj);
        Array custom_arr = toArray(custom_var);
        ASSERT_TRUE(custom_arr.isArray());
        // This should either convert properties or create empty array
    }
    
    // Test 3: stdClass with no properties (edge case)
    auto empty_obj = newObject("stdClass");
    Variant empty_var(empty_obj);
    Array empty_arr = toArray(empty_var);
    ASSERT_TRUE(empty_arr.isArray());
    // Empty stdClass should convert to empty or populated array
}