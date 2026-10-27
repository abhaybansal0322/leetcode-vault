class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m,string(n,'#'));
        
        res[0] = string(n,'.');

        for(int row=1;row<m;row++) {
            res[row][n-1] = '.';
        }

        return res;
    }
};