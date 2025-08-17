#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// O(N) O(H)
// Returns pointer to LCA if both nodes exist; otherwise nullptr.
TreeNode *lcaBinaryTree(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || root == p || root == q)
        return root;
    TreeNode *L = lcaBinaryTree(root->left, p, q);
    TreeNode *R = lcaBinaryTree(root->right, p, q);
    if (L && R)
        return root;
    return L ? L : R;
}
// O(H) O(1)
TreeNode *lcaBST(TreeNode *root, TreeNode *p, TreeNode *q)
{
    int a = min(p->val, q->val), b = max(p->val, q->val);
    while (root)
    {
        if (root->val > b)
            root = root->left;
        else if (root->val < a)
            root = root->right;
        else
            return root; // a <= root->val <= b
    }
    return nullptr;
}
