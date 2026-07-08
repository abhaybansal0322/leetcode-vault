class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions{{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                                   {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

    // int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    //     if (grid[0][0] == 1) {
    //         return -1;
    //     }
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     auto isSafe = [&](int x, int y) {
    //         return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0);
    //     };

    //     vector<vector<int>> result(m, vector<int>(n, INT_MAX));
    //     result[0][0] = 0;

    //     priority_queue<P, vector<P>, greater<P>> pq;
    //     pq.push({0, {0, 0}});
    //     grid[0][0] = 1;

    //     while (!pq.empty()) {
    //         auto curr = pq.top();
    //         pq.pop();

    //         int d = curr.first;
    //         int x = curr.second.first;
    //         int y = curr.second.second;

    //         if (x == m - 1 && y == n - 1) {
    //             return result[m - 1][n - 1] + 1;
    //         }

    //         for (auto dir : directions) {
    //             int x_ = x + dir[0];
    //             int y_ = y + dir[1];

    //             if (isSafe(x_, y_)) {
    //                 pq.push({d + 1, {x_, y_}});
    //                 result[x_][y_] = min(result[x_][y_], d + 1);
    //                 grid[x_][y_] = 1;
    //             }
    //         }
    //     }

    //     return -1;
    // }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        if (grid[0][0] == 1) {
            return -1;
        }

        int m = grid.size();
        int n = grid[0].size();

        auto isSafe = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0);
        };

        queue<pair<int,int>> pq;
        int steps = 1;

        pq.push({0,0});
        grid[0][0]=1;

        while(!pq.empty())
        {
            int N = pq.size();
            while(N--)
            {
                auto curr = pq.front();
                pq.pop();
                int x = curr.first;
                int y = curr.second;

                if(x==m-1 && y==n-1)
                {
                    return steps;
                }

                for(auto dir : directions)
                {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(isSafe(x_,y_))
                    {
                        pq.push({x_,y_});
                        grid[x_][y_]=1;
                    }
                }

            }
            steps++;
        }
        return -1;
    }
};