#include "SplayTree.h"

template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::rotateRight(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

template <typename T>
void SplayTree<T>::splay(Node*& root, const T& key) {
    if (!root) return;

    if (key < root->data) {
        if (!root->left) return;
        if (key < root->left->data) {
            splay(root->left->left, key);
            root = rotateRight(root);
        } else if (key > root->left->data) {
            splay(root->left->right, key);
            if (root->left->right)
                root->left = rotateLeft(root->left);
        }
        root = (root->left) ? rotateRight(root) : root;
    } else if (key > root->data) {
        if (!root->right) return;
        if (key > root->right->data) {
            splay(root->right->right, key);
            root = rotateLeft(root);
        } else if (key < root->right->data) {
            splay(root->right->left, key);
            if (root->right->left)
                root->right = rotateRight(root->right);
        }
        root = (root->right) ? rotateLeft(root) : root;
    }
}

template <typename T>
void SplayTree<T>::insert(const T& key) {
    if (!root) {
        root = new Node(key);
        return;
    }
    splay(root, key);
    if (key < root->data) {
        Node* newNode = new Node(key);
        newNode->left = root->left;
        newNode->right = root;
        root->left = nullptr;
        root = newNode;
    } else if (key > root->data) {
        Node* newNode = new Node(key);
        newNode->right = root->right;
        newNode->left = root;
        root->right = nullptr;
        root = newNode;
    }
}

template <typename T>
bool SplayTree<T>::find(const T& key) {
    if (!root) return false;
    splay(root, key);
    return root->data == key;
}

template <typename T>
void SplayTree<T>::clear(Node* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

template <typename T>
void SplayTree<T>::inorder(Node* node) const {
    if (!node) return;
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}
