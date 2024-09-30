#include "AhoCorasick.h"
#include <gtest/gtest.h>

TEST(AhoCorasickTest, PatternMatching)
{
    AhoCorasick ac;

    ac.insert("he");
    ac.insert("she");
    ac.insert("his");
    ac.insert("hers");

    ac.buildFailureLinks();

    std::string text = "ahishers";
    std::vector<std::pair<int, std::string>> results = ac.search(text);

    std::vector<std::pair<int, std::string>> expected = {
        {1, "his"},
        {3, "she"},
        {4, "he"},
        {4, "hers"}};

    EXPECT_EQ(results, expected);
}
