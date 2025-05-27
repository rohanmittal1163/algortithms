#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Adjacency Matrix
    int V = 4;
    vector<vector<int>> mat(V, vector<int>(V, 0));
    mat[0][1] = mat[1][0] = 1;
    mat[0][2] = mat[2][0] = 1;
    mat[1][2] = mat[2][1] = 1;
    mat[2][3] = mat[3][2] = 1;

    // Adding edge - O(1)
    // Removing Edge - O(1)
    // Initialising - O(N*N)

    // Adjacency List Dynamic
    vector<vector<int>> adj(V);
    adj[0].push_back(1), adj[1].push_back(0);
    adj[0].push_back(2), adj[2].push_back(0);
    adj[1].push_back(2), adj[2].push_back(1);
    adj[2].push_back(3), adj[3].push_back(2);

    // Adjacency List Static
    vector<int> adj[100];
    vector<int> adj2[V];

    // but can use if V=arr.size(); -> Dynamically changed

    // Adding edge - O(1)
    // Removing Edge - O(N)
    // Initialising - O(N)

    return 0;
}