#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Preorder Traversal: Root → Left → Right
void preorder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void preorderIterative(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *node = st.top();
        st.pop();
        cout << node->data << " ";

        if (node->right)
        {
            st.push(node->right);
        }
        if (node->left)
        {
            st.push(node->left);
        }
    }
}