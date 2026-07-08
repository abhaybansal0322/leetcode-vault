class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for(int i=0;i<n;i++)
        {
            int currOr = nums[i];
            for(int j=i+1;j<n;j++)
            {
                if( (currOr & nums[j]) == 0 )
                {
                    currOr = currOr | nums[j];
                    ans = max(ans,j-i+1);
                }
                else{
                    break;
                }
            }
        }

        return ans;
        
    }
};