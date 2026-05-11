#include "phpx_test.h"

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

TEST(array_converter, std_vector_int) {
    StdVector<Int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.offsetSet(1, 42);

    ASSERT_EQ(vec.size(), 3);
    ASSERT_EQ(vec.offsetGet(0), 10);
    ASSERT_EQ(vec.offsetGet(1), 42);
    ASSERT_EQ(vec[2], 30);

    Array parr = toArray(vec);
    ASSERT_EQ(parr.count(), 3);
    ASSERT_EQ(parr.get(0).toInt(), 10);
    ASSERT_EQ(parr.get(1).toInt(), 42);
    ASSERT_EQ(parr.get(2).toInt(), 30);
}

TEST(array_converter, std_vector_float_with_size) {
    StdVector<Float> vec(3);
    vec.offsetSet(0, 1.25);
    vec.offsetSet(2, 3.75);

    Array parr = toArray(vec);
    ASSERT_EQ(parr.count(), 3);
    EXPECT_DOUBLE_EQ(parr.get(0).toFloat(), 1.25);
    EXPECT_DOUBLE_EQ(parr.get(1).toFloat(), 0.0);
    EXPECT_DOUBLE_EQ(parr.get(2).toFloat(), 3.75);
}

TEST(array_converter, std_map_int_key) {
    StdMap<Int> map;
    map.offsetSet(10, 100);
    map.offsetSet(20, 200);
    map.offsetGet(20) += 22;

    ASSERT_EQ(map.size(), 2);
    ASSERT_EQ(map.offsetGet(10), 100);
    ASSERT_EQ(map[20], 222);

    Array parr = toArray(map);
    ASSERT_EQ(parr.count(), 2);
    ASSERT_EQ(parr.get(10).toInt(), 100);
    ASSERT_EQ(parr.get(20).toInt(), 222);
}

TEST(array_converter, std_map_string_key) {
    StdMap<Int, Str> map;
    map.offsetSet("alpha", 10);
    map.offsetSet("beta", 20);
    map.offsetGet("beta") += 22;

    ASSERT_EQ(map.size(), 2);
    ASSERT_EQ(map.offsetGet("alpha"), 10);
    ASSERT_EQ(map[String("beta")], 42);

    Array parr = toArray(map);
    ASSERT_EQ(parr.count(), 2);
    ASSERT_EQ(parr.get("alpha").toInt(), 10);
    ASSERT_EQ(parr.get("beta").toInt(), 42);
}

TEST(array_converter, std_unordered_map_int_key) {
    StdUnorderedMap<Float> map;
    map.offsetSet(7, 1.5);
    map.offsetSet(9, 2.5);
    map.offsetGet(9) += 0.25;

    ASSERT_EQ(map.size(), 2);
    EXPECT_DOUBLE_EQ(map.offsetGet(7), 1.5);
    EXPECT_DOUBLE_EQ(map[9], 2.75);

    Array parr = toArray(map);
    ASSERT_EQ(parr.count(), 2);
    EXPECT_DOUBLE_EQ(parr.get(7).toFloat(), 1.5);
    EXPECT_DOUBLE_EQ(parr.get(9).toFloat(), 2.75);
}

TEST(array_converter, std_unordered_map_string_key) {
    StdUnorderedMap<Float, Str> map;
    map.offsetSet("alpha", 1.5);
    map.offsetSet("beta", 2.5);
    map.offsetGet("beta") += 0.25;

    ASSERT_EQ(map.size(), 2);
    EXPECT_DOUBLE_EQ(map.offsetGet("alpha"), 1.5);
    EXPECT_DOUBLE_EQ(map[String("beta")], 2.75);

    Array parr = toArray(map);
    ASSERT_EQ(parr.count(), 2);
    EXPECT_DOUBLE_EQ(parr.get("alpha").toFloat(), 1.5);
    EXPECT_DOUBLE_EQ(parr.get("beta").toFloat(), 2.75);
}

TEST(array_converter, nested_std_containers) {
    StdVector<StdMap<Int>> rows(2);
    rows.offsetGet(0).offsetSet(10, 100);
    rows.offsetGet(0).offsetSet(20, 200);
    rows.offsetGet(1).offsetSet(30, 300);

    Array parr = toArray(rows);
    ASSERT_EQ(parr.count(), 2);

    Array row0 = toArray(parr.get(0));
    ASSERT_EQ(row0.count(), 2);
    ASSERT_EQ(row0.get(10).toInt(), 100);
    ASSERT_EQ(row0.get(20).toInt(), 200);

    Array row1 = toArray(parr.get(1));
    ASSERT_EQ(row1.count(), 1);
    ASSERT_EQ(row1.get(30).toInt(), 300);
}
