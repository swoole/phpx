#include "phpx_test.h"
#include "phpx_helper.h"

using namespace php;

TEST(safeIndex, valid_index) {
    // 测试有效的索引
    EXPECT_EQ(safeIndex(0, 5), 0);
    EXPECT_EQ(safeIndex(2, 5), 2);
    EXPECT_EQ(safeIndex(4, 5), 4);
}

TEST(safeIndex, negative_index) {
    // 测试负数索引 - 应该抛出异常
    EXPECT_THROW(safeIndex(-1, 5), std::exception);
    EXPECT_THROW(safeIndex(-5, 10), std::exception);
}

TEST(safeIndex, out_of_bounds_index) {
    // 测试超出边界的索引 - 应该抛出异常
    EXPECT_THROW(safeIndex(5, 5), std::exception);
    EXPECT_THROW(safeIndex(10, 5), std::exception);
    EXPECT_THROW(safeIndex(100, 10), std::exception);
}

TEST(safeIndex, edge_cases) {
    // 测试边界情况
    EXPECT_EQ(safeIndex(0, 1), 0);  // 最小有效索引

    // 大小为0的数组，任何索引都应该抛出异常
    EXPECT_THROW(safeIndex(0, 0), std::exception);
    EXPECT_THROW(safeIndex(1, 0), std::exception);
}
