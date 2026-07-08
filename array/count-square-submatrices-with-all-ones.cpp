class Solution {
public:

    // int m,n;

    // int helper(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    // {
    //     if(i >= m || j >= n || matrix[i][j]==0)
    //     {
    //         return 0;
    //     }

    //     if(dp[i][j] != -1)
    //     {
    //         return dp[i][j];
    //     }

    //     int right = helper(i,j+1,matrix,dp);
    //     int left = helper(i+1,j,matrix,dp);
    //     int diag = helper(i+1,j+1,matrix,dp);

    //     return dp[i][j] = 1+min({right,left,diag});
    // }

    // int countSquares(vector<vector<int>>& matrix) {
    //     int result = 0;
    //     m=matrix.size();
    //     n=matrix[0].size();

    //     vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

    //     for(int i=0;i<m;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    //             if(matrix[i][j]==1)
    //             {
    //                 result += helper(i,j,matrix,dp);
    //             }
    //         }
    //     }

    //     return result;        
    // }

    int countSquares(vector<vector<int>>& matrix) {
        int result = 0;
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=matrix[i][j];
                }
                else if(matrix[i][j]==1)
                {
                    dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                }
                result += dp[i][j];
            }
        }
        
        return result;        
    }
};