class Solution {
    int findMaxElement(vector<vector<int>>& mat,int col,int n)
    {
        int idx = -1;
        int Max = -1;
        for(int i=0;i<n;i++)
        {
            if(mat[i][col]>Max)
            {
                Max = mat[i][col];
                idx = i;
            }
        }

        return idx;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int l = 0;
        int r = m-1;

        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int maxRow = findMaxElement(mat,mid,n);

            int left = (mid-1 >= 0) ? mat[maxRow][mid-1] : -1;
            int right = (mid+1 < m) ? mat[maxRow][mid+1] : -1;

            if(mat[maxRow][mid] > left  && mat[maxRow][mid] > right)
                return {maxRow,mid};

            else if(mat[maxRow][mid] < left)
                r = mid-1;

            else
                l = mid+1;

        }

        return {-1,-1};
    }
};