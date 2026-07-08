class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rows(m,0);
        vector<int> cols(n,0);

        int res = 0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    if(rows[i] > 1 || cols[j] > 1)
                    {
                        res++;
                    }
                }
            }
        }

        return res;

        
    }
};





// class Solution {
// public:
//     int countServers(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         int res = 0;

//         vector<vector<int>> checked(m,vector<int>(n,0));

//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(grid[i][j]==1) //Server Node
//                 {                  
//                     bool comm = false;
//                     for(int a=i+1;a<m;a++)
//                     {
//                         if(grid[a][j]==1)
//                         {
//                             checked[a][j]=1;
//                             comm = true;
//                         }
//                     }

//                     for(int b=j+1;b<n;b++)
//                     {
//                         if(grid[i][b]==1)
//                         {
//                             checked[i][b]=1;
//                             comm = true;
//                         }
//                     }

//                     if(comm || checked[i][j]==1)
//                     {
//                         res++;
//                     }

//                     checked[i][j]=1;
                    
//                 } 
//             }
//         }

//         return res;

        
//     }
// };