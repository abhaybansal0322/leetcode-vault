class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> cnt(1001,0);
        vector<int> res;
        for(int i=0;i<nums1.size();i++) {
            cnt[nums1[i]]++;
        }

        for(auto& num : nums2) {
            if(cnt[num] != 0) {
                res.push_back(num);
                cnt[num]--;
            }
        }

        return res;
    }
};