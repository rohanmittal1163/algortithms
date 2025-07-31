#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node()
    {
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int MaximumPathSum(Node *root)
    {
        int sum = INT_MIN;
        h(root, sum);
        return sum;
    }

    int h(Node *root, int &sum)
    {
        if (!root)
            return 0;
        int l = h(root->left, sum);
        int r = h(root->right, sum);
        sum = max(sum, l + r + root->data);
        return root->data + max(l, r);
    }
};
int main()
{
    return 0;
}