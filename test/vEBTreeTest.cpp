#include "vEBTree.h"
#include "gtest/gtest.h"

TEST(vEBTreeTest, InsertTest)
{
    vEBTree *tree = new vEBTree(16);
    tree->insert(3);
    EXPECT_TRUE(tree->member(3));
    EXPECT_FALSE(tree->member(5));

    tree->insert(5);
    EXPECT_TRUE(tree->member(5));
}

TEST(vEBTreeTest, MinMaxTest)
{
    vEBTree *tree = new vEBTree(16);
    tree->insert(15);
    tree->insert(2);
    EXPECT_EQ(tree->minimum(), 2);
    EXPECT_EQ(tree->maximum(), 15);
}

TEST(vEBTreeTest, DeleteTest)
{
    vEBTree *tree = new vEBTree(16);
    tree->insert(5);
    tree->insert(2);
    tree->remove(5);
    EXPECT_FALSE(tree->member(5));
    EXPECT_TRUE(tree->member(2));
}