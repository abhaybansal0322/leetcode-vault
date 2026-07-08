// class Solution {
// public:
//     int dp[101][101];
//     int n;

//     int helper(vector<vector<int>>& matrix,int row,int col)
//     {
//         if(row == n-1)
//         return matrix[row][col];

//         if(dp[row][col]!=-1)
//         return dp[row][col];

//         int minNum=INT_MAX;
//         for(int k=-1;k<=1;k++)
//         {
//             if(col+k < n && col+k>=0){
//             minNum = min(minNum,matrix[row][col]+helper(matrix,row+1,col+k));
//             }
//         }

//         return dp[row][col]=minNum;
//     }


//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         memset(dp,-1,sizeof(dp));
//         n=matrix[0].size();
//         int res=INT_MAX;
//         for(int i=0;i<n;i++)
//         {
//             res = min(res,helper(matrix,0,i));
//         }
//         return res;


        
//     }
// };


// };

class Solution {
public:
    int MFS(vector<vector<int>>& A) {
        int m = A.size();
        vector<vector<int>> t(m, vector<int>(m));
        
        //initialization
        for(int col = 0; col<m; col++) {
            t[0][col] = A[0][col];
        }
        
        for(int row = 1; row < m; row++) {
            for(int col = 0; col < m; col++) {
                t[row][col] = A[row][col] + min({t[row-1][col], 
                                                 t[row-1][max(0, col-1)], 
                                                 t[row-1][min(m-1, col+1)]});
            }
        }

        return *min_element(t[m-1].begin(), t[m-1].end());
        
    }
    int minFallingPathSum(vector<vector<int>>& A) { 
        return MFS(A);
    }
};