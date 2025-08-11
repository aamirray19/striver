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

    int height(TreeNode* root, int& diameter)
    {
        if (root == NULL) return 0;

        int lh = height(root -> left, diameter);
        int rh = height(root -> right, diameter);

        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};