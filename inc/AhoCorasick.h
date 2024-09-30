#ifndef AHOCORASICK_H
#define AHOCORASICK_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <string>

class AhoCorasick
{
public:
    AhoCorasick();

    void insert(const std::string &pattern);

    void buildFailureLinks();

    std::vector<std::pair<int, std::string>> search(const std::string &text);

private:
    struct TrieNode
    {
        std::unordered_map<char, TrieNode *> children;
        TrieNode *failureLink;
        std::vector<std::string> output;

        TrieNode() : failureLink(nullptr) {}
    };

    TrieNode *root;
};

#endif /* AHOCORASICK_H */
