class Solution {
public:
    long long minOperations(vector<int>& nums) {
        
        int n = nums.size();
        long long currVal = 0;
        vector<long long> temp(nums.begin(),nums.end());
        long long currMax = temp[0];

        long long ans = 0;
        for(int i=1;i<n;i++) {
            
            temp[i] += currVal;
            if(temp[i]>=currMax) {
                currMax = temp[i];
                continue;
            }

            long long diff = currMax - temp[i];
            currVal += diff;
            temp[i] += diff;
        }

        return currVal;
    }
};