#include <bits/stdc++.h>
using namespace std;

// Union Find + Tortoise_hare - Functional graph
class Solution
{
    vector<int> parent, size;

public:
    int findUpar(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findUpar(parent[x]);
    }
    void unionBySize(int u, int v)
    {
        int upar_u = findUpar(u);
        int upar_v = findUpar(v);

        if (upar_u == upar_v)
            return;

        if (size[upar_u] < size[upar_v])
        {
            parent[upar_u] = upar_v;
            size[upar_v] += size[upar_u];
        }
        else
        {
            parent[upar_v] = upar_u;
            size[upar_u] += size[upar_v];
        }
    }
    int h(int node, vector<int> &edges)
    {
        int slow = node, fast = node;

        do
        {
            if (slow == -1 || fast == -1)
                return -1;
            slow = edges[slow];
            fast = edges[fast];
            if (fast == -1)
                return -1;
            fast = edges[fast];
        } while (slow != fast);

        slow = node;
        while (slow != fast)
        {
            slow = edges[slow];
            fast = edges[fast];
        }

        int cnt = 1;
        slow = edges[slow];
        while (slow != fast)
        {
            slow = edges[slow];
            cnt++;
        }
        return cnt;
    }
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size(), ans = -1;

        parent.resize(n, 1);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < n; i++)
            if (edges[i] != -1)
                unionBySize(i, edges[i]);

        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                ans = max(ans, h(i, edges));

        return ans;
    }
};

// Topological sort  - Functional graph
class Solution
{
public:
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size(), ans = -1, cnt, curr;
        vector<int> indeg(n, 0);
        queue<int> q;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++)
            if (edges[i] != -1)
                indeg[edges[i]]++;

        for (int i = 0; i < n; i++)
            if (indeg[i] == 0)
                q.push(i);

        while (q.empty() == false)
        {
            int u = q.front(), v = edges[u];
            q.pop();
            vis[u] = 1;
            if (v != -1 && --indeg[v] == 0)
                q.push(v);
        }

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                cnt = 0;
                curr = i;
                while (vis[curr] == 0)
                {
                    vis[curr] = 1;
                    curr = edges[curr];
                    cnt++;
                }
            }
            if (cnt > 1)
                ans = max(ans, cnt);
        }
        return ans;
    }
};

// DFS - Directed Graph
class Solution
{
public:
    vector<bool> vis, inStack;
    vector<int> depth;
    int minCycle = INT_MAX, maxCycle = -1;
    void dfs(int u, int d, vector<vector<int>> &graph)
    {
        vis[u] = true;
        inStack[u] = true;
        depth[u] = d;

        for (int v : graph[u])
        {
            if (!vis[v])
                dfs(v, d + 1, graph);
            else if (inStack[v])
            {
                int cycleLen = depth[u] - depth[v] + 1;
                minCycle = min(minCycle, cycleLen);
                maxCycle = max(maxCycle, cycleLen);
            }
        }

        inStack[u] = false;
    }
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size(), ans = -1, cnt, curr;
        vis.assign(n, false);
        inStack.assign(n, false);
        depth.assign(n, 0);
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++)
            if (edges[i] != -1)
                graph[i].push_back(edges[i]);
        for (int i = 0; i < n; ++i)
            if (!vis[i])
                dfs(i, 0, graph);
        return maxCycle;
    }
};

// BFS - Undirected Graph - Shortest cycle length
class Solution
{
public:
    int bfs(int i, vector<vector<int>> &graph, int n)
    {
        queue<tuple<int, int, int>> q;
        q.push({-1, i, 0});
        int ans = INT_MAX;
        vector<int> distance(n, INT_MAX);
        distance[i] = 0;
        while (q.empty() == false)
        {
            auto rem = q.front();
            q.pop();
            int pr = get<0>(rem);
            int u = get<1>(rem);
            int k = get<2>(rem);
            for (auto &v : graph[u])
            {
                if (v == pr)
                    continue;

                if (distance[v] == INT_MAX)
                {
                    distance[v] = k + 1;
                    q.push({u, v, k + 1});
                }
                else
                    ans = min(ans, distance[v] + k + 1);
            }
        }
        return ans;
    }
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {

        vector<vector<int>> graph(n);
        int ans = INT_MAX;
        for (auto i : edges)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }

        for (int i = 0; i < n; i++)
            ans = min(ans, bfs(i, graph, n));

        return ans == INT_MAX ? -1 : ans;
    }
};

// DFS - Cycle of length n for small graphs
class Solution
{
    static const int V = 5;

public:
    void dfsCycle(bool graph[V][V], vector<bool> &visited, int current, int start, int remainingLen, int &cycleCount)
    {
        visited[current] = true;

        // Base case: cycle of required length found
        if (remainingLen == 0)
        {
            visited[current] = false;

            // If there is an edge from last node to starting node, a cycle is found
            if (graph[current][start])
            {
                cycleCount++;
            }
            return;
        }

        for (int neighbor = 0; neighbor < V; ++neighbor)
        {
            if (!visited[neighbor] && graph[current][neighbor])
            {
                dfsCycle(graph, visited, neighbor, start, remainingLen - 1, cycleCount);
            }
        }

        visited[current] = false; // Backtrack
    }

    // Main function to count cycles of length `n`
    int countCyclesOfLengthN(bool graph[V][V], int cycleLength)
    {
        vector<bool> visited(V, false);
        int totalCycles = 0;

        // Try starting DFS from each node, but only up to V - (n - 1)
        for (int start = 0; start <= V - cycleLength; ++start)
        {
            dfsCycle(graph, visited, start, start, cycleLength - 1, totalCycles);
            visited[start] = true; // Prevent repeated cycles starting from same node
        }

        return totalCycles / 2; // Each cycle is counted twice (u-v-w and w-v-u)
    }
};