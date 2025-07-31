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
int isBalancedRec(Node *root)
{
    if (root == nullptr)
        return 0;
    int lheight = isBalanced(root->left);

    if (lheight == -1)
        return -1;

    int rheight = isBalanced(root->right);

    if (rheight == -1)
        return -1;

    if (abs(lheight - rheight) > 1)
        return -1;
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