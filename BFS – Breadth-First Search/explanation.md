# Breadth-First Search Algorithm

Breadth-First Search (BFS) is a graph traversal algorithm that starts at a root node and explores the nodes at the level before moving on the next level. It uses a queue data structure to keep track of the next node to visit.

Here's how the BFS algorithm works:

1. Start by putting the root node on a queue and marking it as visited.
2. While the queue is not empty, do the following:
	* Pop off the node at the head of the queue.
	* If it is the node we are searching for, exit and return the node.
	* For all of the unvisited neighbors, mark the neighbor as visited and put the neighbor in the queue.
3. If we get here, the node is not reachable from the starting node, BFS failed.

The BFS algorithm can be used to find the shortest path in an unweighted graph, as it visits nodes in increasing order of distance from the starting node. It can also be used to find a minimum spanning tree in a graph with non-negative edge weights.

![image](https://github.com/DuarteDvv/Algorithms/assets/136333571/0aaaaabf-b2e7-4565-af3e-c69cdedc5ea4)

BFS has several applications, including:

* Peer-to-peer networks: BFS can be used to find all neighbor nodes in a peer-to-peer network.
* GPS navigation systems: BFS can be used to find all neighboring locations in a GPS navigation system.
* Path finding: BFS can be used to find if there is a path between two vertices in a graph.
* Finding all nodes within one connected component: BFS can be used to find all nodes reachable from a given node.
* Connected Component: BFS can be used to find all connected components in an undirected graph.



