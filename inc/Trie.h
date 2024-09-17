#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <memory>
#include <unordered_map>

class Trie
{
private:
    struct TrieNode
    {
        bool isEndOfWord;
        std::unordered_map<char, std::shared_ptr<TrieNode>> children;

        TrieNode() : isEndOfWord(false) {}
    };

    std::shared_ptr<TrieNode> root;

public:
    Trie();
    void insert(const std::string &word);
    bool search(const std::string &word) const;
    bool startsWith(const std::string &prefix) const;
};

#endif /* TRIE_H */