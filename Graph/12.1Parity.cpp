#include <bits/stdc++.h>
using namespace std;
class DSU
{
    vector<int> parent, size, parity;

public:
    DSU(int n)
    {
        parent.resize(n, 0);
        size.resize(n, 1);
        parity.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int findUpar(int x)
    {
        if (parent[x] == x)
            return x;
        int par = parent[x];
        parent[x] = findUpar(par);
        parity[x] ^= parity[par];
        return parent[x];
    }

    bool unionBySize(int u, int v, int t)
    {
        int upar_u = findUpar(u);
        int upar_v = findUpar(v);

        if (upar_u == upar_v)
        {
            return ((parity[u] ^ parity[v]) == t);
        }

        if (size[upar_u] < size[upar_v])
        {
            parent[upar_u] = upar_v;
            size[upar_v] += size[upar_u];
            parity[upar_u] = (parity[v] ^ t ^ parity[u]);
        }
        else
        {
            parent[upar_v] = upar_u;
            size[upar_u] += size[upar_v];
            parity[upar_v] = parity[u] ^ parity[v] ^ t;
        }
        return true;
    }

    int relation(int u, int v)
    {
        int upar_u = findUpar(u);
        int upar_v = findUpar(v);
        if (upar_u != upar_v)
        {
            return 2;
        }
        return (parity[u] ^ parity[v]);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q, t;
    string temp, x, y;
    unordered_map<string, int> idx;
    ostringstream out;
    cin >> n >> m >> q;
    DSU dsu(n);
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        idx[temp] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t >> x >> y;
        int idx_x = idx[x];
        int idx_y = idx[y];
        bool res = dsu.unionBySize(idx_x, idx_y, t - 1);
        if (res)
            out << "YES\n";
        else
            out << "NO\n";
    }

    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        int idx_x = idx[x];
        int idx_y = idx[y];
        out << 1 + dsu.relation(idx_x, idx_y) << endl;
    }
    cout << out.str();

    return 0;
}