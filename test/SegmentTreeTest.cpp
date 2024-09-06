#include "gtest/gtest.h"
#include "SegmentTree.h"
#include <vector>

TEST(SegmentTreeTest, BasicRangeQuery)
{
    std::vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(data);

    EXPECT_EQ(segTree.query(1, 3), 3);
    EXPECT_EQ(segTree.query(0, 5), 1);
}

TEST(SegmentTreeTest, UpdateAndQuery)
{
    std::vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(data);

    segTree.update(2, 0);
    EXPECT_EQ(segTree.query(1, 3), 0);
    EXPECT_EQ(segTree.query(0, 5), 0);
}
