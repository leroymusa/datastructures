#include "SuffixTree.h"

SuffixTree::SuffixTree(const std::string &text) : text(text), active_edge(-1), active_length(0), remaining_suffix_count(0)
{
    root = std::make_shared<Node>(-1, std::make_shared<int>(-1));
    active_node = root;
    leaf_end = std::make_shared<int>(-1);
}

void SuffixTree::extendSuffixTree(int pos)
{
    last_new_node = nullptr;
    (*leaf_end)++;
    remaining_suffix_count++;

    while (remaining_suffix_count > 0)
    {
        if (active_length == 0)
            active_edge = pos;

        char current_char = text[active_edge];
        if (active_node->children.find(current_char) == active_node->children.end())
        {
            active_node->children[current_char] = std::make_shared<Node>(pos, leaf_end);
            if (last_new_node)
            {
                last_new_node->suffix_link = active_node;
                last_new_node = nullptr;
            }
        }
        else
        {
            auto next_node = active_node->children[current_char];
            int edge_length = edgeLength(next_node);
            if (active_length >= edge_length)
            {
                active_edge += edge_length;
                active_length -= edge_length;
                active_node = next_node;
                continue;
            }

            if (text[next_node->start + active_length] == text[pos])
            {
                if (last_new_node)
                {
                    last_new_node->suffix_link = active_node;
                    last_new_node = nullptr;
                }
                active_length++;
                break;
            }

            int split_end = next_node->start + active_length - 1;
            auto split_node = std::make_shared<Node>(next_node->start, std::make_shared<int>(split_end));
            active_node->children[current_char] = split_node;

            split_node->children[text[pos]] = std::make_shared<Node>(pos, leaf_end);
            next_node->start += active_length;
            split_node->children[text[next_node->start]] = next_node;

            if (last_new_node)
            {
                last_new_node->suffix_link = split_node;
            }

            last_new_node = split_node;
        }

        remaining_suffix_count--;
        if (active_node == root && active_length > 0)
        {
            active_length--;
            active_edge = pos - remaining_suffix_count + 1;
        }
        else if (active_node != root)
        {
            active_node = active_node->suffix_link;
        }
    }
}

int SuffixTree::edgeLength(std::shared_ptr<Node> node)
{
    return *(node->end) - (node->start) + 1;
}

void SuffixTree::build()
{
    for (int i = 0; i < text.length(); i++)
    {
        extendSuffixTree(i);
    }
}

void SuffixTree::print()
{
    setSuffixIndexByDFS(root, 0);
}

void SuffixTree::setSuffixIndexByDFS(std::shared_ptr<Node> node, int labelHeight)
{
    if (node == nullptr)
        return;
    if (node->start != -1)
    {
        for (int i = node->start; i <= *(node->end); i++)
        {
            std::cout << text[i];
        }
        std::cout << " [" << node->suffix_index << "]" << std::endl;
    }
    for (auto &child : node->children)
    {
        setSuffixIndexByDFS(child.second, labelHeight + edgeLength(child.second));
    }
}

bool SuffixTree::contains(const std::string &substring)
{
    auto current_node = root;
    int substring_index = 0;

    while (substring_index < substring.length())
    {
        if (current_node->children.find(substring[substring_index]) == current_node->children.end())
        {
            return false;
        }
        current_node = current_node->children[substring[substring_index]];
        int edge_length = edgeLength(current_node);

        for (int i = 0; i < edge_length && substring_index < substring.length(); i++)
        {
            if (text[current_node->start + i] != substring[substring_index])
            {
                return false;
            }
            substring_index++;
        }
    }
    return true;
}

std::string SuffixTree::longestRepeatedSubstring()
{
    return longestRepeatedSubstring(root, 0);
}

std::string SuffixTree::longestRepeatedSubstring(std::shared_ptr<Node> node, int labelHeight)
{
    if (!node)
        return "";
    std::string result;
    if (node->suffix_index == -1)
    { // internal node
        for (auto &child : node->children)
        {
            std::string candidate = longestRepeatedSubstring(child.second, labelHeight + edgeLength(child.second));
            if (candidate.length() > result.length())
            {
                result = candidate;
            }
        }
        if (labelHeight > result.length())
        {
            result = text.substr(node->start - labelHeight, labelHeight);
        }
    }
    return result;
}

std::string SuffixTree::longestCommonSubstring(const std::string &str2)
{
    std::string combined = text + "#" + str2 + "$";
    SuffixTree combinedTree(combined);
    combinedTree.build();

    int maxLength = 0;
    std::string result = combinedTree.longestCommonSubstring(combinedTree.root, text, str2, maxLength);

    return result;
}

std::string SuffixTree::longestCommonSubstring(std::shared_ptr<Node> node, const std::string &str1, const std::string &str2, int &maxLength)
{
    if (!node)
        return "";
    std::string result;
    bool str1Found = false, str2Found = false;

    for (auto &child : node->children)
    {
        std::string candidate = longestCommonSubstring(child.second, str1, str2, maxLength);

        if (candidate.length() > result.length())
        {
            result = candidate;
        }

        if (child.second->suffix_index < str1.length())
        {
            str1Found = true;
        }
        else if (child.second->suffix_index > str1.length() + 1)
        {
            str2Found = true;
        }
    }

    if (str1Found && str2Found)
    {
        int nodeLength = edgeLength(node);
        if (nodeLength > maxLength)
        {
            maxLength = nodeLength;
            result = text.substr(node->start - maxLength, maxLength);
        }
    }

    return result;
}