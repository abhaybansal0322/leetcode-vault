class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        map<int,int> mp;
        for(auto& num : nums) {
            mp[num]++;
        }

        while(!mp.empty()) {

            for(auto it = mp.begin(); it != mp.end(); ) {
                int u = it->first;

                res.push_back(u);

                if(--it->second == 0) {
                    it = mp.erase(it);
                } else {
                    ++it;
                }
            }
        }

        return res;
    }
};