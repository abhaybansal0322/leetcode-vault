class Solution {
public:
    int n, m; // rows,cols

    int helper(int i, int j, vector<vector<int>>& grid,
               vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = (j + 1 < m && grid[i][j + 1] > grid[i][j])
                        ? helper(i, j + 1, grid, dp)
                        : 0;
        int upRight =
            (i - 1 >= 0 && j + 1 < m && grid[i - 1][j + 1] > grid[i][j])
                ? helper(i - 1, j + 1, grid, dp)
                : 0;
        int downRight =
            (i + 1 < n && j + 1 < m && grid[i + 1][j + 1] > grid[i][j])
                ? helper(i + 1, j + 1, grid, dp)
                : 0;

        return dp[i][j] = 1 + max({right, upRight, downRight});
    }

    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int result = INT_MIN;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i < n; i++) {
            int val = helper(i, 0, grid, dp);
            result = max(result, val);
        }

        return result - 1;
    }
};