#include "phpx_test.h"

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
}

TEST(array, map) {
    Array array;
    array.set("c++", 1);
    array.set("java", 2);
    array.set("php", 3);
    array.set("golang", 4);
    array.set("node.js", 5);

    auto arr2 = array.slice(2, 2);
    ASSERT_EQ(arr2.count(), 2);
    ASSERT_EQ(arr2["php"].toInt(), 3);
}