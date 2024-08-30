#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <algorithm>
#include <utility>

class Kruskal {
public:
    typedef std::pair<int, int> Edge; // An edge represented by two vertices
    typedef std::pair<int, Edge> WeightedEdge; // Weighted edge represented by weight and an edge

    Kruskal(int vertices);

    void addEdge(int u, int v, int weight);
    int find(int u);
    void unionSets(int u, int v);
    std::vector<WeightedEdge> findMST();

private:
    int vertices;
    std::vector<WeightedEdge> edges; // List of edges
    std::vector<int> parent, rank; // Disjoint set data structure
};

#endif // KRUSKAL_H