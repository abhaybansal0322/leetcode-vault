class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        long long firstRow = accumulate(begin(grid[0]),end(grid[0]),0LL);

        long long secondRow = 0;
        long long minimizedSum = LONG_LONG_MAX;

        for(int i=0;i<grid[0].size();i++)
        {
            firstRow -= grid[0][i];

            long long best = max(firstRow,secondRow);

            minimizedSum = min(minimizedSum,best);

            secondRow += grid[1][i];
        }

        return minimizedSum;

    }
};