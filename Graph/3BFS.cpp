#include <bits/stdc++.h>
using namespace std;

void BFS(int start, vector<int> adj[], int n)
{
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Dijkstra’s shortest path, Kahn’s Algorithm, and Prim’s algorithm
// detect cycle in a directed and undirected graph
// find shortest path in an unweighted graph
// O(V+E) O(V)
