// TC --> O(Q*logN*logN)
// SC --> O(N)

/* -------------------------------------------- */

class Solution {
    vector<int> segmentTree;

    void buildSegmentTree(int i, int l, int r, vector<int>& heights) {
        if (l == r) {
            segmentTree[i] = l;
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, heights);
        buildSegmentTree(2 * i + 2, mid + 1, r, heights);

        int left = segmentTree[2 * i + 1];
        int right = segmentTree[2 * i + 2];

        segmentTree[i] = (heights[left] >= heights[right]) ? left : right;
    }

    int RMIQ(int start, int end, int i, int l, int r, vector<int>& heights) {
        if (r < start || l > end) {
            return -1;
        }

        if (l >= start && r <= end) {
            return segmentTree[i];
        }
        int mid = l + (r - l) / 2;

        int left = RMIQ(start, end, 2 * i + 1, l, mid, heights);
        int right = RMIQ(start, end, 2 * i + 2, mid + 1, r, heights);

        if (left == -1)
            return right;
        if (right == -1)
            return left;

        return (heights[left] >= heights[right]) ? left : right;
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        int n = heights.size();
        segmentTree.resize(4 * n);
        buildSegmentTree(0, 0, n - 1, heights);
        vector<int> ans;

        for (auto& query : queries) {
            int maxIdx = max(query[0], query[1]);
            int minIdx = min(query[0], query[1]);
            if (query[0] == query[1]) {
                ans.push_back(query[0]);
            } else if (heights[maxIdx] > heights[minIdx]) {
                ans.push_back(maxIdx);
            } else {
                int l = maxIdx + 1;
                int r = n - 1;
                int result = INT_MAX;

                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    int idx = RMIQ(l, mid, 0, 0, n - 1, heights);

                    if (heights[idx] > max(heights[minIdx], heights[maxIdx])) {
                        result = idx;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }

                if (result == INT_MAX) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(result);
                }
            }
        }

        return ans;
    }
};