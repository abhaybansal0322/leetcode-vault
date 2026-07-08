class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n  = nums.size();
        vector<long long> cnt(k,0);
        vector<long long> ans(k,0);

        for(int i=0;i<n;i++)
        {
            nums[i] %= k;
            vector<long long> ncnt(k,0);
            ncnt[nums[i]]++;

            for(int x=0;x<k;x++)
            {
                ncnt[x * nums[i] % k] += cnt[x];
            }
            cnt = ncnt;

            for(int x=0;x<k;x++)
            {
                ans[x] += cnt[x];
            }
        }

        return ans;

        
    }
};