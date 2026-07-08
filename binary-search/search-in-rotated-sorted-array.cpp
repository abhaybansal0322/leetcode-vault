class Solution {
    int findPivotIndex(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid element is greater than high, pivot must be to the right
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Else, pivot is at mid or to the left
            else {
                high = mid;
            }
        }
        // When low == high, it points to the pivot (smallest element)
        return low;
    }

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int idx = findPivotIndex(nums);

        int l = idx;
        int r = idx + n;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int i = mid % n;

            if (nums[i] == target)
                return i;

            else if (nums[i] < target)
                l = mid + 1;

            else
                r = mid - 1;
        }

        return -1;
    }
};