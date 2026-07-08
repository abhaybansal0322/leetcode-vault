
/// INTUTION ------------>

// Pehla Rightmost kddan lyi BS lgaayo fer Leftmost kaddan lyio lgaayo BS

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int left = -1;
        int right = -1;

        //Find Left

        while(l<=r)
        {
            int mid = l+(r-l)/2;

            if(nums[mid]==target)
            {
                left = mid;
                r = mid-1;
            }

            else if(nums[mid]>target)
            {
                r = mid-1;
            }

            else{
                l = mid+1;
            }
        }

        //Find right
        l = 0;
        r = n-1;

        while(l<=r)
        {
            int mid = l+(r-l)/2;

            if(nums[mid]==target)
            {
                right = mid;
                l = mid+1;
            }

            else if(nums[mid]>target)
            {
                r = mid-1;
            }

            else{
                l = mid+1;
            }
        }
        return {left,right};

    }
};