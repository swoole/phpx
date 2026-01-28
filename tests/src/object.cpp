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

    auto rs = object.get("notExistsProp");
    ASSERT_TRUE(rs.isNull());

    auto propObj = newObject("ArrayObject");
    propObj.set("key", "value");
    object.set("object", propObj);

    auto ro = object.get("object");
    ASSERT_TRUE(ro.isObject());

    String str("php");
    ASSERT_EQ(ZSTR_H(str.str()), 0);
    ASSERT_EQ(object.get(str).toInt(), rand_num);
    ASSERT_NE(ZSTR_H(str.str()), 0);

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

TEST(object, ctor) {
    auto o1 = newObject("ArrayObject");
    ASSERT_EQ(o1.type(), IS_OBJECT);
    o1.append("hello world");
    ASSERT_EQ(o1.length(), 1);

    auto m = create_map();
    auto o2 = newObject("ArrayObject", m);
    ASSERT_EQ(o2.offsetGet("php").toInt(), 3);
}

TEST(object, method) {
    auto obj = newObject("DateTimeImmutable");
    ASSERT_TRUE(obj.isObject());
    auto str = obj.exec("format", "Y-m-d H:i:s");
    ASSERT_TRUE(str.isString());
    ASSERT_GT(str.length(), 0);
}

TEST(object, static_property) {
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);
    ASSERT_EQ(getStaticProperty("TestClass", "propInt").toInt(), 1990018900);
    ASSERT_STREQ(getStaticProperty("TestClass", "propString").toCString(), "Hello, World!");
    ASSERT_TRUE(setStaticProperty("TestClass", "propString", "phpx test"));
    ASSERT_STREQ(getStaticProperty("TestClass", "propString").toCString(), "phpx test");

    ASSERT_TRUE(hasStaticProperty("TestClass", "propString"));
    ASSERT_FALSE(hasStaticProperty("TestClass", "propObject"));
}

TEST(object, call_parent_method) {
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);

    auto obj = newObject("TestClass2");
    ASSERT_TRUE(obj.methodExists("test"));
    ASSERT_FALSE(obj.methodExists("testNotExists"));

    ASSERT_TRUE(obj.propertyExists("propArray"));
    ASSERT_FALSE(obj.propertyExists("propNotExists"));
    ASSERT_TRUE(obj.propertyExists("propBool"));

    auto prop_offset = getPropertyOffset("TestClass2", "propArray");
    ASSERT_EQ(prop_offset, sizeof(zend_object));

    auto prop = obj.getPropertyIndirect(prop_offset);
    ASSERT_TRUE(prop.isArray());
    ASSERT_EQ(prop.length(), 5);

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

TEST(object, instanceOf) {
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);

    auto obj = newObject("TestClass2");
    ASSERT_TRUE(obj.instanceOf("TestClass"));
    ASSERT_TRUE(obj.instanceOf("TestClass2"));
    ASSERT_FALSE(obj.instanceOf("DateTimeImmutable"));

    auto obj2 = newObject("ArrayObject");
    ASSERT_TRUE(obj2.instanceOf(getClassEntry("ArrayObject")));
    ASSERT_TRUE(obj2.instanceOf(zend_ce_countable));
    ASSERT_TRUE(obj2.instanceOf(zend_ce_arrayaccess));
    ASSERT_FALSE(obj2.instanceOf(zend_ce_exception));
}

TEST(object, clone) {
    auto o1 = newObject("stdClass");
    o1.set("prop1", 1990);
    ASSERT_TRUE(o1.get("prop1").equals(1990));

    auto o2 = o1;
    o1.set("prop1", 2019);
    ASSERT_TRUE(o2.get("prop1").equals(2019));

    auto o3 = o1.clone();
    o1.set("prop1", 2024);
    ASSERT_TRUE(o3.get("prop1").equals(2019));
    ASSERT_TRUE(o1.get("prop1").equals(2024));
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
        getStaticProperty("TestClassNotFound", "propInt");
        return 0;
    });
    var s(r.output);
    ASSERT_TRUE(str_contains(s, "class 'TestClassNotFound' is undefined.").toBool());
}

TEST(object, static_property_error2) {
    ChildResult r = run_in_child_capture_stdout([]() -> int {
        setStaticProperty("TestClassNotFound", "propInt", 1990);
        return 0;
    });
    var s(r.output);
    ASSERT_TRUE(str_contains(s, "class 'TestClassNotFound' is undefined.").toBool());
}

TEST(object, toObject) {
    auto o1 = toObject(1992);
    ASSERT_EQ(o1.getProperty("scalar").toInt(), 1992);

    Array arr = create_map();
    auto o2 = toObject(arr);
    ASSERT_EQ(o2.getProperty("golang").toInt(), 4);

    auto o3 = newObject("ArrayObject");
    o3.setProperty("value", 1999);
    auto o4 = toObject(o3);
    ASSERT_EQ(o4.getProperty("value").toInt(), 1999);
}

TEST(object, getPropertyReference) {
    auto o1 = newObject("stdClass");
    o1.set("prop1", 1990);

    auto prop1 = o1.getPropertyReference("prop1");
    auto str = "first=value&arr[]=foo+bar&arr[]=baz";

    parse_str(str, prop1);

    auto v = prop1.getRefValue();

    ASSERT_TRUE(v.isArray());
    ASSERT_STREQ(v.offsetGet("first").toCString(), "value");

    prop1.unset();

    auto v2 = o1.get("prop1");
    ASSERT_TRUE(v2.isArray());
    ASSERT_STREQ(v2.offsetGet("first").toCString(), "value");
}

TEST(object, getPropertyIndirect) {
    auto o1 = newObject("stdClass");
    o1.set("prop1", 1990);
    ASSERT_EQ(o1.getProperty("prop1").toInt(), 1990);

    auto prop1 = o1.getPropertyIndirect("prop1");
    prop1 = 2022;
    ASSERT_EQ(o1.getProperty("prop1").toInt(), 2022);

    Array arr{1, 3, 99};
    prop1 = arr;
    ASSERT_TRUE(o1.getProperty("prop1").isArray());
}

TEST(object, ArrayProperty) {
    auto o1 = newObject("stdClass");
    o1.set("prop", create_list());
    o1.appendArrayProperty("prop", 1899);

    auto prop1 = o1.get("prop");
    ASSERT_EQ(prop1.offsetGet(5).toInt(), 1899);

    o1.updateArrayProperty("prop", 5, 2026);

    auto prop2 = o1.get("prop");
    ASSERT_EQ(prop2.offsetGet(5).toInt(), 2026);
}

TEST(object, ArrayProperty2) {
    auto o1 = newObject("stdClass");
    o1.set("prop", create_map());

    o1.updateArrayProperty("prop", "php", 2999);

    auto prop1 = o1.get("prop");
    ASSERT_EQ(prop1.offsetGet("php").toInt(), 2999);
}

TEST(object, toObject2) {
    auto v = date_create("now");
    auto o = toObject(v, "DateTime");
    auto ts = o.exec("getTimestamp");
    ASSERT_GE(ts.toInt(), 10000000);
}
