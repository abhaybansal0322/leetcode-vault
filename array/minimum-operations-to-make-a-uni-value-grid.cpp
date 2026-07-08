class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size() , n = grid[0].size();
        vector<int> sortedValues;
        int rem = grid[0][0]%x;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {

                if(grid[i][j] % x != rem) return -1;

                sortedValues.push_back(grid[i][j]);
            }
        }

        sort(sortedValues.begin(),sortedValues.end());

        int mid = sortedValues.size()/2;
        int val = sortedValues[mid];

        int res = 0;
        for(int i=0;i<sortedValues.size();i++) {
            if(i == mid) continue;

            res += abs(val-sortedValues[i])/x;
        }

        return res;
    }
};