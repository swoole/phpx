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

    auto arr2 = array.slice(1, 3);
    ASSERT_EQ(arr2.count(), 3);
    ASSERT_EQ(arr2[0].toInt(), 30);

    array.sort();
    ASSERT_EQ(array[0].toInt(), 10);

    array.append(3.14);
    ASSERT_EQ(array.count(), 6);
}

TEST(array, map) {
    Array array = create_map();

    auto arr2 = array.slice(2, 2);
    ASSERT_EQ(arr2.count(), 2);
    ASSERT_EQ(arr2["php"].toInt(), 3);
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
}

TEST(array, foreach) {
    Array arr = create_list();
    std::vector<std::string> list;
    for (auto i = arr.begin(); i != arr.end(); i++) {
        list.push_back(i.value().toString());
    }
    ASSERT_EQ(list.size(), 5);

    arr.del(3);
    list.clear();
    for (auto i = arr.begin(); i != arr.end(); i++) {
        list.push_back(i.value().toString());
    }
    ASSERT_EQ(list.size(), 4);
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