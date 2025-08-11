#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// Definition for a binary tree node.
struct TreeNode {   
    int val;                // Value of the node
    TreeNode *left;         // Pointer to the left child
    TreeNode *right;        // Pointer to the right child
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // Constructor
};

    int maxDepth(TreeNode* root) 
    {
        if (root == NULL) return 0;

        int lh = maxDepth(root -> left);
        int rh = maxDepth(root -> right);

        return 1 + max(lh, rh);
    }
};