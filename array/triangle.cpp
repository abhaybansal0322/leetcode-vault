// class Solution {
//     int n;

//     int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>> &dp) {

//         if(i==n-1)  return triangle[i][j];

//         if(dp[i][j]!=INT_MAX)   return dp[i][j];

//         int d = triangle[i][j] + solve(i+1,j,triangle,dp);
//         int dg = triangle[i][j] + solve(i+1,j+1,triangle,dp);

//         return dp[i][j] = min(d,dg);
//     }
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         n = triangle.size();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));

//         return solve(0,0,triangle,dp);
        
//     }
// };


// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {

//         int n = triangle.size();

//         vector<vector<int>> dp(n,vector<int>(n,0));

//         for(int j=0;j<n;j++) {

//             dp[n-1][j] = triangle[n-1][j];
//         }

//         for(int i=n-2;i>=0;i--) {

//             for(int j=i;j>=0;j--) {

//                 int d = triangle[i][j] + dp[i+1][j];
//                 int dg = triangle[i][j] + dp[i+1][j+1];

//                 dp[i][j] = min(d,dg);
//             }
//         }

//         return dp[0][0];
        
//     }
// };

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        // vector<vector<int>> dp(n,vector<int>(n,0));

        vector<int> prev(n,0),curr(n,0);

        for(int j=0;j<n;j++) {

            prev[j] = triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--) {

            for(int j=i;j>=0;j--) {

                int d = triangle[i][j] + prev[j];
                int dg = triangle[i][j] + prev[j+1];

                curr[j] = min(d,dg);
            }
            prev = curr;
        }

        return prev[0];
        
    }
};