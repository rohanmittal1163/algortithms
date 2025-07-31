#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    bool isLeaf(Node *root)
    {
        if (!root)
            return false;
        return !root->left && !root->right;
    }
    vector<int> addLeftBoundary(Node *root)
    {
        if (!root)
            return {};
        Node *node = root;
        vector<int> ans;
        while (!isLeaf(node))
        {
            ans.push_back(node->data);
            if (node->left)
                node = node->left;
            else
                node = node->right;
        }
        return ans;
    }

    // MORRIS TRAVERSAL FOR SPACE OPTIMIZATION
    vector<int> addLeaves(Node *root)
    {
        if (!root || !root->left && !root->right)
            return {};
        stack<Node *> st;
        st.push(root);
        vector<int> ans;

        while (st.empty() == false)
        {
            Node *node = st.top();
            st.pop();
            if (!node->left && !node->right)
                ans.push_back(node->data);
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        return ans;
    }

    vector<int> addRightBoundary(Node *root)
    {
        if (!root)
            return {};
        Node *node = root;
        vector<int> ans;
        while (!isLeaf(node))
        {
            ans.push_back(node->data);
            if (node->right)
                node = node->right;
            else
                node = node->left;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int> boundaryTraversal(Node *root)
    {
        if (!root)
            return {};

        vector<int> ans = {root->data};

        vector<int> l = addLeftBoundary(root->left);
        ans.insert(ans.end(), l.begin(), l.end());
        l = addLeaves(root);
        ans.insert(ans.end(), l.begin(), l.end());
        l = addRightBoundary(root->right);
        ans.insert(ans.end(), l.begin(), l.end());
        return ans;
    }
};