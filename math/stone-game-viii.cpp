class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix;
        vector<int> dp;

        prefix.assign(n,0);
        dp.assign(n+1,0);
        prefix[0] = stones[0];

        for(int i=1;i<n;i++)    prefix[i] = prefix[i-1]+stones[i];

        dp[n-1] = prefix[n-1];

        for(int i=n-2;i>=1;i--) {

            int take = prefix[i] - dp[i+1];
            int skip = dp[i+1];

            dp[i] = max(skip,take);
        }

        return dp[1];
    }
};


// class Solution {
//     int n;
//     vector<int> prefix;
//     vector<int> dp;

//     int solve(int i) {
//         if(i == n-1) {
//             return dp[i] = prefix[n-1];
//         }

//         if(dp[i] != -1)     return dp[i];
//         int take = prefix[i] - solve(i+1);
//         int skip = solve(i+1);

//         return dp[i] = max(skip,take);
//     }
// public:
//     int stoneGameVIII(vector<int>& stones) {
//         n = stones.size();
//         prefix.assign(n,0);
//         dp.assign(n+1,-1);
//         prefix[0] = stones[0];

//         for(int i=1;i<n;i++)    prefix[i] = prefix[i-1]+stones[i];
//         return solve(1);
//     }
// };