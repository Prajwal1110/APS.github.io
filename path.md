# Shortest Path Routing Algorithm for Distance

## Algorithm: Dijkstra's Algorithm

### Data Structures Used:
- **Graph Representation:** Adjacency lists.
- **Priority Queue:** Used for implementing Dijkstra's algorithm efficiently.

### Challenges:
- Handling large graphs efficiently.
- Dealing with negative edge weights (if applicable).
- Implementing efficient priority queue operations.

### Benefits:
- Optimizes navigation for drivers.
- Minimizes travel time and fuel consumption.
- Enhances user satisfaction by providing quicker routes.

### Example Code (C++):
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent a vertex in the graph
struct Vertex {
    int id;
    vector<pair<int, int>> edges; // {neighbor vertex, edge weight}
    int distance; // Shortest distance from source
    bool visited;

    Vertex(int id) : id(id), distance(numeric_limits<int>::max()), visited(false) {}
};

// Dijkstra's algorithm to find shortest path from source to all vertices
void dijkstra(vector<Vertex>& graph, int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {distance, vertex}

    // Initialize source vertex
    graph[source].distance = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (graph[u].visited)
            continue;

        graph[u].visited = true;

        // Update distances of adjacent vertices
        for (auto& edge : graph[u].edges) {
            int v = edge.first;
            int weight = edge.second;

            if (!graph[v].visited && graph[u].distance + weight < graph[v].distance) {
                graph[v].distance = graph[u].distance + weight;
                pq.push({graph[v].distance, v});
            }
        }
    }
}

int main() {
    // Example usage of Dijkstra's algorithm
    int numVertices = 6;
    vector<Vertex> graph(numVertices, Vertex(-1));

    // Example graph representation (vertex, {neighbor vertex, edge weight})
    graph[0].edges = {{1, 7}, {2, 9}, {5, 14}};
    graph[1].edges = {{0, 7}, {2, 10}, {3, 15}};
    graph[2].edges = {{0, 9}, {1, 10}, {3, 11}, {5, 2}};
    graph[3].edges = {{1, 15}, {2, 11}, {4, 6}};
    graph[4].edges = {{3, 6}, {5, 9}};
    graph[5].edges = {{0, 14}, {2, 2}, {4, 9}};

    int source = 0;
    dijkstra(graph, source);

    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": " << graph[i].distance << endl;
    }

    return 0;
}
