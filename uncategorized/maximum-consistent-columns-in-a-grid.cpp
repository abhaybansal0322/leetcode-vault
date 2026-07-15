class Solution {
    int m,n;

    bool canConnect(vector<vector<int>>& grid ,int i,int j, int limit) {

        for(int row=0; row<m; row++) {

            if(abs(grid[row][i]-grid[row][j]) > limit) return false;
        }
        return true;
    }

    int helper(vector<vector<int>>& grid, int i, int limit, vector<int>& dp) {

        if(dp[i] != -1) return dp[i];
        int ans = 1;

        for(int j=0;j<i;j++) {
            if(canConnect(grid,i,j,limit)) {

                ans = max(ans,1+helper(grid,j,limit,dp));
            }
        }

        return dp[i] = ans;
    }
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {

        m = grid.size();
        n = grid[0].size();
        int answer = 1;
        vector<int> dp(n+1,-1);

        for (int i = 0; i < n; i++) {
            answer = max(answer, helper(grid,i,limit,dp));
        }

        return answer;
    }
};