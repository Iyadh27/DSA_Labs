#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<int> Dijkstra(const vector<vector<int>>& adjacencyMatrix, int source) {
    int n = adjacencyMatrix.size();
    vector<int> distance(n, numeric_limits<int>::max());  // Distance array
    distance[source] = 0;

    // Priority queue to store (distance, vertex) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Visit each neighbor of u
        for (int v = 0; v < n; ++v) {
            int weight = adjacencyMatrix[u][v];

            // Relaxation step: Update distance if a shorter path is found
            if (weight > 0 && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    return distance;
}

int main() {
    int n = 6;  // Number of vertices
    //cin >> n;

    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        cout << "enter line: ";
        for (int j = 0; j < n; ++j) {
            
            cin >> adjacencyMatrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {

        int source;
        cout << endl << "Enter source node: ";
        cin >> source;

        vector<int> shortest_distances = Dijkstra(adjacencyMatrix, source);

        // Output the shortest distances from the source vertex to all other vertices
        for (int i = 0; i < n; ++i) {
            cout << "Shortest distance from " << source << " to " << i << ": ";
            if (shortest_distances[i] != numeric_limits<int>::max()) {
                cout << shortest_distances[i] << endl;
            } else {
                cout << "No path exists" << endl;
            }
        }
    }
    return 0;
}
