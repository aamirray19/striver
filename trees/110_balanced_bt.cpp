#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Definition for a binary tree node.
    struct TreeNode {
        int val;                // Value of the node
        TreeNode *left;         // Pointer to the left child
        TreeNode *right;        // Pointer to the right child
        TreeNode(int x) : val(x), left(NULL), right(NULL) {} // Constructor to initialize node
    };
    // Helper function that returns the height of the subtree
    // If it detects an imbalance, it returns -1 immediately
    int height(TreeNode* root)
    {
        if (root == NULL) return 0;  // Base case: height of empty subtree is 0

        int lh = height(root->left); // Recursively get height of left subtree
        if (lh == -1) return -1;     // If left subtree is unbalanced, propagate -1

        int rh = height(root->right); // Recursively get height of right subtree
        if (rh == -1) return -1;      // If right subtree is unbalanced, propagate -1

        // If difference in heights is more than 1, the tree is unbalanced
        if (abs(lh - rh) > 1) return -1;

        // Return height of current subtree
        return max(lh, rh) + 1;
    }

    // Main function to check if the tree is balanced
    bool isBalanced(TreeNode* root) 
    {
        // If height returns -1, tree is unbalanced
        return height(root) != -1;
    }
};