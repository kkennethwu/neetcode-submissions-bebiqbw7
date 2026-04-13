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
    bool isValidBST(TreeNode* root) {
        return isValid(root, -1001, 1001);
    }

    bool isValid(TreeNode* root, int lower, int upper) {
        bool flgLeft = true;
        if (root->left) {
            flgLeft = flgLeft && (root->left->val > lower) && (root->left->val < root->val) && isValid(root->left, lower, root->val);
        }
        bool flgRight = true;
        if (root->right) {
            flgRight = flgRight && (root->right->val < upper) && (root->right->val > root->val) && isValid(root->right, root->val, upper);
        }
        return flgLeft && flgRight;
    } 
};
