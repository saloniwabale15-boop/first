#include <bits/stdc++.h>
using namespace std;

int shortestPath(int V, vector<vector<int>>& edges, int start, int end) {
    // Build adjacency list
    vector<vector<int>> graph(V);
    for (auto& e : edges) {
        int u = e[0], v = e[1];
        graph[u].push_back(v);
        graph[v].push_back(u); // undirected graph
    }

    // BFS
    queue<pair<int, int>> q; // (node, distance)
    vector<bool> visited(V, false);
    
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();

        if (node == end) return dist; // found shortest path

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, dist + 1});
            }
        }
    }
    return -1; // no path
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    int start = 0, end = 4;

    cout << shortestPath(V, edges, start, end) << endl; 
    
    return 0;
}