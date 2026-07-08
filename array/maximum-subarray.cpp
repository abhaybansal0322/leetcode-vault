class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSubSum = nums[0];
        int curr = nums[0];

        for(int i=1;i<nums.size();i++)
        {
            curr = max(nums[i],curr+nums[i]);
            maxSubSum = max(maxSubSum,curr);
        }

        return maxSubSum;
        
    }
};