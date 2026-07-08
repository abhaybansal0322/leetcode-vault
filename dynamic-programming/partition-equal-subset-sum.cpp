// class Solution {
//     int totalSum;

//     bool solve(vector<int>& nums,int curr,int i,vector<vector<int>>& dp) {

//         if(curr == 0)  return true;

//         if(i == nums.size())    return false;

//         if(dp[i][curr] != -1)   return dp[i][curr];

//         if(nums[i] <= curr) {

//             return dp[i][curr] = solve(nums,curr-nums[i],i+1,dp) || solve(nums,curr,i+1,dp);
//         }

//         return dp[i][curr] = solve(nums,curr,i+1,dp);
//     }
// public:
//     bool canPartition(vector<int>& nums) {
        
//         int n = nums.size();
//         totalSum = accumulate(nums.begin(),nums.end(),0);

//         if(totalSum % 2 == 1)   return false;
//         int currSum = totalSum/2;

//         vector<vector<int>> dp(n+1,vector<int>(currSum+1,-1));

//         return solve(nums,currSum,0,dp);

//     }
// };

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Initialization
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true; // sum 0 is always possible
        }

        // Build the table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }
};
