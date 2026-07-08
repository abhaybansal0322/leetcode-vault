class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int l=0,r=0;
        int n = nums.size();

        while(r < n-1)
        {
            int farthest = 0;
            for(int idx = l;idx<=r;++idx)
            {
                farthest = max(farthest,idx+nums[idx]);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }

        return jumps;
        
    }
};