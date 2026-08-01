class Solution {
    bool helper(vector<int>& nums, int score1, int score2,int l,int r,int turn) {
        if(l > r) {
            if(score1 >= score2)    return true;
            return false;
        }

        if(turn) {
            return helper(nums,score1+nums[l],score2,l+1,r,0) || helper(nums,score1+nums[r],score2,l,r-1,0);
        }

        return helper(nums,score1,score2+nums[l],l+1,r,1) && helper(nums,score1,score2+nums[r],l,r-1,1);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        
        return helper(nums,0,0,0,nums.size()-1,1);
    }
};