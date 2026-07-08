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
    vector<TreeNode*> ans;
    unordered_set<int> toDeleteSet;

    TreeNode* deleteNodes(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        // pahale niche jaate jao ;
        // (if cnd) agar upar likh di toh parent delete
        // krne ke baad child ko access nhi kar paaenge
        root->left = deleteNodes(root->left);
        root->right = deleteNodes(root->right);

        if (toDeleteSet.find(root->val) != toDeleteSet.end()) {
            if (root->left)
                ans.push_back(root->left);
            if (root->right)
                ans.push_back(root->right);
            delete root;
            return NULL;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == nullptr)
            return {};

        for (int val : to_delete) {
            toDeleteSet.insert(val);
        }

        root = deleteNodes(root);
        if (root) {
            ans.push_back(root);
        }

        return ans;
    }
};