class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        int m = mat.size();
        int n = mat[0].size();

        for(int k=0;k<4;k++) {

            if(mat == target) return true;

            //transpose
            for(int i=0;i<m;i++) {

                for(int j=i+1;j<n;j++) {

                    swap(mat[i][j],mat[j][i]);
                }
            }

            //reverse
            for(int i=0;i<m;i++) {

                reverse(mat[i].begin(),mat[i].end());
            }
        }

        return false;
    }
};