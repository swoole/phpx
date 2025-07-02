#include "phpx_test.h"
#include "phpx_func.h"

using namespace php;

TEST(variant, toCString) {
    std::string s1("hello world");
    Variant s2("hello world");
    ASSERT_STREQ(s1.c_str(), s2.toCString());
}

TEST(variant, toString) {
    std::string s1("hello world");
    Variant s2("hello world");
    ASSERT_STREQ(s1.c_str(), s2.toString().c_str());
}

TEST(variant, toStringWithLength) {
    std::string s1("hello world");
    Variant s2("hello world");
    ASSERT_EQ(s1.length(), s2.toString().length());
}

TEST(variant, serialize) {
    auto v1 = create_map();
    Variant v2 = v1.serialize();

    ASSERT_TRUE(v2.isString());
    ASSERT_GT(v2.length(), 10);

    Variant v3 = v2.unserialize();
    ASSERT_TRUE(v3.isArray());
    ASSERT_TRUE(v3.equals(v1));
}

TEST(variant, incr) {
    Variant v(10);
    ASSERT_EQ(v++, 10);
    ASSERT_EQ(v.toInt(), 11);
}

TEST(variant, decr) {
    Variant v(10);
    ASSERT_EQ(v--, 10);
    ASSERT_EQ(v.toInt(), 9);
}


TEST(variant, pre_incr) {
    Variant v(10);
    ASSERT_EQ((++v).toInt(), 11);
    ASSERT_EQ(v.toInt(), 11);
}

TEST(variant, pre_decr) {
    Variant v(10);
    ASSERT_EQ((--v).toInt(), 9);
    ASSERT_EQ(v.toInt(), 9);
}

TEST(variant, calc) {
    Variant v(10);
    v += 5;
    ASSERT_EQ(v.toInt(), 15);

    v -= 3;
    ASSERT_EQ(v.toInt(), 12);
}

TEST(variant, json) {
    Array arr1 = create_map();
    auto json = arr1.jsonEncode();
    ASSERT_TRUE(json.isString());
    ASSERT_GT(json.length(), 10);

    auto v3 = json.jsonDecode();
    ASSERT_TRUE(v3.isArray());
    ASSERT_TRUE(v3.equals(arr1));
}

TEST(variant, ref0) {
    Array arr;
    Variant ref = &arr;
    array_push(ref, "php", "java", "go");
    ASSERT_EQ((*ref).length(), 3);

    array_push(ref, "c++", "rust", "erlang", "node.js");
    ASSERT_EQ((*ref).length(), 7);

    array_push(ref, "python", "ruby", "lua", "perl", "vue");
    ASSERT_EQ(ref.getRefValue().length(), 12);

    arr.debug();
    ref.debug();
}

TEST(variant, ref1) {
    Array arr;
    Variant ref(&arr);
    parse_str("first=value1&second=value2", ref);
    Array v3 = ref.getRefValue();
    ASSERT_EQ(v3.count(), 2);
}

TEST(variant, ref2) {
    Array arr;
    Variant ref = &arr;
    parse_str("first=value1&second=value2", ref);
    Array v3 = *ref;
    ASSERT_EQ(v3.count(), 2);
}

TEST(variant, ref3) {
    Array arr;
    Variant ref = &arr;
    array_push(ref, "php", "java", "go");
    ASSERT_EQ((*ref).length(), 3);

    array_push(ref, "python", "ruby", "lua", "perl", "vue");
    ASSERT_EQ((*ref).length(), 8);
}

TEST(variant, ref4) {
    Array arr;
    Variant ref;
    ref = &arr;

    array_push(ref, "php", "java", "go");
    ASSERT_EQ((*ref).length(), 3);
}

TEST(variant, object) {
    auto array = create_map();
    auto object = newObject("ArrayObject", {array, constant("ArrayObject::ARRAY_AS_PROPS")});
    ASSERT_TRUE(object.isObject());
    ASSERT_EQ(object.get("php").toInt(), 3);

    object.exec("offsetSet", {"python", 9});
    auto r2 = object.get("python");
    ASSERT_EQ(r2.toInt(), 9);

    auto o2 = newObject("class_not_exists");
    ASSERT_FALSE(o2.isUndef());
}

TEST(variant, callable) {
    Variant v1{"phpinfo"};
    ASSERT_TRUE(v1.isCallable());

    Variant v2{"fn_not_exists"};
    ASSERT_FALSE(v2.isCallable());
}

TEST(variant, empty) {
    ASSERT_TRUE(null.empty());
    Variant v;
    v = false;
    ASSERT_TRUE(v.empty());
    v = true;
    ASSERT_FALSE(v.empty());
    v = "";
    ASSERT_TRUE(v.empty());
    v = "hello";
    ASSERT_FALSE(v.empty());
    v = 0;
    ASSERT_TRUE(v.empty());
    v = 9999;
    ASSERT_FALSE(v.empty());

    v = 0.0;
    ASSERT_TRUE(v.empty());
    v = 1.1;
    ASSERT_FALSE(v.empty());

    Array arr;
    ASSERT_TRUE(arr.empty());
    arr.append("hello");
    ASSERT_FALSE(arr.empty());
    ASSERT_EQ(arr.getRefCount(), 1);

    Variant alias_arr = arr;
    ASSERT_FALSE(alias_arr.empty());
    ASSERT_EQ(arr.getRefCount(), 2);
}
