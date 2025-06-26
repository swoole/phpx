#include "phpx_test.h"

using namespace php;

TEST(array, slice) {
    Array array;
    array.append(10);
    array.append(30);
    array.append(50);
    array.append(90);
    array.append(100);

    auto arr2 = array.slice(1, 3);
    ASSERT_EQ(arr2.count(), 3);
    ASSERT_EQ(arr2[0].toInt(), 30);
}
