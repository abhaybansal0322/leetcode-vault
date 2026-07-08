class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int mask, const vector<int>& nums1, const vector<int>& nums2) {
        if (mask == (1 << n) - 1) return 0;            // all used
        if (dp[mask] != -1) return dp[mask];     // memo
        
        int i = __builtin_popcount(mask);             // next index in nums1
        int ans = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (!(mask & (1 << j))) {
                int newMask = mask | (1 << j);
                int cost = (nums1[i] ^ nums2[j]) + solve(newMask, nums1, nums2); // parentheses important
                ans = min(ans, cost);
            }
        }
        dp[mask] = ans;
        return ans;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        dp.assign(1 << n, -1);
        return solve(0, nums1, nums2);
    }
};
