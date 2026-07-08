class Solution {
public:

    int countBits(int num)
    {
        int ans=0;
        while(num)
        {
            if((num & 1) == 1)
                ans++;
            
            num >>= 1;
        }
        return ans;
    }

    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> Bits(n);
        
        for(int i=0;i<n;i++)
        {
            Bits[i]=countBits(nums[i]);
        }

        int prevMax = INT_MIN;
        int currMax = nums[0];
        int currMin = nums[0];
        int currBits = Bits[0];

        for(int i=1;i<n;i++)
        {
            if(Bits[i]==currBits)
            {
                currMax = max(currMax,nums[i]);
                currMin = min(currMin,nums[i]);
            }
            else{
                if(currMin < prevMax)
                {
                    return false;
                }
                prevMax = currMax;
                currMax = nums[i];
                currMin = nums[i];
                currBits = Bits[i];
            }
        }

        if(currMin < prevMax){
            return false;
        }

        return true;
    }
};