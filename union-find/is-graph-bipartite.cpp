class Solution {
    bool checkBip(vector<vector<int>>& graph, int u, vector<int>& color, int currCol) {
        color[u] = currCol;

        for (int &v : graph[u]) {
            if (color[v] == currCol)
                return false;

            else if (color[v] == -1) {
                if (!checkBip(graph, v, color, 1 - currCol))
                    return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!checkBip(graph, i, color, 1)) 
                    return false;
            }
        }

        return true;   
    }
};
