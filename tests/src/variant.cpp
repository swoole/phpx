#include "phpx_test.h"
#include "phpx_func.h"
#include "const/json.h"

using namespace php;

constexpr double PI = 3.1415926;

TEST(variant, base) {
    Variant v{nullptr};
    ASSERT_TRUE(v.isNull());
    ASSERT_STREQ(v.typeStr(), "null");
    // no gc
    ASSERT_EQ(v.getRefCount(), 0);

    zval zv;
    array_init(&zv);
    Variant v2{&zv, true};
    ASSERT_TRUE(v2.isArray());

    // Assignment to itself
    v2 = v2;

    Variant ref{&v2};
    Variant ref2{ref};
    auto ref2_val = ref2.getRefValue();
    ASSERT_TRUE(ref2_val.isArray());

    auto refval_v2 = v2.getRefValue();
    ASSERT_TRUE(refval_v2.isArray());

    ASSERT_TRUE(v2.isArray());
    auto arr = v2.toArray();
    arr.append("hello world");
    arr.append(1922);
    ASSERT_EQ(arr.count(), 2);
    ASSERT_STREQ(arr.typeStr(), "array");

    ASSERT_EQ(arr.getRefCount(), 1);
    arr.addRef();
    ASSERT_EQ(arr.getRefCount(), 2);
    arr.delRef();
    ASSERT_EQ(arr.getRefCount(), 1);

    v2 = nullptr;
    ASSERT_TRUE(v2.isNull());

    zval *zv2 = nullptr;
    Variant v3{zv2};
    ASSERT_TRUE(v3.isNull());

    v3 = 199000L;
    ASSERT_TRUE(v3.isInt());
    ASSERT_TRUE(v3 == 199000L);

    v3 = std::string("hello");
    ASSERT_TRUE(v3.isString());
    ASSERT_EQ(v3.length(), 5);
    ASSERT_TRUE(v3 == "hello");

    String s("hello world!");
    v3 = s;
    ASSERT_TRUE(v3.isString());
    ASSERT_EQ(v3.length(), s.length());

    v3 = PI;
    ASSERT_TRUE(v3.isFloat());
    ASSERT_TRUE(v3 == PI);

    ASSERT_EQ(s.length(), 12);

    v3 = false;
    ASSERT_TRUE(v3.isBool());
    ASSERT_TRUE(v3 == false);

    float fv1 = PI;
    Variant v4(fv1);
    ASSERT_TRUE(v4 == (float) PI);
}

TEST(variant, toCString) {
    std::string s1("hello world");
    Variant s2("hello world");
    ASSERT_STREQ(s1.c_str(), s2.toCString());
}

TEST(variant, toStdString) {
    std::string s1("hello world");
    Variant s2("hello world");
    ASSERT_STREQ(s1.c_str(), s2.toStdString().c_str());
}

TEST(variant, toString) {
    Variant s("hello world");
    auto s2 = s.toString();
    ASSERT_EQ(s2.getRefCount(), 2);
    ASSERT_TRUE(s2.equals("hello world"));
}

TEST(variant, toStringWithLength) {
    std::string s1("hello world");
    Variant s2("hello world");
    ASSERT_EQ(s1.length(), s2.toStdString().length());
}

TEST(variant, serialize) {
    auto v1 = create_map();
    Variant v2 = v1.serialize();

    ASSERT_TRUE(v2.isString());
    ASSERT_GT(v2.length(), 10);

    Variant v3 = v2.unserialize();
    ASSERT_TRUE(v3.isArray());
    ASSERT_TRUE(v3.equals(v1));

    var v4 = "-----";
    ASSERT_TRUE(v4.unserialize().isNull());
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
    var v(10);
    v += 5;
    ASSERT_EQ(v.toInt(), 15);

    v -= 3;
    ASSERT_EQ(v.toInt(), 12);

    ASSERT_EQ(v.length(), 0);
    ASSERT_EQ(v.getRefCount(), 0);

    var a = 11;
    var b = 19;
    var c = a + b;
    ASSERT_TRUE(c.equals(30));

    var d = b - a;
    ASSERT_TRUE(d.equals(8));

    var e = b * a;
    ASSERT_TRUE(e.equals(209));

    var f1 = 2;
    var f2 = b / f1;
    ASSERT_TRUE(f2.equals(9.5));

    ASSERT_TRUE(f1.pow(16).equals(std::pow(2, 16)));

    var f3 = b / 0.3;
    ASSERT_TRUE(f3.equals(19 / 0.3));

    var g = PI;
    ASSERT_EQ(g++, PI);
    ASSERT_EQ(g, PI + 1.0);
    ASSERT_EQ(g--, PI + 1.0);
    ASSERT_EQ(g, PI);

    ASSERT_EQ(++g, PI + 1.0);
    ASSERT_EQ(g, PI + 1.0);
    ASSERT_EQ(--g, PI);
    ASSERT_EQ(g, PI);

    g += 7;
    ASSERT_EQ(g, PI + 7);

    g -= 7.0;
    ASSERT_TRUE(g.almostEquals(PI, 1e-5));

    var h1 = 31;
    var h2 = 3;
    ASSERT_EQ(h1 % h2, 31 % 3);
    ASSERT_EQ(h1 << h2, 31 << 3);
    ASSERT_EQ(h1 >> h2, 31 >> 3);
    ASSERT_EQ(h1 & h2, 31 & 3);
    ASSERT_EQ(h1 | h2, 31 | 3);
    ASSERT_EQ(h1 ^ h2, 31 ^ 3);
    ASSERT_EQ(~h1, ~31);

    var i = PI;
    var i2 = i % 2.0;
    ASSERT_TRUE(i2.equals(1));

    var i3 = i2.pow(1.3);
    ASSERT_TRUE(i3.almostEquals(std::pow(i2.toFloat(), 1.3), 1e-5));

    var i4 = 2;
    var i5 = i4.pow(8);
    ASSERT_TRUE(i5.equals(std::pow(2, 8)));

    var x = 5.7;
    var y = 1.3;
    var r = php::fmod(x, y);
    ASSERT_TRUE(r.equals(std::fmod(5.7, 1.3)));
}

TEST(variant, compare) {
    {
        var a = 11;
        var b = 19;

        ASSERT_TRUE(a != b);
        ASSERT_FALSE(a == b);

        ASSERT_TRUE(a < b);
        ASSERT_TRUE(b > a);
        ASSERT_TRUE(a <= b);
        ASSERT_TRUE(b >= a);
        ASSERT_TRUE(b >= b);
    }

    {
        var a = 11.23;
        var b = 19.90;

        ASSERT_TRUE(a != b);
        ASSERT_FALSE(a == b);

        ASSERT_TRUE(a < b);
        ASSERT_TRUE(b > a);
        ASSERT_TRUE(a <= b);
        ASSERT_TRUE(b >= a);
        ASSERT_TRUE(b >= b);
    }
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

    var v5 = "\xB1\x31";
    ASSERT_EQ(v5.jsonEncode().toBool(), false);

    var error = json_last_error();
    ASSERT_TRUE(error.equals(JSON_ERROR_UTF8));
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

    ASSERT_EQ(ref.getRefCount(), 1);

    auto ref2 = ref.toReference();
    ASSERT_TRUE(ref2.isReference());
    ASSERT_EQ(ref2.getRefCount(), 2);
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
    delete s;

    auto rs4 = fp.toResource<String>("string_not_exists");
    ASSERT_EQ(rs4, nullptr);
}

TEST(variant, self) {
    Variant v1("hello world");
    Variant v2 = v1;
    ASSERT_TRUE(v1.equals(v2, true));
}

TEST(variant, move_ctor) {
    Variant s("abc");
    Variant t(std::move(s));
    EXPECT_STREQ(t.toCString(), "abc");
    EXPECT_TRUE(s.isUndef());
    s.print();
    t.print();
}

TEST(variant, concat1) {
    var s("abc");
    // s2 and s point to the same zend_string object
    var s2 = s;

    ASSERT_EQ(s2.toString().getRefCount(), 3);

    s.append(" hello ");
    // copy on write: `s` will be separated, and a new zend_string object will be allocated
    ASSERT_STREQ(s.toCString(), "abc hello ");
    ASSERT_STREQ(s2.toCString(), "abc");
    ASSERT_EQ(s2.toString().getRefCount(), 2);

    s.append(1990);
    ASSERT_STREQ(s.toCString(), "abc hello 1990");

    s.append(" ");

    s.append(2020.2009);
    ASSERT_STREQ(s.toCString(), "abc hello 1990 2020.2009");
}

TEST(variant, concat2) {
    var s("abc");

    auto s2 = s.concat(" hello ");
    ASSERT_STREQ(s2.toCString(), "abc hello ");

    auto s3 = s2.concat(1990);
    ASSERT_STREQ(s3.toCString(), "abc hello 1990");

    auto s4 = s3.concat(" ").concat(2020.2009);
    ASSERT_STREQ(s4.toCString(), "abc hello 1990 2020.2009");
}

TEST(variant, binary_op) {
    var a = 256;
    a /= 2;
    ASSERT_EQ(a.toInt(), 128);

    a *= 3;
    ASSERT_EQ(a.toInt(), 384);

    a %= 31;
    ASSERT_EQ(a.toInt(), 12);

    a = 16;
    a <<= 2;
    ASSERT_EQ(a.toInt(), 64);

    a >>= 3;
    ASSERT_EQ(a.toInt(), 8);

    a &= 8;
    ASSERT_EQ(a.toInt(), 8);

    a &= 4;
    ASSERT_EQ(a.toInt(), 0);

    a |= 128;
    ASSERT_EQ(a.toInt(), 128);

    a ^= 64;
    ASSERT_EQ(a.toInt(), 192);
}

TEST(variant, logical_op) {
    const Array a;
    const var b = "1";
    ASSERT_TRUE(a || b);
    ASSERT_FALSE(a && b);
}
