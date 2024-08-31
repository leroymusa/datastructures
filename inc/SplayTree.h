#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <iostream>

template <typename T>
class SplayTree
{
private:
    struct Node
    {
        T data;
        Node *left;
        Node *right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node *root;

    void splay(Node *&root, const T &key);
    Node *rotateRight(Node *x);
    Node *rotateLeft(Node *x);

public:
    SplayTree() : root(nullptr) {}
    ~SplayTree() { clear(root); }

    void insert(const T &key);
    bool find(const T &key);
    void clear(Node *node);

    void inorder(Node *node) const;
    Node *getRoot() const { return root; }
};

#include "SplayTree.tpp"

#endif /* SPLAYTREE_H */
