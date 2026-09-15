class Solution {
    vector<vector<int>> dp;

    bool isPal(string& s, int i, int j) {
        while(i<j) {
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string& s, int k, int i, int j) {
        if(i>=s.length() || j>=s.length())  return 0;
        if(dp[i][j] != -1)    return dp[i][j];

        if(isPal(s,i,j)) {
            int take = 1 + solve(s,k,j+1,j+k);
            int grow = solve(s,k,i,j+1);
            int slide = solve(s,k,i+1,j+1);

            return dp[i][j] = max({take,grow,slide});

        } else {
            int grow = solve(s,k,i,j+1);
            int slide = solve(s,k,i+1,j+1);

            return dp[i][j] = max(grow,slide);
        }

        return -1;
    }
public:
    int maxPalindromes(string s, int k) {
        if(k == 1) return s.length();
        int n = s.length();
        dp.assign(n+1,vector<int>(n+1,-1));
        return solve(s,k,0,k-1);
    }
};