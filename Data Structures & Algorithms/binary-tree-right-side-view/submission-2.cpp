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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<int> res;
        if (root == nullptr) return res;
        Q.push(root);
        while (!Q.empty()) {
            TreeNode* cur = nullptr;
            for (int i = Q.size(); i > 0; i--) {
                cur = Q.front(); Q.pop();
                if (cur->left) Q.push(cur->left);
                if (cur->right) Q.push(cur->right);
            }
            res.emplace_back(cur->val);
        }
        return res;
    }
};
