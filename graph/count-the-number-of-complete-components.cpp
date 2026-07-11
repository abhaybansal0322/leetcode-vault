class Solution {

    void dfs(int curr, unordered_set<int>& isVis, int (&compInfo)[2], unordered_map<int,vector<int>>& graph) {

        isVis.insert(curr);
        compInfo[0]++;
        compInfo[1] += graph[curr].size();

        for(int next : graph[curr]) {

            if(!isVis.count(next)) dfs(next,isVis,compInfo,graph);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>> graph;

        for(auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        unordered_set<int> isVis;
        int res = 0;

        for(int vertex=0;vertex<n;vertex++) {

            if(isVis.count(vertex)) continue;

            int compInfo[2] = {0,0};
            dfs(vertex,isVis,compInfo,graph);

            if(compInfo[0]*(compInfo[0]-1) == compInfo[1]) res++;
        }

        return res;
    }
};