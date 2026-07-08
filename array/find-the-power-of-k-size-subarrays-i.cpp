class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            int temp = i;
            bool valid = true;

            while (cnt < k - 1) {
                if (nums[temp + 1] != nums[temp] + 1) {
                    valid = false;
                    break;
                }
                cnt++;
                temp++;
            }

            if (valid) {
                res.push_back(nums[temp]);
            } else {
                res.push_back(-1);
            }

            if (res.size() == n - k + 1) {
                break;
            }
        }

        return res;
    }
};