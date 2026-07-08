class Solution {
    int n;

    // This helper function is correct and remains unchanged.
    int countWalls(const vector<int>& walls, int L, int R) {
        if (L > R) return 0;
        auto itL = lower_bound(walls.begin(), walls.end(), L);
        auto itR = upper_bound(walls.begin(), walls.end(), R);
        return int(itR - itL);
    }

    // The DFS function is updated to use the expanded state.
    // It now returns a pair: {max_walls if robot i shoots left, max_walls if robot i shoots right}
    pair<int, int> dfs(int i, vector<pair<int, int>>& dp, const vector<pair<int, int>>& robotsDir, const vector<int>& walls) {
        // Base case: No robots mean 0 walls destroyed.
        if (i < 0) {
            return {0, 0};
        }

        // Memoization check for the pair.
        if (dp[i].first != -1) {
            return dp[i];
        }

        // Get the optimal results for the subproblem of the first i-1 robots.
        pair<int, int> prev_max = dfs(i - 1, dp, robotsDir, walls);
        int prev_left_max = prev_max.first;
        int prev_right_max = prev_max.second;

        // --- Calculate walls and ranges for the current robot 'i' ---
        int pos_i = robotsDir[i].first;
        int dis_i = robotsDir[i].second;

        // Range for a left shot by robot 'i' (constrained by robot 'i-1')
        int L_i = pos_i - dis_i;
        if (i > 0) {
            L_i = max(L_i, robotsDir[i-1].first + 1);
        }
        int walls_left = countWalls(walls, L_i, pos_i);

        // Range for a right shot by robot 'i' (constrained by robot 'i+1')
        int R_i = pos_i + dis_i;
        if (i < n - 1) {
            R_i = min(R_i, robotsDir[i+1].first - 1);
        }
        int walls_right = countWalls(walls, pos_i, R_i);

        // --- Calculate the potential overlap ---
        // Overlap only occurs if robot 'i' shoots LEFT and robot 'i-1' shoots RIGHT.
        int overlap = 0;
        if (i > 0) {
            // Right range of robot 'i-1' is constrained by robot 'i'.
            int R_prev = min(robotsDir[i-1].first + robotsDir[i-1].second, pos_i - 1);
            
            // The overlapping region of walls is between L_i and R_prev.
            if (R_prev >= L_i) {
                overlap = countWalls(walls, L_i, R_prev);
            }
        }

        // --- DP Transitions ---

        // Total walls if robot 'i' shoots LEFT:
        // Add its walls to the best of the previous states, subtracting overlap where necessary.
        int total_if_i_shoots_left = walls_left + max(prev_left_max, prev_right_max - overlap);

        // Total walls if robot 'i' shoots RIGHT:
        // Add its walls to the best of the previous states. No overlap possible with robot 'i-1'.
        int total_if_i_shoots_right = walls_right + max(prev_left_max, prev_right_max);
        
        // Memoize and return the result for state 'i'.
        return dp[i] = {total_if_i_shoots_left, total_if_i_shoots_right};
    }
    
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        n = robots.size();
        if (n == 0) return 0;
        
        vector<pair<int, int>> robotsDir;
        for (int i = 0; i < n; i++) {
            robotsDir.push_back({robots[i], distance[i]});
        }

        sort(robotsDir.begin(), robotsDir.end());
        sort(walls.begin(), walls.end());
        
        // DP table now stores pairs, initialized to {-1, -1}.
        vector<pair<int, int>> dp(n, {-1, -1});

        // Get the final pair of results for the last robot.
        pair<int, int> result = dfs(n - 1, dp, robotsDir, walls);

        // The answer is the maximum of the two possibilities for the last robot.
        return max(result.first, result.second);
    }
};