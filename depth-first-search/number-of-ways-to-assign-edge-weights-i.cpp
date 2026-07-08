class Solution {
    int qpow(int a,int b,int mod) {

        int ans = 1;
        while(b>0) {

            if(b&1) {

                ans = 1LL*ans*a%mod;
            }
            b>>=1;
            a = 1LL*a*a%mod;
        }

        return ans;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        
        const int mod = 1e9+7;
        int n = edges.size()+1;
        vector<vector<int>> adj(n+1);

        for(auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int level = 0;
        queue<pair<int,int>> Q;
        Q.push({1,-1});

        while(!Q.empty()) {

            int N = Q.size();
            while(N--) {

                auto[u,v]  = Q.front(); Q.pop();

                for(auto& x : adj[u]) {

                    if(x != v) {

                        Q.push({x,u});
                    }
                }
            }
            level++;
        }

        level = level-1;

        return qpow(2,level-1,mod);
    }
};