#include <bits/stdc++.h>
using namespace std;

// UNDIRECTED GRAPHS

// Union Find
// O(E * α(V)) O(V)
// if there is edge list given u can prefer this

int find(int x, vector<int> &parent)
{
    if (parent[x] == -1)
        return x;
    return parent[x] = find(parent[x], parent);
}

bool unionCycle(vector<pair<int, int>> &edges, int n)
{
    vector<int> parent(n, -1);
    for (auto i : edges)
    {
        int pu = find(i.first, parent);
        int pv = find(i.second, parent);
        if (pu == pv)
            return true; // cycle found
        parent[pu] = pv;
    }
    return false;
}

// UNDIRECTED GRAPHS

// BFS
// O(V + E) O(V)
// if there is adjacency list
bool bfs(int start, vector<int> adj[], vector<bool> &vis)
{
    queue<pair<int, int>> q;
    vis[start] = true;
    q.push({start, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adj[node])
        {
            if (!vis[neighbor])
            {
                vis[neighbor] = true;
                q.push({neighbor, node});
            }
            else if (neighbor != parent)
            {
                return true; // cycle found
            }
        }
    }
    return false;
}

// UNDIRECTED
// DFS
// O(V + E) O(V)
// if there is adjacency list
bool dfs(int node, int parent, vector<bool> &vis, vector<int> adj[])
{
    vis[node] = true;
    for (int neighbor : adj[node])
    {
        if (!vis[neighbor])
        {
            if (dfs(neighbor, node, vis, adj))
                return true;
        }
        else if (neighbor != parent)
        {
            return true; // cycle found
        }
    }
    return false;
}

// DIRECTED GRAPHS

// Kahn's algorithm - BFS Based Topological sort
// O(V + E) O(V)
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

// CYCLE LENGTH
