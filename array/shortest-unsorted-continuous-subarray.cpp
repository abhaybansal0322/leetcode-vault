class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
        }
        sort(temp.begin(),temp.end());
     
        int l1=0,r1=nums.size()-1;
        int l2=l1,r2=r1;
        while(l1 < r1 )
        {
            if(nums[l1]==temp[l2] && nums[r1]==temp[r2])
            {
                l1++;
                l2++;
                r1--;
                r2--;
            }
            else if(nums[l1]==temp[l2])
            {
                l1++;
                l2++;
            }
            else if(nums[r1]==temp[r2])
            {
                r1--;
                r2--;
            }
            else{
                return r1-l1+1;
            }
                
        }
        return 0;
        
    }
};