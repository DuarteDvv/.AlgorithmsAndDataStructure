#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        // Insert key at the correct position
        arr[j + 1] = key;
    }
}

int main() {
    // Example usage
    std::vector<int> arr = {12, 11, 13, 5, 6};

    std::cout << "Array before sorting: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    insertionSort(arr);

    std::cout << "\nArray after sorting: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
