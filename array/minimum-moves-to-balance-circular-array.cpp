class Solution {
public:
    long long minMoves(vector<int>& balance) {

        long long total= 0;
        int negIdx = -1;
        int n = balance.size();

        for(int i=0;i<n;i++) {

            total += balance[i];
            if(balance[i] < 0) {

                negIdx = i;
            }
        }

        if(total < 0) return -1;
        if(negIdx == -1) return 0;

        long long val = -1LL * balance[negIdx];

        vector<pair<int,int>> supp;

        for(int i=0;i<n;i++) {

            if(balance[i] > 0) {

                int d = abs(i - negIdx);
                int dist = min(d,n-d);

                supp.push_back({dist,balance[i]});
            }
        }

        sort(supp.begin(),supp.end());

        long long ans = 0;
        for(auto& s : supp) {

            long long take = min(val,(long long)s.second);
            ans += (take*s.first);

            val -= take;
                if(val == 0) break;
        }

        return ans;

        
    }
};