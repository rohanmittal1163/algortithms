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

// Preorder Traversal: Root → Left → Right
void preorder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal: Left → Root → Right
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal: Left → Right → Root
void postorder(Node *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void levelOrder(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
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

void inorderIterative(Node *root)
{
    stack<Node *> st;
    Node *curr = root;
    while (curr != nullptr || !st.empty())
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
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

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Preorder: ";
    preorder(root); // Output: 1 2 4 5 3 6 7
    cout << "\nInorder: ";
    inorder(root); // Output: 4 2 5 1 6 3 7
    cout << "\nPostorder: ";
    postorder(root); // Output: 4 5 2 6 7 3 1

    return 0;
}
