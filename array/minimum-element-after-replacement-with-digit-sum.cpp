class Solution {
    int digitSum(int num) {
        return (
            (num/10000) +
            (num%10000 / 1000) +
            (num%1000 / 100) + 
            (num%100 / 10) +
            (num%10)
        );
    }
public:
    int minElement(vector<int>& nums) {
        
        int ans = INT_MAX;
        for(auto num : nums) {

            ans = min(ans,digitSum(num));
        }
        return ans;
    }
};