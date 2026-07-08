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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};

        vector<vector<int>> res;

        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty())
        {
            int N = Q.size();
            vector<int> toAdd;
            while(N--)
            {
               TreeNode* curr = Q.front(); Q.pop();

               toAdd.push_back(curr->val);

               if(curr->left) Q.push(curr->left);
               if(curr->right) Q.push(curr->right);
            }

            res.push_back(toAdd);
        }

        return res;
    }
};