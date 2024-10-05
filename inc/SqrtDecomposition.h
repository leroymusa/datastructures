#ifndef SQRT_DECOMPOSITION_H
#define SQRT_DECOMPOSITION_H

#include <vector>

class SqrtDecomposition
{
public:
    SqrtDecomposition(const std::vector<int> &data);
    void update(int index, int value);
    int query(int left, int right) const;

private:
    std::vector<int> data;
    std::vector<int> blockSums;
    int blockSize;
};

#endif /* SQRT_DECOMPOSITION_H */
