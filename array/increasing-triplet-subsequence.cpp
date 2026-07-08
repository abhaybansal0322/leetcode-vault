class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> dp(n,1);
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<i;j++)
        //     {
        //         if(nums[i] > nums[j] && dp[i] < dp[j]+1)
        //         {
        //             dp[i]=dp[j]+1;
        //             if(dp[i]>=3)
        //             {
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return false;

        int first=INT_MAX;
        int second=INT_MAX;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] <=first)
            {
                first=nums[i];
            }
            else if(nums[i] <=second)
            {
                second=nums[i];
            }
            else{
                return true;
            }
        }

        return false;


         
    }
};