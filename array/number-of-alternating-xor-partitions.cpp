class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {

        const int MOD = 1e9 + 7;
        int maxi = 200000;
        vector<int> cnt1(maxi,0),cnt2(maxi,0);

        cnt2[0] =1;

        int curr = 0;
        long long ans1 = 0, ans2 = 0;
        for(int & num : nums) {

            curr ^= num;
            int prev1 = curr^target1;

            if(prev1 < maxi) {

                ans1 = cnt2[prev1];
            } else {

                ans1 = 0;
            }

            int prev2 = curr^target2;

            if(prev2 < maxi) {

                ans2 = cnt1[prev2];
            } else {
                ans2=0;
            }

            cnt1[curr] = (cnt1[curr]+ans1)%MOD;
            cnt2[curr] = (cnt2[curr]+ans2)%MOD;
        }

        return (ans1+ans2)%MOD;
        
    }
};