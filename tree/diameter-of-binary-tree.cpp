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

    int ans = 0;
    int helper(TreeNode* root, int& ans) {

        if(!root)   return 0;

        int l = helper(root->left,ans);
        int r = helper(root->right,ans);

        ans = max(ans,l+r);

        return 1+max(l,r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int val = helper(root,ans);
        return ans;

    }
};