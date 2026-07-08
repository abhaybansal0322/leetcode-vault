class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();      
        vector<long long> res(n,0);
        unordered_map<int,long long> count,sum;

        for(int i=0;i<n;i++) {
            int val = nums[i];

            res[i] += count[val]*i - sum[val];
            sum[val] += i;
            count[val]++;
        }

        sum.clear();
        count.clear();

        for(int i=n-1;i>=0;i--) {
            int val = nums[i];

            res[i] += sum[val] - count[val]*i;
            sum[val] += i;
            count[val]++;
        }

        return res;
    }
};