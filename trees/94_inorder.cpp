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

    // Helper function to perform inorder traversal recursively
    void inorder(TreeNode* root, vector<int>& ans)
    {
        if (root == NULL) return; // Base case: if current node is NULL, do nothing and return

        inorder(root->left, ans);        // Step 1: Traverse the left subtree
        ans.push_back(root->val);        // Step 2: Visit the root (add its value to the answer)
        inorder(root->right, ans);       // Step 3: Traverse the right subtree
    }

    // Main function to be called with just the root
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;        // Vector to store the inorder traversal result
        inorder(root, ans);     // Start the recursion
        return ans;             // Return the final inorder traversal result
    }
};
