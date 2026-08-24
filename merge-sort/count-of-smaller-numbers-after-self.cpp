class Solution {
    static const int N = 20002;
    int tree[N];

    void update(int i) { for (; i < N; i += i & -i) tree[i]++; }
    int query(int i) { int s = 0; for (; i > 0; i -= i & -i) s += tree[i]; return s; }

public:
    vector<int> countSmaller(vector<int>& nums) {
        memset(tree, 0, sizeof(tree));
        int n = nums.size();
        vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {   // right to left
            int idx = nums[i] + 10001;
            res[i] = query(idx - 1);         // count of values strictly smaller
            update(idx);                     // now insert nums[i] itself
        }
        return res;
    }
};