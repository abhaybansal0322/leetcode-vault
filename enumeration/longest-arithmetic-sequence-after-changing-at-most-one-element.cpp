class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        int m = n-1;

        if(n<=3) return n;

        vector<long long> diff(m);
        for(long long i=0;i<n-1;i++) {
            diff[i] = nums[i+1]-nums[i];
        }

        vector<long long> L(m,1),R(m,1);

        for(long long i=1;i<m;i++) {

            if(diff[i-1] == diff[i]) {

                L[i] = L[i-1]+1;
            }
        }

        for(long long i=m-2;i>=0;i--) {

            if(diff[i+1] == diff[i]) {

                R[i] = R[i+1]+1;
            }
        }

        long long maxLen = 1;

        for(long long i=0;i<m;i++) {

            long long val = diff[i];
            long long len = L[i];
            long long s = i-len+1;
            long long e = i;

            long long curr = len;
            if(s>0 || e<m-1) {

                curr = len+1;
            }
            maxLen = max(curr,maxLen);

            if(e+2<m && (diff[e+1]+diff[e+2]) == 2LL*val) {
                long long extended = len+2;

                if(e+3 < m && diff[e+3] == val) {

                    extended += R[e+3];
                }
                maxLen = max(maxLen,extended);
            }

            if(s-2 >=0 && (diff[s-1]+diff[s-2]) == 2LL*val) {

                long long extended = len+2;

                if(s-3>=0 && diff[s-3]==val) {

                    extended += L[s-3];
                }
                maxLen = max(maxLen,extended);
            }
        }

        return maxLen+1;
    }
};