#include <bits/stdc++.h>
using namespace std;

int primsMST(int V, vector<vector<pair<int, int>>> &adj)
{
    vector<bool> visited(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, 0}); // {weight, node}
    int mstCost = 0;

    while (!pq.empty())
    {
        auto rem = pq.top();
        int wt = rem.first;
        int u = rem.second;
        pq.pop();
        if (visited[u])
            continue;

        visited[u] = true;
        mstCost += wt;

        for (auto x : adj[u])

        {
            int v = x.first;
            int weight = x.second;
            if (!visited[v])
            {
                pq.push({weight, v});
            }
        }
    }

    return mstCost;
}

// O(E * log V) using Min Heap + Adjacency List
// Sparse graphs
// Greedy algorithm
// Negative weight edges are allowed.
// Prim’s does not work for disconnected graphs. Use Kruskal’s or run Prim's for each component.
