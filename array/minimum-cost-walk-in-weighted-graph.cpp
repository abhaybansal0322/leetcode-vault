class Solution {

    vector<int> parent;

    int Find(int x)
    {
        if(parent[x]==x)
            return x;

        return parent[x]=Find(parent[x]);
    }

    void Union(int x,int y)
    {
        parent[y]=x;
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int> cost(n);
        vector<int> result;

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            cost[i]=-1;
        }

        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int parent_u = Find(u);
            int parent_v = Find(v);

            if(parent_u!=parent_v)
            {
                cost[parent_u] &= cost[parent_v];
                Union(parent_u,parent_v);
            }

            cost[parent_u] &= w;
        }

        for(auto& q : query)
        {
            int s = q[0];
            int z = q[1];

            int parent_s = Find(s);
            int parent_z = Find(z);
            if(s==z)
            {
                result.push_back(0);
            }
            else if(parent_s!=parent_z)
            {
                result.push_back(-1);
            }
            else{
                result.push_back(cost[parent_s]);
            }
        }

        return result;
        
    }
};