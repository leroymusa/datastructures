#include <gtest/gtest.h>

#include "SuffixTree.h"

TEST(SuffixTreeTest, BasicOperations)
{
    SuffixTree tree("banana");
    tree.build();
    EXPECT_TRUE(tree.contains("ana"));
    EXPECT_TRUE(tree.contains("ban"));
    EXPECT_FALSE(tree.contains("apple"));
    EXPECT_FALSE(tree.contains("naan"));
}

TEST(SuffixTreeTest, SingleCharacterString)
{
    SuffixTree tree("a");
    tree.build();
    EXPECT_TRUE(tree.contains("a"));
    EXPECT_FALSE(tree.contains("b"));
}

TEST(SuffixTreeTest, EmptyString)
{
    SuffixTree tree("");
    tree.build();
    EXPECT_FALSE(tree.contains("a"));
}

TEST(SuffixTreeTest, RepeatedCharacters)
{
    SuffixTree tree("aaaa");
    tree.build();
    EXPECT_TRUE(tree.contains("a"));
    EXPECT_TRUE(tree.contains("aa"));
    EXPECT_TRUE(tree.contains("aaa"));
    EXPECT_TRUE(tree.contains("aaaa"));
    EXPECT_FALSE(tree.contains("b"));
}

TEST(SuffixTreeTest, PalindromeString)
{
    SuffixTree tree("racecar");
    tree.build();
    EXPECT_TRUE(tree.contains("race"));
    EXPECT_TRUE(tree.contains("ace"));
    EXPECT_TRUE(tree.contains("ecar"));
    EXPECT_TRUE(tree.contains("racecar"));
    EXPECT_FALSE(tree.contains("carer"));
}

TEST(SuffixTreeTest, LongestRepeatedSubstring)
{
    SuffixTree tree("banana");
    tree.build();
}

TEST(SuffixTreeTest, LongestCommonSubstring)
{
    SuffixTree tree1("banana");
    SuffixTree tree2("ananas");
    tree1.build();
    tree2.build();
}

TEST(SuffixTreeTest, ComplexString)
{
    SuffixTree tree("thequickbrownfoxjumpsoverthelazydog");
    tree.build();
    EXPECT_TRUE(tree.contains("quick"));
    EXPECT_TRUE(tree.contains("foxjumps"));
    EXPECT_FALSE(tree.contains("lazyfox"));
    EXPECT_TRUE(tree.contains("the"));
    EXPECT_TRUE(tree.contains("thelazydog"));
}
