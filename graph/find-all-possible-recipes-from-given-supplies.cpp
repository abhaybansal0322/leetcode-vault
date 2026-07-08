class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> st(supplies.begin(),supplies.end());
        int n = recipes.size();
        vector<int> inDeg(n,0);
        unordered_map<string,vector<int>> adj;

        for(int i=0;i<n;i++)
        {
            for(string& ing: ingredients[i])
            {
                if(!st.count(ing))
                {
                    adj[ing].push_back(i);
                    inDeg[i]++;
                }
            }
        }

        queue<int> que;

        for(int i=0;i<n;i++)
        {
            if(inDeg[i]==0)
            {
                que.push(i);
            }
        }

        vector<string> result;

        while(!que.empty())
        {
            int i = que.front();
            que.pop();
            string recipe = recipes[i];
            result.push_back(recipe);

            for(int &v : adj[recipe])
            {
                inDeg[v]--;
                if(inDeg[v]==0)
                {
                    que.push(v);
                }
            }

        }

        return result;
        
    }
};