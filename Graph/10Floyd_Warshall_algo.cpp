
#include <bits/stdc++.h>
using namespace std;

void floydWarshall(int n, vector<vector<int>> &dist)
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] != 1e9 && dist[k][j] != 1e9)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (dist[i][i] < 0)
        {
            // Negative cycle detected
        }
    }
}
int main()
{
    int n = 4;
    vector<vector<int>> dist(n, vector<int>(n, 1e9));

    // Initialize distances
    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;

    // Add edges
    dist[0][1] = 5;
    dist[1][2] = 3;
    dist[2][3] = 1;
    dist[0][3] = 10;
}

// Computes shortest paths between all pairs of vertices.
// Based on dynamic programming.
//  O(N^3) O(N^2)
// use floyd warshall algo for only negative cycle and weights otherwise use dijiktras algo n^2logn
// Best suited for dense graphs