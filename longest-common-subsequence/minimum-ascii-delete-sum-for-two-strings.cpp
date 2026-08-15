class Solution {
    int n, m;
    string a, b;
    vector<int> sa, sb;         
    vector<vector<int>> memo;

    int go(int i, int j) {
        if (i == n) return sb[j];
        if (j == m) return sa[i];
        if (memo[i][j] != -1) return memo[i][j];

        if (a[i] == b[j]) return memo[i][j] = go(i + 1, j + 1);
        return memo[i][j] = min(a[i] + go(i + 1, j),
                                b[j] + go(i, j + 1));
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        a = s1; b = s2; n = a.size(); m = b.size();
        sa.assign(n + 1, 0); sb.assign(m + 1, 0);
        for (int i = n - 1; i >= 0; i--) sa[i] = sa[i + 1] + a[i];
        for (int j = m - 1; j >= 0; j--) sb[j] = sb[j + 1] + b[j];
        memo.assign(n + 1, vector<int>(m + 1, -1));
        return go(0, 0);
    }
};