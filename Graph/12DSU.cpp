#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, rank, size;

public:
    DSU(int n)
    {
        parent.resize(n, 0);
        rank.resize(n, 0);
        size.resize(n, 1); // init
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Path Compression
    int findUpar(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findUpar(parent[x]);
    }

    // Union by Rank
    void unionByRank(int u, int v)
    {
        int upar_u = findUpar(u);
        int upar_v = findUpar(v);

        if (upar_u == upar_v)
            return;

        if (rank[upar_u] < rank[upar_v])
        {
            parent[upar_u] = upar_v;
        }
        else if (rank[upar_u] > rank[upar_v])
        {
            parent[upar_v] = upar_u;
        }
        else
        {
            parent[upar_v] = upar_u;
            rank[upar_u]++;
        }
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
};

// O(α(n)), Inverse Ackermann, nearly constant time, | O(n)
