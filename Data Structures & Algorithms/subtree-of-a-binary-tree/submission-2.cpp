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
    
    void OLR(TreeNode* root, string& tree) {
        if (root == nullptr) {
            tree += "@,";
            return;
        }
        tree += (std::to_string(root->val) + ",");
        OLR(root->left, tree);
        OLR(root->right, tree);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string tree, subtree;
        OLR(root, tree);
        OLR(subRoot, subtree);

        if (tree.size() < subtree.size()) return false;
        return tree.find(subtree) != std::string::npos;
    }
};
