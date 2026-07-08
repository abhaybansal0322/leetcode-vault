class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {

        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,-1));
        queue<pair<int,int>> q;

        for(auto& s : sources) {

            int r = s[0] , c = s[1] , color = s[2];
            ans[r][c] = color;
            dist[r][c] = 0;
            q.push({r,c});
        }


        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};

        while(!q.empty()) {

            auto [r,c] = q.front();
            q.pop();

            for(int i=0;i<4;i++) {

                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m) {

                    if(dist[nr][nc] == -1) {

                        ans[nr][nc] = ans[r][c];
                        dist[nr][nc] = dist[r][c]+1;
                        q.push({nr,nc});
                    }

                    if(dist[nr][nc] == dist[r][c]+1) {

                        ans[nr][nc] = max(ans[r][c],ans[nr][nc]);
                    }
                }
            }
        }
        return ans;
    }
};