#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int V, vector<vector<int>> &edges)
{
    vector<int> graph[V], color(V, -1);
    queue<int> q;
    for (auto &i : edges)
    {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    q.push(0);
    color[0] = 0;
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();

        for (auto &v : graph[u])
            if (color[v] == -1)
            {
                color[v] = !color[u];
                q.push(v);
            }
            else if (color[v] == color[u])
                return false;
    }
    return true;
}

// If there is division of graph into multiple groups think about bipartiteness