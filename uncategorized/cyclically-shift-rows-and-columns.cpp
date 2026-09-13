class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> a =  grid , b(n,vector<int>(n));
        for(int i=0;i<n;i++) {
            int k = rowShift[i]%n;
            for(int j=0;j<n;j++) {
                b[i][j] = a[i][(j+k)%n];
            }
        }

        vector<vector<int>> c(n,vector<int>(n));
        for(int j=0;j<n;j++) {
            int k = colShift[j]%n;
            for(int i=0;i<n;i++) {
                c[i][j] = b[(i+k)%n][j];
            }
        }

        return c;
    }
};