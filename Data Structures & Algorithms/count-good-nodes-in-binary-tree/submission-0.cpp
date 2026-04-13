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
    int goodNodes(TreeNode* root) {
        return recur(root, root->val);
    }

    int recur(TreeNode* cur, int max_val) {
        int with_good_node = 0;
        if (cur->val >= max_val) {
            max_val = cur->val;
            with_good_node++;
        }
        if (cur->left) with_good_node += recur(cur->left, max_val);
        if (cur->right) with_good_node += recur(cur->right, max_val);
        return with_good_node;
    }
};
