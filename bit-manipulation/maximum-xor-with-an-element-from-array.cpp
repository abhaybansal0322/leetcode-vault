class Solution {

    struct trieNode {
        trieNode* left;
        trieNode* right;

        trieNode() {

            left = NULL;
            right = NULL;
        }
    };

    void insert(trieNode* root, int num) {

        trieNode* temp = root;
        for(int i=31;i>=0;i--) {

            int i_th_bit = (num>>i)&1;

            if(i_th_bit == 0) {

                if(temp->left == NULL) {
                    temp->left = new trieNode();
                }
                temp = temp->left;
            } else {
                
                if(temp->right == NULL) {
                    temp->right = new trieNode();
                }
                temp = temp->right;
            }
        }
    }

    int maxXOR(trieNode* root, int num) {

        trieNode* temp = root;
        int ans = 0;

        for(int i=31;i>=0;i--) {

            int ith_bit = (num>>i)&1;

            if(ith_bit == 0) {

                if(temp->right) {

                    ans |= (1 << i);
                    temp = temp->right;
                } else {

                    temp = temp->left;
                }
            } else {

                if(temp->left) {

                    ans |= (1 << i);
                    temp = temp->left;
                } else {

                    temp = temp->right;
                }
            }
        }

        return ans;
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        trieNode* root = new trieNode();
        vector<vector<int>> Q;

        for(int i=0;i<n;i++) {
            Q.push_back({queries[i][1],queries[i][0],i});
        }

        sort(Q.begin(),Q.end());
        sort(nums.begin(),nums.end());
        vector<int> res(n,-1);
        int idx = 0;

        for(auto& x : Q) {

            int m = x[0];
            int i = x[2];
            int num = x[1];

            while(idx < nums.size() && nums[idx]<=m) {
                insert(root,nums[idx]);
                idx++;
            }

            if (idx == 0) {
                res[i] = -1;
            } else {
                res[i] = maxXOR(root, num);
            }
        }

        return res;
    }
};