class Solution {
public:

    int helper(vector<int>& nums,int i,int n,vector<int>& dp)
    {
        if(i>=n)
        {
            return 0;
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int include = nums[i]+helper(nums,i+2,n,dp);
        int exclude = helper(nums,i+1,n,dp);

        return dp[i] = max(include,exclude);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);

        return max(helper(nums,0,n-1,dp1),helper(nums,1,n,dp2));
        
    }
};