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
    bool isBalanced(TreeNode* root) {
        bool flg = true;
        recur(root, flg);
        if (flg == false) return false;
        return true;
    }

    int recur(TreeNode* root, bool &flg) {
        if (root == nullptr) return 0;
        // if (flg == false) return -1;
        int left_height = recur(root->left, flg);
        int right_height = recur(root->right, flg);
        if (abs(left_height - right_height) > 1) flg = false;
        return max(left_height, right_height) + 1;
    }
};
