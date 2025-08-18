#include "phpx_test.h"
#include "phpx_func.h"

using namespace php;

TEST(variant, base) {
    Variant v{nullptr};
    ASSERT_TRUE(v.isNull());

    zval zv;
    array_init(&zv);
    Variant v2{&zv, true};

    ASSERT_TRUE(v2.isArray());
    auto arr = v2.toArray();
    arr.append("hello world");
    arr.append(1922);
    ASSERT_EQ(arr.count(), 2);

    v2 = nullptr;
    ASSERT_TRUE(v2.isNull());
}

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

    ASSERT_EQ(v.length(), 0);
    ASSERT_EQ(v.getRefCount(), 0);
}

TEST(variant, json) {
    Array arr1 = create_map();
    auto json = arr1.jsonEncode();
    ASSERT_TRUE(json.isString());
    ASSERT_GT(json.length(), 10);

    auto v3 = json.jsonDecode();
    ASSERT_TRUE(v3.isArray());
    ASSERT_TRUE(v3.equals(arr1));

    Variant v4("");
    ASSERT_TRUE(v4.jsonDecode().isNull());
    ASSERT_EQ(JSON_G(error_code), PHP_JSON_ERROR_SYNTAX);
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

TEST(variant, resource) {
    Variant v;
    auto rs = v.toResource<String>("string");
    ASSERT_EQ(rs, nullptr);

    auto fp = php::fopen("/tmp/test.txt", "w+");
    ASSERT_TRUE(fp.isResource());
    auto rs2 = fp.toResource<php_stream>("php_stream");
    ASSERT_EQ(rs2, nullptr);

    auto *s = new String("hello world");
    auto rs3 = newResource<String>("string", s);
    ASSERT_TRUE(rs3.isNull());
}

TEST(variant, self) {
    Variant v1("hello world");
    Variant v2 = v1;
    ASSERT_TRUE(v1.equals(v2, true));
}
