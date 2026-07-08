class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                sum = sum+nums[j];
                ans.push_back(sum);
            }
            sum=0;
        }
        int ret=0;

        sort(ans.begin(),ans.end());
        int a=left-1;
        while(a < right)
        {
            ret = ret +ans[a];
            ret%=1000000007;
            a++;
        }

        return ret; 
        
    }
};