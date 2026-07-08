class Solution {
    int neg = -1e9;
    int m,n;
    
    int solve(int i, int j, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {

        if(i<0 || i>=m || j<0 || j>=n) return neg;
        if(dp[i][j][k] != -1)   return dp[i][j][k];
        int score = grid[i][j];
        int cost = grid[i][j] == 0 ? 0 : 1;

        if(k < cost) return neg;
        
        if(i == m-1 && j == n-1) {

            if(k < cost) return neg;

            return grid[i][j];
        }
        
        return dp[i][j][k] = max(score + solve(i+1,j,k-cost,grid,dp), score + solve(i,j+1,k-cost,grid,dp));
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        int ans = solve(0,0,k,grid,dp);
        return ans < 0 ? -1 : ans;
    }
};