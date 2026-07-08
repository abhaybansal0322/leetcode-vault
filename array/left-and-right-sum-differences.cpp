class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        if(nums.size() == 1) {return {0};}
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int prevSum = 0;
        vector<int> res(nums.size());

        for(int i=0;i<nums.size();i++) {

            int rightSum = totalSum - prevSum - nums[i];
            res[i] = abs(rightSum - prevSum);
            prevSum += nums[i];
        }

        return res;
    }
};