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
    unordered_map<int,int> mp;
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int instart,int inend,int poststart,int postend) {
        if(instart > inend || poststart > postend)
            return NULL;
        
        int rootVal = postorder[postend];
        
        TreeNode* root = new TreeNode(rootVal);

        int i = mp[rootVal];
        int leftSize = i-instart;
        int rightSize = inend-i;

        root->left = solve(inorder,postorder,instart,i-1,poststart,poststart+leftSize-1);
        root->right = solve(inorder,postorder,i+1,inend,postend-rightSize,postend-1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;

    
        return solve(inorder,postorder,0,n-1,0,n-1);
        

    }
};