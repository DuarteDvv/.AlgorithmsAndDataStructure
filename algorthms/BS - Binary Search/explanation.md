🎯 Objective:<br>

Binary Search is a highly efficient searching algorithm that works on a sorted array. It utilizes the divide-and-conquer strategy to quickly locate a target element within the array.

🚀 How it Works:<br>

- Determine the middle element of the array.
- Compare the middle element with the target element.
- If they match, the search is successful, and the index is returned.
- If the target element is less than the middle element, repeat the search on the left half of the array.
- If the target element is greater than the middle element, repeat the search on the right half of the array.
- Continue dividing the array and repeating the process until the target element is found or the search range becomes empty.<br>

Lets see together:
```cpp
Suppose we have an array {6, 9, 34, 75, 94, 100} (sorted) and a target value of 6. Here are the steps to find the target value in the array using binary search:

1. Initialize the left index to the minimum value of the range where the target can be (in this case, 0), and initialize the right index to the maximum value of the range where the target can be (in this case, the last index, size - 1);

2. Calculate the mid index by taking the average of the left and right indices. In this case, the starter left is index 0 and starter right is index 5, so the mid index is 0 + (5-0)/2 = 2. Note that the result is 2.5, but we use integers, so we narrow to get 2;

3. Check if the element on the mid index is the target. In this case, the element in index 2 is 34, which is not the target (6). Compare the mid element with the target, and if the target is bigger than mid, we know that the minimum element is mid+1. In this case, the target (6) is less than the mid element (34), so we set right to mid - 1 (which is 1).
We repeat steps 2 and 3 with the new range. The new mid index is 0 + (1-0)/2 = 0. The element in index 0 is the target, so we found the target!
```

🎓 Advantages:

Highly efficient on sorted arrays.<br>
Reduces the search range by half in each iteration.<br>

🔥 Disadvantages:

Requires a sorted array as input.<br>
Inefficient for unsorted arrays.<br>
May not find all occurrences of the target element in duplicate scenarios.


![image](https://github.com/DuarteDvv/Algorithms/assets/136333571/7ccf6f29-09ad-4329-958c-d4dd13df7c89)
