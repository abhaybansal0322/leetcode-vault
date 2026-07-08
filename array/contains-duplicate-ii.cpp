class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, priority_queue<int>> mp;

        for (int i = 0; i < nums.size(); i++) {

            if ((int)mp[nums[i]].size() == 0) {

                mp[nums[i]].push(i);
            }

            else {

                int j = mp[nums[i]].top();

                if (abs(i - j) <= k) {
                    return true;
                }
                mp[nums[i]].push(i);
            }
        }

        return false;
    }
};