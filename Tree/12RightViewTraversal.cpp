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
vector<int> rightView(Node *root)
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
        if (root->right)
        {
            Node *pred = root->right;
            int backDepth = 1;

            // Find the leftmost node in the right subtree
            while (pred->left != nullptr &&
                   pred->left != root)
            {
                pred = pred->left;
                backDepth++;
            }

            // If threading is not yet established
            if (pred->left == nullptr)
            {

                // Add the current node to the view if
                // visiting the level for the first time
                if (res.size() == level)
                {
                    res.push_back(root->data);
                }

                // Establish the thread and move
                // to the right subtree
                pred->left = root;
                root = root->right;
                level++;
            }
            else
            {

                // Threading was already done
                //(second visit) remove the thread and
                // go to the left subtree
                pred->left = nullptr;
                root = root->left;
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

            root = root->left;
            level++;
        }
    }

    // Return the right view nodes
    return res;
}