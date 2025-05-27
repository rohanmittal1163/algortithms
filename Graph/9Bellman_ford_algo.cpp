
#include <bits/stdc++.h>
using namespace std;

// O(VE) O(V)

vector<int> bellmanFord(int n, int src, vector<vector<int>> &edges)
{
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Relax all edges (n - 1) times
    for (int i = 0; i < n - 1; i++)
    {
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Optional: Detect negative weight cycle
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            // Negative cycle detected
            return {-1};
        }
    }

    return dist;
}
