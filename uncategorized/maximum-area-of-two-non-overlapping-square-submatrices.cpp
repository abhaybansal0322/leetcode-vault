class Solution {
    int m,n;
    vector<vector<int>> memo;

    int func(int i,int j,vector<vector<int>>& mat) {
        if(i<0 || j<0)  return 0;
        if(!mat[i][j]) return 0;

        int &res = memo[i][j];
        if(res != -1) return res;

        return res = 1+min({func(i-1,j,mat),func(i,j-1,mat),func(i-1,j-1,mat)});
    }
    
public:
    int maxArea(vector<vector<int>>& mat) {

        m = mat.size();
        n = mat[0].size();

        memo.assign(m,vector<int>(n,-1));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                func(i,j,mat);
            }
        }

        int best = 0;
        for(int k=1;k<=min(m,n);k++) {
            int minR = INT_MAX,maxR = -1,minC = INT_MAX, maxC = -1;
            for(int i = k-1;i<m;i++) {
                for(int j=k-1;j<n;j++) {
                    if(memo[i][j] >= k) {
                        int r = i-k+1, c = j-k+1;
                        minR = min(minR,r); maxR = max(maxR,r);
                        minC = min(minC,c); maxC = max(maxC,c);
                    }
                }
            }

            if(maxR < 0 || (maxR-minR < k && maxC - minC < k)) break;
            best = k;
        }

        return best*best;
    }
};