class Solution {
    int m,n;
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};


    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<bool>>& vis)
    {
        if(i<0 || i>m-1 || j<0 || j>n-1 || vis[i][j] || board[i][j]=='X')
            return;

        vis[i][j]=true;
        
        for(auto& dir : directions)
        {
            int i_ = i+dir[0];
            int j_ = j+dir[1];
            dfs(i_,j_,board,vis);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<bool>> vis(m,vector<bool>(n,false));

        //FIRST AND LAST COLUMN
        for(int i=0;i<m;i++)
        {
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,vis);
            }

            if(!vis[i][n-1] && board[i][n-1]=='O'){
                dfs(i,n-1,board,vis);
            }
        }

        //FIRST AND LAST ROW
        for(int i=0;i<n;i++)
        {
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0,i,board,vis);
            }

            if(!vis[m-1][i] && board[m-1][i]=='O'){
                dfs(m-1,i,board,vis);
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};