#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

// Test parent_ce() returns parent class entry
TEST(object_extra, parent_ce) {
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);
    auto obj = newObject("TestClass2");
    auto parent = obj.parent_ce();
    ASSERT_NE(parent, nullptr);
    ASSERT_STREQ(parent->name->val, "TestClass");
}

// Test parent_ce() on class without parent
TEST(object_extra, parent_ce_no_parent) {
    auto obj = newObject("stdClass");
    // stdClass parent_ce may be null or point to internal parent
    auto parent = obj.parent_ce();
    // Just verify no crash - parent may or may not exist
    SUCCEED();
}

// Test count() on object (Countable interface)
TEST(object_extra, count) {
    auto obj = newObject("ArrayObject");
    obj.append("a");
    obj.append("b");
    obj.append("c");
    ASSERT_EQ(obj.count(), 3);

    // Empty ArrayObject
    auto obj2 = newObject("ArrayObject");
    ASSERT_EQ(obj2.count(), 0);
}

TEST(object_extra, count_exception) {
    eval(R"(
        class PhpxThrowingCountable implements Countable {
            public function count(): int { throw new RuntimeException('count failed'); }
        }
    )");
    Object obj = eval("return new PhpxThrowingCountable();");

    try_call([&obj]() { obj.count(); }, "count failed");
}

TEST(object_extra, property_exists_exception) {
    eval(R"(
        class PhpxThrowingIsset {
            public function __isset(string $name): bool { throw new RuntimeException('__isset failed'); }
        }
    )");
    Object obj = eval("return new PhpxThrowingIsset();");

    try_call([&obj]() { obj.propertyExists("value", PROP_ISSET); }, "__isset failed");
}

// Test getId() returns object handle
TEST(object_extra, getId) {
    auto o1 = newObject("stdClass");
    auto o2 = newObject("stdClass");
    ASSERT_NE(o1.getId(), o2.getId());
    ASSERT_GT(o1.getId(), 0);
}

// Test offsetExists with Variant key
TEST(object_extra, offsetExists_variant_key) {
    auto obj = newObject("ArrayObject");
    obj.offsetSet("name", "test");
    obj.offsetSet("age", 30);

    ASSERT_TRUE(obj.offsetExists("name"));
    ASSERT_TRUE(obj.offsetExists("age"));
    ASSERT_FALSE(obj.offsetExists("nonexistent"));

    var key("name");
    ASSERT_TRUE(obj.offsetExists(key));
}

// Test offsetExists with zend_long
TEST(object_extra, offsetExists_long) {
    auto obj = newObject("ArrayObject");
    obj.append("first");
    obj.append("second");

    ASSERT_TRUE(obj.offsetExists(0));
    ASSERT_TRUE(obj.offsetExists(1));
    ASSERT_FALSE(obj.offsetExists(2));
    ASSERT_FALSE(obj.offsetExists(999));
}

// Test offsetGet with Variant key
TEST(object_extra, offsetGet_variant_key) {
    auto obj = newObject("ArrayObject");
    obj.offsetSet("x", 100);
    obj.offsetSet("y", 200);

    var kx("x");
    ASSERT_EQ(obj.offsetGet(kx).toInt(), 100);
    ASSERT_EQ(obj.offsetGet("y").toInt(), 200);

    // Non-existent key
    auto nx = obj.offsetGet("z");
    ASSERT_TRUE(nx.isNull());
}

// Test offsetGet with zend_long
TEST(object_extra, offsetGet_long) {
    auto obj = newObject("ArrayObject");
    obj.append(10);
    obj.append(20);
    obj.append(30);

    ASSERT_EQ(obj.offsetGet(0).toInt(), 10);
    ASSERT_EQ(obj.offsetGet(1).toInt(), 20);
    ASSERT_EQ(obj.offsetGet(2).toInt(), 30);
    ASSERT_TRUE(obj.offsetGet(999).isNull());
}

// Test offsetSet with Variant key
TEST(object_extra, offsetSet_variant_key) {
    auto obj = newObject("ArrayObject");
    var key("color");
    obj.offsetSet(key, "blue");
    ASSERT_STREQ(obj.offsetGet("color").toCString(), "blue");
}

// Test offsetSet with zend_long
TEST(object_extra, offsetSet_long) {
    auto obj = newObject("ArrayObject");
    obj.offsetSet(5, "position_five");
    ASSERT_STREQ(obj.offsetGet(5).toCString(), "position_five");
}

// Test offsetUnset with Variant key
TEST(object_extra, offsetUnset_variant_key) {
    auto obj = newObject("ArrayObject");
    obj.offsetSet("temp", "value");
    ASSERT_TRUE(obj.offsetExists("temp"));

    var key("temp");
    obj.offsetUnset(key);
    ASSERT_FALSE(obj.offsetExists("temp"));
}

// Test offsetUnset with zend_long
TEST(object_extra, offsetUnset_long) {
    auto obj = newObject("ArrayObject");
    obj.append("first");
    obj.append("second");
    ASSERT_TRUE(obj.offsetExists(0));

    obj.offsetUnset(0);
    ASSERT_FALSE(obj.offsetExists(0));
}

// Test propertyExists with different PropertyOperation modes
TEST(object_extra, propertyExists_modes) {
    auto obj = newObject("stdClass");
    obj.set("name", "John");
    obj.set("empty_str", "");
    obj.set("zero", 0);
    obj.set("null_val", std::nullptr_t());

    // PROP_EXISTS (default) - property is declared/set
    ASSERT_TRUE(obj.propertyExists("name"));
    ASSERT_TRUE(obj.propertyExists("empty_str", PROP_EXISTS));
    ASSERT_TRUE(obj.propertyExists("zero", PROP_EXISTS));
    ASSERT_FALSE(obj.propertyExists("nonexistent", PROP_EXISTS));

    // PROP_ISSET - property is set and not null
    ASSERT_TRUE(obj.propertyExists("name", PROP_ISSET));
    ASSERT_TRUE(obj.propertyExists("empty_str", PROP_ISSET));
    ASSERT_TRUE(obj.propertyExists("zero", PROP_ISSET));

    // PROP_EMPTY - property is not empty (truthy)
    ASSERT_FALSE(obj.propertyExists("null_val", PROP_EMPTY));
    ASSERT_TRUE(obj.propertyExists("name", PROP_EMPTY));
    bool result = obj.propertyExists("nonexistent", PROP_EMPTY);
    ASSERT_FALSE(result);
}

// Test propertyExists with all three modes on empty values
TEST(object_extra, propertyExists_empty_values) {
    auto obj = newObject("stdClass");
    obj.set("empty_str", "");
    obj.set("zero", 0);
    obj.set("false_val", false);

    // PROP_EXISTS - all exist
    ASSERT_TRUE(obj.propertyExists("empty_str", PROP_EXISTS));
    ASSERT_TRUE(obj.propertyExists("zero", PROP_EXISTS));
    ASSERT_TRUE(obj.propertyExists("false_val", PROP_EXISTS));

    // PROP_ISSET - all are ISSET (they're set, just falsy)
    ASSERT_TRUE(obj.propertyExists("empty_str", PROP_ISSET));
    ASSERT_TRUE(obj.propertyExists("zero", PROP_ISSET));
    ASSERT_TRUE(obj.propertyExists("false_val", PROP_ISSET));

    // PROP_EMPTY
    ASSERT_FALSE(obj.propertyExists("empty_str", PROP_EMPTY));
    ASSERT_FALSE(obj.propertyExists("zero", PROP_EMPTY));
    ASSERT_FALSE(obj.propertyExists("false_val", PROP_EMPTY));
}

// Test Object constructor from zend_object with Ctor::Move
TEST(object_extra, ctor_zend_object_move) {
    zval tmp;
    object_init(&tmp);
    Object obj(tmp.value.obj, Ctor::Move);
    ASSERT_TRUE(obj.isObject());
}

// Test Object constructor from zend_object with Ctor::Copy
TEST(object_extra, ctor_zend_object_copy) {
    zval tmp;
    object_init(&tmp);
    Object obj1(tmp.value.obj, Ctor::Copy);
    ASSERT_TRUE(obj1.isObject());

    Object obj2(tmp.value.obj, Ctor::Copy);
    ASSERT_TRUE(obj2.isObject());
    zval_ptr_dtor(&tmp);
}

// Test getClassName on various objects
TEST(object_extra, getClassName) {
    auto o1 = newObject("stdClass");
    ASSERT_STREQ(o1.getClassName().toCString(), "stdClass");

    auto o2 = newObject("ArrayObject");
    ASSERT_STREQ(o2.getClassName().toCString(), "ArrayObject");

    auto o3 = newObject("DateTime");
    ASSERT_STREQ(o3.getClassName().toCString(), "DateTime");
}

// Test hash() consistency (same object produces same hash)
TEST(object_extra, hash_consistency) {
    auto o1 = newObject("stdClass");
    o1.set("a", 1);
    auto h1 = o1.hash();
    auto h2 = o1.hash();
    ASSERT_EQ(h1.length(), 32);
    ASSERT_TRUE(h1.equals(h2));
}

// Test hash() differs for different objects
TEST(object_extra, hash_differs) {
    auto o1 = newObject("stdClass");
    o1.set("a", 1);
    auto h1 = o1.hash();

    auto o2 = newObject("stdClass");
    o2.set("b", 2);
    auto h2 = o2.hash();
    ASSERT_FALSE(h1.equals(h2));
}

// Test methodExists for inherited methods
TEST(object_extra, methodExists_inherited) {
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);
    auto obj = newObject("TestClass2");

    ASSERT_TRUE(obj.methodExists("test"));
    ASSERT_TRUE(obj.methodExists("fun"));  // inherited from parent
    ASSERT_FALSE(obj.methodExists("nonexistent"));
}

// Test instanceOf with class_entry overload
TEST(object_extra, instanceOf_ce) {
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);

    auto obj = newObject("TestClass2");
    ASSERT_TRUE(obj.instanceOf(getClassEntry("TestClass2")));
    ASSERT_TRUE(obj.instanceOf(getClassEntry("TestClass")));
    ASSERT_FALSE(obj.instanceOf(getClassEntry("DateTime")));
}

// Test clone and modify independently
TEST(object_extra, clone_independence) {
    auto o1 = newObject("stdClass");
    o1.set("x", 1);
    o1.set("y", 2);

    auto o2 = o1.clone();
    o2.set("x", 999);

    ASSERT_EQ(o1.get("x").toInt(), 1);
    ASSERT_EQ(o2.get("x").toInt(), 999);
    ASSERT_EQ(o1.get("y").toInt(), 2);
    ASSERT_EQ(o2.get("y").toInt(), 2);
}

// Test Object constructed from Variant (non-object throws)
TEST(object_extra, from_non_object_variant) {
    try_call(
        []() {
            var v(42);
            Object o(v);
        },
        "parameter 1 must be `object`, got `int`");
}

// Test Object constructed from null Variant (allowed)
TEST(object_extra, from_null_variant) {
    var v;
    Object o(v);
    ASSERT_TRUE(o.isNull() || o.isUndef());
}

// Test Object default constructor
TEST(object_extra, default_ctor) {
    Object o;
    ASSERT_TRUE(o.isUndef() || o.isNull());
    ASSERT_FALSE(static_cast<bool>(o));
}

TEST(object_extra, null_and_unset_are_false) {
    Object o = newObject("stdClass");
    ASSERT_TRUE(static_cast<bool>(o));

    o = php::null;
    ASSERT_TRUE(o.isNull());
    ASSERT_FALSE(static_cast<bool>(o));

    o = newObject("stdClass");
    ASSERT_TRUE(static_cast<bool>(o));
    o.unset();
    ASSERT_TRUE(o.isUndef());
    ASSERT_FALSE(static_cast<bool>(o));
}

// Test offsetGet with non-existent key on ArrayObject returns null
TEST(object_extra, offsetGet_nonexistent_key) {
    auto obj = newObject("ArrayObject");
    auto rs = obj.offsetGet(999);
    ASSERT_TRUE(rs.isNull());

    auto rs2 = obj.offsetGet("nonexistent_key");
    ASSERT_TRUE(rs2.isNull());
}

TEST(object_extra, temporary_dimension_result_is_released) {
    eval(R"PHP(
        $GLOBALS['phpx_dimension_result_destructed'] = 0;
        class PhpxDimensionResult {
            public function __destruct() {
                ++$GLOBALS['phpx_dimension_result_destructed'];
            }
        }
        class PhpxTemporaryArrayAccess implements ArrayAccess {
            public function offsetExists(mixed $offset): bool { return true; }
            public function offsetGet(mixed $offset): mixed { return new PhpxDimensionResult(); }
            public function offsetSet(mixed $offset, mixed $value): void {}
            public function offsetUnset(mixed $offset): void {}
        }
    )PHP");

    auto object = newObject("PhpxTemporaryArrayAccess");
    {
        auto result = object.offsetGet("object-api");
        ASSERT_TRUE(result.isObject());
    }
    ASSERT_EQ(global("phpx_dimension_result_destructed").toInt(), 1);

    var value = object;
    {
        auto result = value.item("variant-api", false);
        ASSERT_TRUE(result.isObject());
    }
    ASSERT_EQ(global("phpx_dimension_result_destructed").toInt(), 2);

    {
        auto result = value.item(1, false);
        ASSERT_TRUE(result.isObject());
    }
    ASSERT_EQ(global("phpx_dimension_result_destructed").toInt(), 3);

    {
        auto result = value.newItem();
        ASSERT_TRUE(result.isObject());
    }
    ASSERT_EQ(global("phpx_dimension_result_destructed").toInt(), 4);
}

// Test offsetSet on stdClass (not ArrayAccess)
// Test offsetSet on ArrayObject (implements ArrayAccess)
TEST(object_extra, offsetSet_array_object) {
    auto obj = newObject("ArrayObject");
    obj.offsetSet("key", "value");
    ASSERT_STREQ(obj.offsetGet("key").toCString(), "value");
}

// Test offsetExists on ArrayObject
TEST(object_extra, offsetExists_array_object) {
    auto obj = newObject("ArrayObject");
    obj.offsetSet("prop", 42);
    ASSERT_TRUE(obj.offsetExists("prop"));
    ASSERT_FALSE(obj.offsetExists("nonexistent"));
}

// Test appending to an array property through the generic Variant path.
TEST(object_extra, attr_newItem_empty_array_property) {
    auto obj = newObject("stdClass");
    Array inner;
    obj.set("emptylist", inner);
    obj.attr("emptylist", true).newItem() = "first";
    auto prop = obj.get("emptylist");
    ASSERT_TRUE(prop.isArray());
    Array inner_arr(prop);
    ASSERT_EQ(inner_arr.count(), 1);
    ASSERT_STREQ(inner_arr.offsetGet(0).toCString(), "first");
}

// Test call with no arguments
TEST(object_extra, call_no_args) {
    auto obj = newObject("DateTime", {"2020-06-15"});
    auto ts = obj.call("getTimestamp");
    ASSERT_GT(ts.toInt(), 0);
}

// Test Object via Variant copy construction
TEST(object_extra, variant_copy_construct) {
    auto obj = newObject("stdClass");
    obj.set("prop", 42);
    var v = obj;
    ASSERT_TRUE(v.isObject());
    Object obj2(v);
    ASSERT_TRUE(obj2.isObject());
    ASSERT_EQ(obj2.get("prop").toInt(), 42);
}

// Test count on non-Countable object (returns 0 for non-countable)
TEST(object_extra, count_non_countable) {
    auto obj = newObject("stdClass");
    ASSERT_EQ(obj.count(), 0);
}
