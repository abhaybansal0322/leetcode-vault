class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        
        int n = nums.size();
        vector<long long> prefixSum(n);

        prefixSum[0] = nums[0];
        for(int i=1;i<n;i++)    prefixSum[i] += prefixSum[i-1]+nums[i];

        long long result = INT_MIN;
        long long minEl = nums[n-1];

        for(int i=n-2;i>=0;i--) {

            result = max(result,prefixSum[i]-minEl);
            minEl = min(minEl,(long long)nums[i]);
        }
        return result;
    }
};