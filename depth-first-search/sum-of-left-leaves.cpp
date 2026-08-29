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

    int helper(TreeNode* root, bool isLeft) {
        if(!root->left && !root->right && isLeft)   return root->val;

        int l = 0;
        int r = 0;

        if(root->left)  l = helper(root->left,true);
        if(root->right) r = helper(root->right,false);

        return l+r;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root,false);
    }
};