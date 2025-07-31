#include <bits/stdc++.h>
using namespace std;

// Diameter of a tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class Solution
{
public:
    int diameterOfBinaryTree(Node *root)
    {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

    int height(Node *node, int &diameter)
    {
        if (!node)
            return 0;

        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }
};

// Diameter of a graph
int mx = 0, node = 0;

void dfs(int source, int far, vector<int> graph[], int parent)
{
    if (far > mx)
    {
        mx = far;
        node = source;
    }
    for (auto i : graph[source])
        if (i != parent)
            dfs(i, far + 1, graph, source);
}

int main()
{
    int n;
    cin >> n;
    vector<int> graph[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> vis(n, false);
    dfs(1, 0, graph, -1);
    dfs(node, 0, graph, -1);
    cout << 3 * mx << endl;
    return 0;
}