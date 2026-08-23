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
    int helper(TreeNode* root) {
        if(!root->left && !root->right) return 1;

        int l = INT_MAX;
        int r = INT_MAX;

        if(root->left) l = helper(root->left);
        if(root->right) r = helper(root->right);

        return 1 + min(l,r);
    }
public:
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        return helper(root);
    }
};