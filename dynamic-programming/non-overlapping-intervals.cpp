class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int toRemove = 0;
        sort(intervals.begin(),intervals.end(),[&](auto &arr1, auto &arr2) {
            if(arr1[1] == arr2[1]) return arr1[0]>arr2[0];
            return arr1[1]<arr2[1];
        });

        int n = intervals.size();
        int currentTime = intervals[0][1];
        for(int i=1;i<n;i++) {

            if(currentTime <= intervals[i][0]) {
                currentTime = intervals[i][1];
            } else {
                toRemove++;
            }
        }

        return toRemove;
    }
};