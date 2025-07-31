#include <bits/stdc++.h>
using namespace std;

// Define a Node structure
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

// Postorder Traversal: Left → Right → Root
void postorder(Node *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void postorderIterative(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<Node *> st;
    st.push(root);
    vector<int> vec;
    while (!st.empty())
    {
        Node *node = st.top();
        st.pop();
        vec.push_back(node->data);

        if (node->left)
        {
            st.push(node->left);
        }
        if (node->right)
        {
            st.push(node->right);
        }
    }
    reverse(vec.begin(), vec.end());
}

void preInPostOrderTraversal(Node *root)
{
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    if (root == nullptr)
        return;
    while (st.empty() == false)
    {
        auto rem = st.top();
        st.pop();
        Node *node = rem.first;
        int num = rem.second;
        if (num == 1)
        {
            pre.push_back(node->data);
            st.push({node, num + 1});
            if (node->left)
            {
                st.push({node->left, 1});
            }
        }
        else if (num == 2)
        {
            in.push_back(node->data);
            st.push({node, num + 1});
            if (node->right)
            {
                st.push({node->right, 1});
            }
        }
        else
        {
            post.push_back(node->data);
        }
    }
}
