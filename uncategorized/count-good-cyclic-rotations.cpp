class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int h = n/2;

        long long tot = 0;
        for(int x : nums) tot+=x;

        long long win = 0;
        for(int i=0;i<h;i++) win += nums[i];

        int ans = 0;
        for(int r=0;r<n;r++) {
            if(2*win > tot) ans++;
            win -= nums[r];
            win += (nums[(r+h)%n]);
        }

        return ans;
    }
};