class Solution {
public:
    struct myCompare {

        bool operator()(const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1])
                return a[0] > b[0];

            return a[1] > b[1];
        }
    };

    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // int cnt=0;

        sort(intervals.begin(), intervals.end());
        priority_queue<vector<int>, vector<vector<int>>, myCompare> q;

        for (int i = 0; i < n; i++) {
            if (!q.empty() && intervals[i][0] > q.top()[1]) {
                q.pop();
            }
            q.push(intervals[i]);
        }
        return q.size();
    }
};