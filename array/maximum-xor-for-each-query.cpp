// class Solution {
// public:
//     vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
//         int n=nums.size();
//         vector<int> result;

//         int XOR=0;
//         for(int i=0;i<n;i++)
//         {
//             XOR ^= nums[i];
//         }

//         int mask = ((1 << maximumBit) - 1);

//         for(int i=0;i<n;i++)
//         {
//             int k = XOR ^ mask;
//             result.push_back(k);
//             XOR ^= nums[n-i-1];
//         }

//         return result;
   

//     }
// };

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        vector<int> prefixXOR(n);
        prefixXOR[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixXOR[i] = prefixXOR[i - 1] ^ nums[i];
        }

        vector<int> ans(n);
        int mask = (1 << maximumBit) - 1;

        for (int i = 0; i < n; i++) {
            // find k to maximize value
            int currentXOR = prefixXOR[n - 1 - i];
            ans[i] = currentXOR ^ mask;
        }

        return ans;
    }
};