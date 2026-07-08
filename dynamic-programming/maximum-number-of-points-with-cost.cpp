class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        vector<long long> prev(n);
        for(int j=0;j<n;j++)
        {
            prev[j]=points[0][j];
        }

        for(int i=1;i<m;i++)
        {
            vector<long long> left(n,0);
            vector<long long> right(n,0);

            left[0]=prev[0];
            for(int j=1;j<n;j++)
            {
                left[j]=max(prev[j],left[j-1]-1);
            }

            right[n-1]=prev[n-1];
            for(int j=n-2;j>=0;j--)
            {
                right[j]=max(prev[j],right[j+1]-1);
            }

            vector<long long> curr(n);
            for(int j=0;j<n;j++)
            {
                curr[j]=max(left[j],right[j])+points[i][j];
            }
            prev=curr;
        }

        return *max_element(begin(prev),end(prev));
        

        // int row = points.size();
        // int col = points[0].size();
        // vector<long long> dp(col, 0);
        
        // for(int i = 0; i < col; i++) {
        //     dp[i] = points[0][i];
        // }
        
        // for(int r = 1; r < row; r++) {
        //     vector<long long> leftMax(col, 0), rightMax(col, 0);
        //     vector<long long> newDp(col, 0);
            
        //     leftMax[0] = dp[0];
        //     for(int i = 1; i < col; i++) {
        //         leftMax[i] = max(leftMax[i-1], dp[i] + i);
        //     }
            
        //     rightMax[col-1] = dp[col-1] - (col-1);
        //     for(int i = col-2; i >= 0; i--) {
        //         rightMax[i] = max(rightMax[i+1], dp[i] - i);
        //     }
            
        //     for(int i = 0; i < col; i++) {
        //         newDp[i] = max(leftMax[i] - i, rightMax[i] + i) + points[r][i];
        //     }
            
        //     dp = newDp;
        // }
        
        // return *max_element(dp.begin(), dp.end());
    }
};