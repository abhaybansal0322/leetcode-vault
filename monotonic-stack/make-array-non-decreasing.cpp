class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int i=0;
        int j=1;
        
        int n = nums.size();
        int ans = n;

        while(i < j && i < n && j < n)
            {
                while(i<n && j<n && nums[i]<=nums[j])
                    {
                        i++;
                        j++;
                    }
                
                while(i<n && j<n && nums[i] > nums[j])
                    {
                        j++;
                    }
                ans = ans-(j-i-1);
                i = j;
                j = i+1;
                
            }

        return ans;
    }
};