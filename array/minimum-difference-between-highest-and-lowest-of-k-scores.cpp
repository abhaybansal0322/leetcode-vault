class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        if(k == 1) return 0;

        int n = nums.size();
        

        sort(nums.begin(),nums.end());

        int i = 0;
        int j = k-1;

        int ans = INT_MAX;

        while(j<n) {

            ans = min(ans,nums[j]-nums[i]);
            i++;
            j++;
        }

        return ans;
    }
};