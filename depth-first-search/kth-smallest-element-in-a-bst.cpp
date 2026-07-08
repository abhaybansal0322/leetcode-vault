// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         priority_queue<int> pq;
//         queue<TreeNode*> Q;
//         Q.push(root);

//         while(!Q.empty())
//         {
//             int N = Q.size();
//             while(N--)
//             {
//                 TreeNode* curr = Q.front(); Q.pop();
//                 pq.push(curr->val);
//                 if(pq.size()>k)
//                 {
//                     pq.pop();
//                 }

//                 if(curr->left) Q.push(curr->left);
//                 if(curr->right) Q.push(curr->right);
//             }
//         }

//         return pq.top();
//     }
// };


// APPROACH 2--> TC,SC -> O(h+k)
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
    int count = 0;
    int res = -1;
    int K;

    void solve(TreeNode* root)
    {
        if(!root)
            return;

        solve(root->left);
        count++;
        if(count==K)
        {
            res = root->val;
            return;
        }
        solve(root->right);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        K = k;
        solve(root);
        return res;
    }
};