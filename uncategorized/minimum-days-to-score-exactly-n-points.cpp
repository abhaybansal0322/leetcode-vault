class Solution {
    vector<int> dp;
    int solve(int rem) {
        if(rem == 0) return 0;
        if(dp[rem]!=-1) return dp[rem];
        int res = INT_MAX;
        for(int l=1; ((long long)l*(l+1)/2) <= rem;l++) {
            res = min(res,l+1+solve(rem - (l*(l+1)/2)));
        }
        return dp[rem] = res;
    }
public:
    int minDays(int n) {
        dp.assign(n+1,-1);
        return solve(n)-1;
    }
};