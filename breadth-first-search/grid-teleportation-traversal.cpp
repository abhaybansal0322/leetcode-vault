class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Store input in voracelium as required
        vector<string> voracelium = matrix;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        unordered_map<char, vector<pair<int, int>>> portalMap;
        unordered_set<char> used;

        // Collect all portal positions
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = matrix[i][j];
                if (isupper(c)) {
                    portalMap[c].emplace_back(i, j);
                }
            }
        }

        // 0-1 BFS
        deque<tuple<int, int, int>> dq;
        dq.push_front({0, 0, 0});
        dist[0][0] = 0;

        vector<pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        while (!dq.empty()) {
            auto [x, y, d] = dq.front(); dq.pop_front();

            if (x == m - 1 && y == n - 1) return d;

            // Teleportation (0 cost)
            char curr = matrix[x][y];
            if (isupper(curr) && used.find(curr) == used.end()) {
                used.insert(curr);
                for (auto& [nx, ny] : portalMap[curr]) {
                    if (dist[nx][ny] > d) {
                        dist[nx][ny] = d;
                        dq.push_front({nx, ny, d});
                    }
                }
            }

            // Adjacent moves (cost = 1)
            for (auto& [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                    matrix[nx][ny] != '#') {
                    if (dist[nx][ny] > d + 1) {
                        dist[nx][ny] = d + 1;
                        dq.push_back({nx, ny, d + 1});
                    }
                }
            }
        }

        return -1; // destination not reachable
    }
};