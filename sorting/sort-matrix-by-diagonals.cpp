class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<m;i++) {

            for(int j=0;j<n;j++) {

                mp[i-j].push_back(grid[i][j]);
            }
        }

        for(auto& it : mp) {

            if(it.first >= 0)   sort(begin(it.second),end(it.second));
            else    sort(begin(it.second),end(it.second),greater<int>());
        }

        for(int i=0;i<m;i++) {

            for(int j=0;j<n;j++) {

                grid[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }

        return grid;

        

    }
};