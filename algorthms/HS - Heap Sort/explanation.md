🎯 Objective:<br>

Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure. It works by repeatedly removing the maximum element from the heap and inserting it at the end of the sorted list. The algorithm repeats this process until the heap is empty and the sorted list is complete.

🚀 How it Works:<br>

- Build a max heap from the input data.
- Replace the root of the max heap with the last element of the heap and reduce the size of the heap by 1.
- Heapify the root of the max heap. Repeat steps 2-3 until the heap is empty. <br>

🎓 Advantages:<br>

Has a time complexity of O(n log n) for all cases (best, average, and worst). <br>Uses a small amount of additional memory for the heap.

🔥 Disadvantages:<br>

Not suitable for small or mostly sorted data, as the overhead of maintaining the heap may be higher than the benefits of using heap sort.


![image](https://github.com/DuarteDvv/.AlgorithmsAndDataStructure/assets/136333571/bfbef919-b41d-4464-8047-a93b7b5d32ea)

