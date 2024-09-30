#include "AhoCorasick.h"
#include <queue>
#include <iostream>

AhoCorasick::AhoCorasick()
{
    root = new TrieNode();
}

void AhoCorasick::insert(const std::string &pattern)
{
    TrieNode *currentNode = root;
    for (char c : pattern)
    {
        if (currentNode->children.find(c) == currentNode->children.end())
        {
            currentNode->children[c] = new TrieNode();
        }
        currentNode = currentNode->children[c];
    }
    currentNode->output.push_back(pattern);
}

void AhoCorasick::buildFailureLinks()
{
    std::queue<TrieNode *> q;

    for (auto &pair : root->children)
    {
        pair.second->failureLink = root;
        q.push(pair.second);
    }

    while (!q.empty())
    {
        TrieNode *currentNode = q.front();
        q.pop();

        for (auto &pair : currentNode->children)
        {
            char c = pair.first;
            TrieNode *child = pair.second;
            TrieNode *fallback = currentNode->failureLink;

            while (fallback && fallback->children.find(c) == fallback->children.end())
            {
                fallback = fallback->failureLink;
            }

            if (fallback)
            {
                child->failureLink = fallback->children[c];
            }
            else
            {
                child->failureLink = root;
            }

            if (child->failureLink)
            {
                child->output.insert(child->output.end(), child->failureLink->output.begin(), child->failureLink->output.end());
            }

            q.push(child);
        }
    }
}

std::vector<std::pair<int, std::string>> AhoCorasick::search(const std::string &text)
{
    TrieNode *currentNode = root;
    std::vector<std::pair<int, std::string>> results;

    for (int i = 0; i < text.length(); ++i)
    {
        char c = text[i];

        while (currentNode && currentNode->children.find(c) == currentNode->children.end())
        {
            currentNode = currentNode->failureLink;
        }

        if (!currentNode)
        {
            currentNode = root;
            continue;
        }

        currentNode = currentNode->children[c];

        for (const std::string &pattern : currentNode->output)
        {
            results.push_back({i - pattern.length() + 1, pattern});
        }
    }

    return results;
}
