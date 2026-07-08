class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> rightPref(n,0),leftPref(n,0);

        auto closest = [&](int i) -> int{
            if(i==0) return 1;
            if(i == n-1) return n-2;

            long long leftDiff = 1LL*nums[i]-nums[i-1];
            long long rightDiff = 1LL*nums[i+1]-nums[i];

            if(leftDiff <= rightDiff) return i-1;
            return i+1;
        };

        for(int i=0;i<n-1;i++) {

            long long gap = 1LL*nums[i+1] - nums[i];

            long long costRight = (closest(i) == i+1) ? 1 : gap;
            rightPref[i+1] = rightPref[i]+costRight;
        }

        for(int i=1;i<n;i++) {

            long long gap = 1LL*nums[i] - nums[i-1];

            long long costLeft = (closest(i) == i-1) ? 1 : gap;
            leftPref[i] = leftPref[i-1]+costLeft;
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for(auto &q : queries) {
            int l = q[0],r = q[1];
            if(l<r) ans.push_back((int)rightPref[r]-rightPref[l]);
            else if(l>r) ans.push_back((int)leftPref[l]-leftPref[r]);
            else ans.push_back(0);
        }
        return ans;
    }
};