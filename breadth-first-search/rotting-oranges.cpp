class Solution {
public:
    // int orangesRotting(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     queue<pair<pair<int,int>,int>> q;
    //     vector<vector<int>> vis;
    //     int tm=0;

    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(grid[i][j]==2)
    //             {
    //                 q.push({{i,j},0});
    //                 // vis[i][j]=1;
    //             }
    //             // else{
    //             //     vis[i][j]=0;
    //             // }
    //         }
    //     }

    //     while(!q.empty())
    //     {
    //         int r=q.front().first.first;
    //         int c=q.front().first.second;
    //         int t=q.front().second;
    //         q.pop();

    //         int drow[]={-1,0,1,0};
    //         int dcol[]={0,1,0,-1};

    //         for(int i=0;i<4;i++)
    //         {
    //             int nrow=r+drow[i];
    //             int ncol=c+dcol[i];

    //             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m  && grid[nrow][ncol]==1)
    //             {
    //                 q.push({{nrow,ncol},t+1});
    //                 grid[nrow][ncol]=2;
    //                 // vis[nrow][ncol]=1;
    //             }
    //         }
    //         tm=max(tm,t);
    //     }

    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(grid[i][j]==1)
    //             {
    //                 return -1;
    //             }
    //         }
    //     }

    //     return tm;
        
    // }

    int orangesRotting(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();

        bool isEmpty =true;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2 || grid[i][j]==1)
                {
                    isEmpty=false;
                    break;
                }
            }
        }

        if(isEmpty)
        {
            return 0;
        }

        queue<pair<int,int>> que;
        vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
        int tm = 0;

        auto isSafe = [&](int i,int j)
        {
            return (i>=0 && i<m && j>=0 && j<n && grid[i][j]!=0 && grid[i][j]!=2);
        };

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    que.push({i,j});
                }
            }
        }
        
        while(!que.empty())
        {
            int N = que.size();
            while(N--)
            {
                auto curr = que.front();
                que.pop();
                int i = curr.first;
                int j = curr.second;

                for(auto& dir : directions)
                {
                    int i_ = i+dir[0];
                    int j_ = j+dir[1];

                    while(isSafe(i_,j_) && grid[i_][j_]==1)
                    {
                        grid[i_][j_]=2;
                        que.push({i_,j_});
                    }
                }
            }
            tm++;
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }



        return tm-1;

    }
};