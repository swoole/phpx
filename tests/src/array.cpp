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

    arr.set("java", 666);
    ASSERT_EQ(arr.get("java").toInt(), 666);

    Array arr2 = create_list();
    arr2[2] = "golang";
    ASSERT_STREQ(arr2.get(2).toCString(), "golang");
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
    ChildResult r = run_in_child_capture_stdout([&arr1]() -> int {
        auto v = arr1.get(2);
        Array o(v);
        return 0;
    });
    var s(r.output);
    ASSERT_TRUE(str_contains(s, "parameter 1 must be `array`, got `string`").toBool());
}

TEST(array, ref) {
    Array a = {{"a", "apple"}, {"b", "banana"}};
    var ref = &a;
    a.set("c", "cherry");
    ASSERT_EQ(a.count(), 3);
    auto b = ref.toArray();
    ASSERT_EQ(b.count(), 2);
    ASSERT_EQ(b.length(), 2);
    ASSERT_EQ(ref.length(), 0);

    auto c = ref.getRefValue();
    ASSERT_EQ(c.length(), 2);
}

TEST(array, ref2) {
    Array numbers{99, 10, 7};
    var tmp_var_0 = numbers.toReference();
    php::call(php::sort, {tmp_var_0});
    ASSERT_EQ(tmp_var_0.offsetGet(0).toInt(), 7);
}

TEST(array, to_array) {
    var a = 10;
    auto arr = to_array(a);
    ASSERT_EQ(arr.length(), 1);
    ASSERT_EQ(arr.get(0).toInt(), 10);

    var s = "hello world";
    auto arr2 = to_array(s);
    ASSERT_EQ(arr2.length(), 1);
    ASSERT_STREQ(arr2.get(0).toCString(), "hello world");

    auto arr3 = to_array(arr2);
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
