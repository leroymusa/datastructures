#include "FenwickTree.h"

FenwickTree::FenwickTree(int size)
{
    tree.resize(size + 1, 0);
}

void FenwickTree::update(int index, int delta)
{
    index++;
    while (index < tree.size())
    {
        tree[index] += delta;
        index = getNext(index);
    }
}

int FenwickTree::query(int index) const
{
    index++;
    int sum = 0;
    while (index > 0)
    {
        sum += tree[index];
        index = getParent(index);
    }
    return sum;
}

int FenwickTree::rangeQuery(int left, int right) const
{
    return query(right) - query(left - 1);
}

int FenwickTree::getParent(int index) const
{
    return index - (index & -index);
}

int FenwickTree::getNext(int index) const
{
    return index + (index & -index);
}
