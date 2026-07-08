class Solution {
    bool isInc(vector<int>& nums)
    {
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] > nums[i+1])
                return false;
        }
        
        return true;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        
        vector<int> curr = nums;
        int steps = 0;
        
        while(1)
        {
            if(isInc(curr))
                break;
            
            int pos = -1;
            int minSum = INT_MAX;
            
            for(int i=0;i<curr.size()-1;i++)
            {
                int s = curr[i]+curr[i+1];
                if(s < minSum)
                {
                    minSum = s;
                    pos=i;
                }
            }
            
            vector<int> next;
            for(int i=0;i<curr.size();)
            {
                if(i==pos)
                {
                    next.push_back(minSum);
                    i=i+2;
                }
                else{
                    next.push_back(curr[i]);
                    i++; 
                }
            }
            curr = next;
            steps++;
        }
        
        return steps;
    }
};