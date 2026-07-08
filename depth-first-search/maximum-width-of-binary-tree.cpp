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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root)   return 0;
        queue<pair<TreeNode*,long long>> Q;

        Q.push({root,0});
        long long res = INT_MIN;

        while(!Q.empty()) {

            int N = Q.size();
            long long l,r;
            long long minIdx = Q.front().second;

            for(int i=0;i<N;i++) {

                TreeNode* node = Q.front().first;
                long long idx = Q.front().second - minIdx; //IMP to normalise
                Q.pop();

                if(i == 0)  l = idx;

                if(i == N-1)    r = idx;

                if(node->left)  Q.push({node->left,2*idx+1});

                if(node->right) Q.push({node->right,2*idx+2});
            }

            res = max(res,r-l+1);
        }

        return (int)res;
    }
};