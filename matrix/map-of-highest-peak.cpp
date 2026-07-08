class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>> directions{{0,1},{-1,0},{0,-1},{1,0}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m,vector<int>(n,-1));
        queue<P> que;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isWater[i][j]==1)
                {
                    height[i][j]=0;
                    que.push({i,j});
                }
            }
        }

        while(!que.empty())
        {
            P val = que.front();
            que.pop();

            for(auto &dir : directions)
            {
                int i = val.first + dir[0];
                int j = val.second + dir[1];

                if(i>=0 && i<m && j>=0 && j<n && height[i][j]==-1)
                {
                    height[i][j] = height[val.first][val.second]+1;
                    que.push({i,j});
                }
            }
        }

        return height;
        
    }
};