#ifndef FIBONACCIHEAP_H
#define FIBONACCIHEAP_H

#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>
#include <limits>
#include <cmath>

template <typename T>
class FibonacciHeap
{
private:
    struct Node
    {
        T value;
        int degree;
        bool mark;
        std::shared_ptr<Node> parent;
        std::shared_ptr<Node> child;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        Node(T val) : value(val), degree(0), mark(false), parent(nullptr), child(nullptr)
        {
            left = right = std::make_shared<Node>(*this);
        }
    };

    std::shared_ptr<Node> minNode;
    int numNodes;

    void consolidate();
    void cut(std::shared_ptr<Node> x, std::shared_ptr<Node> y);
    void cascadingCut(std::shared_ptr<Node> y);
    void link(std::shared_ptr<Node> y, std::shared_ptr<Node> x);

public:
    FibonacciHeap() : minNode(nullptr), numNodes(0) {}
    void insert(T value);
    T findMin();
    T extractMin();
    void decreaseKey(std::shared_ptr<Node> x, T newVal);
    void deleteNode(std::shared_ptr<Node> x);

    std::shared_ptr<Node> getMinNode() const { return minNode; }
    int size() const { return numNodes; }
};

#include "FibonacciHeap.tpp"

#endif /* FIBONACCIHEAP_H */
