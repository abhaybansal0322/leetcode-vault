class Solution {
    const long long INF = 1e18;
    vector<vector<long long>> dis;

    void floyd(vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        dis.assign(26,vector<long long>(26,INF));
        for(int i=0;i<26;i++) {

            dis[i][i] = 0;
        }

        for(int i=0;i<original.size();i++) {

            char u = original[i];
            char v = changed[i];
            long long val = cost[i];
            int idxu = u - 'a';
            int idxv = v - 'a';

            dis[idxu][idxv] = min(dis[idxu][idxv],val);
        }

        for(int via=0;via<26;via++) {

            for(int i=0;i<26;i++) {

                for(int j=0;j<26;j++) {

                    if(dis[i][via] < INF && dis[via][j] < INF) {

                        dis[i][j] = min(dis[i][j],dis[i][via]+dis[via][j]);
                    }
                }
            }
        }
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        int n = source.length();
        long long ans = 0;
        floyd(original,changed,cost);

        for(int i=0;i<n;i++) {

            char u = source[i];
            char v = target[i];

            int idxu = u-'a';
            int idxv = v-'a';

            if(u == v) continue;

            if(dis[idxu][idxv] == INF) return -1;

            ans += dis[idxu][idxv];
        }

        return ans;
    }
};