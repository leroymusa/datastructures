#include "gtest/gtest.h"
#include "DisjointSet.h"

TEST(DisjointSetTest, UnionFindBasic)
{
    DisjointSet ds(10);

    ds.unionSets(1, 2);
    ds.unionSets(3, 4);
    ds.unionSets(2, 3);

    EXPECT_TRUE(ds.connected(1, 4));
    EXPECT_FALSE(ds.connected(1, 5));
}

TEST(DisjointSetTest, UnionFindPathCompression)
{
    DisjointSet ds(5);

    ds.unionSets(0, 1);
    ds.unionSets(1, 2);
    ds.unionSets(3, 4);

    EXPECT_EQ(ds.find(0), ds.find(2));
    EXPECT_EQ(ds.find(3), ds.find(4));
    EXPECT_NE(ds.find(0), ds.find(3));
}
