class Solution {

    // int findSum(int i,int j,int s,vector<vector<int>>& prefix) {
        
    //     int sum = 0;
    //     int m = prefix.size();
    //     for(int row=i;row<i+s;row++) {

    //         sum += (prefix[row][j+s-1] - ((j>0) ? prefix[row][j-1] : 0));
    //     }
    //     return sum;
    // }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        // Build prefix sum (2D)
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = mat[i - 1][j - 1]
                           + pref[i - 1][j]
                           + pref[i][j - 1]
                           - pref[i - 1][j - 1];
            }
        }

        int r = min(m,n);
        int res = 0;
        int l = 1;

        while(r>=l) {
            
            bool found = false;
            int s = l+(r-l)/2;
            for(int i=0;i+s-1<m && !found;i++) {

                for(int j=0;j+s-1<n;j++) {

                    int sum = pref[i+s][j+s]
                            - pref[i+s][j]
                            - pref[i][j+s]
                            + pref[i][j];

                    if(sum <= threshold) {

                        res = s;
                        found = true;
                        break;
                    }
                } 
            }

            if(found) {

                l = s+1;
                
            } else {
                r = s-1;
            }
        }

        return res;
    }
};