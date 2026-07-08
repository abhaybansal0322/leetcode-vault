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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
            
        vector<int> res;

        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty())
        {
            TreeNode* toAdd = Q.front();
            res.push_back(toAdd->val);
            int N = Q.size();
            while(N--)
            {
                TreeNode* curr = Q.front();
                Q.pop();

                if(curr->right) Q.push(curr->right);

                if(curr->left)  Q.push(curr->left);
            }
        }

        return res;
    }
};