#include "phpx_test.h"
#include "phpx_func.h"

using namespace php;

TEST(object, base) {
    auto array = create_map();
    auto object = newObject("ArrayObject", {array, constant("ArrayObject::ARRAY_AS_PROPS")});

    auto rand_num = random_int(1, 9999999).toInt();

    ASSERT_TRUE(object.isObject());
    ASSERT_EQ(object.get("php").toInt(), 3);

    object.set("php", rand_num);

    String str("php");
    ASSERT_EQ(ZSTR_H(str.ptr()), 0);
    ASSERT_EQ(object.get(str).toInt(), rand_num);
    ASSERT_NE(ZSTR_H(str.ptr()), 0);

    object.exec("offsetSet", {"python", 9});
    auto r2 = object.get("python");
    ASSERT_EQ(r2.toInt(), 9);

    auto flags = object.exec("getFlags");
    ASSERT_TRUE(flags.isInt());
    ASSERT_TRUE(flags.toInt() & constant("ArrayObject::ARRAY_AS_PROPS").toInt());
    flags.debug();

    auto o2 = newObject("class_not_exists");
    ASSERT_FALSE(o2.isUndef());

    auto o3 = newObject("class_not_exists", {1234, "hello world"});
    ASSERT_FALSE(o3.isUndef());

    Array arr3;
    arr3.append("hello world");
    object.set("test_array", arr3);
    ASSERT_TRUE(object.get("test_array").isArray());

    auto hash = object.hash();
    ASSERT_EQ(hash.length(), 32);
}

TEST(object, method) {
    auto obj = newObject("DateTimeImmutable");
    ASSERT_TRUE(obj.isObject());
    auto str = obj.exec("format", "Y-m-d H:i:s");
    ASSERT_TRUE(str.isString());
    ASSERT_GT(str.length(), 0);
}

TEST(object, static_property) {
    include(get_include_dir() + "/library.php");
    ASSERT_EQ(Class::getStaticProperty("TestClass", "propInt").toInt(), 1990018900);
    ASSERT_STREQ(Class::getStaticProperty("TestClass", "propString").toCString(), "Hello, World!");
    ASSERT_TRUE(Class::setStaticProperty("TestClass", "propString", "phpx test"));
    ASSERT_STREQ(Class::getStaticProperty("TestClass", "propString").toCString(), "phpx test");
}

TEST(object, call_parent_method) {
    if (!class_exists("TestClass2")) {
        include(get_include_dir() + "/library.php");
    }

    auto obj = newObject("TestClass2");
    ASSERT_TRUE(obj.methodExists("test"));
    ASSERT_FALSE(obj.methodExists("testNotExists"));

    ASSERT_TRUE(obj.propertyExists("propArray"));
    ASSERT_FALSE(obj.propertyExists("propNotExists"));
    ASSERT_TRUE(obj.propertyExists("propBool"));

    // This method inherits from the parent class and is not defined in the child class
    ASSERT_TRUE(obj.methodExists("fun"));
    auto rs0 = obj.exec("fun");
    ASSERT_TRUE(rs0.isFloat());

    auto rs1 = obj.exec("test");
    ASSERT_STREQ(rs1.toCString(), "child test");

    // The child class and parent class have methods with the same name
    auto rs2 = obj.callParentMethod("test", {"hello", "world"});
    ASSERT_STREQ(rs2.toCString(), "parent test");

    ASSERT_STREQ(obj.getClassName().data(), "TestClass2");
}

TEST(object, bad_type) {
    auto arr1 = create_list();
    ChildResult r = run_in_child_capture_stdout([&arr1]() -> int {
        auto v = arr1.get(2);
        Object o(v);
        return 0;
    });
    var s(r.output);
    ASSERT_TRUE(str_contains(s, "parameter 1 must be `object`, got `string`").toBool());
}

TEST(object, call_parent_method_error) {
    ChildResult r = run_in_child_capture_stdout([]() -> int {
        if (!class_exists("TestClass2")) {
            include(get_include_dir() + "/library.php");
        }
        auto obj = newObject("TestClass2");
        auto rs2 = obj.callParentMethod("test1990", {});
        return 0;
    });
    var s(r.output);
    ASSERT_TRUE(str_contains(s, "Couldn't find implementation for method").toBool());
}

TEST(object, static_property_error1) {
    ChildResult r = run_in_child_capture_stdout([]() -> int {
        Class::getStaticProperty("TestClassNotFound", "propInt");
        return 0;
    });
    var s(r.output);
    ASSERT_TRUE(str_contains(s, "class 'TestClassNotFound' is undefined.").toBool());
}

TEST(object, static_property_error2) {
    ChildResult r = run_in_child_capture_stdout([]() -> int {
        Class::setStaticProperty("TestClassNotFound", "propInt", 1990);
        return 0;
    });
    var s(r.output);
    ASSERT_TRUE(str_contains(s, "class 'TestClassNotFound' is undefined.").toBool());
}
