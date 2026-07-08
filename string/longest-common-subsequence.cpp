// class Solution {

//     int solve(string& text1,string& text2,int idx1,int idx2,vector<vector<int>>& dp) {

//         if(idx1 < 0 || idx2 < 0)    return 0;

//         if(dp[idx1][idx2] != -1)    return dp[idx1][idx2];

//         if(text1[idx1] == text2[idx2])  return dp[idx1][idx2] = 1 + solve(text1,text2,idx1-1,idx2-1,dp);

//         return dp[idx1][idx2] = max(solve(text1,text2,idx1-1,idx2,dp),solve(text1,text2,idx1,idx2-1,dp));
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
        
//         int n = text1.size();
//         int m = text2.size();

//         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

//         return solve(text1,text2,n-1,m-1,dp);
        
//     }
// };


// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
        
//         int n = text1.size();
//         int m = text2.size();

//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));

//         // //Base case
//         // for(int i=0;i<n;i++) {
//         //     dp[i][0] = 0;
//         // }

//         // for(int j=0;j<m;j++) {
//         //     dp[0][j] = 0;
//         // }


//         for(int idx1=1;idx1<n+1;idx1++) {

//             for(int idx2=1;idx2<m+1;idx2++) {

//                 if(text1[idx1-1] == text2[idx2-1])  dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];

//                 else dp[idx1][idx2] = max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
//             }
//         }


//         return dp[n][m];
        
//     }
// };

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m+1,0),curr(m+1,0);


        for(int idx1=1;idx1<n+1;idx1++) {

            for(int idx2=1;idx2<m+1;idx2++) {

                if(text1[idx1-1] == text2[idx2-1])  curr[idx2] = 1 + prev[idx2-1];

                else curr[idx2] = max(prev[idx2],curr[idx2-1]);
            }
            prev = curr;
        }


        return prev[m];
        
    }
};