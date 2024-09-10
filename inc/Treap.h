#ifndef TREAP_H
#define TREAP_H

#include <iostream>
#include <memory>

template <typename T>
class Treap
{
private:
    struct Node
    {
        T key;
        int priority;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        Node(T k, int p) : key(k), priority(p), left(nullptr), right(nullptr) {}
    };

    std::shared_ptr<Node> root;

    std::shared_ptr<Node> rotateRight(std::shared_ptr<Node> node);
    std::shared_ptr<Node> rotateLeft(std::shared_ptr<Node> node);
    std::shared_ptr<Node> insert(std::shared_ptr<Node> node, T key, int priority);
    std::shared_ptr<Node> remove(std::shared_ptr<Node> node, T key);
    void inorderTraversal(std::shared_ptr<Node> node);

public:
    Treap();
    void insert(T key, int priority);
    void remove(T key);
    void inorder();
};

#include "Treap.tpp"

#endif // TREAP_H
