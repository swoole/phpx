#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

// Test operator() (callable) with various argument forms
TEST(variant_edge, callable_operator) {
    var fn("var_dump");
    ASSERT_TRUE(fn.isCallable());

    // Call with initializer list (single arg)
    auto rs = fn({"php_unit_test"});
    ASSERT_TRUE(rs.isNull());

    // Call with initializer list
    ob_start();
    fn({"hello", "world"});
    auto output = ob_get_clean();
    ASSERT_GT(output.length(), 0);
}

TEST(variant_edge, callable_operator_on_object) {
    auto ce = getClassEntry("DateTime");
    auto fn = getMethod(ce, "createFromFormat");

    // call static method via php::call
    auto obj = call(ce, fn, {"j-M-Y", "15-Feb-2009"});
    ASSERT_TRUE(obj.isObject());
    auto formatted = obj.call("format", {"Y-m-d"});
    ASSERT_STREQ(formatted.toCString(), "2009-02-15");
}

// Test getRefValue on non-reference returns self
TEST(variant_edge, getRefValue_non_ref) {
    var v(42);
    auto val = v.getRefValue();
    ASSERT_TRUE(val.isInt());
    ASSERT_EQ(val.toInt(), 42);
}

// Test offsetSet on object via Variant (triggers the object branch)
TEST(variant_edge, offsetSet_object) {
    auto o = newObject("ArrayObject");
    var v = o;
    v.offsetSet("key1", "value1");
    v.offsetSet("key2", 100);
    ASSERT_STREQ(o.offsetGet("key1").toCString(), "value1");
    ASSERT_EQ(o.offsetGet("key2").toInt(), 100);
}

// Test offsetUnset on object
TEST(variant_edge, offsetUnset_object) {
    auto o = newObject("ArrayObject");
    o.offsetSet("key", "value");
    ASSERT_TRUE(o.offsetExists("key"));

    var v = o;
    v.offsetUnset("key");
    ASSERT_FALSE(o.offsetExists("key"));
}

// Test offsetUnset with long on object
TEST(variant_edge, offsetUnset_long_object) {
    auto o = newObject("ArrayObject");
    o.offsetSet(null, 100);
    o.offsetSet(null, 200);
    ASSERT_EQ(o.offsetGet(1).toInt(), 200);

    var v = o;
    v.offsetUnset(0);
    ASSERT_FALSE(o.offsetExists(0));
}

// Test append on string
TEST(variant_edge, append_string) {
    var s("hello");
    s.append(" world");
    ASSERT_STREQ(s.toCString(), "hello world");

    s.append(123);
    ASSERT_STREQ(s.toCString(), "hello world123");

    s.append(std::string(" php"));
    ASSERT_STREQ(s.toCString(), "hello world123 php");
}

// Test append on object via Variant (ArrayObject has offsetSet)
TEST(variant_edge, append_object) {
    auto o = newObject("ArrayObject");
    var v = o;
    v.append("first");
    v.append("second");
    ASSERT_STREQ(v.offsetGet(0).toCString(), "first");
    ASSERT_STREQ(v.offsetGet(1).toCString(), "second");
    // Original object o also modified since var shares ref
    ASSERT_STREQ(o.offsetGet(0).toCString(), "first");
}

// Test append on null/undef raises error
TEST(variant_edge, append_null_becomes_array) {
    var v;
    ASSERT_TRUE(v.isNull());
    try_call([&]() { v.append("hello"); }, "Cannot append element to an `null`");
}

// Test newItem on null triggers error
TEST(variant_edge, newItem_null) {
    try_call(
        []() {
            var v;
            v.newItem();
        },
        "Cannot get new element on `null`");
}

// Test newItem on ArrayObject via Variant
TEST(variant_edge, newItem_object) {
    auto o = newObject("ArrayObject");
    var v = o;
    v.newItem() = 2025;
    ASSERT_EQ(v.offsetGet(0).toInt(), 2025);
}

// Test itemRef on scalar triggers error
TEST(variant_edge, itemRef_non_indirect_non_ref) {
    try_call(
        []() {
            var v(42);
            v.itemRef(0);
        },
        "Only array/object/string support the item");
}

// Test attrRef on property creates reference and assigns
TEST(variant_edge, attrRef_non_existent) {
    auto o = newObject("stdClass");
    auto ref = o.attrRef("new_prop");
    ASSERT_TRUE(ref.isReference());
    ref = 2026;
    ASSERT_EQ(o.get("new_prop").toInt(), 2026);
}

// Test copyRef path through operator=(Variant*)
TEST(variant_edge, copyRef_via_ptr) {
    var a("hello");
    var b(&a);
    ASSERT_TRUE(b.isReference());
    ASSERT_STREQ(b.toCString(), "hello");
}

// Test Variant destructor for reference type
TEST(variant_edge, ref_destructor) {
    Array arr;
    arr.append(100);
    var ref = arr.toReference();
    ASSERT_TRUE(ref.isReference());
    // Let it go out of scope naturally
}

// Test operator! (logical not)
TEST(variant_edge, logical_not) {
    var v1(0);
    ASSERT_TRUE(!v1);
    var v2(42);
    ASSERT_FALSE(!v2);
    var v3("");
    ASSERT_TRUE(!v3);
    var v4("hello");
    ASSERT_FALSE(!v4);
    var v5(false);
    ASSERT_TRUE(!v5);
    var v6(true);
    ASSERT_FALSE(!v6);
}

// Test variant operator== and operator!= with self
TEST(variant_edge, equals_self) {
    var a(42);
    ASSERT_TRUE(a == a);
    ASSERT_FALSE(a != a);

    var b("hello");
    ASSERT_TRUE(b == b);

    auto obj = newObject("stdClass");
    obj.set("prop", 1);
    ASSERT_TRUE(obj == obj);
}

// Test offsetSet on string with Variant key
TEST(variant_edge, offsetSet_string_variant_key) {
    var s("hello");
    var key(2);
    s.offsetSet(key, "X");
    ASSERT_STREQ(s.toCString(), "heXlo");
}

// Test offsetExists on string (integer offset)
TEST(variant_edge, offsetExists_string) {
    var s("world");
    ASSERT_TRUE(s.offsetExists(0));
    ASSERT_TRUE(s.offsetExists(4));
    ASSERT_FALSE(s.offsetExists(5));
}

// Test getProperty via Object
TEST(variant_edge, getProperty_variant_name) {
    auto o = newObject("stdClass");
    o.set("myProp", 2026);

    var v = o;
    auto val = v.getProperty("myProp");
    ASSERT_TRUE(val.isInt());
    ASSERT_EQ(val.toInt(), 2026);
}

// Test getProperty on non-object returns null
TEST(variant_edge, getProperty_non_object) {
    var v(42);
    var name("prop");
    auto val = v.getProperty(name);
    ASSERT_TRUE(val.isNull());
}

// Test toReference on already-reference variant
TEST(variant_edge, toReference_on_ref) {
    Array arr;
    arr.append("test");
    var ref = arr.toReference();
    ASSERT_TRUE(ref.isReference());

    auto ref2 = ref.toReference();
    ASSERT_TRUE(ref2.isReference());
}

// Test serialize/unserialize with various types
TEST(variant_edge, serialize_roundtrip) {
    // Integer
    var v1(42);
    auto s1 = v1.serialize();
    auto u1 = s1.unserialize();
    ASSERT_EQ(u1.toInt(), 42);

    // Float
    var v2(3.14);
    auto s2 = v2.serialize();
    auto u2 = s2.unserialize();
    ASSERT_EQ(u2.toFloat(), 3.14);

    // String
    var v3("hello");
    auto s3 = v3.serialize();
    auto u3 = s3.unserialize();
    ASSERT_STREQ(u3.toCString(), "hello");
}

TEST(variant_edge, divide_assign_preserves_reference) {
    var value(9.0);
    auto ref = value.toReference();

    ref /= 2.0;

    ASSERT_TRUE(ref.isReference());
    ASSERT_DOUBLE_EQ(ref.toFloat(), 4.5);
    ASSERT_DOUBLE_EQ(value.toFloat(), 4.5);
}

TEST(variant_edge, string_conversion_propagates_tostring_exception) {
    eval(R"PHP(
        class PhpxThrowingToString {
            public function __toString(): string {
                throw new RuntimeException('toString failed');
            }
        }
    )PHP");

    auto object = newObject("PhpxThrowingToString");
    auto expect_exception = [](const std::function<void()> &fn) {
        bool thrown = false;
        try {
            fn();
        } catch (zend_object *) {
            thrown = true;
            auto exception = catchException();
            ASSERT_TRUE(str_contains(exception.call("getMessage"), "toString failed").toBool());
        }
        if (!thrown && EG(exception)) {
            catchException();
        }
        ASSERT_TRUE(thrown);
    };

    expect_exception([&object]() { object.toStdString(); });
    expect_exception([&object]() { object.toString(); });
    expect_exception([&object]() { String converted(object); });
}

TEST(variant_edge, append_propagates_tostring_exception) {
    eval(R"PHP(
        class PhpxAppendThrowingValue {
            public function __toString(): string {
                throw new RuntimeException('append toString failed');
            }
        }
    )PHP");

    var value("prefix");
    auto throwing = newObject("PhpxAppendThrowingValue");
    bool thrown = false;
    try {
        value.append(throwing);
    } catch (zend_object *) {
        thrown = true;
        auto exception = catchException();
        ASSERT_TRUE(str_contains(exception.call("getMessage"), "append toString failed").toBool());
    }
    if (!thrown && EG(exception)) {
        catchException();
    }
    ASSERT_TRUE(thrown);
}

TEST(variant_edge, unserialize_rejects_non_string) {
    try_call([]() { var(42).unserialize(); }, "unserialize() expects a string");
}

TEST(variant_edge, serialize_propagates_magic_method_exception) {
    eval(R"PHP(
        class PhpxThrowingSerialize {
            public function __serialize(): array {
                throw new RuntimeException('serialize failed');
            }
        }
    )PHP");

    auto object = newObject("PhpxThrowingSerialize");
    try_call([&object]() { object.serialize(); }, "serialize failed");
}

TEST(variant_edge, unserialize_propagates_magic_method_exception) {
    eval(R"PHP(
        class PhpxThrowingUnserialize {
            public function __unserialize(array $data): void {
                throw new RuntimeException('unserialize failed');
            }
        }
    )PHP");

    var serialized(R"(O:23:"PhpxThrowingUnserialize":0:{})");
    try_call([&serialized]() { serialized.unserialize(); }, "unserialize failed");
}

// Test call on non-object throws
TEST(variant_edge, call_on_non_object) {
    try_call(
        []() {
            var v(42);
            v.call("method");
        },
        "call method `method` on int");
}

// Test variant operator-(negation) on int and float
TEST(variant_edge, unary_negation) {
    var a(10);
    var b = -a;
    ASSERT_EQ(b.toInt(), -10);

    var c(3.14);
    var d = -c;
    ASSERT_EQ(d.toFloat(), -3.14);

    var e(-5);
    var f = -e;
    ASSERT_EQ(f.toInt(), 5);
}

// Test variant deref on non-reference
TEST(variant_edge, deref_non_ref) {
    var v(42);
    v.deref();
    ASSERT_TRUE(v.isInt());
    ASSERT_EQ(v.toInt(), 42);
}

// Test unset and then check type
TEST(variant_edge, unset_then_type) {
    var v("hello");
    v.unset();
    ASSERT_TRUE(v.isUndef());
    ASSERT_TRUE(v.type() == IS_UNDEF);
    ASSERT_FALSE(static_cast<bool>(v));
}

TEST(variant_edge, null_and_unset_are_false) {
    var v("hello");
    v = php::null;
    ASSERT_TRUE(v.isNull());
    ASSERT_FALSE(static_cast<bool>(v));

    v = "world";
    ASSERT_TRUE(static_cast<bool>(v));
    v.unset();
    ASSERT_TRUE(v.isUndef());
    ASSERT_FALSE(static_cast<bool>(v));
}

// Test isFalse/isTrue
TEST(variant_edge, is_false_is_true) {
    var v1(true);
    ASSERT_TRUE(v1.isTrue());
    ASSERT_FALSE(v1.isFalse());

    var v2(false);
    ASSERT_TRUE(v2.isFalse());
    ASSERT_FALSE(v2.isTrue());

    var v3(1);
    ASSERT_FALSE(v3.isFalse());
    ASSERT_FALSE(v3.isTrue());  // it's IS_LONG, not IS_TRUE/IS_FALSE
}

// Test typeStr for various types
TEST(variant_edge, typeStr) {
    var v1;
    ASSERT_STREQ(v1.typeStr(), "null");

    var v2(42);
    ASSERT_STREQ(v2.typeStr(), "int");

    var v3(3.14);
    ASSERT_STREQ(v3.typeStr(), "float");

    var v4("hello");
    ASSERT_STREQ(v4.typeStr(), "string");

    var v5(true);
    ASSERT_STREQ(v5.typeStr(), "bool");

    Array arr;
    ASSERT_STREQ(arr.typeStr(), "array");
}

// Test operator=(nullptr_t)
TEST(variant_edge, assign_nullptr) {
    var v(42);
    v = nullptr;
    ASSERT_TRUE(v.isNull());
}

// Test operator=(zend_string*)
TEST(variant_edge, assign_zend_string) {
    var v;
    zend_string *zs = zend_string_init("direct", 6, 0);
    v = zs;
    ASSERT_TRUE(v.isString());
    ASSERT_STREQ(v.toCString(), "direct");
    // zend_string_copy was called inside operator=(zend_string*)
    zend_string_release(zs);
}

// Test strequals comparison between Variant and raw values
TEST(variant_edge, equals_with_cstring) {
    var v("hello");
    ASSERT_TRUE(v.equals("hello"));
    ASSERT_FALSE(v.equals("world"));

    var n(42);
    ASSERT_TRUE(n.equals(42));
    ASSERT_FALSE(n.equals(99));
}

// Test almostEquals (float comparison)
TEST(variant_edge, almostEquals) {
    var a(3.141592653589793);
    var b(3.141592653589794);
    ASSERT_TRUE(a.almostEquals(b, 1e-10));

    var c(3.14);
    ASSERT_FALSE(a.almostEquals(c, 1e-10));
}

// Test toCString on non-string (should return "")
TEST(variant_edge, toCString_non_string) {
    var v(42);
    ASSERT_STREQ(v.toCString(), "");

    var a = create_map();
    ASSERT_STREQ(a.toCString(), "");
}

// Test call with Args (non-initializer list)
TEST(variant_edge, call_with_args) {
    auto obj = newObject("DateTime", {"2000-01-01"});
    Args args;
    args.append("Y-m-d H:i:s");
    auto rs = obj.call("format", args);
    ASSERT_STREQ(rs.toCString(), "2000-01-01 00:00:00");
}

// Test call with ArgList
TEST(variant_edge, call_with_arglist) {
    auto obj = newObject("DateTime", {"2000-01-01"});
    ArgList al{"Y-m-d H:i:s"};
    auto rs = obj.call("format", al);
    ASSERT_STREQ(rs.toCString(), "2000-01-01 00:00:00");
}

// Test moveTo
TEST(variant_edge, moveTo) {
    var v("hello");
    zval dest;
    v.moveTo(&dest);
    ASSERT_TRUE(v.isUndef());
    ASSERT_TRUE(Z_TYPE(dest) == IS_STRING);
    ASSERT_STREQ(Z_STRVAL(dest), "hello");
    zval_ptr_dtor(&dest);
}

TEST(variant_edge, moveTo_materializes_indirect_value) {
    Array values{"stable"};
    Variant item = values.item(0);
    ASSERT_TRUE(item.isIndirect());

    zval dest;
    item.moveTo(&dest);
    ASSERT_TRUE(item.isUndef());
    ASSERT_FALSE(Z_TYPE(dest) == IS_INDIRECT);
    ASSERT_TRUE(Z_TYPE(dest) == IS_STRING);
    ASSERT_STREQ(Z_STRVAL(dest), "stable");

    values[0] = "changed";
    ASSERT_STREQ(Z_STRVAL(dest), "stable");
    zval_ptr_dtor(&dest);
}

TEST(variant_edge, moveTo_same_storage_is_noop) {
    Variant value("stable");
    value.moveTo(value.ptr());
    ASSERT_STREQ(value.toCString(), "stable");
}

// Test offsetExists on object (zend_long)
TEST(variant_edge, offsetExists_object_long) {
    auto o = newObject("ArrayObject");
    o.offsetSet("key", "value");
    ASSERT_TRUE(o.offsetExists("key"));

    var v = o;
    ASSERT_TRUE(v.offsetExists("key"));

    o.offsetSet(null, 123);
    ASSERT_TRUE(o.offsetExists(0));

    ASSERT_FALSE(o.offsetExists(999));
}

// Test getProperty triggering __get magic (rv path with Ctor::Move)
TEST(variant_edge, getProperty_magic_get) {
    php::eval(R"(
        class GetPropertyTest {
            private $data = [];

            public function __construct() {
                $this->data = ['stored' => 'direct_value'];
            }

            public function __get($name) {
                if (isset($this->data[$name])) {
                    return $this->data[$name];
                }
                return "computed:" . $name;
            }
        }
    )");
    auto obj = php::eval("return new GetPropertyTest();");

    // Existing property accessed directly (non-rv path, Ctor::Indirect)
    auto v1 = obj.getProperty("stored");
    ASSERT_TRUE(v1.isString());
    ASSERT_STREQ(v1.toCString(), "direct_value");

    // Non-existent property triggers __get (rv path, Ctor::Move)
    auto v2 = obj.getProperty("dynamic_prop");
    ASSERT_TRUE(v2.isString());
    ASSERT_STREQ(v2.toCString(), "computed:dynamic_prop");
}

// Test attr triggering __get magic (rv path with Ctor::Move)
TEST(variant_edge, attr_magic_get) {
    php::eval(R"(
        class AttrTest {
            private $data = [];

            public function __construct() {
                $this->data['existing'] = new stdClass();
                $this->data['existing']->value = 100;
            }

            public function __get($name) {
                if (isset($this->data[$name])) {
                    return $this->data[$name];
                }
                $obj = new stdClass();
                $obj->name = $name;
                return $obj;
            }
        }
    )");
    auto obj = php::eval("return new AttrTest();");

    // Existing property accessed directly (non-rv path)
    auto v1 = obj.attr("existing");
    ASSERT_TRUE(v1.isObject());

    // Non-existent property triggers __get (rv path, Ctor::Move)
    auto v2 = obj.attr("dynamic_one");
    ASSERT_TRUE(v2.isObject());
    auto v2name = v2.attr("name");
    ASSERT_STREQ(v2name.toCString(), "dynamic_one");
}

// Test chained attr().attr() through __get (nested rv path, no leak)
TEST(variant_edge, attr_chain_magic_get) {
    php::eval(R"(
        class ChainTest {
            private $items = [];

            public function __set($name, $val) {
                $this->items[$name] = $val;
            }

            public function __get($name) {
                if (isset($this->items[$name])) {
                    return $this->items[$name];
                }
                return null;
            }
        }
    )");
    auto foo = php::eval("return new ChainTest();");
    auto bar = php::eval("return new ChainTest();");
    bar.setProperty("baz", "Check");

    foo.setProperty("bar", bar);

    // foo->bar->baz: each attr() call may trigger __get -> rv path
    auto barObj = foo.attr("bar");
    ASSERT_TRUE(barObj.isObject());
    auto bazVal = barObj.attr("baz");
    ASSERT_TRUE(bazVal.isString());
    ASSERT_STREQ(bazVal.toCString(), "Check");
}

// Test getProperty with string name and object return via __get
TEST(variant_edge, getProperty_magic_get_returns_object) {
    php::eval(R"(
        class GetPropObjTest {
            public function __get($name) {
                $obj = new stdClass();
                $obj->prop = $name;
                return $obj;
            }
        }
    )");
    auto obj = php::eval("return new GetPropObjTest();");

    auto result = obj.getProperty("test_key");
    ASSERT_TRUE(result.isObject());
    ASSERT_STREQ(result.getProperty("prop").toCString(), "test_key");
}

// Test getProperty on non-object with string prop_name
TEST(variant_edge, getProperty_string_name_non_object) {
    php::eval(R"(
        class PropHolder {
            public $visible = "public_val";
            protected $hidden = "protected_val";
        }
    )");
    auto obj = php::eval("return new PropHolder();");

    // Direct property (non-rv, Ctor::Indirect)
    auto v1 = obj.getProperty("visible");
    ASSERT_TRUE(v1.isString());
    ASSERT_STREQ(v1.toCString(), "public_val");

    // Protected property — zend_read_property_ex returns the value regardless
    // of visibility at the C API level (visibility is enforced at PHP compile time)
    auto v2 = obj.getProperty("hidden");
    ASSERT_TRUE(v2.isString());
    ASSERT_STREQ(v2.toCString(), "protected_val");

    // Non-existent property without __get returns null via rv (uninitialized)
    auto v3 = obj.getProperty("nonexistent");
    ASSERT_TRUE(v3.isNull());
}
