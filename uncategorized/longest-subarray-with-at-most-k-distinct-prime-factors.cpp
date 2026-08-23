class Solution {
    const int MAXN = 100000;
    vector<int> spf;

    void preProc() {
        for(int i=0;i<=MAXN;i++) {
            spf[i] = i;
        }

        for(int i=2;i*i<=MAXN;i++) {
            if(spf[i] == i) {
                for(int j=i*i;j<=MAXN;j+=i) {
                    if(spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int res = INT_MIN;
        int l = 0;
        int r = 0;
        vector<int> cnt(MAXN+1,0);
        int dis = 0;
        spf.assign(MAXN+1,-1);
        preProc();

        auto add = [&](int x) {
            while(x>1) {
                int p = spf[x];
                if(cnt[p]++ == 0) dis ++;
                while (x % p == 0) x /= p;
            }
        };

        auto erase = [&](int x) {
            while(x>1) {
                int p = spf[x];
                if(--cnt[p] == 0) dis --;
                while (x % p == 0) x /= p;
            }
        };

        while(r<n) {
            add(nums[r]);
            while(dis > k && l <= r) {
                erase(nums[l]);
                l++;
            }
            res = max(res,r-l+1);
            r++;
        }

        return res;

    }
};