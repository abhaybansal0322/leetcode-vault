class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        vector<bool> proc(100001,false);
        int op = 0;
        int n = nums.size();

        for(int i=0;i<n;i++) {

            if(nums[i]!=target[i]) {

                if(!proc[nums[i]]) {

                    proc[nums[i]] = true;
                    op++;
                }
            }
        }

        return op;
    }
};