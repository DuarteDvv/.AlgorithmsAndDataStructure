
🎯 Objective:

A stack is a Last-In-First-Out (LIFO) data structure that follows the principle of "growing and shrinking from one end only." It has a top pointer that points to the last element added to the stack, and its primary operations are push (adding an element to the top), pop (removing the top element), and peek (viewing the top element without removing it).

🚀 How it Works:

- A stack can be implemented using a dynamic array or a linked list. When a stack is created using a dynamic array, it is allocated with an initial capacity. When an element is added to a stack and the capacity is reached, the stack automatically increases its capacity, usually by doubling the current capacity. When elements are removed from a stack implemented with a dynamic array, the capacity remains the same, and the top pointer is adjusted accordingly.

- Stack operations, such as push, pop, and peek, are typically O(1) operations, regardless of the underlying implementation. However, if a stack is implemented using a linked list, the time complexity for these operations may vary.

🎓 Advantages:

Stacks offer the advantage of being simple to implement and use, and they provide efficient insertion and removal of elements from one end only. They are useful in various applications, such as function calls, expression evaluation, and backtracking algorithms.

🔥 Disadvantages:

Stacks can only be accessed from one end, which can limit their usefulness in certain scenarios. Additionally, if a stack is implemented using a dynamic array, it can suffer from fragmentation when elements are removed, leading to wasted memory. However, this can be mitigated by reducing the size of the array when the number of elements is much smaller than the capacity.


![image](https://github.com/DuarteDvv/.AlgorithmsAndDataStructure/assets/136333571/6ada0492-7ebf-4d60-9533-d59417ddd31b)
