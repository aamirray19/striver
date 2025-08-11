#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    // Recursive helper function for preorder traversal
    void preorder(TreeNode* root, vector<int>& ans)
    {
        // Base case: if the current node is null, return immediately
        if (root == NULL) return;

        // Step 1: Visit the root node
        ans.push_back(root->val);

        // Step 2: Recurse on the left subtree
        preorder(root->left, ans);

        // Step 3: Recurse on the right subtree
        preorder(root->right, ans);
    }

    // Main function to start the preorder traversal
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;            // Create a vector to store the result
        preorder(root, ans);        // Call the recursive helper function
        return ans;                 // Return the final result
    }
};
