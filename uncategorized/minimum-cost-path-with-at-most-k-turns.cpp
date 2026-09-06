class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if(m==1 && n==1) return grid[0][0];

        int di[4] = {-1,1,0,0};
        int dj[4] = {0,0,-1,1};

        vector dist(m,vector(n,vector(4,vector<int>(k+1,INT_MAX))));
        priority_queue<array<int,5>,vector<array<int,5>>,greater<>> pq;

        for(int d=0;d<4;d++) {
            dist[0][0][d][0] = grid[0][0];
            pq.push({grid[0][0],0,0,d,0});
        }

        while(!pq.empty()) {
            auto [c,i,j,d,t] = pq.top(); pq.pop();
            if(c > dist[i][j][d][t]) continue;
            if(i == m-1 && j == n-1) return c;

            for(int nd=0;nd<4;nd++) {
                int ni = i+di[nd];
                int nj = j+dj[nd];
                if(ni<0 || ni>=m || nj<0 || nj>=n) continue;
                int nt = t+(nd!=d);
                int nc = c+grid[ni][nj];

                if(nt<=k && nc<dist[ni][nj][nd][nt]) {
                    dist[ni][nj][nd][nt] = nc;
                    pq.push({nc,ni,nj,nd,nt});
                }
            }
        }

        return -1;
    }
};