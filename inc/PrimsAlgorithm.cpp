#include "PrimsAlgorithm.h"
#include <queue>
#include <limits>

PrimsAlgorithm::PrimsAlgorithm(int V) : V(V), adj(V) {}

void PrimsAlgorithm::addEdge(int u, int v, int weight)
{
    adj[u].emplace_back(v, weight);
    adj[v].emplace_back(u, weight);
}

std::vector<std::pair<int, int>> PrimsAlgorithm::findMST()
{
    std::vector<int> key(V, std::numeric_limits<int>::max());
    std::vector<bool> inMST(V, false);
    std::vector<int> parent(V, -1);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (const auto &[v, weight] : adj[u])
        {
            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    std::vector<std::pair<int, int>> mst;
    for (int i = 1; i < V; ++i)
    {
        mst.emplace_back(parent[i], i);
    }

    return mst;
}
