class SegTree {
public:
    int n;
    vector<long long> tree;

    SegTree(int n) {
        this->n = n;
        tree.resize(4 * n, 0);
    }

    void update(int idx, long long val, int node, int start, int end) {
        if (start == end) {
            tree[node] = max(tree[node], val);
            return;
        }

        int mid = (start + end) / 2;
        if (idx <= mid)
            update(idx, val, 2 * node, start, mid);
        else
            update(idx, val, 2 * node + 1, mid + 1, end);

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    long long query(int l, int r, int node, int start, int end) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;
        return max(
            query(l, r, 2 * node, start, mid),
            query(l, r, 2 * node + 1, mid + 1, end)
        );
    }

    void update(int idx, long long val) {
        update(idx, val, 1, 1, n);
    }

    long long query(int l, int r) {
        if (l > r) return 0;
        return query(l, r, 1, 1, n);
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = nums.size();

        // coordinate compression
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = vals.size();

        auto getPos = [&](int x) {
            return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
        };

        SegTree downSeg(m), upSeg(m);

        vector<long long> up(n, 0), down(n, 0);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int j = i - k;
            if (j >= 0) {
                int p = getPos(nums[j]);

                downSeg.update(p, down[j]);
                upSeg.update(m - p + 1, up[j]);
            }

            int p = getPos(nums[i]);

            // equivalent of Fenwick prefix queries
            long long bestDownLess = downSeg.query(1, p - 1);
            long long bestUpGreater = upSeg.query(1, m - p);

            up[i] = nums[i];
            if (bestDownLess > 0)
                up[i] = max(up[i], (long long)nums[i] + bestDownLess);

            down[i] = nums[i];
            if (bestUpGreater > 0)
                down[i] = max(down[i], (long long)nums[i] + bestUpGreater);

            ans = max(ans, max(up[i], down[i]));
        }

        return ans;
    }
};