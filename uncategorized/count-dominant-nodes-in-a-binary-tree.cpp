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
    int helper(TreeNode* root) {

        if(!root) return INT_MIN;
        if(!root->left && !root->right) {
            ans++;
            return root->val;
        }
        
        int l = helper(root->left);
        int r = helper(root->right);

        if((root->val >= l) && (root->val >= r)) {
            ans++;
        }

        return max({root->val,l,r});
    }
public:
    int countDominantNodes(TreeNode* root) {
        helper(root);
        return ans;
    }
};