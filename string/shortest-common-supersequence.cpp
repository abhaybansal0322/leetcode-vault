class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = (a[i-1] == b[j-1]) ? dp[i-1][j-1] + 1
                                          : max(dp[i-1][j], dp[i][j-1]);

    string r;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1])              { r += a[i-1]; i--; j--; }  
        else if (dp[i-1][j] >= dp[i][j-1]) { r += a[i-1]; i--; }       
        else                               { r += b[j-1]; j--; }       
    }
    while (i > 0) { r += a[i-1]; i--; }    
    while (j > 0) { r += b[j-1]; j--; }

    reverse(r.begin(), r.end());
    return r;
}
};