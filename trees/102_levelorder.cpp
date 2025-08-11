#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {   
    int val;                // Value of the node
    TreeNode *left;         // Pointer to the left child
    TreeNode *right;        // Pointer to the right child
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // Constructor to initialize node
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;

        // If the tree is empty, return empty result
        if (root == NULL) return ans;

        // Use a queue to perform BFS level by level
        queue<TreeNode*> q;
        q.push(root); // ✅ Push root to start the traversal

        // Continue while there are nodes to process
        while (!q.empty())
        {
            int size = q.size();         // Number of nodes at current level
            vector<int> level;           // Store values for this level

            for (int i = 0; i < size; i++)
            {
                TreeNode* node = q.front(); // Get front node
                q.pop();                    // Remove it from the queue

                // Add child nodes for next level
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);

                // Add current node's value to level vector
                level.push_back(node->val);
            }

            // After processing one level, add it to the result
            ans.push_back(level);
        }

        return ans; // Final answer contains all levels
    }
};
