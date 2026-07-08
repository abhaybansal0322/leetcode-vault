class Solution {
    int n;

    pair<int,int> getCoord(int val) {

        int RT = (val-1)/n;
        int RB = (n-1) - RT;

        int col = (val-1)%n;

        if((RB%2==1 && n%2==1) || (RB%2==0 && n%2==0))
            col = (n-1)-col;

        return {RB,col}; 
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int steps = 0;

        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<int> Q;
        Q.push(1);
        vis[n-1][0]=true;

        while(!Q.empty()) {

            int N = Q.size();
            
            while(N--) {

                int t = Q.front(); Q.pop();

                if(t==n*n) return steps;

                for(int k=1;k<=6;k++) {

                    int val = t+k;

                    if(val > n*n) break;


                    pair<int,int> P = getCoord(val);
                    int r = P.first;
                    int c = P.second;

                    if(vis[r][c])   continue;

                    vis[r][c] = true;
                    
                    if(board[r][c]==-1)
                    {
                        Q.push(val);
                    }
                    else {

                        Q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }

        return -1;

    }
};