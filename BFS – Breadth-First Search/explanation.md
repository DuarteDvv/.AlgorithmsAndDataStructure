🎯 Objective:<br>

Breadth-First Search (BFS) is a graph traversal algorithm that explores all the vertices of a graph level by level. It starts from a given source vertex and visits all its neighbors before moving on to their neighbors. BFS is commonly used to find the shortest path in an unweighted graph.

🚀 How it Works:

- Start with a source vertex and enqueue it into a queue.
- While the queue is not empty:
- Dequeue a vertex from the queue and process it.
- Enqueue all unvisited neighbors of the processed vertex.
- Repeat until all vertices are visited or the desired condition is met.<br>

🎓 Advantages:

Guarantees the shortest path in an unweighted graph.<br>
Suitable for finding connectivity and components in a graph.<br>

🔥 Disadvantages:

Inefficient for large graphs due to the need for additional storage.<br>
May require modifications for weighted graphs.

![image](https://github.com/DuarteDvv/Algorithms/assets/136333571/0aaaaabf-b2e7-4565-af3e-c69cdedc5ea4)



