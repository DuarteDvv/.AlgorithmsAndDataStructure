#include <iostream>
#include <algorithm>

class Vector {
private:
    int* arr;
    int capacity;
    int size;

public:
    // Constructor
    Vector() : capacity(1), size(0), arr(new int[capacity]) {}

    // Destructor
    ~Vector() {
        delete[] arr;
    }

    // Copy constructor
    Vector(const Vector& other) : capacity(other.capacity), size(other.size) {
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    // Copy assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            size = other.size;
            arr = new int[capacity];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    // Add an element to the end of the vector
    void push_back(int value) {
        if (size == capacity) {
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[size] = value;
        size++;
    }

    // Remove an element from the vector
    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // Get the element at the given index
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    // Get the size of the vector
    int getSize() const {
        return size;
    }
};

int main() {
    Vector v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (int i = 0; i < v.getSize(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    v.remove(1);

    for (int i = 0; i < v.getSize(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
