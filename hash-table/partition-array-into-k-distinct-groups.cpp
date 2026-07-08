class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        
        int n = nums.size();

        if(n%k != 0)    return false;

        int numOfGrps = n/k;
        unordered_map<int,int> mp;

        for(auto& num : nums) {

            mp[num]++;
            if(mp[num] > numOfGrps) return false;
        }

        return true;


    }
};