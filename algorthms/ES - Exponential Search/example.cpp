#include <iostream>
#include <vector>

int exponentialSearch(std::vector<int>& arr, int target) {
    if (arr.empty() || arr[0] > target) {
        return -1;
    }

    int bound = 1;
    while (bound < arr.size() && arr[bound] <= target) {
        bound *= 2;
    }

    return binarySearch(arr, target, bound / 2, std::min(bound, (int)arr.size() - 1));
}

int binarySearch(std::vector<int>& arr, int target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 11;

    int result = exponentialSearch(arr, target);

    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found in the array" << std::endl;
    }

    return 0;
}
