class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if(px == py) return true; // cycle
        
        if(rank[px] < rank[py]) parent[px] = py;
        else if(rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        
        return false;
    }
};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        DSU dsu(n * m);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int id = i * m + j;
                
                if(i > 0 && grid[i][j] == grid[i-1][j]) {
                    if(dsu.unite(id, (i-1)*m + j)) return true;
                }
                
                if(j > 0 && grid[i][j] == grid[i][j-1]) {
                    if(dsu.unite(id, i*m + (j-1))) return true;
                }
            }
        }
        
        return false;
    }
};


/* -------- DFS ----------- */

// class Solution {
// public:
//     int n, m;
//     vector<vector<int>> vis;
    
//     bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid) {
//         vis[x][y] = 1;
        
//         int dx[4] = {1, -1, 0, 0};
//         int dy[4] = {0, 0, 1, -1};
        
//         for(int i = 0; i < 4; i++) {
//             int nx = x + dx[i];
//             int ny = y + dy[i];
            
//             if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
//             if(grid[nx][ny] != grid[x][y]) continue;
            
//             if(!vis[nx][ny]) {
//                 if(dfs(nx, ny, x, y, grid)) return true;
//             } else if(nx != px || ny != py) {
//                 return true; // cycle found
//             }
//         }
        
//         return false;
//     }
    
//     bool containsCycle(vector<vector<char>>& grid) {
//         n = grid.size();
//         m = grid[0].size();
//         vis.assign(n, vector<int>(m, 0));
        
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if(!vis[i][j]) {
//                     if(dfs(i, j, -1, -1, grid)) return true;
//                 }
//             }
//         }
        
//         return false;
//     }
// };