class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        
        int idx = -1;

        for(int i=n-1;i>=1;i--) {

            if(nums[i-1] < nums[i]) {

                idx = i-1;
                break;
            }
        }

        if(idx == -1) {

            reverse(nums.begin(),nums.end());
            return;
        }

        int swap_idx = -1;

        for(int i=n-1;i>idx;i--) {

            if(nums[i]>nums[idx]) {

                swap_idx = i;
                break;
            }
        }

        swap(nums[idx],nums[swap_idx]);

        reverse(nums.begin()+idx+1,nums.end());

        
    }
};