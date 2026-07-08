class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        
        long long sum = 0;
        int i = 0;
        while(i<nums.size()) {
            sum += nums[i];
            if(nums[i]>nums[i+1]) break;
            i++;
        }

        while(i<nums.size()) {
            sum -= nums[i];
            i++;
        }

        if(sum == 0) return -1;

        return(sum > 0) ? 0 : 1;
    }
};