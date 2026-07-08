// //Approach-1  (Using Parent Pointers)
// class Solution {
// public:
//     unordered_map<TreeNode*, TreeNode*> parent;
//     void addParent(TreeNode* root) {
//         if(!root)
//             return;
        
//         if(root->left)
//             parent[root->left] = root;
        
//         addParent(root->left);
        
//         if(root->right)
//             parent[root->right] = root;
        
//         addParent(root->right);
//     }
    
//     void collectKDistanceNodes(TreeNode* target, int k, vector<int>& result) {
        
//         queue<TreeNode*> que;
//         que.push(target);
//         unordered_set<int> visited;
//         visited.insert(target->val);
        
//         while(!que.empty()) {
            
//             int n = que.size();
//             if(k == 0)
//                 break;
            
//             while(n--) {
//                 TreeNode* curr = que.front();
//                 que.pop();
                
//                 if(curr->left && !visited.count(curr->left->val)) {
//                     que.push(curr->left);
//                     visited.insert(curr->left->val);
//                 }
//                 if(curr->right && !visited.count(curr->right->val)) {
//                     que.push(curr->right);
//                     visited.insert(curr->right->val);
//                 }
                
//                 if(parent.count(curr) && !visited.count(parent[curr]->val)) {
//                     que.push(parent[curr]);
//                     visited.insert(parent[curr]->val);
//                 }
//             }
//             k--;
//         }
        
//         while(!que.empty()) {
//             TreeNode* temp = que.front();
//             que.pop();
//             result.push_back(temp->val);
//         }
//     }
    
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         vector<int> result;
        
//         addParent(root);
        
//         collectKDistanceNodes(target, k, result);
//         return result;
//     }
// };

class Solution {
public:
    vector<int> result;

    // Function to collect all nodes at distance d below this node
    void collectDown(TreeNode* root, int d) {
        if (!root || d < 0)
            return;
        if (d == 0) {
            result.push_back(root->val);
            return;
        }
        collectDown(root->left, d - 1);
        collectDown(root->right, d - 1);
    }

    // DFS: returns distance of current node from target if found, else -1
    int dfs(TreeNode* root, TreeNode* target, int k) {
        if (!root)
            return -1;

        if (root == target) {
            // Collect all nodes k distance below the target
            collectDown(root, k);
            return 0;
        }

        // Search left subtree
        int leftDist = dfs(root->left, target, k);
        if (leftDist != -1) {
            // Target found in left subtree
            if (leftDist + 1 == k)
                result.push_back(root->val);  // current node is k away
            else
                collectDown(root->right, k - leftDist - 2);
            return leftDist + 1;
        }

        // Search right subtree
        int rightDist = dfs(root->right, target, k);
        if (rightDist != -1) {
            // Target found in right subtree
            if (rightDist + 1 == k)
                result.push_back(root->val);
            else
                collectDown(root->left, k - rightDist - 2);
            return rightDist + 1;
        }

        // Target not found in this subtree
        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, target, k);
        return result;
    }
};
