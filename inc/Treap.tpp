#include "Treap.h"

template <typename T>
Treap<T>::Treap() : root(nullptr) {}

template <typename T>
std::shared_ptr<typename Treap<T>::Node> Treap<T>::rotateRight(std::shared_ptr<Node> node)
{
    std::shared_ptr<Node> leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;
    return leftChild;
}

template <typename T>
std::shared_ptr<typename Treap<T>::Node> Treap<T>::rotateLeft(std::shared_ptr<Node> node)
{
    std::shared_ptr<Node> rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;
    return rightChild;
}

template <typename T>
std::shared_ptr<typename Treap<T>::Node> Treap<T>::insert(std::shared_ptr<Node> node, T key, int priority)
{
    if (!node)
        return std::make_shared<Node>(key, priority);
    if (key < node->key)
    {
        node->left = insert(node->left, key, priority);
        if (node->left->priority > node->priority)
        {
            node = rotateRight(node);
        }
    }
    else
    {
        node->right = insert(node->right, key, priority);
        if (node->right->priority > node->priority)
        {
            node = rotateLeft(node);
        }
    }
    return node;
}

template <typename T>
void Treap<T>::insert(T key, int priority)
{
    root = insert(root, key, priority);
}

template <typename T>
std::shared_ptr<typename Treap<T>::Node> Treap<T>::remove(std::shared_ptr<Node> node, T key)
{
    if (!node)
        return nullptr;
    if (key < node->key)
    {
        node->left = remove(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = remove(node->right, key);
    }
    else
    {
        if (!node->left)
            return node->right;
        if (!node->right)
            return node->left;
        if (node->left->priority > node->right->priority)
        {
            node = rotateRight(node);
            node->right = remove(node->right, key);
        }
        else
        {
            node = rotateLeft(node);
            node->left = remove(node->left, key);
        }
    }
    return node;
}

template <typename T>
void Treap<T>::remove(T key)
{
    root = remove(root, key);
}

template <typename T>
void Treap<T>::inorderTraversal(std::shared_ptr<Node> node)
{
    if (node)
    {
        inorderTraversal(node->left);
        std::cout << node->key << " ";
        inorderTraversal(node->right);
    }
}

template <typename T>
void Treap<T>::inorder()
{
    inorderTraversal(root);
    std::cout << std::endl;
}
