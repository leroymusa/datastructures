#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <algorithm>
#include <utility>

class Kruskal
{
public:
    typedef std::pair<int, int> Edge;
    typedef std::pair<int, Edge> WeightedEdge;

    Kruskal(int vertices);

    void addEdge(int u, int v, int weight);
    int find(int u);
    void unionSets(int u, int v);
    std::vector<WeightedEdge> findMST();

private:
    int vertices;
    std::vector<WeightedEdge> edges;
    std::vector<int> parent, rank;
};

#endif /* KRUSKAL_H */