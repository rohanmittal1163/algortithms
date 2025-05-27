#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}

// O(V + E) O(V)

// Detect cycles
// Find connected components
// Solve maze
// graph path problems
// Do topological sorting

void dfs(int start, vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    stack<int> st;

    st.push(start);

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            cout << node << " ";
            visited[node] = true;

            for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it)
            {
                if (!visited[*it])
                    st.push(*it);
            }
        }
    }
}
