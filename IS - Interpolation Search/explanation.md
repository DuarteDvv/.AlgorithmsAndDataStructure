🎯 Objective: 

The Interpolation Search algorithm is a searching algorithm that uses an estimation of the position of the desired element in the array to reduce the number of comparisons needed to find the element. It is a variation of the binary search algorithm, but instead of dividing the search interval in half, it uses the estimation to determine the new search interval.

🚀 How it Works:

The algorithm starts by calculating an estimation of the position of the desired element in the array using the formula:<br>
- pos = low + (((high - low) / (arr[high] - arr[low])) * (x - arr[low]))

where:<br>
- low is the initial position of the search interval;
- high is the final position of the search interval;
- arr[low] is the value of the element at the initial position of the search interval;
- arr[high] is the value of the element at the final position of the search interval;
- x is the value of the desired element.<br>


The algorithm then compares the estimated position with the actual position of the element in the array. If the estimated position matches the actual position, the position of the element is returned. Otherwise, the algorithm adjusts the search interval based on the comparison and repeats the process.

🎓 Advantages

Efficient runtime in the average case. The average-case scenario has a time complexity of O(log(log n)), where n is the number of elements in the array.

🔥 Disadvantages

Requires the array to be sorted. Less efficient than binary search in the worst-case scenario, which has a time complexity of O(n). The estimation of the position of the desired element may not be accurate if the values in the array are not uniformly distributed, leading to a less efficient runtime.
