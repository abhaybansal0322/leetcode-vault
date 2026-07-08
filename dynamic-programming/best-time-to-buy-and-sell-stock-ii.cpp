// TOP DOWN APPROACH
/*class Solution {
    int solve(int idx,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(idx == prices.size())
            return 0;

        if(dp[idx][buy]!=-1)
            return dp[idx][buy];
        
        int profit;
        
        if(buy)
        {
            int buyKro = -prices[idx] + solve(idx+1,0,prices,dp);
            int skipkro = solve(idx+1,1,prices,dp);
            profit = max(buyKro,skipkro);
        }
        else{
            int sellkro = prices[idx] + solve(idx+1,1,prices,dp);
            int skipkro = solve(idx+1,0,prices,dp);
            profit = max(sellkro,skipkro);
        }

        return dp[idx][buy]=profit;
        
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));

        return solve(0,1,prices,dp); 
    }
};*/


class Solution {
    int solve(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int idx = n-1;idx >=0;--idx)
        {
            for(int buy =0;buy<=1;++buy)
            {
                int profit;
                if(buy)
                {
                    int buyKro = -prices[idx] + dp[idx+1][0];
                    int skipkro = dp[idx+1][1];
                    profit = max(buyKro,skipkro);
                }
                else{
                    int sellkro = prices[idx] + dp[idx+1][1];
                    int skipkro = dp[idx+1][0];
                    profit = max(sellkro,skipkro);
                }

                dp[idx][buy]=profit;
            }
        }

        return dp[0][1];
    }
public:
    int maxProfit(vector<int>& prices) {

        return solve(prices);
        
    }
};