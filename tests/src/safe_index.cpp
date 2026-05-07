#include "phpx_test.h"
#include "phpx_std_array.h"

using namespace php;

TEST(safeIndex, valid_index) {
    EXPECT_EQ(safeIndex(0, 5), 0);
    EXPECT_EQ(safeIndex(2, 5), 2);
    EXPECT_EQ(safeIndex(4, 5), 4);
}

TEST(safeIndex, negative_index) {
    try_call([]() { safeIndex(-1, 5); }, "Array index out of bounds");
    try_call([]() { safeIndex(-5, 10); }, "Array index out of bounds");
}

TEST(safeIndex, out_of_bounds_index) {
    try_call([]() { safeIndex(5, 5); }, "Array index out of bounds");
    try_call([]() { safeIndex(10, 5); }, "Array index out of bounds");
    try_call([]() { safeIndex(100, 10); }, "Array index out of bounds");
}

TEST(safeIndex, edge_cases) {
    EXPECT_EQ(safeIndex(0, 1), 0);

    try_call([]() { safeIndex(0, 0); }, "Array index out of bounds");
    try_call([]() { safeIndex(1, 0); }, "Array index out of bounds");
}
