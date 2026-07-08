class Solution {
public:

    int n,m;

    int helper(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp)
    {
        if(i>=n || j>=m || obstacleGrid[i][j]==1)
            return 0;

        if(i==n-1  && j==m-1)
            return 1;

        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int down = helper(i+1,j,obstacleGrid,dp);
        int right = helper(i,j+1,obstacleGrid,dp);

        return dp[i][j] = down + right ;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        return helper(0,0,obstacleGrid,dp);
    }
};