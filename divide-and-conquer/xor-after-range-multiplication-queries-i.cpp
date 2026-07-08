class Solution {
    int MOD = 1e9 +7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        for(auto& Q : queries) {

            int idx = Q[0];
            while(idx <= Q[1]) {

                nums[idx] = (1LL*nums[idx]*Q[3])%MOD;
                idx += Q[2];
            }
        }
        int res = 0;
        for(auto& num : nums) {

            res = res^num;
        }

        return res;
    }
};