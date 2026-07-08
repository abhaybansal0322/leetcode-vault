class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& vis, int i) {
        // if (vis[i] == 1) {
        //     return;
        // }
        vis[i] = 1;
        for (int j = 0; j < isConnected[0].size(); j++) {
            if (isConnected[i][j] && !vis[j]) {
                dfs(isConnected, vis, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        vector<int> vis(isConnected.size() + 1, 0);

        for (int i = 0; i < isConnected.size(); i++) {
            if (!vis[i]) {
                dfs(isConnected, vis, i);
                ans++;
            }
        }
        return ans;
    }
};