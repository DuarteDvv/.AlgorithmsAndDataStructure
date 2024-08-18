#ifndef BTREE_
#define BTREE_

#include <iostream>
#include "NodeBT.hpp"
#include "Queue.hpp"

template <typename T>
class SearchBinaryTree
{

private:
    NodeBT<T> *root;
    void insert(NodeBT<T> *&p, T obj);
    void deleteRecursive(NodeBT<T> *p);
    void byLevel();
    void preOrder(NodeBT<T> *p);
    void inOrder(NodeBT<T> *p);
    void posOrder(NodeBT<T> *p);
    int height(NodeBT<T> *p);
    NodeBT<T> *remove(NodeBT<T> *p, T obj);
    NodeBT<T> *max(NodeBT<T> *p);
    NodeBT<T> *min(NodeBT<T> *p);

public:
    ~SearchBinaryTree();
    SearchBinaryTree();
    void insert(T obj);
    NodeBT<T> *search(T obj);
    NodeBT<T> *max();
    NodeBT<T> *min();
    // 0:bylevel 1:preOrder 2:inOrder 3:posOrder
    void walk(int type);
    void clean();
    int height();
    void remove(T obj);
};

template <typename T>
SearchBinaryTree<T>::SearchBinaryTree()
{
    root = nullptr;
}

template <typename T>
SearchBinaryTree<T>::~SearchBinaryTree()
{
    clean();
}

template <typename T>
void SearchBinaryTree<T>::insert(T obj)
{
    insert(root, obj);
}

// O(n) worst caso degenerated tree (insertion crescent order) max height
// O(log(n)) best case balanced tree minimum height
template <typename T>
void SearchBinaryTree<T>::insert(NodeBT<T> *&p, T obj)
{ // bigger than root on the right, smaller on the left
    if (p == nullptr)
    {
        p = new NodeBT<T>();
        p->object = obj;
    }
    else
    {
        if (obj > p->object)
        {
            insert(p->right, obj);
        }
        else
        {
            insert(p->left, obj);
        }
    }
}

template <typename T>
void SearchBinaryTree<T>::preOrder(NodeBT<T> *p)
{
    if (p != nullptr)
    {
        std::cout << p->object << std::endl;
        preOrder(p->left);
        preOrder(p->right);
    }
}

template <typename T>
void SearchBinaryTree<T>::inOrder(NodeBT<T> *p)
{
    if (p != nullptr)
    {
        inOrder(p->left);
        std::cout << p->object << std::endl;
        inOrder(p->right);
    }
}

template <typename T>
void SearchBinaryTree<T>::posOrder(NodeBT<T> *p)
{
    if (p != nullptr)
    {
        posOrder(p->left);
        posOrder(p->right);
        std::cout << p->object << std::endl;
    }
}

template <typename T>
void SearchBinaryTree<T>::byLevel()
{
    ArrayQueue<NodeBT<T> *> queue_aux;
    NodeBT<T> *p;

    queue_aux.enqueue(root);

    while (!queue_aux.isEmpty())
    {
        p = queue_aux.unqueue();
        if (p != nullptr)
        {
            std::cout << p->object << std::endl;
            queue_aux.enqueue(p->left);
            queue_aux.enqueue(p->right);
        }
    }
}

template <typename T>
void SearchBinaryTree<T>::deleteRecursive(NodeBT<T> *p)
{
    if (p != nullptr)
    {
        deleteRecursive(p->left);
        deleteRecursive(p->right);
        delete p;
    }
}

template <typename T>
void SearchBinaryTree<T>::clean()
{
    deleteRecursive(root);
    root = nullptr;
}

template <typename T>
void SearchBinaryTree<T>::walk(int type)
{
    switch (type)
    {
    case 0:
        byLevel();
        break;
    case 1:
        preOrder(root);
        break;
    case 2:
        inOrder(root);
        break;
    case 3:
        posOrder(root);
        break;
    default:
        break;
    }
}

template <typename T>
NodeBT<T> *SearchBinaryTree<T>::search(T obj)
{

    NodeBT<T> *p = root;

    while (p != nullptr)
    {
        if (obj == p->object)
        {
            return p;
        }
        if (obj < p->object)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }

    return nullptr;
}

template <typename T>
NodeBT<T> *SearchBinaryTree<T>::max(NodeBT<T> *p)
{
    while (p->right != nullptr)
    {
        p = p->right;
    }
    return p;
}

template <typename T>
NodeBT<T> *SearchBinaryTree<T>::max()
{
    return max(root);
}

template <typename T>
NodeBT<T> *SearchBinaryTree<T>::min(NodeBT<T> *p)
{
    while (p->left != nullptr)
    {
        p = p->left;
    }
    return p;
}

template <typename T>
NodeBT<T> *SearchBinaryTree<T>::min()
{
    return min(root);
}

template <typename T>
int SearchBinaryTree<T>::height()
{
    return height(root);
}

template <typename T>
T max2(const T &a, const T &b)
{
    return (a > b) ? a : b;
}

template <typename T>
int SearchBinaryTree<T>::height(NodeBT<T> *p)
{
    if (p == nullptr)
        return -1;

    else
        return 1 + max2(height(p->left), height(p->right));
}

template <typename T>
void SearchBinaryTree<T>::remove(T obj)
{
    root = remove(root, obj);
}

template <typename T>
NodeBT<T> *SearchBinaryTree<T>::remove(NodeBT<T> *p, T obj)
{
    if (p == nullptr)
        return p;

    if (obj < p->object)
    {
        p->left = remove(p->left, obj);
    }
    else if (obj > p->object)
    {
        p->right = remove(p->right, obj);
    }
    else
    {
        // Case 1: Leaf
        if (p->left == nullptr && p->right == nullptr)
        {
            delete p;
            return nullptr;
        }
        // Case 2: One children
        else if (p->left == nullptr)
        {
            NodeBT<T> *temp = p->right;
            delete p;
            return temp;
        }
        else if (p->right == nullptr)
        {
            NodeBT<T> *temp = p->left;
            delete p;
            return temp;
        }
        // Case 3: two children
        else
        {
            NodeBT<T> *temp = min(p->right);
            p->object = temp->object;
            p->right = remove(p->right, temp->object);
        }
    }
    return p;
}

#endif
