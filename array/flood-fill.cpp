class Solution {
public:
    int vis[51][51];

    void dfs(vector<vector<int>>& image,int i,int j,int color,int orig)
    {
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size() || image[i][j]!=orig || vis[i][j]==1)
        {
            return;
        }

        vis[i][j]=1;
        image[i][j]=color;
        dfs(image,i-1,j,color,orig);
        dfs(image,i+1,j,color,orig);
        dfs(image,i,j+1,color,orig);
        dfs(image,i,j-1,color,orig);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        memset(vis,0,sizeof(vis));
        int orig=image[sr][sc];
        if(orig!=color)
        {
            dfs(image,sr,sc,color,orig);
        }
        
        return image;
    }
};