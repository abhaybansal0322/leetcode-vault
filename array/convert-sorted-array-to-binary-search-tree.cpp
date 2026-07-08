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
    TreeNode* helper(vector<int>& nums,int l,int r) {

        if(l > r) return NULL;

        int mid = l+(r-l)/2;
        TreeNode* Node = new TreeNode(nums[mid]);

        Node->left = helper(nums,l,mid-1);
        Node->right = helper(nums,mid+1,r);

        return Node;

    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};