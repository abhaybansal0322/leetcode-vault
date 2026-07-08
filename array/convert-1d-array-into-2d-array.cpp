class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res(m,vector<int>(n,0));
        int x=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(x >= original.size())
                {
                    return {};
                }
                res[i][j]=original[x];
                x++;
                
            }
        }

        if(res[m-1][n-1]==0 || x < original.size())
        {
            return {};
        }

        return res;
        
    }
};