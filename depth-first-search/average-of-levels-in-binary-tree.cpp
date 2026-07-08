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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty())
        {
            int N = Q.size();
            int Size = N;
            double currSum = 0;
            while(N--)
            {
               TreeNode* curr = Q.front(); Q.pop();

               currSum += curr->val;

               if(curr->left) Q.push(curr->left);
               if(curr->right) Q.push(curr->right);
            }

            res.push_back(currSum/Size);
        }

        return res;
    }
};