#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

#include <vector>

class SegmentTree
{
private:
    std::vector<int> tree;
    int n;

    void buildTree(const std::vector<int> &data, int start, int end, int node);
    int queryTree(int start, int end, int l, int r, int node) const;
    void updateTree(int start, int end, int index, int value, int node);

public:
    SegmentTree(const std::vector<int> &data);
    int query(int left, int right) const;
    void update(int index, int value);
};

#endif /* SEGMENTTREE_H */
