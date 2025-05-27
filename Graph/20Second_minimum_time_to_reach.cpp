#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> graph(n);
        for (auto &edge : edges)
        {
            int u = edge[0] - 1, v = edge[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<vector<int>> arrival(n);
        queue<pair<int, int>> q;
        q.push({0, 0});
        arrival[0].push_back(0);

        while (!q.empty())
        {
            auto rem = q.front();
            q.pop();
            int curTime = rem.first;
            int u = rem.second;

            for (int v : graph[u])
            {
                int wait = (curTime / change) % 2 == 1 ? change - (curTime % change) : 0;
                int reachTime = curTime + wait + time;

                if (arrival[v].empty() || (arrival[v].size() == 1 && arrival[v][0] != reachTime) || (arrival[v].size() == 2 && arrival[v][0] != reachTime && arrival[v][1] != reachTime && arrival[v][1] > reachTime))
                {

                    arrival[v].push_back(reachTime);
                    sort(arrival[v].begin(), arrival[v].end());
                    if (arrival[v].size() > 2)
                        arrival[v].pop_back();
                    q.push({reachTime, v});
                }
            }
        }

        return arrival[n - 1][1];
    }
};
