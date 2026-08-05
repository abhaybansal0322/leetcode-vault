class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        unordered_map<int,vector<int>> adj;
        vector<int> inDeg(n,0);
        for(auto& inn : invocations) {
            int u = inn[0];
            int v = inn[1];

            adj[u].push_back(v);
            inDeg[v]++;
        }

        vector<int> susp(n,0);
        susp[k] = 1;
        queue<int> Q;
        Q.push(k);

        while(!Q.empty()) {
            int curr = Q.front();   Q.pop();

            for(int &v : adj[curr]) {
                inDeg[v]--;
                if(!susp[v]) {
                    susp[v] = 1;
                    Q.push(v);
                }
            }
        }

        vector<int> res;
        bool cannotRem = false;
        for(int i=0;i<n;i++) {

            if(susp[i] && (inDeg[i] > 0)) {
                cannotRem = true;
                break;
            }

            if(!susp[i])    res.push_back(i);
        }

        if(cannotRem) {

            vector<int> ans(n);
            iota(ans.begin(),ans.end(),0);
            return ans;
        }

        return res;
    }
};