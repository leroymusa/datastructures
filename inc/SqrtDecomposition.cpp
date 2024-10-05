#include "SqrtDecomposition.h"
#include <cmath>

SqrtDecomposition::SqrtDecomposition(const std::vector<int> &data)
    : data(data), blockSize(std::sqrt(data.size()))
{
    int numBlocks = (data.size() + blockSize - 1) / blockSize;
    blockSums.resize(numBlocks, 0);
    for (int i = 0; i < data.size(); ++i)
    {
        blockSums[i / blockSize] += data[i];
    }
}

void SqrtDecomposition::update(int index, int value)
{
    int blockIndex = index / blockSize;
    blockSums[blockIndex] -= data[index];
    data[index] = value;
    blockSums[blockIndex] += value;
}

int SqrtDecomposition::query(int left, int right) const
{
    int sum = 0;
    int leftBlock = left / blockSize;
    int rightBlock = right / blockSize;

    if (leftBlock == rightBlock)
    {
        for (int i = left; i <= right; ++i)
        {
            sum += data[i];
        }
    }
    else
    {
        for (int i = left; i < (leftBlock + 1) * blockSize; ++i)
        {
            sum += data[i];
        }
        for (int i = leftBlock + 1; i < rightBlock; ++i)
        {
            sum += blockSums[i];
        }
        for (int i = rightBlock * blockSize; i <= right; ++i)
        {
            sum += data[i];
        }
    }

    return sum;
}
