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
        if (!root) return -1;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(true) {
            // left
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            // node
            cur = s.top(); s.pop();
            k--;
            if (k == 0) return cur->val;
            // right
            cur = cur->right;\
        }
        return -1;
    }

};
