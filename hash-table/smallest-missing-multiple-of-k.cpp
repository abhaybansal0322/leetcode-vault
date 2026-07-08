class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bool seen[201] = {};
        for (int x : nums) seen[x] = true;
        for (int i = k;; i += k)
            if (!seen[i]) return i;

        return -1;
    }
};