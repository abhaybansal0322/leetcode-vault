class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0;
        int sum=0;
        int minLen=INT_MAX;;
        while(r<nums.size())
        {
           sum=sum+nums[r];
           if(sum >= target)
           {
            while(sum >= target)
            {
                sum=sum-nums[l];
                minLen=min(minLen,r-l+1);
                l++;
            }
           }
           r++;
        }
        if(minLen==INT_MAX)
        return 0;
        return minLen;

    }
};