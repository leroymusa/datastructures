#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include <vector>

class FenwickTree
{
public:
    FenwickTree(int size);
    void update(int index, int delta);
    int query(int index) const;
    int rangeQuery(int left, int right) const;

private:
    std::vector<int> tree;
    int getParent(int index) const;
    int getNext(int index) const;
};

#endif /* FENWICK_TREE_H */
