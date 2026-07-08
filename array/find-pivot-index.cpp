class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum1=0;
        int sum2=0;
        int n=nums.size();

        for(int i=n-1;i>=0;i--)
        {
            sum1 += nums[i];
        }

        for(int i=0;i<n;i++)
        {
            sum2 += nums[i];
            // sum1 -= nums[i]
            if(sum1==sum2)
            {
                return i;
            }
            sum1 -= nums[i];
        }
        return -1;

        
    }
};