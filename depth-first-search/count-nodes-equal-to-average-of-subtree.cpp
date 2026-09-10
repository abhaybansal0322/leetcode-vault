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
    typedef pair<int,int> P;
    int res;

    P solve(TreeNode* root) {
        if(!root)   return {0,0};

        P P1 = solve(root->left);
        P P2 = solve(root->right);

        int totSum = P1.first+P2.first+root->val;
        int totCnt = P1.second+P2.second+1;

        if(totSum/totCnt == root->val)  res++;

        return {totSum,totCnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        res = 0;
        solve(root);

        return res;
    }
};