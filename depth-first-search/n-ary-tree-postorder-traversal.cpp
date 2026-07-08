class Solution {
    void helper(Node* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }
        for (int i = 0; i < root->children.size(); i++) {
            helper(root->children[i], ans);
        }
        ans.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
         
    
    }
};