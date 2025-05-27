#include <bits/stdc++.h>
using namespace std;

// O(V+ELOGV) // O(V)

vector<vector<pair<int, int>>> constructAdj(vector<vector<int>>
                                                &edges,
                                            int V)
{

    vector<vector<pair<int, int>>> adj(V);

    for (const auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    return adj;
}

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{

    vector<vector<pair<int, int>>> graph = constructAdj(edges, V);
    priority_queue<pair<int, int>> pq;
    vector<int> dist(V, INT_MAX);
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        auto rem = pq.top();
        pq.pop();
        int d = -rem.first;
        int u = rem.second;

        for (auto x : graph[u])
        {
            int v = x.first;
            int wt = x.second;

            if (dist[v] > d + wt)
            {
                dist[v] = d + wt;
                pq.push({-dist[v], v});
            }
        }
    }

    return dist;
}

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src, int dest)
{

    vector<vector<pair<int, int>>> graph = constructAdj(edges, V);
    priority_queue<pair<int, int>> pq;
    vector<int> dist(V, INT_MAX), parent(V, -1), path;
    pq.push({0, src});
    dist[src] = 0;

    // for (int i = 0; i < V; i++)
    //     parent[i] = i;
    iota(parent.begin(), parent.end(), 0);

    while (!pq.empty())
    {
        auto rem = pq.top();
        pq.pop();
        int d = -rem.first;
        int u = rem.second;

        for (auto x : graph[u])
        {
            int v = x.first;
            int wt = x.second;

            if (dist[v] > d + wt)
            {
                dist[v] = d + wt;
                pq.push({-dist[v], v});
                parent[v] = u;
            }
        }
    }
    if (dist[dest] == INT_MAX)
        return {};

    while (parent[dest] != dest)
    {
        path.push_back(dest);
        dest = parent[dest];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());

    return path;
}
