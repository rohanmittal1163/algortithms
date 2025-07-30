#include <bits/stdc++.h>
using namespace std;
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

int height(Node *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int isBalancedRec(Node *root)
{
    if (root == nullptr)
        return 0;
    int lheight = isBalanced(root->left);
    int rheight = isBalanced(root->right);
    if (abs(lheight - rheight) > 1 || lheight == -1 || rheight == -1)
    {
        return -1;
    }
    return 1 + max(lheight, rheight);
}
bool isBalanced(Node *root)
{
    return isBalancedRec(root) != -1;
}
int main()
{
    return 0;
}