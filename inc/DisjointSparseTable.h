#ifndef DISJOINT_SPARSE_TABLE_H
#define DISJOINT_SPARSE_TABLE_H

#include <vector>
#include <functional>

class DisjointSparseTable
{
public:
    DisjointSparseTable(const std::vector<int> &data, const std::function<int(int, int)> &op);
    int query(int left, int right) const;

private:
    std::vector<std::vector<int>> table;
    std::function<int(int, int)> operation;
    int n;
};

#endif /* DISJOINT_SPARSE_TABLE_H */
