class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        // unordered_set<int> st(nums.begin(),nums.end());
        vector<bool> N(100001,0);
        for(auto& num : nums) N[num] = true;
        vector<vector<int>> res;

        bool flag = false;
        for(int i = lower; i<= upper ; i++) {
            if(!N[i]) {
                if(!flag) {
                    res.push_back({i,i});
                    flag = true;
                } else {
                    res.back()[1] = i;
                }
            } else {
                flag = false;
            }
        }

        return res;
    }
};