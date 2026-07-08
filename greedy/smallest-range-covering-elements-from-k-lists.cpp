class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int maxEl = INT_MIN;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            q; //{minEl,listIdx,idx}
        vector<int> ans = {-100000, 100000};

        for (int i = 0; i < k; i++) {
            q.push({nums[i][0], i, 0});
            maxEl = max(maxEl, nums[i][0]);
        }

        while (!q.empty()) {
            vector<int> curr = q.top();
            q.pop();

            int minEl = curr[0];
            int currIdx = curr[1];
            int idx = curr[2];

            if ((maxEl - minEl) < (ans[1] - ans[0])) {
                ans[0] = minEl;
                ans[1] = maxEl;
            }

            if (idx + 1 < nums[currIdx].size()) {
                q.push({nums[currIdx][idx + 1], currIdx, idx + 1});
                maxEl = max(maxEl, nums[currIdx][idx + 1]);
            } else {
                break;
            }
        }
        return ans;
    }
};