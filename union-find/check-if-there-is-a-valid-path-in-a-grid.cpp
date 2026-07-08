class Solution {
    
    struct DSU {
        int maxN = 300*300 + 5;
        vector<int> parent;
        vector<int> rank;

        DSU() {
            parent.resize(maxN);
            rank.resize(maxN, 0);

            for(int i = 0; i < maxN; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {

            if(x == parent[x]) return x;

            return parent[x] = find(parent[x]);
        }

        void Union(int x,int y) {
            int px = find(x);
            int py = find(y);

            if(px != py) {

                if(rank[px] < rank[py]) swap(px,py);

                parent[py] = px;
                if(rank[px] == rank[py]) {
                    rank[px]++;
                }
            }
        }
    } dsu;

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        auto getId = [&](int x,int y) {return x*n+y;};

        auto detectL = [&](int x,int y) {
            if(y-1>=0 && (grid[x][y-1]==4 || grid[x][y-1]==6 || grid[x][y-1]==1))
                dsu.Union(getId(x,y),getId(x,y-1));
        };
        auto detectR = [&](int x,int y) {
            if(y+1<n && (grid[x][y+1]==3 || grid[x][y+1]==5 || grid[x][y+1]==1))
                dsu.Union(getId(x,y),getId(x,y+1));
        };
        auto detectD = [&](int x,int y) {
            if(x+1<m && (grid[x+1][y]==5 || grid[x+1][y]==6 || grid[x+1][y]==2))
                dsu.Union(getId(x,y),getId(x+1,y));
        };
        auto detectU = [&](int x,int y) {
            if(x-1>=0 && (grid[x-1][y]==3 || grid[x-1][y]==4 || grid[x-1][y]==2))
                dsu.Union(getId(x,y),getId(x-1,y));
        };

        auto handler = [&](int x,int y) {

            switch(grid[x][y]) {
                case 1: {
                    detectL(x, y);
                    detectR(x, y);
                } break;
                case 2: {
                    detectU(x, y);
                    detectD(x, y);
                } break;
                case 3: {
                    detectL(x, y);
                    detectD(x, y);
                } break;
                case 4: {
                    detectR(x, y);
                    detectD(x, y);
                } break;
                case 5: {
                    detectL(x, y);
                    detectU(x, y);
                } break;
                case 6: {
                    detectR(x, y);
                    detectU(x, y);
                }
            }
        };

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                handler(i,j);
            }
        }

        return dsu.find(getId(0,0)) == dsu.find(getId(m-1,n-1));
    }
};