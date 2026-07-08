class Solution {
    vector<pair<int, int>> directions = {
    {-1, -1}, {-1, 0}, {-1, 1},
    { 0, -1},          { 0, 1},
    { 1, -1}, { 1, 0}, { 1, 1}
};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> neigh(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count=0;
                for(auto& dir : directions)
                {
                    int i_ = i+dir.first;
                    int j_ = j+dir.second;

                    if(i_>=0 && i_<m && j_>=0 && j_<n && board[i_][j_]==1)
                        count++;
                }
                neigh[i][j]=count;
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(neigh[i][j]<2)
                    board[i][j]=0;
                
                if(neigh[i][j]>3)
                    board[i][j]=0;
                
                if(neigh[i][j]==3)
                    board[i][j]=1;
            }
        }
    }
};