class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long int res = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int idx =
                lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) -
                nums.begin(); // gives first num not less than lower - nums[i] 
            int x = idx - 1 - i;

            idx =
                upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) -
                nums.begin(); //gives num just greater than upper - nums[i]

            int y = idx - 1 - i;

            res += (y - x);
        }

        return res;
    }
};