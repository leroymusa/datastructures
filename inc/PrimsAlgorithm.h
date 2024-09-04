#ifndef PRIMSALGORITHM_H
#define PRIMSALGORITHM_H

#include <vector>
#include <utility>

class PrimsAlgorithm
{
private:
    int V;
    std::vector<std::vector<std::pair<int, int>>> adj;

public:
    PrimsAlgorithm(int V);
    void addEdge(int u, int v, int weight);
    std::vector<std::pair<int, int>> findMST();
};

#endif
