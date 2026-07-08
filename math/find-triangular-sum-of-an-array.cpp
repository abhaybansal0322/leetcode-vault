class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        int n = nums.size();
        int count = n-1;
        while(count--)
        {
            for(int i=0;i<=count;i++)
            {
                nums[i]=(nums[i]+nums[i+1])%10;
            }
        }

        return nums[0];
        
    }
};