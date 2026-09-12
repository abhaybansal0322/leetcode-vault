class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> pos;
        for(int i=0;i<n;i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = 0;
        for(auto& [val,idx] : pos) {
            if(idx.size() < 3) continue;
            int d = idx[1] - idx[0];
            bool ok = true;

            for(int j=2;j<idx.size();j++) {
                if(idx[j]-idx[j-1]!=d) {
                    ok = false;
                    break;
                }
            }

            if(ok) ans++;
        }

        return ans;
    }
};