class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0;i<n;i++) {

            for(int j=0;j<m;j++) {

                if(matrix[j][i] != 0 && j-1 >= 0)
                    matrix[j][i] += matrix[j-1][i];
            }
        }

        for(int i=0;i<m;i++) sort(matrix[i].rbegin(),matrix[i].rend());

        int maxArea = 0;
        for(int i=0;i<m;i++) {
            
            int b = 1;
            for(int j=0;j<n;j++) {

                int h = matrix[i][j];
                maxArea = max(maxArea,b*h);
                b++;
            }
        }

        return maxArea;

    }
};