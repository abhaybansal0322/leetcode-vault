class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0;
        int r=0;
        int max_count=INT_MIN;
        while(r<nums.size())
        {
            if(nums[r]==0)
            {
                l=r+1;
            }
            max_count=max(max_count,r-l+1);
            r++;
        }
        return max_count;

        
    }
};