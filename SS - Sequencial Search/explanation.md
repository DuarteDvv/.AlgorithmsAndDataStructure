🎯 Objective:<br>
The Sequential Search algorithm is a simple searching algorithm that scans through an array sequentially to find an element. It starts at the initial position of the array and moves through each element until the desired element is found or until the end of the array is reached.

🚀 How it Works:<br>
- The algorithm starts at the initial position of the array and compares the current element with the desired element.
- If the current element matches the desired element, its position in the array is returned.
- Otherwise, the position of the current element is maintained, and the process is repeated with the next element.
- This process continues until the entire array has been checked.

Lets see together:
```cpp
array { 6, 4, 10, 7, 15}

target = 7

1. Call the Sequencial search with the parameters ({ 6, 4, 10, 7, 15 }, 5, 7);
2. Verify the index 0 of array and compare the value with the target, butis different,then continue;
3. Verify the index 1 of array and compare the value with the target, but is different,then continue;
4. Verify the index 2 of array and compare the value with the target, but is different,then continue;
5. Verify the index 3 of array and compare the value with the target, gatcha!;
6. return the value or a boolean;

```
   
🎓 Advantages

Easy to understand and implement.<br>
Requires little memory, as the only extra memory needed for the algorithm is for the control variables.


🔥 Disadvantages

Inefficient runtime.<br>
The worst-case scenario has a time complexity of O(n), where n is the number of elements in the array.



![image](https://github.com/DuarteDvv/.AlgorithmsAndDataStructure/assets/136333571/322b35fb-6866-4760-9de5-86aea68ec492)
