class Solution {

    struct PairHash {
        size_t operator()(const pair<int,int>& p) const {
            return ((size_t)p.first << 32) ^ (unsigned int)p.second;
        }
    };

public:
    int maxBalancedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<pair<int,int>, int, PairHash> mp;
        mp[{0,0}] = -1;
        int x = 0,even=0,odd=0;
        int ans = 0;

        for(int i=0;i<n;i++) {

            x = x ^ nums[i];

            if(nums[i]%2 == 0)  even++;
            else    odd++;

            int diff = even - odd;

            pair<int,int> key = {x,diff};

            if(mp.find(key) != mp.end()) {

                ans = max(ans,i - mp[key]);
            } else {

                mp[key] = i;
            }
        }

        return ans;
    }
};