class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<vector<int>> child(n);
        for(int i=1;i<n;i++)
            child[parent[i]].push_back(i);

        vector<int> depth(n,0);
        depth[0] = 1;
        int h = 1;
        queue<int> q;
        q.push(0);

        while(!q.empty()) {
            int u = q.front(); q.pop();
            h = max(h,depth[u]);

            for(int v : child[u]) {
                depth[v] = depth[u]+1;
                q.push(v);
            }
        }

        long long ans = 0;
        for(int i=0;i<n;i++) {
            ans += 1LL*nums[i]*(h - depth[i]+1);
        }

        return ans;
    }
};