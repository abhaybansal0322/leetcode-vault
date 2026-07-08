class Solution {
    int n;

    int solve(int idx,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>> &dp) {

        if(cap == 0)    return 0;

        if(idx == n)    return 0;

        if(dp[idx][buy][cap]!=-1)   return dp[idx][buy][cap];

        int profit;

        if(buy) {

            int buyCase = -prices[idx] + solve(idx+1,0,cap,prices,dp);
            int skipCase = solve(idx+1,1,cap,prices,dp);

            profit = max(buyCase,skipCase);
        }

        else {

            int sellCase = prices[idx] + solve(idx+1,1,cap-1,prices,dp);
            int skipCase = solve(idx+1,0,cap,prices,dp);

            profit = max(sellCase,skipCase);
        }

        return dp[idx][buy][cap] = profit;
        
    }
public:
    int maxProfit(vector<int>& prices) {

        n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

        return solve(0,1,2,prices,dp);

    }
};