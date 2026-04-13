/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        recur(root, d);
        return d;
    }

    int recur(TreeNode* root, int &d) {
        if (!root) return 0;
        int left_height = recur(root->left, d);
        int right_height = recur(root->right, d);
        d = max(d, left_height + right_height);
        return max(left_height, right_height) + 1; 
    }
};
