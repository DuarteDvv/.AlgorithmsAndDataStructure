#include <iostream>

// Function to build a heap from the given array
void buildHeap(int arr[], int n) {
    // Index of the last non-leaf node
    int start = n / 2 - 1;

    // Perform heapify on all non-leaf nodes
    for (int i = start; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to maintain the heap property
void heapify(int arr[], int n, int i) {
    // Find the largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        // Swap the root with the largest element
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to sort the array using Heap Sort
void heapSort(int arr[], int n) {
    // Build a heap from the given array
    buildHeap(arr, n);

    // One by one extract the largest element from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    std::cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
