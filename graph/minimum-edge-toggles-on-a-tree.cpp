class Solution {
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {

        vector<int> D(n,0);
        int cnt = 0;

        for(int i=0;i<n;i++) {

            if(start[i]!=target[i]) {

                D[i] = 1;
                cnt++;
            }
        }

        if(cnt%2 != 0) return {-1};
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++) {

            adj[edges[i][1]].push_back({edges[i][0],i});
            adj[edges[i][0]].push_back({edges[i][1],i});
        }

        vector<int> order;
        order.reserve(n);
        vector<int> parent(n,-1),parentIdx(n,-1);
        vector<bool> vis(n,false);

        queue<int> Q;
        Q.push(0);
        vis[0]=true;

        while(!Q.empty()) {

            int u = Q.front(); Q.pop();
            order.push_back(u);

            for(auto& edge : adj[u]) {

                int v = edge.first;
                int idx = edge.second;

                if(!vis[v]) {

                    vis[v] = true;
                    parent[v]=u;
                    parentIdx[v]=idx;
                    Q.push(v);
                }
            }
        }

        vector<int> ans;
        for(int i=n-1;i>=0;i--) {

            int u = order[i];
            if(u == 0) continue;

            if(D[u] == 1) {

                int idx = parentIdx[u];
                ans.push_back(idx);

                int p = parent[u];
                D[p] = 1-D[p];
            }
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};