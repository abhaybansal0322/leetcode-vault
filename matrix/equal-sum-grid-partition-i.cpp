class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
    int m = grid.size();
        int n = grid[0].size();
        long long total_sum = 0;

        for (const auto& row : grid) {
            total_sum += accumulate(row.begin(), row.end(), 0LL);
        }

        if (total_sum % 2 != 0) {
            return false;
        }

        long long target_sum = total_sum / 2;

        // Check for horizontal cut
        long long current_horizontal_sum = 0;
        for (int i = 0; i < m - 1; ++i) {
            current_horizontal_sum += accumulate(grid[i].begin(), grid[i].end(), 0LL);
            if (current_horizontal_sum == target_sum) {
                return true;
            }
        }

        // Check for vertical cut
        long long left_vertical_sum = 0;
        for (int j = 0; j < n - 1; ++j) {
            
            for (int i = 0; i < m; ++i) {
                left_vertical_sum += grid[i][j];
            }
            if (left_vertical_sum == target_sum) {
                return true;
            }
        }

        return false;
    }
};