#include "gtest/gtest.h"
#include "BloomFilter.h"

TEST(BloomFilterTest, BasicInsertAndContains)
{
    BloomFilter bf(100, 3);
    bf.insert("test");

    EXPECT_TRUE(bf.contains("test"));
    EXPECT_FALSE(bf.contains("random"));
}

TEST(BloomFilterTest, MultipleInserts)
{
    BloomFilter bf(200, 5);
    bf.insert("hello");
    bf.insert("world");

    EXPECT_TRUE(bf.contains("hello"));
    EXPECT_TRUE(bf.contains("world"));
    EXPECT_FALSE(bf.contains("nonexistent"));
}
