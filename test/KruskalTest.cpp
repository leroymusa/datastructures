#include <gtest/gtest.h>
#include "Kruskal.h"

TEST(KruskalTest, BasicMST) {
    Kruskal kruskal(4);
    kruskal.addEdge(0, 1, 10);
    kruskal.addEdge(0, 2, 6);
    kruskal.addEdge(0, 3, 5);
    kruskal.addEdge(1, 3, 15);
    kruskal.addEdge(2, 3, 4);

    std::vector<Kruskal::WeightedEdge> mst = kruskal.findMST();

    // Check that the MST contains the correct number of edges
    EXPECT_EQ(mst.size(), 3);

    // Check the total weight of the MST
    int totalWeight = 0;
    for (const auto& edge : mst) {
        totalWeight += edge.first;
    }
    EXPECT_EQ(totalWeight, 19); // Expected weight for this MST
}