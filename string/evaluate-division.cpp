class Solution {

    void dfs(unordered_map<string,vector<pair<string,double>>> &adj,string src,string des,double product,double &ans,unordered_set<string> &vis) {
        
        if(vis.find(src)!=vis.end())
            return;

        vis.insert(src);

        if(src == des) {

            ans = product;
            return;
        }

        for(auto& P : adj[src]) {

            string newSrc = P.first;
            double val = P.second;

            dfs(adj,newSrc,des,product*val,ans,vis);
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        int n = equations.size();
        vector<double> res;

        for(int i=0;i<n;i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }

        for(auto& query : queries)
        {
            double product = 1;
            double ans = -1;
            string src = query[0];
            string des = query[1];

            if(adj.find(src)==adj.end() || adj.find(des)==adj.end())
                res.push_back(ans);
            
            else {

                unordered_set<string> vis;
                dfs(adj,src,des,product,ans,vis);
                res.push_back(ans);
            }
        }

        return res;
    }
};