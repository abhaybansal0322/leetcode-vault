// class Solution {
// public:
//     int minimumCost(vector<int>& nums, int k) {
//         int MOD = 1e9+7;
//         int cost = 1;
//         int avail = k;
//         int result = 0;

//         for(auto& num : nums) {

//             if(num > avail) {

//                 while(num > avail) {
//                     result = (0LL + result + cost)%MOD;
//                     avail += k;
//                     cost++;
//                 }
//                 avail -= num;

//             } else {

//                 avail -= num;
//             }
//         }

//         return result;
//     }
// };

class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int MOD = 1e9+7;
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long val;
        if(totalSum % k != 0) {
            val = (totalSum + k) / k;
        } else {
            val = (totalSum) / k;
        }
        val = val-1;

        val = (1LL * (val % MOD) * ((val + 1) % MOD))/2 % MOD;

        return val;
    }
};