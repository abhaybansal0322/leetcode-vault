class Solution {
public:
    int minimumCost(vector<int>& nums) {
        
        int n = nums.size();
        int ans = nums[0];
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for(int i=1;i<n;i++) {
            
            int num = nums[i];
            if(num < min1) {

                min2 = min1;
                min1 = num;
            }
            else if(num < min2) {

                min2 = num;
            }
        }

        return ans+min1+min2;

    }
};