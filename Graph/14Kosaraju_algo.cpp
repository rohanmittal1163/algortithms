#include <bits/stdc++.h>
using namespace std;
// Kosaraju's Algorithm for finding Strongly Connected Components (SCCs) in
//  a directed graph:

vector<vector<int>>
    adj, rev_adj;
vector<bool> visited;
stack<int> st;

void dfs1(int node)
{
    visited[node] = true;
    for (int v : adj[node])
        if (!visited[v])
            dfs1(v);
    st.push(node); // finished processing
}

void dfs2(int node, vector<int> &component)
{
    visited[node] = true;
    component.push_back(node);
    for (int v : rev_adj[node])
        if (!visited[v])
            dfs2(v, component);
}

void kosaraju(int n)
{
    visited.assign(n, false);
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            dfs1(i); // 1st pass

    // Reverse the graph
    rev_adj.assign(n, {});
    for (int u = 0; u < n; ++u)
        for (int v : adj[u])
            rev_adj[v].push_back(u); // reverse edge

    visited.assign(n, false);
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            vector<int> component;
            dfs2(node, component);
            // component is one SCC
        }
    }
}

// sort the nodes on the basis of finishing time
// Transpose the graph (reverse all edges).
// Pop from the stack and do DFS if the node is unvisited.
// Each DFS tree gives one SCC.

// O(V + E)(Two DFS passes + edge reversal)
// Works for directed graphs only.