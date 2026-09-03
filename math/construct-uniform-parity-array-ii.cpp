class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minElement = *min_element(nums1.begin(),nums1.end());

        if(minElement&1)    return true;

        for(auto& num : nums1) {
            if(num&1)   return false;
        }

        return true;
    }
};