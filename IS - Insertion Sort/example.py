def insertion_sort(arr):

    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1

        # Move elements greater than key ahead
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        # Insert key at the correct position
        arr[j + 1] = key

# Example usage
arr = [12, 11, 13, 5, 6]

print("List before sorting:", arr)
insertion_sort(arr)
print("List after sorting:", arr)
