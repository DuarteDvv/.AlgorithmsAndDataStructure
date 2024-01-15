# Binary Search Algorithm

The binary search algorithm is an efficient and fast searching algorithm. It works by searching for a target value (t) in a sorted array (arr).

Here's how the BS algorithm works:

1. First, define two variables, "left" and "right", which represent the limits of the search in the array. Initially, "left" points to the first element of the array and "right" to the last.

2. While "left" <= "right", perform the following:

   a. Calculate the "middle" index as the average of "left" and "right".

   b. If the element at the "middle" index of the array is equal to the target value, the search ended successfully. Return the "middle" index.

   c. If the element at the "middle" index is less than the target value, update "left" to "middle" + 1. In this case, the search will continue in the subarray to the right of "middle".

   d. If the element at the "middle" index is greater than the target value, update "right" to "middle" - 1. In this case, the search will continue in the subarray to the left of "middle".

3. If the search ends without finding the target value, return -1. This indicates that the target value is not present in the array.

   
![image](https://github.com/DuarteDvv/Algorithms/assets/136333571/7ccf6f29-09ad-4329-958c-d4dd13df7c89)

Applications:

- Searching for Words in Dictionaries.
- Searching for Files in File Systems.
- Image Classification.
- Implementation of Maps, Sets, and Other Data Structure Elements in Python and Other Programming Languages.
