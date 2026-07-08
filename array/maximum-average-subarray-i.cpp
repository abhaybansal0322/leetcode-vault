class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<int> dp(nums.size()+1,INT_MIN);
        int sum=0;
        for(int i=0;i<k;i++)
        {
            sum += nums[i];
        }  
        dp[0]=sum;
        int l=0;
        int r=k;

        while(r < nums.size())
        {
            dp[l+1]=dp[l]+nums[r]-nums[l];
            l++;
            r++;
        }

        return (double)*max_element(begin(dp),end(dp))/k;
        
    }
};