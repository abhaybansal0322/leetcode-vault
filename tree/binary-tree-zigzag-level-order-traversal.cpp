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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};

        vector<vector<int>> res;
        queue<TreeNode*> Q;
        Q.push(root);
        bool flag = false;

        while(!Q.empty())
        {
            int N = Q.size();
            deque<int> D;

            while(N--)
            {
                TreeNode* curr = Q.front(); Q.pop();

                if(flag)
                {
                    D.push_front(curr->val);
                }
                else{
                    D.push_back(curr->val);
                }

                if(curr->left) Q.push(curr->left);
                if(curr->right)Q.push(curr->right);
            }

            vector<int> toAdd;
            toAdd.insert(toAdd.end(),D.begin(),D.end());
            res.push_back(toAdd);
            flag = !flag;
        }

        return res;
    }
};