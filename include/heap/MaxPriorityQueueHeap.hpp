#ifndef MAX_HEAP_
#define MAX_HEAP_

#include <stdexcept> //std::runtime_error
#include "tools.hpp"

template<typename T>
class MaxPriorityQueueHeap {  
private:
    T*  heap;  //Why i use array ? bc the acess to the elements is O(1) and complete trees can be perfecly represented by a array
    int capacity;
    int size;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    MaxPriorityQueueHeap(int capacity);
    ~MaxPriorityQueueHeap();

    T     getMax_wihout_remove();
    int   getSize() const { return size; };
    bool  isEmpty() const { return size == 0; };
    void  enqueue(const T& obj);
    T     dequeue();
    void  clear();
};

template<typename T>
MaxPriorityQueueHeap<T>::MaxPriorityQueueHeap(int capacity) : capacity(capacity), size(0) {
    heap = new T[capacity];
}

template<typename T>
MaxPriorityQueueHeap<T>::~MaxPriorityQueueHeap() {
    delete[] heap;
}

template<typename T>
void MaxPriorityQueueHeap<T>::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;  //by the property of complete tree in array representation
        if (heap[index] > heap[parent]) {
            swapp(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

template<typename T>
void MaxPriorityQueueHeap<T>::heapifyDown(int index) {
    while (true) {
        int leftChild = 2 * index + 1; //property
        int rightChild = 2 * index + 2; //property
        int largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swapp(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

template<typename T>
void MaxPriorityQueueHeap<T>::enqueue(const T& obj) {
    if (size >= capacity) {
        throw std::runtime_error("Error: Heap is full.");
    }

    heap[size++] = obj;
    heapifyUp(size - 1);
}

template<typename T>
T MaxPriorityQueueHeap<T>::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Error: Heap is empty.");
    }

    T max = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);

    return max;
}

template<typename T>
void MaxPriorityQueueHeap<T>::clear() {
    size = 0;
}

template<typename T>
T MaxPriorityQueueHeap<T>::getMax_wihout_remove(){
    return heap[0];
}

#endif // MAX_HEAP_
