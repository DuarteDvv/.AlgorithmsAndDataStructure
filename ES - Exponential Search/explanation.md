# Exponential Search Algorithm

Exponential Search, also known as Binary Exponential Search, is a searching algorithm designed for sorted arrays. It is an improvement over binary search and works by finding a range where the target element may exist and then performing a binary search within that range.

how work:

1. Determine an initial range, usually with a size of 1.
2. Double the size of the range iteratively until an element greater than the target is found or the end of the array is reached.
3. Perform a binary search within the identified range for the target element.

Applications:
Exponential Search is commonly used in scenarios where the data is sorted, and the size of the dataset is unknown. Here are three applications:

1. **Searching in Databases:**
   - Exponential Search is efficient when searching for a specific record in a large database, especially if the database is sorted.

2. **Finding an Element in a Sorted List:**
   - In scenarios where you have a large sorted list, such as an address book, Exponential Search can quickly locate a specific entry.

3. **Locating Elements in an Ordered Array:**
   - When dealing with ordered datasets, like phone numbers in ascending order, Exponential Search provides an efficient way to find a particular element.

Remember, the effectiveness of Exponential Search lies in its ability to quickly narrow down the search space, making it particularly useful for large sorted datasets.

