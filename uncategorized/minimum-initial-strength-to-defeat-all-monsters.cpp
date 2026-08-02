class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long> diff(n + 1, 0);
        for (auto &b : boosts) {
            diff[b[0]] += b[2];
            diff[b[1] + 1] -= b[2];
        }
        long long ans = 0, prefix = 0, bonus = 0;
        for (int i = 0; i < n; ++i) {
            bonus += diff[i];
            if (bonus < monsters[i])
                ans = max(ans, prefix + monsters[i] - bonus);
            prefix += monsters[i];
        }
        return ans;
    }
};