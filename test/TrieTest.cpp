#include "Trie.h"
#include <gtest/gtest.h>

TEST(TrieTest, InsertAndSearch)
{
    Trie trie;
    trie.insert("apple");
    ASSERT_TRUE(trie.search("apple"));
    ASSERT_FALSE(trie.search("app"));
    ASSERT_TRUE(trie.startsWith("app"));

    trie.insert("app");
    ASSERT_TRUE(trie.search("app"));
}

TEST(TrieTest, SearchNonExistentWord)
{
    Trie trie;
    trie.insert("hello");
    ASSERT_FALSE(trie.search("hell"));
    ASSERT_TRUE(trie.search("hello"));
    ASSERT_FALSE(trie.search("world"));
}

TEST(TrieTest, PrefixTest)
{
    Trie trie;
    trie.insert("car");
    trie.insert("card");
    ASSERT_TRUE(trie.startsWith("ca"));
    ASSERT_TRUE(trie.startsWith("car"));
    ASSERT_FALSE(trie.startsWith("care"));
}