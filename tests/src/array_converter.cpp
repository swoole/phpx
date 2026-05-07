#include "phpx_test.h"
#include "phpx_std_array.h"

using namespace php;

TEST(array_converter, 1d_int_array) {
    StdArray<Int, 5> arr = {1, 2, 3, 4, 5};
    Array parr = toArray(arr);

    ASSERT_EQ(parr.count(), 5);
    ASSERT_EQ(parr.get(0).toInt(), 1);
    ASSERT_EQ(parr.get(1).toInt(), 2);
    ASSERT_EQ(parr.get(2).toInt(), 3);
    ASSERT_EQ(parr.get(3).toInt(), 4);
    ASSERT_EQ(parr.get(4).toInt(), 5);
}

TEST(array_converter, 1d_float_array) {
    StdArray<Float, 4> arr = {1.1, 2.2, 3.3, 4.4};
    Array parr = toArray(arr);

    ASSERT_EQ(parr.count(), 4);
    EXPECT_DOUBLE_EQ(parr.get(0).toFloat(), 1.1);
    EXPECT_DOUBLE_EQ(parr.get(1).toFloat(), 2.2);
    EXPECT_DOUBLE_EQ(parr.get(2).toFloat(), 3.3);
    EXPECT_DOUBLE_EQ(parr.get(3).toFloat(), 4.4);
}

TEST(array_converter, 1d_bool_array) {
    StdArray<bool, 4> arr = {true, false, true, false};
    Array parr = toArray(arr);

    ASSERT_EQ(parr.count(), 4);
    ASSERT_TRUE(parr.get(0).toBool());
    ASSERT_FALSE(parr.get(1).toBool());
    ASSERT_TRUE(parr.get(2).toBool());
    ASSERT_FALSE(parr.get(3).toBool());
}

TEST(array_converter, 1d_string_array) {
    StdArray<std::string, 3> arr = {"hello", "world", "php"};
    Array parr = toArray(arr);

    ASSERT_EQ(parr.count(), 3);
    ASSERT_STREQ(parr.get(0).toCString(), "hello");
    ASSERT_STREQ(parr.get(1).toCString(), "world");
    ASSERT_STREQ(parr.get(2).toCString(), "php");
}

TEST(array_converter, 2d_int_array) {
    StdArray<StdArray<Int, 3>, 2> arr = {{{1, 2, 3}, {4, 5, 6}}};
    Array parr = toArray(arr);

    ASSERT_EQ(parr.count(), 2);

    Array row0 = toArray(parr.get(0));
    ASSERT_EQ(row0.count(), 3);
    ASSERT_EQ(row0.get(0).toInt(), 1);
    ASSERT_EQ(row0.get(1).toInt(), 2);
    ASSERT_EQ(row0.get(2).toInt(), 3);

    Array row1 = toArray(parr.get(1));
    ASSERT_EQ(row1.count(), 3);
    ASSERT_EQ(row1.get(0).toInt(), 4);
    ASSERT_EQ(row1.get(1).toInt(), 5);
    ASSERT_EQ(row1.get(2).toInt(), 6);
}

TEST(array_converter, 2d_large_array) {
    StdArray<StdArray<Int, 10>, 100> arr;

    for (size_t i = 0; i < 100; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            arr[i][j] = static_cast<Int>(i * 10 + j);
        }
    }

    Array parr = toArray(arr);
    ASSERT_EQ(parr.count(), 100);

    Array row0 = toArray(parr.get(0));
    ASSERT_EQ(row0.count(), 10);
    ASSERT_EQ(row0.get(0).toInt(), 0);
    ASSERT_EQ(row0.get(9).toInt(), 9);

    Array row50 = toArray(parr.get(50));
    ASSERT_EQ(row50.count(), 10);
    ASSERT_EQ(row50.get(0).toInt(), 500);
    ASSERT_EQ(row50.get(9).toInt(), 509);

    Array row99 = toArray(parr.get(99));
    ASSERT_EQ(row99.count(), 10);
    ASSERT_EQ(row99.get(0).toInt(), 990);
    ASSERT_EQ(row99.get(9).toInt(), 999);
}

TEST(array_converter, 3d_int_array) {
    StdArray<StdArray<StdArray<Int, 2>, 2>, 2> arr = {{{{{1, 2}, {3, 4}}}, {{{5, 6}, {7, 8}}}}};

    Array parr = toArray(arr);
    ASSERT_EQ(parr.count(), 2);

    Array level1_0 = toArray(parr.get(0));
    Array level2_0 = toArray(level1_0.get(0));
    ASSERT_EQ(level2_0.get(0).toInt(), 1);
    ASSERT_EQ(level2_0.get(1).toInt(), 2);

    Array level2_1 = toArray(level1_0.get(1));
    ASSERT_EQ(level2_1.get(0).toInt(), 3);
    ASSERT_EQ(level2_1.get(1).toInt(), 4);

    Array level1_1 = toArray(parr.get(1));
    Array level2_2 = toArray(level1_1.get(0));
    ASSERT_EQ(level2_2.get(0).toInt(), 5);
    ASSERT_EQ(level2_2.get(1).toInt(), 6);

    Array level2_3 = toArray(level1_1.get(1));
    ASSERT_EQ(level2_3.get(0).toInt(), 7);
    ASSERT_EQ(level2_3.get(1).toInt(), 8);
}

TEST(array_converter, empty_array) {
    StdArray<Int, 0> arr = {};
    Array parr = toArray(arr);

    ASSERT_EQ(parr.count(), 0);
    ASSERT_TRUE(parr.empty());
}

TEST(array_converter, single_element_array) {
    StdArray<Int, 1> arr = {42};
    Array parr = toArray(arr);

    ASSERT_EQ(parr.count(), 1);
    ASSERT_EQ(parr.get(0).toInt(), 42);
}

TEST(array_converter, nested_different_sizes) {
    StdArray<StdArray<Int, 5>, 3> arr;

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 5; ++j) {
            arr[i][j] = static_cast<Int>(i + j);
        }
    }

    Array parr = toArray(arr);
    ASSERT_EQ(parr.count(), 3);

    for (size_t i = 0; i < 3; ++i) {
        Array row = toArray(parr.get(i));
        ASSERT_EQ(row.count(), 5);
        for (size_t j = 0; j < 5; ++j) {
            EXPECT_EQ(row.get(j).toInt(), static_cast<Int>(i + j));
        }
    }
}
