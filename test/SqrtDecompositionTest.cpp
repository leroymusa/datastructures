#include "SqrtDecomposition.h"
#include <gtest/gtest.h>
#include <vector>

TEST(SqrtDecompositionTest, BasicRangeQuery)
{
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SqrtDecomposition sqrtDecomp(data);

    EXPECT_EQ(sqrtDecomp.query(0, 4), 15);
    EXPECT_EQ(sqrtDecomp.query(5, 9), 40);
}

TEST(SqrtDecompositionTest, UpdateAndQuery)
{
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SqrtDecomposition sqrtDecomp(data);

    sqrtDecomp.update(4, 10);
    EXPECT_EQ(sqrtDecomp.query(0, 4), 20);
    EXPECT_EQ(sqrtDecomp.query(4, 9), 50);
}

TEST(SqrtDecompositionTest, LargeRangeQuery)
{
    std::vector<int> data(1000, 1);
    SqrtDecomposition sqrtDecomp(data);

    EXPECT_EQ(sqrtDecomp.query(0, 999), 1000);
}

TEST(SqrtDecompositionTest, FullArrayQueryAfterUpdates)
{
    std::vector<int> data(1000, 1);
    SqrtDecomposition sqrtDecomp(data);

    sqrtDecomp.update(500, 10);
    sqrtDecomp.update(700, 15);
    EXPECT_EQ(sqrtDecomp.query(0, 999), 1000 + 9 + 14);
}
