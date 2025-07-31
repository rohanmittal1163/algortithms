#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // map<x (vertical), map<y (level), multiset<node values>>>
        map<int, map<int, multiset<int>>> nodes;

        // queue of pair: node, pair<x, y>
        queue<pair<TreeNode *, pair<int, int>>> todo;
        todo.push({root, {0, 0}}); // root at (x=0, y=0)

        while (!todo.empty())
        {
            auto p = todo.front();
            todo.pop();

            TreeNode *node = p.first;
            int x = p.second.first;  // horizontal distance
            int y = p.second.second; // depth level

            nodes[x][y].insert(node->val);

            if (node->left)
                todo.push({node->left, {x - 1, y + 1}});
            if (node->right)
                todo.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> ans;
        for (auto &p : nodes)
        {
            vector<int> col;
            for (auto &q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
