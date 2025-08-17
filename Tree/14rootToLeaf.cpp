#include <bits/stdc++.h>
using namespace std;

// Definition of a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Helper function to get the path from root to a given node
    bool getPath(TreeNode *root, vector<int> &arr, int x)
    {
        if (!root)
            return false;

        arr.push_back(root->val);

        if (root->val == x)
            return true;

        if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
            return true;

        arr.pop_back();
        return false;
    }

public:
    vector<int> solve(TreeNode *A, int B)
    {
        vector<int> arr;
        if (A == NULL)
        {
            return arr;
        }
        getPath(A, arr, B);
        return arr;
    }
};
