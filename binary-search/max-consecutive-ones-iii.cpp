class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_count = INT_MIN;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int count_zeros = 0;
        int first_idx = -1;

        while (r < n) {
            if (nums[r] == 0) {
                count_zeros++;
                if (count_zeros == 1) {
                    first_idx = r;
                }
                if (count_zeros > k) {
                    l = first_idx + 1;
                    r = first_idx;
                    count_zeros = 0;
                }
            }
            max_count = max(max_count, r - l + 1);
            r++;
        }
        return max_count;
    }
};