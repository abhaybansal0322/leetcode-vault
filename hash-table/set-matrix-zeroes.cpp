class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        stack<pair<int,int>> st;
        int m= matrix.size();
        int n= matrix[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                    st.push({i,j});
            }
        }

        while(!st.empty())
        {
            auto val = st.top();
            st.pop();

            int row = val.first;
            int col = val.second;

            for(int i=row;i<m;i++)
            {
                matrix[i][col]=0;
            }
            for(int i=row;i>=0;i--)
            {
                matrix[i][col]=0;
            }
            for(int j=col;j<n;j++)
            {
                matrix[row][j]=0;
            }
             for(int j=col;j>=0;j--)
            {
                matrix[row][j]=0;
            }
        }
    }
};