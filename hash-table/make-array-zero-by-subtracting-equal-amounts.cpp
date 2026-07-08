class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());

        int res = st.size();

        for (int i = 0; i < nums.size(); i++) {
            if (!nums[i]) {
                res--;
                break;
            }
        }

        return res;
    }
};