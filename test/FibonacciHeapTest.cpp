#include <gtest/gtest.h>
#include "FibonacciHeap.h"

TEST(FibonacciHeapTest, BasicOperations)
{
    FibonacciHeap<int> heap;
    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    EXPECT_EQ(heap.findMin(), 5);

    int minValue = heap.extractMin();
    EXPECT_EQ(minValue, 5);
    EXPECT_EQ(heap.findMin(), 10);
}

TEST(FibonacciHeapTest, DecreaseKey)
{
    FibonacciHeap<int> heap;
    heap.insert(20);
    heap.insert(30);
    auto minNode = heap.getMinNode();
    heap.decreaseKey(minNode, 5);
    EXPECT_EQ(heap.findMin(), 5);
}

TEST(FibonacciHeapTest, DeleteNode)
{
    FibonacciHeap<int> heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    auto minNode = heap.getMinNode();
    heap.deleteNode(minNode);
    EXPECT_EQ(heap.findMin(), 10);
}
