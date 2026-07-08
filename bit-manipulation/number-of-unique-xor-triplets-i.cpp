class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()==1 ||nums.size()==2)
        {
            return nums.size();
        }
        int temp = nums.size();
        int x=0;
        while(temp)
        {
            temp>>=1;
            x++;
        }

        return pow(2,x);
       
        
        
    }
};