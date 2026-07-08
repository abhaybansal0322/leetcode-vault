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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        if(!root) return {};

        vector<vector<int>> res;

        map<int,map<int,multiset<int>>> mp;

        queue<pair<TreeNode*,pair<int,int>>> Q;
        Q.push({root,{0,0}});

        while(!Q.empty()) {

            auto curr = Q.front(); Q.pop();
            TreeNode* node = curr.first;
            int vd = curr.second.first;
            int hd = curr.second.second;

            mp[hd][vd].insert(node->val);

            if(node->left)  Q.push({node->left,{vd+1,hd-1}});
            if(node->right)  Q.push({node->right,{vd+1,hd+1}});
        }

        for(auto& m : mp) {

            vector<int> col;

            for(auto& g : m.second) {

                col.insert(col.end(),g.second.begin(),g.second.end());
            }

            res.push_back(col);
        }

        return res;
    }
};