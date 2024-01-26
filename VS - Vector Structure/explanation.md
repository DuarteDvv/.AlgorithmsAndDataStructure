🎯 Objective: 

A vector is a dynamic array data structure that can resize itself automatically as elements are added or removed. It follows the principle of dynamic arrays, where the underlying array can grow or shrink in size as needed.

🚀 How it Works: 

- A vector is typically implemented using a dynamic array, which is an array that can change its size during execution. When a vector is created, it is allocated with an initial capacity. When an element is added to a vector and the capacity is reached, the vector automatically increases its capacity, usually by doubling the current capacity. This process is called amortized expansion. Similarly, when elements are removed, and the vector's size is much smaller than its capacity, the vector can reduce its capacity through a process called shrinking, which helps minimize memory usage.

- Vector operations include insertion, deletion, and accessing elements. Insertion at the end of the vector is typically an O(1) operation, while insertion at the beginning or in the middle can be an O(n) operation, as all subsequent elements need to be shifted. Accessing an element by its index is an O(1) operation, as vectors follow the random-access property of arrays.

🎓 Advantages:

Vectors offer the advantage of being able to grow and shrink dynamically, making them more flexible than static arrays. They provide efficient insertion and deletion at the end of the vector and offer constant-time access to elements by their index.

🔥 Disadvantages:

Vectors can have slower insertion and deletion times for elements that are not at the end of the vector, as all subsequent elements need to be shifted. Additionally, vectors can suffer from fragmentation when elements are removed, leading to wasted memory.
