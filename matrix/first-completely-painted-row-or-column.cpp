class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        map<int, pair<int, int>> mp;

        vector<int> rows(m, 0);
        vector<int> cols(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[mat[i][j]].first = i;
                mp[mat[i][j]].second = j;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            rows[mp[arr[i]].first]++;
            cols[mp[arr[i]].second]++;

            if (rows[mp[arr[i]].first] == n) {
                return i;
            }

            if (cols[mp[arr[i]].second] == m) {
                return i;
            }
        }

        return -1;
    }
};

// class Solution {
// public:
//     int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
//         map<int,int> rows; // row -> no of checked
//         map<int,int> cols; // col -> no of checked

//         int m = mat.size();
//         int n = mat[0].size();

//         for(int i=0;i<arr.size();i++)
//         {
//             int val = arr[i];
//             for(int j=0;j<m;j++)
//             {
//                 for(int k=0;k<n;k++)
//                 {
//                     if(val == mat[j][k])
//                     {
//                         rows[j]++;
//                         cols[k]++;

//                         if(rows[j]==n || cols[k]==m)
//                         {
//                             return i;
//                         }
//                     }
//                 }
//             }
//         }

//         return -1;

//     }
// };