#include <iostream>

template <typename T>
class Queue {
private:
    static const int CAPACITY = 10;
    int front, rear;
    T data[CAPACITY];

public:
    Queue() : front(0), rear(-1) {}

    void enqueue(T value) {
        if(rear == CAPACITY - 1)
            std::cout << "Queue is full!\n";
        else {
            data[++rear] = value;
        }
    }

    T dequeue() {
        if(front > rear) {
            std::cout << "Queue is empty!\n";
            return T();
        }
        return data[front++];
    }

    bool isEmpty() {
        return (front > rear);
    }
};

int main() {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << q.dequeue() << "\n";
    std::cout << q.dequeue() << "\n";
    std::cout << q.dequeue() << "\n";

    return 0;
}
