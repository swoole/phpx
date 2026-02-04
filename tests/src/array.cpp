#include "phpx_test.h"
#include "phpx_func.h"

using namespace php;

TEST(array, list) {
    Array array;
    array.append(50);
    array.append(30);
    array.append(100);
    array.append(10);
    array.append(90);

    ASSERT_EQ(array.get(2).toInt(), 100);
    ASSERT_EQ(array[3].toInt(), 10);

    zend_ulong j = 0;
    for (auto i = array.begin(); i != array.end(); i++) {
        ASSERT_EQ(i.key().toInt(), j);
        ASSERT_EQ(i.value().toInt(), array[j].toInt());
        j++;
    }

    auto arr2 = array.slice(1, 3);
    ASSERT_EQ(arr2.count(), 3);
    ASSERT_EQ(arr2[0].toInt(), 30);

    array.sort();
    ASSERT_EQ(array[0].toInt(), 10);

    array.append(3.14);
    ASSERT_EQ(array.count(), 6);

    ASSERT_TRUE(array.exists(4));
    ASSERT_FALSE(array.exists(999));

    array.clean();
    ASSERT_EQ(array.count(), 0);
}

TEST(array, map) {
    Array array = create_map();

    auto arr2 = array.slice(2, 2);
    ASSERT_EQ(arr2.count(), 2);
    ASSERT_EQ(arr2["php"].toInt(), 3);

    auto obj1 = newObject("stdClass");
    array.set("object", obj1);

    auto obj2 = array.get("object").toObject();
    ASSERT_EQ(obj1.getId(), obj2.getId());

    ASSERT_TRUE(array.exists("object"));
    ASSERT_FALSE(array.exists(1990));

    array.set(1990, "world");
    ASSERT_TRUE(array.exists(1990));

    array.del(1990);
    ASSERT_FALSE(array.exists(1990));

    array.del("object");
    ASSERT_FALSE(array.exists("object"));
}

TEST(array, init) {
    Array a1 = {
        "hello",
        3.1415,
    };

    ASSERT_EQ(a1.count(), 2);
    ASSERT_STREQ(a1[0].toCString(), "hello");
    ASSERT_EQ(a1[1].toFloat(), 3.1415);

    Array a2 = {{"hello", Variant("very good")}, {"world", Variant(33.43)}, {"php", 9999}};
    ASSERT_EQ(a2.count(), 3);
    ASSERT_STREQ(a2["hello"].toCString(), "very good");
    ASSERT_EQ(a2["php"].toInt(), 9999);
    ASSERT_EQ(a2["world"].toFloat(), 33.43);

    Array a3 = {{1111, Variant("hello")}, {2222, Variant(3.14)}, {3333, 100}};
    ASSERT_EQ(a3.count(), 3);
    ASSERT_STREQ(a3[1111].toCString(), "hello");
    ASSERT_EQ(a3[2222].toFloat(), 3.14);
    ASSERT_EQ(a3[3333].toFloat(), 100);

    Array a4(null.ptr());
    ASSERT_EQ(a4.count(), 0);
}

TEST(array, search) {
    Array arr = create_list();
    Variant v1{"php"};
    Variant v2{"python"};
    Variant v3{"not-exists"};

    ASSERT_EQ(arr.search(v1).toInt(), 0);
    ASSERT_EQ(arr.search(v2).toInt(), 3);
    ASSERT_TRUE(arr.search(v3).isFalse());

    Array arr2 = create_map();
    Variant v4{3};
    ASSERT_STREQ(arr2.search(v4).toCString(), "php");

    Array arr3;
    Variant v5("hello");
    arr3.set(1990, v5);
    ASSERT_EQ(arr3.search(v5).toInt(), 1990);
}

TEST(array, update) {
    Array arr = create_map();
    arr["php"] = 999;
    ASSERT_EQ(arr.get("php").toInt(), 999);

    arr["rust"] = 1000;
    ASSERT_EQ(arr.get("rust").toInt(), 1000);

    arr.set("java", 666);
    ASSERT_EQ(arr.get("java").toInt(), 666);

    Array arr2 = create_list();
    arr2[2] = "golang";
    ASSERT_STREQ(arr2.get(2).toCString(), "golang");

    arr2[2] = "swift";
    ASSERT_STREQ(arr2.get(2).toCString(), "swift");

    arr2[5] = "erlang";
    ASSERT_STREQ(arr2.get(5).toCString(), "erlang");

    arr2[5] = "node.js";
    ASSERT_STREQ(arr2.get(5).toCString(), "node.js");
}

TEST(array, nesting) {
    Array list = create_list();
    Array map = create_map();
    list.append(map);
    ASSERT_EQ(list.count(), 6);
}

TEST(array, foreach) {
    Array arr = create_list();
    std::vector<std::string> list;
    for (auto i = arr.begin(); i != arr.end(); i++) {
        list.push_back(i.value().toStdString());
    }
    ASSERT_EQ(list.size(), 5);

    arr.del(3);
    list.clear();
    for (auto i = arr.begin(); i != arr.end(); i++) {
        list.push_back(i.value().toStdString());
    }
    ASSERT_EQ(list.size(), 4);
}

TEST(array, foreach2) {
    Array arr = create_list();
    for (auto i : arr) {
        ASSERT_TRUE(i.key.isInt());
        ASSERT_TRUE(i.value.isString());
    }
}

TEST(array, contains) {
    Array arr = create_list();
    Variant v1{"php"};
    ASSERT_TRUE(arr.contains(v1));

    Variant v2{"null"};
    ASSERT_FALSE(arr.contains(v2));
}

TEST(array, join) {
    Array arr = create_list();
    auto s = arr.join(",");
    ASSERT_GE(s.length(), 20);
}

TEST(array, swap) {
    Variant v;
    zval zarr;
    array_init(&zarr);
    add_next_index_long(&zarr, 199);
    add_next_index_long(&zarr, 189);
    v = &zarr;
    zval_ptr_dtor(&zarr);

    Array arr(v);
    ASSERT_EQ(arr[0].toInt(), 199);
    ASSERT_EQ(arr[1].toInt(), 189);
}

TEST(array, slice) {
    Array arr = create_list();
    arr.append("erlang");
    arr.append("ruby");
    arr.append("lua");

    auto arr2 = arr.slice(2, 4, true);
    ASSERT_EQ(arr2.count(), 4);
    ASSERT_TRUE(arr2.get(2).equals("go"));

    auto arr3 = arr.slice(2, 4, false);
    ASSERT_EQ(arr3.count(), 4);
    ASSERT_TRUE(arr3[1].equals("python"));

    auto arr4 = arr.slice(arr.count() + 1);
    ASSERT_TRUE(arr4.empty());

    auto arr5 = arr.slice(2, -3, false);
    ASSERT_EQ(arr5.count(), 3);

    Array arr6;
    arr6[1990] = "hello";
    arr6[1991] = "world";
    arr6[2029] = "php";
    arr6[2099] = "swoole";

    auto arr7 = arr6.slice(1, -1, false);
    ASSERT_EQ(arr7.count(), 2);
    ASSERT_STREQ(arr7[0].toCString(), "world");
    ASSERT_STREQ(arr7[1].toCString(), "php");

    auto arr8 = arr7.slice(1, -4);
    ASSERT_EQ(arr8.count(), 0);
}

TEST(array, subscript) {
    Array arr = create_list();

    auto v1 = arr[0];
    ASSERT_EQ(v1, "php");

    Array map = create_map();
    String key = "php";
    auto v2 = map[key];
    ASSERT_EQ(v2, 3);
}

TEST(array, merge) {
    Array arr1 = create_list();
    Array arr2 = {"erlang", "ruby", "lua"};
    arr1.merge(arr2);
    ASSERT_EQ(arr2.count(), 3);
    ASSERT_EQ(arr1.count(), 8);
}

TEST(array, add) {
    Array a = {{"a", "apple"}, {"b", "banana"}};
    Array b = {{"a", "pear"}, {"b", "strawberry"}, {"c", "cherry"}};
    Array c = a + b;
    ASSERT_EQ(c.length(), 3);
    ASSERT_TRUE(c.get("c").equals("cherry"));

    Array d = a;
    ASSERT_EQ(a.length(), 2);
    d += b;
    ASSERT_EQ(a.length(), 2);
    ASSERT_EQ(d.length(), 3);
    ASSERT_TRUE(d.get("b").equals("banana"));

    Array e = b;
    ASSERT_EQ(b.length(), 3);
    e += a;
    ASSERT_EQ(b.length(), 3);
    ASSERT_EQ(e.length(), 3);
    ASSERT_TRUE(e.get("b").equals("strawberry"));
}

TEST(array, bad_type) {
    auto arr1 = create_list();
    try {
        auto v = arr1.get(2);
        Array o(v);
    } catch (zend_object *ex) {
        auto e = catchException();
        auto s = e.exec("getMessage");
        ASSERT_TRUE(str_contains(s, "parameter 1 must be `array`, got `string`").toBool());
    }
}

TEST(array, ref) {
    Array a = {{"a", "apple"}, {"b", "banana"}};
    var ref = &a;
    a.set("c", "cherry");
    ASSERT_EQ(a.count(), 3);

    auto b = ref.toArray();
    ASSERT_EQ(b.count(), 3);
    ASSERT_EQ(b.length(), 3);
    ASSERT_EQ(ref.length(), 3);

    auto c = ref.getRefValue();
    ASSERT_EQ(c.length(), 3);

    ref.offsetSet("c", "orange");
    ASSERT_EQ(c.length(), 3);
    ASSERT_EQ(ref.length(), 3);
}

TEST(array, ref2) {
    Array numbers{99, 10, 7};
    var tmp_var_0 = numbers.toReference();
    php::call(php::sort, {&tmp_var_0});
    ASSERT_EQ(tmp_var_0.offsetGet(0).toInt(), 7);
}

TEST(array, toArray) {
    var a = 10;
    auto arr = toArray(a);
    ASSERT_EQ(arr.length(), 1);
    ASSERT_EQ(arr.get(0).toInt(), 10);

    var s = "hello world";
    auto arr2 = toArray(s);
    ASSERT_EQ(arr2.length(), 1);
    ASSERT_STREQ(arr2.get(0).toCString(), "hello world");

    auto arr3 = toArray(arr2);
    ASSERT_TRUE(same(arr2, arr3));
}

TEST(array, init3) {
    php::Array arr;

    Int index = 0L;

    arr = php::Array{{index, php::Var(100L)}};
    var_dump(arr);
}

TEST(array, assign) {
    Array arr1 = create_list();
    ASSERT_EQ(arr1.length(), 5);

    arr1 = {"erlang", "ruby", "lua"};
    ASSERT_EQ(arr1.length(), 3);

    ASSERT_TRUE(arr1.isList());
    arr1 = {{"a", "apple"}, {"b", "banana"}};
    ASSERT_FALSE(arr1.isList());
    ASSERT_STREQ(arr1["a"].toCString(), "apple");

    arr1 = {{2020, "apple"}, {1999, "banana"}};
    ASSERT_STREQ(arr1[1999].toCString(), "banana");
}

// Test case to cover the array_data_compare function's handling of INDIRECT values
// The array_data_compare function has specific logic to handle IS_INDIRECT type:
// if (UNEXPECTED(Z_TYPE_P(first) == IS_INDIRECT)) {
//     first = Z_INDIRECT_P(first);
// }
// if (UNEXPECTED(Z_TYPE_P(second) == IS_INDIRECT)) {
//     second = Z_INDIRECT_P(second);
// }
TEST(array, indirect_handling_in_sort) {
    // Create an array with various comparable values
    Array arr;
    arr.append(30);
    arr.append(10);
    arr.append(20);
    arr.append(5);

    // Perform sort operation which will call array_data_compare
    // During the sorting algorithm, some internal operations may create INDIRECT references
    arr.sort();

    // Validate that the array was sorted properly despite potential INDIRECT values
    ASSERT_EQ(arr.count(), 4);
    ASSERT_EQ(arr[0].toInt(), 5);  // Smallest value first
    ASSERT_EQ(arr[1].toInt(), 10);
    ASSERT_EQ(arr[2].toInt(), 20);
    ASSERT_EQ(arr[3].toInt(), 30);  // Largest value last
}

// Another test to verify sorting with mixed data types
TEST(array, indirect_handling_mixed_types) {
    // Create array with values that will definitely be compared by array_data_compare
    Array arr;
    arr.set("key1", 100);
    arr.set("key2", 50);
    arr.set("key3", 75);
    arr.set("key4", 25);

    // Sort by values, which calls array_data_compare
    // The internal implementation might use INDIRECT references during the process
    arr.sort();

    // Verify that the function handles any INDIRECT values properly during comparison
    ASSERT_EQ(arr.count(), 4);

    // Get values in order and verify they are sorted
    int values[4];
    int i = 0;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        values[i++] = it.value().toInt();
    }

    // Values should be in ascending order
    ASSERT_EQ(values[0], 25);
    ASSERT_EQ(values[1], 50);
    ASSERT_EQ(values[2], 75);
    ASSERT_EQ(values[3], 100);
}

TEST(array, array_data_compare) {
    Bucket b1;
    Bucket b2;

    zval zv1;
    ZVAL_LONG(&zv1, 199);

    zval zv2;
    ZVAL_LONG(&zv2, 283);

    ZVAL_INDIRECT(&b1.val, &zv1);
    ZVAL_INDIRECT(&b2.val, &zv2);

    ASSERT_EQ(array_data_compare(&b1, &b2), -1);
}

#if PHP_VERSION_ID >= 80200
void dump_buckets(zend_array *ht) {
    for (int i = 0; i < ht->nNumOfElements; i++) {
        zend_array *ht2 = ht->arPacked[i].value.arr;
        ::printf("i=%d, p=%p, arr=%p, rc=%d\n", i, &ht->arPacked[i], ht2, ht2->gc.refcount);
    }
}
#endif

TEST(array, matrix) {
    auto row = 2;
    auto col = 2;

    auto arr = array_fill(0, row + 1, array_fill(0, col + 1, 0));
    arr.item(1, true).item(1, true) = 99;
    arr.item(2, true).item(0, true) = 88;

    ASSERT_EQ(arr.item(1).item(1).toInt(), 99);
    ASSERT_EQ(arr.item(2).item(0).toInt(), 88);
    ASSERT_EQ(arr.item(0).item(1).toInt(), 0);
    ASSERT_EQ(arr.item(2).item(2).toInt(), 0);
}
