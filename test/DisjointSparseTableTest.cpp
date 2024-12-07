#include "DisjointSparseTable.h"
#include <gtest/gtest.h>
#include <algorithm>
#include <numeric>

TEST(DisjointSparseTableTest, RangeMinQuery)
{
    std::vector<int> data = {5, 2, 4, 3, 1, 6, 7};
    DisjointSparseTable dst(data, [](int a, int b)
                            { return std::min(a, b); });

    EXPECT_EQ(dst.query(0, 2), 2);
    EXPECT_EQ(dst.query(3, 4), 1);
    EXPECT_EQ(dst.query(1, 6), 1);
}

TEST(DisjointSparseTableTest, RangeMaxQuery)
{
    std::vector<int> data = {5, 2, 4, 3, 1, 6, 7};
    DisjointSparseTable dst(data, [](int a, int b)
                            { return std::max(a, b); });

    EXPECT_EQ(dst.query(0, 2), 5);
    EXPECT_EQ(dst.query(3, 4), 3);
    EXPECT_EQ(dst.query(1, 6), 7);
}

TEST(DisjointSparseTableTest, GCDQuery)
{
    std::vector<int> data = {9, 6, 3, 12, 18, 15};
    DisjointSparseTable dst(data, [](int a, int b)
                            { return std::gcd(a, b); });

    EXPECT_EQ(dst.query(0, 2), 3);
    EXPECT_EQ(dst.query(2, 4), 3);
    EXPECT_EQ(dst.query(0, 5), 3);
}
