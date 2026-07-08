class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        int res= 0;
        int n = nums.size();
        for(int i=0;i<32;i++) {

            int sum = 0;
            for(auto& num : nums) {

                sum += ((num>>i) & 1);
            }

            res += (sum*(n-sum));
        }

        return res;
    }
};