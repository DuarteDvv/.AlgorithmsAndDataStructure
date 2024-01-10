import java.util.ArrayDeque;
import java.utilDeque;
import java.util.LinkedList;
import.util.List;
import java.util.Queue;

public class example {

    public static void bfs(List<List<Integer>> graph, int start) {
        Queue<Integer> queue = new ArrayDeque<>();
        boolean[] visited = new boolean[graph.size()];

        queue.offer(start);
        visited[start] = true;

        while (!queue.isEmpty()) {
            int current = queue.poll();
            System.out.print(current + " ");

            for (int neighbor : graph.get(current)) {
                if (!visited[neighbor]) {
                    queue.offer(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    public static void main(String[] args) {
        List<List<Integer>> graph = new LinkedList<>();
        int numVertices = 8;

        for (int i = 0; i < numVertices; i++) {
            graph.add(new LinkedList<>());
        }

        addEdge(graph, 1, 2);
        addEdge(graph, 1, 3);
        addEdge(graph, 2, 4);
        addEdge(graph, 2, 5);
        addEdge(graph, 3, 6);
        addEdge(graph, 3, 7);
        addEdge(graph, 5, 8);

        bfs(graph, 1);
    }

    private static void addEdge(List<List<Integer>> graph, int src, int dest) {
        graph.get(src).add(dest);
        graph.get(dest).add(src);
    }
}
