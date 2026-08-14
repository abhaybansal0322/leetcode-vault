class Solution {
    int n, m;
    vector<vector<int>> memo;

    int helper(int i, int j, string &a, string &b) {
        if (i == n) return m - j;
        if (j == m) return n - i;
        if (memo[i][j] != -1) return memo[i][j];

        if (a[i] == b[j]) return memo[i][j] = helper(i+1, j+1, a, b);
        return memo[i][j] = 1 + min(helper(i+1, j, a, b), helper(i, j+1, a, b));
    }
public:
    int minDistance(string a, string b) {
        n = a.size(); m = b.size();
        memo.assign(n+1, vector<int>(m+1, -1));
        return helper(0, 0, a, b);
    }
};