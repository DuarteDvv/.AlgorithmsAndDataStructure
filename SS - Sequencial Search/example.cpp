#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {1, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;
    int result = sequentialSearch(arr, n, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}
