class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int row=0;
        int col=-1;
        vector<int> ans;
        int dir=1;
        while(rows>0 && cols>0)
        {
            for(int i=0;i<cols;i++)
            {
                col+=dir;
                ans.push_back(matrix[row][col]);
            }
            rows--;
            for(int i=0;i<rows;i++)
            {
                row += dir;
                ans.push_back(matrix[row][col]);
            }
            cols--;
            dir=dir*(-1);
            
        }
        return ans;
        
        
    }
};