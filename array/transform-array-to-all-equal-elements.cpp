class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> temp = nums;
        int c1 = 0;
        for(int i=0;i<n-1;i++)
        {
            if(temp[i]==-1)
            {
                temp[i]=1;
                temp[i+1]=temp[i+1]*-1;
                c1++;
            }
        }

        if(temp[n-1]==-1)
            c1=INT_MAX;
        
        temp = nums;

        int c2 = 0;
        for(int i=0;i<n-1;i++)
        {
            if(temp[i]==1)
            {
                temp[i]=-1;
                temp[i+1]=temp[i+1]*-1;
                c2++;
            }
        }

        if(temp[n-1]==1)
            c2= INT_MAX;
        
        

        if(min(c1,c2)<=k)
            return true;

        return false;
    }
};