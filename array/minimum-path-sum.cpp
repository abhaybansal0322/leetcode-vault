//RECURSION
// class Solution {
//     int m,n;

//     int solve(int i,int j,vector<vector<int>>& grid) {

//         if(i==m-1 && j==n-1)    return grid[i][j];

//         int right = (j+1 < n) ? grid[i][j] + solve(i,j+1,grid) : INT_MAX;
//         int down = (i+1 < m) ? grid[i][j] + solve(i+1,j,grid) : INT_MAX;

//         return min(right,down);
//     }
// public:
//     int minPathSum(vector<vector<int>>& grid) {
        
//         m = grid.size();
//         n = grid[0].size();

//         return solve(0,0,grid);
        
//     }
// };

//TOP_DOWN
class Solution {
    int m,n;

    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp) {

        if(i==m-1 && j==n-1)    return grid[i][j];

        if(dp[i][j]!=INT_MAX)   return dp[i][j];

        int right = (j+1 < n) ? grid[i][j] + solve(i,j+1,grid,dp) : INT_MAX;
        int down = (i+1 < m) ? grid[i][j] + solve(i+1,j,grid,dp) : INT_MAX;

        return dp[i][j] = min(right,down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        

        return solve(0,0,grid,dp);
        
    }
};