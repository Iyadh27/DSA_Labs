#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;  // pair representing (weight, vertex)

// Function to find the minimum spanning tree using Prim's algorithm
vector<pair<int, pii>> primMST(vector<vector<int>>& graph, int startNode) {
    int n = graph.size();  // Number of vertices in the graph
    vector<bool> visited(n, false);
    vector<pair<int, pii>> edges;  // All edges in the minimum spanning tree
    priority_queue<pii, vector<pii>, greater<pii>> pq;  // Priority queue to select the next edge

    // Start with the given start node
    pq.push(make_pair(0, startNode));

    while (!pq.empty()) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        // Traverse the neighbors of the current vertex
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != 0 && !visited[v]) {
                // Add the edge to the minimum spanning tree
                edges.push_back(make_pair(graph[u][v], make_pair(u, v)));

                // Add the neighbor to the priority queue
                pq.push(make_pair(graph[u][v], v));
            }
        }
    }

    return edges;
}

int main() {
    vector<vector<int>> graph = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    int startNode = 0;

    // Find all the edges and their weights in the minimum spanning tree using Prim's algorithm
    vector<pair<int, pii>> edges = primMST(graph, startNode);

    // Sort the edges based on their weights in non-decreasing order
    sort(edges.begin(), edges.end());

    // Print the edges and their weights
    for (auto edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        cout << "Edge (" << u << ", " << v << ") with weight " << weight << endl;
    }

    return 0;
}
