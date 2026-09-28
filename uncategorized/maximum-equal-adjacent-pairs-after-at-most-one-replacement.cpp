class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int cnt = 0;
        unordered_map<int,unordered_map<int,int>> mp;
        for(int i=1;i<=n-1;i++) {
            int u = nums[i-1];
            int v = nums[i];

            if(u>v) {
                swap(u,v);
            }

            if(u == v) cnt++;
            else mp[u][v]++;
            res = max(res,mp[u][v]);
        }

        return res+cnt;
    }
};