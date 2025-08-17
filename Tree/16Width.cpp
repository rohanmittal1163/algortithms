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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (q.empty() == false)
        {
            int size = q.size();
            int first, last;
            for (int i = 0; i < size; i++)
            {
                auto rem = q.front();
                q.pop();
                TreeNode *node = rem.first;
                int idx = rem.second;
                if (i == 0)
                    first = idx;
                if (i == size - 1)
                    last = idx;
                if (node->left)
                    q.push({node->left, 2 * idx + 1});
                if (node->right)
                    q.push({node->right, 2 * idx + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};