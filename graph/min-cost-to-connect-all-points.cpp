class Solution {
    typedef pair<int,int> P;

    int primsAlgo(vector<vector<pair<int,int>>>& adj,int V)
    {
        priority_queue<P,vector<P>,greater<P>> pq; // wt,ptIdx
        vector<bool> inMst(V,false);
        pq.push({0,0});
        int sum = 0;

        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int wt = curr.first;
            int node = curr.second;

            if(inMst[node]==true)
                continue;
            
            sum += wt;
            inMst[node]=true;

            for(auto& v : adj[node])
            {
                int w = v.first;
                int n = v.second;

                if(inMst[n]==false)
                {
                    pq.push({w,n});
                }
            }
        }

        return sum;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<pair<int,int>>> adj(V); //u---> wt,v
        
        for(int i=0;i<V;i++)
        {
            for(int j=i+1;j<V;j++)
            {
                int wt = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({wt,j});
                adj[j].push_back({wt,i}); 
            }
        }

        return primsAlgo(adj,V);
    }
};