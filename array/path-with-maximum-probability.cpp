class Solution {
public:
    typedef pair<double, int> P;
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> adj;
        vector<double> result(n, 0);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        result[start] = 1;
        priority_queue<P> pq;
        pq.push({1.0, start});

        while (!pq.empty()) {
            int currNode = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();

            for (auto& temp : adj[currNode]) {
                double adjProb = temp.second;
                int adjNode = temp.first;

                if (currProb * adjProb > result[adjNode]) {
                    result[adjNode] = currProb * adjProb;
                    pq.push({currProb * adjProb, adjNode});
                }
            }
        }
        return result[end];
    }
};