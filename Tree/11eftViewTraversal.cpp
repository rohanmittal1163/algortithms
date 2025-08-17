#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

// MORRIS TRAVERSAL
vector<int> leftView(Node *root)
{

    // To store the right view nodes
    vector<int> res;

    // Current level of traversal
    int level = 0;

    // Traverse the tree using modified Morris Traversal
    while (root)
    {

        // If the node has a right child,
        // find the inorder predecessor
        if (root->left)
        {
            Node *pred = root->left;
            int backDepth = 1;

            // Find the leftmost node in the right subtree
            while (pred->right != nullptr &&
                   pred->right != root)
            {
                pred = pred->right;
                backDepth++;
            }

            // If threading is not yet established
            if (pred->right == nullptr)
            {

                // Add the current node to the view if
                // visiting the level for the first time
                if (res.size() == level)
                {
                    res.push_back(root->data);
                }

                // Establish the thread and move
                // to the right subtree
                pred->right = root;
                root = root->left;
                level++;
            }
            else
            {

                // Threading was already done
                //(second visit) remove the thread and
                // go to the left subtree
                pred->right = nullptr;
                root = root->right;
                level -= backDepth;
            }
        }
        else
        {

            // If no right child, process the current
            // node and move to the left child
            if (res.size() == level)
            {
                res.push_back(root->data);
            }

            root = root->right;
            level++;
        }
    }

    // Return the right view nodes
    return res;
}