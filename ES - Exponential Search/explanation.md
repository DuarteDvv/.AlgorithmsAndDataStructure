🎯 Objective:<br>

The Exponential Search algorithm is a searching technique that combines elements of binary search and sequential search. It is particularly useful for unbounded arrays or when the size of the array is unknown. Exponential Search works by narrowing down the search range exponentially until the desired element is found or the end of the array is reached.

🚀 How it Works:<br>

Determine a range where the desired element might exist. Initially, set the range as [1, min(2^k, n)], where n is the size of the array.
Perform a binary search within this range.
If the desired element is found, return its index.
If the element is not found, double the range and repeat steps 2-3 until the range exceeds the array size.
Once the range exceeds the array size, switch to a sequential search within the last valid range.<br>

🎓 Advantages:

Efficient for unbounded arrays or situations where the array size is unknown.<br>
Combines the efficiency of binary search and the simplicity of sequential search.<br>

🔥 Disadvantages:

Inefficient for small arrays.<br>
Requires extra space for control variables.<br>
Worst-case time complexity is O(log n), where n is the number of elements, but may involve multiple passes.

Remember, the effectiveness of Exponential Search lies in its ability to quickly narrow down the search space, making it particularly useful for large sorted datasets.


![](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSCIyXSbFwvjXFaEnooPhp8q5YG1oWTnojmRg&usqp=CAU)
