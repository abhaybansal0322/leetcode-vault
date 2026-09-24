class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        long long pulse = 0;
        vector<long long> b(n,0);

        for(int i=0;i<n;i++) {
            b[i] = (i%2 == 0) ? (long long)nums[i] : -(long long)nums[i];
            pulse += b[i];
        }

        vector<long long> best(n,0);
        long long minBlock = 0;

        for(int i=1;i<n;i++) {
            long long currPair = b[i-1]+b[i];
            long long before = (i-2>=0) ? best[i-2] : 0LL;

            best[i] = currPair + min(0LL,before);
            minBlock = min(minBlock,best[i]);
        }

        return pulse - 2*minBlock;
    }
};