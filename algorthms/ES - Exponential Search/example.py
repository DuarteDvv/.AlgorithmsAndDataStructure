def binary_search(arr, low, high, x):
    if high >= low:
        mid = (high + low) // 2

        if arr[mid] == x:
            return mid

        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)

        else:
            return binary_search(arr, mid + 1, high, x)

    else:
        return -1

def exponential_search(arr, n, x):
    if arr[0] == x:
        return 0

    i = 1
    while i < n and arr[i] <= x:
        i = i * 2

    return binary_search(arr, i // 2, min(i, n - 1), x)

arr = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
n = len(arr)
x = 11
result = exponential_search(arr, n, x)

if result != -1:
    print("Element found at index:", result)
else:
    print("Element not found in the array")
