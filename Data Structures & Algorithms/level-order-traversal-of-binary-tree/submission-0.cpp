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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> Q;
        int cur_level = 0;
        Q.push({root, cur_level});
        ans.emplace_back(vector<int>());
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            if (cur.second == cur_level) {
                ans[cur_level].emplace_back(cur.first->val);
            } else if (cur.second > cur_level) {
                cur_level++;
                ans.emplace_back(vector<int>());
                ans[cur_level].emplace_back(cur.first->val);
            }
            if (cur.first->left != nullptr) Q.push({cur.first->left, cur.second+1});
            if (cur.first->right != nullptr) Q.push({cur.first->right, cur.second+1});
        }
        return ans;
    }
};
