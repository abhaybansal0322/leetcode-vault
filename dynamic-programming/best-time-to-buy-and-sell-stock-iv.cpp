// // TOP DOWN APPROACH
// class Solution {
//     int n;

//     int solve(int idx,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>> &dp) {

//         if(cap == 0)    return 0;

//         if(idx == n)    return 0;

//         if(dp[idx][buy][cap]!=-1)   return dp[idx][buy][cap];

//         int profit;

//         if(buy) {

//             int buyCase = -prices[idx] + solve(idx+1,0,cap,prices,dp);
//             int skipCase = solve(idx+1,1,cap,prices,dp);

//             profit = max(buyCase,skipCase);
//         }

//         else {

//             int sellCase = prices[idx] + solve(idx+1,1,cap-1,prices,dp);
//             int skipCase = solve(idx+1,0,cap,prices,dp);

//             profit = max(sellCase,skipCase);
//         }

//         return dp[idx][buy][cap] = profit;
        
//     }
// public:
//     int maxProfit(int k,vector<int>& prices) {

//         n = prices.size();
//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));

//         return solve(0,1,k,prices,dp);

//     }
// };

//TABULATION
class Solution {

public:
    int maxProfit(int k,vector<int>& prices) {

        int n = prices.size();
        

        vector<vector<int>> after(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));

        for(int idx=n-1;idx>=0;idx--) {

            for(int buy=0;buy<=1;buy++) {

                for(int cap=1;cap<=k;cap++) {

                    int profit;

                    if(buy) {

                        int buyCase = -prices[idx] + after[0][cap];
                        int skipCase = after[1][cap];

                        profit = max(buyCase,skipCase);
                    }

                    else {

                        int sellCase = prices[idx] + after[1][cap-1];
                        int skipCase = after[0][cap];

                        profit = max(sellCase,skipCase);
                    }

                    curr[buy][cap] = profit;

                }
            }
            after = curr;
        }

        return after[1][k];

    }
};