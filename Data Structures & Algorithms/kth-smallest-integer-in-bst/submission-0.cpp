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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, ans = -1;
        recur(root, k, cnt, ans);
        return ans;
    }
    void recur(TreeNode* root, int k, int& cnt, int& ans) {
        if (root->left) {
            recur(root->left, k, cnt, ans);
        }
        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }
        if (root->right) {
            recur(root->right, k, cnt, ans);
        }
    }

};
