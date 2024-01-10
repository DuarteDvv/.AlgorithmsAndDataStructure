#include <iostream>
# <vector>
#include <queue>

using namespace std;

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 1000

// Define the graph structure using adjacency lists
struct Graph {
    int V; // Number of vertices
    vector<int> adj[MAX_VERTICES]; // Adjacency lists
};

// Function to initialize the graph
Graph* createGraph(int V) {
    Graph* graph = new Graph();
    graph->V = V;

    for (int i = 0; i < V; i++) {
        graph->adj[i].clear();
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src].push_back(dest);
    graph->adj[dest].push_back(src); // For undirected graph
}

// Function to perform BFS traversal of the graph
void BFS(Graph* graph, int startVertex) {
    // Create a boolean array to keep track of visited vertices
    bool visited[MAX_VERTICES] = {false};

    // Create a queue for BFS traversal
    queue<int> q;

    // Mark the starting vertex as visited and enqueue it
    visited[startVertex] = true;
    q.push(startVertex);

    // Loop until the queue is empty
    while (!q.empty()) {
        // Dequeue a vertex from the queue
        int currentVertex = q.front();
        q.pop();

        // Print the current vertex
        cout << currentVertex << " ";

        // Loop through all the adjacent vertices of the current vertex
        for (int i = 0; i < graph->adj[currentVertex].size(); i++) {
            int adjacentVertex = graph->adj[currentVertex][i];

            // If the adjacent vertex is not visited, mark it as visited and enqueue it
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = true;
                q.push(adjacentVertex);
            }
        }
    }
}

// Main function
int main() {
    // Create a graph with 5 vertices
    Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    // Perform BFS traversal starting from vertex 0
    BFS(graph, 0);

    return 0;
}
