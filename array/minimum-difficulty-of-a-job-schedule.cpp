class Solution {
public:
    int n;

    int helper(vector<int>& jobD, int idx, int d, vector<vector<int>>& dp) {
        if (d == 1) {
            int maxD = INT_MIN;
            for (int i = idx; i < n; i++) {
                maxD = max(maxD, jobD[i]);
            }
            return maxD;
        }

        if (dp[idx][d] != -1) {
            return dp[idx][d];
        }

        int maxD = jobD[idx];
        int finalResult = INT_MAX;

        for (int i = idx; i <= n - d; i++) {
            maxD = max(maxD, jobD[i]);
            int result = maxD + helper(jobD, i + 1, d - 1, dp);
            finalResult = min(finalResult, result);
        }
        return dp[idx][d] = finalResult;
    }

    int minDifficulty(vector<int>& jobD, int d) {
        n = jobD.size();
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, -1));

        if (n < d) {
            return -1;
        }

        return helper(jobD, 0, d, dp);
    }
};