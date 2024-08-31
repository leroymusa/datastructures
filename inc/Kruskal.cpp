#include "Kruskal.h"

Kruskal::Kruskal(int vertices) : vertices(vertices)
{
    parent.resize(vertices);
    rank.resize(vertices, 0);
    for (int i = 0; i < vertices; ++i)
    {
        parent[i] = i;
    }
}

void Kruskal::addEdge(int u, int v, int weight)
{
    edges.push_back({weight, {u, v}});
}

int Kruskal::find(int u)
{
    if (u != parent[u])
    {
        parent[u] = find(parent[u]); // Path compression
    }
    return parent[u];
}

void Kruskal::unionSets(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV)
    {
        if (rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

std::vector<Kruskal::WeightedEdge> Kruskal::findMST()
{
    std::sort(edges.begin(), edges.end());
    std::vector<WeightedEdge> mst;
    for (auto &edge : edges)
    {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (find(u) != find(v))
        {
            mst.push_back(edge);
            unionSets(u, v);
        }
    }
    return mst;
}