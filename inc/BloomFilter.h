#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <vector>
#include <string>
#include <functional>

class BloomFilter
{
private:
    std::vector<bool> bitArray;
    int size;
    int hashCount;

    int hash(const std::string &data, int seed) const;

public:
    BloomFilter(int size, int hashCount);
    void insert(const std::string &data);
    bool contains(const std::string &data) const;
};

#endif /* BLOOMFILTER_H */
