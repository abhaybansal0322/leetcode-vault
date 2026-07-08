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
      int diff = INT_MAX;
    int num  = -1;

    void solve(TreeNode* root)
    {
        if(!root)
            return;

        solve(root->left);
        if(num!=-1)
        {
            diff = min(diff,abs(root->val-num));
        }
        num = root->val;
        solve(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        solve(root);
        return diff; 
    }
};