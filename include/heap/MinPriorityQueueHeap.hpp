#ifndef MIN_HEAP_
#define MIN_HEAP_

#include <stdexcept> // std::runtime_error
#include "tools.hpp"

template <typename T>
class MinPriorityQueueHeap
{
private:
    T *heap;
    int capacity;
    int size;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    MinPriorityQueueHeap(int capacity);
    ~MinPriorityQueueHeap();

    T getMin_without_remove();
    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
    void enqueue(const T &obj);
    T dequeue();
    void clear();
};

template <typename T>
MinPriorityQueueHeap<T>::MinPriorityQueueHeap(int capacity) : capacity(capacity), size(0)
{
    heap = new T[capacity];
}

template <typename T>
MinPriorityQueueHeap<T>::~MinPriorityQueueHeap()
{
    delete[] heap;
}

template <typename T>
void MinPriorityQueueHeap<T>::heapifyUp(int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2; // pela propriedade de árvore completa na representação por array
        if (heap[index] < heap[parent])
        {
            std::swap(heap[index], heap[parent]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

template <typename T>
void MinPriorityQueueHeap<T>::heapifyDown(int index)
{
    while (true)
    {
        int leftChild = 2 * index + 1;  // propriedade
        int rightChild = 2 * index + 2; // propriedade
        int smallest = index;

        if (leftChild < size && heap[leftChild] < heap[smallest])
        {
            smallest = leftChild;
        }
        if (rightChild < size && heap[rightChild] < heap[smallest])
        {
            smallest = rightChild;
        }

        if (smallest != index)
        {
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        }
        else
        {
            break;
        }
    }
}

template <typename T>
void MinPriorityQueueHeap<T>::enqueue(const T &obj)
{
    if (size >= capacity)
    {
        throw std::runtime_error("Error: Heap is full.");
    }

    heap[size++] = obj;
    heapifyUp(size - 1);
}

template <typename T>
T MinPriorityQueueHeap<T>::dequeue()
{
    if (isEmpty())
    {
        throw std::runtime_error("Error: Heap is empty.");
    }

    T min = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);

    return min;
}

template <typename T>
void MinPriorityQueueHeap<T>::clear()
{
    size = 0;
}

template <typename T>
T MinPriorityQueueHeap<T>::getMin_without_remove()
{
    if (isEmpty())
    {
        throw std::runtime_error("Error: Heap is empty.");
    }
    return heap[0];
}

#endif // MIN_HEAP_
