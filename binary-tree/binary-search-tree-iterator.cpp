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

 //APPROACH 1 ------> TC->O(N)  SC->O(N)
// class BSTIterator {
//     list<int> List;

//     void traverse(TreeNode* root)
//     {
//         if(!root)
//             return;
        
//         traverse(root->left);
//         List.push_back(root->val);
//         traverse(root->right);
//     }
// public:
//     BSTIterator(TreeNode* root) {
//         traverse(root);
//     }
    
//     int next() {
//         int val = List.front();
//         List.pop_front();
//         return val;
//     }
    
//     bool hasNext() {
//         if(List.empty())
//             return false;
        
//         return true;
//     }
// };

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

//APPROACH 2 ----> TC->O(1) for next and hasnext  SC->O(h)
class BSTIterator {
    stack<TreeNode*> st;

    void pushLeft(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* curr= st.top();
        st.pop();
        pushLeft(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};