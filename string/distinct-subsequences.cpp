class Solution {
    int n,m;
    vector<vector<int>> dp;
    int helper(string& s, string& t, int i, int j) {

        if(j==m)    return 1;
        if(i==n)    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];

        int notTake = helper(s,t,i+1,j);
        
        int take = 0;
        if(s[i] == t[j]) {
            take = helper(s,t,i+1,j+1);
        }

        return dp[i][j] = take+notTake;
    }
public:
    int numDistinct(string s, string t) {
        n = s.length();
        m = t.length();

        dp.resize(1001,vector<int>(1001,-1));
        
        return helper(s,t,0,0);
    }
};