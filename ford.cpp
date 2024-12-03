#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Bellman-Ford Algorithm Function
void bellmanFord(int vertices, int edgesCount, vector<Edge>& edges, int source) {
    // Initialize distances from source to all vertices as infinite
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    // Relax edges |V| - 1 times
    for (int i = 0; i < vertices - 1; ++i) {
        for (int j = 0; j < edgesCount; ++j) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < edgesCount; ++j) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            cout << "Graph contains a negative weight cycle." << endl;
            return;
        }
    }

    // Print distances
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << i << "\t" << (distance[i] == INT_MAX ? "INF" : to_string(distance[i])) << endl;
    }
}

int main() {
    int vertices, edgesCount, source;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edgesCount;

    vector<Edge> edges(edgesCount);
    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < edgesCount; ++i) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(vertices, edgesCount, edges, source);

    return 0;
}

