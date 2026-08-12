class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();

        unordered_map<int,int> freq;
        while(r<n) {
            freq[nums[r]]++;
            while(freq[nums[r]]>k) {
                freq[nums[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};