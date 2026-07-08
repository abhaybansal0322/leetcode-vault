class Solution {

    bool isCycle(unordered_map<int, vector<int>>& adj, int u, vector<bool>& vis,
                 vector<bool>& inRec) {
        vis[u] = true;
        inRec[u] = true;

        for (int& v : adj[u]) {
            if (!vis[v] && isCycle(adj, v, vis, inRec)) {
                return true;
            } else if (inRec[v] == true) {
                return true;
            }
        }

        inRec[u] = false;
        return false;
    }

public:
    bool canFinish(int n, vector<vector<int>>& p) {

        vector<bool> vis(n, false);
        vector<bool> inRec(n, false);
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < p.size(); i++) {
            int v = p[i][0];
            int u = p[i][1];

            adj[u].push_back(v);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i] && isCycle(adj, i, vis, inRec))
                return false;
        }

        return true;
    }
};

// class Solution {

//     bool topologicalSort(unordered_map<int,vector<int>>& adj,int
//     n,vector<int>& inDeg)
//     {
//         queue<int> que;
//         int count = 0;
//         for(int i=0;i<n;i++)
//         {
//             if(inDeg[i]==0)
//             {
//                 que.push(i);
//                 count++;
//             }
//         }

//         while(!que.empty())
//         {
//             int u = que.front();
//             que.pop();

//             for(int &v : adj[u])
//             {
//                 inDeg[v]--;
//                 if(inDeg[v]==0)
//                 {
//                     que.push(v);
//                     count++;
//                 }
//             }
//         }

//         return (count==n);
//     }

// public:
//     bool canFinish(int n, vector<vector<int>>& p) {
//         unordered_map<int,vector<int>> adj;
//         vector<int> inDeg(n,0);

//         for(int i=0;i<p.size();i++)
//         {
//             int a = p[i][0];
//             int b = p[i][1];

//             // b ---> a

//             inDeg[a]++;
//             adj[b].push_back(a);
//         }

//         return topologicalSort(adj,n,inDeg);

//     }
// };