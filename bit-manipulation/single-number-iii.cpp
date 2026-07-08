// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
        
//         unsigned int x = 0;
//         int a=0,b=0;

//         for(auto& num : nums) x ^= num;

//         x = x & -x;

//         for(auto& n: nums) {

//             if(n & x)   a = a^n;
//             else    b = b^n;
//         }

//         return {a,b};

//     }
// };


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int x = 0;
        int a = 0, b = 0;

        // Step 1: XOR all numbers
        for (auto& num : nums) 
            x ^= num;

        // Step 2: Safely get the rightmost set bit
        unsigned int mask = x & (-x);

        // Step 3: Partition numbers into two groups
        for (auto& n : nums) {
            if (n & mask) 
                a ^= n;
            else 
                b ^= n;
        }

        return {a, b};
    }
};
