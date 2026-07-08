class Solution {
    int helper(int amount, vector<int>& coins,int i, vector<vector<int>>& dp) {
        if(amount == 0) return 1;
        if(i ==  coins.size()) return 0;

        if(dp[amount][i] != -1) return dp[amount][i];
        int notPick = helper(amount,coins,i+1,dp);
        int pick = 0;
        if(coins[i] <= amount) pick = helper(amount-coins[i],coins,i,dp);

        return dp[amount][i] = pick + notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(amount+1,vector<int>(coins.size(),-1));
        return helper(amount,coins,0,dp);
    }
};