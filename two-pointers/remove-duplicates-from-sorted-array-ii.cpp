class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;
        int occ=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[count]=nums[i];
                count++;
                occ=1;
            }
            
            else if(nums[i]==nums[i-1] && occ!=2)
            {
                nums[count]=nums[i];
                count++;
                occ++;
            }
        }
        return count;
    }
};