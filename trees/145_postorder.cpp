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

    // Recursive helper function for postorder traversal
    void postorder(TreeNode* root, vector<int>& ans)
    {
        // Base case: If the node is NULL, there's nothing to do
        if (root == NULL) return;

        // Step 1: Traverse the left subtree
        postorder(root->left, ans);

        // Step 2: Traverse the right subtree
        postorder(root->right, ans);

        // Step 3: Visit the root node (after both subtrees)
        ans.push_back(root->val);
    }

    // Main function to be called externally
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;           // Vector to store traversal result
        postorder(root, ans);      // Call the recursive helper
        return ans;                // Return final postorder result
    }
};
