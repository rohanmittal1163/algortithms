#include <bits/stdc++.h>
using namespace std;

// Kahn's algorithm - BFS Based Topological sort
// O(V + E) O(V)
// detect cycle in a directed graphs

bool isCyclic(int V, vector<vector<int>> &adj)
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
        for (int j : adj[i])
            indegree[j]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for (int neighbor : adj[node])
            if (--indegree[neighbor] == 0)
                q.push(neighbor);
    }
    return count != V;
}

vector<int> eventualSafeNodes(int V, vector<int> adj1[])
{
    vector<int> inDeg(V, 0), vec;
    vector<int> graph[V];
    queue<int> q;

    for (int u = 0; u < V; u++)
    {
        for (auto v : adj1[u])
            graph[v].push_back(u);
        inDeg[u] = adj1[u].size();
        if (inDeg[u] == 0)
            q.push(u);
    }

    while (q.empty() == false)
    {
        auto rem = q.front();
        q.pop();
        vec.push_back(rem);

        for (auto &i : graph[rem])
        {
            inDeg[i]--;
            if (inDeg[i] == 0)
                q.push(i);
        }
    }

    sort(vec.begin(), vec.end());
    return vec;
}

// SHORTEST PATH IN DIRECTED ACYCLIC GRAPH
//  O(V+E) O(V)

vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
{
    // code here
    vector<pair<int, int>> graph[V];
    vector<int> ans(V, INT_MAX), indeg(V, 0), topoSort(V, 0);
    queue<int> q;

    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        graph[u].push_back({v, wt});
        indeg[v]++;
    }

    ans[0] = 0;

    for (int i = 0; i < V; i++)
        if (indeg[i] == 0)
            q.push(i);

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        topoSort.push_back(u);

        for (auto i : graph[u])
        {
            int v = i.first;
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }

    for (int i = 0; i < V; i++)
        q.push(topoSort[i]);

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for (auto i : graph[u])
        {
            int v = i.first;
            int wt = i.second;

            if (ans[u] + wt < ans[v])
            {
                ans[v] = ans[u] + wt;
            }
        }
    }

    for (int i = 0; i < V; i++)
        if (ans[i] == INT_MAX)
            ans[i] = -1;

    return ans;
}