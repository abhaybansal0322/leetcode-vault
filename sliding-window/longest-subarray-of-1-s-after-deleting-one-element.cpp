class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0;
        int r=0;
        int count_zeroes=0;
        int res=INT_MIN;
        int first_occ=-1;

        while(r < nums.size())
        {
            if(nums[r]==0)
            {
                if(first_occ==-1)
                {
                    first_occ=r;
                }
                count_zeroes++;

                if(count_zeroes > 1)
                {
                    l=first_occ+1;
                    count_zeroes=1;
                    first_occ=r;
                }
            }
            res=max(res,r-l+1);
            r++;
        }
        return res-1;  
    }
};