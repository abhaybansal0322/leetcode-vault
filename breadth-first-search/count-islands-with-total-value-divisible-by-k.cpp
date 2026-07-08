class Solution {
    typedef long long ll;
    int m,n;
    vector<int> directions = {0,1,0,-1,0};
public:

    ll bfs(vector<vector<int>>& grid,int i,int j) {

        queue<pair<int,int>> Q;
        Q.push({i,j});

        ll Sum = grid[i][j];
        grid[i][j]=0;

        while(!Q.empty()) {

            auto [x,y] = Q.front();
            Q.pop();

            for(int d = 0;d<4;d++) {

                int nx = x + directions[d];
                int ny = y + directions[d+1];

                if(nx >= 0 && nx <m && ny >=0 && ny < n && grid[nx][ny] > 0) {

                    Sum += grid[nx][ny];
                    Q.push({nx,ny});
                    grid[nx][ny] = 0;
                }
            }
        }

        return Sum;
    }

    
    int countIslands(vector<vector<int>>& grid, int k) {

        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for(int i=0;i<m;i++) {

            for(int j=0;j<n;j++) {

                if(grid[i][j] > 0) {

                    ll islandSum = bfs(grid,i,j);

                    if(islandSum % k == 0)
                        ans++;
                }
            }
        }

        return ans;
        
    }
};