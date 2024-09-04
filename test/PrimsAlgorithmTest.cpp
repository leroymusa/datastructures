#include "PrimsAlgorithm.h"
#include <gtest/gtest.h>

TEST(PrimsAlgorithmTest, BasicMST)
{
    PrimsAlgorithm graph(5);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    auto mst = graph.findMST();
    EXPECT_EQ(mst.size(), 4);
}

TEST(PrimsAlgorithmTest, SingleNodeGraph)
{
    PrimsAlgorithm graph(1);
    auto mst = graph.findMST();
    EXPECT_EQ(mst.size(), 0);
}

TEST(PrimsAlgorithmTest, TwoNodeGraph)
{
    PrimsAlgorithm graph(2);
    graph.addEdge(0, 1, 10);
    auto mst = graph.findMST();
    EXPECT_EQ(mst.size(), 1);
    EXPECT_EQ(mst[0], std::make_pair(0, 1));
}
