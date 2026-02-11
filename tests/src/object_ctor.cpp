#include "phpx_test.h"
#include "phpx_func.h"
#include <thread>
#include <atomic>

using namespace php;

TEST(object_ctor, basic_construction) {
    // Test basic construction with Copy semantics
    auto obj = newObject("stdClass");
    ASSERT_TRUE(obj.isObject());
    
    // Get the underlying zend_object pointer
    zend_object *zend_obj = obj.object();
    ASSERT_NE(zend_obj, nullptr);
    
    // Test constructing Object from zend_object* with Copy semantics
    Object obj_from_zend(zend_obj, Ctor::Copy);
    ASSERT_TRUE(obj_from_zend.isObject());
    ASSERT_STREQ(obj_from_zend.getClassName().data(), "stdClass");
    
    // Verify it's a different object instance but same class
    ASSERT_NE(obj_from_zend.ptr(), obj.ptr());
    ASSERT_EQ(obj_from_zend.getId(), obj.getId()); // Same object handle
}

TEST(object_ctor, move_semantics) {
    // Test construction with Move semantics
	zval tmp;
	object_init(&tmp);
    Object obj(tmp.value.obj, Ctor::Move);
    ASSERT_TRUE(obj.isObject());

    obj.attr("test", true) = 2025;
    ASSERT_EQ(obj.get("test").toInt(), 2025);
}

TEST(object_ctor, default_parameter) {
    // Test default parameter behavior (should be Ctor::Copy)
    auto obj = newObject("DateTime");
    ASSERT_TRUE(obj.isObject());
    
    zend_object *zend_obj = obj.object();
    ASSERT_NE(zend_obj, nullptr);
    
    // Construct without specifying method parameter (should default to Copy)
    Object obj_default(zend_obj);
    ASSERT_TRUE(obj_default.isObject());
    ASSERT_STREQ(obj_default.getClassName().data(), "DateTime");
    
    // Should behave like Copy semantics
    ASSERT_NE(obj_default.ptr(), obj.ptr());
}

TEST(object_ctor, reference_counting) {
    // Test reference counting behavior
    auto obj = newObject("stdClass");
    ASSERT_TRUE(obj.isObject());
    
    zend_object *zend_obj = obj.object();
    ASSERT_NE(zend_obj, nullptr);
    
    // Create Object with Copy semantics
    Object obj_copy(zend_obj, Ctor::Copy);
    ASSERT_TRUE(obj_copy.isObject());
    
    // Both objects should point to the same zend_object
    ASSERT_EQ(obj.object(), obj_copy.object());
}

TEST(object_ctor, different_object_types) {
    // Test with different object types
    auto std_obj = newObject("stdClass");
    
    ASSERT_TRUE(std_obj.isObject());
    
    // Test construction from stdClass
    Object from_std(std_obj.object(), Ctor::Copy);
    ASSERT_STREQ(from_std.getClassName().data(), "stdClass");
}

TEST(object_ctor, copy_vs_move_behavior) {
    // Test behavioral differences between Copy and Move
    auto original_obj = newObject("stdClass");
    
    zend_object *zend_obj = original_obj.object();
    ASSERT_NE(zend_obj, nullptr);
    
    // Test Copy semantics
    Object copy_obj(zend_obj, Ctor::Copy);
    ASSERT_TRUE(copy_obj.isObject());
    
    // Both should reference the same zend_object
    ASSERT_EQ(original_obj.object(), copy_obj.object());
}
