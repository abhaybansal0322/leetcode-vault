class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> memo;

    bool dfs(vector<vector<char>>& grid, int i, int j, int balance) {
        int& res = memo[i][j][balance];
        if (res != -1) return res;

        int nb = balance + ((grid[i][j] == '(') ? 1 : -1);
        int remaining = (m - 1 - i) + (n - 1 - j); // early cutfoff maardo

        bool ok;
        if (nb < 0 || nb > remaining) {
            ok = false;
        } else if (i == m - 1 && j == n - 1) {
            ok = (nb == 0);
        } else {
            ok = false;
            if (i + 1 < m && dfs(grid, i + 1, j, nb)) ok = true;
            if (!ok && j + 1 < n && dfs(grid, i, j + 1, nb)) ok = true;
        }

        res = ok;
        return ok;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int L = m + n - 1;

        if (L % 2 == 1) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        memo.assign(m, vector<vector<int>>(n, vector<int>(L + 1, -1)));
        return dfs(grid, 0, 0, 0);
    }
};