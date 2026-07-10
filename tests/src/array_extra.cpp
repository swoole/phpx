#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

// Test search with strict mode
TEST(array_extra, search_strict) {
    Array arr = create_map();
    ASSERT_STREQ(arr.search(3).toCString(), "php");
    ASSERT_STREQ(arr.search(3, true).toCString(), "php");

    // Strict search - 3L doesn't match "3"
    auto result = arr.search("3", true);
    ASSERT_TRUE(result.isFalse());
}

// Test contains with strict mode
TEST(array_extra, contains_strict) {
    Array arr;
    arr.append("1");
    arr.append("2");
    arr.append(3);

    ASSERT_TRUE(arr.contains("1"));
    ASSERT_TRUE(arr.contains("1", true));
    ASSERT_TRUE(arr.contains(3));
    ASSERT_TRUE(arr.contains(3, true));
    ASSERT_FALSE(arr.contains("3", true));
    ASSERT_FALSE(arr.contains(99));
    ASSERT_FALSE(arr.contains(99, true));
}

// Test isList for packed and non-packed arrays
TEST(array_extra, isList) {
    Array a1{1, 2, 3, 4, 5};
    ASSERT_TRUE(a1.isList());

    Array a2{{"a", "apple"}, {"b", "banana"}};
    ASSERT_FALSE(a2.isList());

    Array a3;
    ASSERT_TRUE(a3.empty());

    // Test after deletion, packed array becomes non-list
    Array a4{1, 2, 3};
    a4.del(1);
    ASSERT_FALSE(a4.isList());
}

// Test del with integer and string keys
TEST(array_extra, del) {
    Array arr = create_map();
    ASSERT_TRUE(arr.exists("php"));
    arr.del("php");
    ASSERT_FALSE(arr.exists("php"));

    Array arr2{1, 2, 3, 4};
    ASSERT_TRUE(arr2.exists(2));
    ASSERT_TRUE(arr2.del(2));
    ASSERT_FALSE(arr2.exists(2));

    // del non-existent key should return false
    ASSERT_FALSE(arr2.del(999));
}

// Test clean
TEST(array_extra, clean) {
    Array arr{1, 2, 3, 4, 5};
    ASSERT_EQ(arr.count(), 5);
    arr.clean();
    ASSERT_EQ(arr.count(), 0);
    ASSERT_TRUE(arr.empty());
}

// Test begin/end iterators
TEST(array_extra, begin_end) {
    Array arr{10, 20, 30, 40, 50};

    zend_ulong count = 0;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        ASSERT_EQ(it.value().toInt(), (int) (10 * (count + 1)));
        count++;
    }
    ASSERT_EQ(count, 5);

    // Empty array
    Array empty;
    ASSERT_TRUE(empty.begin() == empty.end());
}

// Test get with out-of-range index/lookup
TEST(array_extra, get) {
    Array arr{1, 2, 3};

    // Out of range index
    auto v1 = arr.get(999);
    ASSERT_TRUE(v1.isNull());

    // Non-existent key
    auto v2 = arr.get("nonexistent");
    ASSERT_TRUE(v2.isNull());

    // Valid index
    auto v3 = arr.get(1);
    ASSERT_EQ(v3.toInt(), 2);
}

// Test set with integer key and Variant key
TEST(array_extra, set) {
    Array arr;
    zend_ulong zero = 0;

    arr.set(zero, 100);
    ASSERT_EQ(arr.get(zero).toInt(), 100);

    zend_ulong five = 5;
    arr.set(five, "hello");
    ASSERT_STREQ(arr.get(five).toCString(), "hello");

    var key("key");
    arr.set(key, 999);
    ASSERT_EQ(arr.get("key").toInt(), 999);

    var fkey(2.7);  // float key truncates to 2
    arr.set(fkey, "float_key");
    ASSERT_STREQ(arr.get(2).toCString(), "float_key");
}

// Test operator[] with string key (uses ArrayItem)
TEST(array_extra, array_item_string_key) {
    Array arr;
    arr["name"] = "John";
    arr["age"] = 30;

    ASSERT_STREQ(arr.get("name").toCString(), "John");
    ASSERT_EQ(arr.get("age").toInt(), 30);

    // Update existing
    arr["name"] = "Jane";
    ASSERT_STREQ(arr.get("name").toCString(), "Jane");
}

// Test merge edge cases
TEST(array_extra, merge) {
    Array a{1, 2, 3};
    Array b;

    a.merge(b);
    ASSERT_EQ(a.count(), 3);

    b.merge(a);
    ASSERT_EQ(b.count(), 3);

    Array c{4, 5};
    a.merge(c);
    ASSERT_EQ(a.count(), 5);
}

// Test array copy construction
TEST(array_extra, copy_construct) {
    Array a{1, 2, 3};
    Array b(a);
    ASSERT_EQ(b.count(), 3);
    ASSERT_EQ(b.get(0).toInt(), 1);

    // Verify independence
    b.set(static_cast<zend_ulong>(0), 999);
    ASSERT_EQ(b.get(0).toInt(), 999);
    ASSERT_EQ(a.get(0).toInt(), 1);

    var v = a;
    Array c(v);
    ASSERT_EQ(c.count(), 3);
}

// Test array from zval pointer (null)
TEST(array_extra, from_null_zval) {
    var v;
    Array a(v.const_ptr());
    ASSERT_TRUE(a.isArray());
    ASSERT_EQ(a.count(), 0);
}

// Test sort with renumber option
TEST(array_extra, sort_renumber) {
    Array arr;
    zend_ulong five = 5, one = 1, three = 3;
    arr.set(five, "five");
    arr.set(one, "one");
    arr.set(three, "three");

    arr.sort(true);
    // After sort with renumber, should be numerically indexed
    ASSERT_EQ(arr.count(), 3);
    ASSERT_STREQ(arr[0].toCString(), "five");
    ASSERT_STREQ(arr[1].toCString(), "one");
    ASSERT_STREQ(arr[2].toCString(), "three");
}

// Test empty array slice
TEST(array_extra, slice_empty) {
    Array arr;
    auto s = arr.slice(0, 1);
    ASSERT_TRUE(s.empty());
    ASSERT_EQ(s.count(), 0);
}

// Test slice with negative length
TEST(array_extra, slice_negative) {
    Array arr{1, 2, 3, 4, 5};

    auto s1 = arr.slice(1, -2);
    ASSERT_EQ(s1.count(), 2);
    ASSERT_EQ(s1[0].toInt(), 2);
    ASSERT_EQ(s1[1].toInt(), 3);

    auto s2 = arr.slice(3, -1);
    ASSERT_EQ(s2.count(), 1);
    ASSERT_EQ(s2[0].toInt(), 4);
}

// Test join with empty array
TEST(array_extra, join_empty) {
    Array arr;
    auto s = arr.join(",");
    ASSERT_TRUE(s.isString());
    ASSERT_EQ(s.length(), 0);
}

TEST(array_extra, join_propagates_tostring_exception) {
    eval(R"PHP(
        class PhpxJoinThrowingValue {
            public function __toString(): string {
                throw new RuntimeException('join toString failed');
            }
        }
    )PHP");

    Array values{"prefix", newObject("PhpxJoinThrowingValue")};
    bool thrown = false;
    try {
        values.join(",");
    } catch (zend_object *) {
        thrown = true;
        auto exception = catchException();
        ASSERT_TRUE(str_contains(exception.call("getMessage"), "join toString failed").toBool());
    }
    if (!thrown && EG(exception)) {
        catchException();
    }
    ASSERT_TRUE(thrown);
}

// Test toArray with StdVector
TEST(array_extra, from_std_vector) {
    StdVector<int> vec{10, 20, 30};
    Array arr(vec);
    ASSERT_EQ(arr.count(), 3);
    ASSERT_EQ(arr[0].toInt(), 10);
    ASSERT_EQ(arr[1].toInt(), 20);
    ASSERT_EQ(arr[2].toInt(), 30);
}

// Test toArray with StdOrderedMap
TEST(array_extra, from_std_map) {
    StdOrderedMap<std::string, int> m;
    m["a"] = 1;
    m["b"] = 2;
    Array arr(m);
    ASSERT_EQ(arr.count(), 2);
    ASSERT_EQ(arr.get("a").toInt(), 1);
    ASSERT_EQ(arr.get("b").toInt(), 2);
}

// Test toArray helper with StdVector
TEST(array_extra, toArray_std_vector) {
    StdVector<std::string> vec{"hello", "world"};
    Array arr = php::toArray(vec);
    ASSERT_EQ(arr.count(), 2);
    ASSERT_STREQ(arr[0].toCString(), "hello");
    ASSERT_STREQ(arr[1].toCString(), "world");
}

// Test array convert from Std types via toArray
TEST(array_extra, toArray_from_types) {
    StdVector<int> vec{1, 2, 3};
    Array arr = php::toArray(vec);
    ASSERT_EQ(arr.count(), 3);

    StdOrderedMap<std::string, int> m;
    m["x"] = 10;
    m["y"] = 20;
    Array arr2 = php::toArray(m);
    ASSERT_EQ(arr2.count(), 2);
    ASSERT_EQ(arr2.get("x").toInt(), 10);
}

// Test array as Variant through length()
TEST(array_extra, variant_length_array) {
    Array arr{1, 2, 3, 4, 5};
    var v = arr;
    ASSERT_EQ(v.length(), 5);
}

// Test array append various types
TEST(array_extra, append_types) {
    Array arr;
    arr.append(42);
    arr.append(3.14);
    arr.append("string");
    arr.append(true);
    arr.append(false);

    ASSERT_EQ(arr.count(), 5);
    ASSERT_EQ(arr[0].toInt(), 42);
    ASSERT_EQ(arr[1].toFloat(), 3.14);
    ASSERT_STREQ(arr[2].toCString(), "string");
    ASSERT_TRUE(arr[3].toBool());
    ASSERT_FALSE(arr[4].toBool());
}

// Test contains with string key array
TEST(array_extra, contains_with_key_array) {
    Array arr = create_map();
    ASSERT_TRUE(arr.contains(1));
    ASSERT_TRUE(arr.contains(2));
    ASSERT_FALSE(arr.contains(999));
}

// Test empty check on array with items
TEST(array_extra, empty_check) {
    Array arr;
    ASSERT_TRUE(arr.empty());

    arr.append(1);
    ASSERT_FALSE(arr.empty());

    arr.del(0);
    ASSERT_TRUE(arr.empty());
}

// Test object converted to array
TEST(array_extra, toArray_object) {
    auto o = newObject("stdClass");
    o.set("name", "test");
    o.set("value", 42);

    var v = o;
    Array arr = php::toArray(v);
    ASSERT_TRUE(arr.isArray());
    ASSERT_TRUE(arr.exists("name"));
    ASSERT_EQ(arr.get("value").toInt(), 42);
}

// Test Array bad type via constructor
TEST(array_extra, construct_bad_type) {
    try_call(
        []() {
            var v(42);
            Array a(v.const_ptr());
        },
        "parameter 1 must be `array`, got `int`");
}

// Test toArray with closure
TEST(array_extra, toArray_closure) {
    auto c = eval("return function($x) { return $x * 2; };");
    var v = c;
    Array arr = php::toArray(v);
    ASSERT_TRUE(arr.isArray());
    ASSERT_EQ(arr.count(), 1);
}
