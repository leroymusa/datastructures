#include "DisjointSet.h"

DisjointSet::DisjointSet(int size) : parent(size), rank(size, 0)
{
    for (int i = 0; i < size; i++)
        parent[i] = i;
}

int DisjointSet::find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void DisjointSet::unionSets(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY)
    {
        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

bool DisjointSet::connected(int x, int y)
{
    return find(x) == find(y);
}
