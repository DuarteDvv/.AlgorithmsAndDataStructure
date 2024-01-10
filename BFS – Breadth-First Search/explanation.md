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

BFS has several applications, including:

* Peer-to-peer networks: BFS can be used to find all neighbor nodes in a peer-to-peer network.
* Crawlers in search engines: BFS can be used to build an index of a website by starting at the homepage and following all links from the current page.
* Social networking websites: BFS can be used to find people within a given distance from a person in a social network.
* GPS navigation systems: BFS can be used to find all neighboring locations in a GPS navigation system.
* Broadcasting in networks: BFS can be used to broadcast a packet to all nodes in a network.
* In garbage collection: BFS can be used in copying garbage collection using Cheney's algorithm.
* Cycle detection in undirected graphs: BFS can be used to detect a cycle in an undirected graph.
* Path finding: BFS can be used to find if there is a path between two vertices in a graph.
* Finding all nodes within one connected component: BFS can be used to find all nodes reachable from a given node.
* AI: BFS can be used in traversing a game tree to find the best move.
* Network security: BFS can be used in traversing a network to find all the devices connected to it.
* Connected Component: BFS can be used to find all connected components in an undirected graph.
* Topological sorting: BFS can be used to find a topological ordering of the nodes in a directed acyclic graph (DAG).
* Image processing: BFS can be used to flood-fill an image with a particular color or to find connected components of pixels.
* Recommender systems: BFS can be used to find similar items in a large dataset by traversing the items' connections in a similarity graph.

![image](https://github.com/DuarteDvv/Algorithms/assets/136333571/51874a5e-ebd8-4802-83ba-0266485f3546)
