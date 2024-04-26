def interpolation_search(arr, n, x):
   low = 0
   high = n - 1

   while low <= high and x >= arr[low] and x <= arr[high]:
       if low == high:
           if arr[low] == x:
               return low
           return -1

       pos = low + (((high - low) / (arr[high] - arr[low])) * (x - arr[low]))
       pos = min(pos, high - 1)

       if arr[pos] == x:
           return pos
       if arr[pos] < x:
           low = pos + 1
       else:
           high = pos - 1

   return -1

arr = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21]
n = len(arr)
x = 15
index = interpolation_search(arr, n, x)
if index != -1:
   print("Element found at index", index)
else:
   print("Element not found in the array")
