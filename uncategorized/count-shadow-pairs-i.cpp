class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> st;
        vector<int> cntEq(n,0);
        long long ans = 0;

        for(int i=n-1;i>=0;i--) {
            int eq = -1;

            while(!st.empty() && nums[st.back()] >= nums[i]) {
                if(nums[i] == nums[st.back()]) eq = st.back();
                st.pop_back();
            }

            int r = st.empty() ? n : st.back();
            cntEq[i] = (eq == -1) ? 0 : 1 + cntEq[eq];
            ans += (r-i-1)-cntEq[i];

            st.push_back(i);
        }

        return ans;
    }
};