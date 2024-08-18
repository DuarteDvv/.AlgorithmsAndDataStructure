#ifndef AVL_TREE
#define AVL_TREE

#include "NodeAVL.hpp"
#include "GeneralizedMax.hpp"

template <typename T>
class AVL_Tree
{
private:
   int height(NodeAVL<T> *p);
   int balanceFactor(NodeAVL<T> *node);
   void rightRotate(NodeAVL<T> *y);
   void leftRotate(NodeAVL<T> *x);

public:
   void insert(NodeAVL<T> *&p, T obj);
};

template <typename T>
int AVL_Tree<T>::height(NodeAVL<T> *p)
{
   if (p == nullptr)
      return 0;

   else
      return 1 + max(height(p->left), height(p->right));
}

template <typename T>
int AVL_Tree<T>::balanceFactor(NodeAVL<T> *node)
{
   if (node == NULL)
      return 0;

   int balance = (node->right->height) - (node->left->height);

   return balance;
}

template <typename T>
void AVL_Tree<T>::rightRotate(NodeAVL<T> *node)
{
   node->parent->left = node->right;
   node->right = node->parent;

   if (node->parent->parent->left == node->right)
   {
      node->parent->parent->left = node;
   }
   else
   {
      node->parent->parent->right = node;
   }

   NodeAVL<T> *aux = node->parent;

   node->parent = node->parent->parent;
   aux->parent = node;
}

template <typename T>
void AVL_Tree<T>::leftRotate(NodeAVL<T> *node)
{
   node->parent->right = node->right;
   node->left = node->parent;

   if (node->parent->parent->left == node->right)
   {
      node->parent->parent->left = node;
   }
   else
   {
      node->parent->parent->right = node;
   }

   NodeAVL<T> *aux = node->parent;

   node->parent = node->parent->parent;
   aux->parent = node;
}

template <typename T>
void Balance(NodeAVL<T> *&node)
{
   int balance = balanceFactor(node);

   if (balance > 1)
   {
      if (balanceFactor(node->right) < 0)
      {
         rightRotate(node->right);
      }
      leftRotate(node);
   }
   else if (balance < -1)
   {
      if (balanceFactor(node->left) > 0)
      {
         leftRotate(node->left);
      }
      rightRotate(node);
   }
}

template <typename T>
void AVL_Tree<T>::insert(NodeAVL<T> *&p, T obj)
{ // bigger than root on the right, smaller on the left
   if (p == nullptr)
   {
      p = new NodeAVL<T>();
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

   if (p->parent != nullptr)
   {
      if (p->parent->height == p->height)
         p->parent->height++;
   }

   Balance(p->parent);
}

#endif