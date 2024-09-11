#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <vector>

class DisjointSet
{
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    DisjointSet(int size);
    int find(int x);
    void unionSets(int x, int y);
    bool connected(int x, int y);
};

#endif /* DISJOINTSET_H */
