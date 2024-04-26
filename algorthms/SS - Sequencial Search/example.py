def sequential_search(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1

arr = [1, 4, 6, 8, 10]
x = 6
result = sequential_search(arr, x)

if result == -1:
    print("Element is not present in array")
else:
    print("Element is present at index", result)
