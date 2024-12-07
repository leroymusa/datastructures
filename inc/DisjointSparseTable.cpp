#include "DisjointSparseTable.h"
#include <cmath>

DisjointSparseTable::DisjointSparseTable(const std::vector<int> &data, const std::function<int(int, int)> &op)
    : operation(op), n(data.size())
{
    int log = std::log2(n) + 1;
    table.assign(log, std::vector<int>(n));

    table[0] = data;
    for (int i = 1; i < log; ++i)
    {
        int step = 1 << i;
        for (int j = 0; j + step <= n; ++j)
        {
            table[i][j] = operation(table[i - 1][j], table[i - 1][j + (step / 2)]);
        }
    }
}

int DisjointSparseTable::query(int left, int right) const
{
    if (left == right)
    {
        return table[0][left];
    }
    int log = std::log2(right - left + 1);
    return operation(table[log][left], table[log][right - (1 << log) + 1]);
}
