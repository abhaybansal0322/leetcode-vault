class Solution {
public:
    int rows;
    int cols;

    void dfs(vector<vector<char>>& grid,int i,int j) {
        if(i<0 || i>=rows || j < 0 || j >= cols || grid[i][j]!='1'){
            return;
        }

        

        grid[i][j]='0';

        dfs(grid ,i+1 ,j);
        dfs(grid ,i-1 ,j);
        dfs(grid ,i ,j+1);
        dfs(grid ,i ,j-1);
        

    }


    int numIslands(vector<vector<char>>& grid) {
        rows=grid.size();
        cols=grid[0].size();
        int islands=0;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    islands++;
                }
            }
        }

        return islands;


        
    }
};