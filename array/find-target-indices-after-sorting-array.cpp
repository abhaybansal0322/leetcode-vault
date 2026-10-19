class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;

        int cnt1 = 0;
        int cnt2 = 0;

        for(int num : nums) {
            if(num<target)  cnt1++;
            if(num == target) cnt2++;
        }

        for(int i=cnt1;i<cnt1+cnt2;i++) {
            res.push_back(i);
        }

        return res;
    }
};