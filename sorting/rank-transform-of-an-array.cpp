class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) {
            return {};
        }

        vector<int> ans(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;

        for (int i = 0; i < n; i++) {
            q.push({arr[i], i});
        }
        int curr = q.top().first;
        int rank = 1;

        while (!q.empty()) {
            int element = q.top().first;
            int idx = q.top().second;
            q.pop();

            if (element != curr) {
                rank++;
            }

            ans[idx] = rank;
            curr = element;
        }
        return ans;
    }
};