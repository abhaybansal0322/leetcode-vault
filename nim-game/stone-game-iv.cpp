class Solution {
public:
    vector<int> memo;   // -1 = not computed, 0 = losing, 1 = winning

    bool solve(int n) {
        if (n == 0) return false;
        if (memo[n] != -1) return memo[n];      // already solved, reuse

        for (int k = 1; k * k <= n; k++) {
            if (solve(n - k * k) == false)
                return memo[n] = 1;             // store, then return
        }
        return memo[n] = 0;
    }

    bool winnerSquareGame(int n) {
        memo.assign(n + 1, -1);
        return solve(n);
    }
};