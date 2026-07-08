class Solution {
public:

    int dp[1001][1001];

    int helper(int currA,int clip,int n)
    {
        if(currA==n)
        {
            return 0;
        }
        if(currA > n)
        {
            return 100000;
        }
        if(dp[currA][clip]!=-1)
        {
            return dp[currA][clip];
        }

        int copyAllPaste = 2+helper(currA*2,currA,n);
        int Paste = 1+helper(currA+clip,clip,n);

        return dp[currA][clip]=min(copyAllPaste,Paste);

    }

    int minSteps(int n) {
        if(n==1)
        {
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        return 1+helper(1,1,n);
        
    }
};