#include "BloomFilter.h"

BloomFilter::BloomFilter(int size, int hashCount)
    : bitArray(size, false), size(size), hashCount(hashCount) {}

int BloomFilter::hash(const std::string &data, int seed) const
{
    std::hash<std::string> hashFunc;
    return (hashFunc(data) + seed) % size;
}

void BloomFilter::insert(const std::string &data)
{
    for (int ii = 0; ii < hashCount; ++ii)
    {
        int hashValue = hash(data, ii);
        bitArray[hashValue] = true;
    }
}

bool BloomFilter::contains(const std::string &data) const
{
    for (int ii = 0; ii < hashCount; ++ii)
    {
        int hashValue = hash(data, ii);
        if (!bitArray[hashValue])
        {
            return false;
        }
    }
    return true;
}
