
#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> adj(vertices);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(vertices, false);

    int start;
    cout << "Enter starting vertex (0 to "
         << vertices - 1 << "): ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start, adj, visited);

    cout << endl;
    return 0;
}
