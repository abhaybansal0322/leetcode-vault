class Solution {
public:
    // int dp[2501][2501];

    // int helper(vector<int>& nums,int curr,int prev){
    //     if(curr>=nums.size())
    //     return 0;

    //     if(prev!=-1 && dp[curr][prev] !=-1 )
    //     return dp[curr][prev];

    //     int take=0;
    //     if(prev==-1 || nums[curr]>nums[prev] ){
    //         take=1+helper(nums,curr+1,curr);
    //     }
    //     int skip=helper(nums,curr+1,prev);

    //     if(prev!=-1)
    //     dp[curr][prev]=max(take,skip);

    //     return max(take,skip);
        
    // }
    
    // int lengthOfLIS(vector<int>& nums) {
    //     memset(dp,-1,sizeof(dp));
    //     return helper(nums,0,-1);
        
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n, 1);
    //     for (int i = 0; i < n; ++i)
    //         for (int j = 0; j < i; ++j)
    //             if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
    //                 dp[i] = dp[j] + 1;
    //     return *max_element(dp.begin(), dp.end());
    // }

      int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int result = INT_MIN;
        vector<int> LIS(n,1);

        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i] > nums[j])
                {
                    LIS[i] = max(LIS[i],LIS[j]+1);
                }
            }
            result = max(result,LIS[i]);
        }

        return result;
    }
};