///////////////////////////////// THIS GIVES THE BEST CITY THAT YOU SHOULD BUILD HOSPITAL IN ////////////////////////////////////////////////////
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

    int arr[6];
    for (int i = 0; i < n; ++i) {
        
        int sum =0;
        int source;
        cout << "Enter source node " << i <<" :";
        cin >> source;

        vector<int> shortest_distances = Dijkstra(adjacencyMatrix, source);

        // Output the shortest distances from the source vertex to all other vertices
        for (int i = 0; i < n; ++i) {
            //cout << "Shortest distance from " << source << " to " << i << ": ";
            if (shortest_distances[i] != numeric_limits<int>::max()) {
                //cout << shortest_distances[i] << endl;
                sum += shortest_distances[i];
            } else {
                cout << "No path exists" << endl;
            }
        }
        arr[i] = sum;
    }
    int min = INT_MAX;
    int flag = 0;
    for(int i = 0; i <n; i++){
        if (arr[i] < min){ 
            min = arr[i];
            flag ++;
        }
    }
    cout << "city " << flag << " is the best to build the hospital";
    return 0;
}
