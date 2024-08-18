#ifndef _NODE
#define _NODE

template <typename T>
class NodeBT
{
private:
    T object;
    NodeBT *left;
    NodeBT *right;

public:
    NodeBT()
    {
        object = T();
        left = nullptr;
        right = nullptr;
    }

    T getObj()
    {
        return object;
    }

    template <typename U>
    friend class SearchBinaryTree;
};

#endif