class Solution {
    typedef long long ll;
    typedef pair<ll,string> P;
    const ll INF = 1e10;
    unordered_map<string,vector<pair<string,ll>>> adj;
    set<int> validlen;
    vector<ll> dp;

    unordered_map<string,unordered_map<string,ll>> dpDijk;

    ll dijkstra(string & start, string& end) {

        if(dpDijk[start].count(end))    return dpDijk[start][end];

        priority_queue<P,vector<P>,greater<P>> pq;
        unordered_map<string,ll> res;
        pq.push({0,start});
        res[start] = 0;

        while(!pq.empty()) {

            ll curr = pq.top().first;
            string u = pq.top().second;
            pq.pop();

            if(u == end) break;

            for(auto& edge : adj[u]) {

                ll val = edge.second;
                string v = edge.first;

                if(!res.count(v) || curr + val < res[v]) {

                    res[v] = curr+val;
                    pq.push({curr+val,v});
                }
            }
        }

        ll ans = res.count(end) ? res[end] : INF;

        return dpDijk[start][end] = ans;
    }

    ll solve(int idx,string& source, string& target) {

        ll minCost = INF;

        if(idx >= source.length())  return 0;

        if(dp[idx] != -1)   return dp[idx];

        if(source[idx] == target[idx]) {

            minCost = solve(idx+1,source,target);
        }

        for(auto& len : validlen) {

            if(idx + len > source.length()) break;

            string s1 = source.substr(idx,len);
            string s2 = target.substr(idx,len);

            if(!adj.count(s1))  continue;

            ll val = dijkstra(s1,s2);

            minCost = min(minCost, val+solve(idx+len,source,target));
        }

        return dp[idx] = minCost;
    }

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        
        dp.assign(10001,-1);
        for(int i=0;i<original.size();i++) {

            adj[original[i]].push_back({changed[i],cost[i]});
        }

        for(auto& s : original) {

            validlen.insert(s.length());
        }

        ll res = solve(0,source,target);

        return res == INF ? -1 : res;

    }
};