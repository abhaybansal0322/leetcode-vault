class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int n = nums.size();
        int seq = nums[0];

        for(int j=1;j<n;j++) {
            if(nums[j] == nums[j-1]+1) {
                seq += nums[j];
            } else break;
        }

        while(st.count(seq)) {
            seq++;
        }

        return seq;
    }
};