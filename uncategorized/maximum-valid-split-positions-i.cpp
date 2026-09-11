class Solution {
    int score(vector<int>& A) {
        int m = A.size();
        vector<int> suff(m+1,0);
        for(int i=m-1;i>=0;i--) suff[i] = gcd(A[i],suff[i+1]);

        int pre = 0;
        int cnt = 0;

        for(int i=0;i+1<m;i++) {
            pre = gcd(pre,A[i]);

            if(pre == suff[i+1])    cnt++;
        }

        return cnt;
    }
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = score(nums);

        vector<int> arr;
        for(int k=0;k<n;k++) {
            arr.clear();
            for(int i=0;i<n;i++) {
                if(i != k)  arr.push_back(nums[i]);
            }

            ans = max(ans,score(arr));
        }

        return ans;
    }
};