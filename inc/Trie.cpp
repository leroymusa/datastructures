#include "Trie.h"

Trie::Trie()
{
    root = std::make_shared<TrieNode>();
}

void Trie::insert(const std::string &word)
{
    std::shared_ptr<TrieNode> node = root;
    for (char c : word)
    {
        if (node->children.find(c) == node->children.end())
        {
            node->children[c] = std::make_shared<TrieNode>();
        }
        node = node->children[c];
    }
    node->isEndOfWord = true;
}

bool Trie::search(const std::string &word) const
{
    std::shared_ptr<TrieNode> node = root;
    for (char c : word)
    {
        if (node->children.find(c) == node->children.end())
        {
            return false;
        }
        node = node->children[c];
    }
    return node->isEndOfWord;
}

bool Trie::startsWith(const std::string &prefix) const
{
    std::shared_ptr<TrieNode> node = root;
    for (char c : prefix)
    {
        if (node->children.find(c) == node->children.end())
        {
            return false;
        }
        node = node->children[c];
    }
    return true;
}