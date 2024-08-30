#include <gtest/gtest.h>
#include "SplayTree.h"

TEST(SplayTreeTest, InsertAndFind) {
    SplayTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    EXPECT_TRUE(tree.find(10));
    EXPECT_TRUE(tree.find(20));
    EXPECT_TRUE(tree.find(30));
    EXPECT_FALSE(tree.find(40));
}

TEST(SplayTreeTest, SplayMechanism) {
    SplayTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    // Check the root after splaying
    EXPECT_EQ(tree.getRoot()->data, 30);

    // Test splay operation
    tree.find(10);
    EXPECT_EQ(tree.getRoot()->data, 10);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}