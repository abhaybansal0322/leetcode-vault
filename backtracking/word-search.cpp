class Solution {
    int r,c;

    bool DFS(vector<vector<char>>& board,int i,int j,int n,string word)
    {
        if(n==word.size())
            return true;
        
        if(i<0 || i>=r || j<0 || j>=c || board[i][j]!=word[n])
            return false;
        
        board[i][j]='0';
        bool status = DFS(board,i+1,j,n+1,word) ||
                        DFS(board,i,j+1,n+1,word) ||
                        DFS(board,i-1,j,n+1,word) ||
                        DFS(board,i,j-1,n+1,word) ;

        board[i][j]=word[n];
        return status;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word=="")
        {
            return false;
        }
        r = board.size();
        c = board[0].size();

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==word[0] && DFS(board,i,j,0,word))
                {
                    return true;
                }
            }
        }

        return false;  
    }
};