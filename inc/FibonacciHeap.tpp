#include "FibonacciHeap.h"

template <typename T>
void FibonacciHeap<T>::insert(T value)
{
    auto newNode = std::make_shared<Node>(value);
    if (!minNode)
    {
        minNode = newNode;
    }
    else
    {
        minNode->left->right = newNode;
        newNode->right = minNode;
        newNode->left = minNode->left;
        minNode->left = newNode;
        if (newNode->value < minNode->value)
        {
            minNode = newNode;
        }
    }
    numNodes++;
}

template <typename T>
T FibonacciHeap<T>::findMin()
{
    if (!minNode)
        throw std::runtime_error("Heap is empty");
    return minNode->value;
}

template <typename T>
T FibonacciHeap<T>::extractMin()
{
    if (!minNode)
        throw std::runtime_error("Heap is empty");

    auto oldMin = minNode;
    if (oldMin->child)
    {
        auto child = oldMin->child;
        do
        {
            child->parent = nullptr;
            child = child->right;
        } while (child != oldMin->child);

        auto minLeft = minNode->left;
        minLeft->right = oldMin->child;
        oldMin->child->left->right = minNode;
        minNode->left = oldMin->child->left;
        oldMin->child->left = minLeft;
    }

    minNode->left->right = minNode->right;
    minNode->right->left = minNode->left;

    if (minNode == minNode->right)
    {
        minNode = nullptr;
    }
    else
    {
        minNode = minNode->right;
        consolidate();
    }

    numNodes--;
    return oldMin->value;
}

template <typename T>
void FibonacciHeap<T>::decreaseKey(std::shared_ptr<Node> x, T newVal)
{
    if (newVal > x->value)
        throw std::invalid_argument("New key is greater than current key");
    x->value = newVal;
    auto y = x->parent;
    if (y && x->value < y->value)
    {
        cut(x, y);
        cascadingCut(y);
    }
    if (x->value < minNode->value)
    {
        minNode = x;
    }
}

template <typename T>
void FibonacciHeap<T>::deleteNode(std::shared_ptr<Node> x)
{
    decreaseKey(x, std::numeric_limits<T>::min());
    extractMin();
}

template <typename T>
void FibonacciHeap<T>::consolidate()
{
    int maxDegree = static_cast<int>(std::log2(numNodes)) + 1;
    std::vector<std::shared_ptr<Node>> A(maxDegree, nullptr);

    std::vector<std::shared_ptr<Node>> rootNodes;
    auto current = minNode;
    do
    {
        rootNodes.push_back(current);
        current = current->right;
    } while (current != minNode);

    for (auto w : rootNodes)
    {
        auto x = w;
        int d = x->degree;
        while (A[d] != nullptr)
        {
            auto y = A[d];
            if (x->value > y->value)
                std::swap(x, y);
            link(y, x);
            A[d] = nullptr;
            d++;
        }
        A[d] = x;
    }

    minNode = nullptr;
    for (auto node : A)
    {
        if (node)
        {
            if (!minNode || node->value < minNode->value)
            {
                minNode = node;
            }
        }
    }
}

template <typename T>
void FibonacciHeap<T>::cut(std::shared_ptr<Node> x, std::shared_ptr<Node> y)
{
    if (x->right == x)
    {
        y->child = nullptr;
    }
    else
    {
        x->right->left = x->left;
        x->left->right = x->right;
        if (y->child == x)
        {
            y->child = x->right;
        }
    }
    y->degree--;

    minNode->left->right = x;
    x->right = minNode;
    x->left = minNode->left;
    minNode->left = x;

    x->parent = nullptr;
    x->mark = false;
}

template <typename T>
void FibonacciHeap<T>::cascadingCut(std::shared_ptr<Node> y)
{
    auto z = y->parent;
    if (z)
    {
        if (!y->mark)
        {
            y->mark = true;
        }
        else
        {
            cut(y, z);
            cascadingCut(z);
        }
    }
}

template <typename T>
void FibonacciHeap<T>::link(std::shared_ptr<Node> y, std::shared_ptr<Node> x)
{
    y->left->right = y->right;
    y->right->left = y->left;

    y->parent = x;
    if (!x->child)
    {
        x->child = y;
        y->right = y->left = y;
    }
    else
    {
        y->left = x->child;
        y->right = x->child->right;
        x->child->right->left = y;
        x->child->right = y;
    }

    x->degree++;
    y->mark = false;
}
