class Solution {

    vector<vector<int>> dir = {{1,1},{1,-1},{-1,-1},{-1,1}};
    int n,m;

  public:

    int solve(vector<vector<int>>& grid, int i, int j, int d, bool canTurn, int val) {

        int i_ = i + dir[d][0];
        int j_ = j + dir[d][1];

        if(i_ >= m || i_ < 0 || j_ >= n || j_ < 0 || grid[i_][j_] != val) return 0;

        int newVal = (val == 2) ? 0 : 2;

        int len = 0;

        int keepMoving = 1 + solve(grid,i_,j_,d,canTurn,newVal);

        len = max(len,keepMoving);

        if(canTurn) {

            int Turn = 1 + solve(grid,i_,j_,(d+1)%4,false,newVal);
            len = max(len,Turn);
        }

        return len;
        
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int result = 0;

        for(int i=0;i<m;i++) {

            for(int j=0;j<n;j++) {

                if(grid[i][j] == 1) {

                    for(int d=0;d<4;d++) {

                        result = max(result , 1 + solve(grid,i,j,d,true,2));
                    }
                }
            }
        }

        return result;


        
    }
};