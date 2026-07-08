class Solution {
public:
    int numberOfRoutes(vector<string>& grid, int d) {

        int n = grid.size();
        int m = grid[0].size();

        long long MOD = 1e9+7;
        vector<vector<long long>> dp(m,vector<long long>(2,0));

        for(int j=0;j<m;j++) {

            if(grid[n-1][j] =='.') {

                dp[j][0]=1;
            }
        }

        vector<long long> baseSum(m+1,0);
        for(int j=0;j<m;j++) {

            baseSum[j+1] = (baseSum[j]+dp[j][0])%MOD;
        }

        for(int j=0;j<m;j++) {

            if(grid[n-1][j] == '#') continue;
            int l = max(0,j-d);
            int r = min(m-1,j+d);

            long long W = (baseSum[r+1]-baseSum[l]+MOD)%MOD;
            W = (W - dp[j][0] + MOD)%MOD;
            dp[j][1] = W;
            
        }
        for(int i=n-2;i>=0;i--) {

            vector<vector<long long>> nextDp(m,vector<long long>(2,0));
            vector<long long> prevRowSum(m+1,0);

            for(int j=0;j<m;j++) {

                prevRowSum[j+1] = (prevRowSum[j] + dp[j][0] + dp[j][1])%MOD;
            }

            int maxDis = 0;
            if(d>1) {

                maxDis = floor(sqrt((long long)d*d-1));
            }

            for(int j=0;j<m;j++) {

                if(grid[i][j] == '#') continue;

                int l = max(0,j-maxDis);
                int r = min(m-1,j+maxDis);

                long long W = (prevRowSum[r+1]-prevRowSum[l]+MOD)%MOD;
                nextDp[j][0] = W;
            }

            vector<long long> currSum(m+1,0);
            for(int j=0;j<m;j++) {

                currSum[j+1] = (currSum[j]+nextDp[j][0])%MOD;
            }

            for(int j=0;j<m;j++) {

                if(grid[i][j] == '#') continue;

                int l = max(0,j-d);
                int r = min(m-1,j+d);

                long long W = (currSum[r+1]-currSum[l]+MOD)%MOD;
                W = (W - nextDp[j][0] + MOD)%MOD;
                nextDp[j][1] = W;
            }
            dp = nextDp;
        }

        long long tot = 0;
        for(int j=0;j<m;j++) {

            tot = (tot + dp[j][0]+dp[j][1])%MOD;
        }

        return (int)tot;
    }
};