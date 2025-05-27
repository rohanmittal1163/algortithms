#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<int> parent, size;

public:
    Solution()
    {
        parent.clear();
        size.clear();
    }
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
    int isEulerCircuit(int n, vector<int> graph[])
    {
        int cnt = 0, odd = 0;
        parent.assign(n, 0);
        vector<int> deg(n, 0);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
        for (int u = 0; u < n; u++)
            for (auto &v : graph[u])
            {
                unionBySize(u, v);
                deg[v]++;
            }

        for (int i = 0; i < n; i++)
        {
            if (size[i] > 1)
                cnt++;
            if (deg[i] % 2)
                odd++;
        }

        if (cnt > 1)
            return 0;

        if (odd == 0)
            return 2;
        if (odd == 2)
            return 1;
        return 0;
    }
};