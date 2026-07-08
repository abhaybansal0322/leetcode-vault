/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int n = que.size();
            long long levelSum = 0;
            while (n--) {
                TreeNode* tempNode = que.front();
                que.pop();
                levelSum += tempNode->val;

                if (tempNode->left) {
                    que.push(tempNode->left);
                }

                if (tempNode->right) {
                    que.push(tempNode->right);
                }
            }

            pq.push(levelSum);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        if (pq.size() < k) {
            return -1;
        }
        return pq.top();
    }
};