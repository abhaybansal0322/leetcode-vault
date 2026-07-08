class Solution {

    bool isCycle(vector<vector<int>>& graph,int u,vector<bool>& vis,vector<bool>& inRec)
    {
        vis[u]=true;
        inRec[u]=true;

        for(auto &v : graph[u])
        {
            if(vis[v]==false && isCycle(graph,v,vis,inRec))
            {
                return true;
            }
            else if(inRec[v])
            {
                return true;
            }
        }

        inRec[u]=false;
        return false;

    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<bool> vis(n,false);
        vector<bool> inRec(n,false);
        vector<int> result;

        for(int i=0;i<n;i++)
        {
            if(!isCycle(graph,i,vis,inRec))
            {
                result.push_back(i);
            }
        }

        return result;

    }
};