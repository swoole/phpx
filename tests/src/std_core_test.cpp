#include "phpx_test.h"
#include "phpx_std.h"

using namespace php;

TEST(std_core, function_exists) {
    ASSERT_TRUE(fn::function_exists("php_uname"));
    ASSERT_FALSE(fn::function_exists("func_not_exists"));
    ASSERT_TRUE(fn::function_exists("php_uname", true));
    ASSERT_TRUE(fn::function_exists("\\php_uname"));
    ASSERT_TRUE(fn::function_exists("PHP_UNAME"));
}

TEST(std_core, strcmp) {
    ASSERT_EQ(fn::strcmp("hello", "hello"), 0);
    ASSERT_EQ(fn::strcmp("abc", "abd"), -1);
    ASSERT_EQ(fn::strcmp("abd", "abc"), 1);
    ASSERT_GT(fn::strcmp("z", "a"), 0);
    ASSERT_LT(fn::strcmp("a", "z"), 0);
}

TEST(std_core, strcasecmp) {
    ASSERT_EQ(fn::strcasecmp("hello", "HELLO"), 0);
    ASSERT_EQ(fn::strcasecmp("Hello", "hello"), 0);
    ASSERT_GT(fn::strcasecmp("B", "a"), 0);
}

TEST(std_core, strncmp) {
    ASSERT_EQ(fn::strncmp("abcdef", "abcxyz", 3), 0);
    ASSERT_LT(fn::strncmp("abcdef", "abcxyz", 4), 0);
    ASSERT_EQ(fn::strncmp("abc", "abd", 2), 0);
}

TEST(std_core, strncmp_exception) {
    try_call([]() { fn::strncmp("a", "b", -1); },
             "strncmp(): Argument #3 ($length) must be greater than or equal to 0");
}

TEST(std_core, strncasecmp) {
    ASSERT_EQ(fn::strncasecmp("ABCDEF", "abcxyz", 3), 0);
    ASSERT_LT(fn::strncasecmp("ABCDEF", "abcxyz", 4), 0);
}

TEST(std_core, strncasecmp_exception) {
    try_call([]() { fn::strncasecmp("a", "b", -1); },
             "strncasecmp(): Argument #3 ($length) must be greater than or equal to 0");
}

TEST(std_core, class_exists) {
    ASSERT_TRUE(fn::class_exists("ArrayObject"));
    ASSERT_TRUE(fn::class_exists("stdClass"));
    ASSERT_FALSE(fn::class_exists("ClassThatDoesNotExist"));
    ASSERT_FALSE(fn::class_exists("ClassThatDoesNotExist", false));
}

TEST(std_core, interface_exists) {
    ASSERT_TRUE(fn::interface_exists("Countable"));
    ASSERT_TRUE(fn::interface_exists("Iterator"));
    ASSERT_FALSE(fn::interface_exists("InterfaceThatDoesNotExist"));
}

TEST(std_core, trait_exists) {
    ASSERT_FALSE(fn::trait_exists("ArrayObject"));
    ASSERT_FALSE(fn::trait_exists("TraitThatDoesNotExist"));
}

TEST(std_core, method_exists) {
    var obj = newObject("ArrayObject");
    ASSERT_TRUE(fn::method_exists(obj, "count"));
    ASSERT_TRUE(fn::method_exists(obj, "offsetSet"));
    ASSERT_FALSE(fn::method_exists(obj, "nonexistentMethod"));
}

TEST(std_core, property_exists) {
    Object obj = newObject("stdClass");
    obj.setProperty("foo", "bar");
    ASSERT_TRUE(fn::property_exists(obj, "foo"));
    ASSERT_FALSE(fn::property_exists(obj, "baz"));
}

TEST(std_core, is_a) {
    var obj = newObject("ArrayObject");
    ASSERT_TRUE(fn::is_a(obj, "ArrayObject"));
    ASSERT_TRUE(fn::is_a(obj, "IteratorAggregate"));
    ASSERT_FALSE(fn::is_a(obj, "stdClass"));
    ASSERT_TRUE(fn::is_a("ArrayObject", "ArrayObject", true));
}

TEST(std_core, is_subclass_of) {
    // A class is not a subclass of itself
    ASSERT_FALSE(fn::is_subclass_of("ArrayObject", "ArrayObject"));
    ASSERT_FALSE(fn::is_subclass_of("stdClass", "ArrayObject"));
}

TEST(std_core, defined) {
    ASSERT_TRUE(fn::defined("PHP_VERSION"));
    ASSERT_TRUE(fn::defined("PHP_INT_MAX"));
    ASSERT_FALSE(fn::defined("NOT_A_REAL_CONSTANT"));
}

TEST(std_core, define) {
    ASSERT_TRUE(fn::define("MY_TEST_CONSTANT_123", 42));
    ASSERT_TRUE(fn::defined("MY_TEST_CONSTANT_123"));
}

TEST(std_core, define_array) {
    // Simple array constant (exercises _validate_constant_array and _copy_constant_array)
    Array arr;
    arr.set(Variant(0), "a");
    arr.set(Variant(1), "b");
    ASSERT_TRUE(fn::define("MY_TEST_ARR_1", arr));
    ASSERT_TRUE(fn::defined("MY_TEST_ARR_1"));

    // Nested array constant
    Array nested;
    nested.set(Variant(0), arr);
    ASSERT_TRUE(fn::define("MY_TEST_ARR_2", nested));
    ASSERT_TRUE(fn::defined("MY_TEST_ARR_2"));
}

TEST(std_core, gettype) {
    auto t1 = fn::gettype(42);
    ASSERT_STREQ(t1.toCString(), "integer");

    auto t2 = fn::gettype("hello");
    ASSERT_STREQ(t2.toCString(), "string");

    auto t3 = fn::gettype(3.14);
    ASSERT_STREQ(t3.toCString(), "double");

    auto t4 = fn::gettype(true);
    ASSERT_STREQ(t4.toCString(), "boolean");

    auto t5 = fn::gettype(Array{});
    ASSERT_STREQ(t5.toCString(), "array");
}

// Type checking functions
TEST(std_core, is_array) {
    ASSERT_TRUE(fn::is_array(Array{1, 2, 3}));
    ASSERT_FALSE(fn::is_array("not an array"));
    ASSERT_FALSE(fn::is_array(42));
}

TEST(std_core, is_string) {
    ASSERT_TRUE(fn::is_string("hello"));
    ASSERT_FALSE(fn::is_string(42));
    ASSERT_FALSE(fn::is_string(Array{}));
}

TEST(std_core, is_object) {
    var obj = newObject("stdClass");
    ASSERT_TRUE(fn::is_object(obj));
    ASSERT_FALSE(fn::is_object("not object"));
    ASSERT_FALSE(fn::is_object(Array{}));
}

TEST(std_core, is_int) {
    ASSERT_TRUE(fn::is_int(42));
    ASSERT_TRUE(fn::is_int(-100));
    ASSERT_FALSE(fn::is_int(3.14));
    ASSERT_FALSE(fn::is_int("42"));
}

TEST(std_core, is_bool) {
    ASSERT_TRUE(fn::is_bool(true));
    ASSERT_TRUE(fn::is_bool(false));
    ASSERT_FALSE(fn::is_bool(1));
    ASSERT_FALSE(fn::is_bool(0));
}

TEST(std_core, is_float) {
    ASSERT_TRUE(fn::is_float(3.14));
    ASSERT_TRUE(fn::is_float(-0.5));
    ASSERT_FALSE(fn::is_float(42));
    ASSERT_FALSE(fn::is_float("3.14"));
}

TEST(std_core, is_scalar) {
    ASSERT_TRUE(fn::is_scalar(42));
    ASSERT_TRUE(fn::is_scalar("hello"));
    ASSERT_TRUE(fn::is_scalar(3.14));
    ASSERT_TRUE(fn::is_scalar(true));
    ASSERT_FALSE(fn::is_scalar(Array{}));
    ASSERT_FALSE(fn::is_scalar(nullptr));
}

TEST(std_core, is_countable) {
    ASSERT_TRUE(fn::is_countable(Array{1, 2}));
    ASSERT_FALSE(fn::is_countable(42));
    auto obj = newObject("ArrayObject");
    ASSERT_TRUE(fn::is_countable(obj));
}

TEST(std_core, is_null) {
    ASSERT_TRUE(fn::is_null(nullptr));
    ASSERT_TRUE(fn::is_null(null));
    ASSERT_FALSE(fn::is_null(0));
    ASSERT_FALSE(fn::is_null(""));
    ASSERT_FALSE(fn::is_null(false));
}

TEST(std_core, is_iterable) {
    ASSERT_TRUE(fn::is_iterable(Array{1, 2}));
    ASSERT_FALSE(fn::is_iterable(42));
    auto obj = newObject("ArrayObject");
    ASSERT_TRUE(fn::is_iterable(obj));
}

TEST(std_core, is_numeric) {
    ASSERT_TRUE(fn::is_numeric(42));
    ASSERT_TRUE(fn::is_numeric(3.14));
    ASSERT_TRUE(fn::is_numeric("42"));
    ASSERT_TRUE(fn::is_numeric("3.14"));
    ASSERT_TRUE(fn::is_numeric("-10"));
    ASSERT_FALSE(fn::is_numeric("hello"));
    ASSERT_FALSE(fn::is_numeric(Array{}));
    ASSERT_FALSE(fn::is_numeric(true));
}

TEST(std_core, is_callable) {
    ASSERT_TRUE(fn::is_callable("php_uname"));
    ASSERT_FALSE(fn::is_callable("not_a_function"));
    ASSERT_TRUE(fn::is_callable("php_uname", true));
    // syntax_only=true only checks syntax; any valid function name passes
    ASSERT_TRUE(fn::is_callable("not_a_function", true));
}

TEST(std_core, get_class_fn) {
    Object obj = newObject("ArrayObject");
    auto cls = fn::get_class(obj);
    ASSERT_STREQ(cls.toCString(), "ArrayObject");
}

TEST(std_core, enum_exists) {
    // Non-enum classes
    ASSERT_FALSE(fn::enum_exists("ArrayObject"));
    ASSERT_FALSE(fn::enum_exists("stdClass"));
    // Non-existent name
    ASSERT_FALSE(fn::enum_exists("NoSuchEnum"));
    // Without autoload
    ASSERT_FALSE(fn::enum_exists("NoSuchEnum", false));
}

TEST(std_core, get_parent_class) {
    // String class name: class with parent
    auto parent1 = fn::get_parent_class("RuntimeException");
    ASSERT_TRUE(parent1.isString());
    ASSERT_STREQ(parent1.toString().toCString(), "Exception");

    // String class name: class without parent
    auto parent2 = fn::get_parent_class("Exception");
    ASSERT_TRUE(parent2.isFalse());

    // Object
    Object obj = newObject("RuntimeException");
    auto parent3 = fn::get_parent_class(obj);
    ASSERT_TRUE(parent3.isString());
    ASSERT_STREQ(parent3.toString().toCString(), "Exception");

    // Class without parent via string
    auto parent4 = fn::get_parent_class("stdClass");
    ASSERT_TRUE(parent4.isFalse());
}
