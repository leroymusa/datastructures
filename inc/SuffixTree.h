#ifndef SUFFIXTREE_H
#define SUFFIXTREE_H

#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>
#include <string>

class SuffixTree
{
private:
    struct Node
    {
        std::unordered_map<char, std::shared_ptr<Node>> children;
        std::shared_ptr<Node> suffix_link;
        int start;
        std::shared_ptr<int> end;
        int suffix_index;

        Node(int start, std::shared_ptr<int> end) : start(start), end(end), suffix_index(-1), suffix_link(nullptr) {}
    };

    std::string text;
    std::shared_ptr<Node> root;
    std::shared_ptr<Node> active_node;
    int active_edge;
    int active_length;
    int remaining_suffix_count;
    std::shared_ptr<int> leaf_end;
    std::shared_ptr<Node> last_new_node;

    void extendSuffixTree(int pos);
    int edgeLength(std::shared_ptr<Node> node);
    void setSuffixIndexByDFS(std::shared_ptr<Node> node, int labelHeight);

    std::string longestRepeatedSubstring(std::shared_ptr<Node> node, int labelHeight);
    std::string longestCommonSubstring(std::shared_ptr<Node> node, const std::string &str1, const std::string &str2, int &maxLength);

public:
    SuffixTree(const std::string &text);
    void build();
    void print();

    std::string longestRepeatedSubstring();
    std::string longestCommonSubstring(const std::string &str2);
    bool contains(const std::string &substring);
};

#endif /* SUFFIXTREE_H */