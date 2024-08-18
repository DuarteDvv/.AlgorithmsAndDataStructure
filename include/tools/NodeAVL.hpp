#ifndef _NODE_AVL
#define _NODE_AVL

template <typename T>
class NodeAVL
{
private:
   T object;
   int height;
   NodeAVL *left;
   NodeAVL *right;
   NodeAVL *parent;

public:
   Node()
   {
      object = T();
      left = nullptr;
      right = nullptr;
      parent = nullptr;
      height = 1;
   }

   NodeAVL(T obj)
   {
      object = obj;
      height = 1;
      left = nullptr;
      right = nullptr;
      parent = nullptr;
   }

   T getObj()
   {
      return object;
   }

   template <typename U>
   friend class AVL_Tree;
};

#endif