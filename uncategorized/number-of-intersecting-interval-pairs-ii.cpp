class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> ends(n);
        for(int i=0;i<n;i++) {
            ends[i] = intervals[i][1];
        }
        sort(ends.begin(),ends.end());
        long long tot = 1LL*n*(n-1)/2;
        long long dis = 0;

        for(int i=0;i<n;i++) {
            int start = intervals[i][0];
            dis += (lower_bound(ends.begin(),ends.end(),start) - ends.begin());
        }

        return tot - dis;
    }
};