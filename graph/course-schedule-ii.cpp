class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {

        vector<int> result;
        unordered_map<int,vector<int>> adj;
        vector<int> inDeg(n,0);
        queue<int> que;

        for(int i=0;i<p.size();i++)
        {
            int a = p[i][0];
            int b = p[i][1];

            // b ---> a

            inDeg[a]++;
            adj[b].push_back(a);
        }

        for(int i=0;i<n;i++)
        {
            if(inDeg[i]==0)
            {
                que.push(i);
            }
        }

        while(!que.empty())
        {
            int u = que.front();
            que.pop();
            result.push_back(u);

            for(int &v : adj[u])
            {
                inDeg[v]--;
                if(inDeg[v]==0)
                {
                    que.push(v);
                }
            }
        }

        if(result.size()==n)
        {
            return result;
        }

        return {};
        
    }
};