class Solution {
    const int MOD = 1e9 + 7;

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        vector<int> depth(n + 1, 0);
        vector<vector<int>> parent(n + 1, vector<int>(LOG, 0));

        // BFS to calculate depth and immediate parent
        queue<int> q;
        q.push(1);
        parent[1][0] = 0;

        vector<int> visited(n + 1, 0);
        visited[1] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int child : adj[node]) {
                if (!visited[child]) {
                    visited[child] = 1;

                    depth[child] = depth[node] + 1;
                    parent[child][0] = node;

                    q.push(child);
                }
            }
        }

        // Binary lifting table
        for (int j = 1; j < LOG; j++) {
            for (int node = 1; node <= n; node++) {
                int midParent = parent[node][j - 1];
                parent[node][j] = parent[midParent][j - 1];
            }
        }

        // Precompute powers of 2
        vector<int> power(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            power[i] = (2LL * power[i - 1]) % MOD;
        }

        vector<int> answer;

        for (auto &query : queries) {
            int u = query[0];
            int v = query[1];

            int common = lca(u, v, depth, parent, LOG);

            int pathLength = depth[u] + depth[v] - 2 * depth[common];

            if (pathLength == 0) {
                answer.push_back(0);
            } else {
                answer.push_back(power[pathLength - 1]);
            }
        }

        return answer;
    }

private:
    int lca(int u, int v,
            vector<int>& depth,
            vector<vector<int>>& parent,
            int LOG) {

        // Make u the deeper node
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        // Bring u to the same depth as v
        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = parent[u][j];
            }
        }

        if (u == v) {
            return u;
        }

        // Move both nodes upward
        for (int j = LOG - 1; j >= 0; j--) {
            if (parent[u][j] != parent[v][j]) {
                u = parent[u][j];
                v = parent[v][j];
            }
        }

        return parent[u][0];
    }
};