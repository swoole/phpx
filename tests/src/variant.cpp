#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

#include "const/json.h"

using namespace php;

constexpr double PI = 3.1415926;

TEST(variant, base) {
    Variant v{};
    ASSERT_TRUE(v.isNull());
    ASSERT_STREQ(v.typeStr(), "null");
    // no gc
    ASSERT_EQ(v.getRefCount(), 0);

    zval zv;
    array_init(&zv);
    Variant v2{&zv};
    zval_ptr_dtor(&zv);
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
    var copy = arr;
    ASSERT_EQ(arr.getRefCount(), 2);
    copy = nullptr;
    ASSERT_EQ(arr.getRefCount(), 1);

    v2 = nullptr;
    ASSERT_TRUE(v2.isNull());

    zval *zv2 = nullptr;
    Variant v3{zv2};
    ASSERT_TRUE(v3.isNull());

    v3 = 199000L;
    ASSERT_TRUE(v3.isInt());
    ASSERT_TRUE(v3 == 199000L);
    ASSERT_TRUE(v3.isNumeric());

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
    ASSERT_FALSE(v3.isNumeric());

    float fv1 = PI;
    Variant v4(fv1);
    ASSERT_TRUE(v4 == (float) PI);
    ASSERT_TRUE(v4.isNumeric());

    var v5 = "123.456";
    ASSERT_TRUE(v5.isNumeric());
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

    ASSERT_EQ(ref.getRefCount(), 2);

    auto ref2 = ref.toReference();
    ASSERT_TRUE(ref2.isReference());
    ASSERT_EQ(ref2.getRefCount(), 3);
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

TEST(variant, ref5) {
    var s = "hello world";
    var ref = &s;
    s = "hello php";

    auto b = ref.toString();
    ASSERT_TRUE(ref.isReference());
    ASSERT_STREQ(b.data(), "hello php");
    ASSERT_STREQ(ref.toCString(), "hello php");
    ASSERT_TRUE(ref.isString());
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
    String *rs1 = nullptr;

    try {
        rs1 = v.toResource<String>("string");
    } catch (zend_object *ex) {
        catchException();
    }
    ASSERT_EQ(rs1, nullptr);

    auto fp = php::fopen("/tmp/test.txt", "w+");
    ASSERT_TRUE(fp.isResource());

    php_stream *rs2 = nullptr;
    try {
        rs2 = fp.toResource<php_stream>("php_stream");
    } catch (zend_object *ex) {
        catchException();
    }
    ASSERT_EQ(rs2, nullptr);

    auto *s = new String("hello world");
    var rs3;
    try {
        rs3 = newResource<String>("string", s);
    } catch (zend_object *ex) {
        catchException();
    }
    ASSERT_TRUE(rs3.isNull());
    delete s;

    String *rs4 = nullptr;
    try {
        rs4 = fp.toResource<String>("string_not_exists");
    } catch (zend_object *ex) {
        catchException();
    }
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

TEST(variant, calc2) {
    var a = 1990;
    var b = 20 + a;

    ASSERT_EQ(b.toInt(), 2010);

    var c = 2025 - a;
    ASSERT_EQ(c.toInt(), 35);

    var d = 3 * a;
    ASSERT_EQ(d.toInt(), 1990 * 3);

    var e = 23023 / a;
    ASSERT_EQ(e.toFloat(), 23023.0 / 1990.0);

    var f = 23042 % a;
    ASSERT_EQ(f.toInt(), 23042 % 1990);

    var g0 = 16;

    var g = 2 << g0;
    ASSERT_EQ(g.toInt(), 2 << 16);

    auto v = php::atoi("512k");
    var h = v >> g0;
    ASSERT_EQ(h.toInt(), v >> 16);

    var g1 = 0xFFFF;

    var i = 128 & g1;
    ASSERT_EQ(i.toInt(), 128);

    Int j0 = g.toInt();
    var j = j0 | g1;
    ASSERT_EQ(j.toInt(), 196607);

    var k = 128 ^ g1;
    ASSERT_EQ(k.toInt(), 65407);

    var l = 327 + a + 192;
    ASSERT_EQ(l.toInt(), 327 + 1990 + 192);
}

TEST(variant, same) {
    var a = "hello";
    var b = "hello";
    ASSERT_TRUE(a.same(b));

    var c = newObject("stdClass");
    var d = newObject("stdClass");
    ASSERT_TRUE(c.equals(d));
    ASSERT_FALSE(c.same(d));
}

TEST(variant, offsetGet) {
    Array a{1, 2, 3, 99, 1000};
    ASSERT_EQ(a.offsetGet(3).toInt(), 99);
    ASSERT_TRUE(a.offsetGet(100).isNull());
    ASSERT_TRUE(a.offsetExists(3));
    ASSERT_TRUE(a.offsetGet(a.length()).isNull());

    var s = "hello world";
    ASSERT_STREQ(s.offsetGet(4).toCString(), "o");
    ASSERT_STREQ(s.offsetGet("4").toCString(), "o");
    ASSERT_STREQ(s.offsetGet(s.length()).toCString(), "");
    ASSERT_FALSE(s.offsetExists(s.length()));
    ASSERT_FALSE(s.offsetExists(-99));
    ASSERT_TRUE(s.offsetExists(-2));
    ASSERT_STREQ(s.offsetGet(-1).toCString(), "d");

    var b = false;
    ASSERT_TRUE(b.offsetGet(0).isNull());
    ASSERT_STREQ(s.offsetGet(b).toCString(), "h");

    Array a2;
    var sk = "hello";
    a2.set(sk, 999);
    a2.set("world", 888);
    ASSERT_EQ(a2.offsetGet(sk).toInt(), 999);
    ASSERT_TRUE(a2.offsetExists("world"));
    ASSERT_FALSE(a2.offsetExists("golang"));
}

TEST(variant, offsetGet2) {
    var sk = "hello";
    auto o = newObject("ArrayObject");
    o.offsetSet(sk, 1987);
    ASSERT_TRUE(o.offsetExists(sk));
    ASSERT_EQ(o.offsetGet(sk).toInt(), 1987);

    o.offsetUnset(sk);
    ASSERT_FALSE(o.offsetExists(sk));
}

TEST(variant, offsetGet3) {
    auto o = newObject("ArrayObject");
    o.offsetSet(null, 1987);
    o.offsetSet(null, 2026);

    ASSERT_TRUE(o.offsetExists(1));
    ASSERT_FALSE(o.offsetExists(2));
    ASSERT_EQ(o.offsetGet(0).toInt(), 1987);

    var v = o;
    ASSERT_EQ(v.offsetGet(1).toInt(), 2026);
    ASSERT_FALSE(v.offsetExists(4));
    ASSERT_TRUE(v.offsetExists(1));
}

TEST(variant, offsetGet4) {
    auto o = newObject("ArrayObject");
    o.offsetSet("hello", 1987);
    o.offsetSet("world", 2026);

    var v = o;

    var sk = "hello";
    ASSERT_EQ(v.offsetGet(sk).toInt(), 1987);

    var sk2 = "emtpy";
    ASSERT_TRUE(v.offsetGet(sk2).isNull());

    ASSERT_FALSE(sk2.offsetExists(10));
    ASSERT_TRUE(sk2.offsetExists(4));

    ASSERT_TRUE(sk2.offsetExists(true));
    ASSERT_TRUE(sk2.offsetExists(false));
}

TEST(variant, offsetSet2) {
    auto o = newObject("ArrayObject");
    o.offsetSet(null, 1987);
    o.offsetSet(null, 2026);

    var v = o;
    v.offsetSet(1, 1900);
    ASSERT_EQ(o.offsetGet(1).toInt(), 1900);

    v.offsetUnset(1);
    ASSERT_TRUE(o.offsetGet(1).isNull());
}

TEST(variant, offsetSet3) {
	var v;
	v.offsetSet(null, 1923);
    ASSERT_EQ(v.offsetGet(0).toInt(), 1923);

    var s = "hello";
    s.offsetSet(4, "x");
    ASSERT_STREQ(s.toCString(), "hellx");
}

TEST(variant, setProperty) {
    var sk = "hello";
    auto o = newObject("ArrayObject");

    o.setProperty(sk, 1987);
    auto v = o.getProperty(sk);
    ASSERT_EQ(v.toInt(), 1987);
}

TEST(variant, unsetProperty) {
    var sk = "hello";
    auto o = newObject("ArrayObject");

    o.setProperty(sk, 1987);
    auto v = o.getProperty(sk);
    ASSERT_EQ(v.toInt(), 1987);

    o.unsetProperty(sk);
    auto v2 = o.getProperty(sk);
    ASSERT_TRUE(v2.isNull());
}

TEST(variant, newReference) {
    var ref = newReference();

    var str = "first=value&arr[]=foo+bar&arr[]=baz";
    parse_str(str, ref);

    array arr(*ref);
    ASSERT_STREQ(arr.offsetGet("first").toCString(), "value");
}

TEST(variant, unary_operators) {
    var a = -199;
    var b = -a;
    ASSERT_EQ(b.toInt(), 199);
}

TEST(variant, nested_update) {
    Array a{1, 2, 3, 99, 1000};

    Array b{};
    b.set("hello", a);

    auto c = b.offsetGet("hello");
    c.offsetSet(4, 1987);
}

TEST(variant, offsetSet) {
    Array a2;
    var sk = "hello";
    a2.offsetSet(sk, 999);
    a2.offsetSet("world", 888);
    ASSERT_EQ(a2.offsetGet(sk).toInt(), 999);

    Array a3(a2);
    a3.offsetSet("php", 2026);
    ASSERT_EQ(a3.offsetGet("php").toInt(), 2026);

    a3.offsetUnset(sk);
    ASSERT_FALSE(a3.offsetExists(sk));
    ASSERT_TRUE(a2.offsetExists(sk));
}

TEST(variant, offsetUnset) {
    Array a{1, 2, 3, 99, 1000};
    var ik(4);

    a.offsetSet(ik, 999);
    ASSERT_EQ(a.offsetGet(ik).toInt(), 999);

    ASSERT_TRUE(a.offsetExists(3));
    a.offsetUnset(3);
    ASSERT_FALSE(a.offsetExists(3));

    ASSERT_TRUE(a.offsetExists(ik));
    a.offsetUnset(ik);
    ASSERT_FALSE(a.offsetExists(ik));

    a.offsetSet(null, 2026);

    ASSERT_EQ(a.offsetGet(5).toInt(), 2026);

    auto o = newObject("ArrayObject");
    o.offsetSet(null, 1987);
    o.offsetSet(null, 2026);
    o.offsetSet(2, 1999);
    ASSERT_EQ(o.offsetGet(2).toInt(), 1999);

    ASSERT_TRUE(o.offsetExists(1));
    o.offsetUnset(1);
    ASSERT_FALSE(o.offsetExists(1));
}

TEST(variant, operateWithBadType) {
    var v(19992);
    ASSERT_TRUE(v.offsetGet("hello").isNull());
    ASSERT_FALSE(v.offsetExists(2000));

    var ik(3.1415);
    ASSERT_FALSE(v.offsetExists(ik));

    var sk("world");
    ASSERT_FALSE(v.offsetExists(sk));

    ASSERT_TRUE(v.getProperty("hello").isNull());
}

TEST(variant, item) {
    auto o = newObject("ArrayObject");
    o.offsetSet(0, 2000);
    o.offsetSet(1, 1987);

    ASSERT_EQ(o.offsetGet(1).toInt(), 1987);

    auto iv = o.item(1);
    iv = 1999;
    ASSERT_EQ(o.offsetGet(1).toInt(), 1999);

    Array a{1, 2, 3, 99, 1000};
    auto iv2 = a.item(3);
    iv2 = 1987;
    ASSERT_EQ(a.offsetGet(3).toInt(), 1987);
}

TEST(variant, item2) {
    var sk = "hello";
    auto o = newObject("ArrayObject");
    o.offsetSet(sk, 1987);
    ASSERT_TRUE(o.offsetExists(sk));
    ASSERT_EQ(o.offsetGet(sk).toInt(), 1987);

    auto iv = o.item(sk);
    iv = 1999;
    ASSERT_EQ(o.offsetGet(sk).toInt(), 1999);

    Array a = create_map();
    auto iv2 = a.item("php");
    iv2 = 1995;
    ASSERT_EQ(a.offsetGet("php").toInt(), 1995);

    auto iv3 = a.item("swift", true);
    iv3 = 2012;
    ASSERT_EQ(a.offsetGet("swift").toInt(), 2012);

    auto chr = sk.item(1);
    ASSERT_STREQ(chr.toCString(), "e");
}

TEST(variant, ref) {
    Reference ref;
    auto array = create_list();
    ref = array.toReference();
    sort(ref);
    ASSERT_STREQ(ref.offsetGet(0).toCString(), "c++");
}

TEST(variant, item3) {
	auto arr = create_list();
	var v = arr;
	auto indirect = v.item(3, true);
	indirect = "golang";

    ASSERT_STREQ(v.item(3).toCString(), "golang");

    auto item2 = v.item(9999);
    ASSERT_TRUE(item2.isNull());

    try {
    	var v2 = false;
    	auto res = v2.item(2);
    } catch (zend_object *ex) {
        auto e = catchException();
        auto msg = e.exec("getMessage");
        ASSERT_TRUE(str_contains(msg, "Only array/object/string support the item").isTrue());
    }
}

TEST(variant, item4) {
	auto arr = create_list();
	var v = arr;

	{
		auto v2 = std::move(v.item(3));
		ASSERT_EQ(v2.getRefCount(), 2);
	}
}
