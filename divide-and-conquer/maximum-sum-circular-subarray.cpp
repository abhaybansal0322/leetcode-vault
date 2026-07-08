class Solution {

    
    int kadanesMin(vector<int>& nums) {

        int minSum = nums[0];
        int curr = nums[0];

        for(int i=1;i<nums.size();i++) {

            curr = min(nums[i],nums[i]+curr);
            minSum = min(minSum,curr); 
        }

        return minSum;
    }

    int kadanesMax(vector<int>& nums) {

        int maxSum = nums[0];
        int curr = nums[0];

        for(int i=1;i<nums.size();i++) {

            curr = max(nums[i],nums[i]+curr);
            maxSum = max(maxSum,curr); 
        }

        return maxSum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();
        
        int totalSum = accumulate(nums.begin(),nums.end(),0);

        int maxSum = kadanesMax(nums);
        int minSum = kadanesMin(nums);

        int circularSum = totalSum - minSum;

        if(maxSum > 0)  return max(maxSum,circularSum);

        return maxSum;
        
    }
};