class Solution {

    typedef long long ll;
public:
    long long minArraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<ll> dp(n+1,0);
        vector<ll> best(k,LLONG_MIN);   best[0] = 0;

        vector<ll> prefix(n);   

        for(int i=0;i<n;i++) {

            prefix[i] += nums[i];

            if(i)   prefix[i] += prefix[i-1] , dp[i] = dp[i-1];

            int x = prefix[i]%k;

            if(best[x] != LLONG_MIN) {

                dp[i] = max(dp[i] , prefix[i] + best[x]);
            }

            best[x] = max(best[x] , dp[i]-prefix[i]);

        }

        ll tot = 0;
        for(auto& num : nums) {

            tot += num;
        }

        return tot-dp[n-1];
        
    }
};