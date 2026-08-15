class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int Xor = 0;
        bool allZero = true;
        int n = nums.size();
        for(auto& num : nums) {

            if(num!=0) allZero = false;
            Xor ^= num;
        }

        if(Xor != 0) return n;
        else if(!allZero)   return n-1;

        return 0;
    }
};