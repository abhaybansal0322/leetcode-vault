class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul=1;
        bool oneZero=true;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0 && oneZero)
            {
                oneZero=false;    
            }
            else{
                mul=mul*nums[i];
            }
            
        }
       

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0){
                nums[i]=mul;
            }
            else if(nums[i]!=0 && !oneZero){
                nums[i]=0;
            }
            else{
                nums[i]=mul/nums[i];
            }
        }
        return nums;
        
    }
};