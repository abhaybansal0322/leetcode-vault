class Solution {
public:
    int rows, cols;

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i,
             int j, bool& check) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid2[i][j] != 1) {
            return;
        }

        if (grid1[i][j] != 1) {
            check = false;
        }
        grid2[i][j] = 0;

        dfs(grid1, grid2, i + 1, j, check);
        dfs(grid1, grid2, i - 1, j, check);
        dfs(grid1, grid2, i, j + 1, check);
        dfs(grid1, grid2, i, j - 1, check);
    }

    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int result = 0;
        rows = grid2.size();
        cols = grid2[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid2[i][j] == 1) {
                    bool check = true;
                    dfs(grid1, grid2, i, j, check);
                    if (check) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};