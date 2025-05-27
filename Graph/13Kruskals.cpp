#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, rank, size;

public:
    int findUpar(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findUpar(parent[x]);
    }
    bool unionBySize(int u, int v)
    {
        int upar_u = findUpar(u);
        int upar_v = findUpar(v);

        if (upar_u == upar_v)
            return 0;

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
        return 1;
    }
    int kruskal(int n, vector<tuple<int, int, int>> &edges)
    {
        parent.resize(n, 0);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
        sort(edges.begin(), edges.end());
        int mst_weight = 0;

        for (auto &i : edges)
            if (unionBySize(get<1>(i), get<2>(i)))
                mst_weight += get<0>(i);
        return mst_weight;
    }
};

// O(E log E)+ O(α(N))
// greedy algorithm
// edge based | DSU | disconnected graph | dense