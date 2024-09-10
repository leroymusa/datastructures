#include "gtest/gtest.h"
#include "Treap.h"

TEST(TreapTest, BasicInsertRemove)
{
    Treap<int> treap;
    treap.insert(10, 15);
    treap.insert(20, 30);
    treap.insert(5, 25);

    testing::internal::CaptureStdout();
    treap.inorder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "5 10 20 \n");
}

TEST(TreapTest, InorderTraversal)
{
    Treap<int> treap;
    treap.insert(10, 15);
    treap.insert(20, 30);
    treap.insert(5, 25);

    testing::internal::CaptureStdout();
    treap.inorder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "5 10 20 \n");
}
