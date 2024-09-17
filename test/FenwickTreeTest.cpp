#include "FenwickTree.h"
#include <gtest/gtest.h>

TEST(FenwickTreeTest, UpdateAndQuery)
{
    FenwickTree fenwick(10);
    fenwick.update(0, 5);
    fenwick.update(1, 3);
    fenwick.update(2, 7);
    EXPECT_EQ(fenwick.query(0), 5);
    EXPECT_EQ(fenwick.query(1), 8);
    EXPECT_EQ(fenwick.query(2), 15);
}

TEST(FenwickTreeTest, RangeQuery)
{
    FenwickTree fenwick(10);
    fenwick.update(0, 5);
    fenwick.update(1, 3);
    fenwick.update(2, 7);
    EXPECT_EQ(fenwick.rangeQuery(0, 2), 15);
    EXPECT_EQ(fenwick.rangeQuery(1, 2), 10);
}