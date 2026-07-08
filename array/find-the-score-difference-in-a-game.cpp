class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        
        int player1 = 0;
        int player2 = 0;
        bool active1 = true, active2 = false;
        int n = nums.size();

        for(int i=0;i<n;i++) {

            if((i+1)%6 == 0) {

                active1 = !active1;
                active2 = !active2;
            }

            if(nums[i]&1) {

                active1 = !active1;
                active2 = !active2;
            }


            if(active1) {
                player1 += nums[i];
            }
            if(active2) {

                player2 += nums[i];
            }
        }

        return player1 - player2;
    }
};