🎯 Objective: 

A hash table is a data structure that stores key-value pairs in an array using a hash function to compute the index of each element.

🚀 How it Works:

- hash function takes a key as input and generates an index that can be used as the position of the key-value pair in the array.
- If a collision occurs, a method like chaining or open addressing is used to store multiple key-value pairs at the same index.
- To retrieve a value, the hash function is applied to the key again to find the corresponding index in the array.
  
Let's see together:
```cpp
Suppose we have a hash table with the following key-value pairs: {"apple": 1, "banana": 2, "orange": 3, "grape": 4} and a key "banana". Here is an example of how a hash table works:

1. Compute the index of the key "banana" by applying the hash function.
2. Retrieve the key-value pair at the computed index. In this case, the key-value pair at index 2 is ("banana", 2).
3. Return the value 2

```
🎓 Advantages

Faster lookups compared to linear and binary search, with an average time complexity of O(1).
Can be used to implement other data structures like sets and maps.


🔥 Disadvantages

Collisions can occur, leading to slower lookups and increased memory usage.
The hash function must be carefully chosen to distribute keys uniformly and avoid biased collisions.

![image](https://github.com/DuarteDvv/.AlgorithmsAndDataStructure/assets/136333571/3a64d059-3cb8-4046-bbd2-1cb6a1dbf24f)
