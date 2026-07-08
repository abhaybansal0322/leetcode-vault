class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {

        int n = costs.size();
        vector<pair<int,int>> mach(n);
        for(int i=0;i<n;i++) {
            mach[i] = {costs[i],capacity[i]};
        }

        sort(mach.begin(),mach.end());

        vector<int> maxPrefix(n);
        maxPrefix[0]=mach[0].second;
        for(int i=1;i<n;i++) {
            maxPrefix[i] = max(maxPrefix[i-1],mach[i].second);
        }

        long long maxi = 0;

        for(int i=0;i<n;i++) {

            if(mach[i].first<budget) {

                maxi = max(maxi,(long long)mach[i].second);
            }

            int rem = budget - mach[i].first;
            auto it = lower_bound(mach.begin(),mach.end(),rem,[](pair<int,int> a,int val) {
                return a.first < val;
            });

            int idx = distance(mach.begin(),it)-1;
            int validIdx =min(idx,i-1);

            if(validIdx >= 0) {

                maxi = max(maxi,(long long)mach[i].second+maxPrefix[validIdx]);
            }
        }

        return maxi;
    }
};