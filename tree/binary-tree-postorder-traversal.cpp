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

    void helper(TreeNode* root,vector<int>& result)
    {
        if(root!=NULL)
        {
            helper(root->left,result);
            helper(root->right,result);
            result.push_back(root->val);
        }
        

    }
    

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL)
        {
            return result;
        }
        // helper(root,result);
        // return result;

        stack<TreeNode*> s1,s2;
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode *newNode=s1.top();
            s1.pop();
            s2.push(newNode);

            if(newNode->left)
            {
                s1.push(newNode->left);
            }
            if(newNode->right)
            {
                s1.push(newNode->right);
            }
        }

        while(!s2.empty())
        {
            result.push_back(s2.top()->val);
            s2.pop();
        }

        return result;
    }
};