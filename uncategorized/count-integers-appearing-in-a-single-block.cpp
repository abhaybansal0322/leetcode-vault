class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_set<int> st, res;
        int n = nums.size();

        for(int i=0;i<n;i++) {
            if(i == 0 || nums[i]!=nums[i-1]) {
                if(st.find(nums[i])!=st.end()) {
                    res.erase(nums[i]);
                } else {
                    st.insert(nums[i]);
                    res.insert(nums[i]);
                }
            }
        }

        return (int)res.size();
    }
};