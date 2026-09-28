class Solution {
    vector<int> cnt;

    bool canCauseConflict(int v) {
        for(int x=1;x<=500;x++) {
            if(cnt[x] == 0) continue;

            //case 1 - x+y = v
            int y = v-x;
            if(y >= 1) {
                if(x == y) {
                    if(cnt[x]>=2)   return true;
                } else {
                    if(cnt[y]>=1)   return true;
                }
            }

            //case 2 - x+v = s
            int s = x+v;
            if(s<=500 && cnt[s]>=1) {
                if(x!=v) {
                    return true;
                }
                else {
                    if(cnt[x]>=2) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
public:
    int maxSubarray(vector<int>& nums) {
        cnt.resize(501,0);
        int n = nums.size();
        int l = 0;
        int best = 0;

        for(int r=0;r<n;r++) {
            int v = nums[r];
            cnt[v]++;
            
            while(canCauseConflict(v)) {
                cnt[nums[l]]--;
                l++;
            }

            best = max(best,r-l+1);
        }

        return best;
    }
};