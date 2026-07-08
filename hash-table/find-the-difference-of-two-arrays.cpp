class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // To store the final result
        vector<vector<int>> res(2);

        // Sets to store unique elements of nums1 and nums2
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());

        // Find elements in nums1 that are not in nums2
        for (int num : set1) {
            if (set2.find(num) == set2.end()) {
                res[0].push_back(num);
            }
        }

        // Find elements in nums2 that are not in nums1
        for (int num : set2) {
            if (set1.find(num) == set1.end()) {
                res[1].push_back(num);
            }
        }

        return res;
    }
};
