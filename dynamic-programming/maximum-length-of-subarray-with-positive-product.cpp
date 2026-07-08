class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int sz = nums.size();
        int ans=0;

        for(int i=0;i<sz;i++)
        {
            int n=0,ns=-1,ne=-1,j;
            for(j=i;j<sz;j++)
            {
                if(nums[j]==0)  {break;}
                if(nums[j]<0) {n++;}
                
                if(nums[j]<0 && ns==-1) {
                    ns=j;
                    ne=j;
                }

                if(nums[j]<0 && ns!=-1) {ne=j;}
            }

            if(n%2==0)
            {
                ans = max(ans,j-i);
            }
            if(n%2==1)
            {
                ans = max(ans,j-ns-1);
                ans = max(ans,ne-i);
            }

            i=j;
        }

        return ans;
        
    }
};