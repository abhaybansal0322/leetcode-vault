class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        vector<int> result;
        result.reserve(nums.size());
        for(auto& num : nums) {

            if(num == 2)    result.push_back(-1);
            else {

                int val = num - (((num+1) & -(num+1)) >> 1);
                result.push_back(val);
            }
        }

        return result;
    }
};